<?php
/**
 * @file
 * ulf_mails.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ulf_mails_default_rules_configuration() {
  $items = array();
  $items['rules_send_mail_on_course_publishing'] = entity_import('rules_config', '{ "rules_send_mail_on_course_publishing" : {
    "LABEL" : "Send mail on course publishing",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "mail" ],
    "REQUIRES" : [ "workbench_moderation", "rules", "mimemail" ],
    "ON" : { "workbench_moderation_after_moderation_transition" : [] },
    "IF" : [
      { "contents_current_state" : { "node" : [ "node" ], "moderation_state" : "published" } },
      { "NOT contents_previous_state" : { "node" : [ "node" ], "moderation_state" : "published" } }
    ],
    "DO" : [
      { "entity_fetch" : {
          "USING" : { "type" : "user", "id" : [ "node:author:uid" ] },
          "PROVIDE" : { "entity_fetched" : { "entity_user" : "Fetched user" } }
        }
      },
      { "mimemail" : {
          "key" : "publishing_mail",
          "to" : "[entity-user:mail]",
          "from_name" : "[site:name]",
          "from_mail" : "[site:mail]",
          "subject" : "Your content on [site:name] has been published",
          "body" : "\u003Cp\u003EThe content u003Ca href=\u0022[node:url]\u0022\u003E[node:title]\u003C\/a\u003E has been published by a site editor.\u003C\/p\u003E\r\n\r\n\u003Cp\u003ESincerely \u003Ca href=\u0022[site:url]\u0022\u003E[site:name]\u003C\/a\u003E\u003C\/p\u003E ",
          "language" : [ "node:language" ]
          }
        }
      ]
    }
  }');
  return $items;
}
