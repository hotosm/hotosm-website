<?php
/**
 * @file
 * Deinfes the PayPal donation item entity
 */

/**
 * Implements hook_entity_info().
 */
function paypal_donations_entity_info() {
  $info['paypal_donations_item'] = array(
    'label' => t('PayPal donation'),
    'controller class' => 'EntityAPIControllerExportable',
    'base table' => 'paypal_donations_item',
    'uri callback' => 'paypal_donations__uri',
    'module' => 'paypal_donations',
    'fieldable' => TRUE,
    'entity keys' => array(
      'id' => 'donation_id',
    ),
    'static cache' => TRUE,
    'bundles' => array(
      'paypal_donations_item' => array(
        'label' => 'Paypal Donation item',
        'admin' => array(
          'path' => 'admin/structure/paypal_donations/manage',
          'access arguments' => array('administer paypal donations'),
        ),
      ),
    ),
    'view modes' => array(
      'full' => array(
        'label' => t('Full Donation'),
        'custom settings' => FALSE,
      ),
    ),
  );
  return $info;
}

/**
 * Provides the path for the donation entity().
 */
function paypal_donations__uri($donation) {
  return array(
    'path' => 'paypal_donations/' . $donation->id,
  );
}

/**
 * Base entity load.
 */
function paypal_donations_load($pid = NULL, $reset = FALSE) {
  $pids = (isset ($pid) ? array($pid) : array());
  $postit = paypal_donations_load_multiple($pids, $reset);
  return $postit ? reset($postit) : FALSE;
}

/**
 * Multiple entity load.
 */
function paypal_donations_load_multiple($pids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('paypal_donations_item', $pids, $conditions, $reset);
}

/**
 * Just provide some basic info for the entity administration page.
 * 
 * This can be expanded to add more information / a list of all created entites.
 */
function paypal_donations_admin_page() {
  $output = 'Welcome to the administration page for your Basic Entities.<br/>';
  return $output;
}
