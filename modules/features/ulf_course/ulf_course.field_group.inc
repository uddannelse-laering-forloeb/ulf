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
  $field_group->identifier = 'group_course_sub|node|course|form';
  $field_group->group_name = 'group_course_sub';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Aktiviteter, baggrundsviden og efterbehandling',
    'weight' => '7',
    'children' => array(
      0 => 'field_activities',
      1 => 'field_background_knowledge',
      2 => 'field_post_work',
      3 => 'field_material_suggestions',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-sub field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_course_sub|node|course|form'] = $field_group;

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
      0 => 'field_full_description',
      1 => 'field_image',
      2 => 'field_tags',
      3 => 'field_target_group',
      4 => 'field_teaser',
      5 => 'field_purpose',
      6 => 'field_educational_goals',
      7 => 'title',
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
  $field_group->identifier = 'group_duration|node|course|form';
  $field_group->group_name = 'group_duration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_practical_information';
  $field_group->data = array(
    'label' => 'Varighed',
    'weight' => '21',
    'children' => array(
      0 => 'field_duration',
      1 => 'field_duration_unit',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Varighed',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-duration field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_duration|node|course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_facilities|node|course|form';
  $field_group->group_name = 'group_facilities';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Faciliteter',
    'weight' => '4',
    'children' => array(
      0 => 'field_facilities',
      1 => 'field_facilities_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-facilities field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_facilities|node|course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_period|node|course|form';
  $field_group->group_name = 'group_period';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Periode',
    'weight' => '2',
    'children' => array(
      0 => 'field_period',
      1 => 'field_period_info',
      2 => 'field_period_full_year',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-period field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_period|node|course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_information|node|course|form';
  $field_group->group_name = 'group_practical_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Praktisk information',
    'weight' => '1',
    'children' => array(
      0 => 'field_collection_price',
      1 => 'field_count',
      2 => 'field_offer_type',
      3 => 'field_price_info',
      4 => 'field_subject',
      5 => 'field_target_group_sub',
      6 => 'field_free',
      7 => 'group_duration',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-practical-information field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_practical_information|node|course|form'] = $field_group;

  return $export;
}
