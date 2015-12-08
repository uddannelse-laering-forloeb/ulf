<?php
/**
 * @file
 * ulf_base.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function ulf_base_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access broken links report'.
  $permissions['access broken links report'] = array(
    'name' => 'access broken links report',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'course provider' => 'course provider',
      'editor' => 'editor',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access mailchimp signup pages'.
  $permissions['access mailchimp signup pages'] = array(
    'name' => 'access mailchimp signup pages',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'mailchimp_signup',
  );

  // Exported permission: 'access own broken links report'.
  $permissions['access own broken links report'] = array(
    'name' => 'access own broken links report',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access toolbar'.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      'course provider' => 'course provider',
      'editor' => 'editor',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'administer custom content'.
  $permissions['administer custom content'] = array(
    'name' => 'administer custom content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'ctools_custom_content',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(),
    'module' => 'locale',
  );

  // Exported permission: 'administer linkchecker'.
  $permissions['administer linkchecker'] = array(
    'name' => 'administer linkchecker',
    'roles' => array(),
    'module' => 'linkchecker',
  );

  // Exported permission: 'administer mailchimp'.
  $permissions['administer mailchimp'] = array(
    'name' => 'administer mailchimp',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'mailchimp',
  );

  // Exported permission: 'administer mailchimp signup entities'.
  $permissions['administer mailchimp signup entities'] = array(
    'name' => 'administer mailchimp signup entities',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'mailchimp_signup',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'user',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'course provider' => 'course provider',
      'editor' => 'editor',
    ),
    'module' => 'user',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in course_relevancy_educators'.
  $permissions['delete terms in course_relevancy_educators'] = array(
    'name' => 'delete terms in course_relevancy_educators',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in educational_goals'.
  $permissions['delete terms in educational_goals'] = array(
    'name' => 'delete terms in educational_goals',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in elementary_school'.
  $permissions['delete terms in elementary_school'] = array(
    'name' => 'delete terms in elementary_school',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in offer_type'.
  $permissions['delete terms in offer_type'] = array(
    'name' => 'delete terms in offer_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in primary_school'.
  $permissions['delete terms in primary_school'] = array(
    'name' => 'delete terms in primary_school',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in subjects_primary_school'.
  $permissions['delete terms in subjects_primary_school'] = array(
    'name' => 'delete terms in subjects_primary_school',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in subjects_youth'.
  $permissions['delete terms in subjects_youth'] = array(
    'name' => 'delete terms in subjects_youth',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in target_group'.
  $permissions['delete terms in target_group'] = array(
    'name' => 'delete terms in target_group',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in target_group_sub'.
  $permissions['delete terms in target_group_sub'] = array(
    'name' => 'delete terms in target_group_sub',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in topic'.
  $permissions['delete terms in topic'] = array(
    'name' => 'delete terms in topic',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit link settings'.
  $permissions['edit link settings'] = array(
    'name' => 'edit link settings',
    'roles' => array(),
    'module' => 'linkchecker',
  );

  // Exported permission: 'edit terms in course_relevancy_educators'.
  $permissions['edit terms in course_relevancy_educators'] = array(
    'name' => 'edit terms in course_relevancy_educators',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in educational_goals'.
  $permissions['edit terms in educational_goals'] = array(
    'name' => 'edit terms in educational_goals',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in elementary_school'.
  $permissions['edit terms in elementary_school'] = array(
    'name' => 'edit terms in elementary_school',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in offer_type'.
  $permissions['edit terms in offer_type'] = array(
    'name' => 'edit terms in offer_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in primary_school'.
  $permissions['edit terms in primary_school'] = array(
    'name' => 'edit terms in primary_school',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in subjects_primary_school'.
  $permissions['edit terms in subjects_primary_school'] = array(
    'name' => 'edit terms in subjects_primary_school',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in subjects_youth'.
  $permissions['edit terms in subjects_youth'] = array(
    'name' => 'edit terms in subjects_youth',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in target_group'.
  $permissions['edit terms in target_group'] = array(
    'name' => 'edit terms in target_group',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in target_group_sub'.
  $permissions['edit terms in target_group_sub'] = array(
    'name' => 'edit terms in target_group_sub',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in topic'.
  $permissions['edit terms in topic'] = array(
    'name' => 'edit terms in topic',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'course provider' => 'course provider',
      'editor' => 'editor',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'course provider' => 'course provider',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'course provider' => 'course provider',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'course provider' => 'course provider',
      'editor' => 'editor',
    ),
    'module' => 'system',
  );

  return $permissions;
}
