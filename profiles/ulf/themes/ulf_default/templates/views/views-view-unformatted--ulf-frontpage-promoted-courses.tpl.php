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
<div class="teaser--list">
  <?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
  <?php endforeach; ?>
</div>
<a href="/dagtilbud" class="is-daycare teaser--list-button"><?php print t('View all daycare courses');?></a>
<a href="/grundskole" class="is-school teaser--list-button"><?php print t('View all school courses');?></a>
<a href="/ungdomsuddannelse" class="is-youth teaser--list-button"><?php print t('View all youth courses');?></a>
<a href="/kurser" class="is-course teaser--list-button"><?php print t('View all courses');?></a>