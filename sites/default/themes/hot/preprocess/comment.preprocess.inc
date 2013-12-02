<?php

/**
 * @file
 * Contains a pre-process hook for 'comment'.
 */

/**
 * Implements hook_preprocess_comment().
 */
function hot_preprocess_comment(&$variables) {
  $variables['submitted'] = t('Comment by !username on !datetime', array('!username' => $variables['author'], '!datetime' => $variables['created']));
}
