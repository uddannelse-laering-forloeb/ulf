# Git subtree
git subtree pull --prefix profiles/ulf/modules/search_api_search_node git@github.com:search-node/search_api_search_node 7.x-1.x
git subtree pull --prefix profiles/ulf/modules/search_node_page_ git@github.com:search-node/search_node_page 7.x-1.x


# Search node mappings
<pre>
{
  "e0ea2029a2ae62cae2614b85e4061819": {
    "name": "ULF Courses",
    "fields": [
      {
        "field": "title",
        "type": "string",
        "language": "da",
        "country": "DK",
        "default_analyzer": "string_index",
        "sort": true,
        "indexable": true,
        "default_indexer": "analyzed",
        "raw": false
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_educational_goals",
        "indexable": true,
        "default_indexer": "analyzed",
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_offer_type",
        "indexable": true,
        "default_indexer": "analyzed",
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_subject",
        "indexable": true,
        "default_indexer": "analyzed",
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_subjects_primary_school",
        "indexable": true,
        "default_indexer": "analyzed",
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_subjects_youth",
        "indexable": true,
        "default_indexer": "analyzed",
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_target_group",
        "indexable": true,
        "default_indexer": "analyzed",
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "sort": false,
        "field": "field_target_group_sub",
        "indexable": true,
        "default_indexer": "analyzed",
        "raw": true
      },
      {
        "type": "object",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analysed",
        "sort": false,
        "field": "field_image:file",
        "indexable": false
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analysed",
        "sort": false,
        "field": "url",
        "indexable": false
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analysed",
        "sort": false,
        "field": "author:url",
        "indexable": false
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analysed",
        "sort": false,
        "field": "field_subject:url",
        "indexable": false
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "author:field_profile_name",
        "indexable": true,
        "raw": false
      },
      {
        "type": "geo_point",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analysed",
        "sort": false,
        "indexable": false,
        "raw": false,
        "geopoint": true,
        "field": "field_location"
      }
    ],
    "dates": [
      "created",
      "changed",
      "field_period:value"
    ],
    "tag": "private"
  },
  "f8fba18f511d352f1514e86b00ac1499": {
    "name": "ULF  Educator",
    "fields": [
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": true,
        "field": "title",
        "indexable": true,
        "raw": false
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_teaser",
        "indexable": true,
        "raw": false
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_educational_goals",
        "indexable": true,
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_offer_type",
        "indexable": true,
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_relevance_eduators",
        "indexable": true,
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_relevance_primary_school",
        "indexable": true,
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_relavance_upper_school",
        "indexable": true,
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_subject",
        "indexable": true,
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_subjects_primary_school",
        "indexable": true,
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_subjects_youth",
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_tags",
        "indexable": true,
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_target_group",
        "indexable": true,
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "field_target_group_sub",
        "indexable": true,
        "raw": true
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analysed",
        "sort": false,
        "field": "url",
        "indexable": false
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analysed",
        "sort": false,
        "field": "author:url",
        "indexable": false
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analysed",
        "sort": false,
        "field": "field_subject:url",
        "indexable": false
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": false,
        "field": "author:field_profile_name",
        "indexable": true,
        "raw": false
      }
    ],
    "dates": [
      "created",
      "changed",
      "field_period:value"
    ],
    "tag": "private"
  },
  "81f32f94d4cdf81bb8c673eed20ee84f": {
    "name": "ULF Users",
    "fields": [
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analyzed",
        "sort": true,
        "field": "field_profile_name",
        "indexable": true,
        "raw": false
      },
      {
        "type": "string",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analysed",
        "sort": false,
        "field": "url",
        "indexable": false
      },
      {
        "type": "geo_point",
        "country": "DK",
        "language": "da",
        "default_analyzer": "string_index",
        "default_indexer": "analysed",
        "sort": false,
        "indexable": false,
        "raw": false,
        "geopoint": true,
        "field": "field_location"
      }
    ],
    "dates": [
      "created",
      "changed"
    ],
    "tag": "private"
  }
}
</pre>