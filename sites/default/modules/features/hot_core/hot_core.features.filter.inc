<?php
/**
 * @file
 * hot_core.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function hot_core_filter_default_formats() {
  $formats = array();

  // Exported format: Text Editor.
  $formats['text_editor'] = array(
    'format' => 'text_editor',
    'name' => 'Text Editor',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_autop' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'video_embed_field' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
