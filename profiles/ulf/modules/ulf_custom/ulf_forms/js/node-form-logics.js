/**
 * Logic for the node form.
 * A lot of fields change due to the selection of the target group field.
 */
(function($) {

  // Array to hold subgroup checkboxes
  var subgroup = new Array();

  // Called when the document has finished loading.
  Drupal.behaviors.ulfCourseFormAlter = {
    attach: function (context, settings) {
      /**
       * Function to call when the the Target Group selector is changed.
       * Updates which fields should be shown.
       */
      function changeSelection(selected, id) {
        // Hide all target groups.
        $('.field-name-field-target-group-sub input').parent().hide()

        // Hide specific fields only relevant for certain target groups.
        $('.field-name-field-post-work').hide();
        $('.field-name-field-educational-goals').hide();
        $('.field-name-field-subjects-primary-school').hide();
        $('.field-name-field-subjects-youth').hide();
        $('.node-course-form .field-name-field-educational-material').hide();
        $('.node-course-form .field-name-field-inspirational-material').hide();
        $('.field-name-field-material-suggestions').hide();

        // Used in field help text.
        $('.is-school').hide();
        $('.is-preschool').hide();

        // Show stuff depending on what the selection array contains.
        if (selected.valueOf() === "Dagtilbud".valueOf()) {
          selectionPreschool();
        }
        if (selected == 'Grundskole') {
          selectionPrimarySchool();
        }
        if (selected ==='Ungdomsuddannelse') {
          selectionYouth();
        }
      }

      /**
       * Function to call when the the place settings selector is changed.
       * Updates which fields should be shown.
       */
      function changePlaceSelection(selected) {
        // Show stuff depending on what the selection array contains.
        $('.location-wrapper').hide();
        if ($.trim(selected) == 'Vis udbyderadresse') {
          $('.location-wrapper').show();
          $('.group-address .fieldset-wrapper').show();
          $('.group-address').removeClass('collapsed');
          $('.location-wrapper #edit-locations-0-street').val(Drupal.settings.userValues.street);
          $('.location-wrapper #edit-locations-0-additional').val(Drupal.settings.userValues.further_info);
          $('.location-wrapper #edit-locations-0-postal-code').val(Drupal.settings.userValues.postal_code);
          $('.location-wrapper #edit-locations-0-city').val(Drupal.settings.userValues.city);
          $('.group-address input').prop('readonly', true);
          $('.group-address').addClass('form-disabled')
          $('.group-address .gmap-control').hide();
          $('.form-item-locations-0-city .messages').remove();
        }

        if ($.trim(selected) == 'Vis alternativ adresse') {
          $('.location-wrapper').show();
          $('.group-address .gmap-control').show();
          $('.group-address .fieldset-wrapper').show();
          $('.group-address').removeClass('collapsed');
          $('.group-address input').prop('readonly', false);
          $('.group-address').removeClass('form-disabled');
          $('.location-wrapper input[type=text]').val('');
          mapObj = Drupal.gmap.getMap('gmap-auto1map-gmap0');
          mapObj.map.setZoom(12);
          google.maps.event.trigger(mapObj.map, 'resize');
          var coord = Drupal.settings.mapConfig.latlong.split(',');
          mapObj.map.setCenter(new google.maps.LatLng(coord['0'], coord['1']), 12);
          $('.form-item-locations-0-city').append('<div class="messages warning">Google forsøger på baggrund af adressen angivet, at bestemme lokaliteten der vises på kortet til slutbrugeren. Hvis du vil hjælpe google på vej kan du angive positionen på kortet herunder.</div>');
        }
        if ($.trim(selected) == 'Vis ikke på kort') {
          $('.group-address .gmap-control').show();
          $('.group-address .fieldset-wrapper').show();
          $('.group-address').removeClass('collapsed');
          $('.group-address input').prop('readonly', true);
          $('.group-address').removeClass('form-disabled');
          $('.form-item-locations-0-city .messages').remove();
        }
      }

      /**
       * Displays and hides Target Subgroup divs according to the accept function.
       * @param acceptFunction The function that decided if the text is accepted or rejected.
       */
      function displayRelevantSubgroupByKeyword(acceptFunction) {
        // Iterate each subgroup input.
        $.each(subgroup, function (index, arr) {
          var text = arr[0];
          var value = arr[1];
          // If the acceptFunction, accepts the text show the input, else hide it.
          if (acceptFunction(text)) {
            $('.field-name-field-target-group-sub input[value=' + value + ']').parent().show();
          }
          else {
            $('.field-name-field-target-group-sub input[value=' + value + ']').prop( "checked", false );
          }
        });
      }


      /**
       * Sets up available fields when Preschool is selected.
       */
      function selectionPreschool() {
        // The sub target group field selection values.
        displayRelevantSubgroupByKeyword(function (text) {
          return (text.indexOf('år') != -1);
        });

        // Whole fields are either shown or hidden depending on main target group.
        $('.field-name-field-inspirational-material').show();
        $('.field-name-field-material-suggestions').show();
        $('.field-name-field-educational-goals').show();
        $('.is-preschool').show();
      }


      /**
       * Sets up available fields when Primary School is selected.
       */
      function selectionPrimarySchool() {
        // The sub target group field selection values.
        displayRelevantSubgroupByKeyword(function (text) {
          return (text.indexOf('klasse') != -1);
        });

        // Whole fields are either shown or hidden depending on main target group.
        $('.field-name-field-post-work').show();
        $('.field-name-field-educational-material').show();
        $('.field-name-field-subjects-primary-school').show();
        $('.is-school').show();
      }


      /**
       * Sets up available fields when Youth is selected.
       */
      function selectionYouth() {
        // The sub target group field selection values.
        displayRelevantSubgroupByKeyword(function (text) {
          return (text.indexOf('år') == -1 && text.indexOf('klasse') == -1);
        });

        // Whole fields are either shown or hidden depending on main target group.
        $('.field-name-field-post-work').show();
        $('.field-name-field-educational-material').show();
        $('.field-name-field-subjects-youth').show();
        $('.is-school').show();
      }


      /// --- A lot of actions related to click events

      // Change stuff when a new target group is added or removed.
      $('.field-name-field-target-group .form-radio').change(function () {

        // The actual clicked item.
        var id = ($(this).val());
        var selected = $('.field-name-field-target-group input[value="' + id + '"]').next().text().replace(/ /g,'');

        changeSelection(selected, id);
      });

      // Change stuff when a new target group is added or removed.
      $('.field-name-field-place-settings .form-radio').change(function () {

        var id = ($(this).val());
        var selected = $('.field-name-field-place-settings input[value="' + id + '"]').next().text();
        changePlaceSelection(selected);
      });

      // When the Target Group selector is changed, change the subgroup options.
      $('.field-name-field-target-group .form-select').change(changeSelection);

      // When the place settings field is changed, change the subgroup options.
      $('.field-name-field-place-settings .form-select').change(changePlaceSelection);

      // When "Full year" is unchecked show field group for duration.
      // And set some default values.
      $('.field-name-field-period-full-year .form-checkbox').click(function () {
        if ($(this).is(':checked')) {
          $('#node_course_form_group_period').hide();
          $('.field-name-field-period').hide();
          $('.field-name-field-period .start-date-wrapper .form-item-field-period-und-0-value-date input').val(start_time);
          $('.field-name-field-period .end-date-wrapper .form-item-field-period-und-0-value2-date input').val('01/01/2030');
        }
        else {
          $('#node_course_form_group_period').show();
          $('.field-name-field-period').show();
          $('.field-name-field-period .start-date-wrapper .form-item-field-period-und-0-value-date input').val('');
          $('.field-name-field-period .end-date-wrapper .form-item-field-period-und-0-value2-date input').val('');
        }
      });

      // When field free is checked.
      $('.field-name-field-free .form-checkbox').click(function () {
        if ($(this).is(':checked')) {
          $('.field-name-field-collection-price').hide();
          $('.field-name-field-vary-price').hide();
        }
        else {
          $('.field-name-field-collection-price').show();
          $('.field-name-field-vary-price').show();
        }
      });

      $('.form-layout--beta .fieldset-title').click(function () {
        mapObj = Drupal.gmap.getMap('gmap-auto1map-gmap0');
        mapObj.map.setZoom(12);
        google.maps.event.trigger(mapObj.map, 'resize');
        var coord = Drupal.settings.mapConfig.latlong.split(',');
        mapObj.map.setCenter(new google.maps.LatLng(coord['0'], coord['1']), 12);
      });


      /// ------ Stuff that happens when the form is first loaded.

      // Get current date for field_period start time.
      var fullDate = new Date();
      var twoDigitMonth = fullDate.getMonth()+"";if(twoDigitMonth.length==1)	twoDigitMonth="0" +twoDigitMonth;
      var twoDigitDate = fullDate.getDate()+"";if(twoDigitDate.length==1)	twoDigitDate="0" +twoDigitDate;
      var start_time = twoDigitDate + "/" + twoDigitMonth + "/" + fullDate.getFullYear();

      // Display map
      mapObj = Drupal.gmap.getMap('gmap-auto1map-gmap0');
      google.maps.event.trigger(Drupal.gmap.map, 'resize');

      // Set readonly on fields
      if (Drupal.settings.placeConfig == 'place_settings_show_address') {
        $('.group-address input').prop('readonly', true);
        $('.group-address').addClass('form-disabled')
      }

      // Fill the subgroup array.
      $('.field-name-field-target-group-sub .option').each(function () {
        var val = $(this).siblings('input').val();
        var text = $(this).text();
        subgroup.push(new Array(text, val));
      });

      // Hide all target subgroups.
      $('.field-name-field-target-group-sub input').parent().hide()

      // Hide filter selections.
      $('.filter-wrapper').hide();

      // Hide specific fields only relevant for certain target groups.
      $('.field-name-field-post-work').hide();
      $('.field-name-field-educational-goals').hide();
      $('.field-name-field-subjects-primary-school').hide();
      $('.field-name-field-subjects-youth').hide();
      $('.node-course-form .field-name-field-educational-material').hide();
      $('.node-course-form .field-name-field-inspirational-material').hide();
      $('.field-name-field-material-suggestions').hide();

      // Used in field help text.
      $('.is-school').hide();
      $('.is-preschool').hide();

      // Change stuff when a new target group is added or removed.
      $('.field-name-field-target-group .form-radio[checked="checked"]').each(function () {
        // The actual clicked item.
        var id = ($(this).val());
        var selected = $('.field-name-field-target-group input[value="' + id + '"]').next().text().replace(/ /g,'');
        changeSelection(selected, id);
      });


      // When "Full year" is unchecked show field group for duration.
      $('.field-name-field-period-full-year .form-checkbox').each(function () {
        if ($(this).is(':checked')) {
          $('#node_course_form_group_period').hide();
          $('.field-name-field-period').hide();
          $('.field-name-field-period .start-date-wrapper .form-item-field-period-und-0-value-date input').val(start_time);
          $('.field-name-field-period .end-date-wrapper .form-item-field-period-und-0-value2-date input').val('01/01/2030');
        }
        else {
          $('#node_course_form_group_period').show();
          $('.field-name-field-period').show();
        }
      });

      // When "Free" is unchecked show field collection "Price".
      $('.field-name-field-free .form-checkbox').each(function () {
        if ($(this).is(':checked')) {
          $('.field-name-field-collection-price').hide();
          $('.field-name-field-vary-price').hide();
        }
        else {
          $('.field-name-field-collection-price').show();
          $('.field-name-field-vary-price').show();
        }
      });

      // Hide empty fields for old price and and contact on course educators content type.
      // If fields have values the editor should manually move them. When all values have been moved the field should be deleted as part of a future patch.
      if (!$('.field-name-field-course-contact-name input').val()) {
        $('.field-name-field-course-contact-name').hide();
      }
      if (!$('.field-name-field-course-contact-mail input').val()) {
        $('.field-name-field-course-contact-mail').hide();
      }
      if (!$('.field-name-field-course-phone input').val()) {
        $('.field-name-field-course-phone ').hide();
      }

      if ($('.fieldset-wrapper > .field-name-field-price input').val() == '0' || $('.fieldset-wrapper > .field-name-field-price input').val() == '0.00' || !$('.fieldset-wrapper > .field-name-field-price input').val()) {
        $('.fieldset-wrapper > .field-name-field-price').hide();
      }
    }
  };
}(jQuery));
