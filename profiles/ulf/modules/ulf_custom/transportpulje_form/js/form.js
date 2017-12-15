(function ($) {
  "use strict";
  Drupal.behaviors.transportpulje_form = {
    attach: function (context, settings) {

      // Load course.
      $('.form-item-course-dropdown').change(function (){
        var value = $('.form-item-course-dropdown .chosen-single span').html();
        var nid = $('.form-item-course-dropdown option').filter(function() { return ($(this).text() === value) }).val();
        $('#course_dropdown_address').load('fetch-address/' + nid);
      });
      
      // Setup dropdown lists.
      var inst_by_type = [];
      inst_by_type['school_options'] = '';
      inst_by_type['kindergarten_options'] = '';
      inst_by_type['nursery_options'] = '';
      inst_by_type['daycare_options'] = '';
      // Populate dropdown lists.
      $.each(settings.institutions, function(index, value) {
        if(typeof value.field_tpf_type['und'] !== 'undefined') {
          switch(value.field_tpf_type['und']['0']['value']) {
            case 'tpf_institution_type_school':
              inst_by_type['school_options'] += '<option value="'+ value.tid + '">' + value.name + '</option>';
              break;
            case 'tpf_institution_type_kindergarten':
              inst_by_type['kindergarten_options'] += '<option value="'+ value.tid + '">' + value.name + '</option>';
              break;
            case 'tpf_institution_type_nursery':
              inst_by_type['nursery_options'] += '<option value="'+ value.tid + '">' + value.name + '</option>';
              break;
            case 'tpf_institution_type_daycare':
              inst_by_type['daycare_options'] += '<option value="'+ value.tid + '">' + value.name + '</option>';
              break;
          }
        }
      });
      // Change the result of the dropdown based on type selected.
      $('.form-item-institution-type').change(function (){
        var inst_type = $('.form-item-institution-type').find(":selected").text();
        switch(inst_type) {
          case 'Skole':
            $('.form-item-institution-name #edit-institution-name').html(inst_by_type['school_options']);
            break;
          case 'Børnehave':
            $('.form-item-institution-name #edit-institution-name').html(inst_by_type['kindergarten_options']);
            break;
          case 'Vuggestue':
            $('.form-item-institution-name #edit-institution-name').html(inst_by_type['nursery_options']);
            break;
          case 'Dagplejer':
            $('.form-item-institution-name #edit-institution-name').html(inst_by_type['daycare_options']);
            break;
          default:
            break;
        }
      });
    }
  };
}(jQuery));

