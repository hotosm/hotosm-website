<?php
/**
 * @file
 * hot_people.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hot_people_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(),
    'module' => 'contact',
  );

  // Exported permission: 'access user contact forms'.
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(),
    'module' => 'contact',
  );

  // Exported permission: 'administer contact forms'.
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(),
    'module' => 'contact',
  );

  // Exported permission: 'flag board_member'.
  $permissions['flag board_member'] = array(
    'name' => 'flag board_member',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag executive_director'.
  $permissions['flag executive_director'] = array(
    'name' => 'flag executive_director',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag voting_member'.
  $permissions['flag voting_member'] = array(
    'name' => 'flag voting_member',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag board_member'.
  $permissions['unflag board_member'] = array(
    'name' => 'unflag board_member',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag executive_director'.
  $permissions['unflag executive_director'] = array(
    'name' => 'unflag executive_director',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag voting_member'.
  $permissions['unflag voting_member'] = array(
    'name' => 'unflag voting_member',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
