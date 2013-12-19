<?php
/**
 * @file
 * ulf_course_educators.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ulf_course_educators_taxonomy_default_vocabularies() {
  return array(
    'course_relevancy_educators' => array(
      'name' => 'Kursus relevans (undervisere)',
      'machine_name' => 'course_relevancy_educators',
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
  );
}
