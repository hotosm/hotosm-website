<?php
/**
 * @file
 * hot_updates.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hot_updates_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-updates-navigation:node/add/update
  $menu_links['menu-updates-navigation:node/add/update'] = array(
    'menu_name' => 'menu-updates-navigation',
    'link_path' => 'node/add/update',
    'router_path' => 'node/add/update',
    'link_title' => '+ add an update',
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
  t('+ add an update');


  return $menu_links;
}
