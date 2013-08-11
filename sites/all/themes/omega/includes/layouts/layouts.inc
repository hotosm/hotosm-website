<?php

/**
 * @file
 * Main extension file for the 'layouts' extension.
 */

/**
 * Implements hook_extension_EXTENSION_registry_alter().
 */
function omega_extension_layouts_theme_registry_alter(&$registry) {
  $registry['page']['includes'][] = drupal_get_path('theme', 'omega') . '/includes/layouts/layouts.inc';
  $registry['page']['process functions'][] = 'omega_extension_layouts_process_layout';
}

/**
 * Implements hook_extension_EXTENSION_process_page().
 */
function omega_extension_layouts_process_layout(&$variables) {
  if ($layout = omega_layout()) {
    $variables['theme_hook_suggestions'][] = 'omega_layout';
    $variables['omega_layout'] = $layout;
  }
}
