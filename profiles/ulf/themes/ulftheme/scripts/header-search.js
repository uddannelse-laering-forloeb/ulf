/**
 *
 * Toggle search
 *
 */

(function($) {

  // Toggle search.
  function toggle_header_search() {
    // Hide search.
    $('.js-header-search').toggleClass('is-hidden');

    // Attach click function.
    $('.js-toggle-header-search').click(function() {
      // Toggle state class on mobile nav.
      $('.js-header-search').toggleClass('is-visible');

      // Disable default behaviour.
      return false;
    });

  }

  // Start the show.
  $(document).ready(function () {

    toggle_header_search();

  });

})(jQuery);
