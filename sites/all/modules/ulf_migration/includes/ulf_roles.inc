<?php
/**
 * @file
 * Handling roles migration
 */

/**
 * Class UlfUsersMigration.
 */
class UlfRolesMigration extends DrupalRole7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of roles'),
      'machine_name' => 'UlfRoles',
      'source_connection' => 'legacy',
      'source_version' => 7,
    );

    // Call parent structure with combined arguments.
    parent::__construct($common_arguments + $arguments);
  }
}