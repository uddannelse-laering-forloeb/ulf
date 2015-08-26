<?php
/**
 * @file
 * Handling tags migration
 */

/**
 * Class UlfTagsMigration.
 */
class UlfTagsMigration extends DrupalTerm7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of tags taxonomy'),
      'machine_name' => 'UlfTags',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'source_vocabulary' => 'tags',
      'destination_vocabulary' => 'tags',
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
