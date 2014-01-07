/**
 * Logics for the node form
 *
 */

(function($) {
  $(document).ready(function () {
    // The target group selection influences the display of the form.
    var selection = $( ".field-name-field-target-group .form-select" ).val();

    // Setup when the form is loaded.
    switch (selection) {
      // Preschool id.
      case '3':
        selection_preschool();
        break;

      // School id.
      case '34':
        selection_school();
        break;

      // Youth education id.
      case '40':
        selection_youth();
        break;
    }

    // Change the form on the fly.
    $('.form-select').change(function() {
      var selection = $(this).val();
      switch (selection) {
        // Preschool id.
        case '3':
          selection_preschool();
          break;

        // School id.
        case '34':
          selection_school();
          break;

        // Youth education id.
        case '40':
          selection_youth();
          break;
      }
    });
  });

  // Dagtilbud selected.
  function selection_preschool() {
    // The sub target group field selection values.
    $( ".form-item-field-target-group-sub-und-6" ).show();
    $( ".form-item-field-target-group-sub-und-9" ).show();
    $( ".form-item-field-target-group-sub-und-16" ).show();
    $( ".form-item-field-target-group-sub-und-8" ).show();
    $( ".form-item-field-target-group-sub-und-38" ).show();
    $( ".form-item-field-target-group-sub-und-35" ).show();
    $( ".form-item-field-target-group-sub-und-31" ).show();

    $( ".form-item-field-target-group-sub-und-4" ).hide();
    $( ".form-item-field-target-group-sub-und-25" ).hide();
    $( ".form-item-field-target-group-sub-und-5" ).hide();
    $( ".form-item-field-target-group-sub-und-10" ).hide();
    $( ".form-item-field-target-group-sub-und-39" ).hide();
    $( ".form-item-field-target-group-sub-und-26" ).hide();
    $( ".form-item-field-target-group-sub-und-12" ).hide();
    $( ".form-item-field-target-group-sub-und-29" ).hide();
    $( ".form-item-field-target-group-sub-und-28" ).hide();
    $( ".form-item-field-target-group-sub-und-37" ).hide();
    $( ".form-item-field-target-group-sub-und-13" ).hide();

    $( ".form-item-field-target-group-sub-und-14" ).hide();
    $( ".form-item-field-target-group-sub-und-32" ).hide();
    $( ".form-item-field-target-group-sub-und-2" ).hide();
    $( ".form-item-field-target-group-sub-und-7" ).hide();

    // Whole fields are either shown or hidden depending on main target group.
    $( ".field-name-field-post-work" ).hide();
    $( ".field-name-field-educational-material" ).hide();
    $( ".field-name-field-inspirational-material" ).show();
    $( ".field-name-field-material-suggestions" ).show();
    $( ".field-name-field-educational-goals" ).show();

    // We act on our own classes as well. This is usefull for changing help texts (See purpose field for example).
    $( ".is-preschool" ).show();
    $( ".is-school" ).hide();
  }

  // Grundskole selected
  function selection_school() {
    // The sub target group field selection values.
    $( ".form-item-field-target-group-sub-und-6" ).hide();
    $( ".form-item-field-target-group-sub-und-9" ).hide();
    $( ".form-item-field-target-group-sub-und-16" ).hide();
    $( ".form-item-field-target-group-sub-und-8" ).hide();
    $( ".form-item-field-target-group-sub-und-38" ).hide();
    $( ".form-item-field-target-group-sub-und-35" ).hide();
    $( ".form-item-field-target-group-sub-und-31" ).hide();

    $( ".form-item-field-target-group-sub-und-4" ).show();
    $( ".form-item-field-target-group-sub-und-25" ).show();
    $( ".form-item-field-target-group-sub-und-5" ).show();
    $( ".form-item-field-target-group-sub-und-10" ).show();
    $( ".form-item-field-target-group-sub-und-39" ).show();
    $( ".form-item-field-target-group-sub-und-26" ).show();
    $( ".form-item-field-target-group-sub-und-12" ).show();
    $( ".form-item-field-target-group-sub-und-29" ).show();
    $( ".form-item-field-target-group-sub-und-28" ).show();
    $( ".form-item-field-target-group-sub-und-37" ).show();
    $( ".form-item-field-target-group-sub-und-13" ).show();

    $( ".form-item-field-target-group-sub-und-14" ).hide();
    $( ".form-item-field-target-group-sub-und-32" ).hide();
    $( ".form-item-field-target-group-sub-und-2" ).hide();
    $( ".form-item-field-target-group-sub-und-7" ).hide();

    // Whole fields are either shown or hidden depending on main target group.
    $( ".field-name-field-post-work" ).show();
    $( ".field-name-field-educational-material" ).show();
    $( ".field-name-field-inspirational-material" ).hide();
    $( ".field-name-field-material-suggestions" ).hide();
    $( ".field-name-field-educational-goals" ).hide();

    // We act on our own classes as well. This is usefull for changing help texts (See purpose field for example).
    $( ".is-preschool" ).hide();
    $( ".is-school" ).show();
  }

  // Ungdomsuddannelse selected.
  function selection_youth() {
    // The sub target group field selection values.
    $( ".form-item-field-target-group-sub-und-6" ).hide();
    $( ".form-item-field-target-group-sub-und-9" ).hide();
    $( ".form-item-field-target-group-sub-und-16" ).hide();
    $( ".form-item-field-target-group-sub-und-8" ).hide();
    $( ".form-item-field-target-group-sub-und-38" ).hide();
    $( ".form-item-field-target-group-sub-und-35" ).hide();
    $( ".form-item-field-target-group-sub-und-31" ).hide();

    $( ".form-item-field-target-group-sub-und-4" ).hide();
    $( ".form-item-field-target-group-sub-und-25" ).hide();
    $( ".form-item-field-target-group-sub-und-5" ).hide();
    $( ".form-item-field-target-group-sub-und-10" ).hide();
    $( ".form-item-field-target-group-sub-und-39" ).hide();
    $( ".form-item-field-target-group-sub-und-26" ).hide();
    $( ".form-item-field-target-group-sub-und-12" ).hide();
    $( ".form-item-field-target-group-sub-und-29" ).hide();
    $( ".form-item-field-target-group-sub-und-28" ).hide();
    $( ".form-item-field-target-group-sub-und-37" ).hide();
    $( ".form-item-field-target-group-sub-und-13" ).hide();

    $( ".form-item-field-target-group-sub-und-14" ).show();
    $( ".form-item-field-target-group-sub-und-32" ).show();
    $( ".form-item-field-target-group-sub-und-2" ).show();
    $( ".form-item-field-target-group-sub-und-7" ).show();

    // Whole fields are either shown or hidden depending on main target group.
    $( ".field-name-field-post-work" ).show();
    $( ".field-name-field-educational-material" ).show();
    $( ".field-name-field-inspirational-material" ).hide();
    $( ".field-name-field-material-suggestions" ).hide();
    $( ".field-name-field-educational-goals" ).hide();

    // We act on our own classes as well. This is usefull for changing help texts (See purpose field for example).
    $( ".is-preschool" ).hide();
    $( ".is-school" ).show();
  }
})(jQuery);
