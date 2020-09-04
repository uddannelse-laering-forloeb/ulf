<?php

/**
 * @file
 * ulf_course_providers.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ulf_course_providers_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_profile_cvr'.
  $field_bases['field_profile_cvr'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_profile_cvr',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
