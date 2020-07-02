<?php

/**
 * @file
 * ulf_world_targets.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function ulf_world_targets_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_world_targets'.
  $field_bases['field_world_targets'] = array(
    'active' => 1,
    'cardinality' => 4,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_world_targets',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Afskaf fattigdom',
        2 => 'Stop sult',
        3 => 'Sundhed og trivsel',
        4 => 'Kvalitetsuddannelse',
        5 => 'Ligestilling melle kønene',
        6 => 'Rent vand og sanitet',
        7 => 'Bæredygtig energi',
        8 => 'Anstændige jobs og økonomisk vækst',
        9 => 'Industri, innovation og infrastruktur',
        10 => 'Mindre ulighed',
        11 => 'Bæredugtige byer og lokalsamfund',
        12 => 'Ansvarligt forbrug og produktion',
        13 => 'Klimaindsats',
        14 => 'Livet i havet',
        15 => 'Livet på land',
        16 => 'Fred, retfærdighed og stærke institutioner',
        17 => 'Partnerskaber for forhandling',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
