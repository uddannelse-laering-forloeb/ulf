<?php
/**
 * @file
 * ulf_solr_setup.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function ulf_solr_setup_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'Ulf';
  $environment->url = 'http://localhost:8983/solr/ulf_stg';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_index_last' => array(
      'node' => array(
        'last_changed' => '1387443408',
        'last_entity_id' => '2',
      ),
    ),
    'apachesolr_index_updated' => 1387460635,
    'apachesolr_last_optimize' => 1387460635,
    'apachesolr_search_facet_pages' => '',
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'course',
      1 => 'course_educators',
      2 => 'static_page',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
