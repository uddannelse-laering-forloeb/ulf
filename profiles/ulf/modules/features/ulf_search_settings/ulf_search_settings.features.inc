<?php
/**
 * @file
 * ulf_search_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_search_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function ulf_search_settings_default_search_api_index() {
  $items = array();
  $items['courses'] = entity_import('search_api_index', '{
    "name" : "Courses",
    "machine_name" : "courses",
    "description" : null,
    "server" : "search_node",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "course" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "search_node_indexes" : "e0ea2029a2ae62cae2614b85e4061819",
      "fields" : {
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_educational_goals" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_free" : { "type" : "boolean" },
        "field_full_description:value" : { "type" : "text" },
        "field_image:file" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" },
        "field_offer_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_period:value" : { "type" : "date" },
        "field_price" : { "type" : "decimal" },
        "field_subject" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_subjects_primary_school" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_subjects_youth" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target_group" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target_group_sub" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function ulf_search_settings_default_search_api_server() {
  $items = array();
  $items['search_node'] = entity_import('search_api_server', '{
    "name" : "Search node",
    "machine_name" : "search_node",
    "description" : "",
    "class" : "search_api_search_node_service",
    "options" : {
      "host" : "https:\\/\\/quicksilver.aakb.dk",
      "apikey" : "17a0605248cee7105cdba634d6604f28",
      "apikey_readonly" : "dc52d28f7530eb208047c7c422fa8fbf"
    },
    "enabled" : "1"
  }');
  return $items;
}
