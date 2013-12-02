<?php
/**
 * @file
 * hot_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hot_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "openlayers" && $api == "openlayers_layers") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hot_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hot_core_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Static page'),
      'base' => 'node_content',
      'description' => t('A <em>static page</em> is a page of content, organized into a collection of related entries collectively known as a <em>book</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
