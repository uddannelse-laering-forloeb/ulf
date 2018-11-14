<?php
/**
 * @file
 * Views definitions for ulf workflow module.
 */
/**
 * Implements hook_views_data_alter().
 */
function ulf_workflow_views_data_alter(&$data) {
  $data['node']['latest_log_message'] = array(
    'title' => t('Latest log message'),
    'help' => t('Displays the latest log message for the node.'),
    'field' => array(
      'handler' => 'ulf_workflow_handler_latest_log_message',
    ),
  );
}