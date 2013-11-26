<?php
/**
 * @file
 * ulf_base.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function ulf_base_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-static-pages.
  $menus['menu-static-pages'] = array(
    'menu_name' => 'menu-static-pages',
    'title' => 'Static pages',
    'description' => 'Holds the static pages used on the site',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Holds the static pages used on the site');
  t('Main menu');
  t('Static pages');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
