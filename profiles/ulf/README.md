#Install profile setup

##The setup

###Changelog
* CHANGELOG.md located at /htdocs/profiles/ulf
* Logs ITK changes made to the dokk1 project.

##Install guide
* 1) Run vagrant up
* 2) Run ./install.sh
* 3) Run vagrant ssh
* 4) Clone your theme rep into /htdocs/profiles/ulf/themes.
(Available themes @ https://github.com/uddannelse-laering-forloeb)
* 5) Setup site throught UI, making choices along the way.
* You should now have an empty ulf installation.

###Patches
* https://www.drupal.org/files/1093420-22.patch (Used by profiler module during site install)