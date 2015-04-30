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
      'low_stroke_color' => 'rgb(141, 203, 61)',
      'low_opacity' => '0.8',
      'low_point_radius' => '10',
      'low_label_outline' => '1',
      'middle_color' => 'rgb(49, 190, 145)',
      'middle_stroke_color' => 'rgb(49, 190, 145)',
      'middle_opacity' => '0.8',
      'middle_point_radius' => '16',
      'middle_label_outline' => '1',
      'high_color' => 'rgb(35, 59, 177)',
      'high_stroke_color' => 'rgb(35, 59, 177)',
      'high_opacity' => '0.8',
      'high_point_radius' => '22',
      'high_label_outline' => '1',
      'label_low_color' => '#000000',
      'label_low_opacity' => '0.8',
      'label_middle_color' => '#000000',
      'label_middle_opacity' => '0.8',
      'label_high_color' => '#000000',
      'label_high_opacity' => '0.8',
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
      'low_stroke_color' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['low_stroke_color'])) ?
          $defaults['low_stroke_color'] : 'rgb(141, 203, 61)',
        '#size' => 5,
        '#title' => t('Low stroke color'),
        '#description' => t(''),
      ),
      'low_opacity' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['low_opacity'])) ?
          $defaults['low_opacity'] : '0.8',
        '#size' => 5,
        '#title' => t('Low opacity'),
        '#description' => t(''),
      ),
      'low_point_radius' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['low_point_radius'])) ?
          $defaults['low_point_radius'] : '10',
        '#size' => 5,
        '#title' => t('Low point radius'),
        '#description' => t(''),
      ),
      'low_label_outline' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['low_label_outline'])) ?
          $defaults['low_label_outline'] : '1',
        '#size' => 5,
        '#title' => t('Low label outline'),
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
      'middle_stroke_color' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['middle_stroke_color'])) ?
          $defaults['middle_stroke_color'] : 'rgb(49, 190, 145)',
        '#size' => 5,
        '#title' => t('Middle stroke color'),
        '#description' => t(''),
      ),
      'middle_opacity' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['middle_opacity'])) ?
          $defaults['middle_opacity'] : '0.8',
        '#size' => 5,
        '#title' => t('Middle opacity'),
        '#description' => t(''),
      ),
      'middle_point_radius' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['middle_point_radius'])) ?
          $defaults['middle_point_radius'] : '16',
        '#size' => 5,
        '#title' => t('Middle point radius'),
        '#description' => t(''),
      ),
      'middle_label_outline' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['middle_label_outline'])) ?
          $defaults['middle_label_outline'] : '1',
        '#size' => 5,
        '#title' => t('Middle label outline'),
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
      'high_stroke_color' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['high_stroke_color'])) ?
          $defaults['high_stroke_color'] : 'rgb(35, 59, 177)',
        '#size' => 5,
        '#title' => t('High stroke color'),
        '#description' => t(''),
      ),
      'high_opacity' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['high_opacity'])) ?
          $defaults['high_opacity'] : '0.8',
        '#size' => 5,
        '#title' => t('High opacity'),
        '#description' => t(''),
      ),
      'high_point_radius' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['high_point_radius'])) ?
          $defaults['high_point_radius'] : '22',
        '#size' => 5,
        '#title' => t('High point radius'),
        '#description' => t(''),
      ),
      'high_label_outline' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['high_label_outline'])) ?
          $defaults['high_label_outline'] : '1',
        '#size' => 5,
        '#title' => t('High label outline'),
        '#description' => t(''),
      ),
      'label_low_color' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['label_low_color'])) ?
          $defaults['label_low_color'] : '#000000',
        '#size' => 5,
        '#title' => t('Text low color'),
        '#description' => t(''),
      ),
      'label_low_opacity' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['label_low_opacity'])) ?
          $defaults['label_low_opacity'] : '0.8',
        '#size' => 5,
        '#title' => t('Text low opacity'),
        '#description' => t(''),
      ),
      'label_middle_color' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['label_middle_color'])) ?
          $defaults['label_middle_color'] : '#000000',
        '#size' => 5,
        '#title' => t('Text middle color'),
        '#description' => t(''),
      ),
      'label_middle_opacity' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['label_middle_opacity'])) ?
          $defaults['label_middle_opacity'] : '0.8',
        '#size' => 5,
        '#title' => t('Text middle opacity'),
        '#description' => t(''),
      ),
      'label_high_color' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['label_high_color'])) ?
          $defaults['label_high_color'] : '#000000',
        '#size' => 5,
        '#title' => t('Text high color'),
        '#description' => t(''),
      ),
      'label_high_opacity' => array(
        '#type' => 'textfield',
        '#default_value' => (isset($defaults['label_high_opacity'])) ?
          $defaults['label_high_opacity'] : '0.8',
        '#size' => 5,
        '#title' => t('Text high opacity'),
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
