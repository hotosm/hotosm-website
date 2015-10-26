<?php

/**
 * @file
 * Mailchimp module Drush integration
 */

/**
 * Implements hook_drush_command().
 */
function mailchimp_drush_command() {
  $items = array();

  $items['mailchimp-cron'] = array(
    'callback' => '_mailchimp_cron_batch',
    'description' => "Trigger Mailchimp cron task",
    'examples' => array(
      'drush mailchimp-cron 5000' => 'Run Mailchimp cron with a batch size of 5000.',
      'drush mailchimp-cron' => 'Run a Mailchimp cron task.',
    ),
  );

  return $items;
}

/**
 * Callback function to run cron.
 * 
 * @int null $temp_batchsize
 */
function _mailchimp_cron_batch($temp_batchsize = NULL) {
  $stored_batchsize = NULL;
  if (!is_null($temp_batchsize)) {
    $stored_batchsize = variable_get('mailchimp_batch_limit', 100);
    variable_set('mailchimp_batch_limit', $temp_batchsize);
  }
  mailchimp_cron();
  if (!is_null($stored_batchsize)) {
    variable_set('mailchimp_batch_limit', $stored_batchsize);
  }
}
