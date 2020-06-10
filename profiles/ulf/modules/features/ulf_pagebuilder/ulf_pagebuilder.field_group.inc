<?php

/**
 * @file
 * ulf_pagebuilder.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ulf_pagebuilder_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_styles|paragraphs_item|appetizer|form';
  $field_group->group_name = 'group_styles';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'appetizer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Udseende',
    'weight' => '1',
    'children' => array(
      0 => 'field_paragraph_bg_color',
      1 => 'field_paragraph_border_color',
      2 => 'field_paragraph_text_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-styles field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_styles|paragraphs_item|appetizer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_styles|paragraphs_item|download_list|form';
  $field_group->group_name = 'group_styles';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'download_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Udseende',
    'weight' => '1',
    'children' => array(
      0 => 'field_paragraph_bg_color',
      1 => 'field_paragraph_border_color',
      2 => 'field_paragraph_text_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-styles field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_styles|paragraphs_item|download_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_styles|paragraphs_item|four_columns|form';
  $field_group->group_name = 'group_styles';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'four_columns';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Udseende',
    'weight' => '1',
    'children' => array(
      0 => 'field_paragraph_bg_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-styles field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_styles|paragraphs_item|four_columns|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_styles|paragraphs_item|link_list|form';
  $field_group->group_name = 'group_styles';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'link_list';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Udseende',
    'weight' => '1',
    'children' => array(
      0 => 'field_paragraph_bg_color',
      1 => 'field_paragraph_border_color',
      2 => 'field_paragraph_text_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-styles field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_styles|paragraphs_item|link_list|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_styles|paragraphs_item|one_column|form';
  $field_group->group_name = 'group_styles';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'one_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Udseende',
    'weight' => '1',
    'children' => array(
      0 => 'field_paragraph_bg_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-styles field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_styles|paragraphs_item|one_column|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_styles|paragraphs_item|text_with_image|form';
  $field_group->group_name = 'group_styles';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text_with_image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Udseende',
    'weight' => '1',
    'children' => array(
      0 => 'field_paragraph_bg_color',
      1 => 'field_paragraph_border_color',
      2 => 'field_paragraph_text_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-styles field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_styles|paragraphs_item|text_with_image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_styles|paragraphs_item|text_with_video|form';
  $field_group->group_name = 'group_styles';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'text_with_video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Udseende',
    'weight' => '1',
    'children' => array(
      0 => 'field_paragraph_bg_color',
      1 => 'field_paragraph_border_color',
      2 => 'field_paragraph_text_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-styles field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_styles|paragraphs_item|text_with_video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_styles|paragraphs_item|three_columns|form';
  $field_group->group_name = 'group_styles';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'three_columns';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Udseende',
    'weight' => '1',
    'children' => array(
      0 => 'field_paragraph_bg_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-styles field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_styles|paragraphs_item|three_columns|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_styles|paragraphs_item|two_column|form';
  $field_group->group_name = 'group_styles';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'two_column';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Udseende',
    'weight' => '1',
    'children' => array(
      0 => 'field_paragraph_bg_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-styles field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_styles|paragraphs_item|two_column|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Udseende');

  return $field_groups;
}
