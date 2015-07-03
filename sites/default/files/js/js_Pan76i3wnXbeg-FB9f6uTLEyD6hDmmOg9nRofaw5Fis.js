/**
 * Mobile navigation
 *
 */

(function($) {

  // Toggle mobile navigation.
  function toggle_mobile_nav() {

    // Attach click function.
    $('.js-toggle-mobile-nav').click(function() {
      // Toggle state class on page wrapper.
      $('.js-page-wrapper').toggleClass('is-moved-left');

      // Toggle state class on mobile nav.
      $('.js-mobile-nav').toggleClass('is-open');

      // Toggle state class facets.
      $('.js-nav--toggle-facets').toggleClass('is-visible');

      // Disable default behaviour.
      return false;
    });

  }

  // Start the show.
  $(document).ready(function () {

    toggle_mobile_nav();

  });

})(jQuery);
;
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
;
