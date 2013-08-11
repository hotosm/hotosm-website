<?php
/**
 * @file
 * hot_project.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function hot_project_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-projects-navigation.
  $menus['menu-projects-navigation'] = array(
    'menu_name' => 'menu-projects-navigation',
    'title' => 'Projects navigation',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Projects navigation');


  return $menus;
}
