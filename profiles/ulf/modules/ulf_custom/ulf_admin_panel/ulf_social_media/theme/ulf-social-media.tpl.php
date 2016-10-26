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
 * - $icon_path: Path to modules social media icons
 */
?>
<div class="social-media">
  <?php if(!empty($facebook)) : ?>
    <a class="social-media--icon" href="<?php print $facebook; ?>"><img alt="facebook" src="<?php print $icon_path . '/facebook.svg'; ?>"/></a>
  <?php endif; ?>
  <?php if(!empty($instagram)) : ?>
    <a class="social-media--icon" href="<?php print $instagram; ?>"><img alt="instagram" src="<?php print $icon_path . '/instagram.svg'; ?>"/></a>
  <?php endif; ?>
  <?php if(!empty($twitter)) : ?>
    <a class="social-media--icon" href="<?php print $twitter; ?>"><img alt="twitter" src="<?php print $icon_path . '/twitter.svg'; ?>"/></a>
  <?php endif; ?>
  <?php if(!empty($linkedin)) : ?>
    <a class="social-media--icon" href="<?php print $linkedin; ?>"><img alt="linkedin" src="<?php print $icon_path . '/linkedin.svg'; ?>"/></a>
  <?php endif; ?>
</div>
