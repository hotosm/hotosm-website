<?php
/**
 * @file
 * Administration pages for mailchimp_campaign module.
 */

/**
 * Returns a form for creating a campaign.
 */
function mailchimp_campaign_campaign_form($form, &$form_state, MailChimpCampaign $campaign = NULL) {
  $path = drupal_get_path('module', 'mailchimp_campaign');
  drupal_add_js($path . '/js/mailchimp_campaign.utils.js', 'file');
  drupal_add_css($path . '/mailchimp_campaign.css', 'file');

  $form_state['campaign'] = $campaign;
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('An internal name to use for this campaign. By default, the campaign subject will be used.'),
    '#required' => FALSE,
    '#default_value' => ($campaign) ? $campaign->mc_data['title'] : '',
  );
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#required' => TRUE,
    '#default_value' => ($campaign) ? $campaign->mc_data['subject'] : '',
  );
  $mailchimp_lists = mailchimp_get_lists();
  $form['list_id'] = array(
    '#type' => 'select',
    '#title' => t('List'),
    '#description' => t('Select the list this campaign should be sent to.'),
    '#options' => _mailchimp_campaign_build_option_list($mailchimp_lists),
    '#default_value' => ($campaign) ? $campaign->mc_data['list_id'] : -1,
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'mailchimp_campaign_list_segment_callback',
      'method' => 'replace',
      'wrapper' => 'list-segments-wrapper',
    ),
  );

  if (!empty($form_state['values']['list_id'])) {
    $list_id = $form_state['values']['list_id'];
  }
  elseif ($campaign && $campaign->mc_data) {
    $list_id = $campaign->mc_data['list_id'];
    if (isset($campaign->mc_data['saved_segment']['id'])) {
      $segment_id = $campaign->mc_data['saved_segment']['id'];
    }
  }

  $list_segments = array();
  if (isset($list_id)) {
    $list_segments = mailchimp_campaign_get_list_segments($list_id, 'saved');
  }

  if (!empty($list_segments)) {
    $form['list_segment_id'] = array(
      '#type' => 'select',
      '#title' => t('List Segment'),
      '#description' => t('Select the list segment this campaign should be sent to.'),
      '#options' => _mailchimp_campaign_build_option_list($list_segments, '-- Entire list --'),
      '#default_value' => (isset($segment_id)) ? $segment_id : '',
    );
  }
  else {
    $form['list_segment_id'] = array();
  }
  $form['list_segment_id']['#prefix'] = '<div id="list-segments-wrapper">';
  $form['list_segment_id']['#suffix'] = '</div>';

  $form['from_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From Email'),
    '#description' => t('the From: email address for your campaign message.'),
    '#default_value' => ($campaign) ? $campaign->mc_data['from_email'] : variable_get('site_mail'),
    '#size' => 40,
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['from_name'] = array(
    '#type' => 'textfield',
    '#title' => t('From Name'),
    '#description' => t('the From: name for your campaign message (not an email address)'),
    '#default_value' => ($campaign) ? $campaign->mc_data['from_name'] : variable_get('site_name'),
    '#size' => 40,
    '#maxlength' => 255,
  );
  $template_type_labels = array(
    'user' => 'My Custom Templates',
    'basic' => 'Basic Templates',
    'gallery' => 'Themes',
  );
  $form['template_id'] = array(
    '#type' => 'select',
    '#title' => t('Template'),
    '#description' => t('Select a MailChimp user template to use. Due to a limitation in the API, only templates that do not contain repeating sections are available. If empty, the default template will be applied.'),
    '#options' => _mailchimp_campaign_build_option_list(mailchimp_campaign_list_templates(), '-- Select --', $template_type_labels),
    '#default_value' => ($campaign) ? $campaign->mc_data['template_id'] : -1,
    '#ajax' => array(
      'callback' => 'mailchimp_campaign_template_callback',
      'wrapper' => 'content-sections',
    ),
  );
  $form['content'] = array(
    '#id' => 'content-sections',
    '#type' => 'fieldset',
    '#title' => t('Content sections'),
    '#description' => t('The HTML content or, if a template is selected, the content for each section.'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $mc_template = NULL;
  if (!empty($form_state['values']['template_id'])) {
    $mc_template = mailchimp_campaign_get_template($form_state['values']['template_id']);
  }
  else {
    if (($campaign) && $campaign->mc_template) {
      $mc_template = $campaign->mc_template;
    }
  }

  if (isset($list_id)) {
    $merge_vars_list = mailchimp_get_mergevars(array($list_id));
    $merge_vars = $merge_vars_list[$list_id]['merge_vars'];
  }
  else {
    $merge_vars = array();
  }

  if ($mc_template) {
    if (strpos($mc_template['info']['source'], 'mc:repeatable')) {
      drupal_set_message(t('WARNING: This template has repeating sections, which are not supported. You may want to select a different template.'), 'warning');
    }
    foreach ($mc_template['info']['default_content'] as $section => $content) {
      // Set the default value and text format to either saved campaign values
      // or defaults coming from the MailChimp template.
      $default_value = $content;
      $format = 'mailchimp_campaign';
      if ($campaign && $campaign->template[$section]) {
        $default_value = $campaign->template[$section]['value'];
        $format = $campaign->template[$section]['format'];
      }
      $form['content'][$section . '_wrapper'] = array(
        '#type' => 'fieldset',
        '#title' => check_plain(drupal_ucfirst($section)),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['content'][$section . '_wrapper'][$section] = array(
        '#type' => 'text_format',
        '#format' => $format,
        '#title' => check_plain(drupal_ucfirst($section)),
        '#default_value' => $default_value,
      );

      $entity_type = isset($form_state['values']['content'][$section . '_wrapper']['entity_import']['entity_type']) ?
        $form_state['values']['content'][$section . '_wrapper']['entity_import']['entity_type'] : NULL;

      $form['content'][$section . '_wrapper'] += mailchimp_campaign_get_entity_import_form_elements($entity_type, $section);
      $form['content'][$section . '_wrapper'] += mailchimp_campaign_get_merge_vars_form_elements($merge_vars, $mailchimp_lists[$list_id]['name']);
    }
  }
  else {
    $section = 'html';

    $form['content']['html_wrapper'] = array(
      '#type' => 'fieldset',
      '#title' => t('Content'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['content']['html_wrapper']['html'] = array(
      '#type' => 'text_format',
      '#format' => ($campaign) ? $campaign->template['html']['format'] : 'mailchimp_campaign',
      '#title' => t('Content'),
      '#description' => t('The HTML content of the campaign.'),
      '#access' => empty($form_state['values']['template_id']),
      '#default_value' => ($campaign) ? $campaign->template['html']['value'] : '',
    );

    $entity_type = isset($form_state['values']['content'][$section . '_wrapper']['entity_import']['entity_type']) ?
      $form_state['values']['content'][$section . '_wrapper']['entity_import']['entity_type'] : NULL;

    $form['content'][$section . '_wrapper'] += mailchimp_campaign_get_entity_import_form_elements($entity_type, $section);

    $list_name = (!empty($list_id)) ? $mailchimp_lists[$list_id]['name'] : '';
    $form['content'][$section . '_wrapper'] += mailchimp_campaign_get_merge_vars_form_elements($merge_vars, $list_name);
  }

  // Message preview:
  if (isset($form_state['mailchimp_campaign_campaign_preview'])) {
    $form['preview_wrapper'] = array(
      '#title' => t('Campaign content preview'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['preview_wrapper']['preview'] = array(
      '#markup' => $form_state['mailchimp_campaign_campaign_preview'],
    );
  }

  $form['actions']['preview'] = array(
    '#type' => 'submit',
    '#value' => t('Preview content'),
    '#weight' => 10,
    '#submit' => array('mailchimp_campaign_campaign_preview'),
  );
  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save as draft'),
  );

  return $form;
}

/**
 * AJAX callback when changing template ID.
 */
function mailchimp_campaign_template_callback($form, $form_state) {
  return $form['content'];
}

/**
 * AJAX callback when changing list ID.
 */
function mailchimp_campaign_list_segment_callback($form, $form_state) {
  $commands = array();

  $list_segment_html = drupal_render($form['list_segment_id']);
  $commands[] = ajax_command_replace('#list-segments-wrapper', $list_segment_html);

  if (isset($form['content']['html_wrapper']['merge_vars'])) {
    $merge_vars_html = drupal_render($form['content']['html_wrapper']['merge_vars']);
    $commands[] = ajax_command_replace('.merge-vars-wrapper', $merge_vars_html);
  }

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Preview callback for mailchimp_campaign_campaign_form().
 */
function mailchimp_campaign_campaign_preview($form, &$form_state) {
  $text = '';
  $template_content = _mailchimp_campaign_parse_template_content($form_state['values']['content']);
  $content = mailchimp_campaign_render_template($template_content);
  foreach ($content as $key => $section) {
    $text .= "<h3>$key</h3>" . $section;
  }

  $form_state['mailchimp_campaign_campaign_preview'] = $text;
  $form_state['rebuild'] = TRUE;
}

/**
 * Validation callback for mailchimp_campaign_campaign_form().
 */
function mailchimp_campaign_campaign_form_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['from_email'])) {
    form_set_error('from_email', t('Please provide a valid From email address.'));
  }
}

/**
 * Submit handler for mailchimp_campaign_campaign_form().
 */
function mailchimp_campaign_campaign_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $options = array(
    'title' => $values['title'],
    'subject' => $values['subject'],
    'list_id' => $values['list_id'],
    'from_email' => $values['from_email'],
    'from_name' => check_plain($values['from_name']),
    'template_id' => $values['template_id'],
  );
  $segment_options = NULL;
  if (isset($values['list_segment_id']) && !empty($values['list_segment_id'])) {
    $segment_options = array(
      'saved_segment_id' => $values['list_segment_id'],
    );
  }

  $template_content = _mailchimp_campaign_parse_template_content($values['content']);

  $campaign_id = (isset($form_state['campaign']) ? $form_state['campaign']->mc_campaign_id : NULL);
  mailchimp_campaign_save_campaign($template_content, $options, $segment_options, $campaign_id);

  cache_clear_all('mailchimp_campaign_campaigns', 'cache');

  $form_state['redirect'][] = 'admin/config/services/mailchimp/campaigns';
}

/**
 * Gets form elements used in the entity import feature.
 *
 * @param string $entity_type
 *   The type of entity to import.
 * @param string $section
 *   The content section these fields are displayed in.
 *
 * @return array
 *   Array of form elements used to display entity imports.
 */
function mailchimp_campaign_get_entity_import_form_elements($entity_type, $section) {
  $form = array();

  // Get available entity types.
  $entity_info = _mailchimp_campaign_get_entities_for_content_import();
  $entity_options = _mailchimp_campaign_build_entity_option_list($entity_info);

  $form['entity_import'] = array(
    '#id' => 'entity-import',
    '#type' => 'fieldset',
    '#title' => t('Insert site content'),
    '#description' => t('<b>For use only with text filters that use the MailChimp Campaign filter</b><br />You can insert an entity of a given type and pick the view mode that will be rendered within this campaign section.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    // '#states' => array(
    //   'visible' => array(
    //     ':input[name="content[' . $section . '_wrapper][' . $section . '][format]"]' => array('value' => 'mailchimp_campaign'),
    //   ),
    // ),
  );

  $form['entity_import']['entity_type'] = array(
    '#type' => 'select',
    '#title' => t('Entity Type'),
    '#options' => $entity_options,
    '#default_value' => $entity_type,
    '#ajax' => array(
      'callback' => 'mailchimp_campaign_entity_type_callback',
      'wrapper' => $section . '-content-entity-lookup-wrapper',
    ),
  );
  $form['entity_import']['entity_type']['#attributes']['class'][] = $section . '-entity-import-entity-type';

  $form['entity_import']['entity_import_wrapper'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => $section . '-content-entity-lookup-wrapper',
    ),
  );

  if ($entity_type != NULL) {
    // Get available entity view modes.
    $entity_view_mode_options = _mailchimp_campaign_build_entity_view_mode_option_list($entity_info[$entity_type]);

    $form['entity_import']['entity_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Entity Title'),
      // Pass entity type as first parameter to autocomplete callback.
      '#autocomplete_path' => 'admin/config/services/mailchimp/campaigns/entities/' . $entity_type,
    );
    $form['entity_import']['entity_id']['#attributes']['id'] = $section . '-entity-import-entity-id';

    $form['entity_import']['entity_view_mode'] = array(
      '#type' => 'select',
      '#title' => t('View Mode'),
      '#options' => $entity_view_mode_options,
      '#attributes' => array(
        'id' => $section . '-entity-import-entity-view-mode',
      ),
    );
  }

  $form['entity_import']['entity_import_link'] = array(
    '#type' => 'item',
    '#markup' => '<a id="' . $section . '-add-entity-token-link" class="add-entity-token-link" href="javascript:void(0);">' . t('Insert entity token') . '</a>',
    '#states' => array(
      'invisible' => array(
        ':input[name="content[' . $section . '_wrapper][entity_import][entity_type]"]' => array('value' => ''),
      ),
    ),
  );

  $form['entity_import']['entity_import_tag'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => $section . '-entity-import-tag-field',
    ),
    '#states' => array(
      'invisible' => array(
        ':input[name="content[' . $section . '_wrapper][entity_import][entity_type]"]' => array('value' => ''),
      ),
    ),
  );

  return $form;
}

/**
 * Gets form elements used in the merge vars feature.
 *
 * @param array $merge_vars
 *   Array of MailChimp merge vars for the current list.
 * @see mailchimp_get_mergevars
 * @param string $list_name
 *   The name of the current list.
 *
 * @return array
 *   Array of form elements used to display merge vars.
 */
function mailchimp_campaign_get_merge_vars_form_elements($merge_vars, $list_name) {
  $form = array();

  $form['merge_vars'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'merge-vars-wrapper'
      ),
    ),
  );

  $form['merge_vars']['content'] = array(
    '#type' => 'item',
    '#title' => t('MailChimp merge variables'),
    '#markup' => _mailchimp_campaign_build_merge_vars_html($merge_vars),
    '#description' => t(
      'Insert merge variables from the %list_name list or one of the !standard_link.',
      array(
        '%list_name' => $list_name,
        '!standard_link' => l(
          t('standard MailChimp merge variables'), 'http://kb.mailchimp.com/article/all-the-merge-tags-cheatsheet',
          array('attributes' => array('target' => '_blank'))),
      )
    ),
  );

  return $form;
}

/**
 * AJAX callback when changing entity type.
 */
function mailchimp_campaign_entity_type_callback($form, $form_state) {
  $commands = array();

  $content_wrapper = $form_state['triggering_element']['#parents'][1];
  $entity_import_wrapper = $form_state['triggering_element']['#ajax']['wrapper'];

  $html = '<div id="' . $entity_import_wrapper . '" class="content-entity-lookup-wrapper">';
  $html .= drupal_render($form['content'][$content_wrapper]['entity_import']['entity_id']);
  $html .= drupal_render($form['content'][$content_wrapper]['entity_import']['entity_view_mode']);
  $html .= '</div>';

  $commands[] = ajax_command_replace('#' . $entity_import_wrapper, $html);
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Returns an options list for a given array of items.
 *
 * @param array $list
 *   Array of item data containing 'id' and 'name' properties.
 * @param string $no_selection_label
 *   The option value to display when no option is selected.
 * @param array $labels
 *   Optional associative array of list indexes to custom labels.
 *
 * @return array
 *   Associative array of item IDs to name.
 */
function _mailchimp_campaign_build_option_list($list, $no_selection_label = '-- Select --', $labels = array()) {
  $options = array();
  if ($no_selection_label) {
    $options[''] = $no_selection_label;
  }
  foreach ($list as $index => $item) {
    if (!isset($item['id'])) {
      $label = isset($labels[$index]) ? $labels[$index] : $index;
      if (count($item)) {
        $options[$label] = _mailchimp_campaign_build_option_list($item, FALSE, $labels);
      }
    }
    else {
      $options[$item['id']] = $item['name'];
    }
  }

  return $options;
}

/**
 * Returns an array of entities based on data from entity_get_info().
 *
 * Filters out entities that do not contain a title field, as they cannot
 * be used to import content into templates.
 *
 * @return array
 *   Filtered entities from entity_get_info().
 */
function _mailchimp_campaign_get_entities_for_content_import() {
  $entity_info = entity_get_info();

  foreach ($entity_info as $key => $entity) {
    if (in_array('title', $entity['schema_fields_sql']['base table'])) {
      $filtered_entities[$key] = $entity;
    }
  }

  return $filtered_entities;
}

/**
 * Returns an options list of entities based on data from entity_get_info().
 *
 * Filters out entities that do not contain a title field, as they cannot
 * be used to import content into templates.
 *
 * @param array $entity_info
 *   Array of entities as returned by entity_get_info().
 *
 * @return array
 *   Associative array of entity IDs to name.
 */
function _mailchimp_campaign_build_entity_option_list($entity_info) {
  $options = array(
    '' => t('-- Select --'),
  );
  foreach ($entity_info as $entity_id => $entity_data) {
    // Exclude MailChimp entities.
    if (strpos($entity_id, 'mailchimp') === FALSE) {
      $options[$entity_id] = $entity_data['label'];
    }
  }

  return $options;
}

/**
 * Returns an options list of entity view modes.
 *
 * @param array $entity
 *   Array of entity data as returned by entity_get_info().
 *
 * @return array
 *   Associative array of view mode IDs to name.
 */
function _mailchimp_campaign_build_entity_view_mode_option_list(array $entity) {
  $options = array();
  foreach ($entity['view modes'] as $view_mode_id => $view_mode_data) {
    $options[$view_mode_id] = $view_mode_data['label'];
  }

  return $options;
}

/**
 * Builds a HTML string used to render merge vars on the campaign form.
 *
 * @param array $merge_vars
 *   Array of merge vars. @see mailchimp_lists_get_merge_vars
 *
 * @return string
 *   HTML string containing formatted merge vars.
 */
function _mailchimp_campaign_build_merge_vars_html($merge_vars) {
  if (!empty($merge_vars)) {
    $rows = array();
    foreach ($merge_vars as $var) {
      $rows[] = array(
        $var['name'],
        '<a id="merge-var-' . $var['tag'] . '" class="add-merge-var" href="javascript:void(0);">*|' . $var['tag'] . '|*</a>',
      );
    }
    $table = theme('table', array('rows' => $rows));
    return render($table);
  }
  else {
    return t('No custom merge vars exist for the current list.');
  }
}

/**
 * Parses template content to remove wrapper elements from tree.
 *
 * @param array $content
 *   The template content array.
 *
 * @return array
 *   The template content array minus wrapper elements.
 */
function _mailchimp_campaign_parse_template_content($content) {
  $template_content = array();
  $content_keys = array_keys($content);
  foreach ($content_keys as $content_key) {
    if (strpos($content_key, '_wrapper') !== FALSE) {
      // If this element is a wrapper, add the element contained
      // within the wrapper to the template content.
      $new_content_key = str_replace('_wrapper', '', $content_key);
      $template_content[$new_content_key] = $content[$content_key][$new_content_key];
    }
    else {
      // If this element is not a wrapper, add it to the template content.
      $template_content[$content_key] = $content[$content_key];
    }
  }
  return $template_content;
}

/**
 * List deletion form.
 */
function mailchimp_campaign_delete_form($form, &$form_state, MailChimpCampaign $campaign) {
  $form_state['campaign'] = $campaign;
  return confirm_form($form,
    t('Are you sure you want to delete %name?', array('%name' => $campaign->label())),
    'admin/config/services/mailchimp/campaigns/' . $campaign->mc_campaign_id,
    t('This action will delete both the MailChimp campaign and Drupal entity and cannot be undone.'),
    t('Delete campaign')
  );
}

/**
 * Submit handler for mailchimp_campaign_delete_list_form().
 */
function mailchimp_campaign_delete_form_submit($form, &$form_state) {
  $campaign = $form_state['campaign'];
  if (mailchimp_campaign_delete_campaign($campaign->mc_campaign_id)) {
    drupal_set_message(t('Campaign %name has been deleted.',
        array('%name' => $campaign->label()))
    );
  }
  drupal_goto('admin/config/services/mailchimp/campaigns');
}

/**
 * List deletion form.
 */
function mailchimp_campaign_send_form($form, &$form_state, MailChimpCampaign $campaign) {
  $form_state['campaign'] = $campaign;
  return confirm_form($form,
    t('Are you sure you want to send %name?', array('%name' => $campaign->label())),
    'admin/config/services/mailchimp/campaigns/' . $campaign->mc_campaign_id,
    t('This action will send the campaign through MailChimp and cannot be undone.'),
    t('Send campaign')
  );
}

/**
 * Submit handler for mailchimp_campaign_delete_list_form().
 */
function mailchimp_campaign_send_form_submit($form, &$form_state) {
  $campaign = $form_state['campaign'];
  mailchimp_campaign_send_campaign($campaign);
  drupal_set_message(t('Campaign %name has been sent.',
      array('%name' => $campaign->label()))
  );
  drupal_goto('admin/config/services/mailchimp/campaigns');
}

/**
 * Send test campaign form.
 */
function mailchimp_campaign_send_test_form($form, &$form_state, MailChimpCampaign $campaign) {
  $form_state['campaign'] = $campaign;

  $form['recipients'] = array(
    '#type' => 'textfield',
    '#title' => t('Test recipients'),
    '#size' => 100,
    '#default_value' => isset($_SESSION['mailchimp_campaign_test']) ? $_SESSION['mailchimp_campaign_test'] : '',
    '#description' => t('Enter one or more e-mail addresses separated by commas.'),
  );

  return confirm_form($form,
    t('Confirm test for %name?', array('%name' => $campaign->label())),
    'admin/config/services/mailchimp/campaigns/' . $campaign->mc_campaign_id,
    t('This action will send a test message through MailChimp to the recipients specified above.'),
    t('Send test')
  );
}

/**
 * Submit handler for mailchimp_campaign_send_test_form().
 */
function mailchimp_campaign_send_test_form_submit($form, &$form_state) {
  $campaign = $form_state['campaign'];
  $recipients = explode(',', $form_state['values']['recipients']);
  $recipients = array_map('trim', $recipients);

  mailchimp_campaign_send_test_campaign($campaign, $recipients);
  $_SESSION['mailchimp_campaign_test'] = implode(', ', $recipients);

  drupal_set_message(t('Campaign %name test message sent.',
      array('%name' => $campaign->label()))
  );
  drupal_goto('admin/config/services/mailchimp/campaigns/' . $campaign->mc_campaign_id);
}
