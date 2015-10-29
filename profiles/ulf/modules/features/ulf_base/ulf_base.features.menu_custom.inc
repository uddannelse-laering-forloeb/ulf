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
  // Exported menu: menu-about-ulf.
  $menus['menu-about-ulf'] = array(
    'menu_name' => 'menu-about-ulf',
    'title' => 'About ULF',
    'description' => 'Menu for static pages',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About ULF');
  t('Main menu');
  t('Menu for static pages');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}
