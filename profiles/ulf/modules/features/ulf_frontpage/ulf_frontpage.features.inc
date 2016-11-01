<?php
/**
 * @file
 * ulf_frontpage.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ulf_frontpage_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function ulf_frontpage_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: frontpage_html_blocks
  $nodequeues['frontpage_html_blocks'] = array(
    'name' => 'frontpage_html_blocks',
    'title' => 'Frontpage html blocks',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'insert_at_front' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'html_block',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
