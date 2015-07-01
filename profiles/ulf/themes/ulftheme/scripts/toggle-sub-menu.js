/**
 * Toggle sub menu
 *
 */


(function($) {
  // Function for toggle burger navigation.
  function toggle_sub() {
    var sub = $('.js-about-menu');

    $('.js-toggle-about').hover(function() {
      // If nav is open we close it.
      if (sub.hasClass('is-visible')) {

        // Hide menu.
        sub.addClass('is-hidden');
        sub.removeClass('is-visible');
      }

      // If nav is closed we open it.
      else {
        // show menu.
        sub.removeClass('is-hidden');
        sub.addClass('is-visible');
      }
    });
  }

  // Start the show
  $(document).ready(function () {
    toggle_sub();
  });

})(jQuery);
