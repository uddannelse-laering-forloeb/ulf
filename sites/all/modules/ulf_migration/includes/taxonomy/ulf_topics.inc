<?php
/**
 * @file
 * Handling topics migration
 */

/**
 * Class UlfTopicsMigration.
 */
class UlfTopicsMigration extends DrupalTerm7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of topics taxonomy'),
      'machine_name' => 'UlfTopics',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'source_vocabulary' => 'topic',
      'destination_vocabulary' => 'topic',
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
