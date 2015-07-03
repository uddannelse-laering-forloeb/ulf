<?php
/**
 * @file
 * ulf_practical_information_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ulf_practical_information_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ulf_practical_info';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ulf practical info';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Practical information';
  $handler->display->display_options['css_class'] = 'block-inline-module--content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Antal */
  $handler->display->display_options['fields']['field_count']['id'] = 'field_count';
  $handler->display->display_options['fields']['field_count']['table'] = 'field_data_field_count';
  $handler->display->display_options['fields']['field_count']['field'] = 'field_count';
  $handler->display->display_options['fields']['field_count']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Emneområde */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_subject']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_subject']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_subject']['alter']['path'] = 'search/[field_subject]';
  $handler->display->display_options['fields']['field_subject']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_subject']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_subject']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  /* Field: Content: Evt. yderligere oplysninger til varighed og pris */
  $handler->display->display_options['fields']['field_price_info']['id'] = 'field_price_info';
  $handler->display->display_options['fields']['field_price_info']['table'] = 'field_data_field_price_info';
  $handler->display->display_options['fields']['field_price_info']['field'] = 'field_price_info';
  $handler->display->display_options['fields']['field_price_info']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_price_info']['exclude'] = TRUE;
  /* Field: Content: Hele året */
  $handler->display->display_options['fields']['field_period_full_year']['id'] = 'field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year']['table'] = 'field_data_field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year']['field'] = 'field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year']['label'] = 'excluded - used as class';
  $handler->display->display_options['fields']['field_period_full_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['alter']['text'] = 'is-time-full-year';
  $handler->display->display_options['fields']['field_period_full_year']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['type'] = 'list_key';
  /* Field: Content: Målgruppe */
  $handler->display->display_options['fields']['field_target_group_sub']['id'] = 'field_target_group_sub';
  $handler->display->display_options['fields']['field_target_group_sub']['table'] = 'field_data_field_target_group_sub';
  $handler->display->display_options['fields']['field_target_group_sub']['field'] = 'field_target_group_sub';
  $handler->display->display_options['fields']['field_target_group_sub']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_target_group_sub']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_target_group_sub']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_target_group_sub']['alter']['path'] = 'search/[field_target_group_sub]';
  $handler->display->display_options['fields']['field_target_group_sub']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_target_group_sub']['delta_offset'] = '0';
  /* Field: Content: Gratis */
  $handler->display->display_options['fields']['field_free']['id'] = 'field_free';
  $handler->display->display_options['fields']['field_free']['table'] = 'field_data_field_free';
  $handler->display->display_options['fields']['field_free']['field'] = 'field_free';
  $handler->display->display_options['fields']['field_free']['label'] = 'excluded - class';
  $handler->display->display_options['fields']['field_free']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_free']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free']['alter']['text'] = 'is-price-free';
  $handler->display->display_options['fields']['field_free']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_free']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_free']['type'] = 'list_key';
  /* Field: Content: Pris */
  $handler->display->display_options['fields']['field_collection_price']['id'] = 'field_collection_price';
  $handler->display->display_options['fields']['field_collection_price']['table'] = 'field_data_field_collection_price';
  $handler->display->display_options['fields']['field_collection_price']['field'] = 'field_collection_price';
  $handler->display->display_options['fields']['field_collection_price']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_collection_price']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_collection_price']['alter']['preserve_tags'] = '"<span>"';
  $handler->display->display_options['fields']['field_collection_price']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_collection_price']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_collection_price']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_collection_price']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_collection_price']['separator'] = '';
  $handler->display->display_options['fields']['field_collection_price']['field_api_classes'] = TRUE;
  /* Field: Content: Tilbudstype */
  $handler->display->display_options['fields']['field_offer_type']['id'] = 'field_offer_type';
  $handler->display->display_options['fields']['field_offer_type']['table'] = 'field_data_field_offer_type';
  $handler->display->display_options['fields']['field_offer_type']['field'] = 'field_offer_type';
  $handler->display->display_options['fields']['field_offer_type']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_offer_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_offer_type']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_offer_type']['alter']['path'] = 'search/[field_offer_type]';
  $handler->display->display_options['fields']['field_offer_type']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_offer_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Varighed */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_duration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Vælg enhed */
  $handler->display->display_options['fields']['field_duration_unit']['id'] = 'field_duration_unit';
  $handler->display->display_options['fields']['field_duration_unit']['table'] = 'field_data_field_duration_unit';
  $handler->display->display_options['fields']['field_duration_unit']['field'] = 'field_duration_unit';
  $handler->display->display_options['fields']['field_duration_unit']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_duration_unit']['exclude'] = TRUE;
  /* Field: Content: Tidspunkt */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'field_data_field_period';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['label'] = 'excluded start';
  $handler->display->display_options['fields']['field_period']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period']['alter']['text'] = '[field_period]';
  $handler->display->display_options['fields']['field_period']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_period']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Tidspunkt */
  $handler->display->display_options['fields']['field_period_1']['id'] = 'field_period_1';
  $handler->display->display_options['fields']['field_period_1']['table'] = 'field_data_field_period';
  $handler->display->display_options['fields']['field_period_1']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period_1']['label'] = 'excluded end';
  $handler->display->display_options['fields']['field_period_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_period_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Emneområde</div><div class="block-inline-module--field-text">[field_subject]</div>
<div class="block-inline-module--field-label">Tilbudstype</div><div class="block-inline-module--field-text">[field_offer_type]</div>
</div>
<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Antal deltagere</div><div class="block-inline-module--field-text">[field_count]</div>
<div class="block-inline-module--field-label">Målgruppe</div><div class="block-inline-module--field-text">[field_target_group_sub]</div>
</div>
<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Varighed</div><div class="block-inline-module--field-text">[field_duration] [field_duration_unit]</div>
<div class="block-inline-module--field-label [field_free]">Pris</div><div class="block-inline-module--field-text [field_free]">[field_collection_price]</div>
</div>
<div class="block-inline-module--field-wrapper [field_period_full_year]">
<div class="block-inline-module--field-label">Tidspunkt</div><div class="block-inline-module--field-text">[field_period] til [field_period_1]</div>
</div>
<div class="block-module--field-wrapper">
<div class="block-module--field-label">Yderligere information</div><div class="block-inline-module--field-text">[field_price_info]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Ulf practical information */
  $handler = $view->new_display('panel_pane', 'Ulf practical information', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Ulf practical info education */
  $handler = $view->new_display('panel_pane', 'Ulf practical info education', 'panel_pane_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Emneområde */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_subject']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_subject']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_subject']['alter']['path'] = 'search/[field_subject]';
  $handler->display->display_options['fields']['field_subject']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_subject']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  /* Field: Content: Tidspunkt */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'field_data_field_period';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['label'] = 'excluded start';
  $handler->display->display_options['fields']['field_period']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period']['alter']['text'] = '[field_period]';
  $handler->display->display_options['fields']['field_period']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_period']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Tidspunkt */
  $handler->display->display_options['fields']['field_period_1']['id'] = 'field_period_1';
  $handler->display->display_options['fields']['field_period_1']['table'] = 'field_data_field_period';
  $handler->display->display_options['fields']['field_period_1']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period_1']['label'] = 'excluded end';
  $handler->display->display_options['fields']['field_period_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_period_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Gratis */
  $handler->display->display_options['fields']['field_free_1']['id'] = 'field_free_1';
  $handler->display->display_options['fields']['field_free_1']['table'] = 'field_data_field_free';
  $handler->display->display_options['fields']['field_free_1']['field'] = 'field_free';
  $handler->display->display_options['fields']['field_free_1']['label'] = 'excluded - class';
  $handler->display->display_options['fields']['field_free_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_free_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free_1']['alter']['text'] = 'is-price-free';
  $handler->display->display_options['fields']['field_free_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_free_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_free_1']['type'] = 'list_key';
  /* Field: Field: Pris */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_price']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_price']['alter']['text'] = '[field_price],-';
  $handler->display->display_options['fields']['field_price']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_price']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_course_contact_mail']['id'] = 'field_course_contact_mail';
  $handler->display->display_options['fields']['field_course_contact_mail']['table'] = 'field_data_field_course_contact_mail';
  $handler->display->display_options['fields']['field_course_contact_mail']['field'] = 'field_course_contact_mail';
  $handler->display->display_options['fields']['field_course_contact_mail']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_course_contact_mail']['exclude'] = TRUE;
  /* Field: Content: Hele året */
  $handler->display->display_options['fields']['field_period_full_year']['id'] = 'field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year']['table'] = 'field_data_field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year']['field'] = 'field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year']['label'] = 'excluded - value';
  $handler->display->display_options['fields']['field_period_full_year']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['alter']['text'] = '<li class="block--list-item">Tilgængeligt hele året</li>';
  $handler->display->display_options['fields']['field_period_full_year']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year']['type'] = 'list_key';
  /* Field: Content: Navn */
  $handler->display->display_options['fields']['field_course_contact_name']['id'] = 'field_course_contact_name';
  $handler->display->display_options['fields']['field_course_contact_name']['table'] = 'field_data_field_course_contact_name';
  $handler->display->display_options['fields']['field_course_contact_name']['field'] = 'field_course_contact_name';
  $handler->display->display_options['fields']['field_course_contact_name']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_course_contact_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_contact_name']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Hele året */
  $handler->display->display_options['fields']['field_period_full_year_1']['id'] = 'field_period_full_year_1';
  $handler->display->display_options['fields']['field_period_full_year_1']['table'] = 'field_data_field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year_1']['field'] = 'field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year_1']['label'] = 'excluded - class';
  $handler->display->display_options['fields']['field_period_full_year_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year_1']['alter']['text'] = 'is-time-full-year';
  $handler->display->display_options['fields']['field_period_full_year_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year_1']['type'] = 'list_key';
  /* Field: Content: Gratis */
  $handler->display->display_options['fields']['field_free']['id'] = 'field_free';
  $handler->display->display_options['fields']['field_free']['table'] = 'field_data_field_free';
  $handler->display->display_options['fields']['field_free']['field'] = 'field_free';
  $handler->display->display_options['fields']['field_free']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_free']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_free']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free']['alter']['text'] = '<li class="block--list-item">Gratis</li>';
  $handler->display->display_options['fields']['field_free']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_free']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_free']['type'] = 'list_key';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Emneområde</div><div class="block-inline-module--field-text">[field_subject] </div>
<div class="block-inline-module--field-label [field_free_1]">Pris</div><div class="block-inline-module--field-text [field_free_1]">[field_price]</div>
<div class="block-inline-module--field-label">Navn</div><div class="block-inline-module--field-text">[field_course_contact_name] </div>
<div class="block-inline-module--field-label">E-mail</div><div class="block-inline-module--field-text">[field_course_contact_mail] </div>
</div>
<div class="block-inline-module--field-wrapper [field_period_full_year_1]">
<div class="block-inline-module--field-label">Tidspunkt</div><div class="block-inline-module--field-text">[field_period] til [field_period_1]</div>
</div>
<div class="block-module--field-wrapper">
<ul class="block--list">
[field_period_full_year]
[field_free]
</ul>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $translatables['ulf_practical_info'] = array(
    t('Master'),
    t('Practical information'),
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
    t('excluded'),
    t('excluded - used as class'),
    t('is-time-full-year'),
    t('excluded - class'),
    t('is-price-free'),
    t('excluded start'),
    t('[field_period]'),
    t('excluded end'),
    t('<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Emneområde</div><div class="block-inline-module--field-text">[field_subject]</div>
<div class="block-inline-module--field-label">Tilbudstype</div><div class="block-inline-module--field-text">[field_offer_type]</div>
</div>
<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Antal deltagere</div><div class="block-inline-module--field-text">[field_count]</div>
<div class="block-inline-module--field-label">Målgruppe</div><div class="block-inline-module--field-text">[field_target_group_sub]</div>
</div>
<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Varighed</div><div class="block-inline-module--field-text">[field_duration] [field_duration_unit]</div>
<div class="block-inline-module--field-label [field_free]">Pris</div><div class="block-inline-module--field-text [field_free]">[field_collection_price]</div>
</div>
<div class="block-inline-module--field-wrapper [field_period_full_year]">
<div class="block-inline-module--field-label">Tidspunkt</div><div class="block-inline-module--field-text">[field_period] til [field_period_1]</div>
</div>
<div class="block-module--field-wrapper">
<div class="block-module--field-label">Yderligere information</div><div class="block-inline-module--field-text">[field_price_info]</div>
</div>'),
    t('All'),
    t('Ulf practical information'),
    t('View panes'),
    t('Ulf practical info education'),
    t('[field_price],-'),
    t('excluded - value'),
    t('<li class="block--list-item">Tilgængeligt hele året</li>'),
    t('<li class="block--list-item">Gratis</li>'),
    t('<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Emneområde</div><div class="block-inline-module--field-text">[field_subject] </div>
<div class="block-inline-module--field-label [field_free_1]">Pris</div><div class="block-inline-module--field-text [field_free_1]">[field_price]</div>
<div class="block-inline-module--field-label">Navn</div><div class="block-inline-module--field-text">[field_course_contact_name] </div>
<div class="block-inline-module--field-label">E-mail</div><div class="block-inline-module--field-text">[field_course_contact_mail] </div>
</div>
<div class="block-inline-module--field-wrapper [field_period_full_year_1]">
<div class="block-inline-module--field-label">Tidspunkt</div><div class="block-inline-module--field-text">[field_period] til [field_period_1]</div>
</div>
<div class="block-module--field-wrapper">
<ul class="block--list">
[field_period_full_year]
[field_free]
</ul>
</div>'),
  );
  $export['ulf_practical_info'] = $view;

  return $export;
}
