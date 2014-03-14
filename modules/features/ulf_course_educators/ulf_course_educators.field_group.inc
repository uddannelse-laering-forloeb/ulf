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
    'weight' => '4',
    'children' => array(
      0 => 'field_catering',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Yderligere information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'form-layout--gamma',
        'description' => '',
      ),
      'formatter' => 'collapsed',
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
      0 => 'field_full_description',
      1 => 'field_subject',
      2 => 'field_relevance_upper_school',
      3 => 'field_relevance_primary_school',
      4 => 'field_relevance_educators',
      5 => 'title',
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
      0 => 'field_course_contact_mail',
      1 => 'field_course_contact_name',
      2 => 'field_free',
      3 => 'field_period',
      4 => 'field_period_full_year',
      5 => 'field_price',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_materials|node|course_educators|form';
  $field_group->group_name = 'group_materials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_educators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Materialer',
    'weight' => '3',
    'children' => array(
      0 => 'field_educational_material',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Materialer',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-materials field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_materials|node|course_educators|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|course_educators|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_educators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Billeder/medier',
    'weight' => '2',
    'children' => array(
      0 => 'field_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Billeder/medier',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-media field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_media|node|course_educators|form'] = $field_group;

  return $export;
}
