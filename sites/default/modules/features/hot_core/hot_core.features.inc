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
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
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
 * Implements hook_image_default_styles().
 */
function hot_core_image_default_styles() {
  $styles = array();

  // Exported image style: maximum.
  $styles['maximum'] = array(
    'label' => 'Maximum',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 720,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: medium_square.
  $styles['medium_square'] = array(
    'label' => 'Medium Square',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
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
  drupal_alter('node_info', $items);
  return $items;
}
