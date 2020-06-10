<?php

/**
 * Enable ulf_aarhus settings module if it exists.
 */
function ulf_pagebuilder_update_7001(&$sandbox) {
  $module_enable = array();
  $aarhus_path = drupal_get_path('module', 'video_embed_dreambroker');
  if (file_exists($aarhus_path . '/video_embed_dreambroker.module')){
    $module_enable[] = 'video_embed_dreambroker';
  }

  module_enable($module_enable);
}

function ulf_pagebuilder_update_7002(&$sandbox) {
  $module_enable = array();
  $module_path = drupal_get_path('module', 'color_field');
  if (file_exists($module_path . '/color_field.module')){
    $module_enable[] = 'color_field';
  }

  module_enable($module_enable);
}
