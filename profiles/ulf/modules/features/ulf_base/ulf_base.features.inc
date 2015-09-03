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
      6 => array(
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => 1000,
          'height' => 320,
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'node_display',
        ),
        'weight' => -11,
      ),
      10 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1000,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: teaser_display.
  $styles['teaser_display'] = array(
    'label' => 'Teaser display',
    'effects' => array(
      11 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 420,
        ),
        'weight' => 2,
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
      "doublein" : 1,
      "send_welcome" : 1,
      "include_interest_groups" : 1
    }
  }');
  return $items;
}
