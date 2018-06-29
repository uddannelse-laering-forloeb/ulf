<?php
/**
 * @file
 * ulf_base.captcha.inc
 */

/**
 * Implements hook_captcha_default_points().
 */
function ulf_base_captcha_default_points() {
  $export = array();

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'end_user_message_entityform_edit_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['end_user_message_entityform_edit_form'] = $captcha;

  return $export;
}
