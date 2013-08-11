<?php

/**
 * Implements hook_preprocess_TEMPLATE().
 */
function ohm_preprocess_region(&$variables) {
  if (in_array($variables['region'], array('highlighted', 'footer'))) {
    $variables['attributes_array']['class'][] = 'l-constrained';
  }
}
