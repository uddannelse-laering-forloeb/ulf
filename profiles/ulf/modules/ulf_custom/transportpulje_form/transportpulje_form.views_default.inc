<?php
/**
 * @file
 * transportpulje_form.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function transportpulje_form_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'tpf_requests';
  $view->description = 'Ansøgninger i transportpuljen';
  $view->tag = 'default';
  $view->base_table = 'entityform';
  $view->human_name = 'Transportpulje ansøgninger';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Transportpulje ansøgninger';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer tpf';
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« første';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ forrige';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'næste ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'sidste »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_tpf_address_variation' => 'field_tpf_address_variation',
    'field_tpf_purpose_course' => 'field_tpf_purpose_course',
    'field_tpf_what_course' => 'field_tpf_what_course',
    'views_bulk_operations' => 'views_bulk_operations',
    'entityform_id_1' => 'entityform_id_1',
    'created' => 'created',
    'field_tpf_address' => 'field_tpf_address',
    'field_tpf_grade' => 'field_tpf_grade',
    'field_tpf_institution' => 'field_tpf_institution',
    'field_tpf_expense' => 'field_tpf_expense',
    'field_tpf_date' => 'field_tpf_date',
    'field_tpf_name' => 'field_tpf_name',
    'field_tpf_email' => 'field_tpf_email',
    'field_tpf_message' => 'field_tpf_message',
    'field_tpf_status' => 'field_tpf_status',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'field_tpf_address_variation' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tpf_purpose_course' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tpf_what_course' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entityform_id_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tpf_address' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tpf_grade' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tpf_institution' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tpf_expense' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tpf_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tpf_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tpf_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tpf_message' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tpf_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = 'Notice: Addresses marked (*) are submissions wth an address differing from the course selected in the dropdown. Submissions with a course not selected are not considered to be differing.';
  $handler->display->display_options['footer']['area']['format'] = 'editor';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Ingen ansøgninger på nuværende tidspunkt';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_tpf_course_select_target_id']['id'] = 'field_tpf_course_select_target_id';
  $handler->display->display_options['relationships']['field_tpf_course_select_target_id']['table'] = 'field_data_field_tpf_course_select';
  $handler->display->display_options['relationships']['field_tpf_course_select_target_id']['field'] = 'field_tpf_course_select_target_id';
  /* Field: Entityform Submission: Vælg forløb */
  $handler->display->display_options['fields']['field_tpf_course_select']['id'] = 'field_tpf_course_select';
  $handler->display->display_options['fields']['field_tpf_course_select']['table'] = 'field_data_field_tpf_course_select';
  $handler->display->display_options['fields']['field_tpf_course_select']['field'] = 'field_tpf_course_select';
  $handler->display->display_options['fields']['field_tpf_course_select']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_course_select']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  /* Field: Entityform Submission: Adresse varierer fra indhold */
  $handler->display->display_options['fields']['field_tpf_address_variation']['id'] = 'field_tpf_address_variation';
  $handler->display->display_options['fields']['field_tpf_address_variation']['table'] = 'field_data_field_tpf_address_variation';
  $handler->display->display_options['fields']['field_tpf_address_variation']['field'] = 'field_tpf_address_variation';
  $handler->display->display_options['fields']['field_tpf_address_variation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_address_variation']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_address_variation']['alter']['text'] = '(*)';
  $handler->display->display_options['fields']['field_tpf_address_variation']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_address_variation']['type'] = 'list_key';
  /* Field: Entityform Submission: Beskriv læringsfomålet */
  $handler->display->display_options['fields']['field_tpf_purpose_course']['id'] = 'field_tpf_purpose_course';
  $handler->display->display_options['fields']['field_tpf_purpose_course']['table'] = 'field_data_field_tpf_purpose_course';
  $handler->display->display_options['fields']['field_tpf_purpose_course']['field'] = 'field_tpf_purpose_course';
  $handler->display->display_options['fields']['field_tpf_purpose_course']['exclude'] = TRUE;
  /* Field: Entityform Submission: Hvad er forløbet */
  $handler->display->display_options['fields']['field_tpf_what_course']['id'] = 'field_tpf_what_course';
  $handler->display->display_options['fields']['field_tpf_what_course']['table'] = 'field_data_field_tpf_what_course';
  $handler->display->display_options['fields']['field_tpf_what_course']['field'] = 'field_tpf_what_course';
  $handler->display->display_options['fields']['field_tpf_what_course']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_what_course']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_what_course']['alter']['text'] = '<br>(individuel beskr. og formål)';
  /* Field: Bulk operations: Entityform Submission */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_entityform';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::_tpf_accept' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::_tpf_change_status_accepted' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::_tpf_change_status_refused' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::_tpf_refuse' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Entityform Submission: Entityform submission ID */
  $handler->display->display_options['fields']['entityform_id_1']['id'] = 'entityform_id_1';
  $handler->display->display_options['fields']['entityform_id_1']['table'] = 'entityform';
  $handler->display->display_options['fields']['entityform_id_1']['field'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id_1']['label'] = 'ID';
  $handler->display->display_options['fields']['entityform_id_1']['separator'] = '';
  /* Field: Entityform Submission: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Dato for indsendelse';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
  /* Field: Entityform Submission: Udfyldt i backend */
  $handler->display->display_options['fields']['field_tpf_backend_submission']['id'] = 'field_tpf_backend_submission';
  $handler->display->display_options['fields']['field_tpf_backend_submission']['table'] = 'field_data_field_tpf_backend_submission';
  $handler->display->display_options['fields']['field_tpf_backend_submission']['field'] = 'field_tpf_backend_submission';
  $handler->display->display_options['fields']['field_tpf_backend_submission']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_backend_submission']['alter']['text'] = 'Udfyldt i backend';
  $handler->display->display_options['fields']['field_tpf_backend_submission']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_backend_submission']['type'] = 'list_key';
  /* Field: Entityform Submission: Indtast adresse */
  $handler->display->display_options['fields']['field_tpf_address']['id'] = 'field_tpf_address';
  $handler->display->display_options['fields']['field_tpf_address']['table'] = 'field_data_field_tpf_address';
  $handler->display->display_options['fields']['field_tpf_address']['field'] = 'field_tpf_address';
  $handler->display->display_options['fields']['field_tpf_address']['label'] = 'Forløb/Adresse';
  $handler->display->display_options['fields']['field_tpf_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_address']['alter']['text'] = '[field_tpf_course_select]<br>
[field_tpf_address] [field_tpf_address_variation]';
  /* Field: Entityform Submission: Vælg trin */
  $handler->display->display_options['fields']['field_tpf_grade']['id'] = 'field_tpf_grade';
  $handler->display->display_options['fields']['field_tpf_grade']['table'] = 'field_data_field_tpf_grade';
  $handler->display->display_options['fields']['field_tpf_grade']['field'] = 'field_tpf_grade';
  $handler->display->display_options['fields']['field_tpf_grade']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_grade']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_grade']['alter']['text'] = ', [field_tpf_grade]';
  /* Field: Entityform Submission: Institution */
  $handler->display->display_options['fields']['field_tpf_institution']['id'] = 'field_tpf_institution';
  $handler->display->display_options['fields']['field_tpf_institution']['table'] = 'field_data_field_tpf_institution';
  $handler->display->display_options['fields']['field_tpf_institution']['field'] = 'field_tpf_institution';
  $handler->display->display_options['fields']['field_tpf_institution']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_institution']['alter']['text'] = '[field_tpf_institution][field_tpf_grade]';
  $handler->display->display_options['fields']['field_tpf_institution']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Entityform Submission: Udgift */
  $handler->display->display_options['fields']['field_tpf_expense']['id'] = 'field_tpf_expense';
  $handler->display->display_options['fields']['field_tpf_expense']['table'] = 'field_data_field_tpf_expense';
  $handler->display->display_options['fields']['field_tpf_expense']['field'] = 'field_tpf_expense';
  $handler->display->display_options['fields']['field_tpf_expense']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Entityform Submission: Dato */
  $handler->display->display_options['fields']['field_tpf_date']['id'] = 'field_tpf_date';
  $handler->display->display_options['fields']['field_tpf_date']['table'] = 'field_data_field_tpf_date';
  $handler->display->display_options['fields']['field_tpf_date']['field'] = 'field_tpf_date';
  $handler->display->display_options['fields']['field_tpf_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Entityform Submission: Navn */
  $handler->display->display_options['fields']['field_tpf_name']['id'] = 'field_tpf_name';
  $handler->display->display_options['fields']['field_tpf_name']['table'] = 'field_data_field_tpf_name';
  $handler->display->display_options['fields']['field_tpf_name']['field'] = 'field_tpf_name';
  /* Field: Entityform Submission: E-mail */
  $handler->display->display_options['fields']['field_tpf_email']['id'] = 'field_tpf_email';
  $handler->display->display_options['fields']['field_tpf_email']['table'] = 'field_data_field_tpf_email';
  $handler->display->display_options['fields']['field_tpf_email']['field'] = 'field_tpf_email';
  /* Field: Entityform Submission: Evt. besked */
  $handler->display->display_options['fields']['field_tpf_message']['id'] = 'field_tpf_message';
  $handler->display->display_options['fields']['field_tpf_message']['table'] = 'field_data_field_tpf_message';
  $handler->display->display_options['fields']['field_tpf_message']['field'] = 'field_tpf_message';
  $handler->display->display_options['fields']['field_tpf_message']['label'] = 'Vis formål, beskrivelse og besked';
  $handler->display->display_options['fields']['field_tpf_message']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_message']['alter']['text'] = '<a href="/entityform/[entityform_id_1]">Se ansøgning</a><br>
(Ekstra besked)[field_tpf_what_course] ';
  $handler->display->display_options['fields']['field_tpf_message']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tpf_message']['empty'] = '<a href="/entityform/[entityform_id_1] " target="_blank">Se ansøgning</a>[field_tpf_what_course] ';
  /* Field: Entityform Submission: Status */
  $handler->display->display_options['fields']['field_tpf_status']['id'] = 'field_tpf_status';
  $handler->display->display_options['fields']['field_tpf_status']['table'] = 'field_data_field_tpf_status';
  $handler->display->display_options['fields']['field_tpf_status']['field'] = 'field_tpf_status';
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'transportpulje_form' => 'transportpulje_form',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/settings/custom/transport';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Transportpulje';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entityform Submission: Indtast adresse */
  $handler->display->display_options['fields']['field_tpf_address']['id'] = 'field_tpf_address';
  $handler->display->display_options['fields']['field_tpf_address']['table'] = 'field_data_field_tpf_address';
  $handler->display->display_options['fields']['field_tpf_address']['field'] = 'field_tpf_address';
  $handler->display->display_options['fields']['field_tpf_address']['exclude'] = TRUE;
  /* Field: Entityform Submission: Entityform submission ID */
  $handler->display->display_options['fields']['entityform_id_1']['id'] = 'entityform_id_1';
  $handler->display->display_options['fields']['entityform_id_1']['table'] = 'entityform';
  $handler->display->display_options['fields']['entityform_id_1']['field'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id_1']['label'] = 'ID';
  $handler->display->display_options['fields']['entityform_id_1']['separator'] = '';
  /* Field: Entityform Submission: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Dato for indsendelse';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
  /* Field: Entityform Submission: Vælg forløb */
  $handler->display->display_options['fields']['field_tpf_course_select_1']['id'] = 'field_tpf_course_select_1';
  $handler->display->display_options['fields']['field_tpf_course_select_1']['table'] = 'field_data_field_tpf_course_select';
  $handler->display->display_options['fields']['field_tpf_course_select_1']['field'] = 'field_tpf_course_select';
  $handler->display->display_options['fields']['field_tpf_course_select_1']['label'] = 'Forløb';
  $handler->display->display_options['fields']['field_tpf_course_select_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tpf_course_select_1']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Entityform Submission: Indtast adresse */
  $handler->display->display_options['fields']['field_tpf_address_1']['id'] = 'field_tpf_address_1';
  $handler->display->display_options['fields']['field_tpf_address_1']['table'] = 'field_data_field_tpf_address';
  $handler->display->display_options['fields']['field_tpf_address_1']['field'] = 'field_tpf_address';
  /* Field: Entityform Submission: Vælg trin */
  $handler->display->display_options['fields']['field_tpf_grade']['id'] = 'field_tpf_grade';
  $handler->display->display_options['fields']['field_tpf_grade']['table'] = 'field_data_field_tpf_grade';
  $handler->display->display_options['fields']['field_tpf_grade']['field'] = 'field_tpf_grade';
  $handler->display->display_options['fields']['field_tpf_grade']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_grade']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_grade']['alter']['text'] = ', [field_tpf_grade]';
  /* Field: Entityform Submission: Institution */
  $handler->display->display_options['fields']['field_tpf_institution']['id'] = 'field_tpf_institution';
  $handler->display->display_options['fields']['field_tpf_institution']['table'] = 'field_data_field_tpf_institution';
  $handler->display->display_options['fields']['field_tpf_institution']['field'] = 'field_tpf_institution';
  $handler->display->display_options['fields']['field_tpf_institution']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_institution']['alter']['text'] = '[field_tpf_institution][field_tpf_grade]';
  $handler->display->display_options['fields']['field_tpf_institution']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Entityform Submission: Udgift */
  $handler->display->display_options['fields']['field_tpf_expense']['id'] = 'field_tpf_expense';
  $handler->display->display_options['fields']['field_tpf_expense']['table'] = 'field_data_field_tpf_expense';
  $handler->display->display_options['fields']['field_tpf_expense']['field'] = 'field_tpf_expense';
  /* Field: Entityform Submission: Dato */
  $handler->display->display_options['fields']['field_tpf_date']['id'] = 'field_tpf_date';
  $handler->display->display_options['fields']['field_tpf_date']['table'] = 'field_data_field_tpf_date';
  $handler->display->display_options['fields']['field_tpf_date']['field'] = 'field_tpf_date';
  $handler->display->display_options['fields']['field_tpf_date']['settings'] = array(
    'format_type' => 'short',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Entityform Submission: Navn */
  $handler->display->display_options['fields']['field_tpf_name']['id'] = 'field_tpf_name';
  $handler->display->display_options['fields']['field_tpf_name']['table'] = 'field_data_field_tpf_name';
  $handler->display->display_options['fields']['field_tpf_name']['field'] = 'field_tpf_name';
  /* Field: Entityform Submission: E-mail */
  $handler->display->display_options['fields']['field_tpf_email']['id'] = 'field_tpf_email';
  $handler->display->display_options['fields']['field_tpf_email']['table'] = 'field_data_field_tpf_email';
  $handler->display->display_options['fields']['field_tpf_email']['field'] = 'field_tpf_email';
  /* Field: Entityform Submission: Evt. besked */
  $handler->display->display_options['fields']['field_tpf_message']['id'] = 'field_tpf_message';
  $handler->display->display_options['fields']['field_tpf_message']['table'] = 'field_data_field_tpf_message';
  $handler->display->display_options['fields']['field_tpf_message']['field'] = 'field_tpf_message';
  $handler->display->display_options['fields']['field_tpf_message']['label'] = 'Vis/Besked';
  $handler->display->display_options['fields']['field_tpf_message']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tpf_message']['empty'] = '<a href="/entityform/[entityform_id_1] " target="_blank">Se ansøgning</a>';
  /* Field: Entityform Submission: Status */
  $handler->display->display_options['fields']['field_tpf_status']['id'] = 'field_tpf_status';
  $handler->display->display_options['fields']['field_tpf_status']['table'] = 'field_data_field_tpf_status';
  $handler->display->display_options['fields']['field_tpf_status']['field'] = 'field_tpf_status';
  $handler->display->display_options['path'] = 'admin/settings/custom/transport/export.csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['tpf_requests'] = array(
    t('Master'),
    t('Transportpulje ansøgninger'),
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
    t('Notice: Addresses marked (*) are submissions wth an address differing from the course selected in the dropdown. Submissions with a course not selected are not considered to be differing.'),
    t('Ingen ansøgninger på nuværende tidspunkt'),
    t('Content entity referenced from field_tpf_course_select'),
    t('Vælg forløb'),
    t('Adresse varierer fra indhold'),
    t('(*)'),
    t('Beskriv læringsfomålet'),
    t('Hvad er forløbet'),
    t('<br>(individuel beskr. og formål)'),
    t('Entityform Submission'),
    t('- Choose an operation -'),
    t('ID'),
    t('.'),
    t('Dato for indsendelse'),
    t('Udfyldt i backend'),
    t('Forløb/Adresse'),
    t('[field_tpf_course_select]<br>
[field_tpf_address] [field_tpf_address_variation]'),
    t('Vælg trin'),
    t(', [field_tpf_grade]'),
    t('Institution'),
    t('[field_tpf_institution][field_tpf_grade]'),
    t('Udgift'),
    t('Dato'),
    t('Navn'),
    t('E-mail'),
    t('Vis formål, beskrivelse og besked'),
    t('<a href="/entityform/[entityform_id_1]">Se ansøgning</a><br>
(Ekstra besked)[field_tpf_what_course] '),
    t('<a href="/entityform/[entityform_id_1] " target="_blank">Se ansøgning</a>[field_tpf_what_course] '),
    t('Status'),
    t('Page'),
    t('more'),
    t('Data export'),
    t('Indtast adresse'),
    t('Forløb'),
    t('Vis/Besked'),
    t('<a href="/entityform/[entityform_id_1] " target="_blank">Se ansøgning</a>'),
  );
  $export['tpf_requests'] = $view;

  return $export;
}
