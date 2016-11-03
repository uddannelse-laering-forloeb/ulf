<?php
/**
 * @file
 * Definition of example_handler_custom_field
 */

/**
 * Provides a custom views field.
 */
class ulf_latest_moderation_handler_custom_field extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function query() {
    // do nothing -- to override the parent query.
  }

  function render($data) {
    $output = t("This field only works with node views and node revision views");
    if ($this->view->base_table == 'node_revision') {
      if (property_exists($data, 'node_node_revision_nid')) {
        $node = node_load($data->node_node_revision_nid);
        $output = $node->workbench_moderation['current']->vid;
      }
      else {
        $output = t("This field requires af nid to be present as a field");
      }
    }
    if ($this->view->base_table == 'node') {
      if (property_exists($data, 'node_nid')) {
        $node = node_load($data->node_nid);
        $output = $node->workbench_moderation['current']->vid;
      }
      else {
        $output = t("This field requires af nid to be present as a field");
      }
    }

    return $output;
  }
}