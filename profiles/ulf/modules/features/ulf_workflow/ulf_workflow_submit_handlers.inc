<?php

/**
 * Publish action for editors.
 */
function _ulf_workflow_editor_publish($form, &$form_state) {
    // Mail to course provider.
  $form_state['values']['workbench_moderation_state_new'] = 'published';
  $form_state['values']['workbench_moderation_state_current'] = 'published';
}

/**
 * Save action for editors.
 */
function _ulf_workflow_editor_save($form, &$form_state) {
  // If editor saves changes during review, change state to draft (Review considered done).
  // @todo Do we need an extra action for editors?
  if ($form['workbench_moderation_state_current']['#value'] == 'needs_review') {
    $form_state['values']['workbench_moderation_state_new'] = 'draft';
  } elseif ($form['workbench_moderation_state_current']['#value'] == 'published') {
    $form_state['values']['workbench_moderation_state_new'] = 'published';
  } elseif ($form['workbench_moderation_state_current']['#value'] == 'draft') {
    $form_state['values']['workbench_moderation_state_new'] = 'draft';
  }
}

/**
 * Unpublish action for editors.
 */
function _ulf_workflow_editor_unpublish($form, &$form_state) {
  // Mail to course provider.
  $form_state['values']['workbench_moderation_state_new'] = 'draft';
  $form_state['values']['workbench_moderation_state_current'] = 'draft';
  $form_state['values']['status'] = 0;
}

/**
 * Trash action for editors.
 */
function _ulf_workflow_editor_trash($form, &$form_state) {
  // Latest revision: State => Draft
  // Published state: Unpublished.
  // Trash state: Trashed
  // Mail to course provider.
  $a =1;
}

/**
 * Send to revision action for course providers.
 */
function _ulf_workflow_course_provider_revision($form, &$form_state) {
  $form_state['values']['workbench_moderation_state_new'] = 'needs_review';
  // Mail to editor.
}

/**
 * Save action for course providers.
 */
function _ulf_workflow_course_provider_save($form, &$form_state) {
  if ($form['workbench_moderation_state_current']['#value'] == 'needs_review') {
    $form_state['values']['workbench_moderation_state_new'] = 'needs_review';
  } elseif ($form['workbench_moderation_state_current']['#value'] == 'published') {
    // Course providers cannot publish their own changes, instead create a draft.
    $form_state['values']['workbench_moderation_state_new'] = 'draft';
  } elseif ($form['workbench_moderation_state_current']['#value'] == 'draft') {
    $form_state['values']['workbench_moderation_state_new'] = 'draft';
  }
}

/**
 * Publish action for course providers.
 */
function _ulf_workflow_course_provider_publish($form, &$form_state) {
  $form_state['values']['workbench_moderation_state_new'] = 'published';
  $form_state['values']['workbench_moderation_state_current'] = 'published';
}

/**
 * Unpublish action for course providers.
 */
function _ulf_workflow_course_provider_unpublish($form, &$form_state) {
  $form_state['values']['workbench_moderation_state_new'] = 'draft';
  $form_state['values']['workbench_moderation_state_current'] = 'draft';
  $form_state['values']['status'] = 0;
}

/**
 * Trash action for course providers.
 */
function _ulf_workflow_course_provider_trash($form, &$form_state) {
  // Latest revision: State => Draft
  // Published state: Unpublished.
  // Trash state: Trashed
  // Mail to course editor.
  $a =1;
}
