<?php
/**
 * @file
 * ulf_base.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulf_base_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'course editor' => 'course editor',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'course editor' => 'course editor',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'course editor' => 'course editor',
    ),
    'module' => 'system',
  );

  return $permissions;
}
