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
    'course_relevancy_educators' => array(
      'name' => 'Kursus relevans (undervisere)',
      'machine_name' => 'course_relevancy_educators',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'course_relevancy_primary_school' => array(
      'name' => 'Kursus relevans (skole)',
      'machine_name' => 'course_relevancy_primary_school',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'course_relevancy_upper_school' => array(
      'name' => 'Kursus relevans (ungdomsuddannelser)',
      'machine_name' => 'course_relevancy_upper_school',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'educational_goals' => array(
      'name' => 'Læringsmål',
      'machine_name' => 'educational_goals',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'offer_type' => array(
      'name' => 'Tilbudstype',
      'machine_name' => 'offer_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'subjects_primary_school' => array(
      'name' => 'Fag (Skole)',
      'machine_name' => 'subjects_primary_school',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'subjects_youth' => array(
      'name' => 'Fag (Ungdomsuddannelse)',
      'machine_name' => 'subjects_youth',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
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
