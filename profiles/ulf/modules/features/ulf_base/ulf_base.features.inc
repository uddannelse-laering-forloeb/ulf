<?php

/**
 * @file
 * ulf_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "captcha" && $api == "captcha") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ulf_base_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function ulf_base_image_default_styles() {
  $styles = array();

  // Exported image style: facebook_open_graph.
  $styles['facebook_open_graph'] = array(
    'label' => 'Facebook visning',
    'effects' => array(
      1 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 600,
          '#imageinfo_cache_effect_callback' => 'manualcrop_crop_effect',
          'height' => 315,
          'keepproportions' => 1,
          'reuse_crop_style' => 'node_display',
          'style_name' => 'facebook_open_graph',
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: node_display.
  $styles['node_display'] = array(
    'label' => 'Indholdsvisning',
    'effects' => array(
      6 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1000,
          '#imageinfo_cache_effect_callback' => 'manualcrop_crop_and_scale_effect',
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
          '#imageinfo_cache_effect_callback' => 'image_scale_effect',
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: teaser_display.
  $styles['teaser_display'] = array(
    'label' => 'Teaser visning',
    'effects' => array(
      3 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 300,
          '#imageinfo_cache_effect_callback' => 'manualcrop_crop_and_scale_effect',
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
