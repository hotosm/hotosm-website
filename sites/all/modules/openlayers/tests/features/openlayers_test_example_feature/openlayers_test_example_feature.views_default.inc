<?php
/**
 * @file
 * openlayers_test_example_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function openlayers_test_example_feature_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'openlayers_example_data_overlay';
  $view->description = 'This is an example OpenLayers Data Overlay using the OpenLayers Example Content';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'OpenLayers Example Data Overlay';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'OpenLayers Example Content';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_openlayers_example_input',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => 'body',
    'view_mode' => 'full',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: OpenLayers Example Geofield Input */
  $handler->display->display_options['fields']['field_openlayers_example_input']['id'] = 'field_openlayers_example_input';
  $handler->display->display_options['fields']['field_openlayers_example_input']['table'] = 'field_data_field_openlayers_example_input';
  $handler->display->display_options['fields']['field_openlayers_example_input']['field'] = 'field_openlayers_example_input';
  $handler->display->display_options['fields']['field_openlayers_example_input']['label'] = '';
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_openlayers_example_input']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_openlayers_example_input']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_openlayers_example_input']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_openlayers_example_input']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_openlayers_example_input']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_openlayers_example_input']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'openlayers_example_content' => 'openlayers_example_content',
  );

  /* Display: OpenLayers Example Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Example Data Overlay', 'openlayers_1');
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $export['openlayers_example_data_overlay'] = $view;

  $view = new view;
  $view->name = 'openlayers_example_map_display_view';
  $view->description = 'View to display the OpenLayers Example Map.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'OpenLayers Example Map Display View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'OpenLayers Example Map Display View';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'openlayers_test_openlayers_example_map';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: OpenLayers Map Display */
  $handler = $view->new_display('page', 'OpenLayers Map Display', 'page');
  $handler->display->display_options['path'] = 'openlayers-example-map-display';
  $export['openlayers_example_map_display_view'] = $view;

  return $export;
}
