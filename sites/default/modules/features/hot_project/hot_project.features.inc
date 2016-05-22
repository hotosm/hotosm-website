<?php
/**
 * @file
 * hot_project.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hot_project_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hot_project_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function hot_project_flag_default_flags() {
  $flags = array();
  // Exported flag: "Featured project".
  $flags['featured_project'] = array(
    'entity_type' => 'node',
    'title' => 'Featured project',
    'global' => 1,
    'types' => array(
      0 => 'project',
    ),
    'flag_short' => 'Feature this project',
    'flag_long' => 'Feature this project on the home page.',
    'flag_message' => 'Featured project',
    'unflag_short' => 'Un-feature this project',
    'unflag_long' => 'Not feature this project on the home page anymore.',
    'unflag_message' => 'Un-featured.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -6,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'print' => 0,
      'diff_standard' => 0,
      'feature' => 0,
      'list' => 0,
      'revision' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'hot_project',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function hot_project_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A <em>project</em> is a description of an official HOT project, which has a description, contact person(s) and can have updates attached to it.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
