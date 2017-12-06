(function ($) {
  Drupal.behaviors.transportpulje_form = {
    attach: function (context, settings) {
      $('#transportpulje-form-entityform-edit-form', context).once('transportpulje_form', function () {
        console.log('lorem ipsum');
        console.log(Drupal.settings.transportpulje_form.key);
      });
    }
  };
}(jQuery));

