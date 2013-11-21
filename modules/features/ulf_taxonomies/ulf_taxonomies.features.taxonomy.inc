<?php
/**
 * @file
 * ulf_taxonomies.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ulf_taxonomies_taxonomy_default_vocabularies() {
  return array(
    'educational_goals' => array(
      'name' => 'Læringsmål',
      'machine_name' => 'educational_goals',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'target_group' => array(
      'name' => 'Overordnet målgruppe',
      'machine_name' => 'target_group',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
    ),
    'target_group_sub' => array(
      'name' => 'Målgruppe',
      'machine_name' => 'target_group_sub',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -8,
    ),
    'topic' => array(
      'name' => 'Emneområde',
      'machine_name' => 'topic',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -10,
    ),
  );
}
