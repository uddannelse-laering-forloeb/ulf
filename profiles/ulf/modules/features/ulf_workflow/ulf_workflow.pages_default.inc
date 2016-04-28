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
  $handler->name = 'myworkbench__others';
  $handler->task = 'myworkbench';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Others',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'others',
    'access' => array(
      'plugins' => array(),
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
    $pane->pid = 'new-5c907e36-565b-429e-a5ac-2f74f532e569';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ulf_workbench_edits_by_user-panel_pane_5';
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
    $pane->uuid = '5c907e36-565b-429e-a5ac-2f74f532e569';
    $display->content['new-5c907e36-565b-429e-a5ac-2f74f532e569'] = $pane;
    $display->panels['middle'][0] = 'new-5c907e36-565b-429e-a5ac-2f74f532e569';
    $pane = new stdClass();
    $pane->pid = 'new-e2053737-8401-4e72-8986-813ef00d6152';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ulf_workbench_edits_by_user-panel_pane_6';
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
    $pane->uuid = 'e2053737-8401-4e72-8986-813ef00d6152';
    $display->content['new-e2053737-8401-4e72-8986-813ef00d6152'] = $pane;
    $display->panels['middle'][1] = 'new-e2053737-8401-4e72-8986-813ef00d6152';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['myworkbench__others'] = $handler;

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
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'administer nodes',
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

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'myworkbench__redirect_context_7c623ade-2ac9-437d-ab42-5823046c0914';
  $handler->task = 'myworkbench';
  $handler->subtask = '';
  $handler->handler = 'redirect_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Redirect',
    'contexts' => array(),
    'relationships' => array(),
    'path' => 'admin/workbench/awaiting-revision',
    'query' => '',
    'fragment' => '',
    'name' => '',
  );
  $export['myworkbench__redirect_context_7c623ade-2ac9-437d-ab42-5823046c0914'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function ulf_workflow_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'admin_all_courses';
  $page->task = 'page';
  $page->admin_title = 'Admin all courses';
  $page->admin_description = '';
  $page->path = 'admin/workbench/all-courses';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view all unpublished content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'All courses',
    'name' => 'management',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_admin_all_courses__panel';
  $handler->task = 'page';
  $handler->subtask = 'admin_all_courses';
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
  $display->uuid = '9c1c5e10-48c9-4823-ab4e-e1a241074e8d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-29fee4b8-08db-435d-b5c1-1918d8becfa8';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ulf_workbench_edits_by_user-panel_pane_4';
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
    $pane->uuid = '29fee4b8-08db-435d-b5c1-1918d8becfa8';
    $display->content['new-29fee4b8-08db-435d-b5c1-1918d8becfa8'] = $pane;
    $display->panels['middle'][0] = 'new-29fee4b8-08db-435d-b5c1-1918d8becfa8';
    $pane = new stdClass();
    $pane->pid = 'new-06bd40ba-f9c5-4ce0-978b-53d4a0ecdd32';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ulf_workbench_edits_by_user-panel_pane_6';
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
    $pane->uuid = '06bd40ba-f9c5-4ce0-978b-53d4a0ecdd32';
    $display->content['new-06bd40ba-f9c5-4ce0-978b-53d4a0ecdd32'] = $pane;
    $display->panels['middle'][1] = 'new-06bd40ba-f9c5-4ce0-978b-53d4a0ecdd32';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['admin_all_courses'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'admin_awaiting_revision';
  $page->task = 'page';
  $page->admin_title = 'Admin awaiting revision';
  $page->admin_description = '';
  $page->path = 'admin/workbench/awaiting-revision';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view all unpublished content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Content awaiting editor revision',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_admin_awaiting_revision__panel';
  $handler->task = 'page';
  $handler->subtask = 'admin_awaiting_revision';
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
  $display->uuid = '35f3261f-4ce2-4f43-8f66-23f1887d3c74';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-431785eb-c764-4f26-9342-9bbb04eda70f';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ulf_workbench_edits_by_user-panel_pane_5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'exposed' => array(
        'combine' => '',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '431785eb-c764-4f26-9342-9bbb04eda70f';
    $display->content['new-431785eb-c764-4f26-9342-9bbb04eda70f'] = $pane;
    $display->panels['middle'][0] = 'new-431785eb-c764-4f26-9342-9bbb04eda70f';
    $pane = new stdClass();
    $pane->pid = 'new-754738ff-4081-4846-9c48-93f23a12d7aa';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ulf_workbench_edits_by_user-panel_pane_7';
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
    $pane->uuid = '754738ff-4081-4846-9c48-93f23a12d7aa';
    $display->content['new-754738ff-4081-4846-9c48-93f23a12d7aa'] = $pane;
    $display->panels['middle'][1] = 'new-754738ff-4081-4846-9c48-93f23a12d7aa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['admin_awaiting_revision'] = $page;

  return $pages;

}
