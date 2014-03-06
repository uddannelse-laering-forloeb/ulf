/**
 * Logic for the node form.
 * A lot of fields change due to the selection of the target group field.
 */
(function($) {


  // Array to hold subgroup checkboxes
  var subgroup = new Array();

  /**
   * Function to call when the the Target Group selector is changed.
   * Updates which fields should be shown.
   */
  function changeSelection(selected, targetGroupSelections) {

    // Hide all target groups.
    $(".field-name-field-target-group-sub input").parent().hide()

    // Hide specific fields only relevant for certain target groups.
    $( ".field-name-field-post-work" ).hide();
    $( ".field-name-field-educational-material" ).hide();
    $( ".field-name-field-educational-goals" ).hide();
    $( ".field-name-field-subjects-primary-school" ).hide();
    $( ".field-name-field-subjects-youth" ).hide();
    // Used in field help text.
    $( ".is-school" ).hide();
    $( ".field-name-field-inspirational-material" ).hide();
    $( ".field-name-field-material-suggestions" ).hide();

    // Show stuff depending on what the selection array contains.
    if ( $.inArray('Dagtilbud ', targetGroupSelections) > -1 ) {
      selectionPreschool();
    }
    if ( $.inArray('Grundskole ', targetGroupSelections) > -1 ) {
      selectionPrimarySchool();
    }
    if ( $.inArray('Ungdomsuddannelse ', targetGroupSelections) > -1 ) {
      selectionYouth();
    }
  };


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
      }
    });
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
    $( ".field-name-field-inspirational-material" ).show();
    $( ".field-name-field-material-suggestions" ).show();
    $( ".field-name-field-educational-goals" ).show();
    $( ".is-preschool" ).show();
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
    $( ".field-name-field-subjects-primary-school" ).show();
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
    $( ".field-name-field-subjects-youth" ).show();
    $( ".is-school" ).show();
  }



  // Called when the document has finished loading.
  $(document).ready(function() {

    /// --- A lot of actions related to click events

    // Change stuff when a new target group is added or removed.
    $( ".field-name-field-target-group .form-checkbox" ).click(function(){
      // The actual clicked item.
      var checked = ($(this).val());
      var selected = $(".field-name-field-target-group .form-item-field-target-group-und-" + checked + " label").text();

      // An array containing checked of items of the target group field.
      var targetGroupSelections = new Array();
      $('.field-name-field-target-group .form-checkbox').each(function () {
        if (this.checked) {
          var value = ($(this).val());
          targetGroupSelections.push($(".field-name-field-target-group .form-item-field-target-group-und-" + value + " label").text());
        }
      });
      changeSelection(selected, targetGroupSelections);
    });

    // When "Full year" is unchecked show field group for duration.
    $( ".field-name-field-period-full-year .form-checkbox" ).click(function() {
      if($(this).is(":checked")) {
        $( "#node_course_form_group_period" ).hide();
        $( ".field-name-field-period" ).hide();
      } else {
        $( "#node_course_form_group_period" ).show();
        $( ".field-name-field-period" ).show();
      }
    });

    // When "Free" is unchecked show field collection "Price".
    $( ".field-name-field-free .form-checkbox" ).click(function() {
      if($(this).is(":checked")) {
        $( ".field-name-field-collection-price" ).hide();
        $( ".field-name-field-price" ).hide();
        $( ".field-name-field-vary-price" ).hide();
      } else {
        $( ".field-name-field-collection-price" ).show();
        $( ".field-name-field-price" ).show();
        $( ".field-name-field-vary-price" ).show();
      }
    });

    // If  "vary_duration" is checked disable "Duration" and "duration unit".
    $( ".field-name-field-vary-duration .form-checkbox" ).click(function() {
      if($(this).is(":checked")) {
        $( ".field-name-field-duration .form-text" ).attr('readonly', true);
        $( ".field-name-field-duration-unit .form-select" ).attr('disabled', true);
        $( ".field-name-field-duration .form-text" ).css('background', '#eee');
      } else {
        $( ".field-name-field-duration .form-text" ).attr('readonly', false);
        $( ".field-name-field-duration-unit .form-select" ).attr('disabled', false);
        $( ".field-name-field-duration .form-text" ).css('background', '#fff');
      }
    });

    // When "vary_price" is checked disable "Price".
    $( ".field-name-field-vary-price .form-checkbox" ).click(function() {
      if($(this).is(":checked")) {
        $( ".field-name-field-price .form-text" ).attr('readonly', true);
        $( ".field-name-field-unit-price .form-select" ).attr('disabled', true);
        $( ".field-name-field-price .form-text" ).css('background', '#eee');
      } else {
        $( ".field-name-field-price .form-text" ).attr('readonly', false);
        $( ".field-name-field-unit-price .form-select" ).attr('disabled', false);
        $( ".field-name-field-price .form-text").css('background', '#fff');
      }
    });

    // When the Target Group selector is changed, change the subgroup options.
    $('.field-name-field-target-group .form-select').change(changeSelection);

    /// ------ Stuff that happens when the form is first loaded.

    // We add border width in js to reach seven theme.
    $('#node_course_form_group_practical_information').css('border-width', '2px');

    // Fill the subgroup array.
    $(".field-name-field-target-group-sub .option").each(function() {
      var val   = $(this).siblings("input").val();
      var text  = $(this).text();
      subgroup.push(new Array(text, val));
    });

    // Run a check when opening the node form. Used when editing existing nodes.
    // An array containing checked of items of the target group field.
    var targetGroupSelections = new Array();
    $('.field-name-field-target-group .form-checkbox').each(function () {
      if (this.checked) {
        var value = ($(this).val());
        console.log(value);
        targetGroupSelections.push($(".field-name-field-target-group .form-item-field-target-group-und-" + value + " label").text());
      }
    });
    changeSelection('startup', targetGroupSelections);

    // Hide group period as default. This is related to the full year checkbox being checked.
    if($( ".field-name-field-period-full-year .form-checkbox" ).is(":checked")) {
      $( "#node_course_form_group_period" ).hide();
      $( ".field-name-field-period" ).hide();
    }

    // Hide field collection price if "Free" is checked. This is unchecked as default.
    if($( ".field-name-field-free .form-checkbox" ).is(":checked")) {
      $( ".field-name-field-collection-price" ).hide();
      $( ".field-name-field-price" ).hide();
    }

    // Hide filter selection on all fields.
    $('.filter-wrapper').hide();
  });
})(jQuery);


