/**
 * @file
 *
 */
angular.module('searchResultApp').directive('searchSwitch', [ 'CONFIG',
  function (CONFIG) {
    "use strict";

    return {
      restrict: 'E',
      link: function (scope, element, attrs) {
        scope.showMap = false;

        scope.switch = function () {
          // Switch state.
          scope.showMap = !scope.showMap;

          // Result updates for the search map.
          if (scope.showMap) {

          }
        };
      },
      template: '<div class="something" data-ng-click="switch()">Toggle map</div>'
    };
  }
]);