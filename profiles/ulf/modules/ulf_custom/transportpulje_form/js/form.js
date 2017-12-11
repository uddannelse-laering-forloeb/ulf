(function ($) {
  Drupal.behaviors.transportpulje_form = {
    attach: function (context, settings) {
      $('.form-item-course-dropdown').change(function (){
        var value = $('.form-item-course-dropdown .chosen-single span').html();
        var nid = $('.form-item-course-dropdown option').filter(function() { return ($(this).text() === value) }).val();
        $('#course_dropdown_address').load('fetch-address/' + nid);
      });
    }
  };
}(jQuery));

