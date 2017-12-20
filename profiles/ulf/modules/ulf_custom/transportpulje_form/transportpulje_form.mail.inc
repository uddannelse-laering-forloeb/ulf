<?php

/**
 * @file
 * transportpulje_form.mail.inc
 * 
 * Handle the sending of mails.
 */

/**
 * Create mail template.
 *
 * @param $wrapper
 * @return string
 */
function _transportpulje_form_build_mail_confirmation($wrapper) {
  global $language;

  $application = '<h2>';
  $application .= t('Transport application copy', array(), array('langcode' => $language->language));
  $application .= ':</h2>';

  $application .= '<h3>';
  $application .= t('Course', array(), array('langcode' => $language->language));
  $application .= ':</h3>';

  $application .= '<p>';

  if($wrapper->field_tpf_course_not_found->value()) {
    $application .= '<strong>';
    $application .= t('What is the course', array(), array('langcode' => $language->language));
    $application .= ':</strong> ';
    $application .= $wrapper->field_tpf_what_course->value();
    $application .= '<br/>';

    $application .= '<strong>';
    $application .= t('Describe the learning target', array(), array('langcode' => $language->language));
    $application .= ':</strong> ';
    $application .= $wrapper->field_tpf_purpose_course->value();
    $application .= '<br/>';
  } else {
    $course = $wrapper->field_tpf_course_select->value();

    $application .= '<strong>';
    $application .= t('Course', array(), array('langcode' => $language->language));
    $application .= ':</strong> ';
    $application .= $course->title;
    $application .= '<br/>';
  }

  $application .= '<strong>';
  $application .= t('Address', array(), array('langcode' => $language->language));
  $application .= ':</strong> ';
  $application .= $wrapper->field_tpf_address->value();
  $application .= '<br/>';

  $application .= '</p>';

  $application .= '<h3>';
  $application .= t('Transport information', array(), array('langcode' => $language->language));
  $application .= ':</h3>';

  $application .= '<p>';

  $application .= '<strong>';
  $application .= t('Expenses', array(), array('langcode' => $language->language));
  $application .= ':</strong> ';
  $application .= 'kr. ' . $wrapper->field_tpf_expense->value();
  $application .= '<br/>';

  $application .= '<strong>';
  $application .= t('Participants', array(), array('langcode' => $language->language));
  $application .= ':</strong> ';
  $application .= $wrapper->field_tpf_participants->value();
  $application .= '<br/>';

  $application .= '<strong>';
  $application .= t('Date', array(), array('langcode' => $language->language));
  $application .= ':</strong> ';
  $application .= date('d/m/Y', $wrapper->field_tpf_date->value());
  $application .= '<br/>';

  $application .= '</p>';

  $application .= '<h3>';
  $application .= t('Contact information', array(), array('langcode' => $language->language));
  $application .= ':</h3>';

  $application .= '<p>';

  $application .= '<strong>';
  $application .= t('Name', array(), array('langcode' => $language->language));
  $application .= ':</strong> ';
  $application .= $wrapper->field_tpf_name->value();
  $application .= '<br/>';

  $application .= '<strong>';
  $application .= t('Email', array(), array('langcode' => $language->language));
  $application .= ':</strong> ';
  $application .= $wrapper->field_tpf_email->value();
  $application .= '<br/>';

  $application .= '<strong>';
  $application .= t('Short description', array(), array('langcode' => $language->language));
  $application .= ':</strong> ';
  $application .= $wrapper->field_tpf_message->value();
  $application .= '<br/>';

  $application .= '</p>';

  return $application;
}

/**
 * Add the different cases in which to send mail.
 *
 * @param $wrapper
 * @param $action
 */
function _transportpulje_form_notify($wrapper, $action) {
  global $language;
  $to = variable_get('site_mail');
  $params = array();
  switch ($action) {
    case 'on_submit_user':
      $params['subject'] = t('Transport application recieved', array(), array('langcode' => $language->language));
      $params['body'] = '<h2>' . t('Transport application recieved', array(), array('langcode' => $language->language)) . '</h2>';
      $params['body'] .= variable_get('confirmation_email', array(
        'value' => '',
        'format' => NULL
      ))['value'];
      $params['body'] .= _transportpulje_form_build_mail_confirmation($wrapper);

      $to = $wrapper->field_tpf_email->value();
      break;
    case 'on_submit_admin':
      $params['subject'] = t('Transport application recieved', array(), array('langcode' => $language->language));
      $params['body'] = '<h2>' . t('Transport application recieved', array(), array('langcode' => $language->language)) . '</h2>';
      $params['body'] .= variable_get('notify_admin_email', array(
        'value' => '',
        'format' => NULL
      ))['value'];
      $params['body'] .= _transportpulje_form_build_mail_confirmation($wrapper);

      $to = variable_get('secretary_email');
      break;
    case 'on_change_accepted':
      $params['subject'] = t('Request accepted', array(), array('langcode' => $language->language));
      $params['body'] = '<h2>' . t('Transport application request accepted', array(), array('langcode' => $language->language)) . '</h2>';
      $params['body'] .= variable_get('request_accepted_email', array(
        'value' => '',
        'format' => NULL
      ))['value'];

      $to = $wrapper->field_tpf_email->value();
      break;
    case 'on_change_refused':
      $params['subject'] = t('Request denied', array(), array('langcode' => $language->language));
      $params['body'] = '<h2>' . t('Transport application request denied', array(), array('langcode' => $language->language)) . '</h2>';
      $params['body'] .= variable_get('request_denied_email', array(
        'value' => '',
        'format' => NULL
      ))['value'];

      $to = $wrapper->field_tpf_email->value();
      break;
  }

  drupal_mail('transportpulje_form', 'notification', $to, $language->language, $params);
}

/**
 * Implements hook_mail().
 *
 * Alter mail.
 */
function transportpulje_form_mail($key, &$message, $params) {
  switch ($key) {
    case 'notification':
      $message['subject'] = $params['subject'];
      $message['body'] = $params['body'];
      break;
  }
}