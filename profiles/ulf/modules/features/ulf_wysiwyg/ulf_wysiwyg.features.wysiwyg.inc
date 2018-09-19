<?php
/**
 * @file
 * ulf_wysiwyg.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function ulf_wysiwyg_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: editor
  $profiles['editor'] = array(
    'format' => 'editor',
    'editor' => 'ckeditor',
    'settings' => array(
      'theme' => 'advanced',
      'language' => 'da',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'BulletedList' => 1,
          'Italic' => 1,
          'Format' => 1,
          'Link' => 1,
          'NumberedList' => 1,
          'ShowBlocks' => 1,
          'Source' => 1,
          'Copy' => 1,
          'Cut' => 1,
          'PasteFromWord' => 1,
          'RemoveFormat' => 1,
          'Redo' => 1,
          'Undo' => 1,
        ),
        'drupal_path' => array(
          'Link' => 1,
        ),
      ),
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'block_formats' => 'h3',
      'css_setting' => 'theme',
      'css_path' => '',
      'simple_source_formatting' => 0,
      'resize_enabled' => 1,
      'toolbarLocation' => 'top',
      'forcePasteAsPlainText' => 1,
      'stylesSet' => '',
    ),
    'preferences' => array(
      'add_to_summaries' => NULL,
      'default' => NULL,
      'show_toggle' => NULL,
      'user_choose' => NULL,
      'version' => NULL,
    ),
    'name' => 'formateditor',
  );

  return $profiles;
}
