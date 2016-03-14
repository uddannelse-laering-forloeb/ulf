<?php
/**
 * @file
 * ulf_maps.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_maps_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
