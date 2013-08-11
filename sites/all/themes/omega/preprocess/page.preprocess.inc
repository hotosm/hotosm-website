<?php

/**
 * Implements hook_preprocess_page().
 */
function omega_preprocess_page(&$variables) {
  if (omega_extension_enabled('layouts') && $layout = omega_layout()) {
    foreach ($layout['info']['regions'] as $region => $name) {
      if (!isset($variables['page'][$region])) {
        $variables['page'][$region] = array();
      }
    }

    $original = system_region_list($GLOBALS['theme_key'], REGIONS_VISIBLE);
    foreach (array_diff_key($original, $layout['info']['regions']) as $region => $name) {
      unset($variables['page'][$region]);
    }
  }
}
