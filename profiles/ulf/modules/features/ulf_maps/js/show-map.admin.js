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
    var $location = $('.location-wrapper');

    $('.location-current-coordinates-fieldset', $location).hide();
    $('.form-item-locations-0-locpick-user-latitude', $location).hide();
    $('.form-item-locations-0-locpick-user-longitude', $location).hide();
    $('.form-item-locations-0-re-geocode-location', $location).hide();
    $('.form-item-locations-0-delete-location', $location).hide();
    $('.description', $location).hide();
  }

  /**
   * Drupal behavior that are attached to the element after every ajax load of
   * the maps.
   */
  Drupal.behaviors.show_map = {
    attach: function (context, settings) {
      hideMapsInformation();
      //$('.gmap-control').show();
      /*

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
      });*/
    }
  };


  // /**
  //  * Function to call when the the place settings selector is changed.
  //  * Updates which fields should be shown.
  //  */
  // function changePlaceSelection(selected) {
  //   // Show stuff depending on what the selection array contains.
  //   $('.location-wrapper').hide();
  //   if ($.trim(selected) == 'Vis udbyderadresse') {
  //     $('.location-wrapper').show();
  //     $('.group-address .fieldset-wrapper').show();
  //     $('.group-address').removeClass('collapsed');
  //     $('.location-wrapper #edit-locations-0-street').val(Drupal.settings.userValues.street);
  //     $('.location-wrapper #edit-locations-0-additional').val(Drupal.settings.userValues.further_info);
  //     $('.location-wrapper #edit-locations-0-postal-code').val(Drupal.settings.userValues.postal_code);
  //     $('.location-wrapper #edit-locations-0-city').val(Drupal.settings.userValues.city);
  //     $('.group-address input').prop('readonly', true);
  //     $('.group-address').addClass('form-disabled')
  //     $('.group-address .gmap-control').hide();
  //     $('.form-item-locations-0-city .messages').remove();
  //   }
  //
  //   if ($.trim(selected) == 'Vis alternativ adresse') {
  //     $('.location-wrapper').show();
  //     $('.group-address .gmap-control').show();
  //     $('.group-address .fieldset-wrapper').show();
  //     $('.group-address').removeClass('collapsed');
  //     $('.group-address input').prop('readonly', false);
  //     $('.group-address').removeClass('form-disabled');
  //     $('.location-wrapper input[type=text]').val('');
  //     mapObj = Drupal.gmap.getMap('gmap-auto1map-gmap0');
  //     mapObj.map.setZoom(12);
  //     google.maps.event.trigger(mapObj.map, 'resize');
  //     var coord = Drupal.settings.mapConfig.latlong.split(',');
  //     mapObj.map.setCenter(new google.maps.LatLng(coord['0'], coord['1']), 12);
  //     $('.form-item-locations-0-city').append('<div class="messages warning">Google forsøger på baggrund af adressen angivet, at bestemme lokaliteten der vises på kortet til slutbrugeren. Hvis du vil hjælpe google på vej kan du angive positionen på kortet herunder.</div>');
  //   }
  //   if ($.trim(selected) == 'Vis ikke på kort') {
  //     $('.group-address .gmap-control').show();
  //     $('.group-address .fieldset-wrapper').show();
  //     $('.group-address').removeClass('collapsed');
  //     $('.group-address input').prop('readonly', true);
  //     $('.group-address').removeClass('form-disabled');
  //     $('.form-item-locations-0-city .messages').remove();
  //   }
  // }
  //
  // $('.form-layout--beta .fieldset-title').click(function () {
  //   mapObj = Drupal.gmap.getMap('gmap-auto1map-gmap0');
  //   mapObj.map.setZoom(12);
  //   google.maps.event.trigger(mapObj.map, 'resize');
  //   var coord = Drupal.settings.mapConfig.latlong.split(',');
  //   mapObj.map.setCenter(new google.maps.LatLng(coord['0'], coord['1']), 12);
  // });
  //
  //
  // // Display map
  // mapObj = Drupal.gmap.getMap('gmap-auto1map-gmap0');
  // google.maps.event.trigger(Drupal.gmap.map, 'resize');
  //
  // // Set readonly on fields
  // if (Drupal.settings.placeConfig == 'place_settings_show_address') {
  //   $('.group-address input').prop('readonly', true);
  //   $('.group-address').addClass('form-disabled')
  // }
  //
  // if (Drupal.settings.placeConfig === false) {
  //   $('.location-wrapper').hide();
  // }
  //
  // // Change stuff when a new target group is added or removed.
  // $('.field-name-field-place-settings .form-radio').change(function () {
  //
  //   var id = ($(this).val());
  //   var selected = $('.field-name-field-place-settings input[value="' + id + '"]').next().text();
  //   changePlaceSelection(selected);
  // });
  //
  // //When the place settings field is changed, change the subgroup options.
  // $('.field-name-field-place-settings .form-select').change(changePlaceSelection);



})(jQuery);

