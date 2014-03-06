<?php
/**
 * @file
 * ulf_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ulf_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function ulf_search_default_search_api_index() {
  $items = array();
  $items['default'] = entity_import('search_api_index', '{
    "name" : "Default",
    "machine_name" : "default",
    "description" : null,
    "server" : "server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "text" },
        "field_collection_price" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_count" : { "type" : "integer" },
        "field_duration" : { "type" : "integer" },
        "field_duration_unit" : { "type" : "string" },
        "field_educational_goals" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_educational_material" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_facilities" : { "type" : "list\\u003Cstring\\u003E" },
        "field_free" : { "type" : "boolean" },
        "field_inspirational_material" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_offer_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_period_full_year" : { "type" : "boolean" },
        "field_purpose" : { "type" : "text" },
        "field_subject" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_subjects_primary_school" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_subjects_youth" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target_group" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_target_group_sub" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_teaser" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "author:field_profile_name" : { "type" : "text" },
        "field_full_description:value" : { "type" : "text" },
        "field_offer_type:name" : { "type" : "text" },
        "field_subject:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_tags:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_target_group:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_target_group_sub:name" : { "type" : "list\\u003Ctext\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_educational_goals" : true,
              "field_educational_material" : true,
              "field_facilities" : true,
              "field_purpose" : true,
              "field_subject" : true,
              "field_tags" : true,
              "field_target_group" : true,
              "field_target_group_sub" : true,
              "field_teaser" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_educational_goals" : true,
              "field_educational_material" : true,
              "field_facilities" : true,
              "field_inspirational_material" : true,
              "field_offer_type" : true,
              "field_purpose" : true,
              "field_subject" : true,
              "field_tags" : true,
              "field_target_group" : true,
              "field_target_group_sub" : true,
              "field_teaser" : true
            },
            "title" : 1,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "field_purpose" : true, "field_teaser" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "field_purpose" : true, "field_teaser" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_collection_price" : true,
              "field_count" : true,
              "field_duration" : true,
              "field_duration_unit" : true,
              "field_educational_goals" : true,
              "field_educational_material" : true,
              "field_facilities" : true,
              "field_free" : true,
              "field_inspirational_material" : true,
              "field_offer_type" : true,
              "field_period_full_year" : true,
              "field_purpose" : true,
              "field_subject" : true,
              "field_subjects_primary_school" : true,
              "field_subjects_youth" : true,
              "field_tags" : true,
              "field_target_group" : true,
              "field_target_group_sub" : true,
              "field_teaser" : true,
              "search_api_language" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_page().
 */
function ulf_search_default_search_api_page() {
  $items = array();
  $items['default'] = entity_import('search_api_page', '{
    "index_id" : "default",
    "path" : "search",
    "name" : "Default",
    "machine_name" : "default",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : {
        "title" : "title",
        "field_purpose" : "field_purpose",
        "field_teaser" : "field_teaser",
        "author:field_profile_name" : "author:field_profile_name",
        "field_full_description:value" : "field_full_description:value",
        "field_offer_type:name" : "field_offer_type:name",
        "field_subject:name" : "field_subject:name",
        "field_tags:name" : "field_tags:name",
        "field_target_group:name" : "field_target_group:name",
        "field_target_group_sub:name" : "field_target_group_sub:name"
      },
      "per_page" : "10",
      "result_page_search_form" : 1,
      "get_per_page" : 0,
      "view_mode" : "search_api_page_result",
      "language_filter" : { "default" : "default" }
    },
    "enabled" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function ulf_search_default_search_api_server() {
  $items = array();
  $items['server'] = entity_import('search_api_server', '{
    "name" : "Server",
    "machine_name" : "server",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr\\/ulf_stg",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "AUTO"
    },
    "enabled" : "1"
  }');
  return $items;
}
