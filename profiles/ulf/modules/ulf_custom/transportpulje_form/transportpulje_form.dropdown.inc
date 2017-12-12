<?php

/**
 * Fetch node from dropdown.
 *
 * @param $node
 * @return mixed
 */
function _tpf_fetch_address($node) {
  return $node;
}

/**
 * Return html of address display.
 *
 * @param $node
 */
function _tpf_fetch_address_output($node) {
  $location = $node->location;
  if (!empty($location['street']) && !empty($location['postal_code']) && !empty($location['city'])){
    print '<div id="course_dropdown_address">' . $location['street'] . '<br>' . $location['postal_code'] . '<br>' . $location['city'] . '</div>';
  }
}