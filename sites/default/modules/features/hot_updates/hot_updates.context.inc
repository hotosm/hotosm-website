<?php
/**
 * @file
 * hot_updates.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hot_updates_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'updates_overview';
  $context->description = '';
  $context->tag = 'updates';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'updates:updates_all_page' => 'updates:updates_all_page',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('updates');
  $export['updates_overview'] = $context;

  return $export;
}
