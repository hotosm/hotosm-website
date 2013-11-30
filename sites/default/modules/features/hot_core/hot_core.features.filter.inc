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

  // Exported format: Full HTML.
  $formats[2] = array(
    'format' => 2,
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -1,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'textile' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'textile_tags' => 1,
        ),
      ),
      'filter_autop' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
