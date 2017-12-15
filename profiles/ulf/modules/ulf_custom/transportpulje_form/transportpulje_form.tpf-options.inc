<?php
/**
 * @file
 * transportpulje_form.tpf-options.inc
 * 
 * Helper functions to decide transport options.
 */

function _tpf_get_type(&$form_values) {
  if('tpf_school' === $form_values['institution_type'] && 'grade_6' <= $form_values['institution_grade']) {
    $distance = _tpf_get_distance($form_values);

    if(is_array($distance) && key_exists('scalar', $distance)) {
      if (6 >= $distance['scalar']) {
        return 'denied_distance';
      }
    } else {
      $form_values['distance_calc_failed'] = true;
    }
  }

  if (_tpf_node_is_private($form_values)) {
    return 'denied_private';
  }
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

function _tpf_node_is_private($form_values) {
  if (isset($form_values['course_dropdown'])) {
    $institution = taxonomy_term_load($form_values['institution_name']);
    $wrapper = entity_metadata_wrapper('taxonomy_term', $institution);
    $institution_type = $wrapper->field_tpf_relation->value();
    $node_wrapper = entity_metadata_wrapper('node', $form_values['course_dropdown']);
    $allowed_support = $node_wrapper->field_tpf_who_get_support->value();
    // @todo needs check for type of institution
    if ($allowed_support == 'municipal' && $institution_type == 'tpf_relation_private') {
      return TRUE;
    }
  }
  return FALSE;
}

function _tpf_get_distance($form_values) {
  // If course is unknown or user has entered an alternative address we use that.
  // Otherwise use the course location.
  if($form_values['course_not_found'] || $form_values['course_alt_address']) {
    $tpf_location = array(
      'street' => $form_values['street'],
      'postal_code' => $form_values['postal_code'],
      'city' => $form_values['city'],
      'country' => 'dk'
    );

    module_load_include('inc', 'location', 'location');
    $pos_to = location_latlon_exact($tpf_location);
  } else {
    $tpf_course = node_load($form_values['course_dropdown']);
    $tpf_to = field_get_items('node', $tpf_course, 'locations');

    // If the course is not displayed on map we have no coordinates - even if we have a valid address.
    if('0.000000' === $tpf_to['latitude']) {
      module_load_include('inc', 'location', 'location');
      $pos_to = location_latlon_exact($tpf_to);
    } else {
      $pos_to = array('lat' => $tpf_to['latitude'], 'lon' => $tpf_to['longitude']);
    }
  }

  // Get the institutions address/location
  $tpf_institution = taxonomy_term_load($form_values['institution_name']);
  $tpf_from = field_get_items('taxonomy_term', $tpf_institution, 'field_field_tpf_geo_location');
  $pos_from = empty($tpf_from[0]) ? null : array('lat' => $tpf_from[0]['latitude'], 'lon' => $tpf_from[0]['longitude']);

  // Abort if we have no 'to' position
  if(empty($pos_to) || '0.000000' === $pos_to['lat']) {
    return false;
  }

  // Abort if we have no 'from' position
  if(empty($pos_from) || '0.000000' === $pos_from['lat']) {
    return false;
  }

  return location_distance_between($pos_from, $pos_to);
}


function _tpf_is_private($form_values) {
  if (isset($form_values['institution_name'])) {
    $institution = taxonomy_term_load($form_values['institution_name']);
    $wrapper = entity_metadata_wrapper('taxonomy_term', $institution);
    $institution_type = $wrapper->field_tpf_relation->value();
    return ($institution_type == 'tpf_relation_private') ? TRUE : FALSE;
  }
  return FALSE;
}

function _tpf_not_course($form_values) {
  return (isset($form_values['course_dropdown']) ? FALSE : TRUE);
}

function _tpf_has_no_district($form_values) {
  if (isset($form_values['institution_name'])) {
    $institution = taxonomy_term_load($form_values['institution_name']);
    $wrapper = entity_metadata_wrapper('taxonomy_term', $institution);
    $district = $wrapper->field_tpf_district->value();
    // If school (Has district)
    if (!isset($district)) {
      return TRUE;
    }
  }

  return FALSE;
}

function _tpf_not_part_of_course_list($form_values) {
  if (isset($form_values['course_dropdown'])) {
    $node_wrapper = entity_metadata_wrapper('node', $form_values['course_dropdown']);
    $in_list = $node_wrapper->field_tpf_in_list->value();
    // Requested course is part of courselist. (Checkbox on node)
    if (!$in_list) {
      return TRUE;
    }
  }
  
  return FALSE;
}

function _tpf_part_of_course_list($form_values) {
  return TRUE;
}
