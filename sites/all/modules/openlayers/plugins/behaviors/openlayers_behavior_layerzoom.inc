<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Layer Zoom Behavior
 */
class openlayers_behavior_layerzoom extends openlayers_behavior {

  function options_form($defaults = array()) {
    $options = array();

    foreach ($this->map['layers'] as $layer) {
      if ($layer != $this->map['default_layer']) {
        $options[$layer] = array(
          'enable' => array(
            '#type' => 'checkbox',
            '#title' => t('Enable dynamic zoom levels for @layer', array('@layer' => $layer)),
            '#default_value' => isset($this->options[$layer]['enable']) ? $this->options[$layer]['enable'] : 0,
          ),
          'resolutions' => array(
            '#type' => 'select',
            '#multiple' => TRUE,
            '#options' => array_combine(
              array_map('strval', openlayers_get_resolutions('EPSG:900913')),
              range(0, 21)
            ),
            '#title' => t('Zoom Level Range for @layer', array('@layer' => $layer)),
            '#default_value' => isset($this->options[$layer]['resolutions']) ?
              $this->options[$layer]['resolutions'] :
              array_map('strval', openlayers_get_resolutions('EPSG:900913')),
            '#description' => t('The zoom levels at which this layer will display.'),
          ),
        );
      }
    }
    return $options;
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_layerzoom.js');
    return $this->options;
  }
}
