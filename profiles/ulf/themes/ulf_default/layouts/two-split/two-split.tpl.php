<?php
/**
 * @file
 * Template for a 4 element panel layout.
 *
 * This template provides a 4 element layout.
 * This is the template used for displaying courses.
 * Element alpha and gamma get their inner wrapper here. Other elements get their inner wrapper from their element (ie. views, panes etc.)
 *
 * The inner classes are node specific.
 * Alpha and gamma, floats left, beta and delta floats right in an 8-4 zen grid system.
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
<?php
  $image = variable_get('ulf_newsletter_header_image', '');
  $file = file_load($image);
;?>
<div class="layout-newsletter-archive">
  <div class="layout-inner">
    <div class="layout-element-alpha">
      <div class="layout-element-alpha-inner">
        <div class="content">
          <div class="content--image">
            <div class="field--title"><?php print t('Newsletter archive');?></div>
            <?php if(isset($file->uri)) : ?>
              <div class="field--image">
                <div class="field--image-items">
                  <img src="<?php print image_style_url('node_display', $file->uri); ?>" alt="">
                </div>
              </div>
            <?php endif;?>
          </div>
          <div class="content---main">
            <?php if(!empty ($content['alpha'])) : ?>
              <?php print $content['alpha']; ?>
            <?php endif;?>
          </div>
          <div class="content--meta">
            <?php if(!empty ($content['beta'])) : ?>
              <?php print $content['beta']; ?>
            <?php endif;?>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
