<?php

/**
 * @file
 * mailchimp_lists module admin settings.
 */

/**
 * Administrative display showing existing lists and allowing edits/adds.
 */
function mailchimp_lists_overview_page() {
  $mc_lists = mailchimp_get_lists();
  $rows = array();
  $webhook_url = mailchimp_webhook_url();
  foreach ($mc_lists as $mc_list) {
    $webhooks = mailchimp_webhook_get($mc_list['id']);
    $enabled = FALSE;
    if ($webhooks) {
      foreach ($webhooks as $webhook) {
        if ($webhook_url == $webhook['url']) {
          $enabled = TRUE;
          continue;
        }
      }
    }
    if ($enabled) {
      // This is a webhook for this MailChimp Module.
      $webhook_status = t('ENABLED') . '(' . l(t('disable'), 'admin/config/services/mailchimp/lists/' . $mc_list['id'] . '/webhook/disable') . ')';
    }
    else {
      $webhook_status = t('disabled') . ' (' . l(t('enable'), 'admin/config/services/mailchimp/lists/' . $mc_list['id'] . '/webhook/enable') . ')';
    }
    $rows[] = array(
      l($mc_list['name'], 'https://admin.mailchimp.com/lists/dashboard/overview?id=' . $mc_list['web_id']),
      $mc_list['stats']['member_count'],
      $webhook_status,
    );

  }
  $table = array(
    'header' => array(
      t('Name'),
      t('Members'),
      t('Webhook Status'),
    ),
    'rows' => $rows,
  );
  $refresh_link = l(t('Refresh lists from MailChimp'),
    'admin/config/services/mailchimp/list_cache_clear',
    array('query' => array('destination' => 'admin/config/services/mailchimp/lists')));
  if (empty($mc_lists)) {
    $table['caption'] = $refresh_link;
    drupal_set_message(t('You don\'t have any lists configured in your MailChimp account, (or you haven\'t configured your API key correctly on the Global Settings tab). Head over to !link and create some lists, then come back here and click "Refresh lists from MailChimp"',
      array('!link' => l(t('MailChimp'), 'https://admin.mailchimp.com/lists/'))), 'warning');
  }
  else {
    $options = t('Currently Available MailChimp lists').':<i>';
    foreach ($mc_lists as $mc_list) {
      $options .= ' ' . $mc_list['name'] . ',';
    }
    $options = rtrim($options, ',');
    $options .= ".</i><br />" . $refresh_link;
    $table['caption'] = $options;
  }

  return theme('table', $table);
}

/**
 * Administrative display showing existing lists and allowing edits/adds.
 */
function mailchimp_lists_fields_overview_page() {
  $fields = field_info_fields();
  $rows = array();
  foreach ($fields as $field) {
    if ($field['type'] == 'mailchimp_lists_subscription') {
      foreach ($field['bundles'] as $entity_type => $bundles) {
        foreach ($bundles as $bundle) {
          $link = 'admin/config/services/mailchimp/lists/update_mergevars/' . $entity_type . '/' . $bundle . '/' . $field['field_name'];
          $rows[] = array(
            $entity_type,
            $bundle,
            $field['field_name'],
            l(t('Update MailChimp Mergevar Values'), $link),
          );
        }
      }
    }
  }
  $table = array(
    'header' => array(
      t('Entity Type'),
      t('Bundle'),
      t('Field'),
      t('Batch Update'),
    ),
    'rows' => $rows,
  );

  $table['caption'] = t("This displays a list of all MailChimp Subscription Fields configured on your system, with a row for each unique Instance of that field.
    To edit each field's settings, go to the Entity Bundle's configuration screen and use the Field UI.
    When entities with MailChimp Subscription Fields are updated, the Merge Variables configured through Field UI are automatically updated if necessary.
    However, if you have existing subscribers on MailChimp and matching Entities on Drupal when you configure your Merge Variables, the existing values are not synced automatically,
    as this could be a slow process. You can manually force updates of all existing Merge Values to existing MailChimp subscribers for each field configuration using the 'Batch Update'
    option on this table. The MailChimp Subscription Field is provided by the MailChimp Lists (mailchimp_lists) module.<br/><br/>
    The following MailChimp Subscription Field instances were found:");

  return theme('table', $table);
}

/**
 * Webhooks Toggle form.
 */
function mailchimp_lists_webhook_form($form, &$form_state, $list_id, $action) {
  $list = mailchimp_get_list($list_id);
  $form_state['list'] = $list;
  $form_state['action'] = $action;
  if ($list) {
    switch ($action) {
      case "enable":
        break;

      case "disable":
        break;

      default:
        return array();
    }
    $label = t($action) . " webhooks";
    return confirm_form($form,
      t('Are you sure you want to &action webhooks for %name?',
        array(
          '&action' => t($action),
          '%name' => $list['name'],
        )),
      'admin/config/services/mailchimp/lists',
      t('You can change this setting back from the mailchimp administrative UI.'),
      $label
    );
  }
  return array();
}

/**
 * Submit handler for mailchimp_lists_webhook_form().
 */
function mailchimp_lists_webhook_form_submit($form, &$form_state) {
  $list_id = $form_state['list']['id'];
  switch ($form_state['action']) {
    case 'enable':
      $result = mailchimp_webhook_add(
        $list_id,
        mailchimp_webhook_url(),
        array('unsubscribe', 'profile', 'cleaned', 'upemail')
      );
      break;

    case 'disable':
      $result = mailchimp_webhook_delete(
        $list_id,
        mailchimp_webhook_url()
      );
      break;

    default:
      $result = FALSE;
      break;

  }
  if ($result) {
    drupal_set_message(t('Webhooks for list "%name" have been %action.',
      array(
        '%name' => $form_state['list']['name'],
        '%action' => $form_state['action'] . 'd',
      )
    ));
  }
  else {
    drupal_set_message(t('Unable to perform webhook action "%action" for list "%name".',
      array(
        '%name' => $form_state['list']['name'],
        '%action' => $form_state['action'],
      )
    ), 'warning');

  }
  $form_state['redirect'] = 'admin/config/services/mailchimp/lists';
}


/**
 * Update Mergevars Form.
 */
function mailchimp_lists_update_mergevars_form($form, &$form_state, $entity_type, $bundle_name, $field_name) {
  $field = field_info_field($field_name);
  if (!isset($field['settings']['mc_list_id'])) {
    return array();
  }
  $list = mailchimp_get_list($field['settings']['mc_list_id']);
  $form_state['entity_type'] = $entity_type;
  $form_state['bundle_name'] = $bundle_name;
  $form_state['field'] = $field;
  if ($list) {
    return confirm_form($form,
      t('Update Merge Fields on %list for all @entity_type -- @bundle entities?',
        array(
          '%list' => $list['name'],
          '@entity_type' => $entity_type,
          '@bundle' => $bundle_name,
        )),
      'admin/config/services/mailchimp/lists',
      t('This can overwrite values configured directly on your MailChimp Account.'),
      "Update Merge Values"
    );
  }
  return array();
}

/**
 * Submit handler for mailchimp_lists_update_mergevars_form().
 */
function mailchimp_lists_update_mergevars_form_submit($form, &$form_state) {
  mailchimp_lists_update_member_merge_values($form_state['entity_type'], $form_state['bundle_name'], $form_state['field']);
  $form_state['redirect'] = 'admin/config/services/mailchimp/fields';
}
