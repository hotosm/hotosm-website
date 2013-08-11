<?php

/**
 * @file
 * Main extension file for the 'assets' extension.
 */

/**
 * Implements hook_extension_EXTENSION_registry_alter().
 */
function omega_extension_assets_theme_registry_alter(&$registry) {
  if ($settings = omega_theme_get_setting('omega_libraries', array())) {
    foreach (omega_theme_libraries_info() as $library => $info) {
      if (!empty($settings[$library]['status'])) {
        $registry['html']['libraries'][$library] = array(
          'attached' => array(),
          'settings' => $settings[$library],
          'callbacks' => isset($info['callbacks']) ? array_unique($info['callbacks']) : FALSE,
        );

        if (isset($settings[$library]['variant']) && $variant = $settings[$library]['variant']) {
          $registry['html']['libraries'][$library]['attached'] = $info['variants'][$variant]['files'];
        }
        else {
          $registry['html']['libraries'][$library]['attached'] = $info['files'];
        }
      }
    }
  }

  if (!empty($registry['html']['libraries'])) {
    $registry['html']['includes'][] = drupal_get_path('theme', 'omega') . '/includes/assets/assets.inc';
    $registry['html']['preprocess functions'][] = 'omega_extension_assets_attach_libraries';
  }
}

/**
 * Extension callback for attaching enabled libraries.
 */
function omega_extension_assets_attach_libraries(&$variables) {
  $registry = theme_get_registry();

  // Check if there are any enabled libraries.
  foreach ($registry['html']['libraries'] as $library => $info) {
    drupal_process_attached(array('#attached' => $info['attached']));

    if (!empty($info['callbacks'])) {
      foreach ($info['callbacks'] as $callback) {
        $callback($library, $info['settings']);
      }
    }
  }
}

/**
 * Library callback for checking if CSS aggregation is enabled.
 */
function omega_extension_library_requirements_css_aggregation($library, $settings) {
  if ((!variable_get('preprocess_css', FALSE) && (!defined('MAINTENANCE_MODE') || MAINTENANCE_MODE != 'update'))) {
    if (user_access('administer site configuration') && flood_is_allowed('omega_' . $GLOBALS['theme'] . '_aggregation_required', 3, 3600, $library)) {
      $libraries = omega_theme_libraries_info();
      $info = $libraries[$library];

      // Tell the user that the library does not work without CSS aggregation.
      flood_register_event('omega_' . $GLOBALS['theme'] . '_aggregation_required', 3600, $library);
      drupal_set_message(t('The %library library requires aggregated CSS files to work properly. You can enable CSS aggregation in the <a href="!url">performance settings</a>.', array('!url' => url('admin/config/development/performance'), '%library' => $info['name'])), 'warning');
    }
  }
}
