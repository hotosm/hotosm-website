<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function hot_blog_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: primary-links:http://hot.openstreetmap.org
  $menu_links['primary-links:http://hot.openstreetmap.org'] = array(
    'menu_name' => 'primary-links',
    'link_path' => 'http://hot.openstreetmap.org',
    'router_path' => '',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');


  return $menu_links;
}
