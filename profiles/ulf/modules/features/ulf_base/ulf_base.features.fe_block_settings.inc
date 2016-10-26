<?php
/**
 * @file
 * ulf_base.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ulf_base_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['ulf_social_media-ulf_social_media'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'ulf_social_media',
    'module' => 'ulf_social_media',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'ulf_default' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ulf_default',
        'weight' => 20,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
