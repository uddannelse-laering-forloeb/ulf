<?php
/**
 * @file
 * ulf_footer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_footer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
