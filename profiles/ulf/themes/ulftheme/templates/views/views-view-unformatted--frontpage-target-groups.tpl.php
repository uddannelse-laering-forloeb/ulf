<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <?php if (!$id&1) : ?>
    <article class="is-odd teaser-module--<?php print $options['row_class']; ?>">
      <?php print $row; ?>
    </article>
  <?php else : ?>
    <article class="is-even teaser-module--<?php print $options['row_class']; ?>">
      <?php print $row; ?>
    </article>
  <?php endif; ?>
<?php endforeach; ?>