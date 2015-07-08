<?php
/**
 * @file
 * Handling courses migration.
 */

/**
 * Class UlfCoursesMigration.
 */
class UlfCoursesMigration extends DrupalNode7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of courses'),
      'machine_name' => 'UlfCourses',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'destination_type' => 'course',
      'source_type' => 'course',
      'user_migration' => 'UlfUsers',
    );

    $this->dependencies = array('UlfFiles', 'UlfUsers');

    $this->sourceFields += array(
      'field_image_media_fids' => t('Image file ids'),
      'body:summary' => t('Empty body summary'),
      'body:format' => t('Empty body format'),
    );

    // Call parent structure with combined arguments.
    parent::__construct($common_arguments + $arguments);

    $this->removeFieldMapping('body:summary');
    $this->removeFieldMapping('body:format');

    // Map image files.
    $this->addFieldMapping('field_image', 'field_image_media_fids')
      ->sourceMigration('UlfFiles');
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_image:alt', 'field_image_media:alt');
    $this->addFieldMapping('field_image:title', 'field_image_media:title');

    $this->addFieldMapping('field_educational_goals', 'field_educational_goals')
      ->sourceMigration('UlfEducationalGoals');
    $this->addFieldMapping('field_educational_goals:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_educational_goals:create_term')
      ->defaultValue(FALSE);

    $this->addFieldMapping('field_target_group', 'field_target_group')
      ->sourceMigration('UlfTargetGroups');
    $this->addFieldMapping('field_target_group:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_target_group:create_term')
      ->defaultValue(FALSE);

    $this->addFieldMapping('field_full_description:format')
      ->defaultValue('editor');

    $this->addSimpleMappings(array(
      'field_activities',
      'field_activities:format',
      'field_activities:language',
      'field_background_knowledge',
      'field_background_knowledge:format',
      'field_background_knowledge:language',
      'field_facilities',
      'field_facilities_info',
      'field_facilities_info:format',
      'field_facilities_info:language',
      'field_purpose',
      'field_purpose:language',
      'field_count',
      'field_full_description',
      'field_full_description:language'

    ));

    $this->addUnmigratedDestinations(array(
      'field_educational_goals:ignore_case',
      'field_target_group:ignore_case',
      'field_image:language',
      'field_image:preserve_files',
      'field_collection_price:revision_id',
      'field_educational_material:revision_id',
      'field_inspirational_material:revision_id',
    ));

    $this->addUnmigratedSources(array(
      'revision',
      'revision_uid',
      'log',
      'field_image_media',
      'field_image_media:width',
      'field_image_media:height',
      'field_image_media:language',
      'field_facilities:language',
      'field_purpose:format',
      'field_target_group:language',
      'field_full_description:format',
      'field_count:language',
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
      ->select('field_data_field_image_media', 'media')
      ->fields('media', array('delta', 'field_image_media_fid'))
      ->condition('entity_id', $row->nid, '=')
      ->execute();

    $row->field_image_media_fids = array();
    foreach($query as $fid) {
      $row->field_image_fids[$fid->delta] = $fid->field_image_media_fid;
    }

    return TRUE;
  }
}
