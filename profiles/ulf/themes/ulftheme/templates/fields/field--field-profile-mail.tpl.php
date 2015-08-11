<?php if (!$label_hidden): ?>
  <div class="block--field-label is-inline"<?php print $title_attributes; ?>><?php print $label ?></div>
<?php endif; ?>
<div class="block--field-text"<?php print $content_attributes; ?>>
  <?php foreach ($items as $delta => $item): ?>
    <a href="mailto:<?php print $item['#markup']?>"><?php print render($item); ?></a>
  <?php endforeach; ?>
</div>
