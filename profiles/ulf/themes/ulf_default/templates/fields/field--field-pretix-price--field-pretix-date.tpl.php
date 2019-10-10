<?php
// Only show field if field_pretix_free is not set.
if (!isset($element['#object']->field_pretix_free[LANGUAGE_NONE][0]['value'])
    || !$element['#object']->field_pretix_free[LANGUAGE_NONE][0]['value']) {
	include __DIR__.'/field.tpl.php';
} ?>
