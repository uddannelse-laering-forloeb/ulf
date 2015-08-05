<?php
/**
 * @file
 * ulf_workflow.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function ulf_workflow_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'myworkbench__panel_context_d4523189-c8b5-4d33-b532-de17adacbccc';
  $handler->task = 'myworkbench';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Content provider',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'beccf3ab-0fd1-400b-83a0-560ff947e84d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5ed81e95-24b6-46fb-8f1e-018011329a2e';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'ulf_workbench_edits_by_user';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '25',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5ed81e95-24b6-46fb-8f1e-018011329a2e';
    $display->content['new-5ed81e95-24b6-46fb-8f1e-018011329a2e'] = $pane;
    $display->panels['middle'][0] = 'new-5ed81e95-24b6-46fb-8f1e-018011329a2e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['myworkbench__panel_context_d4523189-c8b5-4d33-b532-de17adacbccc'] = $handler;

  return $export;
}
