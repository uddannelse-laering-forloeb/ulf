<?php
/**
 * @file
 * transportpulje_form.dropdown.inc
 *
 * The course dropdown adds a div with content that is hidden with css and used to populate fields with js.
 */

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
    print '<div id="course_dropdown_street">' . $location['street'] . '</div><div id="course_dropdown_postal">' . $location['postal_code'] . '</div><div id="course_dropdown_city">' . $location['city'] . '</div>';
  }
}