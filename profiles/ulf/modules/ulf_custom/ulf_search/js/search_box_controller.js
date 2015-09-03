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
    }

    /**
     * @TODO: Missing description.
     */
    communicatorService.$on('pager', function (event, data) {
      $scope.query.pager = {
        'size': data.size,
        'page': data.page
      };
      search();
    });

    /**
     * @TODO: Missing description.
     */
    $scope.searchClicked = function searchClicked() {
      // Reset pager.
      if ($scope.query.hasOwnProperty('pager')) {
        $scope.query.pager = angular.copy(CONFIG.provider.pager);
      }

      search();
    };

    // Get set show on the road.
    init();
  }
]);