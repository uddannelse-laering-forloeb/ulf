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
 *
 * Remove #required attribute for form elements in the installer
 * as they prevent the install profile from being run using drush
 * site-install.
 *
 * These elements will usually be added by modules implementing
 * hook_ding_install_tasks and passing a default administration form. While
 * setting elements as required in the administration is reasonable, during
 * the installation we may present the users with required form elements
 * they do not know how to handle and thus prevent them from completing the
 * installation.
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
      'display_name' => st('Module selection'),
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
    /*
        // Import ulf translations.
        'ulf_import_ulf_translations' => array(
          'display_name' => st('Import translations'),
          'display' => TRUE,
          'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
          'type' => 'batch',
        ),

        // Add extra tasks based on hook_ulf_install_task, which may be provided by
        // the selection task above.
        'ulf_fetch_ulf_install_tasks' => array(
          'display_name' => 'Configure ulf...',
          // This task should be skipped and hidden when ulf install tasks
          // have been fetched. Fetched tasks will appear instead.
          'run' => empty($tasks) ? INSTALL_TASK_RUN_IF_REACHED : INSTALL_TASK_SKIP,
          'display' => empty($tasks),
        ),
      ) + $tasks + array('profiler_install_profile_complete' => array());

      */
  );
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


  // Disable and enable the themes.
  $enable = array(
    'theme_default' => $values['theme_selection'],
    'admin_theme' => 'seven',
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
    'ulf_pdf' => st('PDF module'),
  );

  $form['modules'] = array(
    '#title' => st('Select ulf extras'),
    '#type' => 'fieldset',
    '#description' => st('Select optional ulf extension. You can always enable/disable these in the administration interface.'),
  );

  $form['modules']['modules_selection'] = array(
    // Title left empty to create more space in the ui.
    '#title' => '',
    '#type' => 'checkboxes',
    '#options' => $modules,
    '#default_value' => array(
      'ulf_pdf',
    ),
  );

  // Favicon, logo & iOS icon upload.
  // Logo settings.
  $form['logo'] = array(
    '#type' => 'fieldset',
    '#title' => st('Logo image settings'),
    '#description' => st('If toggled on, the following logo will be displayed.'),
    '#attributes' => array('class' => array('theme-settings-bottom')),
  );

  $form['logo']['default_logo'] = array(
    '#type' => 'checkbox',
    '#title' => st('Use the default logo'),
    '#default_value' => TRUE,
    '#tree' => FALSE,
    '#description' => st('Check here if you want the theme to use the logo supplied with it.'),
  );

  $form['logo']['settings'] = array(
    '#type' => 'container',
    '#states' => array(
      // Hide the logo settings when using the default logo.
      'invisible' => array(
        'input[name="default_logo"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['logo']['settings']['logo_path'] = array(
    '#type' => 'textfield',
    '#title' => st('Path to custom logo'),
    '#description' => st('The path to the file you would like to use as your logo file instead of the default logo.'),
    '#default_value' => '',
  );

  $form['logo']['settings']['logo_upload'] = array(
    '#type' => 'file',
    '#title' => st('Upload logo image'),
    '#maxlength' => 40,
    '#description' => st("If you don't have direct file access to the server, use this field to upload your logo."),
  );

  // Favicon.
  $form['favicon'] = array(
    '#type' => 'fieldset',
    '#title' => st('Shortcut icon settings'),
    '#description' => st("Your shortcut icon, or 'favicon', is displayed in the address bar and bookmarks of most browsers."),
  );

  $form['favicon']['default_favicon'] = array(
    '#type' => 'checkbox',
    '#title' => st('Use the default shortcut icon.'),
    '#default_value' => TRUE,
    '#description' => st('Check here if you want the theme to use the default shortcut icon.'),
  );

  $form['favicon']['settings'] = array(
    '#type' => 'container',
    '#states' => array(
      // Hide the favicon settings when using the default favicon.
      'invisible' => array(
        'input[name="default_favicon"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['favicon']['settings']['favicon_path'] = array(
    '#type' => 'textfield',
    '#title' => st('Path to custom icon'),
    '#description' => st('The path to the image file you would like to use as your custom shortcut icon.'),
    '#default_value' => '',
  );

  $form['favicon']['settings']['favicon_upload'] = array(
    '#type' => 'file',
    '#title' => st('Upload icon image'),
    '#description' => st("If you don't have direct file access to the server, use this field to upload your shortcut icon."),
  );

  // iOS icon.
  $form['iosicon'] = array(
    '#type' => 'fieldset',
    '#title' => st('iOS icon settings'),
    '#description' => st("Your iOS icon, is displayed at the homescreen."),
  );

  $form['iosicon']['default_iosicon'] = array(
    '#type' => 'checkbox',
    '#title' => st('Use the default iOS icon.'),
    '#default_value' => TRUE,
    '#description' => st('Check here if you want the theme to use the default iOS icon.'),
  );

  $form['iosicon']['settings'] = array(
    '#type' => 'container',
    '#states' => array(
      // Hide the favicon settings when using the default favicon.
      'invisible' => array(
        'input[name="default_iosicon"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['iosicon']['settings']['iosicon_path'] = array(
    '#type' => 'textfield',
    '#title' => st('Path to custom iOS icon'),
    '#description' => st('The path to the image file you would like to use as your custom iOS icon.'),
  );

  $form['iosicon']['settings']['iosicon_upload'] = array(
    '#type' => 'file',
    '#title' => st('Upload iOS icon image'),
    '#description' => st("If you don't have direct file access to the server, use this field to upload your iOS icon."),
    '#default_value' => '',
  );

  // Submit the selections.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Enable modules'),
  );

  // Validate and submit logo, iOS logo and favicon.
  $form['#validate'][] = 'ulf_module_selection_form_validate';
  $form['#submit'][] = 'ulf_module_selection_form_submit';

  return $form;
}


/**
 * Validate handler for ulf_module_selection_form().
 */
function ulf_module_selection_form_validate($form, &$form_state) {
  // We depend on core system module.
  require_once DRUPAL_ROOT . '/modules/system/system.admin.inc';

  $validators = array('file_validate_extensions' => array('ico png gif jpg jpeg apng svg'));

  // Check for a new uploaded favicon.
  $file = file_save_upload('iosicon_upload', $validators);
  if (isset($file)) {
    // File upload was attempted.
    if ($file) {
      // Put the temporary file in form_values so we can save it on submit.
      $form_state['values']['iosicon_upload'] = $file;
    }
    else {
      // File upload failed.
      form_set_error('iosicon_upload', t('The iOS icon could not be uploaded.'));
    }
  }

  // If the user provided a path for iOS icon file, make sure a file exists at
  // that path.
  if ($form_state['values']['iosicon_path']) {
    $path = _system_theme_settings_validate_path($form_state['values']['iosicon_path']);
    if (!$path) {
      form_set_error('iosicon_path', t('The custom iOS icon path is invalid.'));
    }
  }
}


/**
 * Submit handler that enables the modules.
 *
 * It also enabled the provider selected in the form defined above.
 * And iOS upload handling.
 */
function ulf_module_selection_form_submit($form, &$form_state) {
  // We depend on core system module.
  require_once DRUPAL_ROOT . '/modules/system/system.admin.inc';

  $values = $form_state['values'];
  $module_list = array();

  // Load existing theme settings and update theme with extra information.
  $settings = variable_get('theme_ulf_settings', array());

  // If the user uploaded a iOS icon, save it to a permanent location
  // and use it in place of the default theme-provided file.
  if ($file = $values['iosicon_upload']) {
    unset($values['iosicon_upload']);
    $filename = file_unmanaged_copy($file->uri);
    $values['ios_icon'] = 0;
    $values['ios_path'] = $filename;
    $values['toggle_iosicon'] = 1;
  }

  // If the user entered a path relative to the system files directory for
  // a logo or favicon, store a public:// URI so the theme system can handle it.
  if (!empty($values['iosicon_path'])) {
    $values['iosicon_path'] = _system_theme_settings_validate_path($values['iosicon_path']);
  }

  // Save iOS logo to theme settings.
  variable_set('theme_ulf_settings', array_merge($settings, $values));

  // Get list of selected modules.
  if (!empty($values['modules_selection'])) {
    $module_list += array_filter($values['modules_selection']);
  }

  // Store selection to batch them in the next task.
  variable_set('ulf_module_selected', $module_list);
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

  variable_del('ulf_module_selected');

  return $batch;
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
  locale_add_language('da', NULL, NULL, NULL, '', NULL, TRUE, FALSE);

  // Add import of ulf translations.
  $operations = array();
  $operations[] = array(
    '_ulf_insert_translation',
    array(
      'default',
      '/profiles/ulf/translations/da.po',
    ),
  );

  $batch = array(
    'title' => st('Installing ulf translations'),
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
