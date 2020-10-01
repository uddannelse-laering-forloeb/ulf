<?php

/**
 * @file
 * ulf_workflow.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ulf_workflow_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ulf_all_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ulf all content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access content overview';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'field_target_group' => 'field_target_group',
    'name' => 'name',
    'status' => 'status',
    'changed' => 'changed',
    'clone_node' => 'clone_node',
    'edit_node' => 'edit_node',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target_group' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clone_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Sidefod: Global: Resumé af resultat */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Viser @start - @end af @total';
  /* Forbindelse: Indhold: Content author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Felt: Masse-handlinger: Indhold */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Bruger: Navn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Forfatter';
  /* Felt: Indhold: Published status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Felt: Indhold: Opdateringsdato */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Opdateret';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Kopiér link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['exclude'] = TRUE;
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Handlinger';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node] [clone_node] ';
  /* Sorteringskriterie: Indhold: Opdateringsdato */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Kontekstuelt filter: Indhold: Forfatter uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Udgivet';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filterkriterie: Global: Kombinér felter filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Søgefilter';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Søg efter titel eller indholdsleverandør';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'name' => 'name',
  );
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );

  /* Display: Content */
  $handler = $view->new_display('page', 'Content', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Content';
  $handler->display->display_options['menu']['weight'] = '-9';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Trash */
  $handler = $view->new_display('page', 'Trash', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Papirkurv';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Bruger: Navn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Forfatter';
  /* Felt: Indhold: Published status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Felt: Indhold: Opdateringsdato */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Opdateret';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Handlinger';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Udgivet';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  /* Filterkriterie: Global: Kombinér felter filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Søgefilter';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Søg efter titel eller indholdsleverandør';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'name' => 'name',
  );
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_trashed_value']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/content/trash';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Trash';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Content provider - Trash */
  $handler = $view->new_display('page', 'Content provider - Trash', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Papirkurv';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    18 => '18',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Bruger: Navn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Forfatter';
  /* Felt: Indhold: Published status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Felt: Indhold: Opdateringsdato */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Opdateret';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Handlinger';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[edit_node]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_trashed_value']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/workbench/trash';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Trash';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['ulf_all_content'] = array(
    t('Master'),
    t('All content'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« første'),
    t('‹ forrige'),
    t('næste ›'),
    t('sidste »'),
    t('Viser @start - @end af @total'),
    t('forfatter'),
    t('Indhold'),
    t('- Vælg en handling -'),
    t('Titel'),
    t('Type'),
    t('Overordnet målgruppe'),
    t('Forfatter'),
    t('Status'),
    t('Opdateret'),
    t('Kopiér link'),
    t('Link to edit content'),
    t('Handlinger'),
    t('[edit_node] [clone_node] '),
    t('Alle'),
    t('Udgivet'),
    t('Søgefilter'),
    t('Søg efter titel eller indholdsleverandør'),
    t('Content'),
    t('Trash'),
    t('Papirkurv'),
    t('[edit_node]'),
    t('Content provider - Trash'),
  );
  $export['ulf_all_content'] = $view;

  $view = new view();
  $view->name = 'ulf_workbench_edits_by_user';
  $view->description = 'Lists content edited by the user.';
  $view->tag = 'Workbench';
  $view->base_table = 'node_revision';
  $view->human_name = 'ULF Workbench: Edits by user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Udgivne sider';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'vis alle';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access content overview';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 25, 50, 100, 200';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'nid' => 'nid',
    'title' => 'title',
    'field_profile_name' => 'field_profile_name',
    'type' => 'type',
    'field_target_group' => 'field_target_group',
    'timestamp' => 'timestamp',
    'latest_log_message' => 'latest_log_message',
    'edit_node' => 'edit_node',
    'clone_node' => 'clone_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target_group' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'latest_log_message' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clone_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Shows all content scheduled for publishing or unpublishing';
  $handler->display->display_options['header']['area']['format'] = 'editor';
  /* Opførsel ved ingen resultater: Global: Tekstområde */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Du har intet indhold i denne kategori';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Forbindelse: Indholdsversion: Indhold */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  /* Forbindelse: Indhold: Content author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'vid';
  /* Felt: Indhold: Forfatter uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Felt: Indhold: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Felt: Indholdsversion: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'vid';
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Indholdsversion: Opdateringsdato */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Senest opdateret';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Redigér';
  /* Felt: Indhold: Kopiér link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['clone_node']['label'] = '';
  $handler->display->display_options['fields']['clone_node']['element_label_colon'] = FALSE;
  /* Sorteringskriterie: Indhold: Opdateringsdato */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['relationship'] = 'vid';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Kontekstuelt filter: Bruger: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'vid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_educators' => 'course_educators',
    'course' => 'course',
  );
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'vid';
  $handler->display->display_options['filters']['status']['value'] = '0';
  /* Filterkriterie: Global: Kombinér felter filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Søgefilter';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Søg efter titel eller indholdsleverandør';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_profile_name' => 'field_profile_name',
  );
  /* Filterkriterie: Planlægning: Udgiv den */
  $handler->display->display_options['filters']['publish_on']['id'] = 'publish_on';
  $handler->display->display_options['filters']['publish_on']['table'] = 'scheduler';
  $handler->display->display_options['filters']['publish_on']['field'] = 'publish_on';
  $handler->display->display_options['filters']['publish_on']['relationship'] = 'vid';
  $handler->display->display_options['filters']['publish_on']['operator'] = 'not empty';

  /* Display: Editor - Awaiting revision (New content) */
  $handler = $view->new_display('panel_pane', 'Editor - Awaiting revision (New content)', 'panel_pane_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Afventer revision (Ingen publiseret version)';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Viser alt indhold der venter på revision og endnu ikke har en publiseret version';
  $handler->display->display_options['header']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Sidefod: Global: Resumé af resultat */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Viser @start - @end af @total';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Forfatter uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Felt: Indhold: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Felt: Indholdsversion: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '/node/[nid]/current-revision';
  /* Felt: Bruger: Navn */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_profile_name']['label'] = 'Afsender';
  $handler->display->display_options['fields']['field_profile_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name']['alter']['path'] = '/user/[uid]';
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'vid';
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Indholdsversion: Opdateringsdato */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'vid';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Senest opdateret';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Latest log message */
  $handler->display->display_options['fields']['latest_log_message']['id'] = 'latest_log_message';
  $handler->display->display_options['fields']['latest_log_message']['table'] = 'node';
  $handler->display->display_options['fields']['latest_log_message']['field'] = 'latest_log_message';
  $handler->display->display_options['fields']['latest_log_message']['relationship'] = 'vid';
  $handler->display->display_options['fields']['latest_log_message']['label'] = 'Seneste kommentar';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Redigér';
  /* Felt: Indhold: Kopiér link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['clone_node']['label'] = '';
  $handler->display->display_options['fields']['clone_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Workbench Moderation: Status */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'vid';
  $handler->display->display_options['filters']['state']['value'] = array(
    'needs_review' => 'needs_review',
  );
  $handler->display->display_options['filters']['state']['group'] = 1;
  /* Filterkriterie: Workbench Moderation: Aktuelle */
  $handler->display->display_options['filters']['is_current_1']['id'] = 'is_current_1';
  $handler->display->display_options['filters']['is_current_1']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current_1']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current_1']['relationship'] = 'vid';
  $handler->display->display_options['filters']['is_current_1']['value'] = '1';
  $handler->display->display_options['filters']['is_current_1']['group'] = 1;
  /* Filterkriterie: Global: Kombinér felter filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Søgefilter';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Søg efter titel eller indholdsleverandør';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_profile_name' => 'field_profile_name',
  );
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'vid';
  $handler->display->display_options['filters']['status']['value'] = '0';
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_trashed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );
  /* Filterkriterie: Indhold: Passed review (field_passed_review) */
  $handler->display->display_options['filters']['field_passed_review_value']['id'] = 'field_passed_review_value';
  $handler->display->display_options['filters']['field_passed_review_value']['table'] = 'field_data_field_passed_review';
  $handler->display->display_options['filters']['field_passed_review_value']['field'] = 'field_passed_review_value';
  $handler->display->display_options['filters']['field_passed_review_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_passed_review_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_passed_review_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Editor - Unpublished drafts */
  $handler = $view->new_display('panel_pane', 'Editor - Unpublished drafts', 'panel_pane_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upubliserede udkast';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Viser alle upubliserede udkast';
  $handler->display->display_options['header']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Sidefod: Global: Resumé af resultat */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Viser @start - @end af @total';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Forfatter uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Felt: Indhold: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Felt: Indholdsversion: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Felt: Bruger: Navn */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_profile_name']['label'] = 'Afsender';
  $handler->display->display_options['fields']['field_profile_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name']['alter']['path'] = '/user/[uid]';
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'vid';
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Indholdsversion: Opdateringsdato */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'vid';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Senest opdateret';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Redigér';
  /* Felt: Indhold: Kopiér link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['clone_node']['label'] = '';
  $handler->display->display_options['fields']['clone_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'vid';
  $handler->display->display_options['filters']['status']['value'] = '0';
  /* Filterkriterie: Global: Kombinér felter filter */
  $handler->display->display_options['filters']['combine_1']['id'] = 'combine_1';
  $handler->display->display_options['filters']['combine_1']['table'] = 'views';
  $handler->display->display_options['filters']['combine_1']['field'] = 'combine';
  $handler->display->display_options['filters']['combine_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine_1']['expose']['operator_id'] = 'combine_1_op';
  $handler->display->display_options['filters']['combine_1']['expose']['label'] = 'Søgefilter';
  $handler->display->display_options['filters']['combine_1']['expose']['description'] = 'Søg efter titel eller indholdsleverandør';
  $handler->display->display_options['filters']['combine_1']['expose']['operator'] = 'combine_1_op';
  $handler->display->display_options['filters']['combine_1']['expose']['identifier'] = 'combine_1';
  $handler->display->display_options['filters']['combine_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['combine_1']['fields'] = array(
    'title' => 'title',
    'field_profile_name' => 'field_profile_name',
  );
  /* Filterkriterie: Workbench Moderation: Aktuelle */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  /* Filterkriterie: Workbench Moderation: Status */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'draft' => 'draft',
  );
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_trashed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Editor - Published content */
  $handler = $view->new_display('panel_pane', 'Editor - Published content', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Publiserede forløb';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Viser alle publiserede kurser og forløb';
  $handler->display->display_options['header']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Sidefod: Global: Resumé af resultat */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Viser @start - @end af @total';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Forfatter uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Felt: Indhold: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Felt: Indholdsversion: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Felt: Bruger: Navn */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_profile_name']['label'] = 'Afsender';
  $handler->display->display_options['fields']['field_profile_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name']['alter']['path'] = '/user/[uid]';
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'vid';
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Indholdsversion: Opdateringsdato */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'vid';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Senest opdateret';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Redigér';
  /* Felt: Indhold: Kopiér link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['clone_node']['label'] = '';
  $handler->display->display_options['fields']['clone_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'vid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filterkriterie: Global: Kombinér felter filter */
  $handler->display->display_options['filters']['combine_1']['id'] = 'combine_1';
  $handler->display->display_options['filters']['combine_1']['table'] = 'views';
  $handler->display->display_options['filters']['combine_1']['field'] = 'combine';
  $handler->display->display_options['filters']['combine_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine_1']['expose']['operator_id'] = 'combine_1_op';
  $handler->display->display_options['filters']['combine_1']['expose']['label'] = 'Søgefilter';
  $handler->display->display_options['filters']['combine_1']['expose']['description'] = 'Søg efter titel eller indholdsleverandør';
  $handler->display->display_options['filters']['combine_1']['expose']['operator'] = 'combine_1_op';
  $handler->display->display_options['filters']['combine_1']['expose']['identifier'] = 'combine_1';
  $handler->display->display_options['filters']['combine_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['combine_1']['fields'] = array(
    'title' => 'title',
    'field_profile_name' => 'field_profile_name',
  );
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_trashed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Editor - Awaiting revision (has published) */
  $handler = $view->new_display('panel_pane', 'Editor - Awaiting revision (has published)', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Afventer revision (Har publiseret version)';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Shows all content awaiting revision that has a published version already';
  $handler->display->display_options['header']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Sidefod: Global: Resumé af resultat */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['content'] = 'Viser @start - @end af @total';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Forfatter uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Felt: Indhold: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Felt: Indholdsversion: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '/node/[nid]/current-revision';
  /* Felt: Bruger: Navn */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_profile_name']['label'] = 'Afsender';
  $handler->display->display_options['fields']['field_profile_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name']['alter']['path'] = '/user/[uid]';
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'vid';
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Indholdsversion: Opdateringsdato */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'vid';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Senest opdateret';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Latest log message */
  $handler->display->display_options['fields']['latest_log_message']['id'] = 'latest_log_message';
  $handler->display->display_options['fields']['latest_log_message']['table'] = 'node';
  $handler->display->display_options['fields']['latest_log_message']['field'] = 'latest_log_message';
  $handler->display->display_options['fields']['latest_log_message']['relationship'] = 'vid';
  $handler->display->display_options['fields']['latest_log_message']['label'] = 'Seneste kommentar';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Redigér';
  /* Felt: Indhold: Kopiér link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['clone_node']['label'] = '';
  $handler->display->display_options['fields']['clone_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Workbench Moderation: Status */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'vid';
  $handler->display->display_options['filters']['state']['value'] = array(
    'needs_review' => 'needs_review',
  );
  $handler->display->display_options['filters']['state']['group'] = 1;
  /* Filterkriterie: Workbench Moderation: Aktuelle */
  $handler->display->display_options['filters']['is_current_1']['id'] = 'is_current_1';
  $handler->display->display_options['filters']['is_current_1']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current_1']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current_1']['relationship'] = 'vid';
  $handler->display->display_options['filters']['is_current_1']['value'] = '1';
  $handler->display->display_options['filters']['is_current_1']['group'] = 1;
  /* Filterkriterie: Global: Kombinér felter filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Søgefilter';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Søg efter titel eller indholdsleverandør';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_profile_name' => 'field_profile_name',
  );
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'vid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_trashed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Editor - Scheduled publishing */
  $handler = $view->new_display('page', 'Editor - Scheduled publishing', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Scheduled publishing';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'nid' => 'nid',
    'title' => 'title',
    'type' => 'type',
    'field_target_group' => 'field_target_group',
    'publish_on' => 'publish_on',
    'unpublish_on' => 'unpublish_on',
    'timestamp' => 'timestamp',
    'edit_node' => 'edit_node',
    'clone_node' => 'clone_node',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target_group' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'publish_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'unpublish_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clone_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Shows all content scheduled for publishing or unpublishing';
  $handler->display->display_options['header']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Forfatter uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Felt: Indhold: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Felt: Indholdsversion: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'vid';
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Planlægning: Udgiv den */
  $handler->display->display_options['fields']['publish_on']['id'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['table'] = 'scheduler';
  $handler->display->display_options['fields']['publish_on']['field'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['relationship'] = 'vid';
  $handler->display->display_options['fields']['publish_on']['date_format'] = 'short';
  $handler->display->display_options['fields']['publish_on']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Planlægning: Afpublicér den */
  $handler->display->display_options['fields']['unpublish_on']['id'] = 'unpublish_on';
  $handler->display->display_options['fields']['unpublish_on']['table'] = 'scheduler';
  $handler->display->display_options['fields']['unpublish_on']['field'] = 'unpublish_on';
  $handler->display->display_options['fields']['unpublish_on']['relationship'] = 'vid';
  $handler->display->display_options['fields']['unpublish_on']['date_format'] = 'short';
  $handler->display->display_options['fields']['unpublish_on']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indholdsversion: Opdateringsdato */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Senest opdateret';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Redigér';
  /* Felt: Indhold: Kopiér link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['clone_node']['label'] = '';
  $handler->display->display_options['fields']['clone_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Planlægning: Udgiv den */
  $handler->display->display_options['filters']['publish_on']['id'] = 'publish_on';
  $handler->display->display_options['filters']['publish_on']['table'] = 'scheduler';
  $handler->display->display_options['filters']['publish_on']['field'] = 'publish_on';
  $handler->display->display_options['filters']['publish_on']['relationship'] = 'vid';
  $handler->display->display_options['filters']['publish_on']['operator'] = 'not empty';
  $handler->display->display_options['filters']['publish_on']['group'] = 2;
  /* Filterkriterie: Planlægning: Afpublicér den */
  $handler->display->display_options['filters']['unpublish_on']['id'] = 'unpublish_on';
  $handler->display->display_options['filters']['unpublish_on']['table'] = 'scheduler';
  $handler->display->display_options['filters']['unpublish_on']['field'] = 'unpublish_on';
  $handler->display->display_options['filters']['unpublish_on']['relationship'] = 'vid';
  $handler->display->display_options['filters']['unpublish_on']['operator'] = 'not empty';
  $handler->display->display_options['filters']['unpublish_on']['group'] = 2;
  /* Filterkriterie: Planlægning: Afpublicér den */
  $handler->display->display_options['filters']['unpublish_on_1']['id'] = 'unpublish_on_1';
  $handler->display->display_options['filters']['unpublish_on_1']['table'] = 'scheduler';
  $handler->display->display_options['filters']['unpublish_on_1']['field'] = 'unpublish_on';
  $handler->display->display_options['filters']['unpublish_on_1']['relationship'] = 'vid';
  $handler->display->display_options['filters']['unpublish_on_1']['operator'] = '!=';
  $handler->display->display_options['filters']['unpublish_on_1']['value']['value'] = '2030-01-01 23:59:59';
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_trashed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'admin/workbench/scheduled';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Planlagt';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Awaiting revision */
  $handler = $view->new_display('panel_pane', 'Awaiting revision', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Behandles af redaktionen';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title_1' => 'title_1',
    'type' => 'type',
    'field_target_group' => 'field_target_group',
    'log' => 'log',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
    'clone_node' => 'clone_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target_group' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'log' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clone_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Viser indhold der afventer redaktionelt review eller indhold du måske skal reagere på før publisering.';
  $handler->display->display_options['header']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Forbindelse: Workbench Moderation: Bruger */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  /* Forbindelse: Indholdsversion: Indhold */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indholdsversion: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Felt: Indholdsversion: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = '/node/[nid]';
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Indhold: Latest log message */
  $handler->display->display_options['fields']['latest_log_message']['id'] = 'latest_log_message';
  $handler->display->display_options['fields']['latest_log_message']['table'] = 'node';
  $handler->display->display_options['fields']['latest_log_message']['field'] = 'latest_log_message';
  $handler->display->display_options['fields']['latest_log_message']['relationship'] = 'nid';
  $handler->display->display_options['fields']['latest_log_message']['label'] = 'Seneste kommentar';
  /* Felt: Indhold: Opdateringsdato */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'nid';
  $handler->display->display_options['fields']['changed']['label'] = 'Senest opdateret';
  $handler->display->display_options['fields']['changed']['date_format'] = 'raw time ago';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Redigér';
  /* Felt: Indhold: Kopiér link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['clone_node']['label'] = '';
  $handler->display->display_options['fields']['clone_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Indhold: Forfatter uid */
  $handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['arguments']['uid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['uid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid_1']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Workbench Moderation: Aktuelle */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  /* Filterkriterie: Workbench Moderation: Status */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'needs_review' => 'needs_review',
  );
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['relationship'] = 'nid';
  $handler->display->display_options['filters']['field_trashed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );
  /* Filterkriterie: Indhold: Passed review (field_passed_review) */
  $handler->display->display_options['filters']['field_passed_review_value']['id'] = 'field_passed_review_value';
  $handler->display->display_options['filters']['field_passed_review_value']['table'] = 'field_data_field_passed_review';
  $handler->display->display_options['filters']['field_passed_review_value']['field'] = 'field_passed_review_value';
  $handler->display->display_options['filters']['field_passed_review_value']['relationship'] = 'nid';
  $handler->display->display_options['filters']['field_passed_review_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_passed_review_value']['value'] = array(
    1 => '1',
  );

  /* Display: Unpublished drafts */
  $handler = $view->new_display('panel_pane', 'Unpublished drafts', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ikke udgivet';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'nid' => 'nid',
    'title' => 'title',
    'type' => 'type',
    'field_target_group' => 'field_target_group',
    'timestamp' => 'timestamp',
    'edit_node' => 'edit_node',
    'clone_node' => 'clone_node',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target_group' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clone_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Viser dine upubliserede kladder';
  $handler->display->display_options['header']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Forbindelse: Indholdsversion: Indhold */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  /* Forbindelse: Indhold: Content author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'vid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontekstuelt filter: Bruger: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'vid';
  $handler->display->display_options['filters']['status']['value'] = '0';
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_trashed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );
  /* Filterkriterie: Workbench Moderation: Status */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['operator'] = 'not in';
  $handler->display->display_options['filters']['state']['value'] = array(
    'needs_review' => 'needs_review',
  );
  /* Filterkriterie: Indhold: Passed review (field_passed_review) */
  $handler->display->display_options['filters']['field_passed_review_value']['id'] = 'field_passed_review_value';
  $handler->display->display_options['filters']['field_passed_review_value']['table'] = 'field_data_field_passed_review';
  $handler->display->display_options['filters']['field_passed_review_value']['field'] = 'field_passed_review_value';
  $handler->display->display_options['filters']['field_passed_review_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_passed_review_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_passed_review_value']['value'] = array(
    1 => '1',
  );

  /* Display: Published content */
  $handler = $view->new_display('panel_pane', 'Published content', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Udgivet';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'type' => 'type',
    'field_target_group' => 'field_target_group',
    'timestamp' => 'timestamp',
    'edit_node' => 'edit_node',
    'clone_node' => 'clone_node',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target_group' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clone_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Overskrift: Global: Tekstområde */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Denne liste viser alt udgivet indhold';
  $handler->display->display_options['header']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indholdsversion: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Felt: Indholdsversion: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'vid';
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Indholdsversion: Opdateringsdato */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'vid';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Senest opdateret';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Redigér';
  /* Felt: Indhold: Kopiér link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['clone_node']['label'] = '';
  $handler->display->display_options['fields']['clone_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'vid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_trashed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Scheduled publishing/unpublishing */
  $handler = $view->new_display('panel_pane', 'Scheduled publishing/unpublishing', 'panel_pane_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Planlagt til udgivelse';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'nid' => 'nid',
    'title' => 'title',
    'type' => 'type',
    'field_target_group' => 'field_target_group',
    'publish_on' => 'publish_on',
    'unpublish_on' => 'unpublish_on',
    'timestamp' => 'timestamp',
    'edit_node' => 'edit_node',
    'clone_node' => 'clone_node',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target_group' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'publish_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'unpublish_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clone_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Forfatter uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Felt: Indhold: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Felt: Indholdsversion: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'vid';
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Planlægning: Udgiv den */
  $handler->display->display_options['fields']['publish_on']['id'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['table'] = 'scheduler';
  $handler->display->display_options['fields']['publish_on']['field'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['relationship'] = 'vid';
  $handler->display->display_options['fields']['publish_on']['date_format'] = 'short';
  $handler->display->display_options['fields']['publish_on']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Planlægning: Afpublicér den */
  $handler->display->display_options['fields']['unpublish_on']['id'] = 'unpublish_on';
  $handler->display->display_options['fields']['unpublish_on']['table'] = 'scheduler';
  $handler->display->display_options['fields']['unpublish_on']['field'] = 'unpublish_on';
  $handler->display->display_options['fields']['unpublish_on']['relationship'] = 'vid';
  $handler->display->display_options['fields']['unpublish_on']['date_format'] = 'short';
  $handler->display->display_options['fields']['unpublish_on']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indholdsversion: Opdateringsdato */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Senest opdateret';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Redigér';
  /* Felt: Indhold: Kopiér link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['clone_node']['label'] = '';
  $handler->display->display_options['fields']['clone_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Planlægning: Afpublicér den */
  $handler->display->display_options['filters']['unpublish_on']['id'] = 'unpublish_on';
  $handler->display->display_options['filters']['unpublish_on']['table'] = 'scheduler';
  $handler->display->display_options['filters']['unpublish_on']['field'] = 'unpublish_on';
  $handler->display->display_options['filters']['unpublish_on']['relationship'] = 'vid';
  $handler->display->display_options['filters']['unpublish_on']['operator'] = '!=';
  $handler->display->display_options['filters']['unpublish_on']['value']['value'] = '2030-01-01 23:59:59';
  $handler->display->display_options['filters']['unpublish_on']['group'] = 1;
  /* Filterkriterie: Planlægning: Afpublicér den */
  $handler->display->display_options['filters']['unpublish_on_1']['id'] = 'unpublish_on_1';
  $handler->display->display_options['filters']['unpublish_on_1']['table'] = 'scheduler';
  $handler->display->display_options['filters']['unpublish_on_1']['field'] = 'unpublish_on';
  $handler->display->display_options['filters']['unpublish_on_1']['relationship'] = 'vid';
  $handler->display->display_options['filters']['unpublish_on_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['unpublish_on_1']['group'] = 2;
  /* Filterkriterie: Planlægning: Udgiv den */
  $handler->display->display_options['filters']['publish_on']['id'] = 'publish_on';
  $handler->display->display_options['filters']['publish_on']['table'] = 'scheduler';
  $handler->display->display_options['filters']['publish_on']['field'] = 'publish_on';
  $handler->display->display_options['filters']['publish_on']['relationship'] = 'vid';
  $handler->display->display_options['filters']['publish_on']['operator'] = 'not empty';
  $handler->display->display_options['filters']['publish_on']['group'] = 2;
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'vid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 3;
  /* Filterkriterie: Indhold: Passed review (field_passed_review) */
  $handler->display->display_options['filters']['field_passed_review_value']['id'] = 'field_passed_review_value';
  $handler->display->display_options['filters']['field_passed_review_value']['table'] = 'field_data_field_passed_review';
  $handler->display->display_options['filters']['field_passed_review_value']['field'] = 'field_passed_review_value';
  $handler->display->display_options['filters']['field_passed_review_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_passed_review_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_passed_review_value']['group'] = 3;
  /* Filterkriterie: Indhold: Trashed (field_trashed) */
  $handler->display->display_options['filters']['field_trashed_value']['id'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['table'] = 'field_data_field_trashed';
  $handler->display->display_options['filters']['field_trashed_value']['field'] = 'field_trashed_value';
  $handler->display->display_options['filters']['field_trashed_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_trashed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_trashed_value']['value'] = array(
    1 => '1',
  );

  /* Display: Scheduled publishing */
  $handler = $view->new_display('page', 'Scheduled publishing', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Scheduled publishing';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    18 => '18',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Forfatter uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Felt: Indhold: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'vid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Felt: Indholdsversion: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['link_to_node'] = TRUE;
  /* Felt: Indhold: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'vid';
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = FALSE;
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['relationship'] = 'vid';
  $handler->display->display_options['fields']['field_target_group']['type'] = 'taxonomy_term_reference_plain';
  /* Felt: Planlægning: Udgiv den */
  $handler->display->display_options['fields']['publish_on']['id'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['table'] = 'scheduler';
  $handler->display->display_options['fields']['publish_on']['field'] = 'publish_on';
  $handler->display->display_options['fields']['publish_on']['relationship'] = 'vid';
  $handler->display->display_options['fields']['publish_on']['date_format'] = 'short';
  $handler->display->display_options['fields']['publish_on']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indholdsversion: Opdateringsdato */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Senest opdateret';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'html5_tools_iso8601';
  /* Felt: Indhold: Link to edit content */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Redigér';
  /* Felt: Indhold: Kopiér link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['relationship'] = 'vid';
  $handler->display->display_options['fields']['clone_node']['label'] = '';
  $handler->display->display_options['fields']['clone_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'vid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_educators' => 'course_educators',
    'course' => 'course',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'vid';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filterkriterie: Planlægning: Udgiv den */
  $handler->display->display_options['filters']['publish_on']['id'] = 'publish_on';
  $handler->display->display_options['filters']['publish_on']['table'] = 'scheduler';
  $handler->display->display_options['filters']['publish_on']['field'] = 'publish_on';
  $handler->display->display_options['filters']['publish_on']['relationship'] = 'vid';
  $handler->display->display_options['filters']['publish_on']['operator'] = 'not empty';
  $handler->display->display_options['filters']['publish_on']['group'] = 1;
  /* Filterkriterie: Indhold: Passed review (field_passed_review) */
  $handler->display->display_options['filters']['field_passed_review_value']['id'] = 'field_passed_review_value';
  $handler->display->display_options['filters']['field_passed_review_value']['table'] = 'field_data_field_passed_review';
  $handler->display->display_options['filters']['field_passed_review_value']['field'] = 'field_passed_review_value';
  $handler->display->display_options['filters']['field_passed_review_value']['relationship'] = 'vid';
  $handler->display->display_options['filters']['field_passed_review_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'admin/workbench/scheduled-content';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Planlagt';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['ulf_workbench_edits_by_user'] = array(
    t('Defaults'),
    t('Udgivne sider'),
    t('vis alle'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('« første'),
    t('‹ forrige'),
    t('næste ›'),
    t('sidste »'),
    t('Shows all content scheduled for publishing or unpublishing'),
    t('Du har intet indhold i denne kategori'),
    t('Hent indholdet fra en indholdsversion.'),
    t('forfatter'),
    t('Forfatter uid'),
    t('Titel'),
    t('Type'),
    t('Overordnet målgruppe'),
    t('Senest opdateret'),
    t('Redigér'),
    t('Alle'),
    t('Søgefilter'),
    t('Søg efter titel eller indholdsleverandør'),
    t('Editor - Awaiting revision (New content)'),
    t('Afventer revision (Ingen publiseret version)'),
    t('mere'),
    t('Viser alt indhold der venter på revision og endnu ikke har en publiseret version'),
    t('Viser @start - @end af @total'),
    t('Nid'),
    t('Afsender'),
    t('Seneste kommentar'),
    t('View panes'),
    t('Editor - Unpublished drafts'),
    t('Upubliserede udkast'),
    t('Viser alle upubliserede udkast'),
    t('Editor - Published content'),
    t('Publiserede forløb'),
    t('Viser alle publiserede kurser og forløb'),
    t('Editor - Awaiting revision (has published)'),
    t('Afventer revision (Har publiseret version)'),
    t('Shows all content awaiting revision that has a published version already'),
    t('Editor - Scheduled publishing'),
    t('Scheduled publishing'),
    t('Udgiv den'),
    t('Afpublicér den'),
    t('Awaiting revision'),
    t('Behandles af redaktionen'),
    t('Viser indhold der afventer redaktionelt review eller indhold du måske skal reagere på før publisering.'),
    t('moderator user'),
    t('Unpublished drafts'),
    t('Ikke udgivet'),
    t('Viser dine upubliserede kladder'),
    t('Published content'),
    t('Udgivet'),
    t('Denne liste viser alt udgivet indhold'),
    t('Scheduled publishing/unpublishing'),
    t('Planlagt til udgivelse'),
  );
  $export['ulf_workbench_edits_by_user'] = $view;

  return $export;
}
