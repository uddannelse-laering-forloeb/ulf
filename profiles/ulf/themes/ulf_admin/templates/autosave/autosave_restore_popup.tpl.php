<?php
/**
 * @file
 * Popup markup for restore form message.
 */
?>
<div id="autosave-wrapper">
</div>
<div id="autosave-splash">
    <span id="status">
      <?php print t('This form was autosaved on @date', array('@date' => $autosave['savedDate'])); ?>
    </span>
    <span id="operations">
      <?php print $ignore_link . $restore_link; ?>
    </span>
</div>
