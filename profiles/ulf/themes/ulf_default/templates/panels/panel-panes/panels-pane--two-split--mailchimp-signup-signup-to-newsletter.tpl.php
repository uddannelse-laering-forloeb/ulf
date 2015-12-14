<?php
/**
 * @file panels-pane.tpl.php
 * Main panel pane template
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 *
 * - $provided_class: Represents the class provided in the panel pane.
 */
?>
<div class="block--light">
  <h2 class="block--header"><?php print t('Newsletter'); ?></h2>
  <div class="block--content">
    <div class="block--field-text">
      <ul class="nav--static-pages is-node">
        <?php print render($content); ?>
      </ul>
    </div>
  </div>
</div>
