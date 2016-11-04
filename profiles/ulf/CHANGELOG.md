#ULF changelog

#2.4.9
* Added to changelog

#2.4.9
* Added google site verification file

#2.4.8
* Added google site verification file

#2.4.7
* Removed api key from map feature

#2.4.6
* Fixed error in map display on users and nodes
* Fixed error in draft creation and updating.

#2.4.5
* Removed map field from pdf display on courses

#2.4.4
* Removed map field from pdf display

#2.4.3
* Hid field for show on map

#2.4.2
* Added field for show on map on nodes

#2.4.1
* Changed pathauto settings
* Added show on map for courses and course_educators

#2.3.17
* Changed news archive references
* Changed display of youth  target group search for Viborg and Silkeborg

#2.3.16
* Removed metatag dependency from profile info file

#2.3.15
* Added EUD and EUX to youth search template

#2.3.14
* Added user email to csv export
* Changed workflow states for editors

#2.3.13
* Changed pathauto language

#2.3.12
* Changed pathauto language

#2.3.11
* Enabled error messages

#2.3.10
* Fixed bug in unpublishing

#2.3.9
* Fixed bug in unpublishing

#2.3.8
* Fixed bug in unpublishing

#2.3.7
* Changed default menu for static pages

#2.3.6
* Fixed workbench page permissions

#v2.3.5
* Updated IE9 styles

#v2.3.4
* Major change of menu structure
* Added menu block module
* Removed About ULF menu
* Added support for multiple dropdown menus
* Moved all menu items to main menu

#v2.3.3
* Removed impage dependency on profile
* Added image dependency on courses

#v2.3.2
* Added image dependency on profile
* Added url pattern

#v2.3.1
* Added frontpage blocks
* Added nodequeue

#v2.3.0
* Added free checkbox to search
* Changed display of courses on course provider
* Added media display on news and static pages
* Updated Drupal core

#v2.2.0

##Release notes
Clone ulf_aarhus (Theme)
Clone ulf_aarhus_settings (Custom module)
Clone ulf_aarhus_search_settings (Feature)

##Changes
* Updated install profile to reflect ULF version 2.0.0
* Added Silkeborg theme
* Added a base theme as a copy of ulf i aarhus
* Added editor access to url aliases
* Added gulp
* Fixed bug where filters would overflow
* Added permission for course provider to delete own content
* Changed label of "Læringsmål"
* Added free label to courses
* Removed required from courses
* Removed "special needs" field
* Removed links to taxonomy terms on course, and course_educator content types
* Changed order of courses on profile
* Added "place field" on courses
* Fixed a bug where all unpublished content were saved as "sent to revision" rather that "draft"
* Fixed a bug where changed date did not always update when changing workflow state
* Fixed a bug where save as darft in some cases changed state to "send to revision"
* Added Target group in admin views
* Added search input for all admin views
* Changed display of admin workbench interface

#v2.1.2

###Hotfix Node creation error
* Fixed fatal error when creating new nodes

#v2.1.1

##Release notes
* Enable ulf_scheduler_notify module
* Run update
* Update search node configuration (raw multi-field) - JK
* Revert setting feature for search and re-index data.
* Run drush ulf-su (ulf-set-unpublish) to set unpublishing date for courses and courses for educators
* Run drush cron

#Other
* Added script for unpublishing
* Fixed bug in unpublished content admin view

###Hotfix Setup duration and price
* Restructured template directory
* Rearranged duration and price to be grouped together
* Removed old combined duration and price info field
* Changed content overview view to look for duration content

###Feature auto unpublish
* Fixed error on login form
* Added unpublish button for authors and editors
* Added automated unpublishing based on period end date field
* Added mail sending to author/admin on unpublishing action
* Added mail sending one week prior to unpublishing content to author/admin
* Cleaned up l10n module (Caused error after update 2.1.0)

### Feature search filters
* Added support for raw multi-field in search filters.
* Updated settings for panels and search API.

#v2.1.0

##Release notes
* Uninstall Ulf pages (Deprecated)
* Uninstall Ulf structures (Deprecated)
* Uninstall Flag module (Unused)
* Uninstall Mimemail action (Unused)
* Uninstall rules (Unused)
* Uninstall trigger (Unused)

###Notes for endusers:
* Shared field for price and duration description has been separated into two fields.
Existing content should manually be moved from the old field to one of the new fields, a view has been provided to help this migration "Content overview"-tab
* Link checker module has been added to locate dead links see admin/reports/linkchecker page.

###Hotfix Drupal updates
* Drupal core 7.39 -> 7.41 (Security update)
* Mailchimp 7.x-3.4 -> 7.x-3.6
* Pathauto 7.x-1.2 -> 7.x-1.3
* Video Embed Field 7.x-2.0-beta10 -> 7.x-2.0-beta11
* Features 7.x-2.6 -> 7.x-2.7
* Field collection 7.x-1.0-beta8+11-dev -> 7.x-1.0-beta10
* JQuery update 7.x-3.0-alpha2 -> 7.x-3.0-alpha3
* Localization update 7.x-1.1+1-dev -> 7.x-1.2
* Universally unique identifier 7.x-1.0-alpha6 -> 7.x-1.0-beta1
* Date 7.x-2.8 -> 7.x-2.9

###Hotfix Search
* Changed headers in search widgets for "læringsmål" and "tilbudstype" - This change will affect all uses of these terms.
* Changed server settings to fix Internet explorer error on some search results.

###Hotfix Courses
* Added view for locating and moving price and duration content (ulf_workflow)
* Seperated Notes for price and duration into two fields (ulf_field_bases, ulf_course modules)
* Added cropping for teaser image (ulf_base, ulf_course, ulf_news,
ulf_static_page, ulf_course_educators, ulf_course_providers modules)
* Added singularity for duration unit (ulf_course module)
* Added target _blank for links to external matererials (ulf_field_collections module)
* Fixed bug in courses for educators, removed check for non existing duration field
* Added h2 and h3 to content filter and wysiwyg (ulf_wysiwyg module)
* Removed bold on materials and other field collections (Except contact name)

###Hotfix Users
* Added link to contact information
* Added link on user logo
* Removed bold from office hours
* Added padding to contact box
* Removed phone label if no phone number is added
* Reduced field spacing in blocks from 8px to 4px
* Added website address in user creation form (ulf_course_educators module)
* Changed description label to presentation

###Hotfix News
* Changed path to news archive (ulf_news module)

###Hotfix Header-footer
* Changed width of footer blocks

###Hotfix v1-errorfixes:
* Fixed HTML validation
* Added IE11 fixes
* Added linkchecker contrib module including config (linkchecker module)
* Removed custom blocks from feature (ulf_footer module)


#v2.0.0

* Added transliteration module
* Added fixes to search


#v1.0.0 - Beta2

* Added news archive page /news
* Added profiles overview page /organizers
* Added newsletter signup page /newsletter/signup
* Added styling for login
* Added newsletter archive page /newsletter/archive


#v1.0.0 - Beta1

* Added profile display
* Added courses display
* Added static pages display
* Added news display
* Added frontpage display
* Added Header and footer display
* Added configurable footer blocks
* Added mobile menu
* Added sub menu for "About ULF" menu item
* Added view for promoted courses
* Added workbench permissions for editor
* Added styling for courses
* Added newsletter signup form
* Added cookies warning
* Added menu access for editors
* Added imagecrop for main content images
