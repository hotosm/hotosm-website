<?php
/**
 * @file
 *
 * OpenLayers VirtualEarth layer type
 */

/**
 * Define the Ctools plugin options.
 */
$plugin = array(
  'title' => t('Bing'),
  'description' => t('Microsoft Bing'),
  'layer_type' => array(
    'file' => 'openlayers_layer_type_bing.inc',
    'class' => 'openlayers_layer_type_bing',
    'parent' => 'openlayers_layer_type',
  ),
);

/**
 * OpenLayers VirtualEarth Layer Type class
 */
class openlayers_layer_type_bing extends openlayers_layer_type {
  function __construct($layer = array(), $map = array()) {
    parent::__construct($layer, $map);
    if (isset($this->data)) {
      $this->data += $this->options_init();
    }
    else {
      $this->data = $this->options_init();
    }
  }

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_type' => 'bing',
      'layer_handler' => 'bing',
      'key' => variable_get('openlayers_layers_bing_api', ''),
      'projection' => array('900913'),
      'baselayer' => TRUE,
      'type' => 'Road',
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    $warning = (!variable_get('openlayers_layers_bing_api', FALSE)) ?
      array('#value' => t('WARNING: Your Bing API key is not set.
        Map including Bing layers will break until it is set correctly.')
      ) : NULL;

    $bing_layer_types = array(
      'Road' => 'Road',
      'AerialWithLabels' => 'Hybrid',
      'Aerial' => 'Aerial',
    );

    return array(
      'type' => array(
        '#title' => t('Bing Layer Type'),
        '#type' => 'select',
        '#default_value' => isset($this->data['type']) ?
          $this->data['type'] : 'Road',
        '#options' => $bing_layer_types
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_bing'
      ),
      $warning
    );
  }

  /**
   * Layer-type-wide settings form
   */
  function settings_form() {
    return array(
      'openlayers_layers_bing_api' => array(
        '#type' => 'textfield',
        '#title' => t('Bing API Key'),
        '#default_value' => variable_get('openlayers_layers_bing_api', ''),
        '#description' => t('<a href="@microsoft">Get a MS Bing API Key</a>',
          array('@microsoft' => 'http://bingmapsportal.com'))
      )
    );

  }

  /**
   * Render.
   */
  function render(&$map) {
    static $bing_maps_included;

    if (!isset($bing_maps_included)) {
      drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/layer_types/openlayers_layer_type_bing.js');
      $bing_maps_included = TRUE;
    }
    return $this->options;
  }
}
