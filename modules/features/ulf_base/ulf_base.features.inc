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
    'name' => 'node_display',
    'label' => 'Node display',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 770,
          'height' => 224,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
