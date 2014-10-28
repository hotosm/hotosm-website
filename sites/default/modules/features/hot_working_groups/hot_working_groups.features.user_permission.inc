<?php
/**
 * @file
 * hot_working_groups.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hot_working_groups_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create working_group content'.
  $permissions['create working_group content'] = array(
    'name' => 'create working_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any working_group content'.
  $permissions['delete any working_group content'] = array(
    'name' => 'delete any working_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own working_group content'.
  $permissions['delete own working_group content'] = array(
    'name' => 'delete own working_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any working_group content'.
  $permissions['edit any working_group content'] = array(
    'name' => 'edit any working_group content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own working_group content'.
  $permissions['edit own working_group content'] = array(
    'name' => 'edit own working_group content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
