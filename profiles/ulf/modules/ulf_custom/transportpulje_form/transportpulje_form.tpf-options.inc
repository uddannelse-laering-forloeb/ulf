<?php

/**
 * @file
 *
 * Helper functions to decide transport options.
 */

/**
 * A list of checks to perform to decide how the form should react next.
 *
 * @param array $form_values
 *   The values entered in the form.
 *
 * @return string
 *   The type of action to take next.
 */
function _tpf_get_type(array &$form_values) {
  if ('tpf_school' === $form_values['institution_type'] && 'grade_6' <= $form_values['institution_grade']) {
    $distance = _tpf_get_distance($form_values);

    if (is_array($distance) && array_key_exists('scalar', $distance)) {
      if (6 >= $distance['scalar']) {
        return 'denied_distance';
      }
    }
    else {
      $form_values['distance_calc_failed'] = TRUE;
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
  if (_tpf_part_of_course_list()) {
    return TRUE;
  }
}

/**
 * Check if the selected course can be applied to private institutions.
 *
 * @param array $form_values
 *   The values entered in the form.
 *
 * @return bool
 *   True if private requesting municipal only course.
 */
function _tpf_node_is_private(array $form_values) {
  $institution = taxonomy_term_load($form_values['institution_name']);
  $wrapper = entity_metadata_wrapper('taxonomy_term', $institution);
  $institution_type = $wrapper->field_tpf_relation->value();
  // Deny if private requesting municipal only course.
  if (!empty($form_values['course_dropdown'])) {
    $node_wrapper = entity_metadata_wrapper('node', $form_values['course_dropdown']);
    $allowed_support = $node_wrapper->field_tpf_who_get_support->value();
    if ($allowed_support == 'municipal' && $institution_type == 'tpf_relation_private') {
      return TRUE;
    }
  }
  // Deny if private requesting course they typed manually.
  else {
    if ($institution_type == 'tpf_relation_private') {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Check if the range requirements are honored.
 *
 * @param array $form_values
 *   The values entered in the form.
 *
 * @return array|bool|null
 *   True if i a distance could be calculated, false if either
 *   to or from missing.
 */
function _tpf_get_distance(array $form_values) {
  // If course is unknown or user has entered an alternative address we use
  // that. Otherwise use the course location.
  $pos_to = NULL;

  if (!empty($form_values['street']) && !empty($form_values['postal_code']) && !empty($form_values['city'])) {
    $tpf_location = array(
      'street' => $form_values['street'],
      'postal_code' => $form_values['postal_code'],
      'city' => $form_values['city'],
      'country' => 'dk',
    );

    module_load_include('inc', 'location', 'location');
    $pos_to = location_latlon_exact($tpf_location);
  }

  // Get the institutions address/location.
  $tpf_institution = taxonomy_term_load($form_values['institution_name']);
  $tpf_from = field_get_items('taxonomy_term', $tpf_institution, 'field_field_tpf_geo_location');
  $pos_from = empty($tpf_from[0]) ? NULL : array(
    'lat' => $tpf_from[0]['latitude'],
    'lon' => $tpf_from[0]['longitude']
  );

  // Abort if we have no 'to' position.
  if (empty($pos_to) || '0.000000' === $pos_to['lat']) {
    return FALSE;
  }

  // Abort if we have no 'from' position.
  if (empty($pos_from) || '0.000000' === $pos_from['lat']) {
    return FALSE;
  }

  return location_distance_between($pos_from, $pos_to);
}

/**
 * Check if the institution requesting is private.
 *
 * @param array $form_values
 *   The values entered in the form.
 *
 * @return bool
 *   True if the institution requesting is private.
 */
function _tpf_is_private(array $form_values) {
  if (isset($form_values['institution_name'])) {
    $institution = taxonomy_term_load($form_values['institution_name']);
    $wrapper = entity_metadata_wrapper('taxonomy_term', $institution);
    $institution_type = $wrapper->field_tpf_relation->value();
    return ($institution_type == 'tpf_relation_private') ? TRUE : FALSE;
  }
  return FALSE;
}

/**
 * Check if the request is made on behalf of an existing course.
 *
 * @param array $form_values
 *   The values entered in the form.
 *
 * @return bool
 *   True if course is not existing on site.
 */
function _tpf_not_course(array $form_values) {
  return (empty($form_values['course_dropdown']) ? TRUE : FALSE);
}

/**
 * Check if the institution is a school type (Has a district)
 *
 * @param array $form_values
 *   The values entered in the form.
 *
 * @return bool
 *   True if the selected institution does not have a district.
 */
function _tpf_has_no_district(array $form_values) {
  if (isset($form_values['institution_name'])) {
    $institution = taxonomy_term_load($form_values['institution_name']);
    $wrapper = entity_metadata_wrapper('taxonomy_term', $institution);
    $district = $wrapper->field_tpf_district->value();
    // If school (Has district)
    return !isset($district);
  }

  return FALSE;
}

/**
 * Check if selected node is not part of course list.
 *
 * @param array $form_values
 *   The values entered in the form.
 *
 * @return bool
 *   True if the node selected is not in course list (boolean field on node).
 */
function _tpf_not_part_of_course_list(array $form_values) {
  if (!empty($form_values['course_dropdown'])) {
    $node_wrapper = entity_metadata_wrapper('node', $form_values['course_dropdown']);
    $in_list = $node_wrapper->field_tpf_in_list->value();
    // Requested course is part of courselist. (Checkbox on node)
    return !$in_list;
  }

  return FALSE;
}
