<?php
/**
 * @file
 * hot_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hot_core_user_default_roles() {
  $roles = array();

  // Exported role: site admin.
  $roles['site admin'] = array(
    'name' => 'site admin',
    'weight' => 0,
  );

  return $roles;
}
