<?php

/**
 * @file
 * A basic template for entityform entities
 *
 * Available variables:
 * - $content: An array of field items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The name of the entityform
 * - $url: The standard URL for viewing a entityform entity
 * - $page: TRUE if this is the main view page $url points too.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-profile
 *   - entityform-{TYPE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="content--main"<?php print $content_attributes; ?>>
  <?php
    hide($content['info']);
  ?>
  <div class="block--field-wrapper">
    <div class="block--field-label"><?php print t('Name'); ?></div>
    <div class="block--field-text"><?php print $elements['#entity']->field_message_name['und']['0']['value']; ?></div>
  </div>
  <div class="block--field-wrapper">
    <div class="block--field-label"><?php print t('Email'); ?></div>
    <div class="block--field-text"><?php print $elements['#entity']->field_message_email['und']['0']['value']; ?></div>
  </div>
  <div class="block--field-wrapper">
    <div class="block--field-label"><?php print t('Message'); ?></div>
    <div class="block--field-text"><?php print $elements['#entity']->field_message_body['und']['0']['value']; ?></div>
  </div>
</div>