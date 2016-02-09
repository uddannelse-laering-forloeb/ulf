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
      6 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1000,
          'height' => 320,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'node_display',
        ),
        'weight' => -11,
      ),
      10 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1000,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: teaser_display.
  $styles['teaser_display'] = array(
    'label' => 'Teaser display',
    'effects' => array(
      3 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 300,
          'height' => 300,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'teaser_display',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}