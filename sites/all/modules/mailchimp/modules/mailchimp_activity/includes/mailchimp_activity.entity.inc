<?php

/**
 * @file
 * Mailchimp Activity entity class
 */

class MailchimpActivityEntity extends Entity {
  public
    $mailchimp_activity_entity_id,
    $name,
    $label,
    $entity_type,
    $bundle,
    $email_property,
    $entity_path,
    $enabled;

  /**
   * Basic __construct implementation.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'mailchimp_activity_entity');
  }

  /**
   * Overrides Entity\Entity::uri().
   */
  public function uri() {
    return array(
      'path' => 'admin/config/services/mailchimp/activity/manage/' . $this->name,
      'options' => array(
        'entity_type' => $this->entityType,
        'entity' => $this,
      ),
    );
  }

}
