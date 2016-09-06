/**
 * @file
 * Defective to get time-picker available in Angular.
 */
angular.module('searchBoxApp').directive('datetimePicker', ['$filter',
  function ($filter) {
    return {
      restrict: 'A',
      require: '^ngModel',
      link: function(scope, el, attrs, ctrl) {
        var angularFormat = attrs.angularFormat;
        var dateFormat = attrs.datetimePicker;
        var lastUnixTime = undefined;
        el.datetimepicker({
          timepicker: false,
          lang: 'da',
          format: dateFormat,
          onChangeDateTime:function(dp, $input){
            if (dp) {
              lastUnixTime = Math.floor(dp.getTime() / 1000);
            }
          }
        });

        /**
         * Used to format the input (unixtime) to selected format.
         */
        ctrl.$formatters.unshift(function(value) {
          if (value !== undefined) {
            return $filter('date')(value * 1000, angularFormat);
          }

          return '';
        });

        /**
         * Return the lastest timestamp to the model.
         */
        ctrl.$parsers.unshift(function (viewValue) {
          if (lastUnixTime !== undefined) {
            return lastUnixTime;
          }

          return 'test';
        });
      }
    }
  }
]);