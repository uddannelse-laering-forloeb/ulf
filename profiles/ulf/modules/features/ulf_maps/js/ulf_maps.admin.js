/**
 * @file
 * Changes the behavior of the location widget on the node edit form.
 */
(function ($) {
  // Global variables inside this closure. jQuery object can not be defined
  // here as the DOM may not be ready.
  var gmap_name = 'gmap-auto1map-gmap0';
  var location_wrapper = '.location-wrapper';

  /**
   * Hide location fields that we don't want to display to the user.
   *
   * This is extra field with e.g. the lat/lon location etc.
   */
  function hideExtraLocationInformation() {
    var $locationWrapper = $(location_wrapper);

    $('.location-current-coordinates-fieldset', $locationWrapper).hide();
    $('.form-item-locations-0-locpick-user-latitude', $locationWrapper).hide();
    $('.form-item-locations-0-locpick-user-longitude', $locationWrapper).hide();
    $('.form-item-locations-0-re-geocode-location', $locationWrapper).hide();
    $('.form-item-locations-0-delete-location', $locationWrapper).hide();
    $('.description', $locationWrapper).hide();
    $('#' + gmap_name).hide();
  }

  /**
   * Show/hide the google displayed map.
   *
   * @param {boolean} show
   *   If true show the map else hide it.
   */
  function showLocationMap(show) {
    var $gMap = $('#' + gmap_name);

    if (show) {
      // Display the map element in the UI.
      $gMap.show(function () {
        updateGoogleMapPreview();
      });
    }
    else {
      // Simple hide the map element.
      $gMap.hide();
    }
  }

  /**
   * Update the google map preview.
   *
   * This will update the google map preview to display the currently enter
   * address on the map.
   */
  function updateGoogleMapPreview() {
    // Get the google map object and trigger resize to re-draw the map.
    var map  = Drupal.gmap.getMap(gmap_name).map;
    google.maps.event.trigger(map, 'resize');

    // Get the current entered address and use google geocoder to get the
    // lat/lon.
    var address =  $('#edit-locations-0-street').val() + ',' +  $('#edit-locations-0-postal-code').val() + ',' + $('#edit-locations-0-city').val();
    var geocoder = new google.maps.Geocoder();
    geocoder.geocode( { 'address': address}, function(results, status) {
      if (status == 'OK') {
        var location = results[0].geometry.location;

        // Use the location to update the hidden lock-pick fields and
        // trigger change events on them to trigger it to update the marker
        // position on the map.
        $('#gmap-auto1map-locpick_latitude0').val(location.lat);
        $('#gmap-auto1map-locpick_latitude0').change();
        $('#gmap-auto1map-locpick_longitude0').val(location.lng);
        $('#gmap-auto1map-locpick_longitude0').change();

        // Change the map to center on the marker and trigger another resize
        // event to re-draw the map once more.
        if (map) {
          map.setCenter(location);
          google.maps.event.trigger(map, 'resize');
        }
      }
    });
  }

  /**
   * Enable/disable the location input fields.
   *
   * @param {boolean} edit
   *   If true enable the fields else disable.
   */
  function locationEditable(edit) {
    var $locationWrapper = $(location_wrapper);

    if (edit) {
      $('input', $locationWrapper).prop('readonly', false);
      $locationWrapper.removeClass('form-disabled');
    }
    else {
      $('input', $locationWrapper).prop('readonly', true);
      $locationWrapper.addClass('form-disabled');
    }
  }

  /**
   * The logic behind the UI behaviour when the different options are selected.
   *
   * @param {string} state
   *   The state selected in the UI.
   */
  function changeLocationFields(state) {
    var $locationWrapper = $(location_wrapper);

    // Used to set helper text for new nodes selecting the provider address.
    var $providerElement = $('.form-item-field-map-placement-und [for="edit-field-map-placement-und-provider"]');
    var $providerText = $('.description', $providerElement);

    // Helper text don't exists so lets create it (and hide it).
    if (!$providerText.length) {
      $providerElement.append('<div class="description">' + Drupal.t('As this is a new node the provider address will be set before the node have been saved.') + '</div>');
      $providerText = $('.description', $providerElement);
      $providerText.hide();
    }

    switch (state) {
      case 'provider':
        // Fill on the providers address, which have been loaded from the
        // provider. Only if the node is not new, hence we don't have the
        // information yet.
        if (Drupal.settings.hasOwnProperty('ulf_maps')) {
          // If this is a new node add helper text.
          if (Drupal.settings.ulf_maps.is_new) {
            $providerText.show();
          }
          else {
            // Insert the providers information in the location form.
            $('#edit-locations-0-street', $locationWrapper).val(Drupal.settings.ulf_maps.provider.street);
            $('#edit-locations-0-additional', $locationWrapper).val(Drupal.settings.ulf_maps.provider.additional);
            $('#edit-locations-0-postal-code', $locationWrapper).val(Drupal.settings.ulf_maps.provider.postal_code);
            $('#edit-locations-0-city', $locationWrapper).val(Drupal.settings.ulf_maps.provider.city);
          }
        }
        showLocationMap(true);
        locationEditable(false);
        break;

      case 'alternative':
        $providerText.hide();
        showLocationMap(true);
        locationEditable(true);
        break;

      case 'hide':
        $providerText.hide();
        showLocationMap(false);
        locationEditable(true);
        break;

      default:
        console.error('Unknown location provider chosen!');
        break;
    }
  }

  /**
   * Drupal behavior that are attached to the element after every ajax load of
   * the maps.
   */
  Drupal.behaviors.show_map = {
    attach: function (context, settings) {
      var $locationWrapper = $(location_wrapper);

      // Start by hiding the location fields that we don't want the user to see.
      hideExtraLocationInformation();

      // Add hidden overlay to prevent marker movement in google maps.
      $('#' + gmap_name).wrap('<div class="gmap-wrapper"></div>');
      $('.gmap-wrapper').append('<div class="gmap-overlay"></div>');

      // Find the selectors (radio buttons) that defines what should be shown.
      var $selectors = $('.field-name-field-map-placement [name="field_map_placement[und]"]');

      // If selectors not found, it may be an provider profile.
      if (!$selectors.length) {
        $selectors = $('.field-name-field-profile-map-placement [name="field_profile_map_placement[und]"]');
      }

      // Set the default state based on current form selections.
      $selectors.each(function () {
        if ($(this).is(":checked")) {
          changeLocationFields($(this).val());
        }
      });

      // Hook into the selectors change event to update the UI.
      $selectors.change(function () {
        changeLocationFields($(this).val());
      });

      // Hook into the input address fields and update the google map.
      $('#edit-locations-0-street', $locationWrapper).change(updateGoogleMapPreview);
      $('#edit-locations-0-additional', $locationWrapper).change(updateGoogleMapPreview);
      $('#edit-locations-0-postal-code', $locationWrapper).change(updateGoogleMapPreview);
      $('#edit-locations-0-city', $locationWrapper).change(updateGoogleMapPreview);
    }
  };
})(jQuery);
