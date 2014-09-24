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
  $context->name = 'update_node';
  $context->description = '';
  $context->tag = 'updates';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'update' => 'update',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'lang_dropdown-language_content' => array(
          'module' => 'lang_dropdown',
          'delta' => 'language_content',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
        'views-update-block' => array(
          'module' => 'views',
          'delta' => 'update-block',
          'region' => 'sidebar',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('updates');
  $export['update_node'] = $context;

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
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-updates-navigation' => array(
          'module' => 'menu',
          'delta' => 'menu-updates-navigation',
          'region' => 'help',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('updates');
  $export['updates_overview'] = $context;

  return $export;
}
