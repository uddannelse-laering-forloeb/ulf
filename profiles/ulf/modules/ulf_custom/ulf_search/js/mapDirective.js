/**
 * @file
 *
 */
angular.module('searchResultApp').directive('searchMap', [ '$timeout', '$templateCache', '$compile', '$q', '$http', 'CONFIG', 'communicatorService',
  function ($timeout, $templateCache, $compile, $q, $http, CONFIG, communicatorService) {
    "use strict";

    /**
     * Load template file from URL.
     *
     * @param tmpl
     * @param config
     * @returns {*}
     */
    function loadTemplateUrl(tmpl, config) {
      return $http.get(tmpl, angular.extend({cache: false}, config || {})).then(function(res) {
        return res.data || '';
      });
    }

    /**
     * Load template from cache and fallback to URL.
     *
     * @param tmpl
     * @returns {*}
     */
    function loadTemplate(tmpl) {
      if (!tmpl) {
        return 'Empty template';
      }

      return $templateCache.get(tmpl) || loadTemplateUrl(tmpl, {cache: false});
    }

    /**
     * Add marker to the map with "hit" information.
     *
     * It's wrapper in a promise to enable events when all markers have been set
     * on the map.
     *
     * @param map
     *   Leaflet map object.
     * @param data
     *   The data for the current "hit".
     * @param scope
     *   The scope used by the directive.
     *
     * @returns {*}
     *   Promise to set the marker.
     */
    function addMarker(map, data, scope) {
      return $q(function(resolve, reject) {
        var location = data.field_location;

        if (location !== null) {
          var marker = L.marker([location.lat, location.lon]);

          $q.when(loadTemplate(CONFIG.templates.popup)).then(function (template) {
            $templateCache.put(CONFIG.templates.popup, template);

            var div = L.DomUtil.create('div', 'test');
            var $content = angular.element(div);

            // Create new scope for the popup content.
            var $scope = scope.$new(true);
            $scope.hit = data;

            // Attach the angular template to the dom and render the
            // content.
            $content.html(template);
            $content.hide();
            $timeout(function () {
              $compile($content)($scope);
              $content.fadeIn();
            });

            // Add marker to the map.
            marker.bindPopup(div);
            resolve(marker);
          });
        }
        else {
          resolve()
        }
      });
    }

    return {
      restrict: 'E',
      scope: {},
      link: function (scope, element, attrs) {
        // Initialize map container.
        var map = L.map('search-map', { zoomControl:true });

        // @TODO: Make this configurable.
        map.setView(new L.LatLng(56.15331, 10.19651), 10);

        // Add open street map as base layer.
        var osm_url='http://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png';
        var osm_copy='Map data © <a href="http://openstreetmap.org">OpenStreetMap</a>';
        var osm = new L.TileLayer(osm_url, {minZoom: 1, maxZoom: 15, attribution: osm_copy});
        map.addLayer(osm);

        // Bookkeeper for the currently placed markers.
        var markers = new L.featureGroup();

        // Watch for changes in hits
        communicatorService.$on('mapSearchHits', function onMapHits(event, hits) {
          scope.mapHits = hits;

          // Add all results to the map.
          var promises = [];
          for (var hit in hits.results) {
            promises.push(addMarker(map,  hits.results[hit], scope));
          }

          // When all markers are set change the map view to fit the markers.
          if (promises.length) {
            $q.all(promises).then(function (data) {
              // Remove all markers before populating with new markers.
              map.removeLayer(markers);

              // Clean out resolved markers as some are without lat/lon and is
              // undefined in the array.
              var features = [];
              for (var i = 0; i < data.length; i++) {
                if (data[i] !== undefined) {
                  features.push(data[i]);
                }
              }

              // Add marker to the map.
              markers = new L.featureGroup(features);
              markers.addTo(map);
              map.fitBounds(markers.getBounds());
            });
          }
        });

        // Request search results for the map.
        communicatorService.$emit('requestMapSearch');
      }
    };
  }
]);
