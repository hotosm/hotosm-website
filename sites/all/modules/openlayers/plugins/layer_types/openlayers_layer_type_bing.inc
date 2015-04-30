<?php
/**
 * @file
 *
 * OpenLayers Bing layer type
 */

/**
 * OpenLayers Bing Layer Type class
 */
class openlayers_layer_type_bing extends openlayers_layer_type {

  /**
   * Provide initial values for options.
   */
  function options_init() {
    // Get the page language and the map language, if set.
    global $language;
    $lang = $language->language;
    $culture = variable_get('openlayers_layers_bing_language', '');

    // Bing does not provide imagery for a language without a country code.
    // Best guess is to double-up on the language code ('fr' becomes 'fr-FR').
    // This methods succeeds for all but Dutch (Belgium) 'nl-BE'.
    // See http://msdn.microsoft.com/en-us/library/hh441729.aspx
    $lang = $lang . '-' . strtoupper ($lang);

    return array(
      'layer_handler' => 'bing',
      'key' => variable_get('openlayers_layers_bing_api', ''),
      'type' => 'Road',
      'culture' => $culture == '' ? $lang : $culture,
    ) + parent::options_init();
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
      ),
      'openlayers_layers_bing_language' => array(
        '#type' => 'textfield',
        '#title' => t('Culture'),
        '#description' => t(' The culture parameter provides the strings in
          the language of the culture for geographic place names, map labels,
          and route instructions.  By default, Bing Maps REST Services will
          determine the culture automatically.  Only use this is you
          want to force a specific language.  Please see
          <a href="!url">this list of supported culture codes</a>.',
          array('!url' => 'http://msdn.microsoft.com/en-us/library/hh441729.aspx')
        ),
        '#default_value' => variable_get('openlayers_layers_bing_language', ''),
      ),
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
  }
}
