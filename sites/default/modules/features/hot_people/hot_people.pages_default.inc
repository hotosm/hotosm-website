<?php
/**
 * @file
 * hot_people.pages_default.inc
 */

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
  $page->path = 'leadership';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 4,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
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

  return $pages;

}
