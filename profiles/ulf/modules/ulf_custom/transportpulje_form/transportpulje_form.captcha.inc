<?php
/**
 * @file
 * transportpulje_form.captcha.inc
 */

/**
 * Implements hook_captcha_default_points().
 */
function transportpulje_form_captcha_default_points() {
  $export = array();

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'transportpulje_form_entityform_edit_form';
  $captcha->module = '';
  $captcha->captcha_type = 'default';
  $export['transportpulje_form_entityform_edit_form'] = $captcha;

  return $export;
}
