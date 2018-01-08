/**
 * JS to be loaded when full form validation fails.
 **/
(function ($) {
  "use strict";
  Drupal.behaviors.form_validation_error = {
    attach: function (context, settings) {
      $('#edit-part-two .is-hidden').removeClass('is-hidden');
      $('#transportpulje-form-add-application #edit-submit-wrapper').show();
    }
  };
}(jQuery));