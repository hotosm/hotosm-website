<?php

/**
 * @file
 * Tokens for notifications.
 */

/**
 * Implements hook_token_info().
 */
function node_notify_token_info() {
  $info['types']['subscriber'] = array(
    'name' => t('Subscriber'),
    'description' => t('User subscribed to a node comment notifications.'),
    'type' => 'user',
    'needs-data' => 'subscriber',
  );
  $info['types']['subscription'] = array(
    'name' => t('Subscription'),
    'description' => t('Subscription information.'),
    'needs-data' => 'subscription',
  );
  $info['tokens']['subscription']['unsubscribe-url'] = array(
    'name' => t('Unsubscribe URL'),
    'description' => t('Unique URL to cancel subscription.'),
    'type' => 'url',
  );

  return $info;
}

/**
 * Implements hook_tokens().
 */
function node_notify_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  switch ($type) {
    case 'subscriber':
      if (!empty($data['subscriber'])) {
        $replacements += token_generate('user', $tokens, array('user' => $data['subscriber']), $options);
      }
      break;

    case 'subscription':
      if (!empty($data['subscription']) && isset($tokens['unsubscribe-url'])) {
        $replacements[$tokens['unsubscribe-url']] = url('node_notify/unsubscribe/' . $data['subscription']->token, array('absolute' => TRUE));
      }
      break;
  }

  return $replacements;
}
