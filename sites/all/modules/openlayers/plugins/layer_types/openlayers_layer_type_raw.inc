<?php
/**
 * @file
 * Raw Layer Type
 */

/**
 * @file
 * OpenLayers Raw Layer Type
 */
class openlayers_layer_type_raw extends openlayers_layer_type {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_handler' => 'openlayers_raw',
      'vector' => TRUE,
      'isBaseLayer' => FALSE,
    ) + parent::options_init();
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array();
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/layer_types/openlayers_layer_type_raw.js');
    // $features = ;
    // $this->data['features'] = $features;
  }
}

