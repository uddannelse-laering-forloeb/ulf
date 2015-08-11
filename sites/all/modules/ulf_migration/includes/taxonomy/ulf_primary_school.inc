<?php
/**
 * @file
 * Handling primary school migration
 */

/**
 * Class UlfPrimarySchoolMigration.
 */
class UlfPrimarySchoolMigration extends DrupalTerm7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of primary school taxonomy'),
      'machine_name' => 'UlfPrimarySchool',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'source_vocabulary' => 'primary_school',
      'destination_vocabulary' => 'primary_school',
    );

    $this->sourceFields += array();

    // Call parent structure with combined arguments.
    parent::__construct($common_arguments + $arguments);

    // Unmapped destination fields.
    $this->removeFieldMapping('parent');
    $this->addUnmigratedDestinations(array(
      'parent',
    ));
  }

}
