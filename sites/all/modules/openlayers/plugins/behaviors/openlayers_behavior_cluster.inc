<?php
/**
 * @file
 * Implementation of OpenLayers Cluster behavior.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_cluster_openlayers_behaviors() {
  return array(
    'title' => t('Cluster Features'),
    'description' => t('Provides vector layer features clustering by proximity.  This will not always respect the styles that assigned to the layer.'),
    'type' => 'layer',
    'behavior' => array(
      'file' => 'openlayers_behavior_cluster.inc',
      'class' => 'openlayers_behavior_cluster',
      'parent' => 'openlayers_behavior',
    ),
  );
}

/**
 * Cluster behavior
 */
class openlayers_behavior_cluster extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'clusterlayer' => array(),
      'distance' => '20',
      'threshold' => NULL,
    );
  }

  /**
   * OpenLayers library dependency.
   */
  function js_dependency() {
    return array('OpenLayers.Strategy.Cluster');
  }

  /**
   * Provide form for configurations per map.
   */
  function options_form($defaults = array()) {
    // Only prompt for vector layers
    $vector_layers = array();
    foreach ($this->map['layers'] as $id => $name) {
      $layer = openlayers_layer_load($id);
      if (isset($layer->data['vector']) && $layer->data['vector'] == TRUE) {
        $vector_layers[$id] = $name;
      }
    }

    return array(
      'clusterlayer' => array(
        '#title' => t('Layers'),
        '#type' => 'checkboxes',
        '#options' => $vector_layers,
        '#description' => t('Select layers to cluster.'),
        '#default_value' => isset($defaults['clusterlayer']) ?
        $defaults['clusterlayer'] : array(),
      ),
      'distance' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['distance'])) ?
        $defaults['distance'] : 20,
        '#size' => 5,
        '#title' => t('Distance'),
        '#description' => t('Pixel distance between features that should ' .
        'be considered a single cluster'),
      ),
      'threshold' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['threshold'])) ?
        $defaults['threshold'] : NULL,
        '#size' => 5,
        '#title' => t('Threshold'),
        '#description' => t('Optional threshold below which original ' .
        'features will be added to the layer instead of clusters'),
      )
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_cluster.js');
    return $this->options;
  }
}
