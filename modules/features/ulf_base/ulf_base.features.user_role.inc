<?php
/**
 * @file
 * ulf_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function ulf_base_user_default_roles() {
  $roles = array();

  // Exported role: course provider.
  $roles['course provider'] = array(
    'name' => 'course provider',
    'weight' => 2,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 3,
  );

  return $roles;
}
