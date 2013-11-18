<?php

/**
 * @file
 *   drush integration for OpenLayers.
 */

/**
 * The OpenLayers library URI.
 */
define('OPENLAYERS_DOWNLOAD_URI', 'http://openlayers.org/download/OpenLayers-2.12.tar.gz');

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
function openlayers_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['dl-openlayers'] = array(
    'callback' => 'drush_openlayers_plugin',
    'description' => dt('Download and install the OpenLayers library.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the OpenLayers library. If omitted Drush will use the default location.'),
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
function openlayers_drush_help($section) {
  switch ($section) {
    case 'drush:dl-openlayers':
      return dt('Download and install the OpenLayers library from http://openlayers.org, default location is sites/all/libraries.');
  }
}

/**
 * Command to download the OpenLayers library.
 */
function drush_openlayers_plugin() {
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
  if ($filepath = drush_download_file(OPENLAYERS_DOWNLOAD_URI)) {
    $filename = basename($filepath);
    $dirname = basename($filepath, '.tar.gz');

    // Remove any existing OpenLayers library directory
    if (is_dir($dirname) || is_dir('openlayers')) {
      drush_delete_dir($dirname, TRUE);
      drush_delete_dir('openlayers', TRUE);
      drush_log(dt('A existing OpenLayers library was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the archive
    drush_tarball_extract($filename);

    // Change the directory name to "openlayers" if needed.
    if ($dirname != 'openlayers') {
      drush_move_dir($dirname, 'openlayers', TRUE);
      $dirname = 'openlayers';
    }
  }

  if (is_dir($dirname)) {
    drush_log(dt('OpenLayers library has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the OpenLayers library to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
