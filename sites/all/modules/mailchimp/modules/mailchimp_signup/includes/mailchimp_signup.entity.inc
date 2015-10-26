<?php

/**
 * @file
 * Mailchimp Signup entity class
 */

class MailchimpSignup extends Entity {
  public
    $mcs_id,
    $name,
    $mc_lists,
    $mode,
    $title,
    $settings;

  /**
   * Override parent constructor to set the entity type.
   */
  public function __construct(array $values = array()) {
    parent::__construct($values, 'mailchimp_signup');
  }

  /**
   * Return a label for a signup form.
   */
  public function label() {
    return $this->title;
  }

  /**
   * Overrides Entity\Entity::uri().
   */
  public function uri() {
    return array(
      'path' => 'admin/config/services/mailchimp/signup/manage/' . $this->name,
      'options' => array(
        'entity_type' => $this->entityType,
        'entity' => $this,
      ),
    );
  }

}
