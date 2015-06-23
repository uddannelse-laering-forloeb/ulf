<?php
/**
 * @file
 * ulf_base.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ulf_base_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_daycare:search/dagtilbud
  $menu_links['main-menu_daycare:search/dagtilbud'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search/dagtilbud',
    'router_path' => 'search',
    'link_title' => 'Daycare',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_daycare:search/dagtilbud',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_school:search/grundskole
  $menu_links['main-menu_school:search/grundskole'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search/grundskole',
    'router_path' => 'search',
    'link_title' => 'School',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_school:search/grundskole',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_youth:search/ungdomsuddannelse
  $menu_links['main-menu_youth:search/ungdomsuddannelse'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search/ungdomsuddannelse',
    'router_path' => 'search',
    'link_title' => 'Youth',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_youth:search/ungdomsuddannelse',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Daycare');
  t('School');
  t('Youth');


  return $menu_links;
}
