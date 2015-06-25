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
    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL, array('map_joinable' => FALSE));

    // Map the list image field to the new list image field, base this on the
    // DingFile migration to map the files to the imported files table.
    $this->addFieldMapping('field_image', 'field_provider_media')
      ->sourceMigration('UlfFiles');
    $this->addFieldMapping('field_image:alt')
      ->sourceMigration('MigrateFileFid');
    $this->addFieldMapping('field_image:title')
      ->sourceMigration('MigrateFileFid');
    $this->addFieldMapping('field_image:language')
      ->sourceMigration('MigrateFileFid');

    // Unmapped source fields.
    $this->addUnmigratedSources(array(
      'uuid',
     ));

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array());
  }
}