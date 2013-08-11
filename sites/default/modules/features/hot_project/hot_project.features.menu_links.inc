<?php
/**
 * @file
 * hot_project.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hot_project_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-projects-navigation:node/add/project
  $menu_links['menu-projects-navigation:node/add/project'] = array(
    'menu_name' => 'menu-projects-navigation',
    'link_path' => 'node/add/project',
    'router_path' => 'node/add/project',
    'link_title' => '+ add a project',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('+ add a project');


  return $menu_links;
}
