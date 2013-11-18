<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Zoom To Layer Behavior
 */
class openlayers_behavior_zoomtolayer extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'point_zoom_level' => '5',
      'zoomtolayer_scale' => 1,
    );
  }

  function options_form($defaults = array()) {
    return array(
      'zoomtolayer' => array(
        '#type' => 'checkboxes',
        '#options' => $this->map['layers'],
        '#description' => t('Select layer(s) to which to zoom when the map is loaded.'),
        '#default_value' => isset($defaults['zoomtolayer']) ? $defaults['zoomtolayer'] : array(),
      ),
      'point_zoom_level' => array(
        '#title' => t('Point Zoom Level'),
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['point_zoom_level'])) ?
          $defaults['point_zoom_level'] : 5,
        '#size' => 5,
      ),
      'zoomtolayer_scale' => array(
        '#title' => t('Zoom to Layer Scale'),
        '#type' => 'textfield',
        '#size' => 5,
        '#description' => t('Additional scaling to apply to the calculated bounds before zooming.  See <a href="http://dev.openlayers.org/docs/files/OpenLayers/BaseTypes/Bounds-js.html#OpenLayers.Bounds.scale">OpenLayers docs</a>.'),
        '#default_value' => isset($defaults['zoomtolayer_scale']) ? $defaults['zoomtolayer_scale'] : 1
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_zoomtolayer.js');
    return $this->options;
  }
}
