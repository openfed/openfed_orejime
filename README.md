CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Features
 * Requirements
 * Installation
 * Configuration
 

INTRODUCTION
------------

Provides Drupal 7 integration into Orejime JS cookie manager.

See https://github.com/openfed/orejime for more info.


FEATURES:
---------

The Openfed Orejime module:

* Integrates Orejime JS library into Drupal sites, tailored for OpenFed.


REQUIREMENTS
------------

Orejime plugin in "libraries".


INSTALLATION
------------

1. Install the module as normal, see link for instructions.
   Link: https://www.drupal.org/documentation/install/modules-themes/modules-7

2. Follow the installation instructions of Orejime.
   Link: https://github.com/openfed/orejime
   
3. After running "npm run build" process of Orejime you should have generated JS/CSS files within the "dist" directory.
   Create a new directory called "orejime" in the "libraries" root folder and copy the directory "dist" inside.
   Make sure the path to the plugin file becomes:
   "libraries/orejime/dist/orejime.js" and "libraries/orejime/dist/orejime.css"

4. Go to "Administer" -> "Extend" and enable the Openfed Orejime module.


CONFIGURATION
-------------

 * Go to "Configuration" -> "System" -> "Openfed Orejime" to find all the configuration
   options.

