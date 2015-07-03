<?php
/**
 * @file
 * ulf_search.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ulf_search_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'facetapi:block_cache:search_api@default';
  $strongarm->value = -1;
  $export['facetapi:block_cache:search_api@default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_facets_search_ids';
  $strongarm->value = array(
    'default' => array(
      'search_api_page:search' => 'search_api_page:search',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  return $export;
}
