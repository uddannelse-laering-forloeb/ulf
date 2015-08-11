<?php
/**
 * @file
 * Handling user migration
 */

/**
 * Class UlfUsersMigration.
 */
class UlfUsersContactMigration extends DrupalMigration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of users contact'),
      'machine_name' => 'UlfUsersContact',
      'source_connection' => 'legacy',
      'source_version' => 7,
    );

    $this->dependencies = array('UlfUsers');

    $this->sourceFields += array();

    // Call parent structure with combined arguments.
    parent::__construct($common_arguments + $arguments);

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL, array('map_joinable' => FALSE));

    $this->destination = new MigrateDestinationFieldCollection(
      'field_profile_contact',
      array('host_entity_type' => 'user')
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
      ->sourceMigration('UlfUsers');

    $this->addFieldMapping('field_contact_name', 'field_contact_name_value');
    $this->addFieldMapping('field_contact_email', 'field_contact_email_value');
    $this->addFieldMapping('field_contact_phone', 'field_contact_phone_value');

    // Unmapped source fields.
    $this->addUnmigratedSources(array(

    ));

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array(
      'path',
    ));
  }

  protected function query() {
    // Do not attempt to migrate the anonymous user row.
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('field_data_field_profile_contact', 'c')
      ->fields('c', array('entity_id'));

    $name = $query->leftJoin('field_data_field_contact_name', 'name', 'name.entity_id = c.field_profile_contact_value');
    $query->fields($name, array('field_contact_name_value'));

    $mail = $query->leftJoin('field_data_field_contact_email', 'email', 'email.entity_id = c.field_profile_contact_value');
    $query->fields($mail, array('field_contact_email_value'));

    $phone = $query->leftJoin('field_data_field_contact_phone', 'phone', 'phone.entity_id = c.field_profile_contact_value');
    $query->fields($phone, array('field_contact_phone_value'));

    return $query;
  }
}
