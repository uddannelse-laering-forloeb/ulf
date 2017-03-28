#!/usr/bin/env bash
bold=$(tput bold)
normal=$(tput sgr0)

echo -n "${bold}Enter the git branch/tag you want to check out (e.g vX.Y.Z):${normal}"
read tag
git pull
git checkout "${tag}"
drush updb
drush fra -y
drush spr
drush l10n-update-refresh
drush l10n-update
drush cc all
