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
  $layout->name = 'node_display';
  $layout->admin_title = 'Node display';
  $layout->admin_description = 'The default node display';
  $layout->category = 'Node';
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
          0 => 'main_',
        ),
        'parent' => 'main',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'practical_information',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sub_content',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'author_pane',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'main_' => array(
        'type' => 'region',
        'title' => 'Main',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'layout-element-alpha',
      ),
      'practical_information' => array(
        'type' => 'region',
        'title' => 'Practical information',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'layout-element-beta',
      ),
      'sub_content' => array(
        'type' => 'region',
        'title' => 'Sub content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'layout-element-gamma',
      ),
      'author_pane' => array(
        'type' => 'region',
        'title' => 'Author pane',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => 'layout-element-delta',
      ),
    ),
  );
  $export['node_display'] = $layout;

  return $export;
}
