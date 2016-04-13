<?php
/**
 * @file
 * hot_updates.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hot_updates_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hot_updates_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hot_updates_node_info() {
  $items = array(
    'update' => array(
      'name' => t('Update'),
      'base' => 'node_content',
      'description' => t('An update that appears on the home page and project pages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
