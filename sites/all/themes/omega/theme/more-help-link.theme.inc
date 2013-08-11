<?php

/**
 * Returns HTML for a "more help" link.
 *
 * @param $variables
 *   An associative array containing:
 *   - url: The URL for the link.
 */
function omega_more_help_link($variables) {
  return l(t('More help'), $variables['url'], array('attributes' => array('class' => array('more-link'))));
}
