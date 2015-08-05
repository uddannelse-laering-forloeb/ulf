<?php
/**
 * @file
 * ulf_course_providers.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ulf_course_providers_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|user|user|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Organization',
    'weight' => '6',
    'children' => array(
      0 => 'field_profile_address',
      1 => 'field_profile_city',
      2 => 'field_profile_home_page',
      3 => 'field_profile_logo',
      4 => 'field_profile_phone',
      5 => 'field_profile_postal_code',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Organization',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-metadata field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_metadata|user|user|form'] = $field_group;

  return $export;
}
