<?php
/**
 * @file
 * Dummy blank Layer Type
 */

/**
 * @file
 * OpenLayers Dummy blank Layer Type
 */
class openlayers_layer_type_dummy extends openlayers_layer_type {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_handler' => 'dummy',
      'vector' => TRUE,
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
      '/plugins/layer_types/openlayers_layer_type_dummy.js');
  }
}

