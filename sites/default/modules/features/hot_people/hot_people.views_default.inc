<?php
/**
 * @file
 * hot_people.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hot_people_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_lists';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User lists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'avatar';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[picture] [name] ';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_class'] = 'inline';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';

  /* Display: WG members block */
  $handler = $view->new_display('block', 'WG members block', 'block');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Working group (field_working_group) */
  $handler->display->display_options['arguments']['field_working_group_nid']['id'] = 'field_working_group_nid';
  $handler->display->display_options['arguments']['field_working_group_nid']['table'] = 'field_data_field_working_group';
  $handler->display->display_options['arguments']['field_working_group_nid']['field'] = 'field_working_group_nid';
  $handler->display->display_options['arguments']['field_working_group_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_working_group_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_working_group_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_working_group_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_working_group_nid']['summary_options']['items_per_page'] = '25';
  $translatables['user_lists'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('[picture] [name] '),
    t('WG members block'),
    t('All'),
  );
  $export['user_lists'] = $view;

  $view = new view();
  $view->name = 'user_profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: User details block */
  $handler = $view->new_display('block', 'User details block', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['element_type'] = 'h2';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name']['element_default_classes'] = FALSE;
  /* Field: User: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = '';
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_country']['delta_offset'] = '0';
  /* Field: User: Twitter handle */
  $handler->display->display_options['fields']['field_twitter']['id'] = 'field_twitter';
  $handler->display->display_options['fields']['field_twitter']['table'] = 'field_data_field_twitter';
  $handler->display->display_options['fields']['field_twitter']['field'] = 'field_twitter';
  $handler->display->display_options['fields']['field_twitter']['label'] = 'Twitter';
  $handler->display->display_options['fields']['field_twitter']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_twitter']['alter']['path'] = 'https://twitter.com/[field_twitter]';
  $handler->display->display_options['fields']['field_twitter']['element_class'] = 'inline';
  $handler->display->display_options['fields']['field_twitter']['element_default_classes'] = FALSE;
  /* Field: User: OSM user name */
  $handler->display->display_options['fields']['field_osm_user_name']['id'] = 'field_osm_user_name';
  $handler->display->display_options['fields']['field_osm_user_name']['table'] = 'field_data_field_osm_user_name';
  $handler->display->display_options['fields']['field_osm_user_name']['field'] = 'field_osm_user_name';
  $handler->display->display_options['fields']['field_osm_user_name']['label'] = 'OSM';
  $handler->display->display_options['fields']['field_osm_user_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_osm_user_name']['alter']['path'] = 'http://www.openstreetmap.org/user/[field_osm_user_name]';
  $handler->display->display_options['fields']['field_osm_user_name']['element_class'] = 'inline';
  $handler->display->display_options['fields']['field_osm_user_name']['element_default_classes'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Contcact by ';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = 'Email';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'user/[uid]/contact';
  $handler->display->display_options['fields']['uid']['element_class'] = 'inline';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: HOT leadership */
  $handler->display->display_options['fields']['field_hot_leadership']['id'] = 'field_hot_leadership';
  $handler->display->display_options['fields']['field_hot_leadership']['table'] = 'field_data_field_hot_leadership';
  $handler->display->display_options['fields']['field_hot_leadership']['field'] = 'field_hot_leadership';
  $handler->display->display_options['fields']['field_hot_leadership']['label'] = 'HOT';
  $handler->display->display_options['fields']['field_hot_leadership']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_hot_leadership']['element_label_class'] = 'info';
  $handler->display->display_options['fields']['field_hot_leadership']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_hot_leadership']['hide_empty'] = TRUE;
  /* Field: User: Projects */
  $handler->display->display_options['fields']['field_projects']['id'] = 'field_projects';
  $handler->display->display_options['fields']['field_projects']['table'] = 'field_data_field_projects';
  $handler->display->display_options['fields']['field_projects']['field'] = 'field_projects';
  $handler->display->display_options['fields']['field_projects']['element_class'] = 'no-style';
  $handler->display->display_options['fields']['field_projects']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_projects']['element_label_class'] = 'info';
  $handler->display->display_options['fields']['field_projects']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_projects']['type'] = 'node_reference_node';
  $handler->display->display_options['fields']['field_projects']['settings'] = array(
    'node_reference_view_mode' => 'title',
  );
  $handler->display->display_options['fields']['field_projects']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_projects']['multi_type'] = 'ul';
  /* Field: Field: Working group */
  $handler->display->display_options['fields']['field_working_group']['id'] = 'field_working_group';
  $handler->display->display_options['fields']['field_working_group']['table'] = 'field_data_field_working_group';
  $handler->display->display_options['fields']['field_working_group']['field'] = 'field_working_group';
  $handler->display->display_options['fields']['field_working_group']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_working_group']['element_label_class'] = 'info';
  $handler->display->display_options['fields']['field_working_group']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_working_group']['delta_offset'] = '0';
  /* Field: User: Working group role */
  $handler->display->display_options['fields']['field_working_group_role']['id'] = 'field_working_group_role';
  $handler->display->display_options['fields']['field_working_group_role']['table'] = 'field_data_field_working_group_role';
  $handler->display->display_options['fields']['field_working_group_role']['field'] = 'field_working_group_role';
  $handler->display->display_options['fields']['field_working_group_role']['label'] = '';
  $handler->display->display_options['fields']['field_working_group_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_working_group_role']['element_default_classes'] = FALSE;

  /* Display: User bio */
  $handler = $view->new_display('block', 'User bio', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Bio */
  $handler->display->display_options['fields']['field_bio']['id'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['table'] = 'field_data_field_bio';
  $handler->display->display_options['fields']['field_bio']['field'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['label'] = '';
  $handler->display->display_options['fields']['field_bio']['element_label_colon'] = FALSE;
  $translatables['user_profile'] = array(
    t('Master'),
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
    t('All'),
    t('User details block'),
    t('Twitter'),
    t('OSM'),
    t('Contcact by '),
    t('Email'),
    t('HOT'),
    t('Projects'),
    t('Working group'),
    t('User bio'),
  );
  $export['user_profile'] = $view;

  return $export;
}
