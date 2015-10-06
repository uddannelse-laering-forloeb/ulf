<?php
/**
 * @file
 * ulf_node_clone.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ulf_node_clone_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_menu_links';
  $strongarm->value = '0';
  $export['clone_menu_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_method';
  $strongarm->value = 'prepopulate';
  $export['clone_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_nodes_without_confirm';
  $strongarm->value = '0';
  $export['clone_nodes_without_confirm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_omitted';
  $strongarm->value = array(
    'news' => 'news',
    'static_page' => 'static_page',
    'course_educators' => 0,
    'course' => 0,
  );
  $export['clone_omitted'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_course';
  $strongarm->value = 1;
  $export['clone_reset_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_course_educators';
  $strongarm->value = 1;
  $export['clone_reset_course_educators'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_news';
  $strongarm->value = 0;
  $export['clone_reset_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_reset_static_page';
  $strongarm->value = 0;
  $export['clone_reset_static_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_use_node_type_name';
  $strongarm->value = 0;
  $export['clone_use_node_type_name'] = $strongarm;

  return $export;
}
