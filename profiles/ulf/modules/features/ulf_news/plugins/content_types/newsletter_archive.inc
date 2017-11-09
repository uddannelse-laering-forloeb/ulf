<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Newsletter archive'),
  'description' => t('Display the value of newsletter archive from admin page setup'),
  'category' => t('Custom Panes'),
  'render callback' => 'ulf_news_newsletter_archive_render',
  'admin info' => 'ulf_news_newsletter_archive_info',
  'defaults' => array(),
  'all contexts' => TRUE,
);

/**
 * Render the panel.
 */
function ulf_news_newsletter_archive_render($subtype, $conf, $args, $contexts) {
  $archive_content = variable_get('ulf_newsletter_archive_content', '');
  // Render as a block.
  $block = new stdClass();
  $block->module = 'entity';
  $block->title = t('Newsletter archive');
  $block->content = (!empty($archive_content['value'])) ? $archive_content['value'] : '';
  return $block;

}

/**
3  * 'admin info' callback for panel pane.
4  */
function examplemodule_twitter_timeline_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
      $block = new stdClass;
      $block->title = $conf['override_title'] ? $conf['override_title_text'] : '';
      $block->content = t('Display newsletter content from administration page');
    return $block;
  }
}