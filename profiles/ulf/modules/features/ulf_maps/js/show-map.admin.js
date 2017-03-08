/**
 * @file
 * Changes the behavior of the location map widget on the node edit form.
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
  }

  /**
   * Show/hide the google displayed map.
   *
   * @param {boolean} show
   *   If true show the map else hide it.
   */
  function showLocationMap(show) {
    var $gMap = $('#' + gmap_name);
    $gMap.toggle(show);
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

    console.log(state);
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
            $('#edit-locations-0-street', $locationWrapper).val(Drupal.settings.ulf_maps.provider.street);
            $('#edit-locations-0-additional', $locationWrapper).val(Drupal.settings.ulf_maps.provider.address);
            $('#edit-locations-0-postal-code', $locationWrapper).val(Drupal.settings.ulf_maps.provider.postal_code);
            $('#edit-locations-0-postal-code', $locationWrapper).val(Drupal.settings.ulf_maps.provider.city);
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
      // Start by hiding the location fields that we don't want the user to see.
      hideExtraLocationInformation();

      // Find the selectors (radio buttons) that defines what should be shown.
      var $selectors = $('.field-name-field-map-placement [name="field_map_placement[und]"]');

      // Set the default state based on current form selections.
      changeLocationFields($selectors.val());

      // Hook into the selectors change event to update the UI.
      $selectors.click(function () {
        changeLocationFields($(this).val());
      });
    }
  };
})(jQuery);
