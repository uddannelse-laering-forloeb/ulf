/**
 * Hide rich text selection.
 */
(function($) {
  // Called when the document has finished loading.
  Drupal.behaviors.ulfFormRichTextHide = {
    attach: function () {
      // Hide filter selections.
      $('.filter-wrapper').hide();
    }
  };
}(jQuery));
