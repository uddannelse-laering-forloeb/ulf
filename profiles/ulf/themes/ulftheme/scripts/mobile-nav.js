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
