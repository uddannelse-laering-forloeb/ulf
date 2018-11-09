<?php
/**
 * @file
 * ulf_course_provider_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_course_provider_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ulf_course_provider_news_node_info() {
  $items = array(
    'news_course_provider' => array(
      'name' => t('Nyhed'),
      'base' => 'node_content',
      'description' => t('Nyheder fra indholdsleverandøren.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
