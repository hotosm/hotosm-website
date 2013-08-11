<?php

/**
 * @file
 * Theme settings file for the Ohm theme.
 */

require_once dirname(__FILE__) . '/template.php';

/**
 * Implements hook_form_FORM_alter().
 */
function ohm_form_system_theme_settings_alter(&$form, $form_state) {
  // You can use this hook to append your own theme settings to the theme
  // settings form for your subtheme. However, you should also take a look at
  // the 'extensions' concept in the Omega base theme. We highly suggest that you
  // put your custom features and theme settings into extensions.
}
