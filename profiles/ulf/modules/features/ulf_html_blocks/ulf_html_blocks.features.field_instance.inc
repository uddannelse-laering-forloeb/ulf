<?php
/**
 * @file
 * ulf_html_blocks.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ulf_html_blocks_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-html_block-field_html_code'.
  $field_instances['node-html_block-field_html_code'] = array(
    'bundle' => 'html_block',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Tilføj html koden her.
Hvis billeder anvendes som fuld bredde, giver en minimumsbredde på 650px det bedste resultat.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_html_code',
    'label' => 'HTML kode',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 8,
      ),
      'type' => 'text_textarea',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-html_block-field_html_custom_image'.
  $field_instances['node-html_block-field_html_custom_image'] = array(
    'bundle' => 'html_block',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_html_custom_image',
    'label' => 'Custom image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'static_pages_images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 1,
        'insert_absolute' => 1,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 0,
          'icon_link' => 0,
          'image' => 'image',
          'image_large' => 0,
          'image_logo' => 0,
          'image_medium' => 0,
          'image_node_display' => 0,
          'image_teaser_display' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => 1000,
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 0,
        'manualcrop_filter_insert' => 0,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => 0,
        'manualcrop_instant_preview' => 1,
        'manualcrop_keyboard' => 1,
        'manualcrop_maximize_default_crop_area' => 0,
        'manualcrop_require_cropping' => array(
          'teaser_display' => 'teaser_display',
        ),
        'manualcrop_styles_list' => array(
          'teaser_display' => 'teaser_display',
        ),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 32,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom image');
  t('HTML kode');
  t('Tilføj html koden her.
Hvis billeder anvendes som fuld bredde, giver en minimumsbredde på 650px det bedste resultat.');

  return $field_instances;
}
