<?php
/**
 * @file
 * ulf_pdf.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulf_pdf_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access PDF version'.
  $permissions['access PDF version'] = array(
    'name' => 'access PDF version',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'print_pdf',
  );

  return $permissions;
}
