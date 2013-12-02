<?php
/**
 * @file
 * hot_sharing.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hot_sharing_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
