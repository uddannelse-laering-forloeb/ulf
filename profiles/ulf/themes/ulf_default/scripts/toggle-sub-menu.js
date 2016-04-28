/**
 * Toggle sub menu
 *
 */


(function($) {
  // Function for toggle burger navigation.
  function toggle_sub() {
    $('.nav .js-toggle-expanded').hover(function() {
      // Get hovered item id
      var mlid = $(this).attr("mlid");

      // Get the sub menu we want to affect.
      var sub = $('.js-expanded-menu-'+ mlid);

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
