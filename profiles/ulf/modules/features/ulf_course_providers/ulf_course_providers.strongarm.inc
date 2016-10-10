<?php
/**
 * @file
 * ulf_course_providers.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ulf_course_providers_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_user__user';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'redirect' => array(
          'weight' => '11',
        ),
        'account' => array(
          'weight' => '0',
        ),
        'timezone' => array(
          'weight' => '12',
        ),
        'locale' => array(
          'weight' => '10',
        ),
        'wysiwyg' => array(
          'weight' => '9',
        ),
        'mimemail' => array(
          'weight' => '8',
        ),
        'googleanalytics' => array(
          'weight' => '13',
        ),
      ),
      'display' => array(
        'summary' => array(
          'default' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
        ),
        'mimemail' => array(
          'default' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_user__user'] = $strongarm;

  return $export;
}
