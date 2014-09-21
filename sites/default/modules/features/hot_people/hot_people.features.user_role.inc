<?php
/**
 * @file
 * hot_people.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hot_people_user_default_roles() {
  $roles = array();

  // Exported role: content editor.
  $roles['content editor'] = array(
    'name' => 'content editor',
    'weight' => 1,
  );

  return $roles;
}
