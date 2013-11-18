<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Graticule Behavior
 */
class openlayers_behavior_graticule extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'labelled' => TRUE,
      'numPoints' => 50,
      'targetSize' => 200,
      'displayInLayerSwitcher' => TRUE,
      'lineSymbolizer' => array(
        'strokeColor' => '#333',
        'strokeWidth' => 1,
        'strokeOpacity' => 0.5
      )
    );
  }

  function options_form($defaults = array()) {
    return array(
      'displayInLayerSwitcher' => array(
        '#type' => 'checkbox',
        '#title' => t('Display in layer switcher ?'),
        '#description' => t('Allows the Graticule control to be switched on and off by LayerSwitcher control. Default is true.'),
        '#default_value' => (isset($defaults['displayInLayerSwitcher'])) ? $defaults['displayInLayerSwitcher'] : TRUE,
      ),
      'labelled' => array(
        '#type' => 'checkbox',
        '#title' => t('Labelled'),
        '#description' => t('Should the graticule lines be labelled ? Default is true.'),
        '#default_value' => (isset($defaults['labelled'])) ? $defaults['labelled'] : TRUE,
      ),
      'numPoints' => array(
        '#type' => 'textfield',
        '#title' => t('Number of points'),
        '#description' => t('The number of points to use in each graticule line. Higher numbers result in a smoother curve for projected maps.'),
        '#default_value' => (isset($defaults['numPoints'])) ? $defaults['numPoints'] : 50,
      ),
      'targetSize' => array(
        '#type' => 'textfield',
        '#title' => t('Target size'),
        '#description' => t('The maximum size of the grid in pixels on the map.'),
        '#default_value' => (isset($defaults['targetSize'])) ? $defaults['targetSize'] : 200,
      ),
      'lineSymbolizer' => array(
        'strokeColor' => array(
          '#type' => 'textfield',
          '#title' => t('Stroke color'),
          '#description' => t('The color code to use for the lines. Example: #333'),
          '#default_value' => (isset($defaults['lineSymbolizer']['strokeColor'])) ? $defaults['lineSymbolizer']['strokeColor'] : '#333',
        ),
        'strokeWidth' => array(
          '#type' => 'textfield',
          '#title' => t('Stroke width'),
          '#description' => t('The width of the lines. Example: 1'),
          '#default_value' => (isset($defaults['lineSymbolizer']['strokeWidth'])) ? $defaults['lineSymbolizer']['strokeWidth'] : 1,
        ),
        'strokeOpacity' => array(
          '#type' => 'textfield',
          '#title' => t('Stroke opacity'),
          '#description' => t('The opacity of the line, from 0 to 1. Example: 0.5'),
          '#default_value' => (isset($defaults['lineSymbolizer']['strokeOpacity'])) ? $defaults['lineSymbolizer']['strokeOpacity'] : 0.5,
        ),
      )
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_graticule.js');
    return $this->options;
  }
}
