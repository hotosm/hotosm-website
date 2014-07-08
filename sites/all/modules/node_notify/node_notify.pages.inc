<?php
/**
 * @file
 * Node Notify page callbacks.
 */


/**
 * Page callback to disable subscriptions by a given token.
 */
function node_notify_disable_page($token) {
  $record = db_select('node_notify_subscription', 's')
    ->fields('s', array('sid'))
    ->condition('token', $token)
    ->execute()
    ->fetchObject();
  if ($record) {
    db_update('node_notify_subscription')
      ->condition('sid', $record->sid)
      ->fields(array('enabled' => 0))
      ->execute();
    drupal_set_message(t('Subscription canceled.'));
  }
  else {
    drupal_set_message(t('Sorry, there was a problem unsubscribing from notifications.'));
  }
  return ' ';
}

/**
 * Subscription page callback.
 */
function node_notify_subscribe_page($node) {
  if (user_is_logged_in()) {
    node_notify_subscribe($node->nid, $GLOBALS['user']->uid);
    drupal_set_message(t('Subscribed to %title.', array('%title' => $node->title)));
    drupal_goto('node/' . $node->nid);
  }
  else {
    return drupal_get_form('node_notify_subscribe_form', $node);
  }
}

/**
 * Subscription form displayed for anonymous user.
 */
function node_notify_subscribe_form($form, &$form_state, $node) {
  $form_state['node_notify']['node'] = $node;

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Receive comment notifications by email'),
    '#description' => t('Enter your email address to receive email notifications.'),
    '#required' => TRUE,
    '#element_validate' => array('node_notify_validate_email_address'),
  );

  $form['subscribed'] = array(
    '#type' => 'submit',
    '#value' => t('Subscribe'),
  );

  return $form;
}

/**
 * Submit handler.
 *
 * Subscribes given email to a given node.
 */
function node_notify_subscribe_form_submit($form, &$form_state) {
  $email = $form_state['values']['email'];
  $node = $form_state['node_notify']['node'];
  node_notify_subscribe($node->nid, 0, $email);
  drupal_set_message(t('Subscribed to %title.', array('%title' => $node->title)));
  drupal_goto('node/' . $node->nid);
}

/**
 * Page callback to unsubscribe current user from a node.
 */
function node_notify_unsubscribe_page($node) {
  if (user_is_logged_in()) {
    node_notify_unsubscribe($node->nid, $GLOBALS['user']->uid);
    drupal_set_message(t('Unsubscribed from %title.', array('%title' => $node->title)));
    drupal_goto('node/' . $node->nid);
  }
  else {
    drupal_access_denied();
  }
}

/**
 * Page to display subscriptions to a given node.
 */
function node_notify_node_subscriptions_page($node) {
  $header = array(
    array('data' => t('User'), 'field' => 'name'),
    array('data' => t('Email'), 'field' => 'email'),
    array('data' => t('Date'), 'field' => 'subscribed_on', 'sort' => 'desc'),
    '',
  );

  $query = db_select('node_notify_subscription', 's');
  $query->leftJoin('users', 'u', '(s.uid = u.uid)');
  $query->fields('s', array('sid', 'email', 'subscribed_on', 'uid', 'enabled'));
  $query->fields('u', array('name'));
  $query->condition('nid', $node->nid);

  $query
    ->extend('PagerDefault')->limit(20)
    ->extend('TableSort')->orderByHeader($header);

  $rows = array();
  foreach ($query->execute() as $record) {
    $url = 'node/' . $node->nid . '/subscriptions/' . $record->sid;
    $rows[] = array(
      $record->uid ? l($record->name, 'user/' . $record->uid) : NULL,
      $record->email, format_date($record->subscribed_on),
      $record->enabled ?
      l(t('Disable'), $url . '/disable', array('query' => drupal_get_destination())) :
      l(t('Enable'), $url . '/enable', array('query' => drupal_get_destination())),
    );
  }

  $build = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No subscriptions yet.'),
    // '#attributes' => array(),
  );

  return render($build) . theme('pager');
}

/**
 * Page callback to enable or disable subscription by $sid.
 */
function node_notify_node_enable_subscription_page($node, $sid, $enable = TRUE) {
  db_update('node_notify_subscription')
    ->condition('sid', $sid)
    ->fields(array('enabled' => (int) $enable))
    ->execute();

  drupal_goto(drupal_get_destination());
}

/**
 * Page to display account's subscriptions.
 */
function node_notify_user_subscriptions_page($account) {
  $header = array(
    array('data' => t('Title'), 'field' => 'title', 'sort' => 'asc'),
    array('data' => t('Date'), 'field' => 'subscribed_on', 'sort' => 'desc'),
    '',
  );

  $query = db_select('node_notify_subscription', 's');
  $query->leftJoin('node', 'n', '(s.nid = n.nid)');
  $query->fields('s', array('sid', 'subscribed_on', 'nid', 'uid', 'enabled'));
  $query->fields('n', array('title'));
  $query->condition('s.uid', $account->uid);

  $query
    ->extend('PagerDefault')->limit(20)
    ->extend('TableSort')->orderByHeader($header);

  $rows = array();
  foreach ($query->execute() as $record) {
    $url = 'user/' . $account->uid . '/subscriptions/' . $record->sid;
    $rows[] = array(
      l($record->title, 'node/' . $record->nid),
      format_date($record->subscribed_on),
      $record->enabled ?
      l(t('Disable'), $url . '/disable', array('query' => drupal_get_destination())) :
      l(t('Enable'), $url . '/enable', array('query' => drupal_get_destination())),
    );
  }

  $build = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No subscriptions yet.'),
    // '#attributes' => array(),
  );

  return render($build) . theme('pager');
}

/**
 * Page callback to enable/disable subscription.
 */
function node_notify_user_enable_subscription_page($account, $sid, $enable = TRUE) {
  db_update('node_notify_subscription')
    ->condition('sid', $sid)
    ->condition('uid', $account->uid)
    ->fields(array('enabled' => (int) $enable))
    ->execute();

  drupal_goto(drupal_get_destination());
}
