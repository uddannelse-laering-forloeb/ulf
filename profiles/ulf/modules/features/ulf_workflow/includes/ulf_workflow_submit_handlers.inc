<?php

include_once 'ulf_workflow_mail.inc';

/**
 * Publish action for editors.
 */
function _ulf_workflow_editor_publish($form, &$form_state) {
  _ulf_workflow_set_unpublishing_date($form, $form_state);
  // Check for scheduled publishing.
  if (!empty($form_state['values']['publish_on'])) {
    $now = time();
    $datetime = DateTime::createFromFormat( 'Y-m-d H:i:s', $form_state['values']['publish_on'], new DateTimeZone('Europe/Copenhagen'));
    $publishing = $datetime->getTimestamp();
    if ($now < $publishing) {
      drupal_set_message(t('The content has been reviewed by an editor and is scheduled for publishing'));
      $form_state['values']['field_passed_review']['und'][0]['value'] = TRUE;
      $form_state['values']['workbench_moderation_state_new'] = 'needs_review';
      $form_state['values']['workbench_moderation_state_current'] = 'needs_review';
    }
    else {
      drupal_set_message(t('The content has been published'));
      $form_state['values']['workbench_moderation_state_new'] = 'published';
      $form_state['values']['workbench_moderation_state_current'] = 'published';
    }
  }
  else {
    drupal_set_message(t('The content has been published'));
    $form_state['values']['workbench_moderation_state_new'] = 'published';
    $form_state['values']['workbench_moderation_state_current'] = 'published';
  }

  // Don't attempt to send mail on node create (Form node has no nid).
  // This is handled in hook_node_insert to ensure full node entity.
  if (property_exists($form_state['node'], 'nid')) {
    _send_published_mail(
      $form['#node'],
      isset($form_state['values']['publish_on']) ? strtotime($form_state['values']['publish_on']) : FALSE
    );
  }
}

/**
 * Save action for editors.
 */
function _ulf_workflow_editor_save($form, &$form_state) {
  // See ulf_workflow_node_presave about the global scope.
  global $ulf_workflow_global_log_message;
  $ulf_workflow_global_log_message = 'writing_twice';

  _ulf_workflow_set_unpublishing_date($form, $form_state);
  if ($form['workbench_moderation_state_current']['#value'] == 'needs_review') {
    $form_state['values']['workbench_moderation_state_new'] = 'needs_review';
  } elseif ($form['workbench_moderation_state_current']['#value'] == 'published') {
    $form_state['values']['workbench_moderation_state_new'] = 'draft';
  } elseif ($form['workbench_moderation_state_current']['#value'] == 'draft') {
    $form_state['values']['workbench_moderation_state_new'] = 'draft';
  }
}

/**
 * Unpublish action for editors.
 */
function _ulf_workflow_editor_unpublish($form, &$form_state) {
  _ulf_workflow_set_unpublishing_date($form, $form_state, TRUE);
  drupal_set_message(t('The content has been unpublished'));
  $form_state['values']['workbench_moderation_state_new'] = 'draft';
  $form_state['values']['workbench_moderation_state_current'] = 'draft';
  $form_state['values']['status'] = 0;
  // Remove scheduled unpublishing.
  $form_state['values']['unpublish_on'] = NULL;
  $form_state['values']['field_passed_review']['und'][0]['value'] = FALSE;
  _send_unpublished_mail($form['#node']);
}

/**
 * Trash action for editors.
 */
function _ulf_workflow_editor_trash($form, &$form_state) {
  _ulf_workflow_set_unpublishing_date($form, $form_state, TRUE);
  drupal_set_message(t('The content has been trashed'));
  $form_state['values']['workbench_moderation_state_new'] = 'draft';
  $form_state['values']['workbench_moderation_state_current'] = 'draft';
  $form_state['values']['status'] = 0;
  $form_state['values']['field_trashed']['und'][0]['value'] = 1;
  // Remove scheduled publishing and unpublishing.
  $form_state['values']['publish_on'] = NULL;
  $form_state['values']['unpublish_on'] = NULL;
  $form_state['values']['field_passed_review']['und'][0]['value'] = FALSE;
  _send_author_content_trashed_mail($form['#node']);
}

/**
 * Send to revision action for course providers.
 */
function _ulf_workflow_course_provider_revision($form, &$form_state) {
  // See ulf_workflow_node_presave about the global scope.
  global $ulf_workflow_global_log_message;
  $ulf_workflow_global_log_message = 'writing_twice';

  _ulf_workflow_set_unpublishing_date($form, $form_state);
  drupal_set_message(t('The content has been sent to editorial review'));
  $form_state['values']['workbench_moderation_state_new'] = 'needs_review';
  // Don't attempt to send mail on node create (Form node has no nid).
  // This is handled in hook_node_insert to ensure full node entity.
  if (property_exists($form_state['node'], 'nid')) {
    _send_revision_ready_mail($form['#node']);
  }
}

/**
 * Pull revision action for course providers.
 */
function _ulf_workflow_course_provider_pull_revision($form, &$form_state) {
  _ulf_workflow_set_unpublishing_date($form, $form_state);
  drupal_set_message(t('The content has been pulled'));
  $form_state['values']['workbench_moderation_state_new'] = 'draft';
  $form_state['values']['field_passed_review']['und'][0]['value'] = FALSE;
  $form_state['values']['publish_on'] = NULL;
}

/**
 * Save action for course providers.
 */
function _ulf_workflow_course_provider_save($form, &$form_state) {
  // See ulf_workflow_node_presave about the global scope.
  global $ulf_workflow_global_log_message;
  $ulf_workflow_global_log_message = 'writing_twice';

  _ulf_workflow_set_unpublishing_date($form, $form_state);
  if ($form['workbench_moderation_state_current']['#value'] == 'needs_review') {
    $form_state['values']['workbench_moderation_state_new'] = 'needs_review';
    $form_state['values']['field_passed_review']['und'][0]['value'] = FALSE;
    $form_state['values']['publish_on'] = NULL;
  }
  elseif ($form['workbench_moderation_state_current']['#value'] == 'published') {
    // Course providers cannot publish their own changes, instead create a draft.
    drupal_set_message(t('Your changes have been saved as a draft'));
    $form_state['values']['workbench_moderation_state_new'] = 'draft';
    $form_state['values']['field_passed_review']['und'][0]['value'] = FALSE;
    $form_state['values']['publish_on'] = NULL;
  }
  elseif ($form['workbench_moderation_state_current']['#value'] == 'draft') {
    $form_state['values']['workbench_moderation_state_new'] = 'draft';
    $form_state['values']['field_passed_review']['und'][0]['value'] = FALSE;
    $form_state['values']['publish_on'] = NULL;
  }
}

/**
 * Publish action for course providers.
 */
function _ulf_workflow_course_provider_publish($form, &$form_state) {
  _ulf_workflow_set_unpublishing_date($form, $form_state);
  // Check for scheduled publishing.
  if (!empty($form_state['values']['publish_on'])) {
    $now = time();
    $datetime = DateTime::createFromFormat( 'Y-m-d h:i:s', $form_state['values']['publish_on'], new DateTimeZone('Europe/Copenhagen'));
    $publishing = $datetime->getTimestamp();
    if ($now < $publishing) {
      drupal_set_message(t('The content is scheduled for publishing publishing'));
      $form_state['values']['field_passed_review']['und'][0]['value'] = TRUE;
      $form_state['values']['workbench_moderation_state_new'] = 'needs_review';
      $form_state['values']['workbench_moderation_state_current'] = 'needs_review';
    }
    else {
      drupal_set_message(t('The content has been published'));
      $form_state['values']['workbench_moderation_state_new'] = 'published';
      $form_state['values']['workbench_moderation_state_current'] = 'published';
    }
  }
  else {
    drupal_set_message(t('The content has been published'));
    $form_state['values']['workbench_moderation_state_new'] = 'published';
    $form_state['values']['workbench_moderation_state_current'] = 'published';
    $form_state['values']['field_passed_review']['und'][0]['value'] = FALSE;
  }

  // Don't attempt to send mail on node create (Form node has no nid).
  // This is handled in hook_node_insert to ensure full node entity.
  if (property_exists($form_state['node'], 'nid')) {
    _send_published_mail_course_provider($form['#node']);
  }
}

/**
 * Unpublish action for course providers.
 */
function _ulf_workflow_course_provider_unpublish($form, &$form_state) {
  _ulf_workflow_set_unpublishing_date($form, $form_state, TRUE);
  drupal_set_message(t('The content has been unpublished'));
  $form_state['values']['workbench_moderation_state_new'] = 'draft';
  $form_state['values']['workbench_moderation_state_current'] = 'draft';
  // Remove scheduled unpublishing.
  $form_state['values']['unpublish_on'] = NULL;
  $form_state['values']['status'] = 0;
  $form_state['values']['field_passed_review']['und'][0]['value'] = FALSE;
}

/**
 * Trash action for course providers.
 */
function _ulf_workflow_course_provider_trash($form, &$form_state) {
  _ulf_workflow_set_unpublishing_date($form, $form_state, TRUE);
  drupal_set_message(t('The content has been trashed'));
  $form_state['values']['workbench_moderation_state_new'] = 'draft';
  $form_state['values']['workbench_moderation_state_current'] = 'draft';
  $form_state['values']['status'] = 0;
  $form_state['values']['field_trashed']['und'][0]['value'] = 1;
  $form_state['values']['field_passed_review']['und'][0]['value'] = 0;
  // Remove scheduled publishing and unpublishing.
  $form_state['values']['publish_on'] = NULL;
  $form_state['values']['unpublish_on'] = NULL;
  $form_state['values']['field_passed_review']['und'][0]['value'] = FALSE;
}

/**
 * Draft from trash action.
 */
function _ulf_workflow_draft_from_trash($form, &$form_state) {
  _ulf_workflow_set_unpublishing_date($form, $form_state);
  drupal_set_message(t('A draft has been created from trash'));
  $form_state['values']['workbench_moderation_state_new'] = 'draft';
  $form_state['values']['workbench_moderation_state_current'] = 'draft';
  $form_state['values']['status'] = 0;
  $form_state['values']['field_trashed']['und'][0]['value'] = 0;
  $form_state['values']['field_passed_review']['und'][0]['value'] = FALSE;
  $form_state['values']['publish_on'] = NULL;
  $form_state['values']['unpublish_on'] = NULL;
}
