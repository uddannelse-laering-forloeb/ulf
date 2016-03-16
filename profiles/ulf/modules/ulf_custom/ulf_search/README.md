# sub tree
git subtree pull --prefix profiles/ulf/modules/search_api_search_node git@github.com:search-node/search_api_search_node 7.x-1.x


# Search node mappings

<pre>
"xxxx": {
    "name": "ULF Courses",
    "tag": "private",
    "fields": [
      {
        "field": "title",
        "type": "string",
        "language": "da",
        "country": "DK",
        "default_analyzer": "string_index",
        "sort": true,
        "indexable": true,
        "default_indexer": "analyzed"
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_educational_goals",
        "indexable": true,
        "default_indexer": "not_analyzed"
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_offer_type",
        "indexable": true,
        "default_indexer": "not_analyzed"
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_subject",
        "indexable": true,
        "default_indexer": "not_analyzed"
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_subject_primary_school",
        "indexable": true,
        "default_indexer": "not_analyzed"
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_subject_youth",
        "indexable": true,
        "default_indexer": "not_analyzed"
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_target_group",
        "indexable": true,
        "default_indexer": "not_analyzed"
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_target_group_sub",
        "indexable": true,
        "default_indexer": "not_analyzed"
      }
    ],
    "dates": [
      "created",
      "changed",
      "field_period:value"
    ]
  }
  </pre>