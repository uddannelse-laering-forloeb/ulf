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

  $export['ulf_social_media-ulf_social_media_footer'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'ulf_social_media_footer',
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
      'ud_og_laer' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ud_og_laer',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
