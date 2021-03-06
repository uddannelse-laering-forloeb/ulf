/**
 * @file
 * Modify form based on selection of primary target group
 */

/**
 * Attaches to handle vocabulary show/hide functionality.
 */
(function ($) {
  // Called when the document has finished loading.
  Drupal.behaviors.ulfCourseTargetGroupSelect = {
    attach: function (context, settings) {
      // Act on courses target group change.
      $('.field-name-field-relevance-educators').once('proccessed', function () {
        $(this).on('change', function () {
          showCourseRelevancy(settings);
        });
        showCourseRelevancy(settings);
      });
    }
  };

  function showCourseRelevancy(settings) {
    var selected = [];
    var fields_to_display = [];
    // Create array of tids.
    $('.field-name-field-relevance-educators input:checked').each(function() {
      selected.push($(this).val());
    });
    // Loop through all taxonomy_subject_reference fields to get tids we should act on.
    selected.forEach(function(tid) {
      settings.primary_target_group.vocabulary.forEach(function(element) {
        if (typeof element.field_taxonomy_subject_reference.und !== 'undefined') {
          if (tid == element.tid) {
            element.field_taxonomy_subject_reference.und.forEach(function (values) {
              // Create array of tids that should be displayed.
              fields_to_display[values.target_id] = values.target_id;
            });
          }
        }
      });
    });

    // Hide all relevant vocabularies.
    settings.primary_target_group.vocabulary.forEach(function(element) {
      if (typeof element.field_taxonomy_subject_reference.und !== 'undefined') {
        element.field_taxonomy_subject_reference.und.forEach(function(values) {
          $('.field-type-taxonomy-term-reference[data-vocabulary-id=' + values.target_id + ']').hide().addClass('subjects-is-hidden');
        });
      }

    });

    // Show vocabularies from fields_to_display list.
    $('.field-type-taxonomy-term-reference').each(function() {
      if (inArray($(this).data('vocabulary-id'), fields_to_display)) {
        $('.field-type-taxonomy-term-reference[data-vocabulary-id=' + $(this).data('vocabulary-id') + ']').show().removeClass('subjects-is-hidden');
      }
    });

    // Unset hidden checkboxes.
    $('.field-type-taxonomy-term-reference.subjects-is-hidden input').prop('checked', false);
  }

  /**
   * A simple in array check function.
   *
   * @param needle
   * @param haystack
   * @returns {boolean}
   */
  function inArray(needle, haystack) {
    var length = haystack.length;
    for(var i = 0; i < length; i++) {
      if(haystack[i] == needle) return true;
    }
    return false;
  }
}(jQuery));
