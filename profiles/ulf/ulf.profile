<?php
/**
 * @file
 * The installation profile which is called after the profile have been enabled
 * so .install is called first.
 */

// Initialise profiler.
!function_exists('profiler_v2') ? require_once 'libraries/profiler/profiler.inc' : FALSE;
profiler_v2('ulf');

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
if (!function_exists("system_form_install_configure_form_alter")) {
  function system_form_install_configure_form_alter(&$form, $form_state) {
    $form['site_information']['site_name']['#default_value'] = 'ulf';
  }
}

/**
 * Implements hook_form_alter().
 *
 * Select the current install profile by default.
 */
if (!function_exists("system_form_install_select_profile_form_alter")) {
  function system_form_install_select_profile_form_alter(&$form, $form_state) {
    foreach ($form['profile'] as $key => $element) {
      $form['profile'][$key]['#value'] = 'ulf';
    }
  }
}

/**
 * Implements hook_form_alter().
 */
function ulf_form_alter(&$form, &$form_state, $form_id) {
  // Process all forms during installation except the Drupal default
  // configuration form.
  if (defined('MAINTENANCE_MODE') && MAINTENANCE_MODE == 'install' &&
    $form_id != 'install_configure_form') {
    array_walk_recursive($form, '_ulf_remove_form_requirements');
  }
}

/**
 * Implements hook_install_tasks().
 *
 * As this function is called early and often, we have to maintain a cache or
 * else the task specifying a form may not be available on form submit.
 */
function ulf_install_tasks(&$install_state) {
  $tasks = variable_get('ulf_install_tasks', array());
  //print_r($install_state);
  //print_r($tasks);
  if (!empty($tasks)) {
    // Allow task callbacks to be located in an include file.
    foreach ($tasks as $task) {
      if (isset($task['file'])) {
        require_once DRUPAL_ROOT . '/' . $task['file'];
      }
    }
  }

  // Clean up if were finished.
  if ($install_state['installation_finished']) {
    variable_del('ulf_install_tasks');
  }

  include_once 'libraries/profiler/profiler_api.inc';


  $ret = array(
    // Add task to select provider and extra ulf modules.
    'ulf_theme_selection_form' => array(
      'display_name' => st('Theme selection'),
      'display' => TRUE,
      'type' => 'form',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    ),

    // Add task to select provider and extra ulf modules.
    'ulf_module_selection_form' => array(
      'display_name' => st('Module selection and configuration'),
      'display' => TRUE,
      'type' => 'form',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    ),

    // Enable modules.
    'ulf_module_enable' => array(
      'display_name' => st('Enable modules'),
      'display' => TRUE,
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'type' => 'batch',
    ),

    // Set variables.
    'ulf_set_variables' => array(
      'display_name' => st('Set variables'),
      'display' => TRUE,
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'type' => 'batch',
    ),

    // Setup taxonomies.
    'ulf_fetch_terms' => array(
      'display_name' => st('Setup taxonomies'),
      'display' => TRUE,
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'type' => 'batch',
    ),

    // Import ulf translations.
    'ulf_import_ulf_translations' => array(
      'display_name' => st('Import translations'),
      'display' => TRUE,
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'type' => 'batch',
    ),

    // Add content.
    'ulf_create_basic_content' => array(
      'display_name' => st('Create basic content'),
      'display' => TRUE,
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'type' => 'batch',
    ),
  ) + $tasks + array('profiler_install_profile_complete' => array());

  return $ret;
}


/**
 * Implements hook_install_tasks_alter().
 *
 * Remove default locale imports.
 */
function ulf_install_tasks_alter(&$tasks, $install_state) {
  // Remove core steps for translation imports.
  unset($tasks['install_import_locales']);
  unset($tasks['install_import_locales_remaining']);

  // Callback for language selection.
  $tasks['install_select_locale']['function'] = 'ulf_locale_selection';
}


/**
 * Set default language to english.
 */
function ulf_locale_selection(&$install_state) {
  $install_state['parameters']['locale'] = 'en';
}


/**
 * Fetch ulf install tasks from modules implementing hook_ulf_install_tasks().
 *
 * This install task is invoked when Drupal is fully functional.
 */
function ulf_fetch_ulf_install_tasks(&$install_state) {
  $ulf_tasks = module_invoke_all('ulf_install_tasks');
  variable_set('ulf_install_tasks', $ulf_tasks);
}


/**
 * Function to remove all required attributes from a form element array.
 */
function _ulf_remove_form_requirements(&$value, $key) {
  // Set required attribute to false if set.
  if ($key === '#required') {
    $value = FALSE;
  }
}

/**
 * Implements hook_form().
 *
 * Theme selection form.
 */
function ulf_theme_selection_form($form, &$form_state) {
  $themes = list_themes();
  $theme_select = array();
  foreach($themes as $key => $value){
    $theme_select[$value->name] = $value->info['name'];
  }

  $form['themes'] = array(
    '#title' => st('Select your Ulf theme'),
    '#type' => 'fieldset',
    '#description' => st('Select the theme you want to use.'),
  );

  $form['themes']['theme_selection'] = array(
    // Title left empty to create more space in the ui.
    '#title' => '',
    '#type' => 'radios',
    '#options' => $theme_select,
    '#default_value' => isset($theme_select['ulf']) ? $theme_select['ulf'] : 1,
  );

  // Submit the selections.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Select theme'),
  );

  return $form;
}


/**
 * Submit handler that selects a theme for ulf.
 */
function ulf_theme_selection_form_submit($form, &$form_state) {
  // Get form values.
  $values = $form_state['values'];

  // Disable all themes.
  $themes = list_themes();
  $disable_themes = array();
  foreach($themes as $key => $value){
    $disable_themes[] = $value->name;
  }

  theme_disable($disable_themes);


  // Enable desired themes and set seven as admin.
  $enable = array(
    'theme_default' => $values['theme_selection'],
    'admin_theme' => 'ulf_admin',
  );
  theme_enable($enable);

  foreach ($enable as $var => $theme) {
    if (!is_numeric($var)) {
      variable_set($var, $theme);
    }
  }

  // Use administration theme on nodes
  variable_set('node_admin_theme', '1');
}


/**
 * Installation task that handle selection of provider and modules.
 */
function ulf_module_selection_form($form, &$form_state) {
  // Optional modules.
  $modules = array(
    'googleanalytics' => st('Google analytics'),
    'mailchimp_signup' => st('Mailchimp'),
    'autosave' => st('Autosave'),
    'secure_permissions_data' => st('Secure permissions'),
    'ulf_track_mail' => st('Ulf track mail'),
    'ulf_pdf' => st('PDF module'),
    'ulf_cookie_compliance' => st('ULF cookie compliance module'),
    'ulf_course_provider_news' => st('Course provider news'),
  );

  $form['modules'] = array(
    '#title' => st('Select ulf extras'),
    '#type' => 'fieldset',
    '#description' => st('Select optional ulf extension.'),
  );

  $form['modules']['modules_selection'] = array(
    // Title left empty to create more space in the ui.
    '#title' => '',
    '#type' => 'checkboxes',
    '#options' => $modules,
    '#default_value' => array(
      'ulf_pdf',
      'ulf_track_mail',
      'secure_permissions_data'
    ),
  );

  $form['modules']['terms'] = array(
    '#title' => st('Use ULF default terms'),
    '#type' => 'checkbox',
    '#default_value' => TRUE,
    '#description' => st('The default terms include target groups, subjects, ages, classes, etc.'),
  );


  // Search settings
  $form['search'] = array(
    '#type' => 'fieldset',
    '#title' => st('Search settings'),
    '#description' => st('Select the search settings to use'),
  );

  $search_settings = array();
  $list = system_rebuild_module_data();
  $keys = array_keys($list);
  foreach ($keys as $key) {
    if (strpos($key, 'search_settings')) {
      $search_settings[$key] = $list[$key]->info['name'];
    }
  }

  $form['search']['search_selection'] = array(
    // Title left empty to create more space in the ui.
    '#title' => '',
    '#type' => 'radios',
    '#required' => TRUE,
    '#options' => $search_settings,
    '#default_value' => array('ulf_search_settings'),
  );

  // Map settings
  $form['map'] = array(
    '#type' => 'fieldset',
    '#title' => st('Map settings'),
    '#description' => st('Define map settings. The google service is used when creating and editing content. You can bypass the map setup now and configure it later by visiting /admin/config/services/gmap'),
  );

  // Map settings
  $form['map']['api_key'] = array(
    '#type' => 'textfield',
    '#title' => st('API Key'),
    '#description' => st('To obtain an API key follow the steps described here:') . ' <a href="https://developers.google.com/maps/documentation/javascript/get-api-key" target="_blank">https://developers.google.com/maps/documentation/javascript/get-api-key</a>',
    '#size' => 60,
  );

  // Map settings
  $form['map']['starting_point'] = array(
    '#type' => 'textfield',
    '#title' => st('Map starting point'),
    '#description' => st('A lat,long coordinate, seperated by comma. In a format similar to 56.130999,10.173044'),
    '#size' => 60,
  );

  // Submit the selections.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Enable modules'),
  );

  // Validate and submit.
  $form['#submit'][] = 'ulf_module_selection_form_submit';

  return $form;
}

/**
 * Submit handler that enables the modules.
 */
function ulf_module_selection_form_submit($form, &$form_state) {
  // We depend on core system module.
  require_once DRUPAL_ROOT . '/modules/system/system.admin.inc';

  $values = $form_state['values'];
  $module_list = array();

  // Get list of selected modules.
  if (!empty($values['modules_selection'])) {
    $module_list += array_filter($values['modules_selection']);
    $module_list['ulf_search_settings'] = 'ulf_search_settings';
  }

  // Set lat/long and api key for maps.
  $latlong = variable_get('gmap_default');
  $latlong['latlong'] = $values['starting_point'];
  $latlong['zoom'] = '10';
  variable_set('gmap_default', $latlong);
  variable_set('gmap_api_key', $values['api_key']);

  // Store selection to batch them in the next task.
  variable_set('ulf_module_selected', $module_list);

  // Set whether to import default terms or not.
  if (!empty($values['terms'])) {
    variable_set('ulf_import_terms', $values['terms']);
  }
}


/**
 * Enable selected ulf modules as a batch process.
 */
function ulf_module_enable(&$install_state) {
  $modules = variable_get('ulf_module_selected', array());
  $operations = ulf_module_list_as_operations($modules);

  $batch = array(
    'title' => st('Installing additional functionality'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'ulf') . '/ulf.install_callbacks.inc',
  );

  return $batch;
}

/**
 * Set variables.
 */
function ulf_set_variables(&$install_state) {
  $modules = variable_get('ulf_module_selected', array());
  variable_del('ulf_module_selected');

  // Enable modules placed in sites/[sitename]/modules folder.
  $existing_modules = drupal_system_listing("/\\.module\$/", "modules", 'name', 0);
  foreach ($existing_modules as $existing_module) {
    if($existing_module->uri) {
      if (strpos($existing_module->uri, 'sites/') !== false) {
        $modules[$existing_module->name] = $existing_module->name;
      }
    }
  }

  variable_set('secure_permissions_disable_forms', 1);
  variable_set('autosave_period', 120);
  variable_set('autosave_course', 1);
  variable_set('autosave_course_educators', 1);
  variable_set('l10n_update_check_frequency', '7');
  variable_set('print_css', '%t/css/print.css');
  variable_set('print_sourceurl_enabled', 0);
  variable_set('print_footer_options', '0');
  variable_set('print_urls', 0);
  variable_set('print_urls_anchors', 0);
  
  // Disable workbench block.
  $blocks_updated = db_update('block')
  ->fields(array(
    'region' => -1,
    'weight' => 0,
  ))
    ->condition('module', 'workbench', '=')
    ->execute();

  // Set better field descriptions.
  variable_set('better_field_descriptions_default_entity', 'node');
  $fields = [];
  $bundles = ['html_block', 'course_educators', 'news', 'static_page', 'course', 'news_course_provider'];
  foreach ($bundles as $bundle) {
    $field_info = field_info_instances('node', $bundle);
    $fields[$bundle] = [];
    foreach (array_keys($field_info) as $key) {
      if($field_info[$key]['display']['default']['type'] != 'hidden') {
        $fields[$bundle][$key] = $key;
      }
    }
    $fields[$bundle]['title'] = 'title';
  }
  variable_set('better_field_descriptions_settings', $fields);

  // Run features revert.
  features_revert(array('ulf_taxonomies' => array('field_instance')));
}


/**
 * Enable selected ulf modules as a batch process.
 */
  function ulf_fetch_terms(&$install_state) {
  $import_terms = variable_get('ulf_import_terms');
  // Return if we don't want default terms.
  if(!$import_terms) {
    return FALSE;
  }

  // Add import of ulf translations.
  $operations = array();
  $operations[] = array('_ulf_import_tax_topic', array());
  $operations[] = array('_ulf_import_tax_target_group', array());
  $operations[] = array('_ulf_import_tax_target_group_sub', array());
  $operations[] = array('_ulf_import_tax_subjects_primary_school', array());
  $operations[] = array('_ulf_import_tax_subjects_youth_one', array());
  $operations[] = array('_ulf_import_tax_subjects_youth_two', array());
  $operations[] = array('_ulf_import_tax_offer_type', array());
  $operations[] = array('_ulf_import_tax_course_relevancy_educators', array());
  $operations[] = array('_ulf_import_tax_educational_goals', array());

  $batch = array(
    'title' => st('Importing default terms'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'ulf') . '/ulf.install_callbacks.inc',
  );

  variable_del('ulf_import_terms');
  return $batch;
}


/**
 * Builds a batch module enable operations list based on module list.
 *
 * @param array $module_list
 *   List of module names to change to operations.
 *
 * @return array
 *   Batch operation list.
 */
function ulf_module_list_as_operations($module_list) {
  // Resolve the dependencies now, so that module_enable() doesn't need
  // to do it later for each individual module (which kills performance).
  // @See http://drupalcontrib.org/api/drupal/contributions!commerce_kickstart!commerce_kickstart.install/function/commerce_kickstart_install_additional_modules/7
  $files = system_rebuild_module_data();
  $modules_sorted = array();
  foreach ($module_list as $module) {
    if ($files[$module]->requires) {
      // Create a list of dependencies that haven't been installed yet.
      $dependencies = array_keys($files[$module]->requires);
      $dependencies = array_filter($dependencies, 'ulf_filter_dependencies');
      // Add them to the module list.
      $module_list = array_merge($module_list, $dependencies);
    }
  }
  $module_list = array_unique($module_list);
  foreach ($module_list as $module) {
    $modules_sorted[$module] = $files[$module]->sort;
  }
  arsort($modules_sorted);

  $operations = array();
  foreach ($modules_sorted as $module => $weight) {
    $operations[] = array(
      '_ulf_enable_module',
      array(
        $module,
        $files[$module]->info['name'],
      ),
    );
  }

  return $operations;
}


/**
 * Translation callback.
 *
 * @param string $install_state
 *   An array of information about the current installation state.
 *
 * @return array
 *   List of batches.
 */

function ulf_import_ulf_translations(&$install_state) {
  // Enable danish language.
  include_once DRUPAL_ROOT . '/includes/locale.inc';
  locale_add_language('da', NULL, NULL, NULL, '', NULL, TRUE, TRUE);

  $operations = array();

  // Get all translation files
  $translation_dir = variable_get('l10n_update_download_store', 'sites/all/translations');
  $files = file_scan_directory($translation_dir, '/.*\.po$/');
  foreach ($files as $file) {
    $operations[] = array(
      '_ulf_insert_translation',
      array(
        'default',
        '/' . $file->uri,
      ),
    );
  }
  
  $batch = array(
    'title' => st('Installing ulf translations'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'ulf') . '/ulf.install_callbacks.inc',
  );

  return $batch;
}


/**
 * Create some basic pages.
 *
 * @param string $install_state
 *   An array of information about the current installation state.
 *
 * @return array
 *   List of batches.
 */
function ulf_create_basic_content(&$install_state) {

  // Add import of ulf translations.
  $operations = array();
  $operations[] = array('_ulf_create_basic_pages', array());

  $batch = array(
    'title' => st('Creating basic content'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'ulf') . '/ulf.install_callbacks.inc',
  );

  return $batch;
}


/**
 * Helper function to filter out already enabled modules.
 *
 * @param string $dependency
 *   Name of the module that we want to check.
 *
 * @return bool
 *   If module exists and is enabled FALSE else TRUE.
 */
function ulf_filter_dependencies($dependency) {
  return !module_exists($dependency);
}
