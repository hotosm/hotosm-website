<?php

/**
 * Implements hook_views_plugins_alter
 */
function views_enhanced_block_views_plugins_alter(&$plugins) {
  $plugins['display']['block'] = array_merge($plugins['display']['block'], array(
    'module' => 'views_enhanced_block',
    'handler' => 'views_plugin_display_enhanced_block',
    'path' => drupal_get_path('module', 'views_enhanced_block'),
    'file' => 'views_plugin_display_enhanced_block.inc',
  ));
}
