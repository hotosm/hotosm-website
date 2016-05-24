<?php
/**
 * @file
 * Features to export donation settings
 */

/**
 * Implements hook_features_export().
 */
function paypal_donations_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['features'] = 'features';
  $export['dependencies']['paypal_donations'] = 'paypal_donations';
  $export['features']['paypal_donations']['settings'] = 'PayPal donation settings';
  return $export;
}

/**
 * Implements hook_features_export_options().
 */
function paypal_donations_features_export_options() {
  $items = array();
  $items['settings'] = t("PayPal donation settings");
  return $items;
}

/**
 * Implements hook_features_export_render().
 */
function paypal_donations_features_export_render($module, $data) {
  $variable_keys = paypal_donations__variable_list();
  $code = array();

  foreach ($variable_keys as $vk) {
    $code[$vk] = variable_get($vk, '');
  }

  $code = "  return " . features_var_export($code, '  ') . ";";
  return array('paypal_donations_features_settings' => $code);
}

/**
 * Implements hook_features_revert().
 */
function paypal_donations_features_revert($module) {
  paypal_donations_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 */
function paypal_donations_features_rebuild($module) {
  $settings = module_invoke($module, 'paypal_donations_features_settings');
  foreach ($settings as $key => $val) {
    variable_set($key, $val);
  }
}
