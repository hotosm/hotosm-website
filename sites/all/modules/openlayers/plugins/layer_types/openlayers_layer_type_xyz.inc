<?php
/**
 * @file
 * XYZ Layer Type
 * http://dev.openlayers.org/docs/files/OpenLayers/Layer/XYZ-js.html
 */

/**
 * OpenLayers XYZ Layer Type class
 */
class openlayers_layer_type_xyz extends openlayers_layer_type {

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_handler' => 'xyz',
      'sphericalMercator' => TRUE,
      'wrapDateLine' => FALSE,
      'zoomOffset' => 0,
      'resolutions' => array_slice(openlayers_get_resolutions('EPSG:900913'), 0, 18)
    ) + parent::options_init();
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array(
      'url' => array(
        '#type' => 'textarea',
        '#title' => t('Base URL (template)'),
        '#default_value' => !empty($this->data['url']) ? implode("\n", (array) $this->data['url']) : '',
        '#maxlength' => 2083,
        '#description' => t('This is the base URL template for the XYZ layer.  It should be something similar to <em>http://example.com/tiles/1.0.0/layer_name/${z}/${x}/${y}.png</em>.'),
      ),
      'serverResolutions' => array(
        '#type' => 'select',
        '#multiple' => TRUE,
        '#description' => t('Only set this if you need a very specific resolution.'),
        '#options' => array_combine(
          array_map('strval', openlayers_get_resolutions('EPSG:900913')),
          range(0, 21)),
        '#title' => t('Zoom Level Range'),
        '#default_value' => isset($this->data['serverResolutions']) ?
          array_map('strval', $this->data['serverResolutions']) : array(),
      ),
      'resolutions' => array(
        '#type' => 'select',
        '#multiple' => TRUE,
        '#description' => t('Only set this if you need a very specific resolution.'),
        '#options' => array_combine(
          array_map('strval', openlayers_get_resolutions('EPSG:900913')),
          range(0, 21)),
        '#title' => t('Zoom Level Range'),
        '#default_value' => isset($this->data['resolutions']) ?
          array_map('strval', $this->data['resolutions']) : array(),
      ),
      'zoomOffset' => array(
        '#type' => 'select',
        '#description' => t('Zoom offset.'),
        '#options' => array_combine(
          range(0, 21),
          range(0, 21)),
        '#title' => t('Zoom offset'),
        '#default_value' => isset($this->data['zoomOffset']) ?
          $this->data['zoomOffset'] : array(),
      ),
      'wrapDateLine' => array(
        '#type' => 'checkbox',
        '#title' => t('Wrap Date Line'),
        '#default_value' => isset($this->data['wrapDateLine']) ? $this->data['wrapDateLine'] : FALSE,
        '#description' => t('This allows the user to continually pan left and right as the tiles will repeat themselves.  Note that this option is known to not work well with the 2.10 OL library.'),
      ),
    );
  }

  function options_form_validate($form, &$form_state) {
    $form_state['data']['url'] = explode("\n", $form_state['data']['url']);
    $form_state['data']['serverResolutions'] = array_map('floatval', array_values($form_state['data']['serverResolutions']));
    $form_state['data']['resolutions'] = array_map('floatval', array_values($form_state['data']['resolutions']));
    $form_state['data']['zoomOffset'] = (int) $form_state['data']['zoomOffset'];
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/layer_types/openlayers_layer_type_xyz.js');
  }
}
