<?php
/**
 * @file
 * Social media block
 *
 * Variables:
 * - $facebook: String
 * - $instagram: String
 * - $twitter: String
 * - $linkedin: String
 * - $icon_path: Path to modules social media icons: String
 * - $show_footer: Defines whether the social media links should be displayed in footer: Boolean
 */
?>
<?php if($show_footer) : ?>
  <div class="social-media">
    <?php if(!empty($facebook)) : ?>
      <a class="social-media--icon" href="<?php print $facebook; ?>"><img alt="facebook" title="Facebook" src="<?php print $icon_path . '/facebook.svg'; ?>"/></a>
    <?php endif; ?>
    <?php if(!empty($instagram)) : ?>
      <a class="social-media--icon" href="<?php print $instagram; ?>"><img alt="instagram" title="Instagram" src="<?php print $icon_path . '/instagram.svg'; ?>"/></a>
    <?php endif; ?>
    <?php if(!empty($twitter)) : ?>
      <a class="social-media--icon" href="<?php print $twitter; ?>"><img alt="twitter" title="Twitter" src="<?php print $icon_path . '/twitter.svg'; ?>"/></a>
    <?php endif; ?>
    <?php if(!empty($linkedin)) : ?>
      <a class="social-media--icon" href="<?php print $linkedin; ?>"><img alt="linkedin" title="Linkedin" src="<?php print $icon_path . '/linkedin.svg'; ?>"/></a>
    <?php endif; ?>
  </div>
<?php endif; ?>
