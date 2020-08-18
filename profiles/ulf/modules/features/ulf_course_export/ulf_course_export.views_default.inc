<?php

/**
 * @file
 * ulf_course_export.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ulf_course_export_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course export';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'name' => 'name',
    'field_target_group' => 'field_target_group',
    'field_count' => 'field_count',
    'field_count_description' => 'field_count_description',
    'field_subject' => 'field_subject',
    'field_offer_type' => 'field_offer_type',
    'field_target_group_sub' => 'field_target_group_sub',
    'field_subjects_primary_school' => 'field_subjects_primary_school',
    'field_subjects_youth' => 'field_subjects_youth',
    'field_educational_goals' => 'field_educational_goals',
    'field_free' => 'field_free',
    'field_duration_description' => 'field_duration_description',
    'field_duration' => 'field_duration',
    'field_price' => 'field_price',
    'field_price_description' => 'field_price_description',
    'field_period_full_year' => 'field_period_full_year',
    'field_video' => 'field_video',
    'field_period' => 'field_period',
    'field_period_info' => 'field_period_info',
    'address' => 'address',
    'field_map_placement' => 'field_map_placement',
  );
  $handler->display->display_options['style_options']['class'] = '';
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
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
    'field_target_group' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_count_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_subject' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_offer_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target_group_sub' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_subjects_primary_school' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_subjects_youth' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_educational_goals' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_free' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_duration_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_duration' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_price_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_period_full_year' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_video' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_period' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_period_info' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'address' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_map_placement' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Forbindelse: Indhold: Content author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Felt: Bruger: Navn */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Udbyder';
  /* Felt: Indhold: Overordnet målgruppe */
  $handler->display->display_options['fields']['field_target_group']['id'] = 'field_target_group';
  $handler->display->display_options['fields']['field_target_group']['table'] = 'field_data_field_target_group';
  $handler->display->display_options['fields']['field_target_group']['field'] = 'field_target_group';
  /* Felt: Indhold: Antal */
  $handler->display->display_options['fields']['field_count']['id'] = 'field_count';
  $handler->display->display_options['fields']['field_count']['table'] = 'field_data_field_count';
  $handler->display->display_options['fields']['field_count']['field'] = 'field_count';
  /* Felt: Indhold: Beskrivelse til antal */
  $handler->display->display_options['fields']['field_count_description']['id'] = 'field_count_description';
  $handler->display->display_options['fields']['field_count_description']['table'] = 'field_data_field_count_description';
  $handler->display->display_options['fields']['field_count_description']['field'] = 'field_count_description';
  /* Felt: Indhold: Emneområde */
  $handler->display->display_options['fields']['field_subject']['id'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['table'] = 'field_data_field_subject';
  $handler->display->display_options['fields']['field_subject']['field'] = 'field_subject';
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  /* Felt: Indhold: Forløbstype */
  $handler->display->display_options['fields']['field_offer_type']['id'] = 'field_offer_type';
  $handler->display->display_options['fields']['field_offer_type']['table'] = 'field_data_field_offer_type';
  $handler->display->display_options['fields']['field_offer_type']['field'] = 'field_offer_type';
  $handler->display->display_options['fields']['field_offer_type']['delta_offset'] = '0';
  /* Felt: Indhold: Målgruppe */
  $handler->display->display_options['fields']['field_target_group_sub']['id'] = 'field_target_group_sub';
  $handler->display->display_options['fields']['field_target_group_sub']['table'] = 'field_data_field_target_group_sub';
  $handler->display->display_options['fields']['field_target_group_sub']['field'] = 'field_target_group_sub';
  $handler->display->display_options['fields']['field_target_group_sub']['delta_offset'] = '0';
  /* Felt: Indhold: Fag */
  $handler->display->display_options['fields']['field_subjects_primary_school']['id'] = 'field_subjects_primary_school';
  $handler->display->display_options['fields']['field_subjects_primary_school']['table'] = 'field_data_field_subjects_primary_school';
  $handler->display->display_options['fields']['field_subjects_primary_school']['field'] = 'field_subjects_primary_school';
  $handler->display->display_options['fields']['field_subjects_primary_school']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_subjects_primary_school']['delta_offset'] = '0';
  /* Felt: Indhold: Fag */
  $handler->display->display_options['fields']['field_subjects_youth']['id'] = 'field_subjects_youth';
  $handler->display->display_options['fields']['field_subjects_youth']['table'] = 'field_data_field_subjects_youth';
  $handler->display->display_options['fields']['field_subjects_youth']['field'] = 'field_subjects_youth';
  $handler->display->display_options['fields']['field_subjects_youth']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_subjects_youth']['empty'] = '[field_subjects_primary_school] ';
  $handler->display->display_options['fields']['field_subjects_youth']['delta_offset'] = '0';
  /* Felt: Indhold: Kurset er relevant for pædagoger, der arbejder med læreplanstemaerne */
  $handler->display->display_options['fields']['field_educational_goals']['id'] = 'field_educational_goals';
  $handler->display->display_options['fields']['field_educational_goals']['table'] = 'field_data_field_educational_goals';
  $handler->display->display_options['fields']['field_educational_goals']['field'] = 'field_educational_goals';
  $handler->display->display_options['fields']['field_educational_goals']['label'] = 'Læreplanstemaer/fag';
  $handler->display->display_options['fields']['field_educational_goals']['empty'] = '[field_subjects_youth]';
  $handler->display->display_options['fields']['field_educational_goals']['delta_offset'] = '0';
  /* Felt: Indhold: Gratis */
  $handler->display->display_options['fields']['field_free']['id'] = 'field_free';
  $handler->display->display_options['fields']['field_free']['table'] = 'field_data_field_free';
  $handler->display->display_options['fields']['field_free']['field'] = 'field_free';
  $handler->display->display_options['fields']['field_free']['type'] = 'list_key';
  /* Felt: Indhold: Vælg enhed */
  $handler->display->display_options['fields']['field_duration_unit']['id'] = 'field_duration_unit';
  $handler->display->display_options['fields']['field_duration_unit']['table'] = 'field_data_field_duration_unit';
  $handler->display->display_options['fields']['field_duration_unit']['field'] = 'field_duration_unit';
  $handler->display->display_options['fields']['field_duration_unit']['exclude'] = TRUE;
  /* Felt: Indhold: Varighed */
  $handler->display->display_options['fields']['field_duration']['id'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['table'] = 'field_data_field_duration';
  $handler->display->display_options['fields']['field_duration']['field'] = 'field_duration';
  $handler->display->display_options['fields']['field_duration']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_duration']['alter']['text'] = '[field_duration] [field_duration_unit] ';
  $handler->display->display_options['fields']['field_duration']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 0,
  );
  /* Felt: Indhold: Beskrivelse til varighed */
  $handler->display->display_options['fields']['field_duration_description']['id'] = 'field_duration_description';
  $handler->display->display_options['fields']['field_duration_description']['table'] = 'field_data_field_duration_description';
  $handler->display->display_options['fields']['field_duration_description']['field'] = 'field_duration_description';
  $handler->display->display_options['fields']['field_duration_description']['alter']['text'] = '[field_duration_unit] ';
  /* Felt: Indhold: Pris */
  $handler->display->display_options['fields']['field_collection_price']['id'] = 'field_collection_price';
  $handler->display->display_options['fields']['field_collection_price']['table'] = 'field_data_field_collection_price';
  $handler->display->display_options['fields']['field_collection_price']['field'] = 'field_collection_price';
  $handler->display->display_options['fields']['field_collection_price']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_collection_price']['alter']['text'] = '<?php';
  $handler->display->display_options['fields']['field_collection_price']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_collection_price']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_collection_price']['delta_offset'] = '0';
  /* Felt: Indhold: Beskrivelse til pris */
  $handler->display->display_options['fields']['field_price_description']['id'] = 'field_price_description';
  $handler->display->display_options['fields']['field_price_description']['table'] = 'field_data_field_price_description';
  $handler->display->display_options['fields']['field_price_description']['field'] = 'field_price_description';
  /* Felt: Indhold: Hele året */
  $handler->display->display_options['fields']['field_period_full_year']['id'] = 'field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year']['table'] = 'field_data_field_period_full_year';
  $handler->display->display_options['fields']['field_period_full_year']['field'] = 'field_period_full_year';
  /* Felt: Indhold: Periode */
  $handler->display->display_options['fields']['field_period']['id'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['table'] = 'field_data_field_period';
  $handler->display->display_options['fields']['field_period']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period']['label'] = 'Periode start';
  $handler->display->display_options['fields']['field_period']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Felt: Indhold: Periode */
  $handler->display->display_options['fields']['field_period_1']['id'] = 'field_period_1';
  $handler->display->display_options['fields']['field_period_1']['table'] = 'field_data_field_period';
  $handler->display->display_options['fields']['field_period_1']['field'] = 'field_period';
  $handler->display->display_options['fields']['field_period_1']['label'] = 'Periode slut';
  $handler->display->display_options['fields']['field_period_1']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Felt: Indhold: Yderligere oplysninger til periode */
  $handler->display->display_options['fields']['field_period_info']['id'] = 'field_period_info';
  $handler->display->display_options['fields']['field_period_info']['table'] = 'field_data_field_period_info';
  $handler->display->display_options['fields']['field_period_info']['field'] = 'field_period_info';
  /* Felt: Felt: Video */
  $handler->display->display_options['fields']['field_video']['id'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
  $handler->display->display_options['fields']['field_video']['field'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['label'] = 'Video-URL';
  $handler->display->display_options['fields']['field_video']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_video']['type'] = 'video_embed_field_url';
  $handler->display->display_options['fields']['field_video']['settings'] = array(
    'video_style' => 'normal',
  );
  /* Felt: Indhold: Visning på kort */
  $handler->display->display_options['fields']['field_map_placement']['id'] = 'field_map_placement';
  $handler->display->display_options['fields']['field_map_placement']['table'] = 'field_data_field_map_placement';
  $handler->display->display_options['fields']['field_map_placement']['field'] = 'field_map_placement';
  $handler->display->display_options['fields']['field_map_placement']['label'] = 'Lokation';
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filterkriterie: Indhold: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course' => 'course',
  );

  /* Display: Side */
  $handler = $view->new_display('page', 'Side', 'page_1');
  $handler->display->display_options['path'] = 'admin/settings/custom/course-export';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Course export';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['quote'] = 0;
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/settings/custom/couse-export/csv.csv';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['courses'] = array(
    t('Master'),
    t('Course export'),
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
    t('forfatter'),
    t('Titel'),
    t('Udbyder'),
    t('Overordnet målgruppe'),
    t('Antal'),
    t('Beskrivelse til antal'),
    t('Emneområde'),
    t('Forløbstype'),
    t('Målgruppe'),
    t('Fag'),
    t('[field_subjects_primary_school] '),
    t('Læreplanstemaer/fag'),
    t('[field_subjects_youth]'),
    t('Gratis'),
    t('Vælg enhed'),
    t('Varighed'),
    t('[field_duration] [field_duration_unit] '),
    t('Beskrivelse til varighed'),
    t('[field_duration_unit] '),
    t('Pris'),
    t('<?php'),
    t('Beskrivelse til pris'),
    t('Hele året'),
    t('Periode start'),
    t('Periode slut'),
    t('Yderligere oplysninger til periode'),
    t('Video-URL'),
    t('Lokation'),
    t('Side'),
    t('Data export'),
  );
  $export['courses'] = $view;

  return $export;
}
