<?php
/**
 * @file
 * hot_working_groups.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hot_working_groups_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'working_group_node';
  $context->description = '';
  $context->tag = 'working groups';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'working_group' => 'working_group',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-user_lists-block_wg_members' => array(
          'module' => 'views',
          'delta' => 'user_lists-block_wg_members',
          'region' => 'content',
          'weight' => '10',
        ),
        'views-working_group-block' => array(
          'module' => 'views',
          'delta' => 'working_group-block',
          'region' => 'sidebar',
          'weight' => '-25',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('working groups');
  $export['working_group_node'] = $context;

  return $export;
}
