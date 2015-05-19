<?php
/**
 * @file
 * The main form for creating and sending the messages.
 */

/**
 * The mail page.
 *
 * @return array
 *   Either an error, if flood control is active and triggered, or a
 *   rendered form.
 */
function mass_contact_site_page() {
  if (!user_access('mass contact administer') && !flood_is_allowed('mass_contact', variable_get('mass_contact_hourly_threshold', 3))) {
    $output = t("You cannot send more than %number messages per hour. Please try again later.", array('%number' => variable_get('mass_contact_hourly_threshold', 3)));
  }
  else {
    $output = drupal_get_form('mass_contact_mail_page');
  }

  return $output;
}


/**
 * Generates the main Mass Contact mail form.
 *
 * @param array $form_state
 *   A keyed array containing the current state of the form.
 *
 * @return array
 *   An associative array that defines the form to be built.
 */
function mass_contact_mail_page($form, $form_state) {
  global $user;

  $form = array();
  $categories = array();
  $default_category = array();
  $default_category_name = '';

  $result = db_select('mass_contact', 'mc')
    ->fields('mc', array('cid', 'category', 'selected'))
    ->orderBy('weight', 'ASC')
    ->orderBy('category', 'ASC')
    ->execute();
  foreach ($result as $category) {
    if (user_access('mass contact send to users in the ' . $category->category . ' category')) {
      $categories[$category->cid] = $category->category;

      if ($category->selected) {
        $default_category[] = $category->cid;
        $default_category_name = $category->category;
      }
    }
  }

  if (count($categories) == 1) {
    $default_category = array_keys($categories);
    $default_category_name = $categories[$default_category[0]];
  }

  if (count($categories) > 0) {
    $form['contact_information'] = array(
      '#markup' => filter_xss_admin(variable_get('mass_contact_form_information', t('Send an email message using the contact form below.'))),
    );

    // Add the field for specifying the sender's name.
    $mass_contact_default_sender_name = variable_get('mass_contact_default_sender_name', '');
    if ($mass_contact_default_sender_name) {
      if (user_access('mass contact change default sender information')) {
        $form['name'] = array(
          '#type' => 'textfield',
          '#title' => t('Your name'),
          '#maxlength' => 255,
          '#default_value' => $mass_contact_default_sender_name,
          '#required' => TRUE,
        );
      }
      else {
        $form['name'] = array(
          '#type' => 'item',
          '#title' => t('Your name'),
          '#markup' => $mass_contact_default_sender_name,
        );
      }
    }
    else {
      $form['name'] = array(
        '#type' => 'textfield',
        '#title' => t('Your name'),
        '#maxlength' => 255,
        '#default_value' => $user->uid ? check_plain(format_username($user)) : '',
        '#required' => TRUE,
      );
    }

    // Add the field for specifying the sender's email address.
    $mass_contact_default_sender_email = variable_get('mass_contact_default_sender_email', '');
    if ($mass_contact_default_sender_email) {
      if (user_access('mass contact change default sender information')) {
        $form['mail'] = array(
          '#type' => 'textfield',
          '#title' => t('Your email address'),
          '#maxlength' => 255,
          '#default_value' => $mass_contact_default_sender_email,
          '#required' => TRUE,
        );
      }
      else {
        $form['mail'] = array(
          '#type' => 'item',
          '#title' => t('Your email address'),
          '#markup' => $mass_contact_default_sender_email,
        );
      }
    }
    else {
      $form['mail'] = array(
        '#type' => 'textfield',
        '#title' => t('Your email address'),
        '#maxlength' => 255,
        '#default_value' => $user->uid ? $user->mail : '',
        '#required' => TRUE,
      );
    }

    // Add the field for specifying the category(ies).
    if ((count($categories) > 1) || !isset($default_category)) {
      // Display a choice when one is needed.
      $field_type = variable_get('mass_contact_category_display', 'select');
      $form['cid'] = array(
        '#type' => $field_type,
        '#title' => t('Category'),
        '#default_value' => $default_category,
        '#options' => $categories,
        '#required' => TRUE,
        '#multiple' => TRUE,
      );
    }
    else {
      // Otherwise, just use the default category.
      $form['cid'] = array(
        '#type' => 'value',
        '#value' => $default_category,
      );
      $form['cid-info'] = array(
        '#type' => 'item',
        '#title' => t('Category'),
        '#markup' => '<p>This message will be sent to all users in the ' . $default_category_name . ' category.</p>',
      );
    }

    // Add the field for specifying whether opt-outs are respected or not.
    $optout_setting = variable_get('mass_contact_optout_d', 0);

    // Allow users to opt-out of mass emails:
    // 0 => 'No', 1 == 'Yes', 2 == 'Selected categories'.
    if ($optout_setting == 1 || $optout_setting == 2) {
      // Allow to override or respect opt-outs if admin, otherwise use default.
      if (user_access('mass contact administer')) {
        $form['optout'] = array(
          '#type' => 'checkbox',
          '#title' => t('Respect user opt-outs.'),
          '#default_value' => 1,
        );
      }
      else {
        $form['optout'] = array(
          '#type' => 'hidden',
          '#default_value' => 1,
        );
      }
    }
    else {
      $form['optout'] = array(
        '#type' => 'hidden',
        '#default_value' => 0,
      );
    }

    // Add the field for specifying whether the recipients are in the To or
    // BCC field of the message.
    // Check if the user is allowed to override the BCC setting.
    if (user_access('mass contact override bcc')) {
      $form['bcc'] = array(
        '#type' => 'checkbox',
        '#title' => t('Send as BCC (hide recipients)'),
        '#default_value' => variable_get('mass_contact_bcc_d', 1),
      );
    }
    // If not, then just display the BCC info.
    else {
      $form['bcc'] = array(
        '#type' => 'value',
        '#value' => variable_get('mass_contact_bcc_d', 1),
      );
      $form['bcc-info'] = array(
        '#type' => 'item',
        '#title' => t('Send as BCC (hide recipients)'),
        '#markup' => '<p>' . (variable_get('mass_contact_bcc_d', 1) ? t('Recipients will be hidden from each other.') : t('Recipients will NOT be hidden from each other.')) . '</p>',
      );
    }

    // Add the field for specifying the subject of the message.
    $form['subject'] = array(
      '#type' => 'textfield',
      '#title' => t('Subject'),
      '#maxlength' => 255,
      '#required' => TRUE,
    );

    // Add the field for specifying the body and text format of the message.
    // Get the HTML input format setting and the corresponding name.
    if (module_exists('mimemail')) {
      // Get the admin specified default text format.
      $default_filter_format = _mass_contact_compute_default_filter_format();

      // Check if the user is allowed to override the text format.
      if (user_access('mass contact override text format')) {
        // The user is allowed to override the text format, so display a
        // textarea that has the text format selection field attached.
        $form['body']['message'] = array(
          '#type' => 'text_format',
          '#title' => t('Message'),
          '#format' => !empty($default_filter_format) ? $default_filter_format : NULL,
          '#rows' => 12,
          '#required' => TRUE,
        );
      }
      else {
        // The user is not allowed to override the text format, so display a
        // textarea that does not have the text format selection field
        // attached.
        $form['body']['message'] = array(
          '#type' => 'textarea',
          '#title' => t('Message'),
          '#rows' => 12,
          '#required' => TRUE,
        );
        // Save the text format information for later use.
        $form['body_filter_format'] = array(
          '#type' => 'value',
          '#value' => $default_filter_format,
        );
        // Display text format information to the user.
        $form['body_filter_format_info'] = array(
          '#type' => 'item',
          '#description' => '<p>' . (variable_get('mass_contact_html_d', 1) ? t('The message will be sent using the %filter text format. More information about what is available is on the <a href="@formats_descriptions">Compose tips</a> page.', array('%filter' => $default_filter_format, '@formats_descriptions' => url('filter/tips'))) : t('The message will be sent as plain text.')) . '</p>',
        );
      }

      // If the user has access, add the field for specifying the attachment.
      if (user_access('mass contact include attachments')) {
        for ($i = 1; $i <= variable_get('mass_contact_number_of_attachments', '3'); $i++) {
          $form['attachment_' . $i] = array(
            '#type' => 'file',
            '#title' => t('Attachment #!number', array('!number' => $i)),
          );
        }
      }
    }
    else {
      // Mime Mail is not installed, so display a textarea that does not have
      // the text format selection field attached, as this message will only
      // be sent as plain text.
      $form['body']['message'] = array(
        '#type' => 'textarea',
        '#title' => t('Message'),
        '#rows' => 12,
        '#required' => TRUE,
      );
      // Save the text format information for later use.
      $form['body_filter_format'] = array(
        '#type' => 'value',
        '#value' => filter_format_load('plain_text'),
      );
      // Display text format information to the user.
      $form['body_filter_format_info'] = array(
        '#type' => 'item',
        '#description' => '<p>' . t('The message will be sent as plain text.') . '</p>',
      );
    }

    // We do not allow anonymous users to send themselves a copy because it
    // can be abused to spam people.
    if ($user->uid) {
      $form['copy'] = array(
        '#type' => 'checkbox',
        '#title' => t('Send yourself a copy.'),
      );
    }

    // Add the field for specifying whether to save the message as a node or
    // not.
    if (user_access('mass contact archive messages')) {
      // Check if the user is allowed to override the node copy setting.
      if (user_access('mass contact override archiving')) {
        $form['nodecc'] = array(
          '#type' => 'checkbox',
          '#title' => t('Archive a copy of this message on this website'),
          '#default_value' => variable_get('mass_contact_nodecc_d', 1),
        );
      }
      // If not, then do it or not based on the administrative setting.
      else {
        $form['nodecc'] = array(
          '#type' => 'hidden',
          '#default_value' => variable_get('mass_contact_nodecc_d', 1),
        );
        $form['nodecc_notice'] = array(
          '#type' => 'item',
          '#title' => t('Archive a copy of this message on this website'),
          '#markup' => t('A copy of this message will !not be archived on this website.', array('!not' => variable_get('mass_contact_nodecc_d', 1) ? '' : 'not')),
        );
      }
    }
    // If not, then do it or not based on the administrative setting.
    else {
      $form['nodecc'] = array(
        '#type' => 'hidden',
        '#default_value' => variable_get('mass_contact_nodecc_d', 1),
      );
      $form['nodecc_notice'] = array(
        '#type' => 'item',
        '#title' => t('Archive a copy of this message on this website'),
        '#markup' => t('A copy of this message will !not be archived on this website.', array('!not' => variable_get('mass_contact_nodecc_d', 1) ? '' : 'not')),
      );
    }

    // Add the submit button.
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Send email'),
    );
  }
  else {
    $form['error'] = array(
      '#markup' => '<p><b>' . t('Either you have not created any categories, or you are not allowed to send to any of the existing categories.') . '<br /><br />' . t('Either create at least one category of users to send to, or contact your system administer for access to the existing categories.') . '</b>',
    );
  }

  if (user_access('mass contact administer')) {
    $form['tasklist'] = array(
      '#type' => 'fieldset',
      '#title' => t('Related tasks'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#prefix' => '<p>',
    );
    $form['tasklist']['list'] = array(
      '#markup' => '<p><ol>' .
      '<li>' . l(t('Set Permissions'), 'admin/people/permissions', array('fragment' => 'module-mass_contact')) . '</li>' .
      '<li>' . l(t('List current categories'), 'admin/config/system/mass_contact') . '</li>' .
      '<li>' . l(t('Add new category'), 'admin/config/system/mass_contact/add') . '</li>' .
      '<li>' . l(t('Configure the module'), 'admin/config/system/mass_contact/settings') . '</li>' .
      '<li>' . l(t('Help'), 'admin/help/mass_contact') . '</li></ol>',
    );
  }

  return $form;
}


/**
 * Validates the main Mass Contact mail form.
 *
 * @param array $form
 *   An associative array containing the structure of the form.
 * @param array $form_state
 *   A keyed array containing the current state of the form.
 */
function mass_contact_mail_page_validate($form, &$form_state) {
  if (!$form_state['values']['cid']) {
    form_set_error('category', t('You must select a valid category.'));
  }

  if (user_access('mass contact change default sender information') == 1 && !valid_email_address($form_state['values']['mail'])) {
    form_set_error('mass_contact', t('You must enter a valid email address.'));
  }
}


/**
 * Processes the main Mass Contact mail form.
 *
 * @param array $form
 *   An associative array containing the structure of the form.
 * @param array $form_state
 *   A keyed array containing the current state of the form.
 */
function mass_contact_mail_page_submit($form, &$form_state) {
  $send_error = 0;
  $recipient_lists = array();
  $empty_lists = 0;

  // Set wether the recipients will be BCC or not.
  $bcc = variable_get('mass_contact_bcc_d', 1);
  if (user_access('mass contact override bcc')) {
    $bcc = $form_state['values']['bcc'];
  }

  // Set whether a copy will be archived as a node.
  $nodecc = variable_get('mass_contact_nodecc_d', 1);
  if (user_access('mass contact archive messages') && user_access('mass contact override archiving')) {
    // Only set $nodecc if the user is allowed to archive messages AND
    // override the archive setting.
    $nodecc = $form_state['values']['nodecc'];
  }

  // Set the input filter format.
  $format = _mass_contact_compute_default_filter_format();
  if (user_access('mass contact override text format')) {
    // Allow the form data to determine the message format, if the user has the
    // appropriate permissions.
    if (is_array($form_state['values']['message'])) {
      $format = $form_state['values']['message']['format'];
    }
    else {
      $format = $form_state['values']['body_filter_format']->format;
    }
  }

  // Process some parts of the message header (more will be processed later).
  $params = _mass_contact_prepare_header($form_state['values'], $format);

  // Get the admin specified default sender's name.
  $from_name = variable_get('mass_contact_default_sender_name');
  // Get the admin specified default sender's email address.
  $from_email = variable_get('mass_contact_default_sender_email');

  // Set the sender name and email address.
  if (empty($from_name) || empty($from_email) || user_access('mass contact change default sender information')) {
    // Either the admin has not specified a default name and email address or
    // the user is allowed to change them, so we check the form for submitted
    // values.
    if (isset($form_state['values']['name']) && !empty($form_state['values']['name'])) {
      $from_name = $form_state['values']['name'];
    }
    if (isset($form_state['values']['mail']) && !empty($form_state['values']['mail'])) {
      $from_email = $form_state['values']['mail'];
    }
  }

  // Format the sender name and email address.
  if (variable_get('mass_contact_include_from_name', 0) == 1 && !empty($from_name)) {
    $from_address = '"' . $from_name . '" <' . $from_email . '>';
  }
  else {
    $from_address = $from_email;
  }

  // Process the message body.
  $params['body'] = _mass_contact_prepare_bodies($form_state['values'], $format);

  // If there are attachments, and the user is allowed, add them.
  if (user_access('mass contact include attachments')) {
    if (module_exists('mimemail')) {
      for ($i = 1; $i <= variable_get('mass_contact_number_of_attachments', '3'); $i++) {
        if (!empty($_FILES['files']['size']['attachment_' . $i])) {
          $params['attachments'] = _mass_contact_process_mime_mail_attachments($nodecc);
          break;
        }
      }
    }
  }

  // Process the recipients (some more of the message header).
  // Get the IDs of the chosen categories.
  $cids = array();
  foreach ($form_state['values']['cid'] as $cid) {
    $cids[] = $cid;
  }

  // Get the category objects, based on the IDs, and save them into an array
  // for later use.
  $results = db_query("SELECT * FROM {mass_contact} WHERE cid IN(:cids)", array(':cids' => $cids));
  foreach ($results as $category) {
    $permission  = 'mass contact send to users in the ';
    $permission .= $category->category;
    $permission .= ' category';
    if (user_access($permission)) {
      // Only allow categories the user has permission to send to.
      $categories[] = $category;
    }
  }

  // Create the recipient lists, based on category.
  foreach ($categories as $category) {
    // Create the recipient lists, per category.
    $recipient_lists[$category->category] = array(
      // Set the recipients.
      'recipients' => _mass_contact_create_recipient_list($category, $form_state['values']['optout']),
      // Set the subject.
      'subject' => t('[@category] !subject', array('@category' => $category->category, '!subject' => filter_xss($form_state['values']['subject']))),
    );
  }

  // Iterate through each recipient list to verify there are recipients
  // somewhere.
  if (!empty($recipient_lists)) {
    foreach ($recipient_lists as $recipient_list) {
      // Check for empty recipient list.
      if (count($recipient_list['recipients']) == 0) {
        $empty_lists++;
      }
    }
  }

  // There are categories selected, but all of them are empty.
  if (count($recipient_lists) == $empty_lists) {
    // Post a message to the user and exit.
    drupal_set_message(t('No users were in the selected category(ies), and therefore, the message was not sent.'));
  }
  // We have recipients, so send the message to them.
  else {
    // Initialize more variables.
    // The count of all email addresses the message is sent to.
    $total_recipients = 0;
    // An array of all categories and email addresses thie message is sent to.
    $all_recipients = array();

    // If the module is configured to not include the category in the subject,
    // combine all users in all categories into a single listing of recpients.
    if (!variable_get('mass_contact_category_override', 1)) {
      $new_recipient_list = array('All categories combined' => array());

      // Cycle through all the categories adding all the recipients to the one
      // list.
      foreach ($recipient_lists as $category) {
        if (!empty($new_recipient_list['All categories combined']['recipients'])) {
          $new_recipient_list['All categories combined']['recipients'] = array_merge($new_recipient_list['All categories combined']['recipients'], $category['recipients']);
        }
        else {
          $new_recipient_list['All categories combined']['recipients'] = $category['recipients'];
        }
      }

      // Add the subject.
      $new_recipient_list['All categories combined']['subject'] = filter_xss($form_state['values']['subject'], array());

      // Set the original list to the new combined, unduplicated list.
      $new_recipient_list['All categories combined']['recipients'] = array_unique($new_recipient_list['All categories combined']['recipients']);
      $recipient_lists = $new_recipient_list;
    }

    // Capture the rate limiting information.
    $recipient_limit = variable_get('mass_contact_recipient_limit', 0);
    $send_with_cron = variable_get('mass_contact_send_with_cron', 0);

    // Iterate through each recipient list.
    foreach ($recipient_lists as $category => $recipient_list) {
      // Only process this recipient list if it is not empty.
      if (count($recipient_list['recipients']) > 0) {
        if (count($recipient_list['recipients']) > $recipient_limit && $recipient_limit != 0) {
          // Initialize still more variables.
          // The count of current recipients.
          $recipient_count = 0;
          // The batch count.
          $batch = 0;
          // An array of the current grouping of categories and email addresses
          // the message is sent to.
          $current_recipients = array();

          foreach ($recipient_list['recipients'] as $recipient_name => $recipient_address) {
            if (variable_get('mass_contact_include_to_name', 0) == 1) {
              $current_recipients[] = '"' . $recipient_name . '" <' . $recipient_address . '>';
              $partial_list[] = '"' . $recipient_name . '" <' . $recipient_address . '>';
            }
            else {
              $current_recipients[] = $recipient_address;
              $partial_list[] = $recipient_address;
            }

            $recipient_count = count($partial_list);

            if ($recipient_count == $recipient_limit) {
              // Increment the batch count.
              ++$batch;

              // Finalizes the headers, by setting the To, Subject, and
              // possibly, Bcc fields.
              $to = _mass_contact_finalize_headers($bcc, implode(', ', $partial_list), $params, $from_address, $recipient_list['subject']);

              if (empty($send_with_cron)) {
                // Send the message. Save the inverse of the result for tallying.
                $send_error += !(_mass_contact_send_message('mail_page_' . $batch, $to, $params, $from_address, '[Success] Sent batch #' . $batch . '.'));
              }
              else {
                // Create the queue.
                $queue = new SystemQueue('mass_contact');

                // Create the queue item.
                $message = array(
                  'message_key' => 'mail_page_' . $batch,
                  'to' => $to,
                  'params' => $params,
                  'from_email' => $from_address,
                  'success_message' => '[Success] Sent batch #' . $batch . '.',
                );

                // Add the item to the queue.
                $queue->createItem($message);
              }

              // Reset the variables.
              $partial_list = array();
              $recipient_count = 0;
            }
          }

          // Send the remainder.
          if ($recipient_count != 0) {
            // Finalizes the headers, by setting the To, Subject, and possibly,
            // Bcc fields.
            $to = _mass_contact_finalize_headers($bcc, implode(', ', $partial_list), $params, $from_address, $recipient_list['subject']);

            if (empty($send_with_cron)) {
              // Send the message. Save the inverse of the result for tallying.
              $send_error += !(_mass_contact_send_message('mail_page_last', $to, $params, $from_address, '[Success] Sent the remainder.'));
            }
            else {
              // Create the queue.
              $queue = new SystemQueue('mass_contact');

              // Create the queue item.
              $message = array(
                'message_key' => 'mail_page_last',
                'to' => $to,
                'params' => $params,
                'from_email' => $from_address,
                'success_message' => '[Success] Sent the remainder.',
              );

              // Add the item to the queue.
              $queue->createItem($message);
            }
          }

          $total_recipients = count($current_recipients);
          $listed_recipients = implode(', ', $current_recipients);
          $all_recipients = array_merge($all_recipients, $current_recipients);
        }
        // There's no recipient limit, so send the message to all the recipients
        // at the same time.
        else {
          // An array of the current grouping of categories and email addresses
          // the message is being sent to.
          $current_recipients = array();

          foreach ($recipient_list['recipients'] as $recipient_name => $recipient_address) {
            if (variable_get('mass_contact_include_to_name', 0) == 1) {
              $current_recipients[] = '"' . $recipient_name . '" <' . $recipient_address . '>';
            }
            else {
              $current_recipients[] = $recipient_address;
            }
          }

          $total_recipients = count($current_recipients);
          $listed_recipients = implode(', ', $current_recipients);
          $all_recipients = array_merge($all_recipients, $current_recipients);

          // Finalizes the headers, by setting the To, Subject, and possibly,
          // Bcc fields.
          $to = _mass_contact_finalize_headers($bcc, implode(', ', $current_recipients), $params, $from_address, $recipient_list['subject']);

          // Send the message. Save the inverse of the result for tallying.
          $send_error += !(_mass_contact_send_message('mail_page', $to, $params, $from_address, '[Success] Sent all at once.'));
        }

        // Archive the message as a node.
        if ($nodecc) {
          _mass_contact_save_node($params, $format, $from_address, $category, $to, !$send_error);
        }
      }
    }

    // If there were no errors, do the final operations.
    if (!$send_error) {
      // If the sender requested a copy, send it.
      if (!empty($form_state['values']['copy']) && !$bcc) {
        if (empty($recipient_limit) && empty($send_with_cron)) {
          if (!_mass_contact_send_message('user-copy', $from_address, $params, $from_address, 'A copy was sent to you.')) {
            // There was an error, so inform the user.
            if (!module_exists('help')) {
              drupal_set_message(t("A copy could not be sent to you. Check the logs for error messages. For more information, see the Troubleshooting secion of Mass Contact's !help page or README.txt.", array('!help' => l(t('help'), 'admin/help/mass_contact'))));
            }
            else {
              drupal_set_message(t("A copy could not be sent to you. Check the logs for error messages. For more information, see the Troubleshooting secion of Mass Contact's README.txt."));
            }
          }
        }
        else {
          // Create the queue.
          $queue = new SystemQueue('mass_contact');

          // Create the queue item.
          $message = array(
            'message_key' => 'user-copy',
            'to' => $from_address,
            'params' => $params,
            'from_email' => $from_address,
            'success_message' => 'A copy was sent to you.',
          );

          // Add the item to the queue.
          $queue->createItem($message);
        }
      }

      // Register this message send to the flood control mechanism.
      flood_register_event('mass_contact');

      // Log the operation.
      watchdog('mass_contact', '%name-from sent a message to the %category group, which included these recipients: @emails.',
        array(
          '%name-from' => $from_address,
          '%category' => $category,
          '@emails' => $listed_recipients,
        )
      );

      // Prepare some variables for the printing of the final results.
      $total_recipients = count($all_recipients);
      $unique_addresses_count = count(array_unique($all_recipients));
      $listed_recipients = implode(', ', $all_recipients);

      // Print out the final results of the complete operation.
      if ($total_recipients == $unique_addresses_count) {
        drupal_set_message(t('Your message was successfully sent to a total of @total email addresses.', array('@total' => $total_recipients)));
      }
      else {
        drupal_set_message(t('Your message was successfully sent to a total of @total email addresses, of which, there may have been !dups duplicates.',
          array(
            '@total' => $total_recipients,
            '!dups' => $total_recipients - $unique_addresses_count,
          )
        ));
      }
    }
    else {
      // Otherwise, inform the user that there were error(s).
      if (module_exists('help')) {
        drupal_set_message(t("@errors error(s) were encountered sending the message. Check the logs for error messages. For more information, see the Troubleshooting section of Mass Contact's !help page or README.txt.",
          array(
            '@errors' => $send_error,
            '!help' => l(t('help'), 'admin/help/mass_contact'),
          )
        ));
      }
      else {
        drupal_set_message(t("@errors error(s) were encountered sending the message. Check the logs for error messages. For more information, see the Troubleshooting section of Mass Contact's README.txt.", array('@errors' => $send_error)));
      }
    }
  }

  // Redirect to the home page, rather than back to the mail page, to avoid
  // contradictory messages if flood control has been activated.
  $form_state['redirect'] = '/';
}


/**
 * Figures out the default filter format for the current user.
 *
 * @return string
 *   Either the user's selected format, the admin-specified one, or the
 *   system default depending on which of those the user is allowed to use.
 */
function _mass_contact_compute_default_filter_format() {
  global $user;

  $user_default = filter_default_format($user);
  $specified_filter_format = variable_get('mass_contact_html_format', $user_default);

  // The admin has not specified one, there wouldn't be a match for the
  // default.
  if (!empty($specified_filter_format)) {
    // Get all the text formats the user is allowed access to.
    $filter_formats = filter_formats($user);
    // Cycle through the list of possible text formats.
    foreach ($filter_formats as $filter_format) {
      // If the current filter format matches the admin specified one, use it.
      if ((!empty($specified_filter_format['format']) && $filter_format->format == $specified_filter_format['format']) ||
        (!empty($specified_filter_format) && $filter_format->format == $specified_filter_format)) {
        return $filter_format->format;
      }
    }
  }

  // If nothing was selected above, set the default to the Drupal system
  // default.
  return filter_fallback_format();
}


/**
 * Prepares the message's header.
 *
 * This currently only sets the character set, but it's left here for potential
 * future additions.
 *
 * @param array $form_values
 *   The values returned from the message sending form.
 *
 * @return array
 *   The prepared header.
 */
function _mass_contact_prepare_header($form_values, $format) {
  $params = array();

//  if (!empty($form_values['message']['format']) && $form_values['message']['format'] == 'plain_text') {
  if (!empty($format) && $format == 'plain_text') {
    $params['headers']['Content-Type'] = 'text/plain; charset=' . variable_get('mass_contact_character_set', 'UTF-8') . '; format=flowed';
  }
  elseif (module_exists('mimemail')) {
    // Mime Mail requires this header or it will filter all text.
    $params['headers']['Content-Type'] = 'text/html; charset=UTF-8';
  }
  else {
    $params['headers']['Content-Type'] = 'text/plain; charset=' . variable_get('mass_contact_character_set', 'UTF-8') . '; format=flowed';
  }

  return $params;
}


/**
 * Prepares the message's body.
 *
 * @param array $form_values
 *   The values returned from the message sending form.
 * @param string $format
 *   The input text format the message was created with.
 *
 * @return array
 *   The prepared body, including any possible addons.
 */
function _mass_contact_prepare_bodies($form_values, $format) {
  $body = array();

  if (!empty($format) && $format == 'plain_text') {
    // Start with the message prefix.
    $body[] = _mass_contact_prepare_message_addon('prefix', 'plain text');

    // Add in the actual message.
    if (is_array($form_values['message'])) {
      $body[] = wordwrap(check_plain($form_values['message']['value']));
    }
    else {
      $body[] = wordwrap(check_plain($form_values['message']));
    }

    // End with the message suffix.
    $body[] = _mass_contact_prepare_message_addon('suffix', 'plain text');
  }
  elseif (module_exists('mimemail')) {
    // Start with the message prefix.
    $body[] = _mass_contact_prepare_message_addon('prefix', 'html');

    global $language;
    // Add in the actual message.
    if (is_array($form_values['message'])) {
      $body[] = check_markup($form_values['message']['value'], $format, ($language) ? $language->language : LANGUAGE_NONE);
    }
    else {
      $body[] = check_markup($form_values['message'], $format, ($language) ? $language->language : LANGUAGE_NONE);
    }

    // End with the message suffix.
    $body[] = _mass_contact_prepare_message_addon('suffix', 'html');
  }
  // Mime Mail is not installed, so this message will be converted as plain
  // text.
  else {
    // Start with the message prefix.
    $body[] = _mass_contact_prepare_message_addon('prefix', 'converted');

    // Add in the actual message.
    if (is_array($form_values['message'])) {
      $body[] = wordwrap(check_plain($form_values['message']['value']));
    }
    else {
      $body[] = wordwrap(check_plain($form_values['message']));
    }

    // End with the message suffix.
    $body[] = _mass_contact_prepare_message_addon('suffix', 'converted');
  }

  return $body;
}


/**
 * Prepares a message addon (prefix or suffix).
 *
 * @param string $addon
 *   Specifies the addon part to process. There are two possible values:
 *   'prefix' and 'suffix'.
 * @param string $style
 *   Indicates how to process the addon. There are three possible values:
 *   - 'plain text': Indicates that the returned addon should be in plain text
 *     format.
 *   - 'html': Indicates that the returned addon should be in HTML format.
 *   - 'converted': Indicates that the returned addon is HTML but should be
 *     converted into plain text format.
 *
 * @return string
 *   The prepared message addon.
 */
function _mass_contact_prepare_message_addon($addon, $style) {
  $token_module_exists = module_exists('token');
  $message = '';

  switch ($addon) {
    case 'prefix':
      if ($token_module_exists) {
        $message_addon = variable_get('mass_contact_message_prefix', t('[current-user:name] has sent you a group email from [site:name].'));
      }
      else {
        $message_addon = variable_get('mass_contact_message_prefix', t('You were sent a group email from @site.', array('@site' => url(NULL, array('absolute' => TRUE)))));
      }
      break;

    case 'suffix':
      if ($token_module_exists) {
        $message_addon = variable_get('mass_contact_message_suffix', '');
      }
      else {
        $message_addon = variable_get('mass_contact_message_suffix', '');
      }
      break;
  }

  if (is_array($message_addon)) {
    $message_addon_text = $message_addon['value'];
  }
  else {
    $message_addon_text = $message_addon;
  }

  if (!empty($message_addon_text)) {
    switch ($style) {
      case 'plain text':
        if ($token_module_exists) {
          $message .= wordwrap(check_plain(token_replace($message_addon_text)));
        }
        else {
          $message .= wordwrap(check_plain($message_addon_text));
        }
        break;

      case 'html':
        global $language;
        if (is_array($message_addon)) {
          if ($token_module_exists) {
            $message .= check_markup(token_replace($message_addon_text), $message_addon['format'], ($language) ? $language->language : LANGUAGE_NONE);
          }
          else {
            $message .= check_markup($message_addon_text, $message_addon['format'], ($language) ? $language->language : LANGUAGE_NONE);
          }
        }
        else {
          if ($token_module_exists) {
            $message .= check_markup(token_replace($message_addon_text), filter_fallback_format(), ($language) ? $language->language : LANGUAGE_NONE);
          }
          else {
            $message .= check_markup($message_addon_text, filter_fallback_format(), ($language) ? $language->language : LANGUAGE_NONE);
          }
        }
        break;

      case 'converted':
        if ($token_module_exists) {
          $message .= drupal_html_to_text(token_replace($message_addon_text));
        }
        else {
          $message .= drupal_html_to_text($message_addon_text);
        }
        break;
    }
  }

  return $message;
}


/**
 * Processes attachments for use with Mime Mail.
 *
 * @param boolean $nodecc
 *   Identifies whether a copy of the message will be saved as a node.
 *
 * @return array
 *   The attachment information, as Mime Mail expects it.
 */
function _mass_contact_process_mime_mail_attachments($nodecc = FALSE) {
  $files = array();

  // Loop through each possible attachment.
  for ($i = 1; $i <= variable_get('mass_contact_number_of_attachments', '3'); $i++) {
    // Check to see if an attachment exists.
    if ($_FILES['files']['size']['attachment_' . $i] > 0) {
      // If the message is to be saved as a node, we need to save the
      // attachment now so that it is not lost later.
      if ($nodecc) {
        // The name in the global $_FILES array where the information about the
        // attachment is stored.
        $file_source = 'attachment_' . $i;
        $file_validators = array();
        // Get the directory where attachments are to be saved.
        $file_destination = 'public://' . variable_get('mass_contact_attachment_location');
        $file_replace = FILE_EXISTS_RENAME;

        // Check to see that the directory exists.
        if (!file_prepare_directory($file_destination)) {
          // It does not, so create the directoty.
          drupal_mkdir($file_destination);
        }

        // Save the file to the Mass Contact attachments directory.
        $file = file_save_upload($file_source, $file_validators, $file_destination, $file_replace);

        // Check to see if there was an error during the save.
        if ($file === FALSE) {
          // There was an error, so report it.
          $message = 'There was an error uploading the "!attachment" attachment.';
          $variables = array('!attachment' => $_FILES['files']['name']['attachment_' . $i]);

          drupal_set_message(t($message, $variables), 'error');
          watchdog('mass_contact', $message, $variables, WATCHDOG_ERROR);
        }
        elseif ($file === NULL) {
          // Nothing happened, so say so.
          $message = 'The "!attachment" attachment was not uploaded.';
          $variables = array('!attachment' => $_FILES['files']['name']['attachment_' . $i]);

          drupal_set_message(t($message, $variables), 'error');
          watchdog('mass_contact', $message, $variables, WATCHDOG_ERROR);
        }
        // The file was saved, so now the information needs to be added to the
        // database.
        else {
          // Set the status of the uploaded file so it stays around for a while.
          $file->status = FILE_STATUS_PERMANENT;

          // Save the file object to the database.
          $file = file_save($file);

          // Check the state to determine if there was an error or not.
          if (!$file) {
            // If there was an error, report it.
            $message = 'There was an error saving the file object for "!attachment" to the database.';
            $variables = array('!attachment' => $_FILES['files']['name']['attachment_' . $i]);

            drupal_set_message(t($message, $variables), 'error');
            watchdog('mass_contact', $message, $variables, WATCHDOG_ERROR);
          }
          else {
            // Add the file object to the files collection array.
            $files[] = $file;
          }
        }
      }
      // Save the files in a temporary location.
      else {
        $files[] = array(
          'filepath' => $_FILES['files']['tmp_name']['attachment_' . $i],
          'uri' => $_FILES['files']['tmp_name']['attachment_' . $i],
          'filename' => $_FILES['files']['name']['attachment_' . $i],
          'filemime' => $_FILES['files']['type']['attachment_' . $i],
        );
      }
    }
  }

  return $files;
}


/**
 * Creates a list of recipients.
 *
 * @param object $category
 *   The category of users the message is to.
 * @param boolean $respect_opt_outs
 *   The 'Respect user opt-outs' value from the message sending form.
 *
 * @return array
 *   Users' email addresses, keyed by their user name.
 */
function _mass_contact_create_recipient_list($category, $respect_opt_outs) {
  $recipient_list = array();
  $opt_out_setting = variable_get('mass_contact_optout_d', 0);

  // Create the recipient list.
  ctools_include('plugins');
  // Get the information about all plugins that implemnent this type of plugin.
  $plugins = ctools_get_plugins('mass_contact', 'grouping_method');
  $user_ids = array();
  $all_user_ids = array();
  foreach ($plugins as $plugin) {
    // Get the recipient list function name for this particular implementation.
    $function = ctools_plugin_get_function($plugin, 'mass_contact_recipients');
    if (!empty($function)) {
      // Call the plugin function to get the list of recipients.
      $user_ids = $function(unserialize($category->recipients));
      if (!empty($user_ids)) {
        // If there are recipients for this plugin, add them to the total.
        $all_user_ids = array_merge($all_user_ids, $user_ids);
      }
    }
  }

  if (empty($all_user_ids)) {
    return array();
  }

  // Eliminate duplicates.
  $uids = array_unique(array_values($all_user_ids));

  global $user;

  $query = "SELECT u.name, u.mail, u.data FROM {users} u WHERE uid IN (:uids) AND u.status <> 0";
  $results = db_query($query, array(':uids' => $uids));
  foreach ($results as $account) {
    $account_data = unserialize($account->data);

    // Check if this account is the current user. We don't include the user
    // unless requested, and then it's a separate mailing.
    if (empty($user->name) || ($account->name != $user->name)) {
      // Check to see if users may opt out of all mailings.
      if ($respect_opt_outs && $opt_out_setting == 1) {
        // Check to see if this account has opted out.
        if (empty($account_data['mass_contact_optout'])) {
          // Add the account info to the list.
          $recipient_list[$account->name] = $account->mail;
        }
      }
      // Check to see if users may opt out of selected categories.
      elseif ($respect_opt_outs && $opt_out_setting == 2) {
        // Specify the category ID to check.
        $optout_cid = 'mass_contact_optout_' . $category->cid;
        // Check to see if this account has opted out.
        if (empty($account_data[$optout_cid])) {
          // Add the account info to the list.
          $recipient_list[$account->name] = $account->mail;
        }
      }
      // Opt outs are not allowed and/or not being respected.
      else {
        // Add the account info to the list.
        $recipient_list[$account->name] = $account->mail;
      }
    }
  }

  return $recipient_list;
}


/**
 * Finalizes the headers, by setting the To, Subject, and possibly, Bcc fields.
 *
 * @param boolean $bcc
 *   Indicates whether the recipients are to be put into the To or Bcc field.
 *   TRUE indicates the Bcc field, and FALSE indicates the To field.
 * @param string $recipients
 *   The list of recipients, separated by a comma.
 * @param array &$params
 *   The message array.
 * @param string $from_email
 *   The message sender's email address.
 * @param string $subject
 *   The subject of the message.
 *
 * @return string
 *   The contents of the To field. If $bcc is TRUE, this will be $from_email.
 *   If it is FALSE, it will be $recipients.
 */
function _mass_contact_finalize_headers($bcc, $recipients, &$params, $from_email, $subject) {
  // If blind carbon copy (BCC) was selected, put the recipients in
  // the Bcc field.
  if ($bcc) {
    $params['headers']['Bcc'] = $recipients;
    $to = $from_email;
  }
  else {
    // Else, put the recipients in the To field.
    $to = $recipients;
  }

  $params['subject'] = $subject;

  return $to;
}


/**
 * Archive a copy of the sent message as a node.
 *
 * @param array $params
 *   The message array.
 * @param array $body
 *   The body of the message and node.
 * @param array $format
 *   The text format the body is to use.
 * @param string $from
 *   The email address representing who the message is from.
 * @param string $category
 *   The categories of users sent to.
 * @param string $recipients
 *   The users who received the message.
 * @param boolean $result
 *   The result of sending the message.
 */
function _mass_contact_save_node($params, $format, $from, $category, $recipients, $result) {
  // Create a new node object.
  $node = new stdClass();

  // Set the node type.
  $node->type = 'mass_contact';

  // Prepare the node object for editing and fill in a few default values.
  node_object_prepare($node);

  // Set the language code, if the Locale module is enabled.
  // global $language;
  // $node->language = ($language) ? $language->language : LANGUAGE_NONE;
  // The node data is not completely saved if $node->language is not set to
  // LANGUAGE_NONE.
  // @TODO: Find out if this is a bug in Drupal or not.
  $node->language = LANGUAGE_NONE;

  // Set the title of the node to the subject of the message.
  $node->title = $params['subject'];

  // Convert the body from an array to a string.
  $body = implode("\n\n", $params['body']);
  // Set the body of the node to the body of the message.
  $node->body[$node->language][0]['value'] = $body;
  // Set the teaser or summary of the body.
  $node->body[$node->language][0]['summary'] = text_summary($body);
  // Set the text format of the message body.
  $node->body[$node->language][0]['format'] = $format;

  // Set the From field.
  $node->field_mass_contact_from[$node->language][0]['value'] = $from;

  // Set the Category field.
  $node->field_mass_contact_category[$node->language][0]['value'] = $category;

  // Set the To field.
  $to = explode(',', $recipients);
  foreach ($to as $recipient) {
    $node->field_mass_contact_to[$node->language][]['value'] = $recipient;
  }

  // Set the BCC field.
  if (!empty($params['headers']['Bcc'])) {
    $to = explode(',', $params['headers']['Bcc']);
    foreach ($to as $recipient) {
      $node->field_mass_contact_bcc[$node->language][]['value'] = $recipient;
    }
  }

  // Set the Headers field.
  if (!empty($params['headers'])) {
    // Format the output so that it is readable.
    $headers = '';
    foreach ($params['headers'] as $header => $value) {
      $headers .= $header . ": " . $value . "\n";
    }

    // Set the body of the Headers.
    $node->field_mass_contact_headers[$node->language][0]['value'] = $headers;
    // Set the teaser or summary of the Headers.
    $node->field_mass_contact_headers[$node->language][0]['summary'] = text_summary($headers);
    // Set the text format of the Headers.
    $node->field_mass_contact_headers[$node->language][0]['format'] = 'plain_text';
  }

  // Set the Result field.
  // Set the body of the Result.
  $node->field_mass_contact_result[$node->language][0]['value'] = $result;
  // Set the teaser or summary of the Result.
  $node->field_mass_contact_result[$node->language][0]['summary'] = text_summary($result);
  // Set the text format of the Result.
  $node->field_mass_contact_result[$node->language][0]['format'] = 'plain_text';

  // If any attachments exist, add them.
  if (!empty($params['attachments'])) {
    foreach ($params['attachments'] as $attachment) {
      // Attach the attachment to the node.
      $node->field_mass_contact_attachments[$node->language][] = array(
        'fid' => $attachment->fid,
        'display' => 1,
        'dscription' => '',
        'uid' => $attachment->uid,
        'filename' => $attachment->filename,
        'uri' => $attachment->uri,
        'filemime' => $attachment->filemime,
        'filesize' => $attachment->filesize,
        'status' => $attachment->status,
        'timestamp' => $attachment->timestamp,
        'rdf_mapping' => array(),
      );
    }
  }

  // Save the node.
  node_save($node);

  // Log the node creation.
  watchdog('content', 'Mass Contact content added "%title".', array('%title' => $params['subject']), WATCHDOG_NOTICE, l(t('View'), 'node/' . $node->nid));

  // Inform the user.
  drupal_set_message(t('A copy has been created as a node.'));
}
