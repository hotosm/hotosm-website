<?php

$view = new view();
$view->name = 'paypal_donationss';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'paypal_donations_item';
$view->human_name = 'PayPal donations';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'PayPal donations';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view paypal donations entities';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'created' => 'created',
  'field_paypal_donations_amount' => 'field_paypal_donations_amount',
  'field_paypal_donator_email' => 'field_paypal_donator_email',
  'field_paypal_donator_name' => 'field_paypal_donator_name',
  'field_paypal_donator_country' => 'field_paypal_donator_country',
  'field_paypal_donations_type' => 'field_paypal_donations_type',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_paypal_donations_amount' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_paypal_donator_email' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_paypal_donator_name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_paypal_donator_country' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_paypal_donations_type' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: PayPal donation: Donation time */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'paypal_donations_item';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['date_format'] = 'long';
/* Field: PayPal donation: PayPal donation amount */
$handler->display->display_options['fields']['field_paypal_donations_amount']['id'] = 'field_paypal_donations_amount';
$handler->display->display_options['fields']['field_paypal_donations_amount']['table'] = 'field_data_field_paypal_donations_amount';
$handler->display->display_options['fields']['field_paypal_donations_amount']['field'] = 'field_paypal_donations_amount';
$handler->display->display_options['fields']['field_paypal_donations_amount']['settings'] = array(
  'thousand_separator' => ' ',
  'decimal_separator' => '.',
  'scale' => '2',
  'prefix_suffix' => 1,
);
/* Field: PayPal donation: PayPal donation e-mail */
$handler->display->display_options['fields']['field_paypal_donator_email']['id'] = 'field_paypal_donator_email';
$handler->display->display_options['fields']['field_paypal_donator_email']['table'] = 'field_data_field_paypal_donator_email';
$handler->display->display_options['fields']['field_paypal_donator_email']['field'] = 'field_paypal_donator_email';
/* Field: PayPal donation: PayPal donator name */
$handler->display->display_options['fields']['field_paypal_donator_name']['id'] = 'field_paypal_donator_name';
$handler->display->display_options['fields']['field_paypal_donator_name']['table'] = 'field_data_field_paypal_donator_name';
$handler->display->display_options['fields']['field_paypal_donator_name']['field'] = 'field_paypal_donator_name';
/* Field: PayPal donation: PayPal donator country */
$handler->display->display_options['fields']['field_paypal_donator_country']['id'] = 'field_paypal_donator_country';
$handler->display->display_options['fields']['field_paypal_donator_country']['table'] = 'field_data_field_paypal_donator_country';
$handler->display->display_options['fields']['field_paypal_donator_country']['field'] = 'field_paypal_donator_country';
$handler->display->display_options['fields']['field_paypal_donator_country']['label'] = 'PayPal donator name';
/* Field: PayPal donation: PayPal donation type */
$handler->display->display_options['fields']['field_paypal_donations_type']['id'] = 'field_paypal_donations_type';
$handler->display->display_options['fields']['field_paypal_donations_type']['table'] = 'field_data_field_paypal_donations_type';
$handler->display->display_options['fields']['field_paypal_donations_type']['field'] = 'field_paypal_donations_type';
/* Sort criterion: PayPal donation: Donation time */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'paypal_donations_item';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: PayPal donation: PayPal donation type (field_paypal_donations_type) */
$handler->display->display_options['filters']['field_paypal_donations_type_value']['id'] = 'field_paypal_donations_type_value';
$handler->display->display_options['filters']['field_paypal_donations_type_value']['table'] = 'field_data_field_paypal_donations_type';
$handler->display->display_options['filters']['field_paypal_donations_type_value']['field'] = 'field_paypal_donations_type_value';
$handler->display->display_options['filters']['field_paypal_donations_type_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_paypal_donations_type_value']['expose']['operator_id'] = 'field_paypal_donations_type_value_op';
$handler->display->display_options['filters']['field_paypal_donations_type_value']['expose']['label'] = 'Filter to type';
$handler->display->display_options['filters']['field_paypal_donations_type_value']['expose']['operator'] = 'field_paypal_donations_type_value_op';
$handler->display->display_options['filters']['field_paypal_donations_type_value']['expose']['identifier'] = 'field_paypal_donations_type_value';
$handler->display->display_options['filters']['field_paypal_donations_type_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
);
/* Filter criterion: PayPal donation: PayPal donation e-mail (field_paypal_donator_email) */
$handler->display->display_options['filters']['field_paypal_donator_email_value']['id'] = 'field_paypal_donator_email_value';
$handler->display->display_options['filters']['field_paypal_donator_email_value']['table'] = 'field_data_field_paypal_donator_email';
$handler->display->display_options['filters']['field_paypal_donator_email_value']['field'] = 'field_paypal_donator_email_value';
$handler->display->display_options['filters']['field_paypal_donator_email_value']['operator'] = 'contains';
$handler->display->display_options['filters']['field_paypal_donator_email_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_paypal_donator_email_value']['expose']['operator_id'] = 'field_paypal_donator_email_value_op';
$handler->display->display_options['filters']['field_paypal_donator_email_value']['expose']['label'] = 'Search e-mail';
$handler->display->display_options['filters']['field_paypal_donator_email_value']['expose']['operator'] = 'field_paypal_donator_email_value_op';
$handler->display->display_options['filters']['field_paypal_donator_email_value']['expose']['identifier'] = 'field_paypal_donator_email_value';
$handler->display->display_options['filters']['field_paypal_donator_email_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/content/paypal-donations';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'PayPal donations';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
