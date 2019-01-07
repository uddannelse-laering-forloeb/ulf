# ULF Admin panel
## ULF project relation
- Required module

## Description
- Defines ulf admin panel form. This module is used for setting and modifying
global configuration by admins/editors in the UI.
- Holds social media links configuration and templates.

Note: Make sure variables are not configurable by admins in the UI if they exist
as Strongarm variables in other features modules. This would result in overridden
features that will be reverted during new releases.