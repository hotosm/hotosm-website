<?php
/**
 * @file
 * Variable module integration for the AddToAny module.
 */

/**
 * Implements hook_variable_info().
 */
function addtoany_variable_info($options = array()) {
  $variables['addtoany_link_text'] = array(
    'type' => 'string',
    'title' => t('AddToAny link text', array(), $options),
    'description' => t('Text for the universal sharing button link. Example: Share.', array(), $options),
    'default' => '',
    'localize' => TRUE,
  );
  return $variables;
}