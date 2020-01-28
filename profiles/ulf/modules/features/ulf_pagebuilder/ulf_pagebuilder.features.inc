<?php

/**
 * @file
 * ulf_pagebuilder.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_pagebuilder_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ulf_pagebuilder_image_default_styles() {
  $styles = array();

  // Exported image style: pagebuilder.
  $styles['pagebuilder'] = array(
    'label' => 'Pagebuilder',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 972,
          'height' => '',
          'upscale' => 1,
          '#imageinfo_cache_effect_callback' => 'image_scale_effect',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function ulf_pagebuilder_node_info() {
  $items = array(
    'page_with_blocks' => array(
      'name' => t('Statisk side med blokke'),
      'base' => 'node_content',
      'description' => t('Statisk side med pagebuilder funktionalitet'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function ulf_pagebuilder_paragraphs_info() {
  $items = array(
    'appetizer' => array(
      'name' => 'Appetizer',
      'bundle' => 'appetizer',
      'locked' => '1',
    ),
    'download_list' => array(
      'name' => 'Download list',
      'bundle' => 'download_list',
      'locked' => '1',
    ),
    'four_columns' => array(
      'name' => 'Four columns',
      'bundle' => 'four_columns',
      'locked' => '1',
    ),
    'hero' => array(
      'name' => 'Hero',
      'bundle' => 'hero',
      'locked' => '1',
    ),
    'link_list' => array(
      'name' => 'Link list',
      'bundle' => 'link_list',
      'locked' => '1',
    ),
    'one_column' => array(
      'name' => 'One column',
      'bundle' => 'one_column',
      'locked' => '1',
    ),
    'text_with_image' => array(
      'name' => 'Text with image',
      'bundle' => 'text_with_image',
      'locked' => '1',
    ),
    'text_with_video' => array(
      'name' => 'Text with video',
      'bundle' => 'text_with_video',
      'locked' => '1',
    ),
    'three_columns' => array(
      'name' => 'Three columns',
      'bundle' => 'three_columns',
      'locked' => '1',
    ),
    'two_column' => array(
      'name' => 'Two column',
      'bundle' => 'two_column',
      'locked' => '1',
    ),
  );
  return $items;
}
