<?php
/**
 * @file
 * ulf_entityform.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function ulf_entityform_default_rules_configuration() {
  $items = array();
  $items['rules_send_email_on_end_user_message'] = entity_import('rules_config', '{ "rules_send_email_on_end_user_message" : {
      "LABEL" : "Send email on end user message",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Message" ],
      "REQUIRES" : [ "rules", "mimemail", "entityform" ],
      "ON" : { "entityform_insert" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_message_parent_node" } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "entityform:field-message-parent-node:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "parent_node" : "Parent node" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "user", "id" : [ "parent-node:author:uid" ] },
            "PROVIDE" : { "entity_fetched" : { "message_node_author" : "Message node author" } }
          }
        },
        { "mimemail" : {
            "key" : "Send email on end user message",
            "to" : "[message-node-author:field-profile-mail]",
            "from_name" : "[entityform:field-message-name]",
            "from_mail" : "[entityform:field-message-email]",
            "subject" : "Besked fra bruger p\\u00e5 [site:name]",
            "body" : "En bruger har udfyldt en kontakt formular p\\u00e5 [site:name] ([site:url])\\r\\n\\r\\n---\\r\\n\\u003Cstrong\\u003EFra:\\u003C\\/strong\\u003E [entityform:field-message-name]\\r\\n\\u003Cstrong\\u003EEmail:\\u003C\\/strong\\u003E [entityform:field-message-email]\\r\\n\\u003Cstrong\\u003EBesked:\\u003C\\/strong\\u003E\\r\\n[entityform:field-message-body]\\r\\n\\r\\n---\\r\\n\\r\\nMed venlig hilsen\\r\\n[site:name]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
