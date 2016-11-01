<?php
/**
 * @file
 * ulf_frontpage_feature_override.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function ulf_frontpage_feature_override_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: page_manager_pages
  $overrides["page_manager_pages.front.default_handlers|page_front__panel_context_c65e2e76-874a-4cef-80fd-a7843cba6a9a|conf|display|content|new-8c08e917-a5e6-4b7d-a136-35061a9a0b58|panel"] = 'beta';
  $overrides["page_manager_pages.front.default_handlers|page_front__panel_context_c65e2e76-874a-4cef-80fd-a7843cba6a9a|conf|display|content|new-b3960982-6674-462a-beed-faccfdf4ce89|panel"] = 'alpha';
  $overrides["page_manager_pages.front.default_handlers|page_front__panel_context_c65e2e76-874a-4cef-80fd-a7843cba6a9a|conf|display|panels|alpha|0"] = 'new-b3960982-6674-462a-beed-faccfdf4ce89';
  $overrides["page_manager_pages.front.default_handlers|page_front__panel_context_c65e2e76-874a-4cef-80fd-a7843cba6a9a|conf|display|panels|beta|0"] = 'new-8c08e917-a5e6-4b7d-a136-35061a9a0b58';

 return $overrides;
}
