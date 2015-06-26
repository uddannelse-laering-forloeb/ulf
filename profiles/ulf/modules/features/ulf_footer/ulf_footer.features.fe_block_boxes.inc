<?php
/**
 * @file
 * ulf_footer.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function ulf_footer_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer block left';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_one';
  $fe_block_boxes->body = '<p>Lorem</p>';

  $export['footer_one'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer block right';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_three';
  $fe_block_boxes->body = '<p>123</p>';

  $export['footer_three'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Footer block middle';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_two';
  $fe_block_boxes->body = '<p>Ipsum</p>';

  $export['footer_two'] = $fe_block_boxes;

  return $export;
}
