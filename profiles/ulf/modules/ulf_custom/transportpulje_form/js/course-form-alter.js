/**
 * Hide transport form if user not editor or course target_group is Youth.
 * Hide transport form from message form dropdown.
 **/
(function ($) {
  "use strict";
  Drupal.behaviors.course_form = {
    attach: function (context, settings) {
      // Hide if not editor user.
      if (!inArray('editor', Object.values(settings.user.roles))) {
        $('.group-transport-app').hide();
      }

      // Simple inArray function.
      function inArray(needle, haystack) {
        var length = haystack.length;
        for(var i = 0; i < length; i++) {
          if(haystack[i] == needle) return true;
        }
        return false;
      }

      // Hide on change if youth.
      $(".field-name-field-target-group input").on( "change", function() {
        if ($(this).val() == settings.target_group) {
          $('.group-transport-app').hide();
        }
        else {
          $('.group-transport-app').show();
        }
      });

      // Hide on load if youth.
      if ($(".field-name-field-target-group input:checked").val() == settings.target_group) {
        $('.group-transport-app').hide();
      }

      // Hide selection on eform list.
      $('.field-name-field-message-form option').filter(function() { return ($(this).text() === 'Transportpulje formular') }).remove();
    }
  };
}(jQuery));