/**
 * @file
 * Switch/toggle show map.
 *
 * This is create as an directive, so that we don't have to override the whole
 * searchResultsApp controller just change a scope variable.
 */
angular.module('searchResultApp').directive('searchSwitch', [ 'CONFIG',
  function (CONFIG) {
    "use strict";

    return {
      restrict: 'A',
      link: function (scope, element, attrs) {
        scope.displayMap = false;

        scope.showMap = function showMap() {
          scope.displayMap = true;
        };

        scope.hideMap = function hideMap() {
          scope.displayMap = false;
        };

      }
    };
  }
]);