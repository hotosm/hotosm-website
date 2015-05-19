<?php
/**
 * @file
 * mass_contact plugin type grouping_method.
 *
 * Select users by taxonomy terms.
 */

$plugin = array(
  // Retrieve the list of users by category.
  'mass_contact_recipients' => 'mass_contact_taxonomy_recipients',

  // Prepare the Category selection information for the Recipients column of the
  // Category list admin page.
  'mass_contact_categories' => 'mass_contact_taxonomy_categories',

  // The next three callbacks are used to maintain the form for adding/editing
  // categories.
  'mass_contact_admin_edit' => 'mass_contact_taxonomy_admin_edit',
  'mass_contact_admin_edit_validate' => 'mass_contact_taxonomy_admin_edit_validate',
  'mass_contact_admin_edit_submit' => 'mass_contact_taxonomy_admin_edit_submit',

  // This callback is used to maintain the form for opting in or out of
  // categories.
  'mass_contact_user_edit' => 'mass_contact_taxonomy_user_edit',
);


/**
 * Retrieves a list of users by taxonomy terms.
 *
 * Gets the user IDs for all users that have the specified taxonomy terms
 * attached to user object.
 *
 * @param array $recipients
 *   The list of items for this category. For this plugin implementation, it is
 *   an array of taxonomy term IDs.
 *
 * @return array
 *   The user IDs that are part of specified taxonomy terms.
 */
function mass_contact_taxonomy_recipients($recipients) {
  // Check to see if a taxonomy term has been selected.
  if (!isset($recipients['mass_contact_taxonomy']) || empty($recipients['mass_contact_taxonomy'])) {
    return;
  }

  // Check all fields of user entity and if field is taxonomy term reference,
  // add condition.
  $user_fields = field_info_instances('user');
  if (empty($user_fields)) {
    return;
  }

  $uids = array();
  // Iterate through all the fields attached to the user entity.
  foreach ($user_fields['user'] as $user_field_instance) {
    // Get the field's information.
    $field = field_info_field($user_field_instance['field_name']);

    // EntityFieldQuery() cannot handle OR logic, so for each possible taxonomy
    // term attached to a user, we make a separate query.
    if (isset($field['module']) && $field['module'] == 'taxonomy') {
      // Create a query to select users by taxonomy term.
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'user');
      $query->fieldCondition($field['field_name'], 'tid', $recipients['mass_contact_taxonomy'], 'IN');
      $result = $query->execute();
      // Collect uids.
      if (isset($result['user'])) {
        // Save out the keys from the result set.
        $uids = array_keys($result['user']);
      }
    }
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
 *   an array of taxonomy term IDs.
 *
 * @return string
 *   The type of category (taxonomy terms) and the items included in it.
 */
function mass_contact_taxonomy_categories($recipients) {
  // Check to see if a taxonomy term has been selected.
  if (!isset($recipients['mass_contact_taxonomy']) || empty($recipients['mass_contact_taxonomy'])) {
    return;
  }

  // Get the list of term objects for the specified term IDs.
  $terms = taxonomy_term_load_multiple($recipients['mass_contact_taxonomy']);
  if (empty($terms)) {
    return;
  }

  $term_names = array();
  foreach ($terms as $term) {
    // For each term object, add the name to an array.
    $term_names[] = $term->name;
  }

  // Return the list of terms included in this category.
  return t('Taxonomy terms: %terms', array('%terms' => implode(', ', $term_names)));
}


/**
 * Creates a form element for Category add/edit page.
 *
 * @param array $recipients
 *   The list of items for this category. For this plugin implementation, it is
 *   an array of taxonomy term IDs.
 *
 * @return array
 *   The form snippet.
 */
function mass_contact_taxonomy_admin_edit($recipients) {
  // Get the list of all fields on the user entity.
  $user_fields = field_info_instances('user');
  if (empty($user_fields)) {
    return;
  }

  $taxonomy_fields = array();
  // Iterate through all the fields attached to the user entity.
  foreach ($user_fields['user'] as $user_field_instance) {
    // Get the field's information.
    $field = field_info_field($user_field_instance['field_name']);
    if (isset($field['module']) && $field['module'] == 'taxonomy') {
      // If the module providing this field is Taxonomy, add the field to the
      // field_name => vocabulary array of taxonomy fields.
      $taxonomy_fields[$field['field_name']] = $field['settings']['allowed_values'][0]['vocabulary'];
    }
  }

  $form_element = array();
  // Iterate through the array of fields.
  foreach ($taxonomy_fields as $field_name => $vocabulary_name) {
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);
    if (!empty($vocabulary)) {
      $terms = taxonomy_get_tree($vocabulary->vid);
      if (!empty($terms)) {
        $options = array();
        foreach ($terms as $term) {
          $options[$term->tid] = check_plain($term->name);
        }
        $default_value = array();
        if (isset($recipients['mass_contact_taxonomy'])) {
          $default_value = $recipients['mass_contact_taxonomy'];
        }

        // Create a set of checkboxes, including each possible term.
        $form_element[$field_name] = array(
          '#type' => 'checkboxes',
          '#title' => t('Taxonomy vocabulary: %vocabulary', array('%vocabulary' => $vocabulary->name)),
          '#options' => $options,
          '#default_value' => $default_value,
        );
      }
    }
  }

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
function mass_contact_taxonomy_admin_edit_validate($form, &$form_state) {
  if (!empty($form_state['values']['recipients']['mass_contact_taxonomy'])) {
    foreach ($form_state['values']['recipients']['mass_contact_taxonomy'] as $term_values) {
      $term_values_filtered = array_filter($term_values);
      if (!empty($term_values_filtered)) {
        return FALSE;
      }
    }
  }

  return TRUE;
}

/**
 * Add/edit form submit callback.
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
 *   An array of term IDs.
 */
function mass_contact_taxonomy_admin_edit_submit($form, &$form_state) {
  $terms = array();
  if (!empty($form_state['values']['recipients']['mass_contact_taxonomy'])) {
    foreach ($form_state['values']['recipients']['mass_contact_taxonomy'] as $term_values) {
      $terms += array_filter($term_values);
    }
  }

  return $terms;
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
function mass_contact_taxonomy_user_edit($user) {
  // Get all the terms this user has selected.
  // Get the list of all fields on the user entity.
  $user_fields = field_info_instances('user');
  if (empty($user_fields)) {
    return;
  }

  // Get a list of all taxonomy fields.
  $taxonomy_fields = array();
  // Iterate through all the fields attached to the user entity.
  foreach ($user_fields['user'] as $user_field_instance) {
    // Get the field's information.
    $field = field_info_field($user_field_instance['field_name']);
    if (isset($field['module']) && $field['module'] == 'taxonomy') {
      // If the module providing this field is Taxonomy, add the field to the
      // field_name => vocabulary array of taxonomy fields.
      $taxonomy_fields[$field['field_name']] = $field['settings']['allowed_values'][0]['vocabulary'];
    }
  }

  // Put the term IDs into an array for later use.
  $users_terms = array();
  // Iterate through all the taxonomy fields.
  foreach ($taxonomy_fields as $field_id => $field_name) {
    // Iterate through each property in the user oblect to locate the taxonomy
    // fields.
    foreach ($user as $key => $value) {
      if ($key == $field_id) {
        if (!empty($value)) {
          foreach ($value[LANGUAGE_NONE] as $term_id) {
            // Save term.
            $users_terms[] = $term_id['tid'];
          }
        }
      }
    }
  }
  if (empty($users_terms)) {
    return;
  }

  // Get all the Mass Contact categories.
  $categories = db_select('mass_contact', 'mc')
    ->fields('mc', array('cid', 'category', 'recipients'))
    ->execute();

  // Collect all the categories which contain terms the user has selected.
  $included_categories = array();
  // Iterate through each category.
  foreach ($categories as $category) {
    // Pull out the roles that are a part of this category.
    $recipients = unserialize($category->recipients);
    foreach ($recipients['mass_contact_taxonomy'] as $term_id) {
      // If the category's term is one the user has selected, show the category.
      if (in_array($term_id, $users_terms)) {
        $included_categories[$category->cid] = $category->category;
      }
    }
  }

  return $included_categories;
}
