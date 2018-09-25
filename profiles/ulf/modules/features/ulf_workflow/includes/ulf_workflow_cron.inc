<?php

/**
 * Delete trashed content that has not been updated for a year.
 */
function _ulf_workflow_cron_empty_trash() {
  $trash_period_days = variable_get('trash_can_delete_timer');
  $now = time();
  // Approximately one year.
  $trash_period = isset($trash_period_days) ? $trash_period_days*24*60*60 : 31536000;
  // Content types that have workflow enabled.
  $workflow_enabled_types = array(
    'course',
    'course_educators',
    'news_course_provider'
  );

  // Get all relevant nodes that have not been updated recently.
  $query = db_select('node', 'n');
  $query->fields('n');
  $query->condition('n.type', $workflow_enabled_types, 'IN');
  $query->condition('n.changed', $now - $trash_period, '<');
  $result = $query->execute()->fetchAllAssoc('nid');

  // Check for trashed value and delete if they are trashed.
  foreach ($result as $key => $node) {
    $wrapper = entity_metadata_wrapper('node', $key);
    $trashed = $wrapper->field_trashed->value();
    if (!empty($trashed)) {
      node_delete($key);
    }
  }
}
