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

  // Exported format: Full Text Editor.
  $formats['text_editor'] = array(
    'format' => 'text_editor',
    'name' => 'Full Text Editor',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'video_embed_field' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
    ),
  );

  return $formats;
}
