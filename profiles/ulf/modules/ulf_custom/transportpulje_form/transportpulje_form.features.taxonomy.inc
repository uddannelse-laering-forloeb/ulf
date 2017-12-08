<?php
/**
 * @file
 * transportpulje_form.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function transportpulje_form_taxonomy_default_vocabularies() {
  return array(
    'tpf_institutions_list' => array(
      'name' => 'Institutionsliste',
      'machine_name' => 'tpf_institutions_list',
      'description' => 'Liste over institutioner i kommunen',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
