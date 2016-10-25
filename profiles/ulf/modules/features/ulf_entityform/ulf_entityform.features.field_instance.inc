<?php
/**
 * @file
 * ulf_entityform.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ulf_entityform_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'entityform-end_user_message-field_message_body'.
  $field_instances['entityform-end_user_message-field_message_body'] = array(
    'bundle' => 'end_user_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_message_body',
    'label' => 'Besked',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 500,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'entityform-end_user_message-field_message_email'.
  $field_instances['entityform-end_user_message-field_message_email'] = array(
    'bundle' => 'end_user_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Angiv din email adresse',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_message_email',
    'label' => 'Email',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'emailwidget',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'entityform-end_user_message-field_message_name'.
  $field_instances['entityform-end_user_message-field_message_name'] = array(
    'bundle' => 'end_user_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Angiv dit fulde navn',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_message_name',
    'label' => 'Navn',
    'required' => 1,
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
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'entityform-end_user_message-field_message_parent_node'.
  $field_instances['entityform-end_user_message-field_message_parent_node'] = array(
    'bundle' => 'end_user_message',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_message_parent_node',
    'label' => 'Message Parent node',
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
      'type' => 'entityreference_autocomplete',
      'weight' => 34,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Angiv din email adresse');
  t('Angiv dit fulde navn');
  t('Besked');
  t('Email');
  t('Message Parent node');
  t('Navn');

  return $field_instances;
}
