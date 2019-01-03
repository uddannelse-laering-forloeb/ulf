# ULF README

## Specific README files
- Theme setup documentation located in [the default theme folder](https://github.com/uddannelse-laering-forloeb/ulf/blob/master/profiles/ulf/themes/ulf_default/README.md).
- Each custom module located in [the custom modules folder](https://github.com/uddannelse-laering-forloeb/ulf/tree/master/profiles/ulf/modules/ulf_custom) contains a README.md file describing it's functionality.
- Each feature module located in [the feature modules folder](https://github.com/uddannelse-laering-forloeb/ulf/tree/master/profiles/ulf/modules/features) contains a README.md file describing it's functionality.
- Multisite setup documentation located in [the sites folder](https://github.com/uddannelse-laering-forloeb/ulf/tree/feature/profile-update/sites).
- Search setup documentation: JESPER @todo
- Changelog located in [the profile folder](https://github.com/uddannelse-laering-forloeb/ulf/tree/master/profiles/ulf/CHANGELOG.md).

## Tested and confirmed working serversetup
Other server setups will also work, some with minor tweaks.
- PHP 5.6 (For 7.0 compatibility the following updates are needed: [php 7.0 compatibility](https://github.com/uddannelse-laering-forloeb/ulf/blob/master/profiles/ulf/php7-0-test.json))
- Apache 2.4
- Debian jessie
- Mysql 15.1
- Modules
  - wkhtmltopdf 0.12.5-dev (with patched qt)
    - Used by print module.
  - Search
    - JESPER @todo

JESPER @todo

## The profile setup
The install profile contains:

### ulf_default theme
- Uses Ulfiaarhus.dk original images, styles, and templates
- Used as a base theme for all sites).
- See [this readme](https://github.com/uddannelse-laering-forloeb/ulf/blob/master/profiles/ulf/themes/ulf_default/README.md) on info about theme setup.
- Martin @todo

### ulf_admin theme
- A sub theme of seven
- Contains backend overrides.

### Contributed modules
- Maintained and updated on a regular basis.

### Features modules
- Each release should include a step where all features be reverted to their default code state.
- Features modules may contain additional code related to the feature but not maintained through the features module.
- Overridden features should be prevented by updating the features code. This should help to maintain a smooth release flow.
- See the individual README.md files for each features module.

### Custom modules
- See the individual README.md files for each module.
- Martin @todo

### search_api_search_node module
- JESPER @todo

### search_node_page module
- JESPER @todo

### Libraries
- angular
  - Used by search module and search templates
- chosen
  - Used by ulf_custom/transportpulje_form module
- ckeditor
  - The goto wysiwyg editor
- imagesloaded
  - Used for imagecropping
  - contrib/manualcrop module
- imgareaselect
  - Used for imagecropping
  - contrib/manualcrop module
- mailchimp
  - Used by mailchimp module
- profiler
  - Used by the install profile

### Changelog
- CHANGELOG.md located in [the profile folder](https://github.com/uddannelse-laering-forloeb/ulf/tree/master/profiles/ulf/CHANGELOG.md)
- Logs changes made to the ULF project across all repositories related to ULF.

### ulf.install
- Holds update hooks for the project that are not related to a specific module.

### ulf.profile
- The install profile used for new site installations
- Uses ulf.install_callbacks.inc file for batch job callbacks
- Uses profiler library

## Registered patches used
* https://www.drupal.org/files/issues/translate_role_names-2205581-1.patch

## Install guide
- Setup a site file structure as described [here](https://github.com/uddannelse-laering-forloeb/ulf/blob/master/sites/README.md)
- Setup a database
- Create google maps API key as described [here](https://developers.google.com/maps/documentation/javascript/get-api-key)
- Run the installation
  - It is advised to use and follow the ui installation steps @ /install.php
  - Use the ULF install profile
  - If drush is used to run the installation instead of the the advised UI approach, a default configuration is used. You must manually make sure that all the variables are set.
  i.e:
    - map configuration
    - translations
    - optional module activation
    - themes
    - search modules
- Setup search configuration
  - Setting up search JESPER @todo
  - Modify the site settings.php file uncommenting the needed lines.

### Test results for php 7.0
* Conducted using: [https://github.com/sstalle/php7cc](https://github.com/sstalle/php7cc)
* See : [php 7.0 compatibility](https://github.com/uddannelse-laering-forloeb/ulf/blob/master/profiles/ulf/php7-0-test.json)
