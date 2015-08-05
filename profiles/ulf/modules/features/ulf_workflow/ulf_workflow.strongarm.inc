<?php
/**
 * @file
 * ulf_workflow.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ulf_workflow_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_course_educators';
  $strongarm->value = 'needs_review';
  $export['workbench_moderation_default_state_course_educators'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_myworkbench_disabled';
  $strongarm->value = FALSE;
  $export['workbench_myworkbench_disabled'] = $strongarm;

  return $export;
}
