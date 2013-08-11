<?php

/**
 * Implements hook_preprocess_TEMPLATE().
 */
function ohm_preprocess_comment_wrapper(&$variables) {
  $variables['form_title_attributes_array']['class'][] = 'section-title';
  $variables['title_attributes_array']['class'][] = 'section-title';
}
