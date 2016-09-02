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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-95a21ae9-c873-4b4e-8e63-ff685d040c7a';
    $pane->panel = 'alpha';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Newsletter archive',
      'title' => 'Newsletter archive',
      'body' => '<div class="content--newsletter-archive">
<h3 class="content--header-grouping">Generelt</h3>
<script language="javascript" src="//boernekulturaarhus.us8.list-manage.com/generate-js/?u=064509eb2d1820f18782ba2da&fid=13689&show=50" type="text/javascript"></script>

<h3 class="content--header-grouping">Dagtilbud</h3>
<script language="javascript" src="//boernekulturaarhus.us8.list-manage.com/generate-js/?u=064509eb2d1820f18782ba2da&fid=13677&show=50" type="text/javascript"></script>

<h3 class="content--header-grouping">Grundskole</h3>
<script language="javascript" src="//boernekulturaarhus.us8.list-manage.com/generate-js/?u=064509eb2d1820f18782ba2da&fid=13681&show=50" type="text/javascript"></script>

<h3 class="content--header-grouping">Ungdomsuddannelse</h3>
<script language="javascript" src="//boernekulturaarhus.us8.list-manage.com/generate-js/?u=064509eb2d1820f18782ba2da&fid=13685&show=10" type="text/javascript"></script>
</div>
',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '95a21ae9-c873-4b4e-8e63-ff685d040c7a';
    $display->content['new-95a21ae9-c873-4b4e-8e63-ff685d040c7a'] = $pane;
    $display->panels['alpha'][0] = 'new-95a21ae9-c873-4b4e-8e63-ff685d040c7a';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'abb6dfd8-67aa-4df8-b212-96eb6eb52f15';
    $display->content['new-abb6dfd8-67aa-4df8-b212-96eb6eb52f15'] = $pane;
    $display->panels['beta'][0] = 'new-abb6dfd8-67aa-4df8-b212-96eb6eb52f15';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['newsletter_archive'] = $page;

  return $pages;

}
