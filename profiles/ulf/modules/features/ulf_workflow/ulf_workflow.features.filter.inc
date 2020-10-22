<?php

/**
 * @file
 * ulf_workflow.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function ulf_workflow_filter_default_formats() {
  $formats = array();

  // Exported format: E-mail.
  $formats['email'] = array(
    'format' => 'email',
    'name' => 'E-mail',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_html' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <u> <strong> <blockquote> <ul> <ol> <li> <p> <br> <h2> <h3><sub><sup>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
      'strip_emojis' => array(
        'weight' => -40,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -38,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
