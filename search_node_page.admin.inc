<?php

function search_node_page_admin_overview($form, &$form_state) {
  $form = array();

  return system_settings_form($form);
}