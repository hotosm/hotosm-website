<?php
/**
 * @file
 * Rules integration for the mailchimp lists module.
 */

/**
 * Implements hook_rules_action_info().
 */
function mailchimp_lists_rules_action_info() {
  $items = array();
  $items['mailchimp_lists_user_subscribe'] = array(
    'label' => t('Subscribe or unsubscribe entity from a MailChimp list'),
    'parameter' => array(
      'entity' => array(
        'type' => 'entity',
        'label' => t('Entity'),
        'description' => t('The entity to subscribe/unsubscribe'),
      ),
      'field' => array(
        'type' => '*',
        'label' => t('MailChimp List Subscription Field'),
        'description' => t('Subscription Field connected to the desired Mailchimp List.'),
        'restriction' => 'selector',
        'wrapped' => TRUE,
        'allow null' => FALSE,
      ),
      'subscribe' => array(
        'type' => 'boolean',
        'label' => t('Subscribe'),
        'description' => t('True to subscribe, False to unsubscribe'),
      ),
    ),
    'group' => t('MailChimp'),
    'access callback' => 'mailchimp_lists_rules_access_callback',
    'base' => 'mailchimp_lists_rules_action_entity_subscribe',
  );
  return $items;
}

/**
 * Action callback: Subscribe an entity to a list.
 */
function mailchimp_lists_rules_action_entity_subscribe($entity, $field, $subscribe) {
  $field_info = $field->info();
  $choices = reset($field_info['instance']['default_value']);
  $choices['subscribe'] = $subscribe;
  mailchimp_lists_process_subscribe_form_choices($choices, $field_info['instance'], $field_info['field'], $entity->value());
}

/**
 * Access callback for the rules integration.
 */
function mailchimp_lists_rules_access_callback() {
  return user_access('administer mailchimp');
}
