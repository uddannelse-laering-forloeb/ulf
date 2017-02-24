#Install profile setup

##The setup

###Changelog
* CHANGELOG.md located at /htdocs/profiles/ulf
* Logs ITK changes made to the dokk1 project.

##Install guide
1. Run vagrant up
2. Run ./install.sh
3. Run vagrant ssh
4. Clone your theme rep into /htdocs/profiles/ulf/themes.   
(Available themes @ https://github.com/uddannelse-laering-forloeb)
5. Setup site through UI, making choices along the way.

You should now have an empty ulf installation.

##Update guide

###For each site:
```
git pull
git checkout v.XYZ
drush updb
drush spr
drush fra -y
drush l10n-update-refresh
drush l10n-update
drush cc all
```

###Patches used
* https://www.drupal.org/files/1093420-22.patch (Used by profiler module during site install)
* https://www.drupal.org/files/issues/translate_role_names-2205581-1.patch

##About the css files
- ie8.css: Specific to Internet explorer 8 (Might be absolete)

- ie9.css: Specific to Internet explorer 9 (Loaded in html.tpl.php)

- print.css: Print styles used in pdf prints (Overridden in each theme)

- print-styles.css: Default print stylesheet (Not theme specific/Not overridden)

- ulf-styles.css: Compiled scss files from default theme (Used in all themes)

###Other
- Each theme has theme specific styles that override specific selectors. But the default styles (ulf-styles.css) are always used.


