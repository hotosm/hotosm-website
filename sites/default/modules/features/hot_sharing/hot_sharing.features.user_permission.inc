<?php
/**
 * @file
 * hot_sharing.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hot_sharing_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer addtoany'.
  $permissions['administer addtoany'] = array(
    'name' => 'administer addtoany',
    'roles' => array(),
    'module' => 'addtoany',
  );

  return $permissions;
}
