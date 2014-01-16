<?php
/**
 * @file
 * ulf_course_providers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ulf_course_providers_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ulf_author_pane';
  $view->description = 'Provides an author pane for content';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Author pane';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = TRUE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Ulf author pane */
  $handler = $view->new_display('panel_pane', 'Ulf author pane', 'panel_pane_1');
  $translatables['ulf_author_pane'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('All'),
    t('Ulf author pane'),
    t('View panes'),
  );
  $export['ulf_author_pane'] = $view;

  $view = new view();
  $view->name = 'ulf_course_by_user';
  $view->description = 'Displays all courses created by the user.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ulf course by user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Beskrivelse */
  $handler->display->display_options['fields']['field_full_description']['id'] = 'field_full_description';
  $handler->display->display_options['fields']['field_full_description']['table'] = 'field_data_field_full_description';
  $handler->display->display_options['fields']['field_full_description']['field'] = 'field_full_description';
  $handler->display->display_options['fields']['field_full_description']['label'] = '';
  $handler->display->display_options['fields']['field_full_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_full_description']['element_label_colon'] = FALSE;
  /* Field: Field: Upload et billede/illustration */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3>[title]</h3>
<div class="search-module--result-image">[field_image]</div>
<div class="search-module--result-content">[field_full_description]</div>
[title]
';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'search-module--result';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $translatables['ulf_course_by_user'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<h3>[title]</h3>
<div class="search-module--result-image">[field_image]</div>
<div class="search-module--result-content">[field_full_description]</div>
[title]
'),
    t('All'),
    t('Content pane'),
    t('View panes'),
  );
  $export['ulf_course_by_user'] = $view;

  $view = new view();
  $view->name = 'ulf_user_contact';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Ulf user contact';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Navn */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name']['element_label_colon'] = FALSE;
  /* Field: User: Address */
  $handler->display->display_options['fields']['field_profile_address']['id'] = 'field_profile_address';
  $handler->display->display_options['fields']['field_profile_address']['table'] = 'field_data_field_profile_address';
  $handler->display->display_options['fields']['field_profile_address']['field'] = 'field_profile_address';
  $handler->display->display_options['fields']['field_profile_address']['exclude'] = TRUE;
  /* Field: User: By */
  $handler->display->display_options['fields']['field_profile_city']['id'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['table'] = 'field_data_field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['field'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['exclude'] = TRUE;
  /* Field: User: Hjemmeside */
  $handler->display->display_options['fields']['field_profile_home_page']['id'] = 'field_profile_home_page';
  $handler->display->display_options['fields']['field_profile_home_page']['table'] = 'field_data_field_profile_home_page';
  $handler->display->display_options['fields']['field_profile_home_page']['field'] = 'field_profile_home_page';
  $handler->display->display_options['fields']['field_profile_home_page']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_home_page']['click_sort_column'] = 'url';
  /* Field: User: Postnr. */
  $handler->display->display_options['fields']['field_profile_postal_code']['id'] = 'field_profile_postal_code';
  $handler->display->display_options['fields']['field_profile_postal_code']['table'] = 'field_data_field_profile_postal_code';
  $handler->display->display_options['fields']['field_profile_postal_code']['field'] = 'field_profile_postal_code';
  $handler->display->display_options['fields']['field_profile_postal_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_postal_code']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: User: Telefonnr. */
  $handler->display->display_options['fields']['field_profile_phone']['id'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['table'] = 'field_data_field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['field'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['exclude'] = TRUE;
  /* Field: User: Træffetid */
  $handler->display->display_options['fields']['field_profile_order_availa']['id'] = 'field_profile_order_availa';
  $handler->display->display_options['fields']['field_profile_order_availa']['table'] = 'field_data_field_profile_order_availa';
  $handler->display->display_options['fields']['field_profile_order_availa']['field'] = 'field_profile_order_availa';
  $handler->display->display_options['fields']['field_profile_order_availa']['exclude'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3><a href="/user/[uid]">[field_profile_name]</a></h3>
<div class="block-module--field-wrapper">
  <div class="block-module--field-label">Adresse</div>
  <div class="block-inline-module--field-text">[field_profile_address]</div> 
  <div class="block-inline-module--field-text">[field_profile_postal_code] [field_profile_city]</div>
</div>
<div class="block-module--field-wrapper">
  <div class="block-module--field-label">Kontaktinformation</div>
  <div class="block-inline-module--field-text">Telefon: [field_profile_phone]</div> 
  <div class="block-inline-module--field-text">Hjemmeside: [field_profile_home_page]</div>
</div>
<div class="block-module--field-wrapper">
  <div class="block-module--field-label">Træffetid</div>
  <div class="block-inline-module--field-text">[field_profile_order_availa]</div> 
</div>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $translatables['ulf_user_contact'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Address'),
    t('By'),
    t('Hjemmeside'),
    t('Postnr.'),
    t('Telefonnr.'),
    t('Træffetid'),
    t('<h3><a href="/user/[uid]">[field_profile_name]</a></h3>
<div class="block-module--field-wrapper">
  <div class="block-module--field-label">Adresse</div>
  <div class="block-inline-module--field-text">[field_profile_address]</div> 
  <div class="block-inline-module--field-text">[field_profile_postal_code] [field_profile_city]</div>
</div>
<div class="block-module--field-wrapper">
  <div class="block-module--field-label">Kontaktinformation</div>
  <div class="block-inline-module--field-text">Telefon: [field_profile_phone]</div> 
  <div class="block-inline-module--field-text">Hjemmeside: [field_profile_home_page]</div>
</div>
<div class="block-module--field-wrapper">
  <div class="block-module--field-label">Træffetid</div>
  <div class="block-inline-module--field-text">[field_profile_order_availa]</div> 
</div>
'),
    t('All'),
    t('Content pane'),
    t('View panes'),
  );
  $export['ulf_user_contact'] = $view;

  return $export;
}
