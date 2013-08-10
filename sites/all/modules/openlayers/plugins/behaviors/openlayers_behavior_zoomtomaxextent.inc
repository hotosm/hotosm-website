<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_zoomtomaxextent_openlayers_behaviors() {
  return array(
    'title' => t('Zoom to Max Extent'),
    'description' => t('Provides button to zoom to the maximum extent of the map.'),
    'type' => 'map',
    'behavior' => array(
      'file' => 'openlayers_behavior_zoomtomaxextent.inc',
      'class' => 'openlayers_behavior_zoomtomaxextent',
      'parent' => 'openlayers_behavior',
    ),
  );
}

/**
 * Zoom to Max Extent Behavior
 */
class openlayers_behavior_zoomtomaxextent extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'zoomtomaxextent' => '',
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_zoomtomaxextent.js');
    return $this->options;
  }
}
