(function ($) {
  "use strict";
  Drupal.behaviors.transportpulje_form = {
    attach: function (context, settings) {
      console.log(settings);
      // Load course.
      $('.form-item-course-dropdown').change(function () {
        var value = $('.form-item-course-dropdown .chosen-single span').html();
        var nid = $('.form-item-course-dropdown option').filter(function() { return ($(this).text() === value) }).val();
        $('#course_dropdown_address').load('fetch-address/' + nid, function () {
          if($(this)[0].innerHTML.length == 0) {
            // When a course without address is selected.
            $('#edit-course-not-found').prop('checked', false).trigger('change');
            resetFields()
          }
          else {
            if (nid) {
              // When a course with address is selected.
              $('#edit-course-not-found').prop('checked', false).trigger('change');
              populateFields(this);
            } else {
              // When no course (- Select -) selected.
              $('#edit-course-not-found').prop('checked', true).trigger('change');
              resetFields()
            }
          }
        });
      });

      $('#edit-course-not-found').click(function () {
        if($(this).is(':checked')) {
          $('.form-item-course-dropdown .chosen-single').html('<span>- Vælg -</span>');
          $('.form-item-course-dropdown .result-selected').removeClass('result-selected');
        }
      });

      // When course is loaded with url parameter. And it's the first page load.
      var url_course_id = urlParam('course_id');
      if (url_course_id && !context[0]){
        $('#course_dropdown_address').load('fetch-address/' + url_course_id, function () {
          if($(this)[0].innerHTML.length == 0) {
            resetFields()
          }
          else {
            populateFields(this);
          }
        });
      }

      // Empty address fields.
      function resetFields() {
        $('#edit-street').val('');
        $('#edit-postal-code').val('');
        $('#edit-city').val('');
      }

      // Populate address fields
      function populateFields(element) {
        $('#edit-street').val($(element).find('#course_dropdown_street')[0].innerHTML);
        $('#edit-postal-code').val($(element).find('#course_dropdown_postal')[0].innerHTML);
        $('#edit-city').val($(element).find('#course_dropdown_city')[0].innerHTML);
      }

      // Setup dropdown lists.
      var inst_by_type = [];
      inst_by_type['school_options'] = '';
      inst_by_type['kindergarten_options'] = '';
      inst_by_type['nursery_options'] = '';
      inst_by_type['daycare_options'] = '';

      var sort_arr = [];
      for (var key in settings.institutions) {
        sort_arr.push(settings.institutions[key]);
      }

      var sorted = sort_arr.sort(function (a,b) {
        var nameA=a.name.toLowerCase(), nameB=b.name.toLowerCase();
        if (nameA < nameB)
          return -1;
        if (nameA > nameB)
          return 1;
        return 0;
      });

      $.each(sorted, function(index, value) {
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



      // Remove dash before child items.
      $('.form-item-institution-name option:not(:first-child)').text(
        function() {
          return this.text.replace('-', '');
        }
      );

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

      // Find url parameters
      function urlParam(name){
        var results = new RegExp('[\?&]' + name + '=([^]*)').exec(window.location.href);
        if (results==null){
          return null;
        }
        else{
          return results[1] || 0;
        }
      }
    }
  };
}(jQuery));

