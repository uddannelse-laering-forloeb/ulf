<?php
/**
 * @file
 * Definition of ulf_workflow_handler_latest_log_message.
 */
/**
 * Display latest log message.
 */
class ulf_workflow_handler_latest_log_message extends views_handler_field {
  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['vid'] = array(
      'table' => 'node_revision',
      'field' => 'vid',
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Default options form.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Renders the field handler.
   */
  function render($values) {
    $nid = $values->node_node_revision_nid;
    $query = db_select('node_revision', 'n');
    $query->fields('n', array('nid', 'log'));
    $query->condition('n.nid', $nid, '=');
    $query->condition('n.log', '', '<>');
    $query->orderby('n.vid','DESC');
    $query->range(0,1);
    $result = $query->execute()->fetchCol(1);
    return $result[0];
  }
}