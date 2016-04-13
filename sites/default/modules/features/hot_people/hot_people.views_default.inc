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
  $view->name = 'leadership';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Leadership';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Our board';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Flags: board_member */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'executive_director';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'board_member';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'medium_square';
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[field_name]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: User: HOT Board function */
  $handler->display->display_options['fields']['field_hot_leadership']['id'] = 'field_hot_leadership';
  $handler->display->display_options['fields']['field_hot_leadership']['table'] = 'field_data_field_hot_leadership';
  $handler->display->display_options['fields']['field_hot_leadership']['field'] = 'field_hot_leadership';
  $handler->display->display_options['fields']['field_hot_leadership']['label'] = '';
  $handler->display->display_options['fields']['field_hot_leadership']['element_label_colon'] = FALSE;
  /* Field: User: Bio */
  $handler->display->display_options['fields']['field_bio']['id'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['table'] = 'field_data_field_bio';
  $handler->display->display_options['fields']['field_bio']['field'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['label'] = '';
  $handler->display->display_options['fields']['field_bio']['element_label_colon'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Board pane */
  $handler = $view->new_display('panel_pane', 'Board pane', 'panel_pane_board');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Draggableviews: User */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'users';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['save_button_label'] = 'Save order';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'medium_square';
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[field_name]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: User: HOT Board function */
  $handler->display->display_options['fields']['field_hot_leadership']['id'] = 'field_hot_leadership';
  $handler->display->display_options['fields']['field_hot_leadership']['table'] = 'field_data_field_hot_leadership';
  $handler->display->display_options['fields']['field_hot_leadership']['field'] = 'field_hot_leadership';
  $handler->display->display_options['fields']['field_hot_leadership']['label'] = '';
  $handler->display->display_options['fields']['field_hot_leadership']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hot_leadership']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Bio */
  $handler->display->display_options['fields']['field_bio']['id'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['table'] = 'field_data_field_bio';
  $handler->display->display_options['fields']['field_bio']['field'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['label'] = '';
  $handler->display->display_options['fields']['field_bio']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'self';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;

  /* Display: Director pane */
  $handler = $view->new_display('panel_pane', 'Director pane', 'panel_pane_director');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Executive director';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'medium_square';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Bio */
  $handler->display->display_options['fields']['field_bio']['id'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['table'] = 'field_data_field_bio';
  $handler->display->display_options['fields']['field_bio']['field'] = 'field_bio';
  $handler->display->display_options['fields']['field_bio']['label'] = '';
  $handler->display->display_options['fields']['field_bio']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: HOT staff type (field_hot_staff_type) */
  $handler->display->display_options['filters']['field_hot_staff_type_tid']['id'] = 'field_hot_staff_type_tid';
  $handler->display->display_options['filters']['field_hot_staff_type_tid']['table'] = 'field_data_field_hot_staff_type';
  $handler->display->display_options['filters']['field_hot_staff_type_tid']['field'] = 'field_hot_staff_type_tid';
  $handler->display->display_options['filters']['field_hot_staff_type_tid']['value'] = array(
    0 => '221',
  );
  $handler->display->display_options['filters']['field_hot_staff_type_tid']['expose']['operator_id'] = 'field_hot_staff_type_tid_op';
  $handler->display->display_options['filters']['field_hot_staff_type_tid']['expose']['label'] = 'HOT staff type (field_hot_staff_type)';
  $handler->display->display_options['filters']['field_hot_staff_type_tid']['expose']['operator'] = 'field_hot_staff_type_tid_op';
  $handler->display->display_options['filters']['field_hot_staff_type_tid']['expose']['identifier'] = 'field_hot_staff_type_tid';
  $handler->display->display_options['filters']['field_hot_staff_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_hot_staff_type_tid']['vocabulary'] = 'hot_staff';
  $translatables['leadership'] = array(
    t('Master'),
    t('Our board'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('executive_director'),
    t('[field_name]'),
    t('Board pane'),
    t('View panes'),
    t('Director pane'),
    t('Executive director'),
    t('HOT staff type (field_hot_staff_type)'),
  );
  $export['leadership'] = $view;

  $view = new view();
  $view->name = 'staff_contractors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Staff & Contractors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Volunteer leads';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Flags: staff */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'staff';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'medium_square';
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[field_name]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: User: HOT staff position */
  $handler->display->display_options['fields']['field_hot_staff_position']['id'] = 'field_hot_staff_position';
  $handler->display->display_options['fields']['field_hot_staff_position']['table'] = 'field_data_field_hot_staff_position';
  $handler->display->display_options['fields']['field_hot_staff_position']['field'] = 'field_hot_staff_position';
  $handler->display->display_options['fields']['field_hot_staff_position']['label'] = '';
  $handler->display->display_options['fields']['field_hot_staff_position']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: User */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'users';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Sort criterion: Draggableviews: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'leadership:panel_pane_board';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Contextual filter: User: HOT staff type (field_hot_staff_type) */
  $handler->display->display_options['arguments']['field_hot_staff_type_tid']['id'] = 'field_hot_staff_type_tid';
  $handler->display->display_options['arguments']['field_hot_staff_type_tid']['table'] = 'field_data_field_hot_staff_type';
  $handler->display->display_options['arguments']['field_hot_staff_type_tid']['field'] = 'field_hot_staff_type_tid';
  $handler->display->display_options['arguments']['field_hot_staff_type_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_hot_staff_type_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_hot_staff_type_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_hot_staff_type_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_hot_staff_type_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Staff & contractors */
  $handler = $view->new_display('panel_pane', 'Staff & contractors', 'panel_pane_staff');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_hot_staff_type_tid' => array(
      'type' => 'user',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'User: HOT staff type (field_hot_staff_type)',
    ),
  );

  /* Display: Volunteer leads */
  $handler = $view->new_display('panel_pane', 'Volunteer leads', 'panel_pane_volunteer_leads');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: volunteer_lead */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'volunteer_lead';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'medium_square';
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[field_name]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  /* Field: User: Volunteer lead role */
  $handler->display->display_options['fields']['field_volunteer_lead_role']['id'] = 'field_volunteer_lead_role';
  $handler->display->display_options['fields']['field_volunteer_lead_role']['table'] = 'field_data_field_volunteer_lead_role';
  $handler->display->display_options['fields']['field_volunteer_lead_role']['field'] = 'field_volunteer_lead_role';
  $handler->display->display_options['fields']['field_volunteer_lead_role']['label'] = '';
  $handler->display->display_options['fields']['field_volunteer_lead_role']['element_label_colon'] = FALSE;
  /* Field: Draggableviews: User */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'users';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = '';
  $handler->display->display_options['fields']['draggableviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $translatables['staff_contractors'] = array(
    t('Master'),
    t('Volunteer leads'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('flag'),
    t('[field_name]'),
    t('All'),
    t('Staff & contractors'),
    t('View panes'),
  );
  $export['staff_contractors'] = $view;

  $view = new view();
  $view->name = 'user_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User admin';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'picture' => 'picture',
    'name' => 'name',
    'field_name' => 'field_name',
    'field_country' => 'field_country',
    'rid' => 'rid',
    'flagged' => 'flagged',
    'flagged_1' => 'flagged_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'flagged' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'flagged_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Flags: voting_member */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'voting-member-flag`';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'voting_member';
  /* Relationship: Flags: staff */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'staff-flag';
  $handler->display->display_options['relationships']['flag_content_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'staff';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = 'Avatar';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'small_square';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['text'] = '[field_name] ([name])';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name']['empty'] = 'Missing full name ([name])';
  $handler->display->display_options['fields']['field_name']['hide_alter_empty'] = FALSE;
  /* Field: User: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Voting member';
  $handler->display->display_options['fields']['flagged']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged_1']['id'] = 'flagged_1';
  $handler->display->display_options['fields']['flagged_1']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged_1']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['fields']['flagged_1']['label'] = 'Staff';
  $handler->display->display_options['fields']['flagged_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['flagged_1']['not'] = 0;
  /* Sort criterion: User: Full name (field_name) */
  $handler->display->display_options['sorts']['field_name_value']['id'] = 'field_name_value';
  $handler->display->display_options['sorts']['field_name_value']['table'] = 'field_data_field_name';
  $handler->display->display_options['sorts']['field_name_value']['field'] = 'field_name_value';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Users admin */
  $handler = $view->new_display('page', 'Users admin', 'page');
  $handler->display->display_options['path'] = 'admin/hot-users';

  /* Display: Mass contact */
  $handler = $view->new_display('page', 'Mass contact', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['text'] = '[field_name] ([name])';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name']['empty'] = 'Missing full name ([name])';
  $handler->display->display_options['fields']['field_name']['hide_alter_empty'] = FALSE;
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['label'] = 'Link to profile';
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_user']['text'] = 'profile';
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Voting member';
  $handler->display->display_options['fields']['flagged']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Field: Global: Send e-mail */
  $handler->display->display_options['fields']['views_send']['id'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['table'] = 'views';
  $handler->display->display_options['fields']['views_send']['field'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['label'] = 'Send mail';
  $handler->display->display_options['fields']['views_send']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'website of the Humanitarian OpenStreetMap Team';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'http://hotosm.org';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'me';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'mailto:felix.delattre@hotosm.org';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'user login';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'http://hotosm.org/user';
  $handler->display->display_options['fields']['nothing_2']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['path'] = 'admin/mass-contact';
  $translatables['user_admin'] = array(
    t('Master'),
    t('User admin'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('voting-member-flag`'),
    t('staff-flag'),
    t('Avatar'),
    t('Name'),
    t('[field_name] ([name])'),
    t('Missing full name ([name])'),
    t('Country'),
    t('Roles'),
    t('Voting member'),
    t('Staff'),
    t('Users admin'),
    t('Mass contact'),
    t('Link to profile'),
    t('profile'),
    t('Send mail'),
    t('website of the Humanitarian OpenStreetMap Team'),
    t('me'),
    t('user login'),
  );
  $export['user_admin'] = $view;

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
  $handler->display->display_options['title'] = 'Members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<img src="/sites/default/themes/hot/images/avatar_100.png" />';
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'small_square';
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_name']['settings'] = array(
    'title_style' => '_none',
    'title_link' => '',
    'title_class' => '',
  );
  /* Field: User: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = '';
  $handler->display->display_options['fields']['field_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = '[picture]
<span class="text-content"><span><div class="full-name">[field_name]</div><br />[field_country]</span></span>';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Sort criterion: User: Full name (field_name) */
  $handler->display->display_options['sorts']['field_name_value']['id'] = 'field_name_value';
  $handler->display->display_options['sorts']['field_name_value']['table'] = 'field_data_field_name';
  $handler->display->display_options['sorts']['field_name_value']['field'] = 'field_name_value';
  /* Filter criterion: User: Full name (field_name) */
  $handler->display->display_options['filters']['field_name_value']['id'] = 'field_name_value';
  $handler->display->display_options['filters']['field_name_value']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name_value']['field'] = 'field_name_value';
  $handler->display->display_options['filters']['field_name_value']['operator'] = 'not empty';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Pane: Voting members */
  $handler = $view->new_display('panel_pane', 'Pane: Voting members', 'panel_pane_members_voting');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Voting members';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: voting_member */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'voting member';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'voting_member';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Full name (field_name) */
  $handler->display->display_options['filters']['field_name_value']['id'] = 'field_name_value';
  $handler->display->display_options['filters']['field_name_value']['table'] = 'field_data_field_name';
  $handler->display->display_options['filters']['field_name_value']['field'] = 'field_name_value';
  $handler->display->display_options['filters']['field_name_value']['operator'] = 'not empty';
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '1';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Pane: Members by working group */
  $handler = $view->new_display('panel_pane', 'Pane: Members by working group', 'panel_pane_members_wg');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Members by working group';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Working group (field_working_group) */
  $handler->display->display_options['arguments']['field_working_group_nid']['id'] = 'field_working_group_nid';
  $handler->display->display_options['arguments']['field_working_group_nid']['table'] = 'field_data_field_working_group';
  $handler->display->display_options['arguments']['field_working_group_nid']['field'] = 'field_working_group_nid';
  $handler->display->display_options['arguments']['field_working_group_nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_working_group_nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_working_group_nid']['title'] = 'Members of %1 working group';
  $handler->display->display_options['arguments']['field_working_group_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_working_group_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_working_group_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_working_group_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'field_working_group_nid' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Field: Working group (field_working_group)',
    ),
  );

  /* Display: Page: Working groups */
  $handler = $view->new_display('page', 'Page: Working groups', 'page_working_groups_with_members');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Working groups';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'body',
      'rendered' => 0,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Working group (field_working_group) */
  $handler->display->display_options['relationships']['field_working_group_nid']['id'] = 'field_working_group_nid';
  $handler->display->display_options['relationships']['field_working_group_nid']['table'] = 'field_data_field_working_group';
  $handler->display->display_options['relationships']['field_working_group_nid']['field'] = 'field_working_group_nid';
  $handler->display->display_options['relationships']['field_working_group_nid']['label'] = 'working_group';
  $handler->display->display_options['relationships']['field_working_group_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_working_group_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_working_group_nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_working_group_nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_working_group_nid';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '</h3><h3>[title]</h3>
<div>[body]</div>';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<img src="/sites/default/themes/hot/images/avatar_100.png" />';
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'small_square';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'field_working_group_nid';
  /* Sort criterion: User: Full name (field_name) */
  $handler->display->display_options['sorts']['field_name_value']['id'] = 'field_name_value';
  $handler->display->display_options['sorts']['field_name_value']['table'] = 'field_data_field_name';
  $handler->display->display_options['sorts']['field_name_value']['field'] = 'field_name_value';
  $handler->display->display_options['path'] = 'working-groups';

  /* Display: Block: Members by working group */
  $handler = $view->new_display('block', 'Block: Members by working group', 'block_wg_members');
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
    t('Members'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<img src="/sites/default/themes/hot/images/avatar_100.png" />'),
    t('[picture]
<span class="text-content"><span><div class="full-name">[field_name]</div><br />[field_country]</span></span>'),
    t('Pane: Voting members'),
    t('Voting members'),
    t('voting member'),
    t('View panes'),
    t('Pane: Members by working group'),
    t('Members by working group'),
    t('All'),
    t('Members of %1 working group'),
    t('Page: Working groups'),
    t('Working groups'),
    t('working_group'),
    t('</h3><h3>[title]</h3>
<div>[body]</div>'),
    t('Block: Members by working group'),
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
  /* Field: User: Full name */
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
  $handler->display->display_options['fields']['uid']['label'] = 'Contact by ';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = 'Email';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'user/[uid]/contact';
  $handler->display->display_options['fields']['uid']['element_class'] = 'inline';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: HOT Board function */
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
    t('Contact by '),
    t('Email'),
    t('HOT'),
    t('Projects'),
    t('Working group'),
    t('User bio'),
  );
  $export['user_profile'] = $view;

  return $export;
}
