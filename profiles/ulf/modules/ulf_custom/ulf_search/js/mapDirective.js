/**
 * @file
 *
 */
angular.module('searchResultApp').directive('searchMap', [ '$timeout', '$templateCache', '$compile', '$q', '$http', 'CONFIG', 'communicatorService',
  function ($timeout, $templateCache, $compile, $q, $http, CONFIG, communicatorService) {
    "use strict";

    var markers = [];

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

    function addMarker(map, data, scope) {
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


          marker.bindPopup(div);
          markers.push(marker);
          marker.addTo(map);
        });
      }
    }

    return {
      restrict: 'E',
      scope: {},
      link: function (scope, element, attrs) {
        console.log('test');
        // Initialize map container.
        var map = L.map('search-map', { zoomControl:false });

        // @TODO: Make this configurable.
        map.setView(new L.LatLng(56.15331, 10.19651), 10);

        // Add open street map as base layer.
        var osm_url='http://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png';
        var osm_copy='Map data © <a href="http://openstreetmap.org">OpenStreetMap</a>';
        var osm = new L.TileLayer(osm_url, {minZoom: 10, maxZoom: 18, attribution: osm_copy});
        map.addLayer(osm);

        // Watch for changes in hits
        communicatorService.$on('mapHits', function onMapHits(event, hits) {
          // Remove all markers before populating with new markers.
          for (var i in markers) {
            map.removeLayer(markers[i]);
          }
          markers = [];

          // Add all results to the map.
          for (var hit in hits.results) {
            addMarker(map,  hits.results[hit], scope);
          }
        });
      }
    };
  }
]);
