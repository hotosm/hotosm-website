<?php
/**
 * @file
 * Implementation of OpenLayers Cluster behavior.
 */

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
      'display_cluster_numbers' => TRUE,
      'middle_lower_bound' => '15',
      'middle_upper_bound' => '50',
      'low_color' => 'rgb(141, 203, 61)',
      'middle_color' => 'rgb(49, 190, 145)',
      'high_color' => 'rgb(35, 59, 177)',
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
      ),
      'display_cluster_numbers' => array(
        '#type' => 'checkbox',
        '#title' => t('Display numbers in clusters?'),
        '#default_value' => isset($defaults['display_cluster_numbers']) ? $defaults['display_cluster_numbers'] : TRUE
      ),
      'middle_lower_bound' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['middle_lower_bound'])) ?
          $defaults['middle_lower_bound'] : 15,
        '#size' => 5,
        '#title' => t('Middle lower bound'),
        '#description' => t(''),
      ),
      'middle_upper_bound' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['middle_upper_bound'])) ?
          $defaults['middle_upper_bound'] : 50,
        '#size' => 5,
        '#title' => t('Middle upper bound'),
        '#description' => t(''),
      ),
      'low_color' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['low_color'])) ?
          $defaults['low_color'] : 'rgb(141, 203, 61)',
        '#size' => 5,
        '#title' => t('Low color'),
        '#description' => t(''),
      ),
      'middle_color' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['middle_color'])) ?
          $defaults['middle_color'] : 'rgb(49, 190, 145)',
        '#size' => 5,
        '#title' => t('Middle color'),
        '#description' => t(''),
      ),
      'high_color' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['high_color'])) ?
          $defaults['high_color'] : 'rgb(35, 59, 177)',
        '#size' => 5,
        '#title' => t('High color'),
        '#description' => t(''),
      ),
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
