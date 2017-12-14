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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Ingen ansøgninger på nuværende tidspunkt';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
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
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'html5_tools_iso8601';
  /* Field: Entityform Submission: Vælg forløb */
  $handler->display->display_options['fields']['field_tpf_course_select']['id'] = 'field_tpf_course_select';
  $handler->display->display_options['fields']['field_tpf_course_select']['table'] = 'field_data_field_tpf_course_select';
  $handler->display->display_options['fields']['field_tpf_course_select']['field'] = 'field_tpf_course_select';
  $handler->display->display_options['fields']['field_tpf_course_select']['label'] = 'Valgt forløb';
  $handler->display->display_options['fields']['field_tpf_course_select']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  /* Field: Entityform Submission: Jeg kunne ikke finde forløbet  */
  $handler->display->display_options['fields']['field_tpf_course_not_found']['id'] = 'field_tpf_course_not_found';
  $handler->display->display_options['fields']['field_tpf_course_not_found']['table'] = 'field_data_field_tpf_course_not_found';
  $handler->display->display_options['fields']['field_tpf_course_not_found']['field'] = 'field_tpf_course_not_found';
  $handler->display->display_options['fields']['field_tpf_course_not_found']['label'] = 'Manuelt indtastet adresse';
  $handler->display->display_options['fields']['field_tpf_course_not_found']['alter']['text'] = 'Ja';
  $handler->display->display_options['fields']['field_tpf_course_not_found']['empty'] = 'Nej';
  $handler->display->display_options['fields']['field_tpf_course_not_found']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_tpf_course_not_found']['type'] = 'list_key';
  /* Field: Entityform Submission: Indtast adresse */
  $handler->display->display_options['fields']['field_tpf_address']['id'] = 'field_tpf_address';
  $handler->display->display_options['fields']['field_tpf_address']['table'] = 'field_data_field_tpf_address';
  $handler->display->display_options['fields']['field_tpf_address']['field'] = 'field_tpf_address';
  $handler->display->display_options['fields']['field_tpf_address']['label'] = 'Adresse';
  /* Field: Entityform Submission: Institution */
  $handler->display->display_options['fields']['field_tpf_institution']['id'] = 'field_tpf_institution';
  $handler->display->display_options['fields']['field_tpf_institution']['table'] = 'field_data_field_tpf_institution';
  $handler->display->display_options['fields']['field_tpf_institution']['field'] = 'field_tpf_institution';
  $handler->display->display_options['fields']['field_tpf_institution']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Entityform Submission: Link */
  $handler->display->display_options['fields']['link_entityform']['id'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['link_entityform']['field'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['label'] = '';
  $handler->display->display_options['fields']['link_entityform']['element_label_colon'] = FALSE;
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
    t('Ingen ansøgninger på nuværende tidspunkt'),
    t('ID'),
    t('.'),
    t('Dato for indsendelse'),
    t('Valgt forløb'),
    t('Manuelt indtastet adresse'),
    t('Ja'),
    t('Nej'),
    t('Adresse'),
    t('Institution'),
    t('Page'),
    t('more'),
  );
  $export['tpf_requests'] = $view;

  return $export;
}
