<?php
/**
 * @file
 * ulf_course.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_course_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ulf_course_node_info() {
  $items = array(
    'course' => array(
      'name' => t('Undervisnings- og læringsforløb'),
      'base' => 'node_content',
      'description' => t('Undervisnings- og læringsforløb målrettet bør og unge.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
