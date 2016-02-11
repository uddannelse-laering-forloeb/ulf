<?php
/**
 * @file
 * ulf_html_blocks.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ulf_html_blocks_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-html_block-field_html_code'.
  $field_instances['node-html_block-field_html_code'] = array(
    'bundle' => 'html_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Tilføj html koden her.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_html_code',
    'label' => 'HTML kode',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 8,
      ),
      'type' => 'text_textarea',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('HTML kode');
  t('Tilføj html koden her.');

  return $field_instances;
}
