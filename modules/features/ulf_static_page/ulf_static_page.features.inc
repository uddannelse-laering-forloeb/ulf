<?php
/**
 * @file
 * ulf_static_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_static_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ulf_static_page_node_info() {
  $items = array(
    'static_page' => array(
      'name' => t('Statisk side'),
      'base' => 'node_content',
      'description' => t('Used for static content such as guides and information.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
