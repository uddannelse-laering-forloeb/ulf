<?php
/**
 * @file
 * Batch job callbacks used in the installation profile.
 */

/**
 * Enables an module.
 *
 * @param string $module
 *   The modules machine name.
 * @param string $module_name
 *   The modules human name.
 * @param array $context
 *   The context of the batch job.
 */
function _ulf_enable_module($module, $module_name, &$context) {
  module_enable(array($module), FALSE);
  $context['message'] = st('Installed %module module.', array('%module' => $module_name));
}


/**
 * Import translation into the database.
 *
 * @param string $type
 *   Type of translation.
 * @param string $translation_file
 *   File with translation.
 * @param array $context
 *   The context of the batch job.
 */
function _ulf_insert_translation($type, $translation_file, &$context) {
  $file = new stdClass();
  $file->uri = DRUPAL_ROOT . $translation_file;
  $file->filename = basename($file->uri);
  _locale_import_po($file, 'da', LOCALE_IMPORT_OVERWRITE, $type);
  $context['message'] = st('Installed %type translation.', array('%type' => $type));
}
