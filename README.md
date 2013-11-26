profile
=======

Installation profile.

From your intended document root run:

drush make --concurrency=1 --working-copy --contrib-destination=profiles/ulf/ http://raw.github.com/uddannelse-laering-forloeb/ulf/development/drupal.make -y


------------------------------


To export your panel pages after changing panes or other panel content run:

drush ctex ulf_pages --subdir=../../../profiles/ulf/modules/ulf_custom --remove --tables="page_manager_handlers","page_manager_pages"

Select "Export everything".