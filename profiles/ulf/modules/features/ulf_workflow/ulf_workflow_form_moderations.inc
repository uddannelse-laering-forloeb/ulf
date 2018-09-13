<?php

/**
 * Cleanup a node form, hide unused fields.
 */
function _ulf_workflow_cleanup_form(&$form) {
  // Disable workbench dropdown widget and revision log.
  $form['options']['workbench_moderation_state_new']['#access'] = FALSE;
  $form['options']['log']['#access'] = FALSE;
  $form['revision_information']['workbench_moderation_state_new']['#access'] = FALSE;
  $form['revision_information']['#access'] = FALSE;
  $form['actions']['submit']['#access'] = FALSE;
  $form['actions']['preview']['#access'] = FALSE;
  $form['actions']['delete']['#access'] = FALSE;
}

function _ulf_workflow_provide_add_actions(&$form) {
  $content_moderator = user_access('moderate content from needs_review to published');
  $publish_permission = _ulf_workflow_check_publish_permission();
  // Create array of possible actions.
  $actions = array (
    // Course provider actions.
    array (
      'name' =>'send_to_revision',
      'value' => t('Send to revision'),
      'submit_handler' => '_ulf_workflow_course_provider_revision',
      'weight' => '2',
      'access' => !$publish_permission,
    ),
    array (
      'name' =>'save_course_provider',
      'value' => t('Save'),
      'submit_handler' => '_ulf_workflow_course_provider_save',
      'weight' => '1',
      'access' => !$content_moderator,
    ),
    array (
      'name' =>'publish_course_provider',
      'value' => t('Publish'),
      'submit_handler' => '_ulf_workflow_course_provider_publish',
      'weight' => '1',
      'access' => $publish_permission && !$content_moderator,
    ),
    // Editor actions.
    array (
      'name' =>'publish_editor',
      'value' => t('Publish'),
      'submit_handler' => '_ulf_workflow_editor_publish',
      'weight' => '1',
      'access' => $content_moderator,
    ),
    array (
      'name' =>'save_editor',
      'value' => t('Save'),
      'submit_handler' => '_ulf_workflow_editor_save',
      'weight' => '2',
      'access' => $content_moderator,
    ),
  );

  foreach ($actions as $action) {
    $form['actions'][$action['name']] = _ulf_workflow_create_action($action);
  }
}

function _ulf_workflow_provide_edit_actions(&$form) {
  $publish_permission = _ulf_workflow_check_publish_permission();
  $current_state = $form['workbench_moderation_state_current']['#value'];
  $content_moderator = user_access('moderate content from needs_review to published');

  // Create array of possible actions.
  $actions = array (
    // Course provider actions.
    array (
      'name' =>'send_to_revision',
      'value' => t('Send to revision'),
      'submit_handler' => '_ulf_workflow_course_provider_revision',
      'weight' => '1',
      'access' => !$publish_permission,
    ),
    array (
      'name' =>'publish_course_provider',
      'value' => t('Publish'),
      'submit_handler' => '_ulf_workflow_course_provider_publish',
      'weight' => '2',
      'access' => $publish_permission && !$content_moderator && $current_state != 'published',
    ),
    array (
      'name' =>'save_course_provider',
      'value' => t('Save'),
      'submit_handler' => '_ulf_workflow_course_provider_save',
      'weight' => '3',
      'access' => !$content_moderator,
    ),
    array (
      'name' =>'unpublish_course_provider',
      'value' => t('Unpublish'),
      'submit_handler' => '_ulf_workflow_course_provider_unpublish',
      'weight' => '4',
      'access' => !$content_moderator,
    ),
    array (
      'name' =>'trash_course_provider',
      'value' => t('Trash'),
      'submit_handler' => '_ulf_workflow_course_provider_trash',
      'weight' => '5',
      'access' => !$content_moderator,
    ),
    // Editor actions.
    array (
      'name' =>'publish_editor',
      'value' => t('Publish'),
      'submit_handler' => '_ulf_workflow_editor_publish',
      'weight' => '1',
      'access' => $content_moderator && $current_state != 'published',
    ),
    array (
      'name' =>'save_editor',
      'value' => t('Save'),
      'submit_handler' => '_ulf_workflow_editor_save',
      'weight' => '2',
      'access' => $content_moderator,
    ),
    array (
      'name' =>'unpublish_editor',
      'value' => t('Unpublish'),
      'submit_handler' => '_ulf_workflow_editor_unpublish',
      'weight' => '3',
      'access' => $content_moderator && $current_state != 'draft',
    ),
    array (
      'name' =>'trash_editor',
      'value' => t('Trash'),
      'submit_handler' => '_ulf_workflow_editor_trash',
      'weight' => '4',
      'access' => $content_moderator,
    )
  );

  foreach ($actions as $action) {
    $form['actions'][$action['name']] = _ulf_workflow_create_action($action);
  }
}

function _ulf_workflow_create_action($action) {
  return $action_item = array(
    '#type' => 'submit',
    '#access' => $action['access'],
    '#value' => $action['value'],
    '#weight' => $action['weight'],
    '#submit' => array(
      $action['submit_handler'],
      'node_form_submit',
    )
  );
}

function _ulf_workflow_check_publish_permission() {
  global $user;
  $full_user = user_load($user->uid);
  $user_wrapper = entity_metadata_wrapper('user', $full_user);

  // Check if user can bypass workflow.
  // Done this way since we need clean true or false (We don't want empty when field is not filled).
  $user_bypass = $user_wrapper->field_bypass_workflow->value() == TRUE ? TRUE : FALSE;

  if (user_access('moderate content from needs_review to published') || $user_bypass) {
    return TRUE;
  }

  return FALSE;
}