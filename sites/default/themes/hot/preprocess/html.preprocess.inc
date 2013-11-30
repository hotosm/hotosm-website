<?php

/**
 * @file
 * Contains a pre-process hook for 'html'.
 */

/**
 * Implements hook_preprocess_html().
 */
function hot_preprocess_html(&$variables, $hook) {
  // Return early, so the maintenance page does not call any of the code below.
  if ($hook != 'html') {
    return;
  }

  // Add class to body tag when sidebar is present
  if (isset($variables['page']['sidebar'])) {
    $variables['attributes_array']['class'][] = 'sidebar-present';
  }
}
