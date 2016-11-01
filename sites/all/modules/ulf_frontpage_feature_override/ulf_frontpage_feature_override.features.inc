<?php
/**
 * @file
 * ulf_frontpage_feature_override.features.inc
 */

/**
 * Implements hook_default_page_manager_pages_alter().
 */
function ulf_frontpage_feature_override_default_page_manager_pages_alter(&$data) {
  if (isset($data['front'])) {
    $data['front']->default_handlers['page_front__panel_context_c65e2e76-874a-4cef-80fd-a7843cba6a9a']->conf['display']->content['new-8c08e917-a5e6-4b7d-a136-35061a9a0b58']->panel = 'beta'; /* WAS: 'alpha' */
    $data['front']->default_handlers['page_front__panel_context_c65e2e76-874a-4cef-80fd-a7843cba6a9a']->conf['display']->content['new-b3960982-6674-462a-beed-faccfdf4ce89']->panel = 'alpha'; /* WAS: 'beta' */
    $data['front']->default_handlers['page_front__panel_context_c65e2e76-874a-4cef-80fd-a7843cba6a9a']->conf['display']->panels['alpha'][0] = 'new-b3960982-6674-462a-beed-faccfdf4ce89'; /* WAS: 'new-8c08e917-a5e6-4b7d-a136-35061a9a0b58' */
    $data['front']->default_handlers['page_front__panel_context_c65e2e76-874a-4cef-80fd-a7843cba6a9a']->conf['display']->panels['beta'][0] = 'new-8c08e917-a5e6-4b7d-a136-35061a9a0b58'; /* WAS: 'new-b3960982-6674-462a-beed-faccfdf4ce89' */
  }
}
