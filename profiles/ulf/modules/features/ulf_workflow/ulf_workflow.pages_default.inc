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
    $pane->pid = 'new-a202563c-99ee-4129-864f-74916b348808';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ulf_workbench_edits_by_user-panel_pane_1';
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
    $pane->uuid = 'a202563c-99ee-4129-864f-74916b348808';
    $display->content['new-a202563c-99ee-4129-864f-74916b348808'] = $pane;
    $display->panels['middle'][0] = 'new-a202563c-99ee-4129-864f-74916b348808';
    $pane = new stdClass();
    $pane->pid = 'new-af211b72-1a1a-4830-83ca-7d46f2422502';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ulf_workbench_edits_by_user-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'af211b72-1a1a-4830-83ca-7d46f2422502';
    $display->content['new-af211b72-1a1a-4830-83ca-7d46f2422502'] = $pane;
    $display->panels['middle'][1] = 'new-af211b72-1a1a-4830-83ca-7d46f2422502';
    $pane = new stdClass();
    $pane->pid = 'new-b143cffd-447b-4793-85df-4c706935d924';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ulf_workbench_edits_by_user-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b143cffd-447b-4793-85df-4c706935d924';
    $display->content['new-b143cffd-447b-4793-85df-4c706935d924'] = $pane;
    $display->panels['middle'][2] = 'new-b143cffd-447b-4793-85df-4c706935d924';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['myworkbench__panel_context_d4523189-c8b5-4d33-b532-de17adacbccc'] = $handler;

  return $export;
}
