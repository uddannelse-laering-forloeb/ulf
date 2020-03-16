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
