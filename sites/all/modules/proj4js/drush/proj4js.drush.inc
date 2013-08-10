<?php

/**
 * @file
 *   drush integration for Proj4JS.
 */

/**
 * The Proj4JS library URI.
 */
define('PROJ4JS_DOWNLOAD_URI', 'http://download.osgeo.org/proj4js/proj4js-1.1.0.zip');

/**
 * Implementation of hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function proj4js_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['dl-proj4js'] = array(
    'callback' => 'drush_proj4js_plugin',
    'description' => dt('Download and install the Proj4JS library.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the Proj4JS library. If omitted Drush will use the default location.'),
    )
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function proj4js_drush_help($section) {
  switch ($section) {
    case 'drush:dl-proj4js':
      return dt('Download and install the Proj4JS library from http://trac.osgeo.org/proj4js, default location is sites/all/libraries.');
  }
}

/**
 * Command to download the Proj4JS library.
 */
function drush_proj4js_plugin() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  // Download the archive
  if ($filepath = drush_download_file(PROJ4JS_DOWNLOAD_URI)) {
    $filename = basename($filepath);
    $dirname = 'proj4js';

    // Remove any existing Proj4JS library directory
    if (is_dir($dirname) || is_dir('proj4js')) {
      drush_delete_dir($dirname, TRUE);
      drush_log(dt('A existing Proj4JS library was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the archive
    drush_tarball_extract($filename);
  }

  if (is_dir($dirname)) {
    drush_log(dt('Proj4JS library has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the Proj4JS library to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
