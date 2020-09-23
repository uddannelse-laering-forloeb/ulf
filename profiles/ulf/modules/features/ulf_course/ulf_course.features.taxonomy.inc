<?php

/**
 * @file
 * ulf_course.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ulf_course_taxonomy_default_vocabularies() {
  return array(
    'banner' => array(
      'name' => 'Banner',
      'machine_name' => 'banner',
      'description' => 'Taksonomi som inderholder de forskellige valgfrie bannere',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
