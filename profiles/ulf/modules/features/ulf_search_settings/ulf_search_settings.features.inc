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
