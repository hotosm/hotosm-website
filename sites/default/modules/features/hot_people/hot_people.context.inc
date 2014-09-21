<?php
/**
 * @file
 * hot_people.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hot_people_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile';
  $context->description = '';
  $context->tag = 'users';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-user_profile-block_2' => array(
          'module' => 'views',
          'delta' => 'user_profile-block_2',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-user_profile-block_1' => array(
          'module' => 'views',
          'delta' => 'user_profile-block_1',
          'region' => 'sidebar',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('users');
  $export['user_profile'] = $context;

  return $export;
}
