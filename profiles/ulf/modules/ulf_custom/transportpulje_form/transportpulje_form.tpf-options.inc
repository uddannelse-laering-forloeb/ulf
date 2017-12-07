<?php
/**
 * @file
 * transportpulje_form.tpf-options.inc
 * 
 * Helper functions to decide transport options.
 */

function _tpf_get_type($form_values) {
  if (_tpf_is_private($form_values)) {
    return 'is_private';
  }
  if (_tpf_not_course($form_values)) {
    return 'is_not_course';
  }
  if (_tpf_has_no_district($form_values)) {
    return 'has_no_district';
  }
  if (_tpf_not_part_of_course_list($form_values)) {
    return 'not_part_of_course_list';
  }
  if (_tpf_part_of_course_list($form_values)) {
    return 'part_of_course_list';
  }
}


function _tpf_is_private($form_values) {
  $institution = taxonomy_term_load($form_values['institution_name']);
  $wrapper = entity_metadata_wrapper('taxonomy_term', $institution);
  $institution_type = $wrapper->field_tpf_relation->value();
  return ($institution_type == 'tpf_relation_private') ? TRUE : FALSE;
}

function _tpf_not_course($form_values) {
  return (isset($form_values['course_dropdown']) ? TRUE : FALSE);
}

function _tpf_has_no_district($form_values) {
  return TRUE;
}

function _tpf_not_part_of_course_list($form_values) {
  // Check on node field.
  return TRUE;
}

function _tpf_part_of_course_list($form_values) {
  return TRUE;
}