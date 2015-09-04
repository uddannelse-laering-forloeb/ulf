<?php
/**
 * @file
 * Handling educational goals migration
 */

/**
 * Class UlfEducationalGoalsMigration.
 */
class UlfEducationalGoalsMigration extends DrupalTerm7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of educational_goals taxonomy'),
      'machine_name' => 'UlfEducationalGoals',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'source_vocabulary' => 'educational_goals',
      'destination_vocabulary' => 'educational_goals',
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
