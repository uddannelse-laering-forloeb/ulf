<?php
/**
 * @file
 * ulf_course_educators.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_course_educators_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ulf_course_educators_node_info() {
  $items = array(
    'course_educators' => array(
      'name' => t('Kursus til undervisere'),
      'base' => 'node_content',
      'description' => t('Kursusforløb målrettet lærere og pædagoger'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
