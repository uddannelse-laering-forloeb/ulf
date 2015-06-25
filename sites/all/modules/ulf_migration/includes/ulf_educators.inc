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
      'body:summary' => t('Empty body summary'),
      'body:format' => t('Empty body format'),
    );

    // Call parent structure with combined arguments.
    parent::__construct($common_arguments + $arguments);

    $this->removeFieldMapping('body:summary');
    $this->removeFieldMapping('body:format');

    $this->addFieldMapping('field_price', 'field_paris');


    $this->addSimpleMappings(array(
      'field_catering',
      'field_catering:format',
      'field_catering:language',
      'field_course_contact_name',
      'field_course_contact_name:language',
      'field_full_description',
      'field_full_description:format',
      'field_full_description:language',
    ));

    // Field collection.
    //   'field_educational_material',
    //   'field_educational_material:revision_id',


    $this->addUnmigratedSources(array(
      'revision',
      'revision_uid',
      'log',
      'field_paris:revision_id',
      'field_paris:language',
    ));
  }

}
