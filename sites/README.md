# ULF multisite setup

## From README.txt (Default drupal)

This directory structure contains the settings and configuration files specific
to your site or sites and is an integral part of multisite configuration.

The sites/all/ subdirectory structure should be used to place your custom and
downloaded extensions including modules, themes, and third party libraries.

Downloaded installation profiles should be placed in the /profiles directory
in the Drupal root.

In multisite configuration, extensions found in the sites/all directory
structure are available to all sites. Alternatively, the sites/your_site_name/
subdirectory pattern may be used to restrict extensions to a specific
site instance.

See the respective README.txt files in sites/all/themes and sites/all/modules
for additional information about obtaining and organizing extensions.

See INSTALL.txt in the Drupal root for information about single-site
installation or multisite configuration.

## ULF multisite info
- All sites should use the domain name as folder name.
- The folder structure of each site follows the public D7 [documentation](https://www.drupal.org/docs/7/multisite/multi-site-sharing-the-same-code-base#site-specific-modules-themes) i.e:
  + (Sitename)
    + Modules
      + (Site specific modules)
    + Themes
      + (Site specific themes)
    + Files
      + (Site specific files)
  + settings.php (Site specific configuration)

- The site specific modules and themes should be seperate git repositories.
- The settings.php file should be copied from default/default.settings.php and manually configured for the site.
- The default/default.settings.php file has been slightly modified to include search configuration variables.