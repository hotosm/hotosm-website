<?php
/**
 * @file
 * mass_contact plugin type grouping_method.
 *
 * Select users by their role.
 */

$plugin = array(
  // Retrieve the list of users by category.
  // For user roles, we receive unserialized settings with the selected roles.
  'mass_contact_recipients' => 'mass_contact_role_recipients',

  // Prepare the Category selection information for the Recipients column of the
  // Category list admin page.
  'mass_contact_categories' => 'mass_contact_role_categories',

  // The next three callbacks are used to maintain the form for adding/editing
  // categories.
  'mass_contact_admin_edit' => 'mass_contact_role_admin_edit',
  'mass_contact_admin_edit_validate' => 'mass_contact_role_admin_edit_validate',
  'mass_contact_admin_edit_submit' => 'mass_contact_role_admin_edit_submit',

  // This callback is used to maintain the form for opting in or out of
  // categories.
  'mass_contact_user_edit' => 'mass_contact_role_user_edit',
);


/**
 * Retrieves a list of users by roles.
 *
 * Gets the user IDs for all users in all roles included in the category.
 *
 * @param array $recipients
 *   The list of items for this category. For this plugin implementation, it is
 *   an array of role IDs.
 *
 * @return array
 *   The user IDs that are part of specified roles.
 */
function mass_contact_role_recipients($recipients) {
  // Check to see if a role has been selected.
  if (!isset($recipients['mass_contact_role']) || empty($recipients['mass_contact_role'])) {
    return;
  }

  $result = array();
  // Select the users.
  if (!empty($recipients['mass_contact_role'][0]) && $recipients['mass_contact_role'][0] == 2) {
    // If the selected role is the authenticated users role, get everyone.
    $query = "SELECT u.uid FROM {users} u LEFT JOIN {users_roles} ur ON u.uid = ur.uid WHERE status = 1";
    $result = db_query($query)->fetchAllAssoc('uid', PDO::FETCH_ASSOC);
  }
  elseif (!empty($recipients['mass_contact_role'])) {
    // Get the list of users who belong to the current role.
    $query = "SELECT u.uid FROM {users} u LEFT JOIN {users_roles} ur ON u.uid = ur.uid WHERE ur.rid IN (:ur_rids) AND status = 1";
    $result = db_query($query, array(':ur_rids' => $recipients['mass_contact_role']))->fetchAllAssoc('uid', PDO::FETCH_ASSOC);
  }
  if (empty($result)) {
    return;
  }

  // Collect the uids.
  $uids = array();
  foreach ($result as $record) {
    // For each record in the result set, add the user's ID to the array.
    $uids[] = (integer) $record['uid'];
  }

  return $uids;
}


/**
 * Prepares a list of categories for the Category List page.
 *
 * The role names are displayed in the Recipients column on the Category List
 * page (admin/config/system/mass_contact).
 *
 * @param array $recipients
 *   The list of items for this category. For this plugin implementation, it is
 *   an array of role IDs.
 *
 * @return string
 *   The type of category (role) and the items included in it.
 */
function mass_contact_role_categories($recipients) {
  // Check to see if a role has been selected.
  if (!isset($recipients['mass_contact_role']) || empty($recipients['mass_contact_role'])) {
    return;
  }

  // Get all role names from the database that are included in the list of role
  // IDs.
  $result = db_query('SELECT name FROM {role} WHERE rid IN (:rids)', array(':rids' => $recipients['mass_contact_role']));
  if (empty($result)) {
    return;
  }

  $role_names = array();
  foreach ($result as $record) {
    // For each record add the role name to an array.
    $role_names[] = $record->name;
  }

  // Return the list of roles included in this category.
  return t('Roles: %roles', array('%roles' => implode(', ', $role_names)));
}


/**
 * Creates a form element for Category add/edit page.
 *
 * @param array $recipients
 *   The list of items for this category. For this plugin implementation, it is
 *   an array of role IDs.
 *
 * @return array
 *   The form snippet.
 */
function mass_contact_role_admin_edit($recipients) {
  $selected_roles = array();
  if (isset($recipients['mass_contact_role']) && !empty($recipients['mass_contact_role'])) {
    $selected_roles = $recipients['mass_contact_role'];
  }

  // Get a list of all roles, except for the anonymous user role.
  $allroles = db_select('role', 'r')
    ->fields('r', array('rid', 'name'))
    ->condition('rid', 1, '>')
    ->orderBy('name', 'ASC')
    ->execute();

  // Cycle through each role, adding it to the array to include in the selction
  // list.
  foreach ($allroles as $role) {
    $rolesarray[$role->rid] = $role->name;
  }

  // Create a set of checkboxes, including each role.
  $form_element = array(
    '#type' => 'checkboxes',
    '#title' => t('User roles to include'),
    '#options' => $rolesarray,
    '#default_value' => $selected_roles,
    '#description' => t('These roles will be added to the mailing list. Note: if you check "authenticated user", other roles will not be added, as they will receive the email anyway.'),
  );

  return $form_element;
}

/**
 * Category add/edit form validation callback.
 *
 * Sets the form error and returns, whether selection is empty or not.
 *
 * @param array $form
 *   A nested array of form elements that comprise the form.
 * @param array $form_state
 *   A keyed array containing the current state of the form.
 *
 * @return bool
 *   Indicates whether a validation error has occurred or not.
 */
function mass_contact_role_admin_edit_validate($form, &$form_state) {
  $selected_roles = array_filter($form_state['values']['recipients']['mass_contact_role']);
  return empty($selected_roles);
}

/**
 * Category add/edit form submit callback.
 *
 * Returns the piece of data that will be saved to mass_contact table in
 * recepients field.
 *
 * @param array $form
 *   A nested array of form elements that comprise the form.
 * @param array $form_state
 *   A keyed array containing the current state of the form.
 *
 * @return array
 *   An array of role IDs.
 */
function mass_contact_role_admin_edit_submit($form, &$form_state) {
  $roles = $form_state['values']['recipients']['mass_contact_role'];

  // If all authenticated users are already added, simply return the
  // authenticated users' rid.
  if ($roles[2] == 2) {
    return array(2);
  }

  // Remove roles that were not selected.
  $roles = array_filter($roles);

  return $roles;
}


/**
 * Creates a list of categories the user is part of.
 *
 * @param object $user
 *   The user object of the user for which the available categories are sought.
 *
 * @return array
 *   The form snippet.
 */
function mass_contact_role_user_edit($user) {
  // Get all the roles for which this user is a member.
  $user_roles = db_select('users_roles', 'ur')
    ->fields('ur', array('rid'))
    ->condition('uid', $user->uid)
    ->execute();

  // Put the role IDs into an array for later use.
  $users_roles = array();
  // Start with the 'authenticated user' role, as it's not in the database.
  $users_roles[] = 2;
  foreach ($user_roles as $user_role) {
    $users_roles[] = $user_role->rid;
  }

  // Get all the Mass Contact categories.
  $categories = db_select('mass_contact', 'mc')
    ->fields('mc', array('cid', 'category', 'recipients'))
    ->execute();

  // Collect all the categories which contain roles the user is in.
  $included_categories = array();
  // Iterate through each category.
  foreach ($categories as $category) {
    // Pull out the roles that are a part of this category.
    $recipients = unserialize($category->recipients);
    foreach ($recipients['mass_contact_role'] as $role_id) {
      // If the category's role is one the user is in, include the category.
      if (in_array($role_id, $users_roles)) {
        $included_categories[$category->cid] = $category->category;
      }
    }
  }

  return $included_categories;
}
