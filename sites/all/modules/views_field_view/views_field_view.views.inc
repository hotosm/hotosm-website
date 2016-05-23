<?php

/**
 * @file
 * Views integration for the views_field_view module.
 */

/**
 * Implements hook_views_data_alter().
 */
function views_field_view_views_data_alter(&$data) {
  $data['views']['view']['field'] = array(
    'title' => t('View'),
    'help' => t('Embed a view as a field. This can cause slow performance, so enable some caching.'),
    'handler' => 'views_field_view_handler_field_view',
  );
  $data['views']['view_field'] = array(
    'title' => t('View (Views field view)'),
    'help' => t('Embed a view in an area. This can cause slow performance, so enable some caching.'),
    'area' => array(
      'help' => t('Embed a views_field_view field in an area. This can also accept argument tokens.'),
      'handler' => 'views_field_view_handler_field_view',
    ),
  );
}
