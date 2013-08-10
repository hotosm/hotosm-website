<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function hot_project_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function hot_project_imagecache_default_presets() {
  $items = array(
    'featured_project' => array(
      'presetname' => 'featured_project',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '510px',
            'height' => '300px',
          ),
        ),
      ),
    ),
    'mini_project_image' => array(
      'presetname' => 'mini_project_image',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '50px',
            'height' => '50px',
          ),
        ),
      ),
    ),
    'project_landing' => array(
      'presetname' => 'project_landing',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '180',
            'height' => '180',
          ),
        ),
      ),
    ),
    'project_page' => array(
      'presetname' => 'project_page',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '250px',
            'height' => '250px',
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
function hot_project_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'module' => 'features',
      'description' => '',
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
function hot_project_views_api() {
  return array(
    'api' => '2',
  );
}
