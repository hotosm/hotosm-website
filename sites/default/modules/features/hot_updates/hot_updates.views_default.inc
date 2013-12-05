<?php
/**
 * @file
 * hot_updates.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hot_updates_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'updates';
  $view->description = 'News and updates from HOT';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Updates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent Updates';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'More updates';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_class'] = 'node-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'Posted by [name] on [created]';
  $handler->display->display_options['fields']['created']['element_type'] = 'em';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more...';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'update' => 'update',
  );
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';

  /* Display: All updates page */
  $handler = $view->new_display('page', 'All updates page', 'updates_all_page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<a href="/feed/rss2" class="feed-icon" title="Subscribe to Recent Updates"><img src="http://dev-d7-hot.gotpantheon.com/misc/feed.png" width="16" height="16" alt="Subscribe to Recent Updates" /></a>';
  $handler->display->display_options['path'] = 'updates';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Updates';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: All updates feed */
  $handler = $view->new_display('feed', 'All updates feed', 'updates_all_feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent Updates';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'rss';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'feed';
  $handler->display->display_options['displays'] = array(
    'updates_all_block' => 'updates_all_block',
    'default' => 0,
    'updates_all_page' => 0,
    'updates_project_block' => 0,
  );
  $handler->display->display_options['sitename_title'] = 1;

  /* Display: All updates block */
  $handler = $view->new_display('block', 'All updates block', 'updates_all_block');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More updates';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['block_title'] = array(
    'more_link' => 0,
    'feed_icon' => 1,
    'wrapper' => array(
      'use' => 0,
      'element' => 'div',
      'custom_class' => 0,
      'classes' => '',
    ),
  );

  /* Display: Project updates block */
  $handler = $view->new_display('block', 'Project updates block', 'updates_project_block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Related Project (field_update_project) */
  $handler->display->display_options['arguments']['field_update_project_nid']['id'] = 'field_update_project_nid';
  $handler->display->display_options['arguments']['field_update_project_nid']['table'] = 'field_data_field_update_project';
  $handler->display->display_options['arguments']['field_update_project_nid']['field'] = 'field_update_project_nid';
  $handler->display->display_options['arguments']['field_update_project_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_update_project_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_update_project_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_update_project_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_update_project_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_update_project_nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_update_project_nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_update_project_nid']['validate_options']['types'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['block_title'] = array(
    'more_link' => 0,
    'feed_icon' => 1,
    'wrapper' => array(
      'use' => 0,
      'element' => 'div',
      'custom_class' => 0,
      'classes' => '',
    ),
  );

  /* Display: Project updates feed */
  $handler = $view->new_display('feed', 'Project updates feed', 'updates_project_feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'rss';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Related Project (field_update_project) */
  $handler->display->display_options['arguments']['field_update_project_nid']['id'] = 'field_update_project_nid';
  $handler->display->display_options['arguments']['field_update_project_nid']['table'] = 'field_data_field_update_project';
  $handler->display->display_options['arguments']['field_update_project_nid']['field'] = 'field_update_project_nid';
  $handler->display->display_options['arguments']['field_update_project_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_update_project_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_update_project_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_update_project_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_update_project_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_update_project_nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_update_project_nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_update_project_nid']['validate_options']['types'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['path'] = 'project/%/updates/feed';
  $handler->display->display_options['displays'] = array(
    'updates_project_block' => 'updates_project_block',
    'default' => 0,
    'updates_all_page' => 0,
    'updates_all_block' => 0,
  );
  $translatables['updates'] = array(
    t('Master'),
    t('Recent Updates'),
    t('More updates'),
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
    t('author'),
    t('Posted by [name] on [created]'),
    t('Read more...'),
    t('All updates page'),
    t('more'),
    t('<a href="/feed/rss2" class="feed-icon" title="Subscribe to Recent Updates"><img src="http://dev-d7-hot.gotpantheon.com/misc/feed.png" width="16" height="16" alt="Subscribe to Recent Updates" /></a>'),
    t('All updates feed'),
    t('All updates block'),
    t('Project updates block'),
    t('All'),
    t('Project updates feed'),
  );
  $export['updates'] = $view;

  return $export;
}
