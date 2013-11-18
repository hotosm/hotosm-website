<?php
/**
 * @file
 * TileWarper Layer Type
 */

/**
 * OpenLayers MapTiler Layer Type class
 */
class openlayers_layer_type_maptiler extends openlayers_layer_type {

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'type' => 'png',
      'layer_handler' => 'maptiler',
      'zoomOffset' => 0,
    ) + parent::options_init();
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array(
      'base_url' => array(
        '#type' => 'textfield',
        '#title' => t('Base URL'),
        '#default_value' => isset($this->data['base_url']) ?
          $this->data['base_url'] : ''
      ),
      'type' => array(
        '#type' => 'select',
        '#options' => array(
          'jpg' => 'JPG',
          'png' => 'PNG'
        ),
        '#default_value' => isset($this->data['type']) ?
          $this->data['type'] : 'png'
      ),
      'resolutions' => array(
        '#type' => 'select',
        '#multiple' => TRUE,
        '#options' => array_combine(
          array_map('strval', openlayers_get_resolutions('EPSG:900913')),
          range(0, 21)
        ),
        '#title' => t('Zoom Level Range'),
        '#default_value' => isset($this->data['resolutions']) ?
          $this->data['resolutions'] :
          array_map('strval', openlayers_get_resolutions('EPSG:900913'))
      ),
      'zoomOffset' => array(
        '#type' => 'textfield',
        '#title' => t('Zoom offset'),
        '#default_value' => isset($this->data['zoomOffset']) ?
          $this->data['zoomOffset'] : 0,
        '#description' => t('If your cache has more zoom levels than you want to provide access to with this layer, supply a zoomOffset.  This zoom offset is added to the current map zoom level to determine the level for a requested tile.  For example, if you supply a zoomOffset of 3, when the map is at the zoom 0, tiles will be requested from level 3 of your cache.  Default is 0 (assumes cache level and map zoom are equivalent).  Using zoomOffset is an alternative to setting serverResolutions if you only want to expose a subset of the server resolutions.'),
      ),
    );
  }

  function options_form_submit($form, &$form_state) {
    parent::options_form_submit($form, $form_state);
    $form_state['values']['data']['base_url'] = explode("\n", $form_state['values']['data']['base_url']);
    $form_state['values']['data']['resolutions'] = array_map('floatval', array_values($form_state['values']['data']['resolutions']));
    $form_state['values']['data']['zoomOffset'] = intval($form_state['values']['data']['zoomOffset'], 10);
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/layer_types/openlayers_layer_type_maptiler.js');
  }
}
