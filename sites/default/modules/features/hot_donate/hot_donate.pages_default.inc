<?php
/**
 * @file
 * hot_donate.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hot_donate_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'donate';
  $page->task = 'page';
  $page->admin_title = 'Donate';
  $page->admin_description = '';
  $page->path = 'donate-new';
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
  $handler->name = 'page_donate__panel';
  $handler->task = 'page';
  $handler->subtask = 'donate';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'panel-page-donate',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
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
  $display->title = 'Support HOT\'s work - Donate today!';
  $display->uuid = 'd034ac49-51d1-4986-af3c-e4ced5061cd4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-065966e1-5f28-44a5-998f-3bd8c4fc0bdc';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Intro text',
      'title' => '',
      'body' => '<p>When disaster strikes, HOT mobilizes our global network of thousands of volunteers who work together to map the impacted area in OpenStreetMap. We don’t only do it after disaster: every day, HOT volunteers work tirelessly to&nbsp;put the most vulnerable people and places on the map before disaster strikes. These maps contribute to saving lives in emergency.</p><p>Thank you for supporting this critical work. When you give to HOT, your donation is used where it\'s needed most to carry out our humanitarian mission.</p>',
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
    $pane->uuid = '065966e1-5f28-44a5-998f-3bd8c4fc0bdc';
    $display->content['new-065966e1-5f28-44a5-998f-3bd8c4fc0bdc'] = $pane;
    $display->panels['middle'][0] = 'new-065966e1-5f28-44a5-998f-3bd8c4fc0bdc';
    $pane = new stdClass();
    $pane->pid = 'new-cf3069bf-2a89-4794-b9b7-656a77c36b2e';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Video',
      'title' => '',
      'body' => '<p><iframe src="https://www.youtube.com/embed/8wdzGKmZu-k" frameborder="0" width="605" height="338"></iframe></p>',
      'format' => '2',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cf3069bf-2a89-4794-b9b7-656a77c36b2e';
    $display->content['new-cf3069bf-2a89-4794-b9b7-656a77c36b2e'] = $pane;
    $display->panels['middle'][1] = 'new-cf3069bf-2a89-4794-b9b7-656a77c36b2e';
    $pane = new stdClass();
    $pane->pid = 'new-40fbdab6-0241-4fde-b68d-5beb54cbee7f';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'hot_donate-hot_donate';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Donate now',
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
    $pane->uuid = '40fbdab6-0241-4fde-b68d-5beb54cbee7f';
    $display->content['new-40fbdab6-0241-4fde-b68d-5beb54cbee7f'] = $pane;
    $display->panels['middle'][2] = 'new-40fbdab6-0241-4fde-b68d-5beb54cbee7f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-065966e1-5f28-44a5-998f-3bd8c4fc0bdc';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['donate'] = $page;

  return $pages;

}
