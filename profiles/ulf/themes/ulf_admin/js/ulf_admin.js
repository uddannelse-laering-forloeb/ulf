(function ($) {
  Drupal.behaviors.ulfAutosaveAlter = {
    attach: function (context, settings) {
      if ($('#autosave-status > #operations').length){
        $('#autosave-status').addClass('is-popup');
      }
      else {
        $('#autosave-status').removeClass('is-popup');
      }
    }
  };
}(jQuery));