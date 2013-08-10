<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_zoombox_openlayers_behaviors() {
  return array(
    'title' => t('Zoom Box Clicking'),
    'description' => t('Provides a zoom box that can be drawn on SHIFT + click.  Please note that by default the Navigation control behavior includes this, so there is no need to have both.'),
    'type' => 'map',
    'behavior' => array(
      'file' => 'openlayers_behavior_zoombox.inc',
      'class' => 'openlayers_behavior_zoombox',
      'parent' => 'openlayers_behavior',
    ),
  );
}

/**
 * Zoom Box Behavior
 */
class openlayers_behavior_zoombox extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'zoombox' => '',
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.ZoomBox');
  }

  function options_form($defaults = array()) {
    return array();
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_zoombox.js');
    return $this->options;
  }
}
