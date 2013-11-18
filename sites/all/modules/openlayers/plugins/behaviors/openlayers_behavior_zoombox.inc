<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

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
