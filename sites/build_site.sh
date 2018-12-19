#!/usr/bin/env bash

# ---------
# Site build script by ITK Aarhus
# ---------

# Set variables
dir=$(cd $(dirname "${BASH_SOURCE[0]}") && pwd)
bold=$(tput bold)
normal=$(tput sgr0)
domain=
theme_repo=
module_repo=
error=

echo "${bold}---${normal}"
echo "${bold}This script builds a new site file structure from predefined repositories${normal}"

# Help error function
usage() {
  echo "${bold}---${normal}"
  echo "${bold}usage: build_site [[[-d site domain ] [-t theme repository] [-m module repository]] | [-h help]]${normal}"
  echo "${bold}usage: build_site [[[-d site domain ] [-t theme repository] [-m module repository]] | [-h help]]${normal}"
  echo "${bold}e.g: build_site.sh -d ulfiaarhus.dk -t git@github.com:uddannelse-laering-forloeb/ulf_aarhus.git -m git@github.com:uddannelse-laering-forloeb/ulf_aarhus_settings.git${normal}"
  echo "${bold}---${normal}"
}

# Help success function
success() {
  echo "${bold}---${normal}"
  echo "${bold}Building directories and cloning repositories...${normal}"
  echo "${bold}---${normal}"
}

# Check arguments and set variables.
while [ "$1" != "" ]; do
    case $1 in
        -d | --domain )         shift
        domain=$1
                                ;;
        -t | --theme_repo )     shift
        theme_repo=$1
                                ;;
        -m | --module_repo )    shift
        module_repo=$1
                                ;;
        -h | --help )           usage
        error=1
                                exit
                                ;;
        * )                     usage
                                exit
    esac
    shift
done

# Do stuff if no error.
if [ "$error" = 1 ]; then
	usage
else
  success
	mkdir -p $dir/${domain}
	cd $dir/${domain}
	mkdir themes
	mkdir modules
	cd $dir/${domain}/themes
	git clone ${theme_repo}
	cd $dir/${domain}/modules
  git clone ${module_repo}

  # Continue to site install or stop installation.
  echo "${bold}---${normal}"
  echo "${bold}The file structure is now set.${normal}"
  echo "${bold}You can choose to continue the install process. This will do a default site installation using drush site-install.${normal}"
  echo "${bold}If you want to manually set up the site using the ui or just do the site installation at a later stage choose no.${normal}"
  echo "${bold}Continue?${normal}"
  echo "${bold}---${normal}"
  read -p "Reply yes(y) to  continue or no(n) to exit: " reply
  if [ "$reply" = y ] || [ "$reply" = yes ]; then
  	usage
  else
    echo "Your replied $reply exiting..."
    exit 1
  fi
fi