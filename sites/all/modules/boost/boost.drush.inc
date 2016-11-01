<?php

/**
 * @file
 * Drush commands for Boost.
 */

/**
 * Implements hook_drush_cache_clear.
 */
function boost_drush_cache_clear(&$types) {
  $types['boost'] = 'boost_drush_cache_clear_all';
}

/**
 * Clears all Boost cached data.
 */
function boost_drush_cache_clear_all() {
  $ignore = variable_get('boost_ignore_flush', 0);
  $GLOBALS['conf']['boost_ignore_flush'] = 0;

  boost_flush_caches();

  $GLOBALS['conf']['boost_ignore_flush'] = $ignore;
}
