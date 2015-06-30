<?php
/**
 * @file
 * ulf_footer.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function ulf_footer_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-footer_one'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'footer_one',
    'module' => 'block',
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
      'ulf' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ulf',
        'weight' => -13,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-footer_three'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'footer_three',
    'module' => 'block',
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
      'ulf' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ulf',
        'weight' => -11,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['block-footer_two'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'footer_two',
    'module' => 'block',
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
      'ulf' => array(
        'region' => 'footer',
        'status' => 1,
        'theme' => 'ulf',
        'weight' => -12,
      ),
    ),
    'title' => 'Quick links',
    'visibility' => 0,
  );

  return $export;
}
