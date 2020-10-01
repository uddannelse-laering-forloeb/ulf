<?php

/**
 * @file
 * ulf_course_providers.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ulf_course_providers_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editor_settings|user|user|form';
  $field_group->group_name = 'group_editor_settings';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editor settings',
    'weight' => '16',
    'children' => array(
      0 => 'field_editor_info',
      1 => 'field_bypass_workflow',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-editor-settings field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_editor_settings|user|user|form'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'field_profile_home_page',
      1 => 'field_profile_logo',
      2 => 'field_profile_phone',
      3 => 'field_profile_mail',
      4 => 'field_profile_cvr',
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
  $field_groups['group_metadata|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_placement|user|user|form';
  $field_group->group_name = 'group_placement';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lokation',
    'weight' => '11',
    'children' => array(
      0 => 'field_profile_map_placement',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-placement field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_placement|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Editor settings');
  t('Lokation');
  t('Organization');

  return $field_groups;
}
