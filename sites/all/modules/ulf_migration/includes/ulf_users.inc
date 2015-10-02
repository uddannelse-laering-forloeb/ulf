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

    $this->sourceFields += array(
      'field_provider_media_fids' => t('Provider media file ids'),
      'field_provider_logo_fids' => t('Provider logo file ids'),
      'roles' => t('Raw user roles'),
    );

    $this->dependencies = array('UlfFiles');

    // Call parent structure with combined arguments.
    parent::__construct($common_arguments + $arguments);

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL, array('map_joinable' => FALSE));

    // Map provider media files.
    $this->addFieldMapping('field_image', 'field_provider_media_fids')
      ->sourceMigration('UlfFiles');
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_image:preserve_files', NULL, FALSE)
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_image:alt', 'field_provider_media:alt');
    $this->addFieldMapping('field_image:title', 'field_provider_media:title');

    // Map provider logo files.
    $this->addFieldMapping('field_profile_logo', 'field_provider_logo_fids')
      ->sourceMigration('UlfFiles');
    $this->addFieldMapping('field_profile_logo:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_profile_logo:preserve_files', NULL, FALSE)
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_profile_logo:alt', 'field_provider_logo:alt');
    $this->addFieldMapping('field_profile_logo:title', 'field_provider_logo:title');


    // Mappe roles.
    $this->removeFieldMapping('roles');
    $this->addFieldMapping('roles', 'roles')
      ->sourceMigration('UlfRoles');

    // Map one-to-one fields.
    $this->addSimpleMappings(array(
      'field_profile_address',
      'field_profile_address:language',
      'field_profile_city',
      'field_profile_city:language',
      'field_profile_description',
      'field_profile_description:language',
      'field_profile_entry',
      'field_profile_entry:language',
      'field_profile_home_page',
      'field_profile_home_page:title',
      'field_profile_home_page:attributes',
      'field_profile_home_page:language',
      'field_profile_name',
      'field_profile_name:language',
      'field_profile_phone',
      'field_profile_phone:language',
      'field_profile_postal_code',
    ));

    // Unmapped source fields.
    $this->addUnmigratedSources(array(
      'uuid',
      'field_provider_media',
      'field_provider_media:width',
      'field_provider_media:height',
      'field_provider_media:language',
      'field_profile_postal_code:language',
      'field_profile_contact:revision_id',
      'field_profile_contact:language',
      'field_profile_description:format',
      'field_provider_logo',
      'field_provider_logo:width',
      'field_provider_logo:height',
      'field_provider_logo:language',
      'field_profile_contact',
     ));

    // Unmapped destination fields.
    $this->addUnmigratedDestinations(array(
      'field_image:language',
      'field_profile_logo:language',
      'field_profile_contact',
      'field_profile_contact:revision_id',
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
      ->select('field_data_field_provider_media', 'media')
      ->fields('media', array('delta', 'field_provider_media_fid'))
      ->condition('entity_id', $row->uid, '=')
      ->execute();

    $row->field_provider_media_fids = array();
    foreach($query as $fid) {
      $row->field_provider_media_fids[$fid->delta] = $fid->field_provider_media_fid;
    }

    // Query provider images fids.
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('field_data_field_provider_logo', 'media')
      ->fields('media', array('delta', 'field_provider_logo_fid'))
      ->condition('entity_id', $row->uid, '=')
      ->execute();

    $row->field_provider_logo_fids = array();
    foreach($query as $fid) {
      $row->field_provider_logo_fids[$fid->delta] = $fid->field_provider_logo_fid;
    }

    // Load user roles.
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('users_roles', 'r')
      ->fields('r', array('rid'))
      ->condition('uid', $row->uid, '=')
      ->execute();

    $row->roles = array();
    foreach($query as $id) {
      $row->roles[] = $id->rid;
    }

    return TRUE;
  }
}