<?php
/**
 * @file
 * ulf_html_blocks.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_html_blocks_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ulf_html_blocks_node_info() {
  $items = array(
    'html_block' => array(
      'name' => t('HTML block'),
      'base' => 'node_content',
      'description' => t('Simpelt input felt til html'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
