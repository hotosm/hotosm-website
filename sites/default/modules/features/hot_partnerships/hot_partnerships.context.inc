<?php
/**
 * @file
 * hot_partnerships.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hot_partnerships_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'partner_node';
  $context->description = '';
  $context->tag = 'partners';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'partner' => 'partner',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-project_information-block_1' => array(
          'module' => 'views',
          'delta' => 'project_information-block_1',
          'region' => 'follow',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('partners');
  $export['partner_node'] = $context;

  return $export;
}
