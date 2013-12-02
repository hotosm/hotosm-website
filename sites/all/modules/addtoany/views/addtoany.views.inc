<?php

/**
 * @file
 * Views integration for AddToAny.
 */

/**
 * Implementation of hook_views_data().
 */
function addtoany_views_data() {
  // Add the addtoany link to the node fields
  $data['node']['addtoany_link'] = array(
    'title' => t('AddToAny link'),
    'help' => t('Link provided by the AddToAny module'),
    'group' => t('Content'),
    'field' => array(
      'handler' => 'addtoany_handler_field_addtoany_link',
      'click sortable' => FALSE,
    )
  );
  return $data;
}
