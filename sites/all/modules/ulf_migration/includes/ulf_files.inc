<?php
/**
 * @file
 * Class for migrating files.
 */

/**
 * Class UlfFilesMigration.
 */
class UlfFilesMigration extends DrupalFile7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   *   Configuration arguments.
   */
  public function __construct($arguments) {
    // The description and the migration machine name are also required
    // arguments, which will be unique for each migration you register.
    $common_arguments = array(
      'source_connection' => 'legacy',
      'source_version' => 7,
      'description' => t('Migration of files'),
      'machine_name' => 'UlfFiles',
      'source_dir' => variable_get('migrate_source_dir', '/vagrant/sutrix_files'),
    );

    parent::__construct($common_arguments + $arguments);

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array('path', 'urlencode'));

    // Unmapped destination fields.
    $this->addUnmigratedSources(array('uuid'));
    $this->removeFieldMapping('NULL', 'urlencode');
  }

  /**
   * Destination file callback used to convert to new path.
   *
   * @param string $value
   *   The source value.
   *
   * @return string
   *   The destination value.
   */
  protected function getModifiedPath($value) {
    return $value;
  }
}
