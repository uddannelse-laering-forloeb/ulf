<?php
/**
 * @file
 * Handling educational material migration
 */

/**
 * Class UlfEducationalMaterialMigration.
 */
class UlfEducationalMaterialMigration extends DrupalMigration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of educational material'),
      'machine_name' => 'UlfEducationalMaterial',
      'source_connection' => 'legacy',
      'source_version' => 7,
    );

    $this->dependencies = array('UlfCoursesEducation');

    $this->sourceFields += array();

    // Call parent structure with combined arguments.
    parent::__construct($common_arguments + $arguments);

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL, array('map_joinable' => FALSE));

    $this->destination = new MigrateDestinationFieldCollection(
      'field_educational_material',
      array('host_entity_type' => 'node')
    );

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'entity_id' => array(
          'type' => 'int',
          'not null' => true,
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );


    $this->addFieldMapping('host_entity_id', 'entity_id')
      ->sourceMigration('UlfCoursesEducation')->sourceMigration('UlfCourses');

    $this->addFieldMapping('field_material_description', 'field_material_description_value');

    $this->addFieldMapping('field_material_file', 'field_material_file_fid');
    $this->addFieldMapping('field_material_file:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_material_file:preserve_files', NULL, FALSE)
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_material_link', 'field_material_link_url');

    $this->addFieldMapping('field_material_litt', 'field_material_litt_slag_value');

    // Unmapped source fields.
    $this->addUnmigratedSources(array(

    ));

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array(
      'path',
      'field_material_description:language',
      'field_material_file:language',
      'field_material_file:destination_dir',
      'field_material_file:destination_file',
      'field_material_file:file_replace',
      'field_material_file:source_dir',
      'field_material_file:urlencode',
      'field_material_file:description',
      'field_material_file:display',
      'field_material_link:title',
      'field_material_link:attributes',
      'field_material_link:language',
      'field_material_litt:language',
    ));
  }

  protected function query() {
    // Do not attempt to migrate the anonymous user row.
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('field_data_field_educational_material', 'm')
      ->fields('m', array('entity_id'));

    $description = $query->leftJoin('field_data_field_material_description', 'description', 'description.entity_id = m.field_educational_material_value');
    $query->fields($description, array('field_material_description_value'));

    $file = $query->leftJoin('field_data_field_material_file', 'file', 'file.entity_id = m.field_educational_material_value');
    $query->fields($file, array('field_material_file_fid'));

    $link = $query->leftJoin('field_data_field_material_link', 'link', 'link.entity_id = m.field_educational_material_value');
    $query->fields($link, array('field_material_link_url'));

    $litt = $query->leftJoin('field_data_field_material_litt_slag', 'litt', 'litt.entity_id = m.field_educational_material_value');
    $query->fields($litt, array('field_material_litt_slag_value'));


    return $query;
  }

}
