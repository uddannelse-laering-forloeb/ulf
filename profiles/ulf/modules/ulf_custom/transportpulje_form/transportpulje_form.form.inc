<?php

/**
 * @file
 *
 * Code for the Transportpulje custom form.
 */

include_once 'transportpulje_form.tpf-options.inc';
include_once 'transportpulje_form.mail.inc';

/**
 * Custom form for adding a transport application entity_form entity.
 *
 * @param array $form
 *   Custom frontend form.
 * @param array $form_state
 *   Form state of custom form.
 *
 * @return mixed
 *   The complete form.
 */
function transportpulje_form_add_application(array $form, array &$form_state) {
  $institution_list = taxonomy_get_tree(taxonomy_vocabulary_machine_name_load('tpf_institutions_list')->vid);
  $term_ids = array();
  foreach ($institution_list as $term) {
    $term_ids[] = $term->tid;
  }

  // Get terms with fields from institutions list.
  $terms = taxonomy_term_load_multiple($term_ids);

  // Get all courses with location hidden.
  $hidden_courses = db_select('field_data_field_map_placement', 'f')
    ->fields('f', array('entity_id'))
    ->condition('entity_type', 'node')
    ->condition('bundle', 'course')
    ->condition('field_map_placement_value', 'hide')
    ->execute()
    ->fetchCol();

  // General form setup.
  $form['#attached'] = array(
    'css' => array(
      drupal_get_path('module', 'transportpulje_form') . '/css/transportpulje_form.css',
    ),
    'js' => array(
      array(
        'type' => 'file',
        'data' => drupal_get_path('module', 'transportpulje_form') . '/js/transportpulje_form.js',
      ),
      array(
        'type' => 'setting',
        'data' => array(
          'transportpulje_form' => array(
            'institutions' => $terms,
            'hidden' => $hidden_courses,
          ),
        ),
      ),
    ),
  );

  // Add fields.
  $form['intro'] = array(
    '#markup' => '<h1>' . t('Transport pool form') . '</h1><div class="user-message--wrapper"><div class="user-message">' . variable_get('intro', array('value' => '', 'format' => NULL))['value'] . '</div></div>',
  );
  $form['fields'] = array('#type' => 'container');

  // Create part one.
  $form['fields']['part_one'] = array(
    '#type' => 'container',
    '#weight' => 1,
  );
  $form['fields']['part_one']['select_course'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select course')
  );
  $form['fields']['part_one']['select_institution'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select institution')
  );

  // Set suffix and default selection based on query.
  $course_dropdown_default = isset($form_state['values']['course_dropdown']) ? $form_state['values']['course_dropdown'] : '';
  $course_dropdown_suffix = '<div id="course_dropdown_address"></div>';
  $course_dropdown_params = drupal_get_query_parameters();
  if (array_key_exists('course_id', $course_dropdown_params)) {
    $course_dropdown_default = $course_dropdown_params['course_id'];
    $course_dropdown_selected_node = node_load($course_dropdown_params['course_id']);
    if (isset($course_dropdown_selected_node->location['street']) && isset($course_dropdown_selected_node->location['postal_code']) && isset($course_dropdown_selected_node->location['city'])) {
      $course_dropdown_suffix = '<div id="course_dropdown_address">' . $course_dropdown_selected_node->location['street'] . '<br>' . $course_dropdown_selected_node->location['postal_code'] . '<br>' . $course_dropdown_selected_node->location['city'] . '</div>';
    }
    else {
      $course_dropdown_suffix = '<div id="course_dropdown_address"></div>';
    }
  }

  // Add fields to course wrapper.
  $form['fields']['part_one']['select_course']['course_dropdown'] = array(
    '#title' => t('Select course'),
    '#type' => 'select',
    "#empty_option" => t('- Select -'),
    '#size' => 15,
    '#options' => _tpf_modify_course_dropdown(entityreference_get_selection_handler(field_info_field('field_tpf_course_select'))->getReferencableEntities()),
    '#default_value' => $course_dropdown_default,
    '#name' => 'course_dropdown',
    '#states' => array(
      'required' => array(
        ':input[name="course_not_found"]' => array('unchecked' => TRUE),
      ),
    ),
    '#suffix' => $course_dropdown_suffix,

  );

  $form['fields']['part_one']['select_course']['course_not_found'] = array(
    '#title' => t('I could not find the course'),
    '#type' => 'checkbox',
    '#description' => variable_get('help_no_course'),
  );

  $form['fields']['part_one']['select_course']['distance_calc_failed'] = array(
    '#title' => t('Distance calculation failed'),
    '#type' => 'hidden',
  );

  $form['fields']['part_one']['select_course']['course_what'] = array(
    '#title' => t('What is the course'),
    '#type' => 'textarea',
    '#default_value' => isset($form_state['values']['course_what']) ? $form_state['values']['course_what'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="course_not_found"]' => array('checked' => TRUE),
      ),
      'required' => array(
        ':input[name="course_not_found"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['fields']['part_one']['select_course']['course_description'] = array(
    '#title' => t('Describe the learning target'),
    '#type' => 'textarea',
    '#default_value' => isset($form_state['values']['course_description']) ? $form_state['values']['course_description'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="course_not_found"]' => array('checked' => TRUE),
      ),
      'required' => array(
        ':input[name="course_not_found"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['fields']['part_one']['select_course']['course_address'] = array(
    '#type' => 'fieldset',
    '#title' => t('Course Address'),
  );

  $form['fields']['part_one']['select_course']['course_address']['street'] = array(
    '#title' => t('Street'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => isset($form_state['values']['course_address']['street']) ? $form_state['values']['street'] : '',
  );

  $form['fields']['part_one']['select_course']['course_address']['postal_code'] = array(
    '#title' => t('Postal code'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => isset($form_state['values']['course_address']['postal_code']) ? $form_state['values']['course_address']['postal_code'] : '',
  );

  $form['fields']['part_one']['select_course']['course_address']['city'] = array(
    '#title' => t('City'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => isset($form_state['values']['course_address']['city']) ? $form_state['values']['course_address']['city'] : '',
  );

  // Add fields to select institution.
  $form['fields']['part_one']['select_institution']['institution_type'] = array(
    '#title' => t('Type'),
    '#type' => 'select',
    "#empty_option" => t('- Select -'),
    '#options' => list_allowed_values(field_info_field('field_tpf_institution_type')),
    '#required' => TRUE,
    '#default_value' => isset($form_state['values']['institution_type']) ? $form_state['values']['institution_type'] : '',
  );

  $form['fields']['part_one']['select_institution']['institution_name'] = array(
    '#title' => t('Institution'),
    '#type' => 'select',
    "#empty_option" => t('- Select -'),
    '#options' => taxonomy_allowed_values(field_info_field('field_tpf_institution')),
    '#required' => TRUE,
    '#default_value' => isset($form_state['values']['institution_name']) ? $form_state['values']['institution_name'] : '',
  );

  $form['fields']['part_one']['select_institution']['institution_grade'] = array(
    '#title' => t('Select grade'),
    '#type' => 'select',
    "#empty_option" => t('- Select -'),
    '#options' => list_allowed_values(field_info_field('field_tpf_grade')),
    '#default_value' => isset($form_state['values']['institution_grade']) ? $form_state['values']['institution_grade'] : '',
    '#states' => array(
      'visible' => array(
        ':input[name="institution_type"]' => array('value' => 'tpf_school'),
      ),
      'required' => array(
        ':input[name="institution_type"]' => array('value' => 'tpf_school'),
      ),
    ),
  );

  $form['fields']['part_two'] = array(
    '#prefix' => '<div id="part_two">',
    '#type' => 'container',
    '#weight' => 4,
    '#suffix' => '</div>',
  );

  // Add button for calculation.
  $form['fields']['transportpulje_calculate'] = array(
    '#type' => 'button',
    '#value' => t('Create transport request'),
    '#weight' => 1,
    '#name' => '_transportpulje_calculate',
    '#ajax' => array(
      'callback' => '_transportpulje_form_calculate_conditions',
      'wrapper' => 'part_two',
      'method' => 'replace',
      'effect' => 'fade',
    ),
    '#executes_submit_callback' => TRUE,
  );

  // Add message wrapper.
  $form['fields']['part_two']['message_wrapper'] = array(
    '#type' => 'container',
    '#weight' => 1,
  );

  $form['fields']['part_two']['message_wrapper']['messages'] = array();

  $form['fields']['part_two']['transport'] = array(
    '#prefix' => '<div class="is-hidden">',
    '#type' => 'fieldset',
    '#title' => t('Transport information'),
    '#suffix' => '</div>',
    '#weight' => 2,
  );

  $form['fields']['part_two']['contact'] = array(
    '#prefix' => '<div class="is-hidden">',
    '#type' => 'fieldset',
    '#title' => t('Contact information'),
    '#suffix' => '</div>',
    '#weight' => 3,
  );

  // Add fields for transport information.
  $form['fields']['part_two']['transport']['expenses'] = array(
    '#title' => t('Expenses'),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['values']['expenses']) ? $form_state['values']['expenses'] : '',
  );

  $form['fields']['part_two']['transport']['participants'] = array(
    '#title' => t('Participants'),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['values']['participants']) ? $form_state['values']['participants'] : '',
  );

  $form['fields']['part_two']['transport']['date'] = array(
    '#type' => 'date_popup',
    '#date_format' => 'd/m/Y',
    '#default_value' => isset($form_state['values']['date']) ? $form_state['values']['date'] : '',
    '#weight' => 1,
  );

  // Add fields to contact information.
  $form['fields']['part_two']['contact']['name'] = array(
    '#title' => t('Name'),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['values']['name']) ? $form_state['values']['name'] : '',
  );

  $form['fields']['part_two']['contact']['email'] = array(
    '#title' => t('Email'),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['values']['email']) ? $form_state['values']['email'] : '',
  );

  $form['fields']['part_two']['contact']['email_repeat'] = array(
    '#title' => t('Repeat email'),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['values']['email_repeat']) ? $form_state['values']['email_repeat'] : '',
  );

  $form['fields']['part_two']['contact']['description'] = array(
    '#title' => t('Short description'),
    '#type' => 'textarea',
    '#default_value' => isset($form_state['values']['description']) ? $form_state['values']['description'] : '',
  );

  $form['#validate'] = array(
    '_tpf_states_required_form_validate',
    '_tpf_full_form_validate',
  );

  $form['fields']['submit_wrapper'] = array(
    '#type' => 'container',
    '#weight' => 5
  );

  $form['fields']['submit_wrapper']['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Send application'),
    '#weight' => 1,
  );

  return $form;
}

/**
 * Provide texts based on form state when part one of the form is submitted.
 *
 * @param array $form
 *   The form to apply conditions to.
 * @param array $form_state
 *   The state of the form to apply conditions to.
 *
 * @return mixed
 *   part two of the form.
 */
function _transportpulje_form_calculate_conditions(array $form, array &$form_state) {
  // If passed is true we show part two of the form.
  $passed = FALSE;

  // If part one has form errors return without doing anything else.
  if (!empty(form_get_errors())) {  
    $form_state['rebuild'] = TRUE;
    return $form['fields']['part_two'];
  }

  $form_values = $form_state['values'];
  $type = _tpf_get_type($form_values);
  // The different messages to display.
  switch ($type) {
      case 'denied_private':
      $text = variable_get('denied_private', array('value' => '', 'format' => NULL))['value'];
      break;

    case 'denied_distance':
      $text = variable_get('denied_distance', array('value' => '', 'format' => NULL))['value'];
      break;

    case 'is_private':a
      $passed = TRUE;
      $text = variable_get('free_choice', array('value' => '', 'format' => NULL))['value'];
      break;

    case 'is_not_course':
      $passed = TRUE;
      $text = variable_get('course_not_found', array('value' => '', 'format' => NULL))['value'];
      break;

    case 'has_no_district':
      $passed = TRUE;
      $text = variable_get('free_choice', array('value' => '', 'format' => NULL))['value'];
      break;

    case 'not_part_of_course_list':
      $passed = TRUE;
      $text = variable_get('free_choice', array('value' => '', 'format' => NULL))['value'];
      break;

    case 'part_of_course_list':
      $passed = TRUE;
      if (!empty($form_values['course_dropdown']) && isset($form_values['institution_name'])) {
        $institution = taxonomy_term_load($form_values['institution_name']);
        $wrapper = entity_metadata_wrapper('taxonomy_term', $institution);
        $district = $wrapper->field_tpf_district->value();
        switch ($district) {
          case 'district_1':
            $text = variable_get('district_1', array('value' => '', 'format' => NULL))['value'];
            break;

          case 'district_2':
            $text = variable_get('district_2', array('value' => '', 'format' => NULL))['value'];
            break;

          case 'district_3':
            $text = variable_get('district_3', array('value' => '', 'format' => NULL))['value'];
            break;

          case 'district_4':
            $text = variable_get('district_4', array('value' => '', 'format' => NULL))['value'];
            break;

          case 'district_5':
            $text = variable_get('district_5', array('value' => '', 'format' => NULL))['value'];
            break;
        }
      }

      break;
  }

  // If passed is true we show part two of the form.
  if ($passed) {
    $form['fields']['part_two']['#prefix'] = '<div id="part_two" class="has-passed">';
    unset($form['fields']['part_two']['transport']['#prefix']);
    unset($form['fields']['part_two']['transport']['#suffix']);
    unset($form['fields']['part_two']['contact']['#prefix']);
    unset($form['fields']['part_two']['contact']['#suffix']);
    $form['fields']['part_two']['transport']['expenses']['#required'] = TRUE;
    $form['fields']['part_two']['transport']['participants']['#required'] = TRUE;
    $form['fields']['part_two']['transport']['date']['#required'] = TRUE;
    $form['fields']['part_two']['contact']['name']['#required'] = TRUE;
    $form['fields']['part_two']['contact']['email']['#required'] = TRUE;
    $form['fields']['part_two']['contact']['email_repeat']['#required'] = TRUE;

    $form['fields']['part_two']['message_wrapper']['#prefix'] = '<div class="user-message" id="type-' . $type . '">';
    $form['fields']['part_two']['message_wrapper']['#suffix'] = '</div>';

    $form['fields']['part_two']['message_wrapper']['messages']['#markup'] = $text;
  }
  else {
    // We still show some of part two because this is what is ajaxified
    // (Ie. This is where we can display a message to the user).
    // We just only show the message.
    $form['fields']['part_two']['#prefix'] = '<div id="part_two" class="not-passed"><div class="user-message" id="type-' . $type . '">' . $text . '</div>';
  }

  $form_state['rebuild'] = TRUE;
  return $form['fields']['part_two'];
}

/**
 * Check for required field specified in the states array.
 *
 * @param array $form
 *   Custom frontend form.
 * @param array $form_state
 *   Form state of custom form.
 */
function _tpf_states_required_form_validate(array $form, array &$form_state) {
  _tpf_states_required_form_fields_validate($form['fields']['part_one']['select_course'], $form_state);
}

/**
 * Part one of the form.
 *
 * Manually validate fields required by states.
 *
 * @param array $fields
 *   Fields in part one of the form.
 * @param array $form_state
 *   Form state of custom form.
 */
function _tpf_states_required_form_fields_validate(array $fields, array &$form_state) {
  // Check for required field specified in the states array.
  foreach ($fields as $key => $field) {
    if (is_array($field) && array_key_exists('#type', $field) && $field['#type'] === 'fieldset') {
      // Recursive serch for fields.
      _tpf_states_required_form_fields_validate($field, $form_state);
    }
    elseif (is_array($field) && isset($field['#states']['required'])) {
      $required = FALSE;
      foreach ($field['#states']['required'] as $cond_field_sel => $cond_vals) {
        // Look for name= in the jquery selector - if that isn't there
        // then give up (for now).
        preg_match('/name="(.*)"/', $cond_field_sel, $matches);

        if (isset($matches[1])) {
          // Get value identifier (e.g. value, tid, target_id)
          $value_ident = key($cond_vals);

          // Loop over the values of the conditional field.
          foreach ($form_state['values'] as $cond_field_val => $value) {
            // Reverse for course_dropdown field.
            if (array_key_exists('unchecked', $cond_vals) && $form_state['values'][$matches[1]] == '0') {
              $required = TRUE;
              break 2;
            }
            // Check for a match.
            if (array_key_exists('checked', $cond_vals) && $cond_vals[$value_ident] == $form_state['values'][$matches[1]]) {
              // Now we know this field is required.
              $required = TRUE;
              break 2;
            }
          }
        }
      }

      if ($required) {
        $field_name = $field['#name'];
        if (empty($form_state['values'][$field_name])) {
          form_set_error($field_name, t(':field is a required field', array(':field' => $field['#title'])));
        }
      }
    }
  }

  // Set som form errors based on form state.
  if ($form_state['values']['institution_type'] == 'tpf_school' && empty($form_state['values']['institution_grade'])) {
    form_set_error('institution_grade', t(':field is a required field', array(':field' => t('Select grade'))));
  }

  if ($form_state['values']['course_not_found'] == 1 && (empty($form_state['values']['street']) || empty($form_state['values']['postal_code']) || empty($form_state['values']['city']))) {
    form_set_error('course_address', t(':field is a required field', array(':field' => t('Course Address'))));
  }
}

/**
 * Validate function to run before submitting the entire form.
 *
 * @param array $form
 *   Form state of custom form.
 * @param array $form_state
 *   Form state of custom form.
 */
function _tpf_full_form_validate(array $form, array &$form_state) {
  $error = FALSE;
  // Get all fields.
  $form_groups = array(
    array('part_one', 'select_course'),
    array('part_one', 'select_institution'),
    array('part_two', 'transport'),
    array('part_two', 'contact'),
  );
  $form_fields = array();
  foreach ($form_groups as $groups) {
    foreach ($form['fields'][$groups[0]][$groups[1]] as $field) {
      if (is_array($field) && isset($field['#name'])) {
        $form_fields[$field['#name']] = $field;
      }
    }
  }
  // The dreaded date field has no title.
  // We don't set it in form since that will make two titles appear.
  $form_fields['date']['#title'] = t('Date');

  if ($form_state['clicked_button']['#name'] == 'op') {
    $required_fields = _tpf_validate_all_required($form_state);
    if (!empty($required_fields)) {
      foreach ($required_fields as $field_name) {
        form_set_error($field_name, t(':field is a required field', array(':field' => $form_fields[$field_name]['#title'])));
      }
      $error = TRUE;
    }

    // Provide specific field validations.
    if (_tpf_validate_expenses($form_state)) {
      form_set_error('expenses', t(':field must be integer or decimal', array(':field' => $form_fields['expenses']['#title'])));
      $error = TRUE;
    }

    if (_tpf_validate_email_address($form_state)) {
      form_set_error('email', t(':field_1 must be a valid email address', array(':field_1' => $form_fields['email']['#title'])));
      $error = TRUE;
    }

    if (_tpf_validate_emails($form_state)) {
      form_set_error('email_repeat', t(':field_1 and :field_2 must be alike', array(':field_1' => $form_fields['email']['#title'], ':field_2' => $form_fields['email_repeat']['#title'])));
      $error = TRUE;
    }

    if (_tpf_validate_participants($form_state)) {
      form_set_error('participants', t(':field must be an integer', array(':field' => $form_fields['participants']['#title'])));
      $error = TRUE;
    }

    // Add js on form validation error, so we show part two.
    if ($error) {
      drupal_add_js(drupal_get_path('module', 'transportpulje_form') . '/js/transportpulje_form_validation_error.js');
    }
  }
}

/**
 * Validate several fields for required.
 *
 * @param array $form_state
 *   Form state of custom form.
 *
 * @return array
 *   Array of empty field names that are required.
 */
function _tpf_validate_all_required(array $form_state) {
  $error_field_names = array();

  if ($form_state['values']['course_not_found']) {
    unset($form_state['values']['course_dropdown']);
  }
  else {
    unset($form_state['values']['course_what']);
    unset($form_state['values']['course_description']);
    unset($form_state['values']['course_address']);
  }

  // We don't require all fields.
  unset($form_state['values']['course_not_found']);
  unset($form_state['values']['institution_grade']);
  unset($form_state['values']['description']);
  unset($form_state['values']['distance_calc_failed']);

  foreach ($form_state['values'] as $key => $value) {
    if (empty($value) && $value != '0') {
      $error_field_names[] = $key;
    }
  }

  return $error_field_names;
}

/**
 * Validate expenses for numeric.
 *
 * @param array $form_state
 *   Form state of custom form.
 *
 * @return bool
 *   True if expenses is not numeric.
 */
function _tpf_validate_expenses(array $form_state) {
  $formated_expenses = str_replace(',', '.', $form_state['values']['expenses']);
  return(is_numeric($formated_expenses)) ? FALSE : TRUE;
}

/**
 * Validate email fields / Email repeat check.
 *
 * @param array $form_state
 *   Form state of custom form.
 *
 * @return bool
 *   True if input does not look like an email.
 */
function _tpf_validate_email_address(array $form_state) {
  return(filter_var($form_state['values']['email'], FILTER_VALIDATE_EMAIL)) ? FALSE : TRUE;
}

/**
 * Validate email fields / Email repeat check.
 *
 * @param array $form_state
 *   Form state of custom form.
 *
 * @return bool
 *   True if email and repeat email differ.
 */
function _tpf_validate_emails(array $form_state) {
  return($form_state['values']['email'] == $form_state['values']['email_repeat']) ? FALSE : TRUE;
}

/**
 * Validate participants field for integer.
 *
 * @param array $form_state
 *   Form state of custom form.
 *
 * @return bool
 *   True if input is not an integer.
 */
function _tpf_validate_participants(array $form_state) {
  return(filter_var($form_state['values']['participants'], FILTER_VALIDATE_INT)) ? FALSE : TRUE;
}

/**
 * Modify the course dropdown list.
 *
 * @param array $courses
 *   The courses in the dropdown list.
 *
 * @return mixed
 *   A modified array of courses.
 */
function _tpf_modify_course_dropdown(array $courses) {
  // Cache the dropdown list.
  if (!isset($courses)) {
    $cache = cache_get('tpf_dropdown_data');
    if ($cache && REQUEST_TIME < $cache->expire) {
      $courses = $cache->data;
    }
    else {
      // 15 mins.
      cache_set('tpf_dropdown_data', $courses, 'cache', time() + 900);
    }
  }

  // Remove youth courses and create a modified list of nodes for the dropdown.
  $youth_term_id = key(taxonomy_get_term_by_name('Ungdomsuddannelse', 'target_group'));
  $modified_list['course'] = array();
  $results = db_select('field_data_field_target_group', 'f')
    ->fields('f', array('entity_id', 'field_target_group_tid'))
    ->condition('entity_type', 'node')
    ->condition('bundle', 'course')
    ->condition('entity_id', array_keys($courses['course']), 'IN')
    ->execute();

  foreach ($results as $result) {
    $node_wrapper = entity_metadata_wrapper('node', $result->entity_id);
    $excluded = $node_wrapper->field_tpf_exclude->value();
    // If youth term or excluded by checkbox we don't want to display it.
    if ($result->field_target_group_tid != $youth_term_id && $excluded != TRUE) {
      // If a title for the course already exists in the modified list
      // we want to add target group to title.
      if ($match = array_search($courses['course'][$result->entity_id], $modified_list['course'])) {

        // Fetch the matching nodes.
        $matched_node_wrapper = entity_metadata_wrapper('node', $match);

        // Fetch the respective nodes target groups.
        $new_node_target_group = taxonomy_term_load($node_wrapper->field_target_group->tid->value())->name;
        $matched_node_target_group = taxonomy_term_load($matched_node_wrapper->field_target_group->tid->value())->name;

        // Add new node with modified title.
        $modified_list['course'][$result->entity_id] = $courses['course'][$result->entity_id] . ' (' . $new_node_target_group . ')';

        // Modify existing nodes title.
        $modified_list['course'][$match] = $courses['course'][$result->entity_id] . ' (' . $matched_node_target_group . ')';
      }
      // Else just add the nodes title.
      else {
        // Fetch nodes location setting.
        $modified_list['course'][$result->entity_id] = $courses['course'][$result->entity_id];
      }
    }
  }

  // Cleanup array.
  foreach ($modified_list['course'] as $key => $value) {
    $modified_list['course'][$key] = trim(html_entity_decode($value));
  }

  // Sort alphabetically.
  asort($modified_list['course']);

  return $modified_list['course'];
}

/**
 * Submission handler for the custom application form.
 *
 * @param array $form
 *   The custom application form.
 * @param array $form_state
 *   Form state of custom form.
 */
function transportpulje_form_add_application_submit(array $form, array &$form_state) {
  // Check which button attempts to submit the form.
  if ($form_state['clicked_button']['#name'] == 'op') {
    // Create node entity.
    $entityform = entity_create('entityform', array(
      'uid' => 0,
      'type' => "transportpulje_form",
      'created' => time(),
      'changed' => time(),
      'language' => LANGUAGE_NONE,
    ));

    // We simplify our lifes using Entity API.
    $wrapper = entity_metadata_wrapper('entityform', $entityform);
    $form_state['values']['course_dropdown'];

    // Set address from either selected node or user provided values.
    $form_address = t('ERROR - NO VALID ADDRESS FOUND');
    if (isset($form_state['values']['street']) && isset($form_state['values']['postal_code']) && isset($form_state['values']['city'])) {
      $form_address = $form_state['values']['street'] . ', ' . $form_state['values']['postal_code'] . ' ' . $form_state['values']['city'];
    }

    // Set the fields.
    if ($form_state['values']['course_not_found'] == 0) {
      $wrapper->field_tpf_course_select = $form_state['values']['course_dropdown'];
    }
    $wrapper->field_tpf_course_not_found = $form_state['values']['course_not_found'];
    $wrapper->field_tpf_what_course = $form_state['values']['course_what'];
    $wrapper->field_tpf_purpose_course = $form_state['values']['course_description'];
    $wrapper->field_tpf_address = $form_address;
    $wrapper->field_tpf_institution_type = $form_state['values']['institution_type'];
    $wrapper->field_tpf_institution = $form_state['values']['institution_name'];
    $wrapper->field_tpf_grade = $form_state['values']['institution_grade'];
    $wrapper->field_tpf_expense = str_replace(',', '.', $form_state['values']['expenses']);
    $wrapper->field_tpf_participants = $form_state['values']['participants'];
    $wrapper->field_tpf_date = strtotime($form_state['values']['date']);
    $wrapper->field_tpf_name = $form_state['values']['name'];
    $wrapper->field_tpf_email = $form_state['values']['email'];
    $wrapper->field_tpf_email_repeat = $form_state['values']['email_repeat'];
    $wrapper->field_tpf_message = $form_state['values']['description'];
    $wrapper->field_tpf_status = ($form_state['values']['distance_calc_failed']) ? 'awaiting_distance_calc_failed' : 'awaiting';
    $wrapper->field_tpf_address_variation = _tpf_address_variation($form_state['values']);
    $wrapper->field_tpf_backend_submission = FALSE;

    $wrapper->save();

    _transportpulje_form_notify($wrapper, 'on_submit_user');
    _transportpulje_form_notify($wrapper, 'on_submit_admin');

    // Set redirect.
    $form_state['redirect'] = '/transport_application/sent';
  }
}

/**
 * Check if the values in the form correspond to the node selected.
 *
 * @param array $values
 *   The values collected from form state.
 *
 * @return bool
 *   True if course is selected and street, postal code and city vary from node.
 */
function _tpf_address_variation(array $values) {
  $ret = FALSE;
  if (!empty($values['course_dropdown']) && !empty($values['street']) && !empty($values['postal_code']) && !empty($values['city'])) {
    $node = node_load($values['course_dropdown']);
    if ($node->location['street'] == $values['street'] && $node->location['postal_code'] == $values['postal_code'] && $node->location['city'] == $values['city']) {
      return $ret;
    }
    else {
      $ret = TRUE;
    }
  }
  return $ret;
}
