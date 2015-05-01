<?php
/**
 * @file
 * hot_jobs.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hot_jobs_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'job_offers';
  $page->task = 'page';
  $page->admin_title = 'Job offers';
  $page->admin_description = '';
  $page->path = 'jobs';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_job_offers__panel_context_fe8f9849-4780-4dee-96c6-eb5645c9c5bd';
  $handler->task = 'page';
  $handler->subtask = 'job_offers';
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
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Jobs';
  $display->uuid = '1ff6bbc7-3d78-4acd-b822-e3c5fdccce24';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-21b7e415-44a1-40d3-b3f4-0d1a57db959b';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Introduction text',
      'title' => '',
      'body' => '<p>Do you want to work with the Humanitarian OpenStreetMap Team? We are seeking good people for the following jobs:</p>',
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
    $pane->uuid = '21b7e415-44a1-40d3-b3f4-0d1a57db959b';
    $display->content['new-21b7e415-44a1-40d3-b3f4-0d1a57db959b'] = $pane;
    $display->panels['middle'][0] = 'new-21b7e415-44a1-40d3-b3f4-0d1a57db959b';
    $pane = new stdClass();
    $pane->pid = 'new-e298aed4-5c3f-48dc-aef0-d93f7bda68da';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'jobs-panel_pane_jobs_open';
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
    $pane->uuid = 'e298aed4-5c3f-48dc-aef0-d93f7bda68da';
    $display->content['new-e298aed4-5c3f-48dc-aef0-d93f7bda68da'] = $pane;
    $display->panels['middle'][1] = 'new-e298aed4-5c3f-48dc-aef0-d93f7bda68da';
    $pane = new stdClass();
    $pane->pid = 'new-a3206fb7-6e91-4e8b-969b-c597de5913f0';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'jobs-panel_pane_jobs_closed';
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
    $pane->uuid = 'a3206fb7-6e91-4e8b-969b-c597de5913f0';
    $display->content['new-a3206fb7-6e91-4e8b-969b-c597de5913f0'] = $pane;
    $display->panels['middle'][2] = 'new-a3206fb7-6e91-4e8b-969b-c597de5913f0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e298aed4-5c3f-48dc-aef0-d93f7bda68da';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['job_offers'] = $page;

  return $pages;

}
