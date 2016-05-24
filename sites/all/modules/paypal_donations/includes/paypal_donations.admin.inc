<?php
/**
 * @file
 * Create the configuration area for PayPal donation
 */

/**
 * Administrative settings from.
 */
function paypal_donations__paypal_admin_settings($form, &$form_state) {

  $form = array('#attributes' => array('enctype' => 'multipart/form-data'));

  $donation_types = array(
    'single' => t('Single donation'),
    'recurring' => t('Recurring donation'),
  );

  foreach ($donation_types as $type_key => $type_name) {
    $form[$type_key] = array(
      '#type' => 'fieldset',
      '#title' => $type_name,
    );

    $form[$type_key]['paypal_donations_' . $type_key . '_account_email'] = array(
      '#title' => t('Receiver PayPal account'),
      '#required' => TRUE,
      '#description' => t("The PayPal account's e-mail address"),
      '#default_value' => variable_get('paypal_donations_' . $type_key . '_account_email', ""),
      '#type' => 'textfield',
    );

    $form[$type_key]['paypal_donations_' . $type_key . '_item_name'] = array(
      '#title' => t('PayPal item name'),
      '#type' => 'textfield',
      '#description' => t('The visible item name at PayPal'),
      '#default_value' => variable_get('paypal_donations_' . $type_key . '_item_name', "Donation"),
    );

    $form[$type_key]['paypal_donations_' . $type_key . '_return_url'] = array(
      '#title' => t('Return URL'),
      '#type' => 'textfield',
      '#description' => t('This is the URL where users will be redirected after payment'),
      '#default_value' => variable_get('paypal_donations_' . $type_key . '_return_url', "donation/thank-you"),
    );

    $form[$type_key]['paypal_donations_' . $type_key . '_predefined_donation_amounts'] = array(
      '#title' => t('Predefined amounts'),
      '#type' => 'textfield',
      '#description' => t('Separate predefined amounts with commas'),
      '#default_value' => variable_get('paypal_donations_' . $type_key . '_predefined_donation_amounts', '5,10,15'),
    );

    $form[$type_key]['paypal_donations_' . $type_key . '_currency_code'] = array(
      '#title' => t('Currency code'),
      '#type' => 'textfield',
      '#description' => t('ISO 4217 Currency Code') . ' ' . l('http://en.wikipedia.org/wiki/ISO_4217', 'http://en.wikipedia.org/wiki/ISO_4217', array('attributes' => array('target' => '_blank'))),
      '#default_value' => variable_get('paypal_donations_' . $type_key . '_currency_code', 'USD'),
    );

    $form[$type_key]['paypal_donations_' . $type_key . '_currency_sign'] = array(
      '#title' => t('Currency sign'),
      '#type' => 'textfield',
      '#description' => t('The currency sign') . ' ' . l('http://en.wikipedia.org/wiki/Currency_sign', 'http://en.wikipedia.org/wiki/Currency_sign', array('attributes' => array('target' => '_blank'))),
      '#default_value' => variable_get('paypal_donations_' . $type_key . '_currency_sign', '$'),
    );

    $form[$type_key]['paypal_donations_' . $type_key . '_submit_value'] = array(
      '#title' => t('Form submit text'),
      '#type' => 'textfield',
      '#description' => t('The button text when someone sends the form'),
      '#default_value' => variable_get('paypal_donations_' . $type_key . '_submit_value', 'Donate now'),
    );

    $form[$type_key]['paypal_donations_' . $type_key . '_custom_amount_allowed'] = array(
      '#title' => t('Custom amount'),
      '#type' => 'select',
      '#options' => array(
        1 => t('allowed'),
        0 => t('not allowed'),
      ),
      '#description' => t('If you allow custom amounts, the visitor is able to enter other then the specified amounts'),
      '#default_value' => variable_get('paypal_donations_' . $type_key . '_custom_amount_allowed', 1),
    );

    $default_notification_text = 'Dear <b>@first_name</b>

Thank you for your donation of $!amount.

Your generous contribution will strengthen our work.
';

    $form[$type_key]['paypal_donations_' . $type_key . '_notification_email'] = array(
      '#title' => t('Donator notification e-mail'),
      '#type' => 'textarea',
      '#rows' => 8,
      '#description' => t('This message will be sent out to the donator.'),
      '#default_value' => variable_get('paypal_donations_' . $type_key . '_notification_email', $default_notification_text),
    );

    $form[$type_key]['token'] = array(
      '#type' => 'fieldset',
      '#title' => t('Available tokens'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form[$type_key]['token']['token_list'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('paypal_donations'),
      '#global_types' => FALSE,
      '#click_insert' => TRUE,
    );
  }

  // Special fields for recurring.
  $form['recurring']['paypal_donations_recurring_period'] = array(
    '#title' => t('Donation recurring'),
    '#type' => 'textfield',
    '#description' => t('Recurring period, like every X months'),
    '#default_value' => variable_get('paypal_donations_recurring_period', '1'),
  );

  $form['recurring']['paypal_donations_recurring_unit'] = array(
    '#title' => t('Donation recurring units'),
    '#type' => 'select',
    '#options' => array(
      'D' => t('day'),
      'W' => t('week'),
      'M' => t('month'),
      'Y' => t('year'),
    ),
    '#description' => t('The time unit for the recurring period.'),
    '#default_value' => variable_get('paypal_donations_recurring_unit', 'M'),
  );

  $form['paypal_donations_notif_email'] = array(
    '#title' => t('Donation e-mail address'),
    '#type' => 'textfield',
    '#description' => t('This e-mail address will be used to send out the thank you e-mail message to the donator.'),
    '#default_value' => variable_get('paypal_donations_notif_email', variable_get('site_mail', ini_get('sendmail_from'))),
  );

  $form['paypal_donations_notif_email_subject'] = array(
    '#title' => t('Donation e-mail subject'),
    '#type' => 'textfield',
    '#description' => t('This e-mail address will be used to send out the thank you e-mail message to the donator.'),
    '#default_value' => variable_get('paypal_donations_notif_email_subject', 'Thank you'),
  );

  $form['paypal_donations_ipn_url'] = array(
    '#title' => t('IPN Callback URL'),
    '#type' => 'textfield',
    '#description' => t("This is the URL where PayPal is sending back the donation information. Normally this doesn't needs to be changed."),
    '#default_value' => variable_get('paypal_donations_ipn_url', "paypal/payment/ipn"),
  );

  $form['paypal_donations_service_url'] = array(
    '#title' => t('Service URL'),
    '#type' => 'select',
    '#options' => array(
      'www.sandbox.paypal.com' => t("Sandbox (www.sandbox.paypal.com)"),
      'www.paypal.com' => t("Production (www.paypal.com)"),
    ),
    '#default_value' => variable_get('paypal_donations_service_url', "www.sandbox.paypal.com"),
  );

  $upload_validators = array(
    'file_validate_extensions' => array('gif png jpg jpeg'),
    'file_validate_size' => array(0.5 * 1024 * 1024),
    'file_validate_image_resolution' => array('750x100', '750x60'),
  );
  $form['paypal_donations_header_logo'] = array(
    '#type' => 'managed_file',
    '#title' => t('Header logo'),
    '#name' => 'paypal_donations_header_logo',
    '#default_value' => variable_get('paypal_donations_header_logo', ''),
    '#upload_location' => 'public://paypal_donations/',
    '#description' => theme("file_upload_help", array(
      'description' => t('This logo will be visible at PayPal payments, in case you have an enterprise PayPal account'),
      'upload_validators' => $upload_validators,
    )),
    '#upload_validators' => $upload_validators,
  );

  return system_settings_form($form);
}
