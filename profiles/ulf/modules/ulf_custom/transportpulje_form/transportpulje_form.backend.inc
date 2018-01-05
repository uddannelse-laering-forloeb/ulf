<?php

/**
 * @file
 * 
 * Code for the backend form.
 */

/**
 * Create custom backend form.
 *
 * @param array $form
 *   Custom backend form.
 * @param array $form_state
 *   Form state of the backend form.
 *
 * @return mixed
 *   The form displayed in the backend.
 */
function transportpulje_form_backend(array $form, array &$form_state) {
  $form['groups'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['email_texts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email texts'),
    '#group' => 'groups',
    '#collapsible' => FALSE,
    '#collapsed' => 0,
  );

  $form['email_texts']['notify_admin_email'] = array(
    '#type' => 'text_format',
    '#title' => t('Notification to adm. function when request is sent'),
    '#default_value' => variable_get('notify_admin_email', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 0,
  );

  $form['email_texts']['confirmation_email'] = array(
    '#type' => 'text_format',
    '#title' => t('Copy of confirmation for user'),
    '#default_value' => variable_get('confirmation_email', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 1,
  );

  $form['email_texts']['request_accepted_email'] = array(
    '#type' => 'text_format',
    '#title' => t('Request accepted'),
    '#default_value' => variable_get('request_accepted_email', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 2,
  );

  $form['email_texts']['request_denied_email'] = array(
    '#type' => 'text_format',
    '#title' => t('Request denied'),
    '#default_value' => variable_get('request_denied_email', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 3,
  );

  $form['frontend_texts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Frontend texts'),
    '#group' => 'groups',
    '#collapsible' => FALSE,
    '#collapsed' => 0,
  );

  $form['frontend_texts']['intro'] = array(
    '#type' => 'text_format',
    '#title' => t('Intro text'),
    '#default_value' => variable_get('intro', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 0,
  );

  $form['frontend_texts']['help_no_course'] = array(
    '#type' => 'textfield',
    '#title' => t('Help text "I could not find course" checkbox'),
    '#default_value' => variable_get('help_no_course'),
    '#weight' => 0,
  );

  $form['frontend_texts']['denied_distance'] = array(
    '#type' => 'text_format',
    '#title' => t('Denied for 6th grade+ because distance to course is less than 6 km.'),
    '#default_value' => variable_get('denied_distance', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 1,
  );

  $form['frontend_texts']['denied_private'] = array(
    '#type' => 'text_format',
    '#title' => t('Denied for private institution requesting funding for public only courses'),
    '#default_value' => variable_get('denied_private', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 2,
  );

  $form['frontend_texts']['confirmation'] = array(
    '#type' => 'text_format',
    '#title' => t('Request confirmed'),
    '#default_value' => variable_get('confirmation', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 3,
  );

  $form['transport_texts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Transport expenses texts'),
    '#group' => 'groups',
    '#collapsible' => FALSE,
    '#collapsed' => 0,
  );

  $form['transport_texts']['free_choice'] = array(
    '#type' => 'text_format',
    '#title' => t('Free choice of transport'),
    '#default_value' => variable_get('free_choice', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 0,
  );

  $form['transport_texts']['course_not_found'] = array(
    '#type' => 'text_format',
    '#title' => t('Course not found'),
    '#default_value' => variable_get('course_not_found', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 1,
  );

  $form['transport_texts']['districts'] = array(
    '#type' => 'fieldset',
    '#title' => t('District specific texts'),
    '#collapsible' => FALSE,
    '#collapsed' => 0,
    '#weight' => 2,
  );

  $form['transport_texts']['districts']['district_1'] = array(
    '#type' => 'text_format',
    '#title' => t('District 1'),
    '#default_value' => variable_get('district_1', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 1,
  );

  $form['transport_texts']['districts']['district_2'] = array(
    '#type' => 'text_format',
    '#title' => t('District 2'),
    '#default_value' => variable_get('district_2', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 2,
  );

  $form['transport_texts']['districts']['district_3'] = array(
    '#type' => 'text_format',
    '#title' => t('District 3'),
    '#default_value' => variable_get('district_3', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 3,
  );

  $form['transport_texts']['districts']['district_4'] = array(
    '#type' => 'text_format',
    '#title' => t('District 4'),
    '#default_value' => variable_get('district_4', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 4,
  );

  $form['transport_texts']['districts']['district_5'] = array(
    '#type' => 'text_format',
    '#title' => t('District 5'),
    '#default_value' => variable_get('district_5', array('value' => '', 'format' => NULL))['value'],
    '#format' => 'editor',
    '#weight' => 5,
  );

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other settings'),
    '#group' => 'groups',
    '#collapsible' => FALSE,
    '#collapsed' => 0,
  );

  $form['settings']['secretary_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Mail to secretariat'),
    '#default_value' => variable_get('secretary_email'),
    '#weight' => 1,
    '#size' => 30,
  );

  return system_settings_form($form);
}
