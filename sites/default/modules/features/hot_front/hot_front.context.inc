<?php
/**
 * @file
 * hot_front.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hot_front_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = '';
  $context->tag = 'section';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'project:page' => 'project:page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-updates-block' => array(
          'module' => 'views',
          'delta' => 'updates-block',
          'region' => 'triptych_first',
          'weight' => '-10',
        ),
        'views-project-block' => array(
          'module' => 'views',
          'delta' => 'project-block',
          'region' => 'triptych_first',
          'weight' => '-9',
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
