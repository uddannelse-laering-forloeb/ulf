<?php
/**
 * @file
 * ulf_structures.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function ulf_structures_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'content_layout_2_split';
  $layout->admin_title = 'content-layout-2-split';
  $layout->admin_description = 'One column splits into two columns at 50em width';
  $layout->category = 'content';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 1,
          2 => 2,
          3 => 3,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'element_alfa',
        ),
        'parent' => 'main',
      ),
      'element_alfa' => array(
        'type' => 'region',
        'title' => 'Element alfa',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'layout-element-alfa',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'element_beta',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'element_beta' => array(
        'type' => 'region',
        'title' => 'Element beta',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'layout-element-beta',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'element_gamma',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'element_gamma' => array(
        'type' => 'region',
        'title' => 'Element gamma',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'layout-element-gamma',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'element_delta',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'element_delta' => array(
        'type' => 'region',
        'title' => 'Element delta',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => 'layout-element-delta',
      ),
    ),
  );
  $export['content_layout_2_split'] = $layout;

  return $export;
}
