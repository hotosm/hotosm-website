<?php
/**
 * @file
 * hot_core.features.contact_categories.inc
 */

/**
 * Implements hook_contact_categories_defaults().
 */
function hot_core_contact_categories_defaults() {
  return array(
    'Website feedback' => array(
      'category' => 'Website feedback',
      'recipients' => 'hot.drupal@mikemcccaffrey.net',
      'reply' => '',
      'weight' => 0,
      'selected' => 1,
    ),
  );
}
