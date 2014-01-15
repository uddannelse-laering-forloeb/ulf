/**
 * Logics for the node form
 *
 * Alot of fields change due to the selection of the target group field.
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
        selectionPreschool();
        break;

      // Primary school id.
      case '34':
        selectionPrimarySchool();
        break;

      // Youth education id.
      case '40':
        selectionYouth();
        break;
    }

    // Change the form on the fly.
    $('.form-select').change(function() {
      var selection = $(this).val();
      switch (selection) {
        // Preschool id.
        case '3':
          selectionPreschool();
          break;

        // School id.
        case '34':
          selectionPrimarySchool();
          break;

        // Youth education id.
        case '40':
          selectionYouth();
          break;
      }
    });
  });

  // Dagtilbud selected.
  function selectionPreschool() {
    // The sub target group field selection values.

    // Preschool selections
    $( ".form-item-field-target-group-sub-und-6" ).show();
    $( ".form-item-field-target-group-sub-und-9" ).show();
    $( ".form-item-field-target-group-sub-und-16" ).show();
    $( ".form-item-field-target-group-sub-und-8" ).show();
    $( ".form-item-field-target-group-sub-und-38" ).show();
    $( ".form-item-field-target-group-sub-und-35" ).show();
    $( ".form-item-field-target-group-sub-und-31" ).show();

    // Primary school selections
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

    // Youth selections
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

    // The happenings of the subjectfield gets its very own function to maintain a bit of order.
    subjectSelection('preschool');
  }

  // Grundskole selected
  function selectionPrimarySchool() {
    // The sub target group field selection values.

    // Preschool selections
    $( ".form-item-field-target-group-sub-und-6" ).hide();
    $( ".form-item-field-target-group-sub-und-9" ).hide();
    $( ".form-item-field-target-group-sub-und-16" ).hide();
    $( ".form-item-field-target-group-sub-und-8" ).hide();
    $( ".form-item-field-target-group-sub-und-38" ).hide();
    $( ".form-item-field-target-group-sub-und-35" ).hide();
    $( ".form-item-field-target-group-sub-und-31" ).hide();

    // Primary school selections
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

    // Youth selections
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

    // The happenings of the subject field gets its very own function to maintain a bit of order.
    subjectSelection('primary_school');
  }

  // Ungdomsuddannelse selected.
  function selectionYouth() {
    // The sub target group field selection values.

    // Preschool selections
    $( ".form-item-field-target-group-sub-und-6" ).hide();
    $( ".form-item-field-target-group-sub-und-9" ).hide();
    $( ".form-item-field-target-group-sub-und-16" ).hide();
    $( ".form-item-field-target-group-sub-und-8" ).hide();
    $( ".form-item-field-target-group-sub-und-38" ).hide();
    $( ".form-item-field-target-group-sub-und-35" ).hide();
    $( ".form-item-field-target-group-sub-und-31" ).hide();

    // Primary school selections
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

    // Youth selections
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

    // The happenings of the subject field gets its very own function to maintain a bit of order.
    subjectSelection('youth');
  }

  // The subject selection field has alot of choices which should change accordingly.
  function subjectSelection(choice) {
    //var myOpts = $(".field-name-field-subjects option").detach();
    //console.log(myOpts);
    // Choices reflect the target group field.
    switch (choice) {

      case 'preschool':

        $(".field-name-field-subjects select").append("<div id='appended'>Hello World</div>");
        $(".field-name-field-subjects option[value=17]").attach();
        $(".field-name-field-subjects option[value=22]").attach();
        $(".field-name-field-subjects option[value=24]").attach();
        $(".field-name-field-subjects option[value=33]").attach();
        break;

      case 'primary_school1':
        $(".field-name-field-subjects option[value=43]").attach();
        $(".field-name-field-subjects option[value=44]").attach();
        $(".field-name-field-subjects option[value=46]").attach();
        $(".field-name-field-subjects option[value=47]").attach();
        $(".field-name-field-subjects option[value=48]").attach();
        $(".field-name-field-subjects option[value=49]").attach();
        $(".field-name-field-subjects option[value=50]").attach();
        $(".field-name-field-subjects option[value=51]").attach();
        $(".field-name-field-subjects option[value=52]").attach();
        $(".field-name-field-subjects option[value=53]").attach();
        $(".field-name-field-subjects option[value=54]").attach();
        $(".field-name-field-subjects option[value=56]").attach();
        $(".field-name-field-subjects option[value=57]").attach();
        $(".field-name-field-subjects option[value=58]").attach();
        $(".field-name-field-subjects option[value=59]").attach();
        $(".field-name-field-subjects option[value=60]").attach();
        $(".field-name-field-subjects option[value=61]").attach();
        $(".field-name-field-subjects option[value=71]").attach();
        break;

      case 'youth1':
        $(".field-name-field-subjects option[value=72]").attach();
        $(".field-name-field-subjects option[value=73]").attach();
        $(".field-name-field-subjects option[value=74]").attach();
        $(".field-name-field-subjects option[value=75]").attach();
        $(".field-name-field-subjects option[value=77]").attach();
        $(".field-name-field-subjects option[value=78]").attach();
        $(".field-name-field-subjects option[value=79]").attach();
        $(".field-name-field-subjects option[value=80]").attach();
        $(".field-name-field-subjects option[value=82]").attach();
        $(".field-name-field-subjects option[value=84]").attach();
        $(".field-name-field-subjects option[value=86]").attach();
        $(".field-name-field-subjects option[value=88]").attach();
        $(".field-name-field-subjects option[value=89]").attach();
        $(".field-name-field-subjects option[value=90]").attach();
        $(".field-name-field-subjects option[value=91]").attach();
        $(".field-name-field-subjects option[value=92]").attach();
        $(".field-name-field-subjects option[value=93]").attach();
        $(".field-name-field-subjects option[value=94]").attach();
        $(".field-name-field-subjects option[value=95]").attach();
        $(".field-name-field-subjects option[value=96]").attach();
        $(".field-name-field-subjects option[value=97]").attach();
        $(".field-name-field-subjects option[value=98]").attach();
        $(".field-name-field-subjects option[value=99]").attach();
        $(".field-name-field-subjects option[value=100]").attach();
        $(".field-name-field-subjects option[value=101]").attach();
        $(".field-name-field-subjects option[value=103]").attach();
        $(".field-name-field-subjects option[value=104]").attach();
        $(".field-name-field-subjects option[value=105]").attach();
        $(".field-name-field-subjects option[value=107]").attach();
        $(".field-name-field-subjects option[value=108]").attach();
        $(".field-name-field-subjects option[value=109]").attach();
        $(".field-name-field-subjects option[value=110]").attach();
        $(".field-name-field-subjects option[value=111]").attach();
        $(".field-name-field-subjects option[value=112]").attach();
        $(".field-name-field-subjects option[value=113]").attach();
        $(".field-name-field-subjects option[value=114]").attach();
        $(".field-name-field-subjects option[value=115]").attach();
        $(".field-name-field-subjects option[value=116]").attach();
        $(".field-name-field-subjects option[value=118]").attach();
        $(".field-name-field-subjects option[value=119]").attach();
        $(".field-name-field-subjects option[value=120]").attach();
        $(".field-name-field-subjects option[value=121]").attach();
        $(".field-name-field-subjects option[value=122]").attach();
        $(".field-name-field-subjects option[value=123]").attach();
        $(".field-name-field-subjects option[value=124]").attach();
        $(".field-name-field-subjects option[value=125]").attach();
        $(".field-name-field-subjects option[value=126]").attach();
        $(".field-name-field-subjects option[value=127]").attach();
        $(".field-name-field-subjects option[value=129]").attach();
        break;
    }
  }
})(jQuery);


