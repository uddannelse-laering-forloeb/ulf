/**
 * @file
 * This is the main controller for the application.
 *
 * It controls the search box and filters.
 */

/**
 * Create filter that pads a number with zero's.
 *
 * @TODO: Move this back to the main angular library.
 */
angular.module('searchResultApp').filter('trimWordBoundary', function () {
  "use strict";

  return function (str, len) {
    // Clean out headlines.
    str = str.replace(/(<h\d>).+(<\/h\d>)/gi, '');

    // Clean out HTML.
    str = str.replace(/(<([^>]+)>)/gi, '');

    // Trim string to word boundery.
    var trimmedString = str.substr(0, len);
    str = trimmedString.substr(0, Math.min(trimmedString.length, trimmedString.lastIndexOf(" ")));

    return str + '...';
  };
});

/**
 * Overrides the default searchBoxApp controller.
 */
angular.module('searchBoxApp').controller('UlfBoxController', ['CONFIG', 'communicatorService', 'searchProxy', '$scope',
  function (CONFIG, communicatorService, searchProxy, $scope) {
    'use strict';

    /**
     * Execute the search and emit the results.
     */
    function search() {
      searchProxy.search($scope.query).then(
        function (data) {
          // Updated filters.
          searchProxy.getFilters().then(
            function (filters) {
              $scope.filters = filters;
            },
            function (reason) {
              console.error(reason);
            }
          );

          // Updated selected filters base on search query.
          var filters = angular.copy($scope.query.filters);
          var selectedFilters = {};
          for (var field in filters) {
            selectedFilters[field] = []
            for (var key in filters[field]) {
              if (filters[field][key]) {
                selectedFilters[field].push(key);
              }
            }
          }
          $scope.selectedFilters = selectedFilters;

          // Send results.
          communicatorService.$emit('hits', {"hits" : data});
        },
        function (reason) {
          console.error(reason);
        }
      );
    }

    /**
     * Init the contoller.
     */
    function init() {
      // Get state from pervious searches.
      var state = searchProxy.init();

      // Get filters.
      $scope.filters = state.filters;

      // Set template to use.
      $scope.template = CONFIG.templates.box;

      // Init the query object.
      $scope.query = {
        'text': '',
        'filters': {}
      };

      // Init selected filters.
      $scope.selectedFilters = {};

      // Check if any search query have been located from the hash tag.
      if (state.hasOwnProperty('query')) {
        // Query found in state, so execute that search.
        $scope.query = state.query;
        search();
      }
      else {
        // Check if the provider supports an pager.
        if (CONFIG.provider.hasOwnProperty('pager')) {
          // Add pager information to the search query.
          $scope.query.pager = angular.copy(CONFIG.provider.pager);
        }

        // Get filters based on search content (maybe slow).
        $scope.filters = searchProxy.getFilters().then(
          function (filters) {
            $scope.filters = filters;
          },
          function (reason) {
            console.error(reason);
          }
        );
      }

      // Set selected filters class array.
      $scope.toggleFilterClasses = {};
    }

    /**
     * Handle pager updated from the search result application.
     */
    communicatorService.$on('pager', function (event, data) {
      $scope.query.pager = {
        'size': data.size,
        'page': data.page
      };
      search();
    });

    /**
     * Click hanlder for searches.
     */
    $scope.searchClicked = function searchClicked() {
      // Reset pager.
      if ($scope.query.hasOwnProperty('pager')) {
        $scope.query.pager = angular.copy(CONFIG.provider.pager);
      }

      search();
    };

    /**
     * Open clicked filter.
     *
     * @param id
     *   The ID of the filter to open.
     */
    $scope.openFilter = function openFilter(id) {
      if ($scope.toggleFilterClasses.hasOwnProperty(id)) {
        // Same filter clicked just, close it.
        $scope.toggleFilterClasses = {
          'active': false
        };

      }
      else {
        // Close active filter.
        if ($scope.toggleFilterClasses.active) {
          $scope.toggleFilterClasses = {
            'active': false
          };
        }

        // Open new filter.
        $scope.toggleFilterClasses['active'] = true;
        $scope.toggleFilterClasses[id] = ['is-active', 'is-visible'];
      }
    };

    /**
     * Remove filter from the current query.
     *
     * @param field
     *   The field/filter to remove the filter from.
     * @param filter
     *   The filter word its self.
     */
    $scope.removeFilter = function removeFilter(field, filter) {
      if ($scope.query.filters[field].hasOwnProperty(filter)) {
        // Remove the filter for current query.
        delete $scope.query.filters[field][filter];

        // Update search.
        search();
      }
    };

    // Get set show on the road.
    init();
  }
]);
