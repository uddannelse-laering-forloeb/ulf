<?php
/**
 * @file
 * ulf_course_educators.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ulf_course_educators_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_course_educators';
  $strongarm->value = '0';
  $export['language_content_type_course_educators'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_course_educators';
  $strongarm->value = array();
  $export['menu_options_course_educators'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_course_educators';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_course_educators'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_course_educators';
  $strongarm->value = array();
  $export['node_options_course_educators'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_course_educators';
  $strongarm->value = '0';
  $export['node_preview_course_educators'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_course_educators';
  $strongarm->value = 0;
  $export['node_submitted_course_educators'] = $strongarm;

  return $export;
}
