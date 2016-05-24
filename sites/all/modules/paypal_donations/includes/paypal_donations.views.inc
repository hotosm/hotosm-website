<?php
/**
 * @file
 * Provides the views data and handlers for nodeblock.module.
 */

/**
 * Implements hook_views_data().
 */
function paypal_donations_views_data() {

  $data = array();
  $data['paypal_donations_item']['table']['group'] = t('PayPal donation');
  $data['paypal_donations_item']['table']['entity type'] = 'paypal_donations_item';
  $data['paypal_donations_item']['table']['base'] = array(
    'field' => 'donation_id',
    'title' => t('PayPal donation'),
    'help' => t('PayPal donations'),
  );

  $data['paypal_donations_item']['created'] = array(
    'title' => t('Donation time'),
    'help' => t('Donation timestamp'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}
