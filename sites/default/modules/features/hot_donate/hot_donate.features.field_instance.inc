<?php
/**
 * @file
 * hot_donate.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hot_donate_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'paypal_donations_item-paypal_donations_item-field_paypal_donations_amount'.
  $field_instances['paypal_donations_item-paypal_donations_item-field_paypal_donations_amount'] = array(
    'bundle' => 'paypal_donations_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'paypal_donations_item',
    'field_name' => 'field_paypal_donations_amount',
    'label' => 'PayPal donation amount',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'paypal_donations_item-paypal_donations_item-field_paypal_donations_type'.
  $field_instances['paypal_donations_item-paypal_donations_item-field_paypal_donations_type'] = array(
    'bundle' => 'paypal_donations_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'paypal_donations_item',
    'field_name' => 'field_paypal_donations_type',
    'label' => 'PayPal donation type',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'paypal_donations_item-paypal_donations_item-field_paypal_donator_country'.
  $field_instances['paypal_donations_item-paypal_donations_item-field_paypal_donator_country'] = array(
    'bundle' => 'paypal_donations_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'paypal_donations_item',
    'field_name' => 'field_paypal_donator_country',
    'label' => 'PayPal donator country',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'paypal_donations_item-paypal_donations_item-field_paypal_donator_email'.
  $field_instances['paypal_donations_item-paypal_donations_item-field_paypal_donator_email'] = array(
    'bundle' => 'paypal_donations_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'paypal_donations_item',
    'field_name' => 'field_paypal_donator_email',
    'label' => 'PayPal donation e-mail',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'paypal_donations_item-paypal_donations_item-field_paypal_donator_name'.
  $field_instances['paypal_donations_item-paypal_donations_item-field_paypal_donator_name'] = array(
    'bundle' => 'paypal_donations_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'paypal_donations_item',
    'field_name' => 'field_paypal_donator_name',
    'label' => 'PayPal donator name',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'paypal_donations_item-paypal_donations_item-field_paypal_transaction_id'.
  $field_instances['paypal_donations_item-paypal_donations_item-field_paypal_transaction_id'] = array(
    'bundle' => 'paypal_donations_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paypal_donations_item',
    'field_name' => 'field_paypal_transaction_id',
    'label' => 'PayPal transaction id',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('PayPal donation amount');
  t('PayPal donation e-mail');
  t('PayPal donation type');
  t('PayPal donator country');
  t('PayPal donator name');
  t('PayPal transaction id');

  return $field_instances;
}
