# Sry about the hack.

## Whats going on?
This is basically an empty module to allow for custom translations to be
grouped into a single .po file.

## But where are the translations?
All translation packages are located at sites/all/translations

If you want to add a translation string simply edit the translation file
related to this module (ulf_translations-7.x-1.0.da.po).

For translations to appear run:
´
drush l10n-update-refresh

drush l10n-update

drush cc all
´
