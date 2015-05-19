<?php

/**
 * Implements hook_views_data_alter().
 */
function views_send_views_data_alter(&$data) {
  $data['views']['views_send'] = array(
    'title' => t('Send e-mail'),
    'help' => t('Provide a checkbox to select the row for e-mail sending.'),
    'field' => array(
      'handler' => 'views_send_handler_field_selector',
      'click sortable' => FALSE,
    ),
  );
}
