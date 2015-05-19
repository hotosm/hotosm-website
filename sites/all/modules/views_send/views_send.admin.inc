<?php

/**
 * @file
 *   Views Send administration page.
 *
 * @ingroup views_send
 */

/**
 * Callback for admin/settings/views_send menu item.
 */
function views_send_settings() {
  $form = array();

  $throttle = drupal_map_assoc(array(1, 10, 20, 30, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000));
  $throttle[0] = t('Unlimited');

  $form['views_send_throttle'] = array(
    '#type' => 'select',
    '#title' => t('Cron throttle'),
    '#options' => $throttle,
    '#default_value' => variable_get('views_send_throttle', 20),
    '#description' => t('Sets the numbers of messages sent per cron run. Failure to send will also be counted. Cron execution must not exceed the PHP maximum execution time of %max seconds. You find the time spend to send e-mails in the !recent_logs.', array('%max' => ini_get('max_execution_time'), '!recent_logs' => l(t('Recent log entries'), 'admin/reports/dblog'))),
  );
  $form['views_send_spool_expire'] = array(
    '#type' => 'select',
    '#title' => t('Mail spool expiration'),
    '#options' => array(0 => t('Immediate'), 1 => t('1 day'), 7 => t('1 week'), 14 => t('2 weeks')),
    '#default_value' => variable_get('views_send_spool_expire', 0),
    '#description' => t('E-mails are spooled. How long must messages be retained in the spool after successfull sending.'),
  );
  $form['views_send_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log e-mails'),
    '#default_value' => variable_get('views_send_debug', FALSE),
    '#description' => t('When checked all outgoing mesages are logged in the system log. A logged e-mail does not guarantee that it is send or will be delivered. It only indicates that a message is send to the PHP mail() function. No status information is available of delivery by the PHP mail() function.'),
  );

  return system_settings_form($form);
}
