<?php

/**
 * @file
 * Field hooks.
 */

/**
 * Implements hook_field_info().
 */
function mailchimp_lists_field_info() {
  return array(
    'mailchimp_lists_subscription' => array(
      'label' => t('MailChimp Subscription'),
      'description' => t('Allows an entity to be subscribed to a MailChimp list.'),
      'mc_list_id' => NULL,
      'double_opt_in' => FALSE,
      'send_welcome' => TRUE,
      'instance_settings' => array(
        'show_interest_groups' => FALSE,
        'interest_groups_title' => NULL,
        'mergefields' => array(),
        'unsubscribe_on_delete' => TRUE,
        'options' => array(
          'subscribe' => FALSE,
          'interest_groups' => array(),
        ),
      ),
      'default_widget' => 'mailchimp_lists_select',
      'default_formatter' => 'mailchimp_lists_subscribe_default',
      'no_ui' => FALSE,
      'property_type' => 'mailchimp_lists_subscription',
      'property_callbacks' => array('mailchimp_lists_subscription_property_info_callback'),
    ),
  );
}

/**
 * Implements hook_field_settings_form().
 */
function mailchimp_lists_field_settings_form($this_field, $instance, $has_data) {
  $form = array();

  $lists = mailchimp_get_lists();
  $lists_exist = count($lists) > 0;
  $options = array('' => t('-- Select --'));
  foreach ($lists as $mc_list) {
    $options[$mc_list['id']] = $mc_list['name'];
  }
  // Grab the fields list.
  $fields = field_info_fields();
  // Remove options for MailChimp lists that already have fields.
  foreach ($fields as $field) {
    if ($field['type'] == 'mailchimp_lists_subscription') {
      if ($field['id'] != $this_field['id'] && isset($field['settings']['mc_list_id'])) {
        unset($options[$field['settings']['mc_list_id']]);
      }
    }
  }

  // If there are no available lists, provide a warning..
  if (count($options)==1) {
    $warning = $lists_exist
             ? 'All available MailChimp lists are already attached to MailChimp Subscription Fields.'
             : 'No available MailChimp lists exist.';
    $warning .= ' Create a new list at !mc, then !cc.';

    drupal_set_message(t(
        $warning,
        array(
          '!mc' => l(t('MailChimp'), 'https://admin.mailchimp.com'),
          '!cc' => l(t('clear your list cache'),
                 'admin/config/services/mailchimp/list_cache_clear',
                 array('query' => array('destination' => $_GET['q']))),
        )),
      'warning'
    );
    $disabled = TRUE;
  } else {
    $disabled = FALSE;
  }

  $form['mc_list_id'] = array(
    '#type' => 'select',
    '#title' => t('MailChimp List'),
    '#multiple' => FALSE,
    '#description' => t('Available MailChimp lists which are not already attached to MailChimp Subscription Fields. If unavailable, make sure you have created a list at !MailChimp first, then !cacheclear.',
                    array(
                      '!MailChimp' => l(t('MailChimp'), 'https://admin.mailchimp.com'),
                      '!cacheclear' => l(t('clear your list cache'),
                                     'admin/config/services/mailchimp/list_cache_clear',
                                     array('query' => array('destination' => $_GET['q']))),
                    )),
    '#options' => $options,
    '#default_value' => isset($this_field['settings']['mc_list_id']) ? $this_field['settings']['mc_list_id'] : FALSE,
    '#required' => TRUE,
    '#disabled' => $disabled,
  );
  $form['double_opt_in'] = array(
    '#type' => 'checkbox',
    '#title' => t('Require subscribers to Double Opt-in'),
    '#description' => t('New subscribers will be sent a link with an email they must follow to confirm their subscription.'),
    '#default_value' => isset($this_field['settings']['double_opt_in']) ? $this_field['settings']['double_opt_in'] : FALSE,
    '#disabled' => $disabled,
  );
  $form['send_welcome'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send a welcome email to new subscribers'),
    '#description' => t('New subscribers will be sent a welcome email once they are confirmed.'),
    '#default_value' => isset($this_field['settings']['send_welcome']) ? $this_field['settings']['send_welcome'] : FALSE,
    '#disabled' => $disabled,
  );
  $form['unsubscribe_action'] = array(
    '#type' => 'radios',
    '#title' => t('Action to take when unchecking this field'),
    '#description' => t('When this field gets unchecked you can choose if the subscriber gets unsubscribed (to keep the subscriber data in MailChimp) or completely removed from the Mailchimp list.'),
    '#options' => array(
      'unsubscribe' => t('Unsubscribe from list'),
      'remove' => t('Remove from list'),
    ),
    '#default_value' => isset($this_field['settings']['unsubscribe_action']) ? $this_field['settings']['unsubscribe_action'] : 'remove',
  );

  return $form;
}

/**
 * Implements hook_field_instance_settings_form().
 */
function mailchimp_lists_field_instance_settings_form($field, $instance) {
  $form = array();
  $mc_list_id = $field['settings']['mc_list_id'];
  $form['show_interest_groups'] = array(
    '#title' => t('Enable Interest Groups'),
    '#type' => 'checkbox',
    '#default_value' => $instance['settings']['show_interest_groups'],
  );
  $form['interest_groups_title'] = array(
    '#title' => t('Interest Groups Label'),
    '#type' => 'textfield',
    '#default_value' => isset($instance['settings']['interest_groups_title']) ? $instance['settings']['interest_groups_title'] : "Interest Groups",
  );

  $form['mergefields'] = array(
    '#type' => 'fieldset',
    '#title' => t('Merge Fields'),
    '#tree' => TRUE,
    '#prefix' => '<div id="mergefield-wrapper">',
    '#suffix' => '</div>',
    '#field' => $field,
    '#instance' => $instance,
    '#mc_list_id' => $mc_list_id,
    '#process' => array(
      '_mailchimp_lists_field_instance_settings_form_process',
    ),
  );

  $form['unsubscribe_on_delete'] = array(
    '#title' => t('Unsubscribe on deletion'),
    '#type' => 'checkbox',
    '#description' => t('Unsubscribe entities from this list when they are deleted.'),
    '#default_value' => $instance['settings']['unsubscribe_on_delete'],
  );

  return $form;
}

/**
 * Element processor. Expand the mergefields mapping form.
 *
 * Doing it this way instead of adding all the mapping fields inside of the
 * hook_field_instance_settings_form() implementation allows us to use AJAX in
 * the settings form to toggle between the basic and advanced mapping UI.
 */
function _mailchimp_lists_field_instance_settings_form_process($form, &$form_state) {
  $field = $form['#field'];
  $instance = $instance = isset($form_state['mailchimp']['instance']) ? $form_state['mailchimp']['instance'] : $form['#instance'];
  $mc_list_id = $form['#mc_list_id'];

  $mv_defaults = $instance['settings']['mergefields'];
  $use_advanced_mode = isset($mv_defaults['advanced']) ? (bool) $mv_defaults['advanced'] : FALSE;

  // If the AJAX checkbox to toggle between advanced and basic input mode has
  // been clicked we can use that info here to override what is stored in the
  // database.
  // TODO: figure out why 'mergefields' is in 'input' but not 'values'
  if (isset($form_state['input']) && isset($form_state['input']['instance']['settings']['mergefields']['advanced'])) {
    $use_advanced_mode = (bool) $form_state['input']['instance']['settings']['mergefields']['advanced'];
  }

  $form['#description'] = $use_advanced_mode ? t('Use tokens like [user:mail] which will be replaced with the appropriate value before sending them to MailChimp.') : t('Multi-value fields will only sync their first value to MailChimp.');

  $mergevars = mailchimp_get_mergevars(array($mc_list_id));
  $fields = mailchimp_lists_fieldmap_options($instance['entity_type'], $instance['bundle']);
  $required_fields = mailchimp_lists_fieldmap_options($instance['entity_type'], $instance['bundle'], TRUE);
  unset($fields[$field['field_name']]);
  foreach ($mergevars[$mc_list_id]['merge_vars'] as $mergevar) {
    $default_value = isset($mv_defaults[$mergevar['tag']]) ? $mv_defaults[$mergevar['tag']] : -1;
    // If the advanced UI is enabled we use a textfield here, otherwise use a
    // select field.
    $form[$mergevar['tag']] = array(
      '#type' => $use_advanced_mode ? 'textfield' : 'select',
      '#title' => check_plain($mergevar['name']),
      '#default_value' => $default_value ? $default_value : '',
      '#required' => $mergevar['req'],
    );
    if (!$mergevar['req'] || $mergevar['tag'] === 'EMAIL') {
      // Add select field options when using basic UI.
      if (!$use_advanced_mode) {
        $form[$mergevar['tag']]['#options'] = $fields;
      }

      if ($mergevar['tag'] === 'EMAIL') {
        $form[$mergevar['tag']]['#description'] = t('Any entity with an empty or invalid email address field value will simply be ignored by the MailChimp subscription system. <em>This is why the Email field is the only required merge field which can sync to non-required fields.</em>');
      }
    }
    else {
      // Add options for select fields when using basic UI.
      if (!$use_advanced_mode) {
        $form[$mergevar['tag']]['#options'] = $required_fields;
      }

      $form[$mergevar['tag']]['#description'] = t("Only 'required' and 'calculated' fields are allowed to be synced with MailChimp 'required' merge fields.");
    }
  }

  // If we're displaying the advanced mode UI, and the token module from contrib
  // is enabled we can use its ability to add some additional features like a
  // better token browser, and better validation.
  if ($use_advanced_mode && module_exists('token')) {
    // Add element validator for each text field. This allows the token module
    // to provide feedback on token syntax.
    foreach ($mergevars[$mc_list_id]['merge_vars'] as $mergevar) {
      $form[$mergevar['tag']] += array(
        '#element_validate' => array('token_element_validate'),
        '#token_types' => array($instance['entity_type']),
      );
    }

    // Add the UI for browsing tokens.
    $form['_tokens'] = array(
      '#theme' => 'token_tree_link',
      '#token_types' => array($instance['entity_type']),
      '#global_types' => TRUE,
      '#click_insert' => TRUE,
    );
  }

  // Toggle advanced mode, allows for directly entering tokens into a textfield
  // rather than using the <select> based UI.
  $form['advanced'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable advanced mapping'),
    '#description' => t('Enable token based input to deal with multi-value fields and gain more control over formatting.'),
    '#default_value' => $use_advanced_mode,
    '#ajax' => array(
      'callback' => 'mailchimp_lists_field_instance_settings_form_ajax_callback',
      'wrapper' => 'mergefield-wrapper',
    ),
  );

  return $form;
}

/**
 * Validation callback for MailChimp field instance settings form element.
 */
function _mailchimp_lists_field_instance_settings_validate($form, &$form_state) {
  // Store the new values in the form state.
  $instance = $form['#instance'];
  if (isset($form_state['values']['instance'])) {
    $instance = drupal_array_merge_deep($instance, $form_state['values']['instance']);
  }
  $form_state['mailchimp']['instance'] = $instance;
}

/**
 * Callback for AJAX request triggered by checkbox to toggle advanced UI on/off.
 */
function mailchimp_lists_field_instance_settings_form_ajax_callback($form, &$form_state) {
  return $form['instance']['settings']['mergefields'];
}

/**
 * Implements hook_field_validate().
 */
function mailchimp_lists_field_validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
  if ($instance['required'] && $entity !== NULL) {
    foreach ($items as $delta => $item) {
      if (!$item['subscribe']) {
        $errors[$field['field_name']][$langcode][$delta][] = array(
          'error' => 'mailchimp_lists_required',
          'message' => t('Subscription to MailChimp List %name is required.', array('%name' => $instance['label'])),
        );
        return FALSE;
      }
    }
  }
  return TRUE;
}

/**
 * Implements hook_field_is_empty().
 */
function mailchimp_lists_field_is_empty($item, $field) {
  return FALSE;
}

/**
 * Implements hook_field_widget_info().
 */
function mailchimp_lists_field_widget_info() {
  return array(
    'mailchimp_lists_select' => array(
      'label' => t('Subscription form'),
      'field types' => array('mailchimp_lists_subscription'),
      'settings' => array(),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_DEFAULT,
        'default value' => FIELD_BEHAVIOR_DEFAULT,
      ),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 */
function mailchimp_lists_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $default = isset($instance['default_value'][0]['subscribe']) ? $instance['default_value'][0]['subscribe'] : FALSE;
  $email = NULL;
  if (isset($element['#entity'])) {
    $email = mailchimp_lists_load_email($instance, $element['#entity'], FALSE);
    if ($email) {
      $default = mailchimp_is_subscribed($field['settings']['mc_list_id'], $email);
    }
  }
  $element += array(
    '#title' => check_plain($element['#title']),
    '#type' => 'fieldset',
  );
  $element['subscribe'] = array(
    '#title' => t('Subscribe'),
    '#type' => 'checkbox',
    '#default_value' => $default || $instance['required'],
    '#required' => $instance['required'],
    '#disabled' => $instance['required'],
  );
  if ($instance['settings']['show_interest_groups'] || $form_state['build_info']['form_id'] == 'field_ui_field_edit_form') {
    $mc_list = mailchimp_get_list($field['settings']['mc_list_id']);
    $element['interest_groups'] = array(
      '#type' => 'fieldset',
      '#title' => check_plain($instance['settings']['interest_groups_title']),
      '#weight' => 100,
      '#states' => array(
        'invisible' => array(
          ':input[name="' . $field['field_name'] . '[' . $langcode . '][0][subscribe]"]' => array('checked' => FALSE),
        ),
      ),
    );
    if ($form_state['build_info']['form_id'] == 'field_ui_field_edit_form') {
      $element['interest_groups']['#states']['invisible'] = array(
        ':input[name="instance[settings][show_interest_groups]"]' => array('checked' => FALSE),
      );
    }
    $groups_default = isset($instance['default_value'][0]['interest_groups']) ? $instance['default_value'][0]['interest_groups'] : array();
    if ($mc_list['stats']['group_count']) {
      $element['interest_groups'] += mailchimp_interest_groups_form_elements($mc_list, $groups_default, $email);
    }
  }

  // Make a distinction between whether the field is edited by the system or the user.
  // This is important to prevent unwanted subscription overwrites.
  // @see _mailchimp_lists_field_postsave()
  if (isset($element['#entity'])) {
    // The field is edited via the UI.
    $element['is_default'] = array(
      '#type' => 'value',
      '#value' => FALSE,
    );
  }
  else {
    // The field is NOT edited via the UI.
    $element['is_default'] = array(
      '#type' => 'value',
      '#value' => TRUE,
    );
  }

  $element['#element_validate'] = array('mailchimp_lists_field_widget_form_validate');

  return $element;
}

/**
 * Validation callback for mailchimp_lists_select widget.
 */
function mailchimp_lists_field_widget_form_validate(&$element, &$form_state) {
  if (isset($element['#access']) && !$element['#access']) {
    // When the field is not accessible, do not accept any values.
    // Else the default value will be send to MailChimp, which causes
    // an existing subscription to be overwritten.
    form_set_value($element, NULL, $form_state);
  }
}

/**
 * Implements hook_field_formatter_info().
 */
function mailchimp_lists_field_formatter_info() {
  return array(
    'mailchimp_lists_field_subscribe' => array(
      'label' => t('Subscription Form'),
      'field types' => array('mailchimp_lists_subscription'),
      'settings' => array(
        'show_interest_groups' => FALSE,
      ),
    ),
    'mailchimp_lists_subscribe_default' => array(
      'label' => t('Subscription Info'),
      'field types' => array('mailchimp_lists_subscription'),
      'settings' => array(
        'show_interest_groups' => FALSE,
        'interest_groups' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function mailchimp_lists_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();
  $element['show_interest_groups'] = array(
    '#title' => t('Show Interest Groups'),
    '#type' => 'checkbox',
    '#description' => $instance['settings']['show_interest_groups'] ? t('Check to display interest group membership details.') : t('To display Interest Groups, first enable them in the field instance settings.'),
    '#default_value' => $instance['settings']['show_interest_groups'] && $settings['show_interest_groups'],
    '#disabled' => !$instance['settings']['show_interest_groups'],
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function mailchimp_lists_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  if ($settings['show_interest_groups'] && $instance['settings']['show_interest_groups']) {
    $summary = t('Display Interest Groups');
  }
  else {
    $summary = t('Hide Interest Groups');
  }

  return $summary;
}

/**
 * Implements hook_field_formatter_view().
 */
function mailchimp_lists_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $mc_list = mailchimp_get_list($field['settings']['mc_list_id']);
  $email = mailchimp_lists_load_email($instance, $entity, FALSE);

  // Display subscription form if accessible.
  if ($display['type'] == 'mailchimp_lists_field_subscribe' && $email && entity_access('edit', $entity_type, $entity)) {
    $field_form_id = 'mailchimp_lists_' . $field['field_name'] . '_form';
    $element = drupal_get_form($field_form_id, $instance, $display['settings'], $entity, $field);
  }
  else {
    if ($email) {
      if (mailchimp_is_subscribed($field['settings']['mc_list_id'], $email)) {
        $status = t('Subscribed to %list', array('%list' => $mc_list['name']));
      }
      else {
        $status = t('Not subscribed to %list', array('%list' => $mc_list['name']));
      }
    }
    else {
      $status = t('Invalid email configuration.');
    }
    $element['status'] = array(
      '#markup' => $status,
      '#description' => t('@mc_list_description', array('@mc_list_description' => $instance['description'])),
    );
    if ($instance['settings']['show_interest_groups'] && $display['settings']['show_interest_groups']) {
      $memberinfo = mailchimp_get_memberinfo($field['settings']['mc_list_id'], $email);
      if (isset($memberinfo['merges']['GROUPINGS'])) {
        $element['interest_groups'] = array(
          '#type' => 'fieldset',
          '#title' => t('Interest Groups'),
          '#weight' => 100,
        );
        foreach ($memberinfo['merges']['GROUPINGS'] as $grouping) {
          $items = array();
          foreach ($grouping['groups'] as $interest) {
            if ($interest['interested']) {
              $items[] = $interest['name'];
            }
          }
          if (count($items)) {
            $element['interest_groups'][$grouping['id']] = array(
              '#title' => $grouping['name'],
              '#theme' => 'item_list',
              '#items' => $items,
              '#type' => 'ul',
            );
          }
        }
      }
    }
  }

  return array($element);
}

/**
 * Implements hook_field_prepare_view().
 *
 * Our field has no actual data in the database, so we have to push a dummy
 * value into $items, or the render system will assume we have nothing to
 * display. See https://api.drupal.org/comment/48043#comment-48043
 */
function mailchimp_lists_field_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items) {
  if ($field['type'] == 'mailchimp_lists_subscription') {
    foreach ($items as $key => $item) {
      $items[$key][0]['value'] = 'Dummy value';
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function mailchimp_lists_form_field_ui_field_edit_form_alter(&$form, &$form_state, $form_id) {
  if ($form['#field']['type'] == 'mailchimp_lists_subscription') {
    // Disable the list selector on the instance config page:
    $form['field']['settings']['mc_list_id']['#disabled'] = TRUE;
    $form['field']['settings']['mc_list_id']['#description'] = t("To alter this list, use the 'Field Settings' tab");
    // Hide the cardinality setting:
    $form['field']['cardinality']['#default_value'] = 1;
    $form['field']['cardinality']['#access'] = FALSE;
    $form['#validate'][] = 'mailchimp_lists_form_field_ui_field_edit_form_validate';
  }
}

/**
 * Validation handler for mailchimp_lists_form_field_ui_field_edit_form.
 *
 * Ensure cardinality is set to 1 on mailchimp_lists_subscription fields.
 */
function mailchimp_lists_form_field_ui_field_edit_form_validate(&$form, &$form_state) {
  if ($form['#field']['type'] == 'mailchimp_lists_subscription') {
    if ($form_state['values']['field']['cardinality'] !== 1) {
      form_set_error('cardinality', t('Cardinality on MailChimp lists fields must be set to one.'));
    }
  }
}

/**
 * Property callback for mailchimp_lists_subscription field.
 */
function mailchimp_lists_subscription_property_info_callback(&$info, $entity_type, $field, $instance, $field_type) {
  $name = $field['field_name'];
  $property = &$info[$entity_type]['bundles'][$instance['bundle']]['properties'][$name];

  $property['type'] = 'mailchimp_lists_subscription';
  $property['getter callback'] = 'mailchimp_lists_field_get';
  $property['setter callback'] = 'entity_metadata_field_verbatim_set';

  unset($property['query callback']);
}

/**
 * Entity field data callback for MailChimp subscription fields.
 */
function mailchimp_lists_field_get($entity, array $options, $name, $entity_type, &$context) {
  $verbatim = entity_metadata_field_verbatim_get($entity, $options, $name, $entity_type, $context);
  // If we're creating or updating field values they shouldn't be mucked with:
  if (isset($verbatim['subscribe'])) {
    return $verbatim;
  }
  $email = mailchimp_lists_load_email($context['instance'], $entity);
  $subscribed = mailchimp_is_subscribed($context['field']['settings']['mc_list_id'], $email);
  $val = array('subscribe' => $subscribed);
  if ($context['instance']['settings']['show_interest_groups']) {
    $mc_list = mailchimp_get_list($context['field']['settings']['mc_list_id']);
    if (isset($mc_list['intgroups'])) {
      $val['interest_groups'] = array();
      $interest_group_settings = mailchimp_interest_groups_form_elements($mc_list, array(), $email);
      foreach ($interest_group_settings as $id => $group) {
        $val['interest_groups'][$id] = $group['#options'];
        foreach ($val['interest_groups'][$id] as $key => &$value) {
          if (!in_array($key, $group['#default_value'])) {
            $value = 0;
          }
        }
      }
    }
  }
  return $val;
}

/**
 * Implements hook_field_insert().
 */
function mailchimp_lists_field_insert($entity_type, $entity, $field, $instance, $langcode, &$items) {
  _mailchimp_lists_field_postsave($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_update().
 */
function mailchimp_lists_field_update($entity_type, $entity, $field, $instance, $langcode, &$items) {
  _mailchimp_lists_field_postsave($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * If we have any mailchimp_lists_subscription fields, we handle any changes to
 * them by making appropriate subscription calls.
 */
function _mailchimp_lists_field_postsave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  if ($field['type'] == 'mailchimp_lists_subscription') {
    $entity_wrapper = entity_metadata_wrapper($entity_type, $entity);
    $choices = $entity_wrapper->{$instance['field_name']}->value();

    if (!isset($entity->is_new)) {
      $entity->is_new = (($entity_wrapper->getIdentifier() === FALSE) || ($entity_wrapper->getIdentifier() === NULL));
    }

    // Check if the field is empty or is set by the system via field_get_default_value().
    if (empty($items[0]) || !empty($item[0]['is_default'])) {
      // Check if this email is already subscribed.
      $email = mailchimp_lists_load_email($instance, $entity);
      $list_id = $field['settings']['mc_list_id'];
      $subscribed = mailchimp_is_subscribed($list_id, $email);
      if ($subscribed) {
        // The mail address is already subscribed. Do not overwrite the subscription.
        return;
      }

      $choices = $instance['default_value'][0];
    }

    mailchimp_lists_process_subscribe_form_choices($choices, $instance, $field, $entity);
  }
}
