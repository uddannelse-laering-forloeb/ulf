# ULF Default theme
- This is the default theme for the ulf project.
- This theme holds global changes to the theme that should affect all sites.
- Each site sub theme should use this as a base theme and override the
appropriate selectors.

## Installation/setup
```
npm install
```

## Compiling
```
node_modules/gulp/bin/gulp.js sass
```

## Notes on setting up a new subtheme
-  The frontpage images are currently hardcoded into panel panes and looks for
files with the appropriate filename in the active themes images folder.
    - See more @ features/ulf_frontpage/ulf_frontpage.ctools_content.inc
- Each subtheme holds it's own print styles.
- Each subtheme holds it's own fonts
- Each subtheme may hold it's own search template overrides. The templates are referenced from settings.php

### Templates in subtheme
The entity configuration for all content types, field_collections, entityforms and users and views are stored in features code.
This way all sub themes can use the node templates and field templates from the ulf_default base theme without overriding them.
If these templates are customized in a subtheme that would result in that subtheme having to maintain it's own display during upgrades of ulf_core code and changes to default configuration.

Instead of adding theme template overrides in a subtheme it is advised that the changes in templates be made in the ulf_default base theme to benefit all ulf sites.

New sites should strive to use the layout defined in ulf_default and not override it in the sub theme. That would simplify the workflow of new releases and changes in configuration.
 - Exception: The varying system specifications for each site in regard to search displays and metadata has resulted in a setup where each subtheme may contain it's own search template overrides.
 These overrides are referenced in that sites settings.php file.

### Styles in subtheme
A subtheme should use the styles provided by the base theme and only include styles that override the desired selectors.

One of the other subthemes could be copied and used as a starting template. (Though ulf_aarhus should probably NOT be used as it hardly contains any changes to the styles.)

Sass is used as a default CSS extension but this could change between sub themes if desired.
If Sass is used it is possible to change most of the visual representation needed from the _theme-vars.scss file.