/**
 * @file
 * Logic for the node form.
 *
 * A lot of fields change due to the selection of the target group field.
 */
(function($) {
  // Array to hold subgroup checkboxes
  var subgroup = [];

  // Called when the document has finished loading.
  Drupal.behaviors.ulfCourseFormAlter = {
    attach: function (context, settings) {

      /**
       * Initialize the form by hiding elements and attaching event handlers.
       */
      function initializeFormElements() {
        // Hide all target subgroups.
        $('.field-name-field-target-group-sub input').parent().hide();

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

        // Listen to change event on "target group" radio buttons in edit user
        // form and change form content based on the selection. This is also
        // called directly to be initialized on load.
        $('.field-name-field-target-group').change(targetGroupSelectionChanged);
        targetGroupSelectionChanged();

        // When "Full year" is unchecked show field group for duration else hide
        // the fields. This is also called when the form is initialized.
        var timeSelector = $('.field-name-field-period-full-year');
        timeSelector.click(function () { timePeriodSelectionChanged(timeSelector) });
        timePeriodSelectionChanged(timeSelector);

        // Handle the price (free) checkboxes and show/hide price input fields
        // based on free field state.
        var priceSelector = $('.field-name-field-free');
        priceSelector.click(function () { priceChanged(priceSelector) });
        priceChanged(priceSelector);

        // @TODO: Can this be removed?????
        // Hide empty fields for old price and and contact on course educators
        // content type.
        // If fields have values the editor should manually move them. When all
        // values have been moved the field should be deleted as part of a future
        // patch.
        if (!$('.field-name-field-course-contact-name input').val()) {
          $('.field-name-field-course-contact-name').hide();
        }
        if (!$('.field-name-field-course-contact-mail input').val()) {
          $('.field-name-field-course-contact-mail').hide();
        }
        if (!$('.field-name-field-course-phone input').val()) {
          $('.field-name-field-course-phone ').hide();
        }

        // @TODO: Please document this?
        if ($('.fieldset-wrapper > .field-name-field-price input').val() == '0' || $('.fieldset-wrapper > .field-name-field-price input').val() == '0.00' || !$('.fieldset-wrapper > .field-name-field-price input').val()) {
          $('.fieldset-wrapper > .field-name-field-price').hide();
        }
      }

      /**
       * Displays/hides Target Subgroup divs according to the callback function.
       *
       * @param {function} accept_callback
       *   The function that decided if the text is accepted or rejected.
       */
      function displayRelevantSubgroupByKeyword(accept_callback) {
        // Iterate each subgroup input.
        $.each(subgroup, function (index, arr) {
          var text = arr[0];
          var value = arr[1];

          // If the accept_callback, accepts the text show the input, else hide
          // it.
          var field = $('.field-name-field-target-group-sub input[value=' + value + ']');
          if (accept_callback(text)) {
            field.parent().show();
          }
          else {
            field.prop( "checked", false );
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

        $('.field-name-field-post-work').show();
        $('.field-name-field-educational-material').show();
        $('.field-name-field-subjects-youth').show();
        $('.is-school').show();
      }

      /**
       * Handle logic when Target Group selector is changed.
       */
      function targetGroupSelectionChanged() {
        // Hide all target groups.
        $('.field-name-field-target-group-sub input').parent().hide();

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

        // Fill the subgroup array, if no already done. Used in the
        // sub-selection function in the switch statement below.
        if (subgroup.length === 0) {
          $('.field-name-field-target-group-sub .option').each(function () {
            var val = $(this).siblings('input').val();
            var text = $(this).text();
            subgroup.push([text, val]);
          });
        }

        // Change form input elements based on selected target group.
        var selected = $(':checked', $('.field-name-field-target-group')).next().text().trim();
        switch (selected) {
          case 'Dagtilbud':
            selectionPreschool();
            break;

          case 'Grundskole':
            selectionPrimarySchool();
            break;

          case 'Ungdomsuddannelse':
            selectionYouth();
            break;

          default:
            // When the edit node page is first loaded (for new nodes) the
            // selection is empty and we fallback to "pre-school".
            // This should not happen - ever.
            selectionPreschool();
            break;
        }
      }

      /**
       * Hide/show the time period selection fields.
       *
       * @param {object} field
       *   jQuery element object.
       */
      function timePeriodSelectionChanged(field) {
        if ($(':checked', field).length) {
          $('#node_course_form_group_period').hide();
          $('.field-name-field-period').hide();
        }
        else {
          $('#node_course_form_group_period').show();
          $('.field-name-field-period').show();
        }
      }

      /**
       * Hide/show the price fields.
       *
       * @param {object} field
       *   jQuery element object.
       */
      function priceChanged(field) {
        if ($(':checked', field).length) {
          $('.field-name-field-collection-price').hide();
          $('.field-name-field-vary-price').hide();
        }
        else {
          $('.field-name-field-collection-price').show();
          $('.field-name-field-vary-price').show();
        }
      }

      // Get the show on the road.
      initializeFormElements();
    }
  };
}(jQuery));
