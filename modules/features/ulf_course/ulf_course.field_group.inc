<?php
/**
 * @file
 * ulf_course.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ulf_course_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course|node|course|form';
  $field_group->group_name = 'group_course';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Forløbet',
    'weight' => '0',
    'children' => array(
      0 => 'field_target_group',
      1 => 'field_subject',
      2 => 'field_tags',
      3 => 'field_teaser',
      4 => 'field_short_description',
      5 => 'field_full_description',
      6 => 'field_image',
      7 => 'field_target_group_sub',
      8 => 'field_tilbudstype',
      9 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Forløbet',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-course field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_course|node|course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_info|node|course|form';
  $field_group->group_name = 'group_practical_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Målgruppe, varighed, pris',
    'weight' => '1',
    'children' => array(
      0 => 'field_duration',
      1 => 'field_duration_unit',
      2 => 'field_count',
      3 => 'field_price',
      4 => 'field_free',
      5 => 'field_unit_price',
      6 => 'field_price_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Målgruppe, varighed, pris',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-practical-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_practical_info|node|course|form'] = $field_group;

  return $export;
}
