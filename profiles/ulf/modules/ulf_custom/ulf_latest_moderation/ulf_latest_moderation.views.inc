<?php
/**
 * @file
 * Views definitions for 'example'
 */

/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function ulf_latest_moderation_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'ulf_latest_moderation'),
    ),
    'handlers' => array(
      // The name of my handler
      'ulf_latest_moderation_handler_custom_field' => array(
        // The name of the handler we are extending.
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function ulf_latest_moderation_views_data() {
  $data = array();
  // Add Example group
  $data['ulf_latest_moderation']['table']['group'] = t('Latest moderation id');
  $data['ulf_latest_moderation']['table']['join'] = array(
    // #global is a special flag which let's a table appear all the time.
    '#global' => array(),
  );
  // Add custom field
  $data['ulf_latest_moderation']['custom_field'] = array(
    'title' => t('Latest moderation id Field'),
    'help' => t('Provides a custom field for latest moderation.'),
    'field' => array(
      'handler' => 'ulf_latest_moderation_handler_custom_field',
    ),
  );
  return $data;
}