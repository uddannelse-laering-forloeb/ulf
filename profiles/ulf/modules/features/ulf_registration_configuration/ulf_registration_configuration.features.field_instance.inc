<?php
/**
 * @file
 * ulf_registration_configuration.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ulf_registration_configuration_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-course-field_registration_form'.
  $field_instances['node-course-field_registration_form'] = array(
    'bundle' => 'course',
    'default_value' => array(
      0 => array(
        'registration_type' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'registration',
        'settings' => array(),
        'type' => 'registration_form',
        'weight' => 33,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'registration',
        'settings' => array(),
        'type' => 'registration_form',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_registration_form',
    'label' => 'Tilmeldingsformular',
    'required' => 0,
    'settings' => array(
      'default_registration_settings' => array(
        'capacity' => 0,
        'reminder' => array(
          'reminder_settings' => array(
            'reminder_date' => NULL,
            'reminder_template' => '',
          ),
          'send_reminder' => 0,
        ),
        'scheduling' => array(
          'close' => NULL,
          'open' => NULL,
        ),
        'settings' => array(
          'confirmation' => 'Registration has been saved.',
          'confirmation_redirect' => '',
          'from_address' => 'noreply@aabenaalborg.dk',
          'maximum_spaces' => 0,
          'multiple_registrations' => 0,
        ),
        'status' => 1,
      ),
      'hide_register_tab' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'registration',
      'settings' => array(),
      'type' => 'registration_select',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_registration_form'.
  $field_instances['node-course_educators-field_registration_form'] = array(
    'bundle' => 'course_educators',
    'default_value' => array(
      0 => array(
        'registration_type' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'registration',
        'settings' => array(),
        'type' => 'registration_form',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_registration_form',
    'label' => 'Tilmeldingsformular',
    'required' => 0,
    'settings' => array(
      'default_registration_settings' => array(
        'capacity' => 0,
        'reminder' => array(
          'reminder_settings' => array(
            'reminder_date' => NULL,
            'reminder_template' => '',
          ),
          'send_reminder' => 0,
        ),
        'scheduling' => array(
          'close' => NULL,
          'open' => NULL,
        ),
        'settings' => array(
          'confirmation' => 'Registration has been saved.',
          'confirmation_redirect' => '',
          'from_address' => 'noreply@aabenaalborg.dk',
          'maximum_spaces' => 0,
          'multiple_registrations' => 0,
        ),
        'status' => 1,
      ),
      'hide_register_tab' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'registration',
      'settings' => array(),
      'type' => 'registration_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'registration-signup-field_registration_name'.
  $field_instances['registration-signup-field_registration_name'] = array(
    'bundle' => 'signup',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'registration',
    'field_name' => 'field_registration_name',
    'label' => 'Name',
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'registration-signup-field_registration_phone'.
  $field_instances['registration-signup-field_registration_phone'] = array(
    'bundle' => 'signup',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'registration',
    'field_name' => 'field_registration_phone',
    'label' => 'Phone',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'telwidget',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Name');
  t('Phone');
  t('Tilmeldingsformular');

  return $field_instances;
}
