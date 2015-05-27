<?php
/**
 * @file
 * hot_people.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function hot_people_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view__profile';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Profile',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'profile',
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7dbf6068-f071-4e82-b2e6-b324eadf9bdf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-be8e5ca3-f0ab-4f1c-9fdc-660292a7b73b';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_bio';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
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
    $pane->uuid = 'be8e5ca3-f0ab-4f1c-9fdc-660292a7b73b';
    $display->content['new-be8e5ca3-f0ab-4f1c-9fdc-660292a7b73b'] = $pane;
    $display->panels['left'][0] = 'new-be8e5ca3-f0ab-4f1c-9fdc-660292a7b73b';
    $pane = new stdClass();
    $pane->pid = 'new-e5b3f5f0-c9ba-49e6-b047-cdd577d972e2';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_working_group';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'node_reference_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => 'Active in working group(s)',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e5b3f5f0-c9ba-49e6-b047-cdd577d972e2';
    $display->content['new-e5b3f5f0-c9ba-49e6-b047-cdd577d972e2'] = $pane;
    $display->panels['left'][1] = 'new-e5b3f5f0-c9ba-49e6-b047-cdd577d972e2';
    $pane = new stdClass();
    $pane->pid = 'new-2d0d906f-fed0-4048-b942-4f3c668674f0';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_working_group_role';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'title_linked',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'title_style' => '_none',
        'title_link' => '',
        'title_class' => '',
      ),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
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
    $pane->uuid = '2d0d906f-fed0-4048-b942-4f3c668674f0';
    $display->content['new-2d0d906f-fed0-4048-b942-4f3c668674f0'] = $pane;
    $display->panels['left'][2] = 'new-2d0d906f-fed0-4048-b942-4f3c668674f0';
    $pane = new stdClass();
    $pane->pid = 'new-06ea9ba0-e499-42d9-86c3-89b9104b1a64';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_hot_leadership';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'taxonomy_term_reference_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => 'Board function',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '06ea9ba0-e499-42d9-86c3-89b9104b1a64';
    $display->content['new-06ea9ba0-e499-42d9-86c3-89b9104b1a64'] = $pane;
    $display->panels['left'][3] = 'new-06ea9ba0-e499-42d9-86c3-89b9104b1a64';
    $pane = new stdClass();
    $pane->pid = 'new-4f2aa2d6-3c7c-4feb-8753-7f493469997c';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'node_reference_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => 'Projects this user has participated',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '4f2aa2d6-3c7c-4feb-8753-7f493469997c';
    $display->content['new-4f2aa2d6-3c7c-4feb-8753-7f493469997c'] = $pane;
    $display->panels['left'][4] = 'new-4f2aa2d6-3c7c-4feb-8753-7f493469997c';
    $pane = new stdClass();
    $pane->pid = 'new-26511b1d-32d1-4555-814a-763d621731d9';
    $pane->panel = 'right';
    $pane->type = 'user_picture';
    $pane->subtype = 'user_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
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
    $pane->uuid = '26511b1d-32d1-4555-814a-763d621731d9';
    $display->content['new-26511b1d-32d1-4555-814a-763d621731d9'] = $pane;
    $display->panels['right'][0] = 'new-26511b1d-32d1-4555-814a-763d621731d9';
    $pane = new stdClass();
    $pane->pid = 'new-8857eb75-b0ee-45d7-8dd5-696cb965f65a';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_country';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'country_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
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
    $pane->uuid = '8857eb75-b0ee-45d7-8dd5-696cb965f65a';
    $display->content['new-8857eb75-b0ee-45d7-8dd5-696cb965f65a'] = $pane;
    $display->panels['right'][1] = 'new-8857eb75-b0ee-45d7-8dd5-696cb965f65a';
    $pane = new stdClass();
    $pane->pid = 'new-18113c42-6074-49b9-88f7-d1744b100b36';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_osm_user_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'title_linked',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'title_style' => '_none',
        'title_link' => '',
        'title_class' => '',
      ),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => 'OSM username',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '18113c42-6074-49b9-88f7-d1744b100b36';
    $display->content['new-18113c42-6074-49b9-88f7-d1744b100b36'] = $pane;
    $display->panels['right'][2] = 'new-18113c42-6074-49b9-88f7-d1744b100b36';
    $pane = new stdClass();
    $pane->pid = 'new-80b2539f-74b9-4b76-ac8b-80f56e4f0d1b';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h2>Social media</h2>',
      'format' => '1',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '80b2539f-74b9-4b76-ac8b-80f56e4f0d1b';
    $display->content['new-80b2539f-74b9-4b76-ac8b-80f56e4f0d1b'] = $pane;
    $display->panels['right'][3] = 'new-80b2539f-74b9-4b76-ac8b-80f56e4f0d1b';
    $pane = new stdClass();
    $pane->pid = 'new-2d03a069-aa9a-4dcf-bfe3-3db70b54c7e6';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_twitter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'title_linked',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'title_style' => '_none',
        'title_link' => '',
        'title_class' => '',
      ),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => 'Twitter',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '2d03a069-aa9a-4dcf-bfe3-3db70b54c7e6';
    $display->content['new-2d03a069-aa9a-4dcf-bfe3-3db70b54c7e6'] = $pane;
    $display->panels['right'][4] = 'new-2d03a069-aa9a-4dcf-bfe3-3db70b54c7e6';
    $pane = new stdClass();
    $pane->pid = 'new-4b4b8753-8b98-407e-8d6f-b2e41998e58b';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_facebook';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'span',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '4b4b8753-8b98-407e-8d6f-b2e41998e58b';
    $display->content['new-4b4b8753-8b98-407e-8d6f-b2e41998e58b'] = $pane;
    $display->panels['right'][5] = 'new-4b4b8753-8b98-407e-8d6f-b2e41998e58b';
    $pane = new stdClass();
    $pane->pid = 'new-4f8902ec-b75e-41a8-b62a-aa56fe3c164a';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_linkedin';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:user_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '4f8902ec-b75e-41a8-b62a-aa56fe3c164a';
    $display->content['new-4f8902ec-b75e-41a8-b62a-aa56fe3c164a'] = $pane;
    $display->panels['right'][6] = 'new-4f8902ec-b75e-41a8-b62a-aa56fe3c164a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-be8e5ca3-f0ab-4f1c-9fdc-660292a7b73b';
  $handler->conf['display'] = $display;
  $export['user_view__profile'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function hot_people_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'leadership';
  $page->task = 'page';
  $page->admin_title = 'leadership';
  $page->admin_description = '';
  $page->path = 'board';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Board',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_leadership_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'leadership';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'leadership',
    'css_id' => 'leadership',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Leadership';
  $display->uuid = '1cd88d5d-93a4-4202-9fb5-8b831ced9da1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3235225a-2fa8-4ad9-b9a4-97a6ab086182';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'leadership-panel_pane_board';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3235225a-2fa8-4ad9-b9a4-97a6ab086182';
    $display->content['new-3235225a-2fa8-4ad9-b9a4-97a6ab086182'] = $pane;
    $display->panels['middle'][0] = 'new-3235225a-2fa8-4ad9-b9a4-97a6ab086182';
    $pane = new stdClass();
    $pane->pid = 'new-46e42b47-4c75-44c8-b205-057bff7d4f00';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'leadership-panel_pane_director';
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
    $pane->uuid = '46e42b47-4c75-44c8-b205-057bff7d4f00';
    $display->content['new-46e42b47-4c75-44c8-b205-057bff7d4f00'] = $pane;
    $display->panels['middle'][1] = 'new-46e42b47-4c75-44c8-b205-057bff7d4f00';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3235225a-2fa8-4ad9-b9a4-97a6ab086182';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['leadership'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'voting_members';
  $page->task = 'page';
  $page->admin_title = 'Voting members';
  $page->admin_description = '';
  $page->path = 'voting-members';
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
  $handler->name = 'page_voting_members__panel_context_9c1e955c-0605-4cdb-9085-df37f2e0b798';
  $handler->task = 'page';
  $handler->subtask = 'voting_members';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Voting members';
  $display->uuid = '29cf1d2c-b917-4f0d-904a-cae1d553561d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-108a5d46-9acd-4b4b-a861-9b5213524729';
    $pane->panel = 'middle';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '187',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'teaser',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'span',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '108a5d46-9acd-4b4b-a861-9b5213524729';
    $display->content['new-108a5d46-9acd-4b4b-a861-9b5213524729'] = $pane;
    $display->panels['middle'][0] = 'new-108a5d46-9acd-4b4b-a861-9b5213524729';
    $pane = new stdClass();
    $pane->pid = 'new-ceb0423e-60b9-4131-98fe-7686875025ef';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_lists-panel_pane_members_voting';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
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
    $pane->uuid = 'ceb0423e-60b9-4131-98fe-7686875025ef';
    $display->content['new-ceb0423e-60b9-4131-98fe-7686875025ef'] = $pane;
    $display->panels['middle'][1] = 'new-ceb0423e-60b9-4131-98fe-7686875025ef';
    $pane = new stdClass();
    $pane->pid = 'new-5fbded7c-e788-4670-bbd1-d8be6cbcb347';
    $pane->panel = 'middle';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '386',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'teaser',
      'link_node_title' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'span',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5fbded7c-e788-4670-bbd1-d8be6cbcb347';
    $display->content['new-5fbded7c-e788-4670-bbd1-d8be6cbcb347'] = $pane;
    $display->panels['middle'][2] = 'new-5fbded7c-e788-4670-bbd1-d8be6cbcb347';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['voting_members'] = $page;

  return $pages;

}
