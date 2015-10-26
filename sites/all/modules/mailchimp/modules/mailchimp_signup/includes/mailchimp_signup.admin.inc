<?php

/**
 * @file
 * mailchimp_signup module admin settings.
 */

/**
 * Return a form for adding/editing a MailChimp signup form.
 */
function mailchimp_signup_form($form, &$form_state, MailchimpSignup $signup) {
  // Store the existing list for updating on submit.
  $form_state['signup'] = $signup;

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('The title for this signup form.'),
    '#size' => 35,
    '#maxlength' => 32,
    '#default_value' => $signup->title,
    '#required' => TRUE,
  );

  // Machine-readable list name.
  $status = isset($signup->status) && $signup->mcs_id && (($signup->status & ENTITY_IN_CODE) || ($signup->status & ENTITY_FIXED));
  $form['name'] = array(
    '#type' => 'machine_name',
    '#default_value' => $signup->name,
    '#maxlength' => 32,
    '#disabled' => $status,
    '#machine_name' => array(
      'exists' => 'mailchimp_signup_load_multiple_by_name',
      'source' => array('title'),
    ),
    '#description' => t('A unique machine-readable name for this list. It must only contain lowercase letters, numbers, and underscores.'),
  );
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => isset($signup->settings['description']) ? $signup->settings['description'] : '',
    '#rows' => 2,
    '#maxlength' => 500,
    '#description' => t('This description will be shown on the signup form below the title. (500 characters or less)'),
  );
  $mode_defaults = array(
    MAILCHIMP_SIGNUP_BLOCK => array(MAILCHIMP_SIGNUP_BLOCK),
    MAILCHIMP_SIGNUP_PAGE => array(MAILCHIMP_SIGNUP_PAGE),
    MAILCHIMP_SIGNUP_BOTH => array(MAILCHIMP_SIGNUP_BLOCK, MAILCHIMP_SIGNUP_PAGE),
  );
  $form['mode'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Display Mode'),
    '#required' => TRUE,
    '#options' => array(
      MAILCHIMP_SIGNUP_BLOCK => 'Block',
      MAILCHIMP_SIGNUP_PAGE => 'Page',
    ),
    '#default_value' => !empty($signup->mode) ? $mode_defaults[$signup->mode] : array(),
  );

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['settings']['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Page URL'),
    '#description' => t('Path to the signup page. ie "newsletter/signup".'),
    '#default_value' => isset($signup->settings['path']) ? $signup->settings['path'] : NULL,
    '#states' => array(
      // Hide unless needed.
      'visible' => array(
        ':input[name="mode[' . MAILCHIMP_SIGNUP_PAGE . ']"]' => array('checked' => TRUE),
      ),
      'required' => array(
        ':input[name="mode[' . MAILCHIMP_SIGNUP_PAGE . ']"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['settings']['submit_button'] = array(
    '#type' => 'textfield',
    '#title' => t('Submit Button Label'),
    '#required' => 'TRUE',
    '#default_value' => isset($signup->settings['submit_button']) ? $signup->settings['submit_button'] : t('Submit'),
  );

  $form['settings']['confirmation_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Confirmation Message'),
    '#description' => t('This message will appear after a successful submission of this form. Leave blank for no message, but make sure you configure a destination in that case unless you really want to confuse your site visitors.'),
    '#default_value' => isset($signup->settings['confirmation_message']) ? $signup->settings['confirmation_message'] : t('You have been successfully subscribed.'),
  );

  $form['settings']['destination'] = array(
    '#type' => 'textfield',
    '#title' => t('Form destination page'),
    '#description' => t('Leave blank to stay on the form page.'),
    '#default_value' => isset($signup->settings['destination']) ? $signup->settings['destination'] : NULL,
  );

  $form['mc_lists_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('MailChimp List Selection & Configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $lists = mailchimp_get_lists();
  $options = array();
  foreach ($lists as $mc_list) {
    $options[$mc_list['id']] = $mc_list['name'];
  }
  $form['mc_lists_config']['mc_lists'] = array(
    '#type' => 'checkboxes',
    '#title' => t('MailChimp Lists'),
    '#description' => t('Select which lists to show on your signup form. You can create additional lists at !MailChimp.',
      array('!MailChimp' => l(t('MailChimp'), 'https://admin.mailchimp.com'))),
    '#options' => $options,
    '#default_value' => is_array($signup->mc_lists) ? $signup->mc_lists : array(),
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'mailchimp_signup_mergefields_callback',
      'wrapper' => 'mergefields-wrapper',
      'method' => 'replace',
      'effect' => 'fade',
      'progress' => array(
        'type' => 'throbber',
        'message' => t('Retrieving merge fields for this list.'),
      ),
    ),
  );

  $form['mc_lists_config']['mergefields'] = array(
    '#prefix' => '<div id="mergefields-wrapper">',
    '#suffix' => '</div>',
  );

  // Show merge fields if changing list field or editing existing list.
  if (!empty($form_state['values']['mc_lists']) || !isset($signup->is_new) || !$signup->is_new) {
    $form['mc_lists_config']['mergefields'] = array(
      '#type' => 'fieldset',
      '#title' => t('Merge Field Display'),
      '#description' => t('Select the merge fields to show on registration forms. Required fields are automatically displayed.'),
      '#id' => 'mergefields-wrapper',
      '#tree' => TRUE,
      '#weight' => 20,
    );
    $mc_lists = !empty($form_state['values']['mc_lists']) ? $form_state['values']['mc_lists'] : $signup->mc_lists;
    $mergevar_settings = mailchimp_get_mergevars(array_filter($mc_lists));
    $form_state['mergevar_options'] = array();
    foreach ($mergevar_settings as $list_mergevars) {
      foreach ($list_mergevars['merge_vars'] as $mergevar) {
        $form_state['mergevar_options'][$mergevar['tag']] = $mergevar;
        if (!$mergevar['public']) {
          $form_state['mergevar_options'][$mergevar['tag']]['name'] .= ' (private)';
        };
      }
    }
    foreach ($form_state['mergevar_options'] as $mergevar) {
      $form['mc_lists_config']['mergefields'][$mergevar['tag']] = array(
        '#type' => 'checkbox',
        '#title' => check_plain($mergevar['name']),
        '#default_value' => isset($signup->settings['mergefields'][$mergevar['tag']]) ? !empty($signup->settings['mergefields'][$mergevar['tag']]) : TRUE,
        '#required' => $mergevar['req'],
        '#disabled' => $mergevar['req'],
      );
    }
  }

  $form['subscription_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Subscription Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['subscription_settings']['doublein'] = array(
    '#type' => 'checkbox',
    '#title' => t('Require subscribers to Double Opt-in'),
    '#description' => t('New subscribers will be sent a link with an email they must follow to confirm their subscription.'),
    '#default_value' => isset($signup->settings['doublein']) ? $signup->settings['doublein'] : FALSE,
  );

  $form['subscription_settings']['send_welcome'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send a welcome email to new subscribers'),
    '#description' => t('New subscribers will be sent a welcome email once they are confirmed.'),
    '#default_value' => isset($signup->settings['send_welcome']) ? $signup->settings['send_welcome'] : FALSE,
  );

  $form['subscription_settings']['include_interest_groups'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include interest groups on subscription form.'),
    '#default_value' => isset($signup->settings['include_interest_groups']) ? $signup->settings['include_interest_groups'] : FALSE,
    '#description' => t('If set, subscribers will be able to select applicable interest groups on the signup form.'),
  );

  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#access' => isset($signup),
    '#submit' => array('mailchimp_signup_delete_submit'),
  );
  $form['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => 'admin/config/services/mailchimp/signup',
  );

  return $form;
}

/**
 * AJAX callback to return fields for a given type.
 *
 * Returns the form lists configuration fields.
 */
function mailchimp_signup_mergefields_callback($form, $form_state) {
  return $form['mc_lists_config']['mergefields'];
}

/**
 * Submit handler for mailchimp_signup_form().
 */
function mailchimp_signup_form_submit($form, &$form_state) {
  if (isset($form_state['signup'])) {
    $signup = $form_state['signup'];
    $prior_settings = $signup->settings;
    if (!$form_state['values']['mode'][MAILCHIMP_SIGNUP_PAGE]) {
      $form_state['values']['settings']['path'] = '';
    }
  }
  else {
    $signup = mailchimp_signup_create();
    $prior_settings = array();
  }
  $mergefields = $form_state['values']['mergefields'];
  foreach ($mergefields as $id => $val) {
    if ($val) {
      $mergefields[$id] = $form_state['mergevar_options'][$id];
    }
  }
  $signup->title = $form_state['values']['title'];
  $signup->name = $form_state['values']['name'];
  $signup->mode = array_sum($form_state['values']['mode']);
  $signup->mc_lists = array_filter($form_state['values']['mc_lists']);
  $signup->settings = $form_state['values']['settings'];
  $signup->settings['mergefields'] = $mergefields;
  $signup->settings['description'] = $form_state['values']['description'];
  $signup->settings['doublein'] = $form_state['values']['doublein'];
  $signup->settings['send_welcome'] = $form_state['values']['send_welcome'];
  $signup->settings['include_interest_groups'] = $form_state['values']['include_interest_groups'];
  if ($signup->save()) {
    if (isset($form_state['values']['settings']['path'])) {
      if (!isset($prior_settings['path']) || $prior_settings['path'] != $signup->settings['path'] || !($signup->mode & MAILCHIMP_SIGNUP_PAGE)) {
        // We have a new (or removed) path. Rebuild menus.
        menu_rebuild();
      }
    }
    drupal_set_message(t('Signup form @name has been saved.',
      array('@name' => $signup->name)));
    $form_state['redirect'] = 'admin/config/services/mailchimp/signup';
  }
  else {
    drupal_set_message(t('There has been an error saving your signup form.'), 'error');
  }
}

/**
 * Signup deletion form.
 */
function mailchimp_signup_signup_delete_form($form, &$form_state, $signup) {
  $form_state['signup'] = $signup;
  return confirm_form($form,
    t('Are you sure you want to delete the signup form %name?', array('%name' => $signup->label())),
    'admin/config/services/mailchimp/signup/' . $signup->identifier() . '/edit',
    t('This action cannot be undone.'),
    t('Delete Signup form'));
}

/**
 * Submit function for the delete button on the signup overview and edit forms.
 */
function mailchimp_signup_delete_submit($form, &$form_state) {
  $form_state['redirect'] = 'admin/config/services/mailchimp/signup/' . $form_state['signup']->identifier() . '/delete';
}

/**
 * Submit handler for mailchimp_signup_signup_delete_form().
 */
function mailchimp_signup_signup_delete_form_submit($form, &$form_state) {
  $signup = $form_state['signup'];
  mailchimp_signup_delete_multiple(array($signup->identifier()));
  drupal_set_message(t('%name has been deleted.', array('%name' => $signup->label())));
  $form_state['redirect'] = 'admin/config/services/mailchimp/signup';
}

/**
 * Create a new Mailchimp Signup object.
 *
 * @param array $values
 *   Associative array of values.
 *
 * @return MailchimpSignup
 *   New MailchimpSignup entity.
 */
function mailchimp_signup_create(array $values = array()) {
  return entity_get_controller('mailchimp_signup')->create($values);
}
