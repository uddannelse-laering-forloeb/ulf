<?php

/**
 * @file
 * Better field descriptions theme implementation of a pure text description.
 *
 * Available variables:
 * - $variables['label']: The label of the description.
 * - $variables['description']: The description itself.
 */
?>
<div class="better-descriptions">
  <?php if (empty($variables['label']) == FALSE): ?>
    <label ><?php print ($variables['label']); ?></label>
  <?php endif; ?>
    <div class="description"><?php print ($variables['description']); ?></div>
</div>
