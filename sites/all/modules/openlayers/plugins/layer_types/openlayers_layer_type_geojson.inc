<?php
/**
 * @file
 * GeoJSON Layer Type
 */

/**
 * Define the Ctools plugin options.
 */
function openlayers_openlayers_layer_type_geojson_openlayers_layer_types() {
  return array(
    'title' => t('GeoJSON'),
    'description' => t('Provides a vector layer based on <a href="!url">GeoJSON</a>.',
      array('!url' => 'http://geojson.org/')),
    'layer_type' => array(
      'file' => 'openlayers_layer_type_geojson.inc',
      'class' => 'openlayers_layer_type_geojson',
      'parent' => 'openlayers_layer_type',
    ),
  );
}

/**
 * OpenLayers GeoJSON Layer Type class
 */
class openlayers_layer_type_geojson extends openlayers_layer_type {
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
      'layer_type' => 'openlayers_layer_type_geojson',
      'layer_handler' => 'geojson',
      'projection' => array('4326'),
      'baselayer' => FALSE,
      'vector' => TRUE,
      'geojson_data' => '',
      'useBBOX' => FALSE,
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array(
      'url' => array(
        '#type' => 'textfield',
        '#title' => t('URL'),
        '#description' => t('The URL of the GeoJSON file.  This can be a Drupal path as well, as it will get run through the Drupal <a href="!url">url()</a> function.',
          array('!url' => 'http://api.drupal.org/api/drupal/includes--common.inc/function/url')),
        '#maxlength' => 1024,
        '#default_value' => isset($this->data['url']) ? $this->data['url'] : '',
      ),
      'useBBOX' => array(
        '#type' => 'checkbox',
        '#title' => t('Use Bounding Box Strategy'),
        '#description' => t('Bounding Box strategy will add a query string onto the GeoJSON URL, which means that only data in the viewport of the map will be loaded.  This can be helpful if you have lots of data coming from the feed.'),
        '#default_value' => isset($this->data['useBBOX']) ? $this->data['useBBOX'] : FALSE,
      ),
      //see http://dev.openlayers.org/docs/files/OpenLayers/Strategy/BBOX-js.html#OpenLayers.Strategy.BBOX.resFactor
      'resFactor' => array(
        '#type' => 'textfield',
        '#title' => t('Bounding Box resFactor'),
        '#description' => t('Used to determine when previously requested features are invalid (set to 1 if unsure).
          The resFactor will be compared to the resolution of the previous request to the current map resolution.<br />
          If resFactor > (old / new) and 1/resFactor < (old / new).
          <ul>
          <li>If you set a resFactor of 1, data will be requested every time the resolution changes.</li>
          <li>If you set a resFactor of 3, data will be requested if the old resolution is 3 times the new, or if the new is 3 times the old.</li>
          <li>If the old bounds do not contain the new bounds new data will always be requested (with or without considering resFactor).</li>
          </ul>
          '),
        '#default_value' => isset($this->data['resFactor']) ? $this->data['resFactor'] : 1
      ),
      'geojson_data' => array(
        '#type' => 'textarea',
        '#title' => t('GeoJSON Data'),
        '#description' => t('Paste raw GeoJSON data here.  It is better to use a URL.  This is provided for very simple use cases like one or two features.  If there is data here, it will override the URL above.'),
        '#default_value' => isset($this->data['geojson_data']) ? $this->data['geojson_data'] : '',
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_geojson'
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    $this->options['url'] = !empty($this->options['url']) ? url($this->options['url']) : '';

    drupal_add_js(drupal_get_path('module', 'openlayers')
      . '/plugins/layer_types/openlayers_layer_type_geojson.js');
    return $this->options;
  }
}
