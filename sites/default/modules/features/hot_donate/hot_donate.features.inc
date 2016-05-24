<?php
/**
 * @file
 * hot_donate.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hot_donate_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paypal_donations_features_settings().
 */
function hot_donate_paypal_donations_features_settings() {
  return array(
    'paypal_donations_single_account_email' => 'donations@hotosm.org',
    'paypal_donations_single_item_name' => 'Humanitarian OpenStreetMap Team',
    'paypal_donations_single_return_ur' => '',
    'paypal_donations_single_predefined_donation_amounts' => '500,250,150,100,50,25',
    'paypal_donations_single_currency_code' => 'USD',
    'paypal_donations_single_currency_sign' => '$',
    'paypal_donations_single_submit_value' => 'Donate',
    'paypal_donations_single_custom_amount_allowed' => 1,
    'paypal_donations_recurring_account_email' => 'donations@hotosm.org',
    'paypal_donations_recurring_item_name' => 'Humanitarian OpenStreetMap Team',
    'paypal_donations_recurring_return_url' => 'donation/thank-you',
    'paypal_donations_recurring_predefined_donation_amounts' => '500,250,150,100,50,25',
    'paypal_donations_recurring_currency_code' => 'USD',
    'paypal_donations_recurring_currency_sign' => '$',
    'paypal_donations_recurring_submit_value' => 'Donate',
    'paypal_donations_recurring_custom_amount_allowed' => 1,
    'paypal_donations_recurring_period' => 1,
    'paypal_donations_recurring_unit' => 'M',
  );
}
