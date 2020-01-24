<?php
/**
 * @file
 * Template for a 5 element panel layout.
 *
 * This template provides a 5 element layout.
 * This is the template used for displaying frontpage.
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
 *   - $content['epsilon']: Fifth element
 */
?>

<div class="layout-frontpage">
  <div class="layout-inner">
    <?php if(!empty ($content['alpha'])) : ?>
      <div class="layout-element-alpha <?php (empty($display->panels['alpha'])) ? print 'is-empty' : ''; ?>">
        <div class="layout-element-alpha-inner">
          <?php print $content['alpha']; ?>
        </div>
      </div>
    <?php endif;?>
    <?php if(!empty ($content['beta'])) : ?>
      <div class="layout-element-beta <?php (empty($display->panels['beta'])) ? print 'is-empty' : '' ?>">
        <div class="layout-element-beta-inner">
          <?php print $content['beta']; ?>
        </div>
      </div>
    <?php endif;?>
    <?php if(!empty ($content['gamma'])) : ?>
      <div class="layout-element-gamma <?php (empty($display->panels['gamma'])) ? print 'is-empty' : '' ?>">
        <div class="layout-element-gamma-inner">
          <?php print $content['gamma']; ?>
        </div>
      </div>
    <?php endif;?>
    <?php if(!empty ($content['delta'])) : ?>
      <div class="layout-element-delta <?php (empty($display->panels['delta'])) ? print 'is-empty' : '' ?>">
        <div class="layout-element-delta-inner">
          <?php print $content['delta']; ?>
        </div>
      </div>
    <?php endif;?>
    <?php if(!empty ($content['epsilon'])) : ?>
      <div class="layout-element-epsilon <?php (empty($display->panels['epsilon'])) ? print 'is-empty' : '' ?>">
        <div class="layout-element-epsilon-inner">
          <?php print $content['epsilon']; ?>
        </div>
      </div>
    <?php endif;?>
  </div>
</div>
