<?php
// Only show field (label) if value is true.
if (isset($element['#object']->field_pretix_free[LANGUAGE_NONE][0]['value'])
    && $element['#object']->field_pretix_free[LANGUAGE_NONE][0]['value']): ?>
  <div class="block--field-text"<?php print $content_attributes; ?>><?php print t('Free'); ?></div>
<?php endif; ?>
