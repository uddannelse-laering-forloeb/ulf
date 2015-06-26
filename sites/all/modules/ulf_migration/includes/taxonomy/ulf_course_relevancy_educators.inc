<?php
/**
 * @file
 * Handling course relevancy educators migration
 */

/**
 * Class UlfCourseRelevancyEducatorsMigration.
 */
class UlfCourseRelevancyEducatorsMigration extends DrupalTerm7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of course relevancy educators taxonomy'),
      'machine_name' => 'UlfCourseRelevancyEducators',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'source_vocabulary' => 'course_relevancy_educators',
      'destination_vocabulary' => 'course_relevancy_educators',
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
