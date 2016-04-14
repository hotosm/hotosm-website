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

  // Exported format: Simple Text editor.
  $formats[1] = array(
    'format' => 1,
    'name' => 'Simple Text editor',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'video_embed_field' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_html' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <img> <h2> <h3> <h4> <h5> <p> <br> <div> <iframe>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats[2] = array(
    'format' => 2,
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'video_embed_field' => array(
        'weight' => -46,
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

  // Exported format: PHP code.
  $formats[3] = array(
    'format' => 3,
    'name' => 'PHP code',
    'cache' => 0,
    'status' => 1,
    'weight' => -7,
    'filters' => array(
      'php_code' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
    ),
  );

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
