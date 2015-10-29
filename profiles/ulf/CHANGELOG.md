#ULF changelog

#In development

#v2.1.0

##Release notes
* Uninstall Ulf pages (Deprecated)
* Uninstall Ulf structures (Deprecated)
* Uninstall Flag module (Unused)
* Uninstall Mimemail action (Unused)
* Uninstall rules (Unused)
* Uninstall trigger (Unused)

###Editors:
* Shared field for price and duration description has been separated into two fields.
Existing content should manually be moved from the old field to one of the new fields, a view has been provided to help this migration "Content overview"-tab
* Link checker module has been added to locate dead links see Reports/broken links.

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

###Hotfix Courses
* Added view for locating and moving price and duration content (ulf_workflow)
* Seperated Notes for price and duration into two fields (ulf_field_bases, ulf_course modules)
* Added cropping for teaser image (ulf_base, ulf_course, ulf_news,
ulf_static_page, ulf_course_educators, ulf_course_providers modules)
* Added singularity for duration unit (ulf_course module)
* Added target _blank for links to external matererials (ulf_field_collections module)
* Fixed bug in courses for educators, removed check for non existing duration field
* Added link to author homepage on courses
* Added h2 and h3 to content filter and wysiwyg (ulf_wysiwyg module)
* Removed bold on materials and other field collections

###Hotfix Users
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