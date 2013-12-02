<?php
/**
 * @file
 * ulf_course.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ulf_course_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course|node|course|form';
  $field_group->group_name = 'group_course';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Forløbet',
    'weight' => '0',
    'children' => array(
      0 => 'field_full_description',
      1 => 'field_image',
      2 => 'field_short_description',
      3 => 'field_subject',
      4 => 'field_tags',
      5 => 'field_target_group',
      6 => 'field_target_group_sub',
      7 => 'field_teaser',
      8 => 'field_tilbudstype',
      9 => 'field_offer_type',
      10 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Forløbet',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-course field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_course|node|course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_duration|node|course|default';
  $field_group->group_name = 'group_duration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_layout_gamma';
  $field_group->data = array(
    'label' => 'Varighed',
    'weight' => '16',
    'children' => array(
      0 => 'field_duration',
      1 => 'field_duration_unit',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Varighed',
      'instance_settings' => array(
        'classes' => 'module--field field-group--duration',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_duration|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_duration|node|course|full';
  $field_group->group_name = 'group_duration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_layout_gamma';
  $field_group->data = array(
    'label' => 'Varighed',
    'weight' => '14',
    'children' => array(
      0 => 'field_duration',
      1 => 'field_duration_unit',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Varighed',
      'instance_settings' => array(
        'classes' => 'module--field field-group--duration',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_duration|node|course|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_duration|node|course|node_display';
  $field_group->group_name = 'group_duration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'node_display';
  $field_group->parent_name = 'group_layout_gamma';
  $field_group->data = array(
    'label' => 'Varighed',
    'weight' => '9',
    'children' => array(
      0 => 'field_duration',
      1 => 'field_duration_unit',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Varighed',
      'instance_settings' => array(
        'classes' => 'module--field field-group--duration',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_duration|node|course|node_display'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_beta|node|course|default';
  $field_group->group_name = 'group_layout_beta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Beta',
    'weight' => '0',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Beta',
      'instance_settings' => array(
        'classes' => 'layout-element-beta',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_layout_beta|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_beta|node|course|full';
  $field_group->group_name = 'group_layout_beta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Beta',
    'weight' => '0',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Beta',
      'instance_settings' => array(
        'classes' => 'layout-element-beta',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_layout_beta|node|course|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_beta|node|course|node_display';
  $field_group->group_name = 'group_layout_beta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'node_display';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Beta',
    'weight' => '0',
    'children' => array(
      0 => 'field_image',
      1 => 'field_tags',
      2 => 'field_teaser',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Beta',
      'instance_settings' => array(
        'classes' => 'layout-element-beta',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_layout_beta|node|course|node_display'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_delta|node|course|default';
  $field_group->group_name = 'group_layout_delta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Delta',
    'weight' => '13',
    'children' => array(
      0 => 'field_full_description',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Delta',
      'instance_settings' => array(
        'classes' => 'layout-element-delta',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_layout_delta|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_delta|node|course|full';
  $field_group->group_name = 'group_layout_delta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Delta',
    'weight' => '12',
    'children' => array(
      0 => 'field_full_description',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Delta',
      'instance_settings' => array(
        'classes' => 'layout-element-delta',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_layout_delta|node|course|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_delta|node|course|node_display';
  $field_group->group_name = 'group_layout_delta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'node_display';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Delta',
    'weight' => '6',
    'children' => array(
      0 => 'field_full_description',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Delta',
      'instance_settings' => array(
        'classes' => 'layout-element-delta',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_layout_delta|node|course|node_display'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_gamma|node|course|default';
  $field_group->group_name = 'group_layout_gamma';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Gamma',
    'weight' => '12',
    'children' => array(
      0 => 'field_collection_price',
      1 => 'field_count',
      2 => 'field_price_info',
      3 => 'field_subject',
      4 => 'field_target_group_sub',
      5 => 'field_offer_type',
      6 => 'group_duration',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Gamma',
      'instance_settings' => array(
        'classes' => 'layout-element-gamma',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_layout_gamma|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_gamma|node|course|full';
  $field_group->group_name = 'group_layout_gamma';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Gamma',
    'weight' => '11',
    'children' => array(
      0 => 'field_collection_price',
      1 => 'field_count',
      2 => 'field_price_info',
      3 => 'field_subject',
      4 => 'field_target_group_sub',
      5 => 'field_offer_type',
      6 => 'group_duration',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Gamma',
      'instance_settings' => array(
        'classes' => 'layout-element-gamma',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_layout_gamma|node|course|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_gamma|node|course|node_display';
  $field_group->group_name = 'group_layout_gamma';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'node_display';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Gamma',
    'weight' => '3',
    'children' => array(
      0 => 'field_collection_price',
      1 => 'field_count',
      2 => 'field_price_info',
      3 => 'field_subject',
      4 => 'field_target_group',
      5 => 'field_target_group_sub',
      6 => 'field_offer_type',
      7 => 'group_duration',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Gamma',
      'instance_settings' => array(
        'classes' => 'layout-element-gamma',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_layout_gamma|node|course|node_display'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_practical_info|node|course|form';
  $field_group->group_name = 'group_practical_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Målgruppe, varighed, pris',
    'weight' => '1',
    'children' => array(
      0 => 'field_collection_price',
      1 => 'field_count',
      2 => 'field_duration',
      3 => 'field_duration_unit',
      4 => 'field_price_info',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Målgruppe, varighed, pris',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-practical-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_practical_info|node|course|form'] = $field_group;

  return $export;
}
