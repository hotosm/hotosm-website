<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function hot_project_context_default_contexts() {
  $export = array();

  $context = new stdClass;
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
        'views-updates-block_2' => array(
          'module' => 'views',
          'delta' => 'updates-block_2',
          'region' => 'content',
          'weight' => 0,
        ),
        'views-project_ol_map-block_2' => array(
          'module' => 'views',
          'delta' => 'project_ol_map-block_2',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-project_ol_map-block_1' => array(
          'module' => 'views',
          'delta' => 'project_ol_map-block_1',
          'region' => 'right',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('projects');
  $export['project_node'] = $context;

  return $export;
}
