<?php
/**
 * @file
 * ulf_search_settings.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ulf_search_settings_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_courses';
  $page->task = 'page';
  $page->admin_title = 'Search - courses';
  $page->admin_description = '';
  $page->path = 'kurser';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Kurser',
    'name' => 'main-menu',
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
  $handler->name = 'page_search_courses__panel';
  $handler->task = 'page';
  $handler->subtask = 'search_courses';
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
  $display->uuid = '638248a9-b3be-42cc-b840-e4e1e62f0114';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4e4e009d-a620-453a-acb5-98f13a7bbeb1';
    $pane->panel = 'middle';
    $pane->type = 'search_box';
    $pane->subtype = 'search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'search_node' => array(
        'id' => '1443436570',
        'server' => 'search_node',
        'index' => 'educators',
        'options' => array(
          'cache_expire' => '30',
          'size' => '8',
          'initial_query_enable' => 1,
          'initial_query_text' => '',
          'fields' => array(
            'field_teaser' => 'field_teaser',
            'title' => 'title',
            'author:field_profile_name' => 0,
            'author:uid' => 0,
            'changed' => 0,
            'created' => 0,
            'field_period:value' => 0,
            'field_price' => 0,
            'nid' => 0,
            'search_api_language' => 0,
            'type' => 0,
          ),
          'filters' => array(
            'field_subject' => 'field_subject',
            'field_educational_goals' => 0,
            'field_offer_type' => 0,
            'field_relevance_educators' => 0,
            'field_relevance_primary_school' => 0,
            'field_relevance_upper_school' => 0,
            'field_subjects_primary_school' => 0,
            'field_subjects_youth' => 0,
            'field_tags' => 0,
            'field_target_group' => 0,
            'field_target_group_sub' => 0,
          ),
        ),
        'intervals' => array(
          'fields' => array(
            'field_period:value' => 'field_period:value',
            'author:field_profile_name' => 0,
            'author:uid' => 0,
            'changed' => 0,
            'created' => 0,
            'field_price' => 0,
            'field_teaser' => 0,
            'nid' => 0,
            'search_api_language' => 0,
            'title' => 0,
            'type' => 0,
          ),
        ),
        'forces' => array(
          'field' => '_none_',
          'selected' => array(),
        ),
        'templates' => array(
          'box' => '/profiles/ulf/themes/ulftheme/templates/search/angular/search-course.html',
          'result' => '/profiles/ulf/themes/ulftheme/templates/search/angular/results-course.html',
          'pager' => '/profiles/ulf/modules/search_node_page/templates/angular/pager.html',
        ),
      ),
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
    $pane->uuid = '4e4e009d-a620-453a-acb5-98f13a7bbeb1';
    $display->content['new-4e4e009d-a620-453a-acb5-98f13a7bbeb1'] = $pane;
    $display->panels['middle'][0] = 'new-4e4e009d-a620-453a-acb5-98f13a7bbeb1';
    $pane = new stdClass();
    $pane->pid = 'new-6289d997-fcad-46e2-9e66-d34b03470b96';
    $pane->panel = 'middle';
    $pane->type = 'search_result';
    $pane->subtype = 'search_result';
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
    $pane->uuid = '6289d997-fcad-46e2-9e66-d34b03470b96';
    $display->content['new-6289d997-fcad-46e2-9e66-d34b03470b96'] = $pane;
    $display->panels['middle'][1] = 'new-6289d997-fcad-46e2-9e66-d34b03470b96';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_courses'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_day_care';
  $page->task = 'page';
  $page->admin_title = 'Search - day care';
  $page->admin_description = '';
  $page->path = 'dagtilbud';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Dagtilbud',
    'name' => 'main-menu',
    'weight' => '-10',
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
  $handler->name = 'page_search_day_care__panel';
  $handler->task = 'page';
  $handler->subtask = 'search_day_care';
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
  $display->uuid = '628079a0-513c-4ad1-965b-dc9dd22943cc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-dfa56415-9735-4149-b13c-fecff6fecb10';
    $pane->panel = 'middle';
    $pane->type = 'search_box';
    $pane->subtype = 'search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => '',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'search_node' => array(
        'id' => '1441278884',
        'server' => 'search_node',
        'index' => 'courses',
        'options' => array(
          'cache_expire' => '30',
          'size' => '14',
          'initial_query_enable' => 1,
          'initial_query_text' => '',
          'fields' => array(
            'author:field_profile_name' => 'author:field_profile_name',
            'field_full_description:value' => 'field_full_description:value',
            'title' => 'title',
            'author' => 0,
            'changed' => 0,
            'created' => 0,
            'field_free' => 0,
            'field_image:file' => 0,
            'field_period:value' => 0,
            'field_period:value2' => 0,
            'field_period_full_year' => 0,
            'field_price' => 0,
            'field_subject:tid' => 0,
            'nid' => 0,
            'search_api_language' => 0,
            'type' => 0,
          ),
          'filters' => array(
            'field_educational_goals' => 'field_educational_goals',
            'field_offer_type' => 'field_offer_type',
            'field_subject' => 'field_subject',
            'field_target_group_sub' => 'field_target_group_sub',
            'field_subjects_primary_school' => 0,
            'field_subjects_youth' => 0,
            'field_target_group' => 0,
          ),
        ),
        'intervals' => array(
          'fields' => array(
            'field_period:value' => 'field_period:value',
            'author' => 0,
            'author:field_profile_name' => 0,
            'changed' => 0,
            'created' => 0,
            'field_free' => 0,
            'field_full_description:value' => 0,
            'field_image:file' => 0,
            'field_period:value2' => 0,
            'field_period_full_year' => 0,
            'field_price' => 0,
            'field_subject:tid' => 0,
            'nid' => 0,
            'search_api_language' => 0,
            'title' => 0,
            'type' => 0,
          ),
        ),
        'forces' => array(
          'field' => 'field_target_group',
          'selected' => array(
            'Dagtilbud' => 'Dagtilbud',
            'Grundskole' => 0,
            'Ungdomsuddannelse' => 0,
          ),
        ),
        'templates' => array(
          'box' => '/profiles/ulf/themes/ulftheme/templates/search/angular/search-daycare.html',
          'result' => '/profiles/ulf/themes/ulftheme/templates/search/angular/results-daycare.html',
          'pager' => '/profiles/ulf/themes/ulftheme/templates/search/angular/pager.html',
        ),
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
    $pane->uuid = 'dfa56415-9735-4149-b13c-fecff6fecb10';
    $display->content['new-dfa56415-9735-4149-b13c-fecff6fecb10'] = $pane;
    $display->panels['middle'][0] = 'new-dfa56415-9735-4149-b13c-fecff6fecb10';
    $pane = new stdClass();
    $pane->pid = 'new-485b89b0-43a3-4592-8e8e-d0f5160a9288';
    $pane->panel = 'middle';
    $pane->type = 'search_result';
    $pane->subtype = 'search_result';
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
    $pane->uuid = '485b89b0-43a3-4592-8e8e-d0f5160a9288';
    $display->content['new-485b89b0-43a3-4592-8e8e-d0f5160a9288'] = $pane;
    $display->panels['middle'][1] = 'new-485b89b0-43a3-4592-8e8e-d0f5160a9288';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_day_care'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_elementary_school';
  $page->task = 'page';
  $page->admin_title = 'Search - school';
  $page->admin_description = '';
  $page->path = 'grundskole';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Grundskole',
    'name' => 'main-menu',
    'weight' => '-5',
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
  $handler->name = 'page_search_elementary_school__panel';
  $handler->task = 'page';
  $handler->subtask = 'search_elementary_school';
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
  $display->uuid = 'c67ab2d8-1b5e-47fc-9df5-75bed018664e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a7e8be04-63a1-4381-a371-5a09951f34fe';
    $pane->panel = 'middle';
    $pane->type = 'search_box';
    $pane->subtype = 'search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'search_node' => array(
        'id' => '1441278867',
        'server' => 'search_node',
        'index' => 'courses',
        'options' => array(
          'cache_expire' => '30',
          'size' => '14',
          'initial_query_enable' => 1,
          'initial_query_text' => '',
          'fields' => array(
            'author:field_profile_name' => 'author:field_profile_name',
            'field_full_description:value' => 'field_full_description:value',
            'title' => 'title',
            'author' => 0,
            'changed' => 0,
            'created' => 0,
            'field_free' => 0,
            'field_image:file' => 0,
            'field_period:value' => 0,
            'field_period:value2' => 0,
            'field_period_full_year' => 0,
            'field_price' => 0,
            'field_subject:tid' => 0,
            'nid' => 0,
            'search_api_language' => 0,
            'type' => 0,
          ),
          'filters' => array(
            'field_offer_type' => 'field_offer_type',
            'field_subject' => 'field_subject',
            'field_subjects_primary_school' => 'field_subjects_primary_school',
            'field_target_group_sub' => 'field_target_group_sub',
            'field_educational_goals' => 0,
            'field_subjects_youth' => 0,
            'field_target_group' => 0,
          ),
        ),
        'intervals' => array(
          'fields' => array(
            'field_period:value' => 'field_period:value',
            'author' => 0,
            'author:field_profile_name' => 0,
            'changed' => 0,
            'created' => 0,
            'field_free' => 0,
            'field_full_description:value' => 0,
            'field_image:file' => 0,
            'field_period:value2' => 0,
            'field_period_full_year' => 0,
            'field_price' => 0,
            'field_subject:tid' => 0,
            'nid' => 0,
            'search_api_language' => 0,
            'title' => 0,
            'type' => 0,
          ),
        ),
        'forces' => array(
          'field' => 'field_target_group',
          'selected' => array(
            'Grundskole' => 'Grundskole',
            'Dagtilbud' => 0,
            'Ungdomsuddannelse' => 0,
          ),
        ),
        'templates' => array(
          'box' => '/profiles/ulf/themes/ulftheme/templates/search/angular/search-school.html',
          'result' => '/profiles/ulf/themes/ulftheme/templates/search/angular/results-school.html',
          'pager' => '/profiles/ulf/themes/ulftheme/templates/search/angular/pager.html',
        ),
      ),
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
    $pane->uuid = 'a7e8be04-63a1-4381-a371-5a09951f34fe';
    $display->content['new-a7e8be04-63a1-4381-a371-5a09951f34fe'] = $pane;
    $display->panels['middle'][0] = 'new-a7e8be04-63a1-4381-a371-5a09951f34fe';
    $pane = new stdClass();
    $pane->pid = 'new-8baed29e-d0f0-406c-80b5-9b8e61858e9c';
    $pane->panel = 'middle';
    $pane->type = 'search_result';
    $pane->subtype = 'search_result';
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
    $pane->uuid = '8baed29e-d0f0-406c-80b5-9b8e61858e9c';
    $display->content['new-8baed29e-d0f0-406c-80b5-9b8e61858e9c'] = $pane;
    $display->panels['middle'][1] = 'new-8baed29e-d0f0-406c-80b5-9b8e61858e9c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-a7e8be04-63a1-4381-a371-5a09951f34fe';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_elementary_school'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_youth';
  $page->task = 'page';
  $page->admin_title = 'Search - youth';
  $page->admin_description = '';
  $page->path = 'ungdomsuddannelse';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Ungdomsuddannelse',
    'name' => 'main-menu',
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
  $handler->name = 'page_search_youth__panel';
  $handler->task = 'page';
  $handler->subtask = 'search_youth';
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
  $display->uuid = '18f053fb-58e2-4179-aa39-b7cd3636fd09';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-19a1cbde-32f9-4961-913b-e912a8686148';
    $pane->panel = 'middle';
    $pane->type = 'search_box';
    $pane->subtype = 'search_box';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'search_node' => array(
        'id' => '1441950013',
        'server' => 'search_node',
        'index' => 'courses',
        'options' => array(
          'cache_expire' => '30',
          'size' => '14',
          'initial_query_enable' => 1,
          'initial_query_text' => '',
          'fields' => array(
            'author:field_profile_name' => 'author:field_profile_name',
            'field_full_description:value' => 'field_full_description:value',
            'title' => 'title',
            'author' => 0,
            'changed' => 0,
            'created' => 0,
            'field_free' => 0,
            'field_image:file' => 0,
            'field_period:value' => 0,
            'field_period:value2' => 0,
            'field_period_full_year' => 0,
            'field_price' => 0,
            'field_subject:tid' => 0,
            'nid' => 0,
            'search_api_language' => 0,
            'type' => 0,
          ),
          'filters' => array(
            'field_offer_type' => 'field_offer_type',
            'field_subject' => 'field_subject',
            'field_subjects_youth' => 'field_subjects_youth',
            'field_target_group_sub' => 'field_target_group_sub',
            'field_educational_goals' => 0,
            'field_subjects_primary_school' => 0,
            'field_target_group' => 0,
          ),
        ),
        'intervals' => array(
          'fields' => array(
            'field_period:value' => 'field_period:value',
            'author' => 0,
            'author:field_profile_name' => 0,
            'changed' => 0,
            'created' => 0,
            'field_free' => 0,
            'field_full_description:value' => 0,
            'field_image:file' => 0,
            'field_period:value2' => 0,
            'field_period_full_year' => 0,
            'field_price' => 0,
            'field_subject:tid' => 0,
            'nid' => 0,
            'search_api_language' => 0,
            'title' => 0,
            'type' => 0,
          ),
        ),
        'forces' => array(
          'field' => 'field_target_group',
          'selected' => array(
            'Ungdomsuddannelse' => 'Ungdomsuddannelse',
            'Dagtilbud' => 0,
            'Grundskole' => 0,
          ),
        ),
        'templates' => array(
          'box' => '/profiles/ulf/themes/ulftheme/templates/search/angular/search-youth.html',
          'result' => '/profiles/ulf/themes/ulftheme/templates/search/angular/results-youth.html',
          'pager' => '/profiles/ulf/themes/ulftheme/templates/search/angular/pager.html',
        ),
      ),
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
    $pane->uuid = '19a1cbde-32f9-4961-913b-e912a8686148';
    $display->content['new-19a1cbde-32f9-4961-913b-e912a8686148'] = $pane;
    $display->panels['middle'][0] = 'new-19a1cbde-32f9-4961-913b-e912a8686148';
    $pane = new stdClass();
    $pane->pid = 'new-9d653cc5-9b10-4c19-9884-7da0e70281b7';
    $pane->panel = 'middle';
    $pane->type = 'search_result';
    $pane->subtype = 'search_result';
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
    $pane->uuid = '9d653cc5-9b10-4c19-9884-7da0e70281b7';
    $display->content['new-9d653cc5-9b10-4c19-9884-7da0e70281b7'] = $pane;
    $display->panels['middle'][1] = 'new-9d653cc5-9b10-4c19-9884-7da0e70281b7';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-19a1cbde-32f9-4961-913b-e912a8686148';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_youth'] = $page;

  return $pages;

}
