<?php
/**
 * @file
 * ulf_course_educators.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ulf_course_educators_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-course_educators-field_catering'.
  $field_instances['node-course_educators-field_catering'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Angiv oplysninger om, hvordan man tilmelder sig, om kurset er med forplejning osv.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_catering',
    'label' => 'Forplejning',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_collection_price'.
  $field_instances['node-course_educators-field_collection_price'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_collection_price',
    'label' => 'Pris',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_course_contact_mail'.
  $field_instances['node-course_educators-field_course_contact_mail'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Værdier fra dette felt bør flyttes til kontakt.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_course_contact_mail',
    'label' => 'Email',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'emailwidget',
      'weight' => 46,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_course_contact_name'.
  $field_instances['node-course_educators-field_course_contact_name'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Værdier fra dette felt bør flyttes til kontakt.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_course_contact_name',
    'label' => 'Navn',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 45,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_course_phone'.
  $field_instances['node-course_educators-field_course_phone'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Værdier fra dette felt bør flyttes til kontakt.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_course_phone',
    'label' => 'Telefonnummer',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'telwidget',
      'weight' => 47,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_duration'.
  $field_instances['node-course_educators-field_duration'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => 1,
          'scale' => 2,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_decimal',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_duration',
    'label' => 'Varighed',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 42,
    ),
  );

  // Exported field_instance:
  // 'node-course_educators-field_duration_description'.
  $field_instances['node-course_educators-field_duration_description'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_duration_description',
    'label' => 'Beskrivelse til varighed',
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
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 45,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_duration_unit'.
  $field_instances['node-course_educators-field_duration_unit'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_duration_unit',
    'label' => 'Vælg enhed',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 43,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_educational_goals'.
  $field_instances['node-course_educators-field_educational_goals'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_educational_goals',
    'label' => 'Pædagogiske læreplanstemaer',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'node-course_educators-field_educational_material'.
  $field_instances['node-course_educators-field_educational_material'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Her kan du uploade materiale til kurset.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_educational_material',
    'label' => 'Materialer',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_free'.
  $field_instances['node-course_educators-field_free'] = array(
    'bundle' => 'course_educators',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_free',
    'label' => 'Gratis',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 39,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_full_description'.
  $field_instances['node-course_educators-field_full_description'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Skriv en beskrivelse af kursets indhold',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_full_description',
    'label' => 'Beskrivelse',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_image'.
  $field_instances['node-course_educators-field_image'] = array(
    'bundle' => 'course_educators',
    'deleted' => 0,
    'description' => '<p>OBS! Det er jeres ansvar at sikre, at der er styr på rettigheder og tilladelser, når I sender billeder til os.</p>
<p>Hvis flere billeder er uploadet vil det øverste billede blive anvendt. Rækkefølgen på billeder kan styres ved at trække i krydset i venstre side.</p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'node_display',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'teaser_display',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image',
    'label' => 'Upload et billede/illustration',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'course_images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '1000x320',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => 0,
        'insert_class' => '',
        'insert_default' => 'image',
        'insert_styles' => array(
          'image' => 0,
          'image_node_display' => 0,
          'image_teaser_display' => 0,
        ),
        'insert_width' => '',
        'manualcrop_crop_info' => 1,
        'manualcrop_default_crop_area' => 1,
        'manualcrop_enable' => 1,
        'manualcrop_filter_insert' => 1,
        'manualcrop_inline_crop' => 0,
        'manualcrop_instant_crop' => 0,
        'manualcrop_instant_preview' => 1,
        'manualcrop_keyboard' => 0,
        'manualcrop_maximize_default_crop_area' => 1,
        'manualcrop_require_cropping' => array(),
        'manualcrop_styles_list' => array(
          'node_display' => 'node_display',
          'teaser_display' => 'teaser_display',
        ),
        'manualcrop_styles_mode' => 'include',
        'manualcrop_thumblist' => 0,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_last_signup_date'.
  $field_instances['node-course_educators-field_last_signup_date'] = array(
    'bundle' => 'course_educators',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'ulf_default_date_format',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_last_signup_date',
    'label' => 'Tilmeldingsfrist',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 55,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_map_placement'.
  $field_instances['node-course_educators-field_map_placement'] = array(
    'bundle' => 'course_educators',
    'default_value' => array(
      0 => array(
        'value' => 'provider',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_map_placement',
    'label' => 'Visning på kort',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_message_form'.
  $field_instances['node-course_educators-field_message_form'] = array(
    'bundle' => 'course_educators',
    'default_value' => array(
      0 => array(
        'target_id' => 2,
      ),
    ),
    'deleted' => 0,
    'description' => 'Vælg indstilling for visning af kontaktformular i kontaktboks',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 1,
          'use_content_language' => 1,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_message_form',
    'label' => 'Message form',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_period'.
  $field_instances['node-course_educators-field_period'] = array(
    'bundle' => 'course_educators',
    'deleted' => 0,
    'description' => 'Angiv tidspunkt for kursets afvikling.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'simple_date',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_period',
    'label' => 'Periode',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'd/m/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_select',
      'weight' => 54,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_period_full_year'.
  $field_instances['node-course_educators-field_period_full_year'] = array(
    'bundle' => 'course_educators',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_period_full_year',
    'label' => 'Hele året',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 52,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_period_info'.
  $field_instances['node-course_educators-field_period_info'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_period_info',
    'label' => 'Yderligere oplysninger til periode',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
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
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 56,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_place'.
  $field_instances['node-course_educators-field_place'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Skriv ikke jeres faste fysiske adresse her, den har vi allerede. Anvend dette felt til ekstraoplysninger om forløbets sted: Eks. \'Store Sal\', \'Brug højre indgang - ring på dørklokken\' eller en alternativ adresse end jeres faste fysiske adresse.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_place',
    'label' => 'Sted (ekstraoplysninger): Eks. \'Store Sal\', \'Brug højre indgang - ring på dørklokken\' ',
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
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_price'.
  $field_instances['node-course_educators-field_price'] = array(
    'bundle' => 'course_educators',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Værdier fra dette felt bør flyttes til multifeltet "Pris" herunder.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_price',
    'label' => 'Pris',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 40,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_price_description'.
  $field_instances['node-course_educators-field_price_description'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_price_description',
    'label' => 'Beskrivelse til pris',
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
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_profile_contact'.
  $field_instances['node-course_educators-field_profile_contact'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 27,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_profile_contact',
    'label' => 'Kontakt',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 48,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_relevance_educators'.
  $field_instances['node-course_educators-field_relevance_educators'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Vælg den relevante målgruppe for dit kursus.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_relevance_educators',
    'label' => 'Målgruppe',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-course_educators-field_relevance_primary_school'.
  $field_instances['node-course_educators-field_relevance_primary_school'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Vælg omfattede fag for grundskoler.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_relevance_primary_school',
    'label' => 'Kurset er relevant for lærere, der underviser i fagene',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'node-course_educators-field_relevance_upper_school'.
  $field_instances['node-course_educators-field_relevance_upper_school'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Vælg omfattede fag for ungdomsuddannelser.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_relevance_upper_school',
    'label' => 'Kurset er relevant for undervisere i fagene',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_signup_description'.
  $field_instances['node-course_educators-field_signup_description'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Beskriv hvordan man tilmelder sig og andre instruktioner i forbindelse med tilmelding.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 29,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_signup_description',
    'label' => 'Tilmeldingsbeskrivelse',
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
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 59,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_signup_email'.
  $field_instances['node-course_educators-field_signup_email'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_signup_email',
    'label' => 'Tilmeldingsemail',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'emailwidget',
      'weight' => 57,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_signup_link'.
  $field_instances['node-course_educators-field_signup_link'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Angiv url til mail eller link til side.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_signup_link',
    'label' => 'Tilmelding',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 56,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_signup_phone'.
  $field_instances['node-course_educators-field_signup_phone'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Telefonnummer til tilmelding.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_signup_phone',
    'label' => 'Tilmeldingstelefonnummer',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'html5_tools',
      'settings' => array(),
      'type' => 'telwidget',
      'weight' => 58,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_subject'.
  $field_instances['node-course_educators-field_subject'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Angiv kursets emneområde, vælg gerne flere.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_plain',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_subject',
    'label' => 'Emneområde',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_trashed'.
  $field_instances['node-course_educators-field_trashed'] = array(
    'bundle' => 'course_educators',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_trashed',
    'label' => 'Trashed',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 60,
    ),
  );

  // Exported field_instance: 'node-course_educators-field_video'.
  $field_instances['node-course_educators-field_video'] = array(
    'bundle' => 'course_educators',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Angiv URLen på en Youtube eller Vimeo video',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 1,
          'description_position' => 'bottom',
          'video_style' => 'normal',
        ),
        'type' => 'video_embed_field',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_video',
    'label' => 'Video',
    'required' => 0,
    'settings' => array(
      'allowed_providers' => array(
        'vimeo' => 'vimeo',
        'youtube' => 'youtube',
      ),
      'description_field' => 0,
      'description_length' => 128,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'video_embed_field',
      'settings' => array(),
      'type' => 'video_embed_field_video',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>OBS! Det er jeres ansvar at sikre, at der er styr på rettigheder og tilladelser, når I sender billeder til os.</p>
<p>Hvis flere billeder er uploadet vil det øverste billede blive anvendt. Rækkefølgen på billeder kan styres ved at trække i krydset i venstre side.</p>');
  t('Angiv URLen på en Youtube eller Vimeo video');
  t('Angiv kursets emneområde, vælg gerne flere.');
  t('Angiv oplysninger om, hvordan man tilmelder sig, om kurset er med forplejning osv.');
  t('Angiv tidspunkt for kursets afvikling.');
  t('Angiv url til mail eller link til side.');
  t('Beskriv hvordan man tilmelder sig og andre instruktioner i forbindelse med tilmelding.');
  t('Beskrivelse');
  t('Beskrivelse til pris');
  t('Beskrivelse til varighed');
  t('Email');
  t('Emneområde');
  t('Forplejning');
  t('Gratis');
  t('Hele året');
  t('Her kan du uploade materiale til kurset.');
  t('Kontakt');
  t('Kurset er relevant for lærere, der underviser i fagene');
  t('Kurset er relevant for undervisere i fagene');
  t('Materialer');
  t('Message form');
  t('Målgruppe');
  t('Navn');
  t('Periode');
  t('Pris');
  t('Pædagogiske læreplanstemaer');
  t('Skriv en beskrivelse af kursets indhold');
  t('Skriv ikke jeres faste fysiske adresse her, den har vi allerede. Anvend dette felt til ekstraoplysninger om forløbets sted: Eks. \'Store Sal\', \'Brug højre indgang - ring på dørklokken\' eller en alternativ adresse end jeres faste fysiske adresse.');
  t('Sted (ekstraoplysninger): Eks. \'Store Sal\', \'Brug højre indgang - ring på dørklokken\' ');
  t('Telefonnummer');
  t('Telefonnummer til tilmelding.');
  t('Tilmelding');
  t('Tilmeldingsbeskrivelse');
  t('Tilmeldingsemail');
  t('Tilmeldingsfrist');
  t('Tilmeldingstelefonnummer');
  t('Trashed');
  t('Upload et billede/illustration');
  t('Varighed');
  t('Video');
  t('Visning på kort');
  t('Vælg den relevante målgruppe for dit kursus.');
  t('Vælg enhed');
  t('Vælg indstilling for visning af kontaktformular i kontaktboks');
  t('Vælg omfattede fag for grundskoler.');
  t('Vælg omfattede fag for ungdomsuddannelser.');
  t('Værdier fra dette felt bør flyttes til kontakt.');
  t('Værdier fra dette felt bør flyttes til multifeltet "Pris" herunder.');
  t('Yderligere oplysninger til periode');

  return $field_instances;
}
