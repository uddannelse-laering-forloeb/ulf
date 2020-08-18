<?php

/**
 * @file
 * ulf_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ulf_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'newsletter_archive';
  $page->task = 'page';
  $page->admin_title = 'Newsletter archive';
  $page->admin_description = '';
  $page->path = 'newsletter/archive';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_newsletter_archive__panel';
  $handler->task = 'page';
  $handler->subtask = 'newsletter_archive';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'two_split';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'alpha' => NULL,
      'beta' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '48b90bda-edcf-48b2-9481-be555bc2cfc2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_newsletter_archive__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-675cf0a4-7b70-43e4-8aba-e92150d1914b';
  $pane->panel = 'alpha';
  $pane->type = 'newsletter_archive';
  $pane->subtype = 'newsletter_archive';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '675cf0a4-7b70-43e4-8aba-e92150d1914b';
  $display->content['new-675cf0a4-7b70-43e4-8aba-e92150d1914b'] = $pane;
  $display->panels['alpha'][0] = 'new-675cf0a4-7b70-43e4-8aba-e92150d1914b';
  $pane = new stdClass();
  $pane->pid = 'new-56544fdc-11ee-47b0-a1d3-cfe54aca9ce7';
  $pane->panel = 'beta';
  $pane->type = 'block';
  $pane->subtype = 'menu_block-ulf_base-1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '56544fdc-11ee-47b0-a1d3-cfe54aca9ce7';
  $display->content['new-56544fdc-11ee-47b0-a1d3-cfe54aca9ce7'] = $pane;
  $display->panels['beta'][0] = 'new-56544fdc-11ee-47b0-a1d3-cfe54aca9ce7';
  $pane = new stdClass();
  $pane->pid = 'new-abb6dfd8-67aa-4df8-b212-96eb6eb52f15';
  $pane->panel = 'beta';
  $pane->type = 'block';
  $pane->subtype = 'mailchimp_signup-signup_to_newsletter';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'abb6dfd8-67aa-4df8-b212-96eb6eb52f15';
  $display->content['new-abb6dfd8-67aa-4df8-b212-96eb6eb52f15'] = $pane;
  $display->panels['beta'][1] = 'new-abb6dfd8-67aa-4df8-b212-96eb6eb52f15';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['newsletter_archive'] = $page;

  return $pages;

}
