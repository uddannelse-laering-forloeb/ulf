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

  // Exported menu link: main-menu_dagtilbud:taxonomy/term/3
  $menu_links['main-menu_dagtilbud:taxonomy/term/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/3',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Dagtilbud',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_dagtilbud:taxonomy/term/3',
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
  // Exported menu link: main-menu_grundskole:taxonomy/term/34
  $menu_links['main-menu_grundskole:taxonomy/term/34'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/34',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Grundskole',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_grundskole:taxonomy/term/34',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_ungdomsuddannelse:taxonomy/term/40
  $menu_links['main-menu_ungdomsuddannelse:taxonomy/term/40'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/40',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Ungdomsuddannelse',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_ungdomsuddannelse:taxonomy/term/40',
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
