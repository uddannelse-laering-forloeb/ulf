<?php

/**
 * Create and send mail to author when new draft is published.
 *
 * @param $node
 *   The node that the mail relates to.
 */
function _send_published_mail($node, $planned = FALSE) {
  // Get author fields.
  $user = user_load($node->uid);

  // Set recipient.
  $to = $user->mail;
  if ($planned) {
    _ulf_workflow_mail_send_mail('planned_publishing_author', $to, $user, $node, NULL, $planned);
  } else {
    _ulf_workflow_mail_send_mail('published_mail_author', $to, $user, $node);
  }
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
function _send_user_edited_mail($user, $user_changes) {
  // Set recipient.
  $to = !empty(variable_get('email_workflow_recipient')) ? variable_get('email_workflow_recipient') : variable_get('mimemail_mail');

  _ulf_workflow_mail_send_mail('user_edited_mail_admin', $to, $user, NULL,
    $user_changes);
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
  return [
    'revision_ready_mail_admin' => t('Mail sent to admin(Site mail address) when a new draft is ready for revision.'),
    'published_mail_author' => t('Mail sent to author when an editor publishes the content.'),
    'unpublished_mail_author' => t('Mail sent to author when an editor unpublishes the content.'),
    'user_edited_mail_admin' => t('Mail sent to admin(Site mail address) when a user has changed its account.'),
    'trashed_mail_author' => t('Mail sent to author when an editor trashes the content.'),
    'trashed_mail_admin' => t('Mail sent to admin(Site mail address) when a user trashes their content.'),
    'content_assigned_mail' => t('Mail sent to course providers when an editor creates content and assigns it to them.'),
    'published_mail_admin' => t('Mail sent to admin when a course provider publishes content.'),
    'planned_publishing_author' => t('Mail sent when a node is planned for publishing, and not immediately published')
  ];
}

/**
 * Implements hook_mail_edit_text().
 */
function ulf_workflow_mail_edit_text($mailkey, $language) {
  $return = [];
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

The following fields were changed:
[ulf_workflow:user_changes]

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
    
    // User edited mail.
    case 'trashed_mail_admin':
      $return['subject'] = 'The organisation: [user:field_profile_name] has trashed some content';
      $return['always'] = TRUE;
      $return['body'] =
        'The organisation: [user:field_profile_name] has trashed [node:title].

This is an automated message created by [site:name].';
      break;

    // Planned publishing mail.
    case 'planned_publishing_author':
      $return['subject'] = 'Content passed review and is planned for publishing on [site:name]';
      $return['always'] = TRUE;
      $return['body'] =
        'The content: [node:title] has passed review and is planned for publishing on [ulf_workflow:publishing_date].

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
function ulf_workflow_form_mail_edit_template_form_alter(
  &$form,
  &$form_state,
  $form_id
) {
  $form['mail']['token_tree'] = [
    '#theme' => 'token_tree_link',
    '#token_types' => ['node', 'user', 'ulf_workflow'],
    '#global_types' => TRUE,
    '#click_insert' => TRUE,
  ];
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
 *
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
 * @param null $user_changes
 *   Array of User changes.
 */
function _ulf_workflow_mail_send_mail(
  $key,
  $to,
  $user,
  $node = NULL,
  $user_changes = NULL,
  $publishing_date = NULL
) {
  $module = 'ulf_workflow';
  // Get language from user obj.
  $language = _ulf_workflow_get_language_object($user->language);

  // Provide additional parameters.
  $params['user'] = $user;
  $params['node'] = $node;
  $params['user_changes'] = $user_changes;
  $params['publishing_date'] = date('d/m/Y - H:i', $publishing_date);
  drupal_mail($module, $key, $to, $language, $params);
}

/**
 * Implements hook_token_info().
 */
function ulf_workflow_token_info() {
  $info['types']['ulf_workflow'] = [
    'name' => t('Ulf workflow'),
  ];
  $info['tokens']['ulf_workflow']['user_changes'] = [
    'name' => t('User changes'),
    'description' => t("Lists the user changes."),
  ];
  $info['tokens']['ulf_workflow']['publishing_date'] = [
    'name' => t('Publishing date'),
    'description' => t("Display publishing date from form."),
  ];
  return $info;
}

/**
 * Implements hook_tokens().
 */
function ulf_workflow_tokens(
  $type,
  $tokens,
  array $data = [],
  array $options = []
) {
  $replacements = [];

  if ($type == 'ulf_workflow' && !empty($data['user_changes'])) {
    $user_changes = $data['user_changes'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'user_changes':
          $replacements[$original] = implode("\r\n", $user_changes);
          break;
      }
    }
  }
  if ($type == 'ulf_workflow' && !empty($data['publishing_date'])) {
    $publishing_date = $data['publishing_date'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'publishing_date':
          $replacements[$original] = $publishing_date;
          break;
      }
    }
  }

  return $replacements;
}

/**
 * Calculate changes to the user that should be notified for.
 *
 * @param $account
 *   The user account.
 *
 * @return array
 */
function _ulf_workflow_mail_get_user_changes($account) {
  $changes_array = [];

  $keys_to_monitor = [
    'locations',
    'field_image',
    'field_profile_description',
    'field_profile_educat_profi',
    'field_profile_entry',
    'field_profile_home_page',
    'field_profile_logo',
    'field_profile_name',
    'field_profile_phone',
    'field_profile_mail',
    'field_editor_info',
    'field_profile_map_placement',
    'field_bypass_workflow',
  ];

  $accountArray = (array) $account;
  $originalArray = (array) $account->original;

  // Figure out what fields should be notified about.
  $diff = _ulf_workflow_array_diff_assoc_recursive($accountArray,
    $originalArray);
  if (is_array($diff)) {
    foreach ($diff as $key => $value) {
      if (in_array($key, $keys_to_monitor)) {
        $addToChanges = FALSE;

        if (is_array($value)) {
          // Locations field is different from other fields.
          if ($key == 'locations' && isset($value[0])) {
            if (array_key_exists('name', $value[0]) ||
              array_key_exists('street', $value[0]) ||
              array_key_exists('city', $value[0]) ||
              array_key_exists('postal_code', $value[0])) {
              $addToChanges = TRUE;
            }
          }
          else {
            if (!array_key_exists('und', $value)) {
              continue;
            }
            else {
              foreach ($value['und'] as $entryKey => $entry) {
                if (array_key_exists('value', $entry) ||
                  array_key_exists('fid', $entry) ||
                  array_key_exists('title', $entry) ||
                  array_key_exists('url', $entry)) {
                  $addToChanges = TRUE;
                  break;
                }
              }
            }
          }
        }
        else {
          $addToChanges = TRUE;
        }

        if (!$addToChanges) {
          continue;
        }

        $info = field_info_instance('user', $key, 'user');

        if (!is_null($info)) {
          $label = $info['label'];
        }
        else {
          $label = t(ucfirst($key));
        }

        $changes_array[$key] = $label;
      }
    }

    // Get field_profile_contact from global variable set in
    // _ulf_workflow_mail_field_collection_changes since it the field collection
    // is save before the user.
    if (isset($GLOBALS['conf']['ulf_workflox_field_profile_contact_diff'])) {
      $field_profile_contact = $GLOBALS['conf']['ulf_workflox_field_profile_contact_diff'];

      $field_profile_contact_info = field_info_instance('user',
        'field_profile_contact', 'user');

      foreach ($field_profile_contact as $key => $field) {
        $info = field_info_instance('field_collection_item', $key,
          'field_profile_contact');
        $changes_array[$key] = $field_profile_contact_info['label'] . ' - ' . $info['label'];
      }
    }
  }

  return $changes_array;
}

/**
 * Set the global $conf['ulf_workflow_field_profile_contact_diff'] if the
 * field_profile_contact has changed.
 *
 * @param $entity
 *   The changed entity.
 */
function _ulf_workflow_mail_field_collection_changes($entity) {
  $entity_changes = [];

  $fields = [
    'field_contact_email' => 'value',
    'field_contact_name' => 'value',
    'field_contact_phone' => 'value',
    'field_contact_office_hours' => 'value',
    'field_contact_title' => 'value',
    'field_contact_home_page' => 'url',
  ];

  foreach ($fields as $key => $field) {
    if (
      isset($entity->{$key}) &&
      $entity->{$key}['und'][0][$field] != $entity->original->{$key}['und'][0][$field]) {
      $entity_changes[$key] = $key;
    }
  }

  global $conf;
  $conf['ulf_workflox_field_profile_contact_diff'] = $entity_changes;
}

/**
 * Recursively does an array_diff_assoc, which will calculate differences on a
 * multi-dimensional level.
 *
 * @from http://php.net/manual/en/function.array-diff-assoc.php#114297
 *
 * @param $array1
 *   First array to compare.
 * @param $array2
 *   2nd Array to compare
 *
 * @return int
 */
function _ulf_workflow_array_diff_assoc_recursive($array1, $array2) {
  foreach ($array1 as $key => $value) {
    if (is_array($value)) {
      if (!isset($array2[$key])) {
        $difference[$key] = $value;
      }
      elseif (!is_array($array2[$key])) {
        $difference[$key] = $value;
      }
      else {
        $new_diff = _ulf_workflow_array_diff_assoc_recursive($value,
          $array2[$key]);
        if ($new_diff != FALSE) {
          $difference[$key] = $new_diff;
        }
      }
    }
    elseif (!array_key_exists($key, $array2) || $array2[$key] != $value) {
      $difference[$key] = $value;
    }
  }
  return !isset($difference) ? 0 : $difference;
}


/**
 * Implements hook_mail_alter().
 *
 * Add additional recipients for admin mails related to workflow.
 */
function ulf_workflow_mail_alter(&$message) {
  $workflow_email_keys = array(
    'revision_ready_mail_admin',
    'user_edited_mail_admin',
    'trashed_mail_admin',
    'published_mail_admin',
    'register_pending_approval_admin'
  );

  if (in_array($message['key'], $workflow_email_keys)) {
    $recipients = variable_get('email_workflow_additional_recipients', '');
    $additional_recipients = implode(",", preg_split('/\r\n|\r|\n/', $recipients));
    $message['to'] = $message['to'] . ',' . $additional_recipients;
  }
}