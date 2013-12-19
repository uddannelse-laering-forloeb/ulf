<?php
/**
 * @file
 * ulf_course_educators.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ulf_course_educators_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_edu_course_sub|node|course_educators|form';
  $field_group->group_name = 'group_edu_course_sub';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_educators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Yderligere information',
    'weight' => '2',
    'children' => array(
      0 => 'field_relevancy_prim_school',
      1 => 'field_relevancy_upper_school',
      2 => 'field_relevancy_educators',
      3 => 'field_catering',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Yderligere information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'form-layout--gamma',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_edu_course_sub|node|course_educators|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_edu_course|node|course_educators|form';
  $field_group->group_name = 'group_edu_course';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_educators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Kurset',
    'weight' => '0',
    'children' => array(
      0 => 'field_subject',
      1 => 'field_full_description',
      2 => 'field_image',
      3 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Kurset',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'form-layout--alfa',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_edu_course|node|course_educators|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_edu_practical_info|node|course_educators|form';
  $field_group->group_name = 'group_edu_practical_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_educators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Praktisk information',
    'weight' => '1',
    'children' => array(
      0 => 'field_period',
      1 => 'field_period_full_year',
      2 => 'field_price',
      3 => 'field_free',
      4 => 'field_course_contact_name',
      5 => 'field_course_contact_mail',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Praktisk information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'form-layout--beta',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_edu_practical_info|node|course_educators|form'] = $field_group;

  return $export;
}
