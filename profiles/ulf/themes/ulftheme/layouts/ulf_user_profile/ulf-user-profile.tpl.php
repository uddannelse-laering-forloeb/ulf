<?php
/**
 * @file
 * Template for a 4 element panel layout.
 *
 * This template provides a 4 element layout.
 * This is the template used for displaying courses.
 * Element alpha and gamma get their inner wrapper here. Other elements get their inner wrapper from their element (ie. views, panes etc.)
 *
 * @see ../sass/layout/_layout.scss
 *
 *
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['alpha']: First element
 *   - $content['beta']: Second element
 *   - $content['gamma']: Third element
 *   - $content['delta']: Fourth element
 */
?>
<div class="layout-alternative">
  <div class="layout-inner">
    <div class="layout-element-alpha">
      <div class="layout-element-inner">
        <div class="page-content"><?php print $content['alpha']; ?></div>
      </div>
    </div>

    <div class="layout-element-beta">
      <div class="layout-element-inner"><?php print $content['beta']; ?></div>
    </div>

    <div class="layout-element-gamma">
      <div class="layout-element-inner">
        <?php print $content['gamma']; ?>
      </div>
    </div>
  </div>
</div>
