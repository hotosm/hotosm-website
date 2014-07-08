<?php
/**
 * @file
 * hot_updates.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hot_updates_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer node notify'.
  $permissions['administer node notify'] = array(
    'name' => 'administer node notify',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node_notify',
  );

  // Exported permission: 'administer node subscriptions'.
  $permissions['administer node subscriptions'] = array(
    'name' => 'administer node subscriptions',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node_notify',
  );

  // Exported permission: 'create update content'.
  $permissions['create update content'] = array(
    'name' => 'create update content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any update content'.
  $permissions['delete any update content'] = array(
    'name' => 'delete any update content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own update content'.
  $permissions['delete own update content'] = array(
    'name' => 'delete own update content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any update content'.
  $permissions['edit any update content'] = array(
    'name' => 'edit any update content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own update content'.
  $permissions['edit own update content'] = array(
    'name' => 'edit own update content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'subscribe to node'.
  $permissions['subscribe to node'] = array(
    'name' => 'subscribe to node',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node_notify',
  );

  return $permissions;
}
