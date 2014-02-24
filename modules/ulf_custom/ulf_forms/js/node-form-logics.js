/**
 * Logic for the node form.
 * A lot of fields change due to the selection of the target group field.
 */
(function($) {
  // Array to hold subgroup checkboxes
  var subgroup = new Array();

  /**
   * Displays and hides Target Subgroup divs according to the accept function.
   * @param acceptFunction The function that decided if the text is accepted or rejected.
   */
  function displayRelevantSubgroupByKeyword(acceptFunction) {
    // Iterate each subgroup input.
    $.each(subgroup, function(index, arr) {
      var text  = arr[0];
      var value = arr[1];

      // If the acceptFunction, accepts the text show the input, else hide it.
      if (acceptFunction(text)) {
        $(".field-name-field-target-group-sub input[value=" + value +"]").parent().show();
      } else {
        $(".field-name-field-target-group-sub input[value=" + value +"]").parent().hide();
      }
    });
  };

  /**
   * Function to call when the the Target Group selector is changed.
   * Updates which fields should be shown.
   */
  function changeSelection() {
    // Get the text of the target group selector.
    var selection = $( ".field-name-field-target-group .form-select option:selected").text();

    switch (selection) {
      // Preschool id.
      case 'Dagtilbud':
        selectionPreschool();
        break;

      // School id.
      case 'Grundskole':
        selectionPrimarySchool();
        break;

      // Youth education id.
      case 'Ungdomsuddannelse':
        selectionYouth();
        break;

      // Default is to show all options.
      default:
        displayRelevantSubgroupByKeyword(function() {
          return true;
        });
        break;
    }
  };

  /**
   * Sets up available fields when Preschool is selected.
   */
  function selectionPreschool() {
    // The sub target group field selection values.
    displayRelevantSubgroupByKeyword(function(text) {
      return (text.indexOf("år") != -1);
    });

    // Whole fields are either shown or hidden depending on main target group.
    $( ".field-name-field-post-work" ).hide();
    $( ".field-name-field-educational-material" ).hide();
    $( ".field-name-field-inspirational-material" ).show();
    $( ".field-name-field-material-suggestions" ).show();
    $( ".field-name-field-educational-goals" ).show();
    $( ".field-name-field-subjects-primary-school" ).hide();
    $( ".field-name-field-subjects-youth" ).hide();

    // We act on our own classes as well. This is useful for changing help texts (See purpose field for example).
    $( ".is-preschool" ).show();
    $( ".is-school" ).hide();
  }

  /**
   * Sets up available fields when Primary School is selected.
   */
  function selectionPrimarySchool() {
    // The sub target group field selection values.
    displayRelevantSubgroupByKeyword(function(text) {
      return (text.indexOf("klasse") != -1);
    });

    // Whole fields are either shown or hidden depending on main target group.
    $( ".field-name-field-post-work" ).show();
    $( ".field-name-field-educational-material" ).show();
    $( ".field-name-field-inspirational-material" ).hide();
    $( ".field-name-field-material-suggestions" ).hide();
    $( ".field-name-field-educational-goals" ).hide();
    $( ".field-name-field-subjects-primary-school" ).show();
    $( ".field-name-field-subjects-youth" ).hide();

    // We act on our own classes as well. This is useful for changing help texts (See purpose field for example).
    $( ".is-preschool" ).hide();
    $( ".is-school" ).show();
  }

  /**
   * Sets up available fields when Youth is selected.
   */
  function selectionYouth() {
    // The sub target group field selection values.
    displayRelevantSubgroupByKeyword(function(text) {
      return (text.indexOf("år") == -1 && text.indexOf("klasse") == -1);
    });

    // Whole fields are either shown or hidden depending on main target group.
    $( ".field-name-field-post-work" ).show();
    $( ".field-name-field-educational-material" ).show();
    $( ".field-name-field-inspirational-material" ).hide();
    $( ".field-name-field-material-suggestions" ).hide();
    $( ".field-name-field-educational-goals" ).hide();
    $( ".field-name-field-subjects-primary-school" ).hide();
    $( ".field-name-field-youth" ).show();

    // We act on our own classes as well. This is useful for changing help texts (See purpose field for example).
    $( ".is-preschool" ).hide();
    $( ".is-school" ).show();
  }

  // Called when the document has finished loading.
  $(document).ready(function() {
    // Hide filter selection.
    $('.filter-wrapper').hide();

    // Fill the subgroup array.
    $(".field-name-field-target-group-sub .option").each(function() {
      var val   = $(this).siblings("input").val();
      var text  = $(this).text();
      subgroup.push(new Array(text, val));
    });

    // When the Target Group selector is changed, change the subgroup options.
    $('.field-name-field-target-group .form-select').change(changeSelection);

    // Hide help text for preschool as default.
    $( ".is-preschool" ).hide();

    // Run a check when opening the node form. Used when editing existing nodes.
    changeSelection();

    // Hide group period as default. This is related to the full year checkbox being checked.
    if($( ".field-name-field-period-full-year .form-checkbox" ).is(":checked")) {
      $( "#node_course_form_group_period" ).hide();
    }

    // Hide field collection price if "Free" is checked. This is unchecked as default.
    if($( ".field-name-field-free .form-checkbox" ).is(":checked")) {
      $( ".field-name-field-collection-price" ).hide();
    }

    // When "Full year" is unchecked show field group for duration.
    $( ".field-name-field-period-full-year .form-checkbox" ).click(function() {
      if($(this).is(":checked")) {
        $( "#node_course_form_group_period" ).hide();
      } else {
        $( "#node_course_form_group_period" ).show();
      }
    });

    // When "Free" is unchecked show field collection "Price".
    $( ".field-name-field-free .form-checkbox" ).click(function() {
      if($(this).is(":checked")) {
        $( ".field-name-field-collection-price" ).hide();
      } else {
        $( ".field-name-field-collection-price" ).show();
      }
    });
  });

})(jQuery);


