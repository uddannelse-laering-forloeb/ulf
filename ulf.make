api = 2
core = 7.x

; Modules
projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.x-dev"

projects[ckeditor_link][subdir] = "contrib"
projects[ckeditor_link][version] = "2.3"

projects[date][subdir] = "contrib"
projects[date][version] = "2.7"

projects[diff][subdir] = "contrib"
projects[diff][version] = "3.2"

projects[elements][subdir] = "contrib"
projects[elements][version] = "1.4"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.3"

projects[entity_view_mode][subdir] = "contrib"
projects[entity_view_mode][version] = "1.0-rc1"

projects[facetapi][subdir] = "contrib"
projects[facetapi][version] = "1.3"
;projects[facetapi][patch][] = "https://drupal.org/files/limit-active-items.patch"

projects[facetapi_bonus][subdir] = "contrib"
projects[facetapi_bonus][version] = "1.1"

projects[features][subdir] = "contrib"
projects[features][version] = "2.0"

projects[features_extra][subdir] = "contrib"
projects[features_extra][version] = "1.0-beta1"

projects[field_group][subdir] = "contrib"
projects[field_group][version] = "1.3"

projects[field_collection][subdir] = "contrib"
projects[field_collection][version] = "1.x-dev"

projects[flag][subdir] = "contrib"
projects[flag][version] = "3.2"

projects[globalredirect][subdir] = "contrib"
projects[globalredirect][version] = "1.5"

projects[google_analytics][subdir] = "contrib"
projects[google_analytics][version] = "1.4"

projects[html5_tools][subdir] = "contrib"
projects[html5_tools][version] = "1.2"

projects[jquery_update][type] = "module"
projects[jquery_update][subdir] = "contrib"
projects[jquery_update][download][type] = "git"
projects[jquery_update][download][url] = "http://git.drupal.org/project/jquery_update.git"
projects[jquery_update][download][revision] = "65eecb0"

projects[l10n_update][subdir] = "contrib"
projects[l10n_update][version] = "1.x-dev"
projects[l10n_update][patch][] = "https://drupal.org/files/issues/l10n_update-1490664-fix_pdo_exception-27.patch"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.1"

projects[link][subdir] = "contrib"
projects[link][version] = "1.2"

projects[mailsystem][subdir] = "contrib"
projects[mailsystem][version] = "2.34"

projects[mimemail][subdir] = "contrib"
projects[mimemail][version] = "1.0-beta1"

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "1.8"

projects[panels][subdir] = "contrib"
projects[panels][version] = "3.3"
projects[panels][patch][] = "https://drupal.org/files/panels.code_.2114599-1.patch"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.2"

projects[redirect][subdir] = "contrib"
projects[redirect][version] = "1.0-rc1"

projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.11"

projects[search_api_page][subdir] = "contrib"
projects[search_api_page][version] = "1.0"

projects[search_api_solr][subdir] = "contrib"
projects[search_api_solr][version] = "1.4"

projects[search_api_spellcheck][subdir] = "contrib"
projects[search_api_spellcheck][version] = "1.0"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"

projects[token][subdir] = "contrib"
projects[token][version] = "1.5"

projects[transliteration][subdir] = "contrib"
projects[transliteration][version] = "3.1"

projects[uuid][subdir] = "contrib"
projects[uuid][version] = "1.0-alpha5"

projects[uuid_features][subdir] = "contrib"
projects[uuid_features][version] = "1.0-alpha3"

projects[rules][subdir] = "contrib"
projects[rules][version] = "2.6"

projects[views][subdir] = "contrib"
projects[views][version] = "3.7"

projects[workbench][subdir] = "contrib"
projects[workbench][version] = "1.2"

projects[workbench_moderation][subdir] = "contrib"
projects[workbench_moderation][version] = "1.3"

projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][version] = "2.2"

; Libraries
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.2/ckeditor_3.6.2.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "libraries"

libraries[respondjs][download][type] = "git"
libraries[respondjs][download][url] = "git@github.com:scottjehl/Respond.git"
libraries[respondjs][destination] = "libraries"
libraries[respondjs][directory_name] = "respond"


; Base theme
projects[ulftheme][type] = "theme"
projects[ulftheme][download][type] = "git"
projects[ulftheme][download][url] = "git@github.com:uddannelse-laering-forloeb/ulftheme.git"
projects[ulftheme][download][branch] = "development"
