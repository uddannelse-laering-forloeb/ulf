<?php
/**
 * @file
 * ulf_field_collections.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ulf_field_collections_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_collection_price-field_price'
  $field_instances['field_collection_item-field_collection_price-field_price'] = array(
    'bundle' => 'field_collection_price',
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
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_price',
    'label' => 'Pris',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_collection_price-field_unit_price'
  $field_instances['field_collection_item-field_collection_price-field_unit_price'] = array(
    'bundle' => 'field_collection_price',
    'default_value' => array(
      0 => array(
        'value' => 'per_person',
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
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_unit_price',
    'label' => 'Afregningsenhed',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 33,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Afregningsenhed');
  t('Pris');

  return $field_instances;
}
