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
  $form['actions']['preview_changes']['#access'] = FALSE;
  $form['field_trashed']['#access'] = FALSE;
  $form['field_passed_review']['#access'] = FALSE;
  if ($form['#node']->type == 'course' || $form['#node']->type == 'course_educators') {
    $form['scheduler_settings']['unpublish_on']['#attributes'] = array('disabled' => 'disabled');
    $form['scheduler_settings']['unpublish_on']['#description'] = t('The value of this field is set by period end date when content is saved.');
  }
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
  $current_state = $form['#node']->workbench_moderation['current']->state;
  $content_moderator = user_access('moderate content from needs_review to published');
  $has_published_version = $form['#node']->status;
  $has_scheduled_publishing = property_exists($form['#node'], 'publish_on') && $form['#node']->publish_on > 0 ? TRUE : FALSE;
  // Create array of possible actions.
  $actions = array (
    // Course provider actions.
    array (
      'name' =>'send_to_revision',
      'value' => t('Send to revision'),
      'submit_handler' => '_ulf_workflow_course_provider_revision',
      'weight' => '1',
      'access' => !$publish_permission && !$has_scheduled_publishing,
    ),
    array (
      'name' =>'pull_revision_course_provider',
      'value' => t('Remove from redaction'),
      'submit_handler' => '_ulf_workflow_course_provider_pull_revision',
      'weight' => '1',
      'access' => !$publish_permission && $current_state == 'needs_review',
    ),
    array (
      'name' =>'publish_course_provider',
      'value' => t('Publish'),
      'submit_handler' => '_ulf_workflow_course_provider_publish',
      'weight' => '2',
      'access' => $publish_permission && !$content_moderator,
    ),
    array (
      'name' =>'save_course_provider',
      'value' => t('Save'),
      'submit_handler' => '_ulf_workflow_course_provider_save',
      'weight' => '3',
      'access' => !$content_moderator && !$has_scheduled_publishing,
    ),
    array (
      'name' =>'unpublish_course_provider',
      'value' => t('Unpublish'),
      'submit_handler' => '_ulf_workflow_course_provider_unpublish',
      'weight' => '4',
      'access' => !$content_moderator && $has_published_version,
    ),
    array (
      'name' =>'trash_course_provider',
      'value' => t('Move to trash'),
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
      'access' => $content_moderator,
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
      'access' => $content_moderator && $has_published_version,
    ),
    array (
      'name' =>'trash_editor',
      'value' => t('Move to trash'),
      'submit_handler' => '_ulf_workflow_editor_trash',
      'weight' => '4',
      'access' => $content_moderator,
    )
  );

  // If content is trashed only allow "Draft from trash" as option.
  $trashed = isset($form['#node']->field_trashed['und'][0]['value']) ? $form['#node']->field_trashed['und'][0]['value'] : FALSE;
  if ($trashed) {
    $action = array (
      'name' =>'draft_from_trash',
      'value' => t('Draft from trash'),
      'submit_handler' => '_ulf_workflow_draft_from_trash',
      'weight' => '2',
      'access' => TRUE,
    );
    $form['actions'][$action['name']] = _ulf_workflow_create_action($action);
  }
  else {
    foreach ($actions as $action) {
      $form['actions'][$action['name']] = _ulf_workflow_create_action($action);
    }
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
