<?php
/**
 * @file
 * Node Notify admin pages.
 */


/**
 * Node Notify admin settings form.
 */
function node_notify_settings_form($form, &$form_state) {
  $types = array();
  foreach (node_type_get_types() as $type) {
    $types[$type->type] = $type->name;
  }

  $form['node_notify_enabled_types'] = array(
    '#title' => t('Subscribable content types'),
    '#type' => 'checkboxes',
    '#options' => $types,
    '#default_value' => variable_get('node_notify_enabled_types', array()),
  );

  $form['node_notify_enabled_by_default'] = array(
    '#title' => t('Subscription enabled by default on'),
    '#type' => 'checkboxes',
    '#options' => $types,
    '#default_value' => variable_get('node_notify_enabled_by_default', array()),
    '#description' => t('Choose content types to tick off subscription checkbox by default for new content.'),
  );

  $form['node_notify_cron'] = array(
    '#title' => t('Remove expired subscriptions'),
    '#description' => t('Remove disabled and expired subscriptions when cron is run.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('node_notify_cron', FALSE),
  );

  $form['node_notify_expires'] = array(
    '#title' => t('Expiration date'),
    '#description' => t('Subscription is considered expired if it is disabled and subscription or modification date is earlier than this setting. Expiration date can and should be <a href="http://www.php.net/manual/en/datetime.formats.relative.php">relative</a>. Current value would produce <span id="node-notify-expires-test">%time</span>.', array(
      '%time' => format_date(strtotime(variable_get('node_notify_expires', '-1 month')), 'custom', 'Y-m-d H:i:s'),
    )),
    '#type' => 'textfield',
    '#default_value' => variable_get('node_notify_expires', '-1 month'),
  );

  $token_types = array(
    'comment', 'site', 'random', 'subscriber', 'subscription',
  );
  $form['node_notify_template'] = array(
    '#title' => t('Notification template'),
    '#type' => 'fieldset',
    'node_notify_template_subject' => array(
      '#title' => t('Subject'),
      '#type' => 'textfield',
      '#default_value' => variable_get('node_notify_template_subject', NODE_NOTIFY_DEFAULT_NOTIFICATION_SUBJECT),
      '#return_value' => 1,
      '#token_types' => $token_types,
      '#element_validate' => array('token_element_validate'),
    ),
    'node_notify_template_body' => array(
      '#title' => t('Body'),
      '#type' => 'textarea',
      '#default_value' => variable_get('node_notify_template_body', NODE_NOTIFY_DEFAULT_NOTIFICATION_BODY),
      '#return_value' => 1,
      '#token_types' => $token_types,
      '#element_validate' => array('token_element_validate'),
    ),
    'token_help' => array(
      '#theme' => 'token_tree',
      '#token_types' => $token_types,
      '#global_types' => FALSE,
    ),
  );

  $form['node_notify_log'] = array(
    '#title' => t('Log notifications'),
    '#type' => 'checkbox',
    '#description' => t('Log information about notifications and email messages if they are sent.'),
    '#default_value' => variable_get('node_notify_log', FALSE),
  );

  return system_settings_form($form);
}
