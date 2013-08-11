<?php

/**
 * Removes the ugly .panels-separator.
 */
function omega_panels_default_style_render_region(&$variables) {
  return implode('', $variables['panes']);
}
