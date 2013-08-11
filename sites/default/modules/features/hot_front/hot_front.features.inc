<?php
/**
 * @file
 * hot_front.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hot_front_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function hot_front_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
