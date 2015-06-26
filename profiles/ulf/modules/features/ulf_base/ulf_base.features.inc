<?php
/**
 * @file
 * ulf_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ulf_base_image_default_styles() {
  $styles = array();

  // Exported image style: node_display.
  $styles['node_display'] = array(
    'label' => 'Node display',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: teaser_display.
  $styles['teaser_display'] = array(
    'label' => 'Teaser display',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 752,
          'height' => 695,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
