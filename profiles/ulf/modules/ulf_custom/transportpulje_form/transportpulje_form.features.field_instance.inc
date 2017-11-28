<?php
/**
 * @file
 * transportpulje_form.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function transportpulje_form_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'entityform-transportpulje_form-field_tpf_address'.
  $field_instances['entityform-transportpulje_form-field_tpf_address'] = array(
    'bundle' => 'transportpulje_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tpf_address',
    'label' => 'Indtast adresse',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 33,
    ),
  );

  // Exported field_instance:
  // 'entityform-transportpulje_form-field_tpf_course_not_found'.
  $field_instances['entityform-transportpulje_form-field_tpf_course_not_found'] = array(
    'bundle' => 'transportpulje_form',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tpf_course_not_found',
    'label' => 'Jeg kunne ikke finde forløbet ',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 32,
    ),
  );

  // Exported field_instance:
  // 'entityform-transportpulje_form-field_tpf_course_select'.
  $field_instances['entityform-transportpulje_form-field_tpf_course_select'] = array(
    'bundle' => 'transportpulje_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tpf_course_select',
    'label' => 'Vælg forløb',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'entityform-transportpulje_form-field_tpf_institution'.
  $field_instances['entityform-transportpulje_form-field_tpf_institution'] = array(
    'bundle' => 'transportpulje_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tpf_institution',
    'label' => 'Institution',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 35,
    ),
  );

  // Exported field_instance:
  // 'entityform-transportpulje_form-field_tpf_institution_type'.
  $field_instances['entityform-transportpulje_form-field_tpf_institution_type'] = array(
    'bundle' => 'transportpulje_form',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tpf_institution_type',
    'label' => 'Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 34,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Indtast adresse');
  t('Institution');
  t('Jeg kunne ikke finde forløbet ');
  t('Type');
  t('Vælg forløb');

  return $field_instances;
}
