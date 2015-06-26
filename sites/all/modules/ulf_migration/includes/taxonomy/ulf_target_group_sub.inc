<?php
/**
 * @file
 * Handling topics migration
 */

/**
 * Class UlfTopicsMigration.
 */
class UlfTargetGroupsSubMigration extends DrupalTerm7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of target groups sub taxonomy'),
      'machine_name' => 'UlfTargetGroupsSub',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'source_vocabulary' => 'target_group_sub',
      'destination_vocabulary' => 'target_group_sub',
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
