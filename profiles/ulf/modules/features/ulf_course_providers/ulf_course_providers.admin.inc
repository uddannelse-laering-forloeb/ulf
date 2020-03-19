<?php

/**
 * Implements hook_form_FORMID_alter().
 */
function ulf_course_providers_form__ulf_admin_panel_form_alter(&$form, &$form_state) {
  $form['ulf_users'] = array(
    '#type' => 'fieldset',
    '#title' => t('User profile'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#group' => 'ulf_admin_panel',
  );
  $form['ulf_users']['ulf_users_admin_show_authored'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show authored content on profile'),
    '#description' => t('Whether the system shows authored content on profile display'),
    '#default_value' => variable_get('ulf_users_admin_show_authored') ?? FALSE,
  );
}
