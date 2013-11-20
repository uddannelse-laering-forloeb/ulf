<?php
/**
 * @file
 * ulf_course_educators.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulf_course_educators_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create course_educators content'.
  $permissions['create course_educators content'] = array(
    'name' => 'create course_educators content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any course_educators content'.
  $permissions['delete any course_educators content'] = array(
    'name' => 'delete any course_educators content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own course_educators content'.
  $permissions['delete own course_educators content'] = array(
    'name' => 'delete own course_educators content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any course_educators content'.
  $permissions['edit any course_educators content'] = array(
    'name' => 'edit any course_educators content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own course_educators content'.
  $permissions['edit own course_educators content'] = array(
    'name' => 'edit own course_educators content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
