<?php
/**
 * @file
 * Handling user migration
 */

/**
 * Class UlfUsersMigration.
 */
class UlfUsersMigration extends DrupalUser7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of users'),
      'machine_name' => 'UlfUsers',
      'source_connection' => 'legacy',
      'source_version' => 7,
    );

    // Call parent structure with combined arguments.
    parent::__construct($common_arguments + $arguments);

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($this->query(), array(), NULL, array('map_joinable' => FALSE));

    // Unmapped source fields.
    $this->addUnmigratedSources(array());

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array());
  }

  /**
   * Defines the Query to execute.
   */
  protected function query() {
    $query = parent::query();
    return $query;
  }
}