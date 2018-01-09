# ULF changelog

# v2.5.x

## 2.5.21
* Fixed bug in 2.5.20 release

## 2.5.20
* Transportpulje workflow fix in denied private institutions

## 2.5.19
* Transportpulje workflow fix

## 2.5.18
* Fix of failed array check

## 2.5.17
* Full release of transportpulje module

## 2.5.16
* Temporarily denied access to transportpulje

## 2.5.15
* Added transport pulje module targeted KLC Viborg

## 2.5.14
* SUPPORT-1314: Fixed moderation bug in workflow.
* SUPPORT-1317: Added configuration to mailchimp archive page

## 2.5.13
* SUPPORT-1278: Apply translate role names patch

## 2.5.12
* SUPPORT-1278: Added ulf_track_mail module to assist bug reporting

## 2.5.11
* SUPPORT-1250: Added node token to mail edit templates

## 2.5.10
* SUPPORT-1228: Removed ULF occurrences in core

## 2.5.9
* SUPPORT-1193: Split siteimprove from default theme
* Removed Aarhus mail address from mime mail

## 2.5.7
* SUPPORT-1122: Added placeholder text for mailchimp block
* SUPPORT-1121: Removed label for mailchimp block.
* SUPPORT-1133: Changed captcha strength
* SUPPORT-1129: Fixed course duration describtion error

## 2.5.6
* SUPPORT-1121: Changed spacing in mailchimp block

## 2.5.5
* SUPPORT-1106: Fixed bugs in duration patterns
* SUPPORT-1106: Fixed Viborg logo

## 2.5.4
* SUPPORT-1064: Fixed bug where sidebar content appeared at the bottom of content.
* SUPPORT-1057: Added Editor view for tracking mixed target groups
* ULF-581 Run through backlog document and implementation of lacking features
* ULF-580: Fixes of bugs related to 2.5.0 described in "Extra feedback" document
* SUPPORT-1052: Changed workflow mails to follow user language.
* ULF-581: Added checkbox for showing footer social links.
* ULF-581: Removed required from number of participants.
* ULF-581: Updated all search settings modules (to 2.5.1) to add free field for courses.
* ULF-581: Fixed bug where changing course target group didn't clear all unretaed field values.
* ULF-581: Added free tag on search pages for course educators.
* ULF-580: Contact form enabled by default.
* ULF-580: Pagination fixed on taxonomy term pages.
* ULF-580: Max upload size increased.
* SUPPORT-1040: Added Taxonomy term view for target group on courses.
* SUPPORT-1044: Changed contact form email text.
* Contrib modules updated
  ```

  Entityform	                    7.x-2.0-rc3	    7.x-2.0-rc4
  Entity reference	              7.x-1.2	        7.x-1.4
  Mime Mail	                      7.x-1.0-beta4	  7.x-1.0
  Universally Unique IDentifier	  7.x-1.0-beta2	  7.x-1.0
  Wysiwyg	                        7.x-2.3	        7.x-2.4
  ```

## 2.5.3
* SUPPORT-1019: Made 'field_profile_mail' on users required and set account mail as default is missing value. 
* SUPPORT-1027: Added course titel to entityform email.
* SUPPORT-1029: Added check for “full year” when scheduling un-publishing to fix un-publishing bug. Added hook to fix wrongly set schedules.
* Contrib updated:
    ```                
   Mail Editor (mail_edit)                    7.x-1.1    7.x-1.2   Update available                                                                                   
   Rules (rules)                              7.x-2.9    7.x-2.10  Update available
   ```

## 2.5.2

* SUPPORT-1001: Updated missing locations form nodes
* SUPPORT-1006: Fixed signupdate default value on ulf_course_educators
* SUPPORT-1008: Fixed when/where ‘place’ was shown on course and course_educators
* SUPPORT-1013: Changed widget for ‘periode’ date fields to select to avoid js error in popup setting end year to wrong value
* SUPPORT-1014: Fixed ‘signup’ box display
* Contrib updated:
    ```
    Date (date)                                7.x-2.9         7.x-2.10          Update available                                                                                   
    jQuery Update (jquery_update)              7.x-3.0-alpha3  7.x-3.0-alpha5    Update available                                                                                   
    Views (views)                              7.x-3.15        7.x-3.16          Update available                                                                                   
    Views Data Export (views_data_export)      7.x-3.1         7.x-3.2           Update available
    ```

## 2.5.1
* SUPPORT-997: 
  - Removed required from period date field
  - Reverted ‘revision’ settings on ‘course’ node type to fix workbench bug where node couldn’t change from ‘needs review’ to ‘published’

## 2.5.0
* Changed 'place' to be a location field. Simplified node edit form for place selection. 
* Fixed mobile styling an javascript for ‘end user message’ modal 
* Added sigup fields from 'course educators' to 'course'
* Changed title fields to use H1’s instead of DIV’s
* Fixed ‘gratisbanner’ placement on mobile
* CKEditor updated to 4.6.2
* Core and contrib updated:
    ```
    Drupal                                                     7.52               7.54              Update available   
    Views (views)                                              7.x-3.14           7.x-3.15          SECURITY UPDATE available                                                                  
    Views Bulk Operations (views_bulk_operations)              7.x-3.3            7.x-3.4           Update available                                                                 
    Chaos tools (ctools)                                       7.x-1.11           7.x-1.12          Update available                                                                 
    CAPTCHA (captcha)                                          7.x-1.3            7.x-1.4           Update available                                                                 
    Diff (diff)                                                7.x-3.2            7.x-3.3           Update available                                                                 
    Drafty (drafty)                                            7.x-1.0-beta3      7.x-1.0-beta4     Update available                                                                 
    Entity API (entity)                                        7.x-1.6            7.x-1.8           Update available                                                                 
    Entityforms (entityform)                                   7.x-2.0-rc2+2-dev  7.x-2.0-rc3       Update available                                                                 
    Field collection (field_collection)                        7.x-1.0-beta11     7.x-1.0-beta12    Update available                                                                 
    Panels (panels)                                            7.x-3.8            7.x-3.9           Update available                                                                 
    Localization update (l10n_update)                          7.x-2.0            7.x-2.1           Update available                                                                 
    Libraries (libraries)                                      7.x-2.2            7.x-2.3           Update available                                                                 
    Link checker (linkchecker)                                 7.x-1.2            7.x-1.3           Update available                                                                 
    MailChimp (mailchimp)                                      7.x-4.7            7.x-4.8           Update available                                                                 
    Manual Crop (manualcrop)                                   7.x-1.5            7.x-1.6           Update available                                                                 
    Nodequeue (nodequeue)                                      7.x-2.0            7.x-2.1           Update available                                                                 
    Search API (search_api)                                    7.x-1.18           7.x-1.21          Update available                                                                 
    Token (token)                                              7.x-1.6            7.x-1.7           Update available                                                                 
    Universally Unique ID (uuid)                               7.x-1.0-beta1      7.x-1.0-beta2     Update available                                                                 
    UUID Features (uuid_features)                              7.x-1.0-alpha4     7.x-1.0-rc1       Update available
    Wysiwyg (wysiwyg)                                          7.x-2.2            7.x-2.3           Update available
    ```

# v2.4.x

## 2.4.15
* Added extra padding between blocks in footer 

## 2.4.14
* Updated Gitignore to exclude Google site verification

## 2.4.13
* Fixed bug where "ghost role" was added on user create
* Fixed circular dependency between ulf_workflow and ulf_scheduler_notify

## 2.4.12
* Updated core with security fix
* Updated several contrib modules with security updates

## 2.4.11
* Removed verification file from git

## 2.4.10
* Added to changelog

## 2.4.9
* Added google site verification file

## 2.4.8
* Added google site verification file

## 2.4.7
* Removed api key from map feature

## 2.4.6
* Fixed error in map display on users and nodes
* Fixed error in draft creation and updating.

## 2.4.5
* Removed map field from pdf display on courses

## 2.4.4
* Removed map field from pdf display

## 2.4.3
* Hid field for show on map

## 2.4.2
* Added field for show on map on nodes

## 2.4.1
* Changed pathauto settings
* Added show on map for courses and course_educators

# v2.3.x

## 2.3.17
* Changed news archive references
* Changed display of youth  target group search for Viborg and Silkeborg

## 2.3.16
* Removed metatag dependency from profile info file

## 2.3.15
* Added EUD and EUX to youth search template

## 2.3.14
* Added user email to csv export
* Changed workflow states for editors

## 2.3.13
* Changed pathauto language

## 2.3.12
* Changed pathauto language

## 2.3.11
* Enabled error messages

## 2.3.10
* Fixed bug in unpublishing

## 2.3.9
* Fixed bug in unpublishing

## 2.3.8
* Fixed bug in unpublishing

## 2.3.7
* Changed default menu for static pages

## 2.3.6
* Fixed workbench page permissions

## v2.3.5
* Updated IE9 styles

## v2.3.4
* Major change of menu structure
* Added menu block module
* Removed About ULF menu
* Added support for multiple dropdown menus
* Moved all menu items to main menu

## v2.3.3
* Removed impage dependency on profile
* Added image dependency on courses

## v2.3.2
* Added image dependency on profile
* Added url pattern

## v2.3.1
* Added frontpage blocks
* Added nodequeue

## v2.3.0
* Added free checkbox to search
* Changed display of courses on course provider
* Added media display on news and static pages
* Updated Drupal core

# v2.2.0

## Release notes
Clone ulf_aarhus (Theme)
Clone ulf_aarhus_settings (Custom module)
Clone ulf_aarhus_search_settings (Feature)

## Changes
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

# v2.1.2

### Hotfix Node creation error
* Fixed fatal error when creating new nodes

# v2.1.1

## Release notes
* Enable ulf_scheduler_notify module
* Run update
* Update search node configuration (raw multi-field) - JK
* Revert setting feature for search and re-index data.
* Run drush ulf-su (ulf-set-unpublish) to set unpublishing date for courses and courses for educators
* Run drush cron

#Other
* Added script for unpublishing
* Fixed bug in unpublished content admin view

### Hotfix Setup duration and price
* Restructured template directory
* Rearranged duration and price to be grouped together
* Removed old combined duration and price info field
* Changed content overview view to look for duration content

### Feature auto unpublish
* Fixed error on login form
* Added unpublish button for authors and editors
* Added automated unpublishing based on period end date field
* Added mail sending to author/admin on unpublishing action
* Added mail sending one week prior to unpublishing content to author/admin
* Cleaned up l10n module (Caused error after update 2.1.0)

###  Feature search filters
* Added support for raw multi-field in search filters.
* Updated settings for panels and search API.

# v2.1.0

## Release notes
* Uninstall Ulf pages (Deprecated)
* Uninstall Ulf structures (Deprecated)
* Uninstall Flag module (Unused)
* Uninstall Mimemail action (Unused)
* Uninstall rules (Unused)
* Uninstall trigger (Unused)

### Notes for endusers:
* Shared field for price and duration description has been separated into two fields.
Existing content should manually be moved from the old field to one of the new fields, a view has been provided to help this migration "Content overview"-tab
* Link checker module has been added to locate dead links see admin/reports/linkchecker page.

### Hotfix Drupal updates
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

### Hotfix Search
* Changed headers in search widgets for "læringsmål" and "tilbudstype" - This change will affect all uses of these terms.
* Changed server settings to fix Internet explorer error on some search results.

### Hotfix Courses
* Added view for locating and moving price and duration content (ulf_workflow)
* Seperated Notes for price and duration into two fields (ulf_field_bases, ulf_course modules)
* Added cropping for teaser image (ulf_base, ulf_course, ulf_news,
ulf_static_page, ulf_course_educators, ulf_course_providers modules)
* Added singularity for duration unit (ulf_course module)
* Added target _blank for links to external matererials (ulf_field_collections module)
* Fixed bug in courses for educators, removed check for non existing duration field
* Added h2 and h3 to content filter and wysiwyg (ulf_wysiwyg module)
* Removed bold on materials and other field collections (Except contact name)

### Hotfix Users
* Added link to contact information
* Added link on user logo
* Removed bold from office hours
* Added padding to contact box
* Removed phone label if no phone number is added
* Reduced field spacing in blocks from 8px to 4px
* Added website address in user creation form (ulf_course_educators module)
* Changed description label to presentation

### Hotfix News
* Changed path to news archive (ulf_news module)

### Hotfix Header-footer
* Changed width of footer blocks

### Hotfix v1-errorfixes:
* Fixed HTML validation
* Added IE11 fixes
* Added linkchecker contrib module including config (linkchecker module)
* Removed custom blocks from feature (ulf_footer module)


# v2.0.0

* Added transliteration module
* Added fixes to search


# v1.0.0 - Beta2

* Added news archive page /news
* Added profiles overview page /organizers
* Added newsletter signup page /newsletter/signup
* Added styling for login
* Added newsletter archive page /newsletter/archive


# v1.0.0 - Beta1

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
