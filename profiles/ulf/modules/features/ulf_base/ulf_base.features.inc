<?php
/**
 * @file
 * ulf_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ulf_base_image_default_styles() {
  $styles = array();

  // Exported image style: node_display.
  $styles['node_display'] = array(
    'label' => 'Node display',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1000,
          'height' => 320,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: teaser_display.
  $styles['teaser_display'] = array(
    'label' => 'Teaser display',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 752,
          'height' => 695,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_mailchimp_signup().
 */
function ulf_base_default_mailchimp_signup() {
  $items = array();
  $items['signup_to_newsletter'] = entity_import('mailchimp_signup', '{
    "name" : "signup_to_newsletter",
    "mc_lists" : { "bd5595991a" : "bd5595991a" },
    "mode" : "3",
    "title" : "Signup to newsletter",
    "settings" : {
      "path" : "newsletter\\/signup",
      "submit_button" : "Indsend",
      "confirmation_message" : "Du er nu oprettet som abonnent.",
      "destination" : "",
      "mergefields" : { "EMAIL" : {
          "name" : "Emailadresse",
          "req" : true,
          "field_type" : "email",
          "public" : true,
          "show" : true,
          "order" : "1",
          "default" : "",
          "helptext" : "",
          "size" : "25",
          "tag" : "EMAIL",
          "id" : 0
        }
      },
      "description" : "",
      "doublein" : 0,
      "send_welcome" : 0,
      "include_interest_groups" : 0
    }
  }');
  return $items;
}
