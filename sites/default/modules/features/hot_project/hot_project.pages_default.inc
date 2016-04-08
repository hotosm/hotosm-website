<?php
/**
 * @file
 * hot_project.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hot_project_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Project',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'project' => 'project',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'two_66_33';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'two_66_33_top' => NULL,
      'two_66_33_first' => NULL,
      'two_66_33_second' => NULL,
      'two_66_33_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '00e01bc7-6ed7-4c73-9cda-851a6ed324a5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8c995504-aade-4807-af76-e19d10bb58a2';
    $pane->panel = 'two_66_33_first';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8c995504-aade-4807-af76-e19d10bb58a2';
    $display->content['new-8c995504-aade-4807-af76-e19d10bb58a2'] = $pane;
    $display->panels['two_66_33_first'][0] = 'new-8c995504-aade-4807-af76-e19d10bb58a2';
    $pane = new stdClass();
    $pane->pid = 'new-48bece43-136f-4143-a3bf-9dc70b23c4e7';
    $pane->panel = 'two_66_33_first';
    $pane->type = 'views_panes';
    $pane->subtype = 'updates-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '48bece43-136f-4143-a3bf-9dc70b23c4e7';
    $display->content['new-48bece43-136f-4143-a3bf-9dc70b23c4e7'] = $pane;
    $display->panels['two_66_33_first'][1] = 'new-48bece43-136f-4143-a3bf-9dc70b23c4e7';
    $pane = new stdClass();
    $pane->pid = 'new-f620c3da-f520-45f1-847d-f363534f5834';
    $pane->panel = 'two_66_33_second';
    $pane->type = 'views_panes';
    $pane->subtype = 'project_ol_map-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'contact',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f620c3da-f520-45f1-847d-f363534f5834';
    $display->content['new-f620c3da-f520-45f1-847d-f363534f5834'] = $pane;
    $display->panels['two_66_33_second'][0] = 'new-f620c3da-f520-45f1-847d-f363534f5834';
    $pane = new stdClass();
    $pane->pid = 'new-91ece9f5-11b0-4765-a401-c4cc0c42900e';
    $pane->panel = 'two_66_33_second';
    $pane->type = 'views_panes';
    $pane->subtype = 'project_ol_map-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '91ece9f5-11b0-4765-a401-c4cc0c42900e';
    $display->content['new-91ece9f5-11b0-4765-a401-c4cc0c42900e'] = $pane;
    $display->panels['two_66_33_second'][1] = 'new-91ece9f5-11b0-4765-a401-c4cc0c42900e';
    $pane = new stdClass();
    $pane->pid = 'new-467b19fe-b7ee-46a4-8190-6a9104829be9';
    $pane->panel = 'two_66_33_second';
    $pane->type = 'views_panes';
    $pane->subtype = 'project_ol_map-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '467b19fe-b7ee-46a4-8190-6a9104829be9';
    $display->content['new-467b19fe-b7ee-46a4-8190-6a9104829be9'] = $pane;
    $display->panels['two_66_33_second'][2] = 'new-467b19fe-b7ee-46a4-8190-6a9104829be9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8c995504-aade-4807-af76-e19d10bb58a2';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function hot_project_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'projects';
  $page->task = 'page';
  $page->admin_title = 'Projects';
  $page->admin_description = '';
  $page->path = 'projects';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_projects__panel_context_1b35ecd3-38ef-4880-a8a2-1c39feae6774';
  $handler->task = 'page';
  $handler->subtask = 'projects';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Ongoing projects',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'projects/ongoing',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Ongoing projects';
  $display->uuid = '28326a7b-0c15-4b9a-80d7-cc2875f936d2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8496d9dd-a8e8-4ead-a75e-adcd757dd6e7';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '218',
      ),
      'override_title' => 1,
      'override_title_text' => '<a href="/projects/disaster-mapping">Disaster Mapping</a>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8496d9dd-a8e8-4ead-a75e-adcd757dd6e7';
    $display->content['new-8496d9dd-a8e8-4ead-a75e-adcd757dd6e7'] = $pane;
    $display->panels['center'][0] = 'new-8496d9dd-a8e8-4ead-a75e-adcd757dd6e7';
    $pane = new stdClass();
    $pane->pid = 'new-c585b20d-06dc-4dd7-9fb3-45c285cd8ac7';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '219',
      ),
      'override_title' => 1,
      'override_title_text' => '<a href="/projects/community">Community Development</a>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c585b20d-06dc-4dd7-9fb3-45c285cd8ac7';
    $display->content['new-c585b20d-06dc-4dd7-9fb3-45c285cd8ac7'] = $pane;
    $display->panels['center'][1] = 'new-c585b20d-06dc-4dd7-9fb3-45c285cd8ac7';
    $pane = new stdClass();
    $pane->pid = 'new-380b9910-bd76-4d9b-a9dc-b821397069b5';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '220',
      ),
      'override_title' => 1,
      'override_title_text' => '<a href="/projects/technical">Technical Projects</a>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '380b9910-bd76-4d9b-a9dc-b821397069b5';
    $display->content['new-380b9910-bd76-4d9b-a9dc-b821397069b5'] = $pane;
    $display->panels['center'][2] = 'new-380b9910-bd76-4d9b-a9dc-b821397069b5';
    $pane = new stdClass();
    $pane->pid = 'new-48e4a3d3-57a8-4629-a7ef-6985670b33b8';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '234',
      ),
      'override_title' => 1,
      'override_title_text' => '<a href="/projects/partnerships">Partnerships</a>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '48e4a3d3-57a8-4629-a7ef-6985670b33b8';
    $display->content['new-48e4a3d3-57a8-4629-a7ef-6985670b33b8'] = $pane;
    $display->panels['center'][3] = 'new-48e4a3d3-57a8-4629-a7ef-6985670b33b8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8496d9dd-a8e8-4ead-a75e-adcd757dd6e7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_projects__panel_context_123b96fa-0871-4dbf-b8fb-11239c35fec3';
  $handler->task = 'page';
  $handler->subtask = 'projects';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Projects startpage',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'projects',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fe9dba74-ea40-4b31-951c-e622d3ce4390';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8dd4873e-27c6-4e0f-b724-efb7052d1d17';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Description',
      'title' => '',
      'body' => '<p>When disaster strikes, HOT mobilizes our global network of thousands of volunteers who work together to map the impacted area in OpenStreetMap. We don\'t only do it after disaster: every day, HOT volunteers work tirelessly to put the most vulnerable people and places on the map before disasters strike. These maps contribute to saving lives in emergency.</p>',
      'format' => '1',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8dd4873e-27c6-4e0f-b724-efb7052d1d17';
    $display->content['new-8dd4873e-27c6-4e0f-b724-efb7052d1d17'] = $pane;
    $display->panels['middle'][0] = 'new-8dd4873e-27c6-4e0f-b724-efb7052d1d17';
    $pane = new stdClass();
    $pane->pid = 'new-bef44972-9963-42f0-857d-bec109c1e24f';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects_latest_disaster';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bef44972-9963-42f0-857d-bec109c1e24f';
    $display->content['new-bef44972-9963-42f0-857d-bec109c1e24f'] = $pane;
    $display->panels['middle'][1] = 'new-bef44972-9963-42f0-857d-bec109c1e24f';
    $pane = new stdClass();
    $pane->pid = 'new-00aa779d-1c51-4c05-9050-fa884541ec54';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects_latest_community';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '00aa779d-1c51-4c05-9050-fa884541ec54';
    $display->content['new-00aa779d-1c51-4c05-9050-fa884541ec54'] = $pane;
    $display->panels['middle'][2] = 'new-00aa779d-1c51-4c05-9050-fa884541ec54';
    $pane = new stdClass();
    $pane->pid = 'new-333dd1b7-6d9c-4516-9c1f-43aa84d0dc7f';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects_latest_technical';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '333dd1b7-6d9c-4516-9c1f-43aa84d0dc7f';
    $display->content['new-333dd1b7-6d9c-4516-9c1f-43aa84d0dc7f'] = $pane;
    $display->panels['middle'][3] = 'new-333dd1b7-6d9c-4516-9c1f-43aa84d0dc7f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_projects__panel_context_9c0db501-b353-44e8-b8f7-aa2df4ae52c9';
  $handler->task = 'page';
  $handler->subtask = 'projects';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Past projects',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'projects/complete',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Completed projects';
  $display->uuid = '28326a7b-0c15-4b9a-80d7-cc2875f936d2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1b50285c-a230-4e13-b75b-320034bd6a52';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects_old';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '218',
      ),
      'override_title' => 1,
      'override_title_text' => 'Disaster Mapping',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1b50285c-a230-4e13-b75b-320034bd6a52';
    $display->content['new-1b50285c-a230-4e13-b75b-320034bd6a52'] = $pane;
    $display->panels['center'][0] = 'new-1b50285c-a230-4e13-b75b-320034bd6a52';
    $pane = new stdClass();
    $pane->pid = 'new-56b282df-658a-49a6-821f-3ed27880c7fb';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects_old';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '219',
      ),
      'override_title' => 1,
      'override_title_text' => 'Community Development',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '56b282df-658a-49a6-821f-3ed27880c7fb';
    $display->content['new-56b282df-658a-49a6-821f-3ed27880c7fb'] = $pane;
    $display->panels['center'][1] = 'new-56b282df-658a-49a6-821f-3ed27880c7fb';
    $pane = new stdClass();
    $pane->pid = 'new-39be5c56-ad53-41f7-92b9-5e62837f37ec';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects_old';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '220',
      ),
      'override_title' => 1,
      'override_title_text' => 'Technical Projects',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '39be5c56-ad53-41f7-92b9-5e62837f37ec';
    $display->content['new-39be5c56-ad53-41f7-92b9-5e62837f37ec'] = $pane;
    $display->panels['center'][2] = 'new-39be5c56-ad53-41f7-92b9-5e62837f37ec';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_projects__panel_context_6d343c42-3701-4940-b5aa-d864e7ef712e';
  $handler->task = 'page';
  $handler->subtask = 'projects';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Disaster Mapping',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'projects/disaster-mapping',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Disaster Mapping Projects';
  $display->uuid = '28326a7b-0c15-4b9a-80d7-cc2875f936d2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-293769c3-3f67-407f-b5bd-a0ba24655d36';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Description',
      'title' => '',
      'body' => '<img src="/sites/default/themes/hot_theme/images/icons/emergency-mapping.jpg" alt=""><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec facilisis convallis placerat. Sed et venenatis neque. Integer metus massa, dictum sed elementum vel, suscipit eu justo. Praesent vestibulum pretium nisi non ullamcorper. Donec nunc diam, congue quis porttitor quis, congue eget magna. Fusce tincidunt justo non purus suscipit porttitor. Praesent quis congue ante. Sed pharetra neque fringilla sem sagittis commodo. Integer odio arcu, gravida at lacinia viverra, blandit sit amet justo. Donec varius sollicitudin ipsum ut consequat. Suspendisse potenti.</p>',
      'format' => '2',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '293769c3-3f67-407f-b5bd-a0ba24655d36';
    $display->content['new-293769c3-3f67-407f-b5bd-a0ba24655d36'] = $pane;
    $display->panels['center'][0] = 'new-293769c3-3f67-407f-b5bd-a0ba24655d36';
    $pane = new stdClass();
    $pane->pid = 'new-df8c9f31-b1e9-4216-9cd9-aee06637354b';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '218',
      ),
      'override_title' => 1,
      'override_title_text' => 'Ongoing Projects',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'df8c9f31-b1e9-4216-9cd9-aee06637354b';
    $display->content['new-df8c9f31-b1e9-4216-9cd9-aee06637354b'] = $pane;
    $display->panels['center'][1] = 'new-df8c9f31-b1e9-4216-9cd9-aee06637354b';
    $pane = new stdClass();
    $pane->pid = 'new-1b50285c-a230-4e13-b75b-320034bd6a52';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects_old';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '218',
      ),
      'override_title' => 1,
      'override_title_text' => 'Completed Projects',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '1b50285c-a230-4e13-b75b-320034bd6a52';
    $display->content['new-1b50285c-a230-4e13-b75b-320034bd6a52'] = $pane;
    $display->panels['center'][2] = 'new-1b50285c-a230-4e13-b75b-320034bd6a52';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_projects__panel_context_62405dba-258a-4023-a3de-3da74c85f532';
  $handler->task = 'page';
  $handler->subtask = 'projects';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Community development',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'projects/community',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Community Development Projects';
  $display->uuid = '28326a7b-0c15-4b9a-80d7-cc2875f936d2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ececfc65-ac49-45cf-8469-744522685eb8';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Description',
      'title' => '',
      'body' => '<img src="/sites/default/themes/hot_theme/images/icons/community.jpg" alt=""><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec facilisis convallis placerat. Sed et venenatis neque. Integer metus massa, dictum sed elementum vel, suscipit eu justo. Praesent vestibulum pretium nisi non ullamcorper. Donec nunc diam, congue quis porttitor quis, congue eget magna. Fusce tincidunt justo non purus suscipit porttitor. Praesent quis congue ante. Sed pharetra neque fringilla sem sagittis commodo. Integer odio arcu, gravida at lacinia viverra, blandit sit amet justo. Donec varius sollicitudin ipsum ut consequat. Suspendisse potenti.</p>',
      'format' => '2',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ececfc65-ac49-45cf-8469-744522685eb8';
    $display->content['new-ececfc65-ac49-45cf-8469-744522685eb8'] = $pane;
    $display->panels['center'][0] = 'new-ececfc65-ac49-45cf-8469-744522685eb8';
    $pane = new stdClass();
    $pane->pid = 'new-df8c9f31-b1e9-4216-9cd9-aee06637354b';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '219',
      ),
      'override_title' => 1,
      'override_title_text' => 'Ongoing Projects',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'df8c9f31-b1e9-4216-9cd9-aee06637354b';
    $display->content['new-df8c9f31-b1e9-4216-9cd9-aee06637354b'] = $pane;
    $display->panels['center'][1] = 'new-df8c9f31-b1e9-4216-9cd9-aee06637354b';
    $pane = new stdClass();
    $pane->pid = 'new-1b50285c-a230-4e13-b75b-320034bd6a52';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects_old';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '219',
      ),
      'override_title' => 1,
      'override_title_text' => 'Completed Projects',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '1b50285c-a230-4e13-b75b-320034bd6a52';
    $display->content['new-1b50285c-a230-4e13-b75b-320034bd6a52'] = $pane;
    $display->panels['center'][2] = 'new-1b50285c-a230-4e13-b75b-320034bd6a52';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_projects__panel_context_45fa0c42-2ff7-4298-ac1b-bfd618938c6d';
  $handler->task = 'page';
  $handler->subtask = 'projects';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Technical projects',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'projects/technical',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Technical Projects';
  $display->uuid = '28326a7b-0c15-4b9a-80d7-cc2875f936d2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-29fde7ae-58a4-44e3-a05a-1493ef335d86';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Description',
      'title' => '',
      'body' => '<img src="/sites/default/themes/hot_theme/images/icons/technical.jpg" alt=""><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec facilisis convallis placerat. Sed et venenatis neque. Integer metus massa, dictum sed elementum vel, suscipit eu justo. Praesent vestibulum pretium nisi non ullamcorper. Donec nunc diam, congue quis porttitor quis, congue eget magna. Fusce tincidunt justo non purus suscipit porttitor. Praesent quis congue ante. Sed pharetra neque fringilla sem sagittis commodo. Integer odio arcu, gravida at lacinia viverra, blandit sit amet justo. Donec varius sollicitudin ipsum ut consequat. Suspendisse potenti.</p>',
      'format' => '2',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '29fde7ae-58a4-44e3-a05a-1493ef335d86';
    $display->content['new-29fde7ae-58a4-44e3-a05a-1493ef335d86'] = $pane;
    $display->panels['center'][0] = 'new-29fde7ae-58a4-44e3-a05a-1493ef335d86';
    $pane = new stdClass();
    $pane->pid = 'new-df8c9f31-b1e9-4216-9cd9-aee06637354b';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '220',
      ),
      'override_title' => 1,
      'override_title_text' => 'Ongoing Projects',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'df8c9f31-b1e9-4216-9cd9-aee06637354b';
    $display->content['new-df8c9f31-b1e9-4216-9cd9-aee06637354b'] = $pane;
    $display->panels['center'][1] = 'new-df8c9f31-b1e9-4216-9cd9-aee06637354b';
    $pane = new stdClass();
    $pane->pid = 'new-1b50285c-a230-4e13-b75b-320034bd6a52';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'project-panel_pane_projects_old';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_project_type_tid' => '220',
      ),
      'override_title' => 1,
      'override_title_text' => 'Completed Projects',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '1b50285c-a230-4e13-b75b-320034bd6a52';
    $display->content['new-1b50285c-a230-4e13-b75b-320034bd6a52'] = $pane;
    $display->panels['center'][2] = 'new-1b50285c-a230-4e13-b75b-320034bd6a52';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page-projects__redirection';
  $handler->task = 'page';
  $handler->subtask = 'projects';
  $handler->handler = 'http_response';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => 'Redirection',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'projects',
    'name' => 'redirection',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['projects'] = $page;

  return $pages;

}
