<?php
/**
 * @file
 * transportpulje_form.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function transportpulje_form_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tpf_contact|entityform|transportpulje_form|form';
  $field_group->group_name = 'group_tpf_contact';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'transportpulje_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '4. Kontaktoplysninger',
    'weight' => '8',
    'children' => array(
      0 => 'field_tpf_name',
      1 => 'field_tpf_phone',
      2 => 'field_tpf_email',
      3 => 'field_tpf_email_repeat',
      4 => 'field_tpf_message',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '4. Kontaktoplysninger',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-tpf-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_tpf_contact|entityform|transportpulje_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tpf_course|entityform|transportpulje_form|form';
  $field_group->group_name = 'group_tpf_course';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'transportpulje_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '1. Vælg forløb',
    'weight' => '0',
    'children' => array(
      0 => 'field_tpf_address',
      1 => 'field_tpf_course_not_found',
      2 => 'field_tpf_course_select',
      3 => 'field_tpf_purpose_course',
      4 => 'field_tpf_what_course',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '1. Vælg forløb',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_tpf_course|entityform|transportpulje_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tpf_institution|entityform|transportpulje_form|form';
  $field_group->group_name = 'group_tpf_institution';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'transportpulje_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '2. Vælg institution',
    'weight' => '1',
    'children' => array(
      0 => 'field_tpf_grade',
      1 => 'field_tpf_institution',
      2 => 'field_tpf_institution_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '2. Vælg institution',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-tpf-institution field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_tpf_institution|entityform|transportpulje_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tpf_transport|entityform|transportpulje_form|form';
  $field_group->group_name = 'group_tpf_transport';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'transportpulje_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '3. Transportudgifter',
    'weight' => '7',
    'children' => array(
      0 => 'field_tpf_expense',
      1 => 'field_tpf_participants',
      2 => 'field_tpf_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '3. Transportudgifter',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-tpf-transport field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_tpf_transport|entityform|transportpulje_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_transport_app|node|course|form';
  $field_group->group_name = 'group_transport_app';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_placement';
  $field_group->data = array(
    'label' => 'Transportpulje indstillinger',
    'weight' => '17',
    'children' => array(
      0 => 'field_tpf_who_get_support',
      1 => 'field_tpf_in_list',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-transport-app field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_transport_app|node|course|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('1. Vælg forløb');
  t('2. Vælg institution');
  t('3. Transportudgifter');
  t('4. Kontaktoplysninger');
  t('Transportpulje indstillinger');

  return $field_groups;
}
