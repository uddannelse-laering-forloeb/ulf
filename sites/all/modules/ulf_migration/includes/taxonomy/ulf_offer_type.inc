<?php
/**
 * @file
 * Handling offer type migration
 */

/**
 * Class UlfOfferTypeMigration.
 */
class UlfOfferTypeMigration extends DrupalTerm7Migration {
  /**
   * Default constructor.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $common_arguments = array(
      'description' => t('Migration of offer type taxonomy'),
      'machine_name' => 'UlfOfferType',
      'source_connection' => 'legacy',
      'source_version' => 7,
      'source_vocabulary' => 'offer_type',
      'destination_vocabulary' => 'offer_type',
    );

    $this->sourceFields += array();

    // Call parent structure with combined arguments.
    parent::__construct($common_arguments + $arguments);

    // Unmapped destination fields.
    $this->removeFieldMapping('parent');
    $this->addUnmigratedDestinations(array(
      'parent',
    ));
  }

}
