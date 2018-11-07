/**
 * JS that adds pager to top of table.
 **/
(function ($) {
  "use strict";
  Drupal.behaviors.form_validation_error = {
    attach: function (context, settings) {
      if ($('.js-transportpulje_form-added-pager').length == 0) {
        var view = $('.view-id-tpf_requests');
        var pager = view.find('.item-list:has(.pager)').first().clone();
        var table = view.find('.views-table');

        pager.addClass('js-transportpulje_form-added-pager');

        table.before(pager);
        table.before('<div style="height: 10px;">&nbsp;</div>')
      }
    }
  };
}(jQuery));
