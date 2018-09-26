<?php
/**
 * @file
 * ulf_course_educators.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ulf_course_educators_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|course_educators|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_educators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Vis kontaktformular / Skjul kontaktformular',
    'weight' => '61',
    'children' => array(
      0 => 'field_message_form',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Vis kontaktformular / Skjul kontaktformular',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_contact|node|course_educators|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_duration|node|course_educators|form';
  $field_group->group_name = 'group_duration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_educators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Varighed og pris',
    'weight' => '2',
    'children' => array(
      0 => 'field_free',
      1 => 'field_price',
      2 => 'field_collection_price',
      3 => 'field_duration',
      4 => 'field_duration_description',
      5 => 'field_duration_unit',
      6 => 'field_price_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Varighed og pris',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-duration field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_duration|node|course_educators|form'] = $field_group;

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
    'weight' => '7',
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
  $field_groups['group_edu_course_sub|node|course_educators|form'] = $field_group;

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
      1 => 'field_relevance_educators',
      2 => 'field_relevance_primary_school',
      3 => 'field_relevance_upper_school',
      4 => 'field_subject',
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
  $field_groups['group_edu_course|node|course_educators|form'] = $field_group;

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
      2 => 'field_course_phone',
      3 => 'field_educational_goals',
      4 => 'field_profile_contact',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Praktisk information',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'form-layout--beta',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_edu_practical_info|node|course_educators|form'] = $field_group;

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
    'weight' => '6',
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
  $field_groups['group_materials|node|course_educators|form'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_image',
      1 => 'field_video',
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
  $field_groups['group_media|node|course_educators|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_period|node|course_educators|form';
  $field_group->group_name = 'group_period';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_educators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Periode',
    'weight' => '4',
    'children' => array(
      0 => 'field_period',
      1 => 'field_period_full_year',
      2 => 'field_period_info',
      3 => 'scheduler_settings',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Periode',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-period field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_period|node|course_educators|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_placement|node|course_educators|form';
  $field_group->group_name = 'group_placement';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_educators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lokation',
    'weight' => '8',
    'children' => array(
      0 => 'field_map_placement',
      1 => 'field_place',
      2 => 'locations',
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
  $field_groups['group_placement|node|course_educators|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_signup|node|course_educators|form';
  $field_group->group_name = 'group_signup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_educators';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Signup',
    'weight' => '3',
    'children' => array(
      0 => 'field_last_signup_date',
      1 => 'field_signup_email',
      2 => 'field_signup_link',
      3 => 'field_signup_description',
      4 => 'field_signup_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Signup',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-signup field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_signup|node|course_educators|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Billeder/medier');
  t('Kurset');
  t('Lokation');
  t('Materialer');
  t('Periode');
  t('Praktisk information');
  t('Signup');
  t('Varighed og pris');
  t('Vis kontaktformular / Skjul kontaktformular');
  t('Yderligere information');

  return $field_groups;
}
