<?php
/**
 * @file
 * Handling courses education migration.
 */

/**
 * Class UlfCoursesEducationMigration.
 */
class UlfCoursesEducationMigration extends DrupalNode7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of education courses'),
      'machine_name' => 'UlfCoursesEducation',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'destination_type' => 'course_educators',
      'source_type' => 'course_educators',
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
    $this->addFieldMapping('field_image:preserve_files', NULL, FALSE)
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_image:alt', 'field_image_media:alt');
    $this->addFieldMapping('field_image:title', 'field_image_media:title');

    $this->addFieldMapping('field_relevance_educators', 'field_relevance_educators')
      ->sourceMigration('UlfCourseRelevancyEducators');
    $this->addFieldMapping('field_relevance_educators:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_relevance_educators:create_term')
      ->defaultValue(FALSE);
    
    $this->addFieldMapping('field_relevance_primary_school', 'field_relevance_primary_school')
      ->sourceMigration('UlfElementarySchool');
    $this->addFieldMapping('field_relevance_primary_school:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_relevance_primary_school:create_term')
      ->defaultValue(FALSE);

    $this->addFieldMapping('field_subject', 'field_subject')
      ->sourceMigration('UlfTopics');
    $this->addFieldMapping('field_subject:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_subject:create_term')
      ->defaultValue(FALSE);

    $this->addFieldMapping('field_relevance_upper_school', 'field_relevance_upper_school')
      ->sourceMigration('UlfPrimarySchool');
    $this->addFieldMapping('field_relevance_upper_school:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_relevance_upper_school:create_term')
      ->defaultValue(FALSE);

    $this->addFieldMapping('field_course_contact_mail', 'field_contact_mail');


    $this->addFieldMapping('field_full_description:format')->defaultValue('editor');
    $this->addFieldMapping('field_full_description', 'field_full_description');


    $this->addSimpleMappings(array(
      'field_catering',
      'field_catering:format',
      'field_course_contact_name',
    ));

    $this->addUnmigratedDestinations(array(
      'field_educational_material',
      'field_educational_material:revision_id',
      'field_relevance_educators:ignore_case',
      'field_relevance_primary_school:ignore_case',
      'field_subject:ignore_case',
      'field_relevance_upper_school:ignore_case',
    ));

    $this->addUnmigratedSources(array(
      'revision',
      'revision_uid',
      'log',
      'field_educational_material',
      'field_educational_material:revision_id',
      'field_educational_material:language',
      'field_relevance_educators:language',
      'field_relevance_primary_school:language',
      'field_subject:language',
      'field_relevance_upper_school:language',
      'field_image_media',
      'field_image_media:width',
      'field_image_media:height',
      'field_image_media:language',
      'field_full_description:language',
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
      $row->field_image_media_fids[$fid->delta] = $fid->field_image_media_fid;
    }

    return TRUE;
  }
}
