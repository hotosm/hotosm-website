<?php
/**
 * @file
 * hot_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function hot_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = 'Front page context';
  $context->tag = 'general';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-project-projects_featured_block' => array(
          'module' => 'views',
          'delta' => 'project-projects_featured_block',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'highlighted',
          'weight' => '-9',
        ),
        'block-6' => array(
          'module' => 'block',
          'delta' => '6',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-updates-updates_all_block' => array(
          'module' => 'views',
          'delta' => 'updates-updates_all_block',
          'region' => 'content',
          'weight' => '-9',
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front page context');
  t('general');
  $export['front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'get_involved';
  $context->description = '';
  $context->tag = 'information';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'get-involved' => 'get-involved',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'content',
          'weight' => '2',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('information');
  $export['get_involved'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'Sitewide context';
  $context->tag = 'general';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'header',
          'weight' => '-27',
        ),
        'lang_dropdown-language' => array(
          'module' => 'lang_dropdown',
          'delta' => 'language',
          'region' => 'header',
          'weight' => '-26',
        ),
        'menu_block-hot_core-1' => array(
          'module' => 'menu_block',
          'delta' => 'hot_core-1',
          'region' => 'navigation',
          'weight' => '-10',
        ),
        'mailchimp_signup-hot_newsletter' => array(
          'module' => 'mailchimp_signup',
          'delta' => 'hot_newsletter',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'block-7' => array(
          'module' => 'block',
          'delta' => '7',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'block-8' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'footer',
          'weight' => '-7',
        ),
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'footer',
          'weight' => '-6',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'footer',
          'weight' => '-5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide context');
  t('general');
  $export['sitewide'] = $context;

  return $export;
}
