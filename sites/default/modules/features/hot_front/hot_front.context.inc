<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function hot_front_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = '';
  $context->tag = 'section';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'project:page_1' => 'project:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-updates-block_1' => array(
          'module' => 'views',
          'delta' => 'updates-block_1',
          'region' => 'content',
          'weight' => 0,
        ),
        'views-project-block_1' => array(
          'module' => 'views',
          'delta' => 'project-block_1',
          'region' => 'content',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('section');
  $export['front'] = $context;

  return $export;
}
