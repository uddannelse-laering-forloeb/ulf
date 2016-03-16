(function ($) {
  Drupal.behaviors.show_map = {
    attach: function () {
      // Get map parameter from url.
      var map = getUrlParameter('map');

      // Hide several fields that are used by the map display.
      $('.location-wrapper .location-current-coordinates-fieldset').hide();
      $('.location-wrapper .form-item-locations-0-locpick-user-latitude').hide();
      $('.location-wrapper .form-item-locations-0-locpick-user-longitude').hide();
      $('.location-wrapper .form-item-locations-0-re-geocode-location').hide();
      $('.location-wrapper .form-item-locations-0-delete-location').hide();
      $('.location-wrapper .gmap-control').hide();
      $('.location-wrapper .description').hide();

      // Hide button if some address fields are missing.
      if ($('.location-wrapper #edit-locations-0-street').val() == '' || $('.location-wrapper #edit-locations-0-postal-code').val() == '' || $('.location-wrapper #edit-locations-0-city').val() == '' ) {
        $('.location-wrapper #edit-locations-0-submit').hide();
      }

      if ($('.location-wrapper #edit-locations-0-street').val() && $('.location-wrapper #edit-locations-0-postal-code').val() && $('.location-wrapper #edit-locations-0-city').val()) {
        $('.location-wrapper').addClass('form-disabled');
        $('.location-wrapper #edit-locations-0-street').attr('disabled','disabled');
        $('.location-wrapper #edit-locations-0-postal-code').attr('disabled','disabled');
        $('.location-wrapper #edit-locations-0-city').attr('disabled','disabled');
      }

      // Show map if address has been submitted from custom submit handler.
      if (map === 'true') {
        $('.location-wrapper .gmap-control').show();
      }

      // Check when all address fields have values.
      $('.location-wrapper .form-item input').keyup(function() {
        var empty = false;
        if ($('.location-wrapper #edit-locations-0-street').val() == '' || $('.location-wrapper #edit-locations-0-postal-code').val() == '' || $('.location-wrapper #edit-locations-0-city').val() == '' ) {
          empty = true;
        }

        // Show button if all address fields are filled out.
        if (empty) {
          $('.location-wrapper #edit-locations-0-submit').hide();
        } else {
          $('.location-wrapper #edit-locations-0-submit').show();
        }
      });
    }
  };
})(jQuery);


// Custom function to check url parameters.
var getUrlParameter = function getUrlParameter(sParam) {
  var sPageURL = decodeURIComponent(window.location.search.substring(1)),
    sURLVariables = sPageURL.split('&'),
    sParameterName,
    i;

  for (i = 0; i < sURLVariables.length; i++) {
    sParameterName = sURLVariables[i].split('=');
    if (sParameterName[0] === sParam) {
      return sParameterName[1] === undefined ? true : sParameterName[1];
    }
  }
};