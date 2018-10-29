<?php

/**
 * Create and send mail to author when new draft is published.
 *
 * @param $node
 *   The node that the mail relates to.
 */
function _send_published_mail($node) {
  // Get author fields.
  $user = user_load($node->uid);

  // Set recipient.
  $to = $user->mail;

  _ulf_workflow_mail_send_mail('published_mail_author', $to, $user, $node);
}

/**
 * Create and send mail to admin when course provider publishes content.
 *
 * @param $node
 *   The node that the mail relates to.
 */
function _send_published_mail_course_provider($node) {
  // Get author fields.
  $user = user_load($node->uid);

  // Set recipient.
  $to = !empty(variable_get('email_workflow_recipient')) ? variable_get('email_workflow_recipient') : variable_get('mimemail_mail');

  _ulf_workflow_mail_send_mail('published_mail_admin', $to, $user, $node);
}

/**
 * Create and send mail to author when content is unpublished.
 *
 * @param $node
 *   The node that the mail relates to.
 */
function _send_unpublished_mail($node) {
  // Get author fields.
  $user = user_load($node->uid);

  // Set recipient.
  $to = $user->mail;

  _ulf_workflow_mail_send_mail('unpublished_mail_author', $to, $user, $node);
}


/**
 * Create and send mail to editor when new draft needs review.
 *
 * @param $node
 *   The node that the mail relates to.
 */
function _send_revision_ready_mail($node) {
  // Get author fields.
  $user = user_load($node->uid);

  // Set recipient.
  $to = !empty(variable_get('email_workflow_recipient')) ? variable_get('email_workflow_recipient') : variable_get('mimemail_mail');

  _ulf_workflow_mail_send_mail('revision_ready_mail_admin', $to, $user, $node);
}


/**
 * Create and send mail to editor when a user has been changed.
 *
 * @param $user
 *   The user that the mail relates to.
 */
function _send_user_edited_mail($account, $user) {
  // Set recipient.
  $to = !empty(variable_get('email_workflow_recipient')) ? variable_get('email_workflow_recipient') : variable_get('mimemail_mail');

  _ulf_workflow_mail_send_mail('user_edited_mail_admin', $to, $account);
}


/**
 * Create and send mail to author when an element has been trashed.
 *
 * @param $node
 *   The node that the mail relates to.
 */
function _send_author_content_trashed_mail($node) {
  // Get author fields.
  $user = user_load($node->uid);

  // Set recipient.
  $to = $user->mail;

  _ulf_workflow_mail_send_mail('trashed_mail_author', $to, $user, $node);
}


/**
 * Create and send mail to content provider when an element has been assigned to them.
 *
 * @param $node
 *   The node that the mail relates to.
 */
function _send_content_assigned_mail($node) {
  // Get author fields.
  $user = user_load($node->uid);

  // Set recipient.
  $to = $user->mail;

  _ulf_workflow_mail_send_mail('content_assigned_mail', $to, $user, $node);
}

/**
 * Implements hook_mailkeys().
 */
function ulf_workflow_mailkeys() {
  return array(
    'revision_ready_mail_admin' => t('Mail sent to admin(Site mail address) when a new draft is ready for revision.'),
    'published_mail_author' => t('Mail sent to author when an editor publishes the content.'),
    'unpublished_mail_author' => t('Mail sent to author when an editor unpublishes the content.'),
    'user_edited_mail_admin' => t('Mail sent to admin(Site mail address) when a user has changed its account.'),
    'trashed_mail_author' => t('Mail sent to author when an editor trashes the content.'),
    'content_assigned_mail' => t('Mail sent to course providers when an editor creates content and assigns it to them.'),
    'published_mail_admin' => t('Mail sent to admin when a course provider publishes content.'),
  );
}


/**
 * Implements hook_mail_edit_text().
 */
function ulf_workflow_mail_edit_text($mailkey, $language) {
  $return = array();
  switch ($mailkey) {

    // Revision ready mail.
    case 'published_mail_admin':
      $return['subject'] = 'New content has been published by [user:field_profile_name]';
      $return['always'] = TRUE;
      $return['body'] =
        '[user:field-profile-name] has published new content.

This is an automated message created by [site:name].';
      break;

    // Revision ready mail.
    case 'revision_ready_mail_admin':
      $return['subject'] = 'A new draft is ready for publishing by [user:field_profile_name]';
      $return['always'] = TRUE;
      $return['body'] =
        '[user:field-profile-name] has marked a draft ready for publishing.

This is an automated message created by [site:name].';
      break;

    // Content published mail.
    case 'published_mail_author':
      $return['subject'] = 'Content you sent to revision has been published by an admin on [site:name]';
      $return['always'] = TRUE;
      $return['body'] =
        'Some content you sent to revision has now been published on [site:name].

Go to [site:login-url] and login to see what has been published.

This is an automated message created by [site:name].';
      break;
    
    // Content unpublished mail.
    case 'unpublished_mail_author':
      $return['subject'] = 'Content that was published on [site:name] has now been unpublished';
      $return['always'] = TRUE;
      $return['body'] =
        'Some content that was published on [site:name] has now been unpublished.

Go to [site:login-url] and login to see what has been unpublished.

This is an automated message created by [site:name].';
      break;

    // Content assigned to course provider mail.
    case 'content_assigned_mail':
      $return['subject'] = 'New content was created on your behalf by an admin on [site:name]';
      $return['always'] = TRUE;
      $return['body'] =
        'An admin created new content on your behalf on [site:name].

Go to [site:login-url] and login to see what was created.

This is an automated message created by [site:name].';
      break;

    // User edited mail.
    case 'user_edited_mail_admin':
      $return['subject'] = 'The organisation: [user:field_profile_name] has made changes to its profile';
      $return['always'] = TRUE;
      $return['body'] =
        'The organisation: [user:field_profile_name] has made changes to its profile [current-date:short].

Go to [user:url] to see the changes.

This is an automated message created by [site:name].';
      break;

    // User edited mail.
    case 'trashed_mail_author':
      $return['subject'] = 'Content you created has been trashed by an admin on [site:name]';
      $return['always'] = TRUE;
      $return['body'] =
        'The content: [node:title] has been trashed by an admin.

This is an automated message created by [site:name].';
      break;

  }
  return $return;
}

/**
 * Implements hook_form_FORMID_alter().
 *
 * Alter the token tree in mail edit functionality to represent nodes and users.
 */
function ulf_workflow_form_mail_edit_template_form_alter(&$form, &$form_state, $form_id) {
  $form['mail']['token_tree'] = array(
    '#theme' => 'token_tree_link',
    '#token_types' => array('node', 'user'),
    '#global_types' => TRUE,
    '#click_insert' => TRUE,
  );
}

/**
 * Implements hook_mail_edit_token_types().
 */
function ulf_workflow_mail_edit_token_types($mailkey) {
  return user_mail_edit_token_types($mailkey);
}

/**
 * Get language object from string.
 *
 * @param $language
 *  The language code.
 * @return mixed
 *   An array of languages.
 */
function _ulf_workflow_get_language_object($language = 'da') {
  $installed_languages = language_list();
  return $installed_languages[$language];
}

/**
 * Send the mail
 *
 * @param $key
 *  The mail key to identify the mail by.
 * @param $to
 *  The email address to send to.
 * @param $user
 *   The user that the mail relates to.
 * @param null $node
 *   The node that the mail relates to.
 */
function _ulf_workflow_mail_send_mail($key, $to, $user, $node = NULL) {
  $module = 'ulf_workflow';
  // Get language from user obj.
  $language = _ulf_workflow_get_language_object($user->language);

  // Provide additional parameters.
  $params['user'] = $user;
  $params['node'] = $node;
  drupal_mail($module, $key, $to, $language, $params);
}