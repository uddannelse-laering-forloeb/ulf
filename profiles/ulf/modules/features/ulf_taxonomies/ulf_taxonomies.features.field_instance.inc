<?php
/**
 * @file
 * ulf_taxonomies.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ulf_taxonomies_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-course_relevancy_educators-field_taxonomy_subject_reference'.
  $field_instances['taxonomy_term-course_relevancy_educators-field_taxonomy_subject_reference'] = array(
    'bundle' => 'course_relevancy_educators',
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
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_taxonomy_subject_reference',
    'label' => 'Fagliste/Læreplanstemaer',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Fagliste/Læreplanstemaer');

  return $field_instances;
}
