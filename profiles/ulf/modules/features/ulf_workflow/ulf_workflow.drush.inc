<?php

/**
 * Implements hook_drush_command().
 */
function ulf_workflow_drush_command() {

  $items['ulf-set-unpublish'] = array(
    'description' => 'Set a potential unpublish date for all courses',
    'aliases' => array('ulf-su'),
  );

  return $items;
}


/**
 * Callback for the ulf-set-unpublish command.
 */
function drush_ulf_workflow_ulf_set_unpublish() {
  // Set unpublish for course content types.
  $type = 'course';
  $nodes = node_load_multiple(array(), array('type' => $type));
  _ulf_workflow_set_unpublish($type, $nodes);

  // Set unpublish for course_educators content types.
  $type = 'course_educators';
  $nodes = node_load_multiple(array(), array('type' => $type));
  _ulf_workflow_set_unpublish($type, $nodes);
}

/**
 * @param $type
 * @param $nodes
 *
 * Custom function for setting unpublish date based on period end date.
 */
function _ulf_workflow_set_unpublish($type, $nodes) {
  $count = 0;
  $unpublished_count = 0;
  // Run through all nodes
  foreach ($nodes as $node) {
    if ($node->status == 1) {
      // Count up for result display.
      $count++;

      // Get period "to" date
      $wrapper = entity_metadata_wrapper('node', $node);
      $end_date = $wrapper->field_period->value()['value2'];

      // Week prior timestamp.
      $week_prior = $end_date - 604800;

      // Remove old nid entry element.
      if (db_table_exists('scheduler')) {
        db_delete('scheduler')
          ->condition('nid', $node->nid)
          ->execute();

        // Create new entry from nid.
        db_insert('scheduler')
          ->fields(array(
            'nid' => $node->nid,
            'publish_on' => 0,
            'unpublish_on' => $end_date,
          ))
          ->execute();
      }

      // Remove old entry for element.
      if (db_table_exists('scheduler_notify')) {
        db_delete('scheduler_notify')
          ->condition('nid', $node->nid)
          ->execute();

        // Create new entry from nid.
        db_insert('scheduler_notify')
          ->fields(array(
            'nid' => $node->nid,
            'uid' => $node->uid,
            'send_mail_on' => $week_prior,
          ))
          ->execute();
      }
    }
    else {
      $unpublished_count++;
    }
  }
  if ($count > 0) {
    drush_print($count . " nodes of the " . $type . " content type have had unpublish date added.");
  }

  else {
    drush_print("No nodes of the " . $type . " content type were published.");
  }

  drush_print($unpublished_count . " nodes of " . $type . " content type are currently unpublished.");
}