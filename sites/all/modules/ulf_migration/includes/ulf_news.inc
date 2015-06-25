<?php
/**
 * @file
 * Handling news migration.
 */

/**
 * Class UlfNewsMigration.
 */
class UlfNewsMigration extends DrupalNode7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of news'),
      'machine_name' => 'UlfNews',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'destination_type' => 'news',
      'source_type' => 'news',
      'user_migration' => 'UlfUsers',
    );

    $this->dependencies = array('UlfFiles', 'UlfUsers');

    $this->sourceFields += array(
      'field_image_fids' => t('Image file ids'),
      'body:summary' => t('Empty body summary'),
      'body:format' => t('Empty body format'),
    );

    // Call parent structure with combined arguments.
    parent::__construct($common_arguments + $arguments);

    $this->removeFieldMapping('body:summary');
    $this->removeFieldMapping('body:format');

    // Map image files.
    $this->addFieldMapping('field_image', 'field_image_fids')
      ->sourceMigration('UlfFiles');
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addSimpleMappings(array(
      'field_teaser',
      'field_teaser:language',
      'field_content',
      'field_content:format',
      'field_content:language',
      'field_image:alt',
      'field_image:title',
    ));


    $this->addUnmigratedSources(array(
      'revision',
      'revision_uid',
      'log',
      'field_image',
      'field_image:width',
      'field_image:height',
      'field_image:language',
    ));

    $this->addUnmigratedDestinations(array(
      'field_image:language',
      'field_image:preserve_files',
    ));
  }

  /**
   * Load extra information about fields.
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Query provider images fids.
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('field_data_field_image', 'media')
      ->fields('media', array('delta', 'field_image_fid'))
      ->condition('entity_id', $row->nid, '=')
      ->execute();

    $row->field_image_fids = array();
    foreach($query as $fid) {
      $row->field_image_fids[$fid->delta] = $fid->field_image_fid;
    }

    return TRUE;
  }


}
