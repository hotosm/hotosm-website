<?php
/**
 * @file
 * hot_jobs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hot_jobs_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'jobs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Jobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Jobs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
    4 => '4',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Application deadline */
  $handler->display->display_options['fields']['field_application_deadline']['id'] = 'field_application_deadline';
  $handler->display->display_options['fields']['field_application_deadline']['table'] = 'field_data_field_application_deadline';
  $handler->display->display_options['fields']['field_application_deadline']['field'] = 'field_application_deadline';
  $handler->display->display_options['fields']['field_application_deadline']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_application_deadline']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Place of work */
  $handler->display->display_options['fields']['field_place']['id'] = 'field_place';
  $handler->display->display_options['fields']['field_place']['table'] = 'field_data_field_place';
  $handler->display->display_options['fields']['field_place']['field'] = 'field_place';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'More information';
  /* Sort criterion: Content: Application deadline (field_application_deadline) */
  $handler->display->display_options['sorts']['field_application_deadline_value']['id'] = 'field_application_deadline_value';
  $handler->display->display_options['sorts']['field_application_deadline_value']['table'] = 'field_data_field_application_deadline';
  $handler->display->display_options['sorts']['field_application_deadline_value']['field'] = 'field_application_deadline_value';
  $handler->display->display_options['sorts']['field_application_deadline_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );

  /* Display: Open job offers */
  $handler = $view->new_display('panel_pane', 'Open job offers', 'panel_pane_jobs_open');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );
  /* Filter criterion: Content: Application deadline (field_application_deadline) */
  $handler->display->display_options['filters']['field_application_deadline_value']['id'] = 'field_application_deadline_value';
  $handler->display->display_options['filters']['field_application_deadline_value']['table'] = 'field_data_field_application_deadline';
  $handler->display->display_options['filters']['field_application_deadline_value']['field'] = 'field_application_deadline_value';
  $handler->display->display_options['filters']['field_application_deadline_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_application_deadline_value']['default_date'] = 'now';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Closed job offers */
  $handler = $view->new_display('panel_pane', 'Closed job offers', 'panel_pane_jobs_closed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Past job offers';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );
  /* Filter criterion: Content: Application deadline (field_application_deadline) */
  $handler->display->display_options['filters']['field_application_deadline_value']['id'] = 'field_application_deadline_value';
  $handler->display->display_options['filters']['field_application_deadline_value']['table'] = 'field_data_field_application_deadline';
  $handler->display->display_options['filters']['field_application_deadline_value']['field'] = 'field_application_deadline_value';
  $handler->display->display_options['filters']['field_application_deadline_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_application_deadline_value']['default_date'] = 'now';
  $translatables['jobs'] = array(
    t('Master'),
    t('Jobs'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Application deadline'),
    t('Place of work'),
    t('More information'),
    t('Open job offers'),
    t('View panes'),
    t('Closed job offers'),
    t('Past job offers'),
  );
  $export['jobs'] = $view;

  return $export;
}
