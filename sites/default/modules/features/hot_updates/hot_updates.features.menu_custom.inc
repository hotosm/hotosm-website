<?php
/**
 * @file
 * hot_updates.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function hot_updates_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-updates-navigation.
  $menus['menu-updates-navigation'] = array(
    'menu_name' => 'menu-updates-navigation',
    'title' => 'Updates navigation',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Updates navigation');


  return $menus;
}
