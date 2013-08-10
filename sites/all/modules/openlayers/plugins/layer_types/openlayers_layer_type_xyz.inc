<?php
/**
 * @file
 * XYZ Layer Type
 * http://dev.openlayers.org/docs/files/OpenLayers/Layer/XYZ-js.html
 */

/**
 * Define the Ctools plugin options.
 */
function openlayers_openlayers_layer_type_xyz_openlayers_layer_types() {
  return array(
    'title' => t('XYZ'),
    'description' => t('XYZ layer type.  These are tiles sets usually in the form of {z}/{x}/{y}.png.'),
    'layer_type' => array(
      'file' => 'openlayers_layer_type_xyz.inc',
      'class' => 'openlayers_layer_type_xyz',
      'parent' => 'openlayers_layer_type',
    ),
  );
}

/**
 * OpenLayers XYZ Layer Type class
 */
class openlayers_layer_type_xyz extends openlayers_layer_type {
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
      'serverResolutions' => array(),
      'maxExtent' => openlayers_get_extent('900913'),
      'layer_handler' => 'xyz',
      'baselayer' => TRUE,
      'sphericalMercator' => TRUE,
      'wrapDateLine' => FALSE,
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array(
      'url' => array(
        '#type' => 'textfield',
        '#title' => t('Base URL (template)'),
        '#default_value' => isset($this->data['url']) ? $this->data['url'] : '',
        '#maxlength' => 2083,
        '#description' => t('This is the base URL template for the XYZ layer.  It should be something similar to <em>http://example.com/tiles/1.0.0/layer_name/${z}/${x}/${y}.png</em>.'),
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_xyz'
      ),
      'serverResolutions' => array(
        '#type' => 'select',
        '#multiple' => TRUE,
        '#description' => t('Only set this if you need a very specific resolution.'),
        '#options' => array_combine(
          array_map('strval', openlayers_get_resolutions('900913')),
          range(0, 18)),
        '#title' => t('Zoom Level Range'),
        '#default_value' => isset($this->data['serverResolutions']) ?
          $this->data['serverResolutions'] : array(),
      ),
      'wrapDateLine' => array(
        '#type' => 'checkbox',
        '#title' => t('Wrap Date Line'),
        '#default_value' => isset($this->data['wrapDateLine']) ? $this->data['wrapDateLine'] : FALSE,
        '#description' => t('This allows the user to continually pan left and right as the tiles will repeat themselves.  Note that this option is known to not work well with the 2.10 OL library.'),
      ),
      'projection' =>
        array(
         '0' => array(
          '#type' => 'hidden',
          '#value' => '900913',
        ),
      )
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/layer_types/openlayers_layer_type_xyz.js');
    return $this->options;
  }
}
