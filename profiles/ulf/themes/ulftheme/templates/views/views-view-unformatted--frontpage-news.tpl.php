<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <?php print $title; ?>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
<div class="block-module--content-element-wrapper">
  <?php print $row; ?>
</div>
<?php endforeach; ?>
