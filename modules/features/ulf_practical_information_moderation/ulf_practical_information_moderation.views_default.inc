<?php
/**
 * @file
 * ulf_practical_information_moderation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ulf_practical_information_moderation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ulf_practical_info_moderation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Ulf practical info moderation';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Practical information';
  $handler->display->display_options['css_class'] = 'block-inline-module--content';
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
  /* Forbindelse: Indholdsversion: Indhold */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  /* Felt: Indhold (historiske data): Antal */
  $handler->display->display_options['fields']['field_count-revision_id']['id'] = 'field_count-revision_id';
  $handler->display->display_options['fields']['field_count-revision_id']['table'] = 'field_revision_field_count';
  $handler->display->display_options['fields']['field_count-revision_id']['field'] = 'field_count-revision_id';
  $handler->display->display_options['fields']['field_count-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_count-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_count-revision_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Indhold (historiske data): Evt. yderligere oplysninger til varighed og pris */
  $handler->display->display_options['fields']['field_price_info-revision_id']['id'] = 'field_price_info-revision_id';
  $handler->display->display_options['fields']['field_price_info-revision_id']['table'] = 'field_revision_field_price_info';
  $handler->display->display_options['fields']['field_price_info-revision_id']['field'] = 'field_price_info-revision_id';
  $handler->display->display_options['fields']['field_price_info-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_price_info-revision_id']['exclude'] = TRUE;
  /* Felt: Indhold (historiske data): Målgruppe */
  $handler->display->display_options['fields']['field_target_group_sub-revision_id']['id'] = 'field_target_group_sub-revision_id';
  $handler->display->display_options['fields']['field_target_group_sub-revision_id']['table'] = 'field_revision_field_target_group_sub';
  $handler->display->display_options['fields']['field_target_group_sub-revision_id']['field'] = 'field_target_group_sub-revision_id';
  $handler->display->display_options['fields']['field_target_group_sub-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_target_group_sub-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_target_group_sub-revision_id']['delta_offset'] = '0';
  /* Felt: Indhold (historiske data): Gratis */
  $handler->display->display_options['fields']['field_free-revision_id']['id'] = 'field_free-revision_id';
  $handler->display->display_options['fields']['field_free-revision_id']['table'] = 'field_revision_field_free';
  $handler->display->display_options['fields']['field_free-revision_id']['field'] = 'field_free-revision_id';
  $handler->display->display_options['fields']['field_free-revision_id']['label'] = 'excluded - class';
  $handler->display->display_options['fields']['field_free-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id']['alter']['text'] = 'is-price-free';
  $handler->display->display_options['fields']['field_free-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id']['type'] = 'list_key';
  /* Felt: Indhold (historiske data): Pris */
  $handler->display->display_options['fields']['field_collection_price-revision_id']['id'] = 'field_collection_price-revision_id';
  $handler->display->display_options['fields']['field_collection_price-revision_id']['table'] = 'field_revision_field_collection_price';
  $handler->display->display_options['fields']['field_collection_price-revision_id']['field'] = 'field_collection_price-revision_id';
  $handler->display->display_options['fields']['field_collection_price-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_collection_price-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_collection_price-revision_id']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_collection_price-revision_id']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_collection_price-revision_id']['delta_offset'] = '0';
  /* Felt: Indhold (historiske data): Tidspunkt */
  $handler->display->display_options['fields']['field_period-revision_id']['id'] = 'field_period-revision_id';
  $handler->display->display_options['fields']['field_period-revision_id']['table'] = 'field_revision_field_period';
  $handler->display->display_options['fields']['field_period-revision_id']['field'] = 'field_period-revision_id';
  $handler->display->display_options['fields']['field_period-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_period-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period-revision_id']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Felt: Indhold (historiske data): Tilbudstype */
  $handler->display->display_options['fields']['field_offer_type-revision_id']['id'] = 'field_offer_type-revision_id';
  $handler->display->display_options['fields']['field_offer_type-revision_id']['table'] = 'field_revision_field_offer_type';
  $handler->display->display_options['fields']['field_offer_type-revision_id']['field'] = 'field_offer_type-revision_id';
  $handler->display->display_options['fields']['field_offer_type-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_offer_type-revision_id']['exclude'] = TRUE;
  /* Felt: Indhold (historiske data): Varighed */
  $handler->display->display_options['fields']['field_duration-revision_id']['id'] = 'field_duration-revision_id';
  $handler->display->display_options['fields']['field_duration-revision_id']['table'] = 'field_revision_field_duration';
  $handler->display->display_options['fields']['field_duration-revision_id']['field'] = 'field_duration-revision_id';
  $handler->display->display_options['fields']['field_duration-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_duration-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_duration-revision_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Felt: Indhold (historiske data): Vælg enhed */
  $handler->display->display_options['fields']['field_duration_unit-revision_id']['id'] = 'field_duration_unit-revision_id';
  $handler->display->display_options['fields']['field_duration_unit-revision_id']['table'] = 'field_revision_field_duration_unit';
  $handler->display->display_options['fields']['field_duration_unit-revision_id']['field'] = 'field_duration_unit-revision_id';
  $handler->display->display_options['fields']['field_duration_unit-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_duration_unit-revision_id']['exclude'] = TRUE;
  /* Felt: Indhold (historiske data): Emneområde */
  $handler->display->display_options['fields']['field_subject-revision_id']['id'] = 'field_subject-revision_id';
  $handler->display->display_options['fields']['field_subject-revision_id']['table'] = 'field_revision_field_subject';
  $handler->display->display_options['fields']['field_subject-revision_id']['field'] = 'field_subject-revision_id';
  $handler->display->display_options['fields']['field_subject-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_subject-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_subject-revision_id']['delta_offset'] = '0';
  /* Felt: Indhold (historiske data): Tidspunkt */
  $handler->display->display_options['fields']['field_period-revision_id_1']['id'] = 'field_period-revision_id_1';
  $handler->display->display_options['fields']['field_period-revision_id_1']['table'] = 'field_revision_field_period';
  $handler->display->display_options['fields']['field_period-revision_id_1']['field'] = 'field_period-revision_id';
  $handler->display->display_options['fields']['field_period-revision_id_1']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_period-revision_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period-revision_id_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Felt: Indhold (historiske data): Hele året */
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['id'] = 'field_period_full_year-revision_id';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['table'] = 'field_revision_field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['field'] = 'field_period_full_year-revision_id';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['label'] = 'excluded - class';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['alter']['text'] = 'is-time-full-year';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['type'] = 'list_key';
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Emneområde</div><div class="block-inline-module--field-text">[field_subject-revision_id]</div>
<div class="block-inline-module--field-label">Tilbudstype</div><div class="block-inline-module--field-text">[field_offer_type-revision_id]</div>
</div>
<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Antal deltagere</div><div class="block-inline-module--field-text">[field_count-revision_id]</div>
<div class="block-inline-module--field-label">Målgruppe</div><div class="block-inline-module--field-text">[field_target_group_sub-revision_id]</div>
</div>
<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Varighed</div><div class="block-inline-module--field-text">[field_duration-revision_id] [field_duration_unit-revision_id]</div>
<div class="block-inline-module--field-label [field_free-revision_id]">Pris</div><div class="block-inline-module--field-text [field_free-revision_id]">[field_collection_price-revision_id]</div>
</div>
<div class="block-inline-module--field-wrapper [field_period_full_year-revision_id]">
<div class="block-inline-module--field-label">Tidspunkt</div><div class="block-inline-module--field-text">[field_period-revision_id] til [field_period-revision_id_1]</div>
</div>
<div class="block-module--field-wrapper">
<div class="block-module--field-label">Yderligere information</div><div class="block-module--field-text">[field_price_info-revision_id]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Kontekstuelt filter: Indholdsversion: Vid */
  $handler->display->display_options['arguments']['vid']['id'] = 'vid';
  $handler->display->display_options['arguments']['vid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['vid']['field'] = 'vid';
  $handler->display->display_options['arguments']['vid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['vid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['vid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['vid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vid']['summary_options']['items_per_page'] = '25';

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

  /* Display: Ulf practical info educators */
  $handler = $view->new_display('panel_pane', 'Ulf practical info educators', 'panel_pane_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold (historiske data): Emneområde */
  $handler->display->display_options['fields']['field_subject-revision_id']['id'] = 'field_subject-revision_id';
  $handler->display->display_options['fields']['field_subject-revision_id']['table'] = 'field_revision_field_subject';
  $handler->display->display_options['fields']['field_subject-revision_id']['field'] = 'field_subject-revision_id';
  $handler->display->display_options['fields']['field_subject-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_subject-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_subject-revision_id']['delta_offset'] = '0';
  /* Felt: Indhold (historiske data): Gratis */
  $handler->display->display_options['fields']['field_free-revision_id_2']['id'] = 'field_free-revision_id_2';
  $handler->display->display_options['fields']['field_free-revision_id_2']['table'] = 'field_revision_field_free';
  $handler->display->display_options['fields']['field_free-revision_id_2']['field'] = 'field_free-revision_id';
  $handler->display->display_options['fields']['field_free-revision_id_2']['label'] = 'excluded -class';
  $handler->display->display_options['fields']['field_free-revision_id_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id_2']['alter']['text'] = 'is-price-free';
  $handler->display->display_options['fields']['field_free-revision_id_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id_2']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id_2']['type'] = 'list_key';
  /* Felt: Felt (historiske data): Pris */
  $handler->display->display_options['fields']['field_price-revision_id']['id'] = 'field_price-revision_id';
  $handler->display->display_options['fields']['field_price-revision_id']['table'] = 'field_revision_field_price';
  $handler->display->display_options['fields']['field_price-revision_id']['field'] = 'field_price-revision_id';
  $handler->display->display_options['fields']['field_price-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_price-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_price-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_price-revision_id']['alter']['text'] = '[field_price-revision_id],-';
  $handler->display->display_options['fields']['field_price-revision_id']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 0,
  );
  /* Felt: Indhold (historiske data): Navn */
  $handler->display->display_options['fields']['field_course_contact_name-revision_id']['id'] = 'field_course_contact_name-revision_id';
  $handler->display->display_options['fields']['field_course_contact_name-revision_id']['table'] = 'field_revision_field_course_contact_name';
  $handler->display->display_options['fields']['field_course_contact_name-revision_id']['field'] = 'field_course_contact_name-revision_id';
  $handler->display->display_options['fields']['field_course_contact_name-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_course_contact_name-revision_id']['exclude'] = TRUE;
  /* Felt: Indhold (historiske data): Email */
  $handler->display->display_options['fields']['field_course_contact_mail-revision_id']['id'] = 'field_course_contact_mail-revision_id';
  $handler->display->display_options['fields']['field_course_contact_mail-revision_id']['table'] = 'field_revision_field_course_contact_mail';
  $handler->display->display_options['fields']['field_course_contact_mail-revision_id']['field'] = 'field_course_contact_mail-revision_id';
  $handler->display->display_options['fields']['field_course_contact_mail-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_course_contact_mail-revision_id']['exclude'] = TRUE;
  /* Felt: Indhold (historiske data): Hele året */
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['id'] = 'field_period_full_year-revision_id';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['table'] = 'field_revision_field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['field'] = 'field_period_full_year-revision_id';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['label'] = 'excluded - class';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['alter']['text'] = 'is-time-full-year';
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id']['type'] = 'list_key';
  /* Felt: Indhold (historiske data): Tidspunkt */
  $handler->display->display_options['fields']['field_period-revision_id']['id'] = 'field_period-revision_id';
  $handler->display->display_options['fields']['field_period-revision_id']['table'] = 'field_revision_field_period';
  $handler->display->display_options['fields']['field_period-revision_id']['field'] = 'field_period-revision_id';
  $handler->display->display_options['fields']['field_period-revision_id']['label'] = 'excluded start';
  $handler->display->display_options['fields']['field_period-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period-revision_id']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Felt: Indhold (historiske data): Tidspunkt */
  $handler->display->display_options['fields']['field_period-revision_id_1']['id'] = 'field_period-revision_id_1';
  $handler->display->display_options['fields']['field_period-revision_id_1']['table'] = 'field_revision_field_period';
  $handler->display->display_options['fields']['field_period-revision_id_1']['field'] = 'field_period-revision_id';
  $handler->display->display_options['fields']['field_period-revision_id_1']['label'] = 'excluded end';
  $handler->display->display_options['fields']['field_period-revision_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period-revision_id_1']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Felt: Indhold (historiske data): Gratis */
  $handler->display->display_options['fields']['field_free-revision_id']['id'] = 'field_free-revision_id';
  $handler->display->display_options['fields']['field_free-revision_id']['table'] = 'field_revision_field_free';
  $handler->display->display_options['fields']['field_free-revision_id']['field'] = 'field_free-revision_id';
  $handler->display->display_options['fields']['field_free-revision_id']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_free-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id']['alter']['text'] = '<li class="block--list-item">Gratis</li>';
  $handler->display->display_options['fields']['field_free-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_free-revision_id']['type'] = 'list_key';
  /* Felt: Indhold (historiske data): Hele året */
  $handler->display->display_options['fields']['field_period_full_year-revision_id_1']['id'] = 'field_period_full_year-revision_id_1';
  $handler->display->display_options['fields']['field_period_full_year-revision_id_1']['table'] = 'field_revision_field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year-revision_id_1']['field'] = 'field_period_full_year-revision_id';
  $handler->display->display_options['fields']['field_period_full_year-revision_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id_1']['alter']['text'] = '<li class="block--list-item">Tilgængeligt hele året</li>';
  $handler->display->display_options['fields']['field_period_full_year-revision_id_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_period_full_year-revision_id_1']['type'] = 'list_key';
  /* Felt: Global: Tilpasset tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Emneområde</div><div class="block-inline-module--field-text">[field_subject-revision_id]</div>
</div>
<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label [field_free-revision_id_2]">Pris</div><div class="block-inline-module--field-text [field_free-revision_id_2]">[field_price-revision_id]</div>
<div class="block-inline-module--field-label">Navn</div><div class="block-inline-module--field-text">[field_course_contact_name-revision_id] </div>
<div class="block-inline-module--field-label">E-mail</div><div class="block-inline-module--field-text">[field_course_contact_mail-revision_id] </div>
</div>
<div class="block-inline-module--field-wrapper [field_period_full_year-revision_id]">
<div class="block-inline-module--field-label">Tidspunkt</div><div class="block-inline-module--field-text">[field_period-revision_id] til [field_period-revision_id_1]</div>
</div>
<div class="block-module--field-wrapper">
<ul class="block--list">
[field_period_full_year-revision_id_1]
[field_free-revision_id]
</ul>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  $translatables['ulf_practical_info_moderation'] = array(
    t('Master'),
    t('Practical information'),
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
    t('Hent indholdet fra en indholdsversion.'),
    t('excluded'),
    t('excluded - class'),
    t('is-price-free'),
    t('is-time-full-year'),
    t('<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Emneområde</div><div class="block-inline-module--field-text">[field_subject-revision_id]</div>
<div class="block-inline-module--field-label">Tilbudstype</div><div class="block-inline-module--field-text">[field_offer_type-revision_id]</div>
</div>
<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Antal deltagere</div><div class="block-inline-module--field-text">[field_count-revision_id]</div>
<div class="block-inline-module--field-label">Målgruppe</div><div class="block-inline-module--field-text">[field_target_group_sub-revision_id]</div>
</div>
<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Varighed</div><div class="block-inline-module--field-text">[field_duration-revision_id] [field_duration_unit-revision_id]</div>
<div class="block-inline-module--field-label [field_free-revision_id]">Pris</div><div class="block-inline-module--field-text [field_free-revision_id]">[field_collection_price-revision_id]</div>
</div>
<div class="block-inline-module--field-wrapper [field_period_full_year-revision_id]">
<div class="block-inline-module--field-label">Tidspunkt</div><div class="block-inline-module--field-text">[field_period-revision_id] til [field_period-revision_id_1]</div>
</div>
<div class="block-module--field-wrapper">
<div class="block-module--field-label">Yderligere information</div><div class="block-module--field-text">[field_price_info-revision_id]</div>
</div>'),
    t('Alle'),
    t('Ulf practical information'),
    t('View panes'),
    t('Ulf practical info educators'),
    t('excluded -class'),
    t('[field_price-revision_id],-'),
    t('excluded start'),
    t('excluded end'),
    t('<li class="block--list-item">Gratis</li>'),
    t('Hele året'),
    t('<li class="block--list-item">Tilgængeligt hele året</li>'),
    t('<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label">Emneområde</div><div class="block-inline-module--field-text">[field_subject-revision_id]</div>
</div>
<div class="block-inline-module--field-wrapper">
<div class="block-inline-module--field-label [field_free-revision_id_2]">Pris</div><div class="block-inline-module--field-text [field_free-revision_id_2]">[field_price-revision_id]</div>
<div class="block-inline-module--field-label">Navn</div><div class="block-inline-module--field-text">[field_course_contact_name-revision_id] </div>
<div class="block-inline-module--field-label">E-mail</div><div class="block-inline-module--field-text">[field_course_contact_mail-revision_id] </div>
</div>
<div class="block-inline-module--field-wrapper [field_period_full_year-revision_id]">
<div class="block-inline-module--field-label">Tidspunkt</div><div class="block-inline-module--field-text">[field_period-revision_id] til [field_period-revision_id_1]</div>
</div>
<div class="block-module--field-wrapper">
<ul class="block--list">
[field_period_full_year-revision_id_1]
[field_free-revision_id]
</ul>
</div>'),
  );
  $export['ulf_practical_info_moderation'] = $view;

  return $export;
}
