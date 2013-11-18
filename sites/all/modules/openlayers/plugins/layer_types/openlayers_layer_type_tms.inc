<?php
/**
 * @file
 * TMS Layer Type
 */

/**
 * OpenLayers TMS Layer Type class
 */
class openlayers_layer_type_tms extends openlayers_layer_type {

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_handler' => 'tms',
      'type' => 'png',
      'maptiler' => FALSE,
      'serviceVersion' => '1.0.0',
      'wrapDateLine' => FALSE,
      'zoomOffset' => 0,
      'url' => ''
    ) + parent::options_init();
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array(
      'url' => array(
        '#type' => 'textarea',
        '#title' => t('Base URL'),
        '#default_value' => !empty($this->data['url']) ? implode("\n", $this->data['url']) : '',
        '#description' => t('This is the base URL of the TMS service.  For example, if this was your tile scheme URL: http://example.com/tms/1.0.0/layer_name/{z}/{y}/{x}.png, then <em>http://example.com/tms/</em> would be the Base URL.'),
      ),
      'layername' => array(
        '#type' => 'textfield',
        '#title' => t('Layer Name'),
        '#default_value' => isset($this->data['layername']) ?
          $this->data['layername'] : '',
        '#description' => t('This is the base URL of the TMS service.  For example, if this was your tile scheme URL: http://example.com/tms/1.0.0/layer_name/{z}/{y}/{x}.png, then <em>layer_name</em> would be the Layer Name.'),
      ),
      'type' => array(
        '#type' => 'select',
        '#title' => t('File Format'),
        '#options' => array(
          'png' => 'png',
          'jpg' => 'jpg'),
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
          array_map('strval', openlayers_get_resolutions('EPSG:900913')),
        '#description' => t('The available zoom levels for the tiles.'),
      ),
      'wrapDateLine' => array(
        '#type' => 'checkbox',
        '#title' => t('Wrap Dateline'),
        '#default_value' => isset($this->data['wrapDateLine']) ?
          $this->data['wrapDateLine'] : FALSE,
        '#description' => t('Wrapping the dateline will cause the map to appear to repeat itself when going east or west.  This may not be supported by all tilesets.'),
      ),
      'serviceVersion' => array(
        '#type' => 'textfield',
        '#title' => t('Service version for tile requests'),
        '#default_value' => isset($this->data['serviceVersion']) ?
          $this->data['serviceVersion'] : '',
        '#description' => t('Service version for tile requests.  Default is “1.0.0”.'),
      ),
      'zoomOffset' => array(
        '#type' => 'textfield',
        '#title' => t('Zoom offset'),
        '#default_value' => isset($this->data['zoomOffset']) ?
          $this->data['zoomOffset'] : 0,
        '#description' => t('If your cache has more zoom levels than you want to provide access to with this layer, supply a zoomOffset.  This zoom offset is added to the current map zoom level to determine the level for a requested tile.  For example, if you supply a zoomOffset of 3, when the map is at the zoom 0, tiles will be requested from level 3 of your cache.  Default is 0 (assumes cache level and map zoom are equivalent).  Using zoomOffset is an alternative to setting serverResolutions if you only want to expose a subset of the server resolutions.'),
      ),
      'maptiler' => array(
        '#type' => 'checkbox',
        '#title' => t('Rewrite the getUrl method for MapTiler ?'),
        '#default_value' => isset($this->data['maptiler']) ?
          $this->data['maptiler'] : FALSE,
        '#description' => t('MapTiler is using a custom getUrl method to get it\'s tiles'),
      ),
    );
  }

  function options_form_validate($form, &$form_state) {
  }

  function options_form_submit($form, &$form_state) {
    parent::options_form_submit($form, $form_state);
    $form_state['values']['data']['url'] = explode("\n", $form_state['values']['data']['url']);
    $form_state['values']['data']['resolutions'] = array_map('floatval', array_values($form_state['values']['data']['resolutions']));
    $form_state['values']['data']['wrapDateLine'] = (bool) $form_state['values']['data']['wrapDateLine'];
    $form_state['values']['data']['zoomOffset'] = intval($form_state['values']['data']['zoomOffset'], 10);
    $form_state['values']['data']['maptiler'] = (bool) $form_state['values']['data']['maptiler'];
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/layer_types/openlayers_layer_type_tms.js');
  }
}
