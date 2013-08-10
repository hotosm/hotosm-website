<?php
/**
 * @file
 * Raw Layer Type
 */

/**
 * Define the Ctools plugin options.
 */
function openlayers_openlayers_layer_type_raw_openlayers_layer_types() {
  return array(
    'title' => t('Raw'),
    'description' => t('Layer type for raw data input -
    not meant to be added with the UI.'
    ),
    'layer_type' => array(
      'file' => 'openlayers_layer_type_raw.inc',
      'class' => 'openlayers_layer_type_raw',
      'parent' => 'openlayers_layer_type',
    ),
  );
}

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
      'layer_type' => 'openlayers_layer_type_raw',
      'layer_handler' => 'openlayers_raw',
      'vector' => TRUE,
      'baselayer' => FALSE,
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array(
      array(
        '#value' => t('Raw layers should not be added
        through the UI.')
      )
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/layer_types/openlayers_layer_type_raw.js');
    // $features = ;
    // $this->data['features'] = $features;
    return $this->options;
  }
}

