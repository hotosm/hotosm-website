<?php

/**
 * @file
 * Class file for Mailchimp Activity UI Controller.
 */

/**
 * Override EntityDefaultUIController to customize our menu items.
 */
class MailChimpActivityUIController extends EntityDefaultUIController {

  /**
   * Overrides parent::hook_menu().
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage MailChimp Activity entity settings.';
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    $items[$this->path]['access callback'] = 'mailchimp_activity_entity_access';
    $items[$this->path]['title'] = "Activity";
    $items[$this->path]['weight'] = 10;
    return $items;
  }

}
