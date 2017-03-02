/**
 * Toggle modal
 *
 */

(function($) {
  // Function for toggle burger navigation.
  function toggle_modal() {
    var modal = $('.js-modal');
    var modalDialog = $('.js-modal-dialog');
    var body = $('html');

    $('.js-toggle-modal').bind('touchstart click', function(e) {
      // If fired on 'touchstart' prevent 'click' from firing,
      // and closing dialog
      e.stopPropagation(); e.preventDefault();

      // If nav is open we close it.
      if (modal.hasClass('is-visible')) {

        // Hide menu.
        modal.addClass('is-hidden');
        modal.removeClass('is-visible');
        modalDialog.addClass('is-hidden');
        modalDialog.removeClass('is-visible');
        body.removeClass('is-locked');
      }

      // If nav is closed we open it.
      else {
        // show menu.
        modal.removeClass('is-hidden');
        modal.addClass('is-visible');
        modalDialog.removeClass('is-hidden');
        modalDialog.addClass('is-visible');
        body.addClass('is-locked');
      }
    });
  }

  // Start the show
  $(document).ready(function () {
    toggle_modal();
  });

})(jQuery);
