<?php
/**
 * @file
 * ulf_search_settings.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ulf_search_settings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_dagtilbud:dagtilbud
  $menu_links['main-menu_dagtilbud:dagtilbud'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dagtilbud',
    'router_path' => 'dagtilbud',
    'link_title' => 'Dagtilbud',
    'options' => array(
      'identifier' => 'main-menu_dagtilbud:dagtilbud',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_grundskole:grundskole
  $menu_links['main-menu_grundskole:grundskole'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'grundskole',
    'router_path' => 'grundskole',
    'link_title' => 'Grundskole',
    'options' => array(
      'identifier' => 'main-menu_grundskole:grundskole',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Dagtilbud');
  t('Grundskole');

  return $menu_links;
}
