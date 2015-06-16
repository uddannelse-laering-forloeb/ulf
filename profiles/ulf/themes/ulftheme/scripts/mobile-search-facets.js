/**
 * Mobile search facets
 *
 */

(function($) {

  // Toggle mobile navigation
  function toggle_mobile_search_facets() {

    // Attach click function
    $('.js-toggle-mobile-search-facets').click(function() {

      // Toggle state class on mobile search facets
      $('.js-mobile-search-facets').toggleClass('is-visible');

    });

  }

  // Start the show
  $(document).ready(function () {

    toggle_mobile_search_facets();

  });

})(jQuery);
