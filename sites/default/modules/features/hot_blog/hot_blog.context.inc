<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function hot_blog_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog';
  $context->description = '';
  $context->tag = 'section';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'story' => 'story',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'views' => array(
      'values' => array(
        'archive:page' => 'archive:page',
        'blog:page_1' => 'blog:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-archive-block' => array(
          'module' => 'views',
          'delta' => 'archive-block',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-blog-block_1' => array(
          'module' => 'views',
          'delta' => 'blog-block_1',
          'region' => 'right',
          'weight' => 1,
        ),
        'views-blog-block_2' => array(
          'module' => 'views',
          'delta' => 'blog-block_2',
          'region' => 'right',
          'weight' => 2,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('section');

  $export['blog'] = $context;
  return $export;
}
