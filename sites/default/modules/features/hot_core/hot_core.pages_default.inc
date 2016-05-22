<?php
/**
 * @file
 * hot_core.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hot_core_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'activations';
  $page->task = 'page';
  $page->admin_title = 'Disaster Mapping';
  $page->admin_description = '';
  $page->path = 'get-involved/disaster-mapping';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => 'Mapping',
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
  $handler->name = 'page_activations__panel_context_c552f72b-acc2-44c3-a29e-495afe3bb1f9';
  $handler->task = 'page';
  $handler->subtask = 'activations';
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
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Help Us Map!';
  $display->uuid = '7120ee1d-b08d-4c8d-9e18-d2d124befda6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-831fa318-7484-43a2-b039-a103a6f09da6';
    $pane->panel = 'center';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '370',
      'links' => 1,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
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
    $pane->uuid = '831fa318-7484-43a2-b039-a103a6f09da6';
    $display->content['new-831fa318-7484-43a2-b039-a103a6f09da6'] = $pane;
    $display->panels['center'][0] = 'new-831fa318-7484-43a2-b039-a103a6f09da6';
    $pane = new stdClass();
    $pane->pid = 'new-36e1af63-6f73-42c2-abaa-f3a679784d95';
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
      'override_title_text' => 'These ongoing projects need your help!',
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
    $pane->uuid = '36e1af63-6f73-42c2-abaa-f3a679784d95';
    $display->content['new-36e1af63-6f73-42c2-abaa-f3a679784d95'] = $pane;
    $display->panels['center'][1] = 'new-36e1af63-6f73-42c2-abaa-f3a679784d95';
    $pane = new stdClass();
    $pane->pid = 'new-d29ee4b7-b31d-4621-b870-97957f3bf77a';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Tasking Manager Link',
      'title' => '',
      'body' => '<a class="button" href="http://tasks.hotosm.org">View more projects in the Tasking Manager</a>',
      'format' => '2',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd29ee4b7-b31d-4621-b870-97957f3bf77a';
    $display->content['new-d29ee4b7-b31d-4621-b870-97957f3bf77a'] = $pane;
    $display->panels['center'][2] = 'new-d29ee4b7-b31d-4621-b870-97957f3bf77a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-831fa318-7484-43a2-b039-a103a6f09da6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['activations'] = $page;

  return $pages;

}
