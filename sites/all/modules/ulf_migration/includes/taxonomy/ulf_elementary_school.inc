<?php
/**
 * @file
 * Handling elementary school migration
 */

/**
 * Class UlfElementarySchoolMigration.
 */
class UlfElementarySchoolMigration extends DrupalTerm7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of elementary school taxonomy'),
      'machine_name' => 'UlfElementarySchool',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'source_vocabulary' => 'elementary_school',
      'destination_vocabulary' => 'elementary_school',
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
