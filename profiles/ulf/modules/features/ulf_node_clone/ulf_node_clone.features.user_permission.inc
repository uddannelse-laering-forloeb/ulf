<?php
/**
 * @file
 * ulf_node_clone.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulf_node_clone_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'clone node'.
  $permissions['clone node'] = array(
    'name' => 'clone node',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'clone own nodes'.
  $permissions['clone own nodes'] = array(
    'name' => 'clone own nodes',
    'roles' => array(),
    'module' => 'clone',
  );

  return $permissions;
}
