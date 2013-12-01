<?php

/**
 * @file
 * Contains a pre-process hook for 'node'.
 */

/**
 * Implements hook_preprocess_node().
 */
function hot_preprocess_node(&$variables) {
  // Hide book links
  if ($variables['type'] == 'book') {
    hide($variables['content']['links']['book']);
  }
}
