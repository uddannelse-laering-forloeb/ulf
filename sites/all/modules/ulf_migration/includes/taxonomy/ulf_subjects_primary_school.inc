<?php
/**
 * @file
 * Handling subjects primary schools migration
 */

/**
 * Class UlfSubjectsPrimarySchoolsMigration.
 */
class UlfSubjectsPrimarySchoolsMigration extends DrupalTerm7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of subjects primary school taxonomy'),
      'machine_name' => 'UlfSubjectsPrimarySchools',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'source_vocabulary' => 'subjects_primary_school',
      'destination_vocabulary' => 'subjects_primary_school',
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
