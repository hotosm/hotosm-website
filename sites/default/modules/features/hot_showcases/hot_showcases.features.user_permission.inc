<?php
/**
 * @file
 * hot_showcases.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hot_showcases_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create showcase content'.
  $permissions['create showcase content'] = array(
    'name' => 'create showcase content',
    'roles' => array(
      'content editor' => 'content editor',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any showcase content'.
  $permissions['delete any showcase content'] = array(
    'name' => 'delete any showcase content',
    'roles' => array(
      'content editor' => 'content editor',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own showcase content'.
  $permissions['delete own showcase content'] = array(
    'name' => 'delete own showcase content',
    'roles' => array(
      'content editor' => 'content editor',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any showcase content'.
  $permissions['edit any showcase content'] = array(
    'name' => 'edit any showcase content',
    'roles' => array(
      'content editor' => 'content editor',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own showcase content'.
  $permissions['edit own showcase content'] = array(
    'name' => 'edit own showcase content',
    'roles' => array(
      'content editor' => 'content editor',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
