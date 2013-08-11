<?php

/**
 * Implements hook_preprocess_block().
 */
function omega_preprocess_field(&$variables) {
  // Change field name class to use BEM syntax.
  $variables['classes_array'] = preg_replace('/^field-name-' . $variables['field_name_css'] . '$/', 'field--name-' . $variables['field_name_css'], $variables['classes_array']);
  // Change field type class to use BEM syntax.
  $variables['classes_array'] = preg_replace('/^field-type-' . $variables['field_type_css'] . '$/', 'field--type-' . $variables['field_type_css'], $variables['classes_array']);
  // Change field label display class to use BEM syntax.
  $variables['label_display_css'] = drupal_clean_css_identifier($variables['element']['#label_display']);
  $variables['classes_array'] = preg_replace('/^field-label-' . $variables['label_display_css'] . '$/', 'field--label-' . $variables['label_display_css'], $variables['classes_array']);
}
