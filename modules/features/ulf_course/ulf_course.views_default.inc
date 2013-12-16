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
  $handler->display->display_options['css_class'] = 'block-inline-module';
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
  $handler->display->display_options['fields']['field_subject']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_subject']['delta_offset'] = '0';
  /* Field: Content: Evt. yderligere oplysninger til varighed og pris */
  $handler->display->display_options['fields']['field_price_info']['id'] = 'field_price_info';
  $handler->display->display_options['fields']['field_price_info']['table'] = 'field_data_field_price_info';
  $handler->display->display_options['fields']['field_price_info']['field'] = 'field_price_info';
  $handler->display->display_options['fields']['field_price_info']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_price_info']['exclude'] = TRUE;
  /* Field: Content: Målgruppe */
  $handler->display->display_options['fields']['field_target_group_sub']['id'] = 'field_target_group_sub';
  $handler->display->display_options['fields']['field_target_group_sub']['table'] = 'field_data_field_target_group_sub';
  $handler->display->display_options['fields']['field_target_group_sub']['field'] = 'field_target_group_sub';
  $handler->display->display_options['fields']['field_target_group_sub']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_target_group_sub']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_target_group_sub']['delta_offset'] = '0';
  /* Field: Content: Pris */
  $handler->display->display_options['fields']['field_collection_price']['id'] = 'field_collection_price';
  $handler->display->display_options['fields']['field_collection_price']['table'] = 'field_data_field_collection_price';
  $handler->display->display_options['fields']['field_collection_price']['field'] = 'field_collection_price';
  $handler->display->display_options['fields']['field_collection_price']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_collection_price']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_collection_price']['alter']['strip_tags'] = TRUE;
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
  /* Field: Content: Gratis */
  $handler->display->display_options['fields']['field_free']['id'] = 'field_free';
  $handler->display->display_options['fields']['field_free']['table'] = 'field_data_field_free';
  $handler->display->display_options['fields']['field_free']['field'] = 'field_free';
  $handler->display->display_options['fields']['field_free']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_free']['exclude'] = TRUE;
  /* Field: Content: Vælg enhed */
  $handler->display->display_options['fields']['field_duration_unit']['id'] = 'field_duration_unit';
  $handler->display->display_options['fields']['field_duration_unit']['table'] = 'field_data_field_duration_unit';
  $handler->display->display_options['fields']['field_duration_unit']['field'] = 'field_duration_unit';
  $handler->display->display_options['fields']['field_duration_unit']['label'] = 'excluded';
  $handler->display->display_options['fields']['field_duration_unit']['exclude'] = TRUE;
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
<div class="block-inline-module--field-label">Pris</div><div class="block-inline-module--field-text">[field_collection_price]</div>
<div class="block-inline-module--field-text">[field_free]</div>
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
<div class="block-inline-module--field-label">Pris</div><div class="block-inline-module--field-text">[field_collection_price]</div>
<div class="block-inline-module--field-text">[field_free]</div>
</div>
<div class="block-module--field-wrapper">
<div class="block-module--field-label">Yderligere information</div><div class="block-inline-module--field-text">[field_price_info]</div>
</div>'),
    t('All'),
    t('Ulf practical information'),
    t('View panes'),
  );
  $export['ulf_practical_info'] = $view;

  return $export;
}
