<?php
/**
 * @file
 * hot_project.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hot_project_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'project_node';
  $context->description = '';
  $context->tag = 'projects';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-updates-updates_project_block' => array(
          'module' => 'views',
          'delta' => 'updates-updates_project_block',
          'region' => 'content',
          'weight' => '10',
        ),
        'views-project_ol_map-block_1' => array(
          'module' => 'views',
          'delta' => 'project_ol_map-block_1',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
        'views-project_ol_map-block_2' => array(
          'module' => 'views',
          'delta' => 'project_ol_map-block_2',
          'region' => 'sidebar',
          'weight' => '-9',
        ),
        'views-videos-videos_block_projects' => array(
          'module' => 'views',
          'delta' => 'videos-videos_block_projects',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('projects');
  $export['project_node'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'projects_overview';
  $context->description = '';
  $context->tag = 'projects';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'project:projects_overview_page' => 'project:projects_overview_page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-projects-navigation' => array(
          'module' => 'menu',
          'delta' => 'menu-projects-navigation',
          'region' => 'help',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('projects');
  $export['projects_overview'] = $context;

  return $export;
}
