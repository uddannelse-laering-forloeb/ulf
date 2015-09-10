<?php
/**
 * @file
 * Handling static pages migration.
 */

/**
 * Class UlfStaticMigration.
 */
class UlfStaticMigration extends DrupalNode7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of static pages'),
      'machine_name' => 'UlfStatic',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'destination_type' => 'static_page',
      'source_type' => 'omulf',
      'user_migration' => 'UlfUsers',
    );

    $this->dependencies = array('UlfFiles', 'UlfUsers');

    $this->sourceFields += array(
      'field_image_banner_fids' => t('Image file ids'),
      'body:summary' => t('Empty body summary'),
      'body:format' => t('Empty body format'),
    );

    // Call parent structure with combined arguments.
    parent::__construct($common_arguments + $arguments);

    $this->removeFieldMapping('body:summary');
    $this->removeFieldMapping('body:format');

    // Map image files.
    $this->addFieldMapping('field_image', 'field_image_banner_fids')
      ->sourceMigration('UlfFiles');
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_image:preserve_files', NULL, FALSE)
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_image:alt', 'field_image_banner:alt');
    $this->addFieldMapping('field_image:title', 'field_image_banner:title');

    $this->addFieldMapping('field_content:format')->defaultValue('editor');
    $this->addFieldMapping('field_content', 'body');

    $this->addUnmigratedSources(array(
      'revision',
      'revision_uid',
      'log',
      'body:language',
      'field_manchet_omulf:language',
      'field_image_banner',
      'field_image_banner:width',
      'field_image_banner:height',
      'field_image_banner:language',
    ));

    $this->addUnmigratedDestinations(array(
      'field_content:language',
      'field_image:language',
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
      ->select('field_data_field_image_banner', 'media')
      ->fields('media', array('delta', 'field_image_banner_fid'))
      ->condition('entity_id', $row->nid, '=')
      ->execute();

    $row->field_image_banner_fids = array();
    foreach($query as $fid) {
      $row->field_image_banner_fids[$fid->delta] = $fid->field_image_banner_fid;
    }

    return TRUE;
  }
}
