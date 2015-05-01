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
 * Implements hook_image_default_styles().
 */
function hot_updates_image_default_styles() {
  $styles = array();

  // Exported image style: update_content.
  $styles['update_content'] = array(
    'label' => 'update_content',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 780,
          'height' => 520,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
