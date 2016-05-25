<?php
/**
 * @file
 * hot_showcases.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hot_showcases_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hot_showcases_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hot_showcases_node_info() {
  $items = array(
    'showcase' => array(
      'name' => t('Showcase'),
      'base' => 'node_content',
      'description' => t('A showcase of a map or outcome, which was achieved with HOT\'s participation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
