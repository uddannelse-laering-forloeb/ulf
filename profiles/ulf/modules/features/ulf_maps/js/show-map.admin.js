/**
 * @file
 * Changes the behavior of the location map widget on the node edit form.
 */
(function ($) {

  /**
   * Hide all map related fields on the node edit form.
   *
   * @TODO: A lot of this could be remove in form alter.
   */
  function hideMapsInformation() {
    var $location = $('#location-wrapper');

    $('.location-current-coordinates-fieldset', $location).hide();
    $('.form-item-locations-0-locpick-user-latitude', $location).hide();
    $('.form-item-locations-0-locpick-user-longitude', $location).hide();
    $('.form-item-locations-0-re-geocode-location', $location).hide();
    $('.form-item-locations-0-delete-location', $location).hide();
    $('.description', $location).hide();
    $('.gmap-control', $location).hide();
  }

  /**
   * Drupal behavior that are attached to the element after every ajax load of
   * the maps.
   */
  Drupal.behaviors.show_map = {
    attach: function (context, settings) {
      // Get current location wrapper.
      var $location = $('#location-wrapper');

      hideMapsInformation();

      // Show content based on classes.
      if ($('.js-show-map', $location).length) {
        $('.gmap-control', $location).show();
      }

      var $street = $('.form-item-locations-0-street input');
      var $postal = $('.form-item-locations-0-postal-code input');
      var $city = $('.form-item-locations-0-city input');

      // Hide "specify entrance" button if address fields are missing.
      if ($street.val() == '' || $postal.val() == '' || $city.val() == '' ) {
        $('.js-specify-on-map', $location).hide();
        $('.js-change-address', $location).hide();

        // Needs to be remove as it may have been set before.
        $('.location-wrapper').removeClass('form-disabled');
      }
      else if (!$('.js-enable-address', $location).length) {
        // Disable input fields.
        $('.location-wrapper').addClass('form-disabled');
        $street.attr('disabled','disabled');
        $postal.attr('disabled','disabled');
        $city.attr('disabled','disabled');
        $('.js-change-address', $location).show();
      }
      else {
        // Needs to be remove as it may have been set before.
        $('.location-wrapper').removeClass('form-disabled');
      }

      // Check when all address fields have values.
      $('.form-item input', $location).keyup(function() {
        // Show button if all address fields are filled out.
        if ($('.form-item-locations-0-street input').val() == '' || $('.form-item-locations-0-postal-code input').val() == '' || $('.form-item-locations-0-city input').val() == '' ) {
          $('.js-specify-on-map', $location).hide();
        }
        else {
          $('.js-specify-on-map', $location).show();
          $('.js-change-address', $location).show();
        }
      });
    }
  };
})(jQuery);

