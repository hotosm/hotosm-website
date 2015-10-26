<?php

/**
 * @file
 * Class file for Mailchimp Signup UI Controller.
 */

/**
 * Override EntityDefaultUIController to customize our menu items.
 */
class MailChimpSignupUIController extends EntityDefaultUIController {

  /**
   * Overrides parent::hook_menu().
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['title'] = t('Signup Forms');
    $items[$this->path]['description'] = t('Manage MailChimp Signup blocks and pages.');
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    $items[$this->path]['weight'] = 10;
    $items[$this->path]['access callback'] = 'mailchimp_signup_entity_access';

    return $items;
  }

  /**
   * Overrides parent::overviewTable().
   */
  public function overviewTable($conditions = array()) {
    $render = parent::overviewTable($conditions);
    $mc_lists = mailchimp_get_lists();
    foreach ($render['#rows'] as &$row) {
      $signup = $row[0]['data']['#url']['options']['entity'];
      $modes = NULL;
      $block_only = FALSE;
      switch ($signup->mode) {
        case MAILCHIMP_SIGNUP_BLOCK:
          $modes = l(t('Block'), 'admin/structure/block');
          $block_only = TRUE;
          break;

        case MAILCHIMP_SIGNUP_PAGE:
          $modes = l(t('Page'), $signup->settings['path']);
          break;

        case MAILCHIMP_SIGNUP_BOTH:
          $modes = l(t('Block'), 'admin/structure/block') . ' and ' . l(t('Page'), $signup->settings['path']);
          break;

      }
      $list_labels = array();
      foreach ($signup->mc_lists as $list_id) {
        $list_labels[] = l($mc_lists[$list_id]['name'], 'https://admin.mailchimp.com/lists/dashboard/overview?id=' . $mc_lists[$list_id]['web_id']);
      }
      if ($block_only) {
        $access = t('N/A - this form only exists as a block');
      }
      else {
        $all_roles_allowed = user_roles(FALSE, 'mailchimp_signup_all_forms' . $signup->name);
        $page_roles_allowed = user_roles(FALSE, 'mailchimp_signup_form_' . $signup->name);
        $roles_allowed = array_merge($all_roles_allowed, $page_roles_allowed);
        $access = implode(', ', $roles_allowed);
        $actions[] = l(t('Permissions'), 'admin/people/permissions', array('fragment' => 'edit-mailchimp-signup-all-forms'));
      }
      $new_row = array();
      // Put the label column data first:
      $new_row[] = array_shift($row);
      // Now our custom columns:
      $new_row[] = $modes;
      $new_row[] = implode(', ', $list_labels);
      $new_row[] = $access;
      // Now tack on the remaining built-in rows:
      $row = array_merge($new_row, $row);
    }
    $new_header[] = array_shift($render['#header']);
    $new_header[] = t('Display Mode(s)');
    $new_header[] = t('MailChimp Lists');
    $new_header[] = t('Page Access');
    $render['#header'] = array_merge($new_header, $render['#header']);
    return $render;
  }

}
