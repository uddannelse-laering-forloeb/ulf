<?php
/**
 * @file
 * ulf_course.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ulf_course_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ulf_node_contact';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ulf Node Contact';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Forbindelse: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Felt: User: Navn */
  $handler->display->display_options['fields']['field_profile_name']['id'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['table'] = 'field_data_field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['field'] = 'field_profile_name';
  $handler->display->display_options['fields']['field_profile_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_profile_name']['label'] = '';
  $handler->display->display_options['fields']['field_profile_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name']['element_label_colon'] = FALSE;
  /* Felt: User: Address */
  $handler->display->display_options['fields']['field_profile_address']['id'] = 'field_profile_address';
  $handler->display->display_options['fields']['field_profile_address']['table'] = 'field_data_field_profile_address';
  $handler->display->display_options['fields']['field_profile_address']['field'] = 'field_profile_address';
  $handler->display->display_options['fields']['field_profile_address']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_profile_address']['label'] = 'Adresse';
  $handler->display->display_options['fields']['field_profile_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_address']['element_label_colon'] = FALSE;
  /* Felt: User: Postnr. */
  $handler->display->display_options['fields']['field_profile_postal_code']['id'] = 'field_profile_postal_code';
  $handler->display->display_options['fields']['field_profile_postal_code']['table'] = 'field_data_field_profile_postal_code';
  $handler->display->display_options['fields']['field_profile_postal_code']['field'] = 'field_profile_postal_code';
  $handler->display->display_options['fields']['field_profile_postal_code']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_profile_postal_code']['label'] = '';
  $handler->display->display_options['fields']['field_profile_postal_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_postal_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_postal_code']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Felt: User: By */
  $handler->display->display_options['fields']['field_profile_city']['id'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['table'] = 'field_data_field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['field'] = 'field_profile_city';
  $handler->display->display_options['fields']['field_profile_city']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_profile_city']['label'] = '';
  $handler->display->display_options['fields']['field_profile_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_city']['element_label_colon'] = FALSE;
  /* Felt: User: Hjemmeside */
  $handler->display->display_options['fields']['field_profile_home_page']['id'] = 'field_profile_home_page';
  $handler->display->display_options['fields']['field_profile_home_page']['table'] = 'field_data_field_profile_home_page';
  $handler->display->display_options['fields']['field_profile_home_page']['field'] = 'field_profile_home_page';
  $handler->display->display_options['fields']['field_profile_home_page']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_profile_home_page']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_home_page']['click_sort_column'] = 'url';
  /* Felt: User: Telefonnr. */
  $handler->display->display_options['fields']['field_profile_phone']['id'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['table'] = 'field_data_field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['field'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_profile_phone']['label'] = 'Telefon';
  $handler->display->display_options['fields']['field_profile_phone']['exclude'] = TRUE;
  /* Felt: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Felt: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="block-module--content">
  <h3><a href="/user/[uid]">[field_profile_name]</a></h3>
  <div class="block-module--field-wrapper">
    <div class="block-module--field-label">Adresse</div>
    <div class="block-module--field-text--no-space">[field_profile_address]</div> 
    <div class="block-module--field-text">[field_profile_postal_code] [field_profile_city]</div>
  </div>
  <div class="block-module--field-wrapper">
    <div class="block-module--field-label">Kontaktinformation</div>
    <div class="block-module--field-text--no-space">Telefon: [field_profile_phone]</div> 
    <div class="block-module--field-text">Hjemmeside: [field_profile_home_page]</div>
  </div>
</div>
';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sorteringskriterie: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontekstuelt filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filterkriterie: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $export['ulf_node_contact'] = $view;

  $view = new view();
  $view->name = 'ulf_useful_info';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ulf useful info';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nyttigt';
  $handler->display->display_options['css_class'] = 'block-inline-module--content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'block--list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_facilities' => 'field_facilities',
    'field_free' => 'field_free',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Felt: Content: Hvilke faciliteter kan I tilbyde? */
  $handler->display->display_options['fields']['field_facilities']['id'] = 'field_facilities';
  $handler->display->display_options['fields']['field_facilities']['table'] = 'field_data_field_facilities';
  $handler->display->display_options['fields']['field_facilities']['field'] = 'field_facilities';
  $handler->display->display_options['fields']['field_facilities']['label'] = '';
  $handler->display->display_options['fields']['field_facilities']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_facilities']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_facilities']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_facilities']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_facilities']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_facilities']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_facilities']['field_api_classes'] = TRUE;
  /* Felt: Content: Gratis */
  $handler->display->display_options['fields']['field_free']['id'] = 'field_free';
  $handler->display->display_options['fields']['field_free']['table'] = 'field_data_field_free';
  $handler->display->display_options['fields']['field_free']['field'] = 'field_free';
  $handler->display->display_options['fields']['field_free']['label'] = '';
  $handler->display->display_options['fields']['field_free']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free']['alter']['text'] = '<li class="block--list-item">Gratis</li>';
  $handler->display->display_options['fields']['field_free']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_free']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_free']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_free']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_free']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_free']['type'] = 'list_key';
  /* Felt: Content: Hele året */
  $handler->display->display_options['fields']['field_period_full_year']['id'] = 'field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year']['table'] = 'field_data_field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year']['field'] = 'field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year']['label'] = '';
  $handler->display->display_options['fields']['field_period_full_year']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['alter']['text'] = '<li class="block--list-item">Tilgængeligt hele året</li>';
  $handler->display->display_options['fields']['field_period_full_year']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_period_full_year']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_period_full_year']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['type'] = 'list_key';
  /* Sorteringskriterie: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontekstuelt filter: Content revision: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filterkriterie: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Ulf useful information */
  $handler = $view->new_display('panel_pane', 'Ulf useful information', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'vid' => array(
      'type' => 'user',
      'context' => 'entity:node.vid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content revision: Vid',
    ),
  );
  $export['ulf_useful_info'] = $view;

  $view = new view();
  $view->name = 'ulf_useful_info_moderation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Ulf useful info moderation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nyttigt';
  $handler->display->display_options['css_class'] = 'block-inline-module--content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view revisions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Udfør';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'block--list';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Forbindelse: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  /* Felt: Content (historical data): Hvilke faciliteter kan I tilbyde? */
  $handler->display->display_options['fields']['field_facilities-revision_id']['id'] = 'field_facilities-revision_id';
  $handler->display->display_options['fields']['field_facilities-revision_id']['table'] = 'field_revision_field_facilities';
  $handler->display->display_options['fields']['field_facilities-revision_id']['field'] = 'field_facilities-revision_id';
  $handler->display->display_options['fields']['field_facilities-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_facilities-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_facilities-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_facilities-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_facilities-revision_id']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_facilities-revision_id']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_facilities-revision_id']['field_api_classes'] = TRUE;
  /* Felt: Content (historical data): Gratis */
  $handler->display->display_options['fields']['field_free-revision_id']['id'] = 'field_free-revision_id';
  $handler->display->display_options['fields']['field_free-revision_id']['table'] = 'field_revision_field_free';
  $handler->display->display_options['fields']['field_free-revision_id']['field'] = 'field_free-revision_id';
  $handler->display->display_options['fields']['field_free-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_free-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id']['alter']['text'] = '<li class="block--list-item">Gratis</li>';
  $handler->display->display_options['fields']['field_free-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_free-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_free-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id']['type'] = 'list_key';
  /* Felt: Content (historical data): Hele året */
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['id'] = 'field_period_full_year-revision_id';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['table'] = 'field_revision_field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['field'] = 'field_period_full_year-revision_id';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['alter']['text'] = '<li class="block--list-item">Hele året</li>';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['type'] = 'list_key';
  /* Kontekstuelt filter: Content revision: Vid */
  $handler->display->display_options['arguments']['vid']['id'] = 'vid';
  $handler->display->display_options['arguments']['vid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['vid']['field'] = 'vid';
  $handler->display->display_options['arguments']['vid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['vid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['vid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['vid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vid']['summary_options']['items_per_page'] = '25';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'vid' => array(
      'type' => 'user',
      'context' => 'entity:field_collection_item.field-unit-price',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content revision: Vid',
    ),
  );
  $export['ulf_useful_info_moderation'] = $view;

  return $export;
}
