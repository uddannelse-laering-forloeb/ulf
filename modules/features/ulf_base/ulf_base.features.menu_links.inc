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

  // Exported menu link: main-menu_dagtilbud:search/site/dagtilbud
  $menu_links['main-menu_dagtilbud:search/site/dagtilbud'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search/site/dagtilbud',
    'router_path' => 'search/site/%',
    'link_title' => 'Dagtilbud',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_dagtilbud:search/site/dagtilbud',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_forside:<front>
  $menu_links['main-menu_forside:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Forside',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_forside:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_grundskole:search/site/grundskole
  $menu_links['main-menu_grundskole:search/site/grundskole'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search/site/grundskole',
    'router_path' => 'search/site/%',
    'link_title' => 'Grundskole',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_grundskole:search/site/grundskole',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_ungdomsuddannelse:search/site/ungdomsuddannelse
  $menu_links['main-menu_ungdomsuddannelse:search/site/ungdomsuddannelse'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search/site/ungdomsuddannelse',
    'router_path' => 'search/site/%',
    'link_title' => 'Ungdomsuddannelse',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_ungdomsuddannelse:search/site/ungdomsuddannelse',
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
  t('Dagtilbud');
  t('Forside');
  t('Grundskole');
  t('Ungdomsuddannelse');


  return $menu_links;
}
