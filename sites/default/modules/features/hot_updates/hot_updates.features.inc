<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function hot_updates_imagecache_default_presets() {
  $items = array(
    'update_content' => array(
      'presetname' => 'update_content',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '780',
            'height' => '520',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function hot_updates_node_info() {
  $items = array(
    'update' => array(
      'name' => t('Update'),
      'module' => 'features',
      'description' => t('An update that appears on the home page and project pages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function hot_updates_views_api() {
  return array(
    'api' => '2',
  );
}
