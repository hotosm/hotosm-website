<?php
/**
 * @file
 * Google Layer Type
 */

/**
 * OpenLayers Google Layer Type class
 */
class openlayers_layer_type_google extends openlayers_layer_type {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_handler' => 'google',
      'animationEnabled' => TRUE,
      'sphericalMercator' => TRUE,
      'numZoomLevels' => 21
    ) + parent::options_init();
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    $google_layer_types = array(
      'hybrid' => 'Hybrid',
      'normal' => 'Normal',
      'satellite' => 'Satellite',
      'physical' => 'Physical',
    );
    return array(
      'type' => array(
        '#title' => t('Google Layer Type'),
        '#type' => 'select',
        '#default_value' => isset($this->data['type']) ? $this->data['type'] : 'normal',
        '#options' => $google_layer_types
      ),
      'numZoomLevels' => array(
        '#type' => 'textfield',
        '#title' => t('Number of Zoom Levels'),
        '#description' => t('Satellite and hybrid maps are occasionally
          unavailable at higher zoom levels.'),
        '#default_value' => isset($this->data['numZoomLevels']) ?
          $this->data['numZoomLevels'] : '21'
      ),
      'animationEnabled' => array(
        '#type' => 'checkbox',
        '#title' => t('Animation Enabled'),
        '#description' => t('This enables the Google Maps API zooming animation.
          If you are having issues with your Google layer, it may be helpful
          to turn this off.'),
        '#default_value' => isset($this->data['animationEnabled']) ?
          $this->data['animationEnabled'] : TRUE
      ),
    );
  }

  /**
   * Layer-type-wide settings form
   */
  function settings_form() {
    return array(
      'openlayers_google_version' => array(
        '#type' => 'select',
        '#title' => t('Google Maps API version'),
        '#description' => t('If you use Google Maps v3, an API key is not necessary.'),
        '#options' => array(
          '2' => t('v2'),
          '3.5' => t('v3.5'),
        ),
        '#default_value' => variable_get('openlayers_google_version', '3.5'),
      ),
      'openlayers_layers_google_mapdomain' => array(
        '#type' => 'select',
        '#options' => array(
          'maps.google.com' => 'maps.google.com',
          'maps.googleapis.com' => 'maps.googleapis.com',
        ),
        '#title' => t('Google map default domain'),
        '#default_value' => variable_get('openlayers_layers_google_mapdomain', 'maps.google.com'),
        '#description' => t('Select the Google Map default domain. maps.googleapis.com is cookie-free.')
      ),
      'openlayers_layers_google_api' => array(
        '#type' => 'textfield',
        '#title' => t('Google API Key'),
        '#default_value' => variable_get('openlayers_layers_google_api', ''),
        '#description' => t('<a href="@google">Obtain an API key from Google for your domain</a>',
          array('@google' => 'http://code.google.com/apis/maps/signup.html'))
      ),
      'openlayers_layers_google_language' => array(
        '#type' => 'textfield',
        '#title' => t('Language'),
        '#description' => t('This will set the language used
          for the interface (like attribution) as well as tiles,
          as supported by Google.  By default, Google Map API will
          determine the language automatically.  Only use this is you
          want to force a specific language.  Please see
          <a href="!url">this list of languages</a>.',
          array('!url' => 'http://sites.google.com/site/tomihasa/google-language-codes')
        ),
        '#default_value' => variable_get('openlayers_layers_google_language', ''),
      ),
      'openlayers_layers_google_libraries' => array(
        '#type' => 'textfield',
        '#title' => t('Google Maps Libraries'),
        '#description' => t('Insert name of libraries delemited by comma without whitespaces.
          This will determine which libraries will be included in Google Map API v3 js file.'
        ),
        '#default_value' => variable_get('openlayers_layers_google_libraries', ''),
        '#states' => array(
          // Show the settings if 'openlayers_google_version' has been selected for '3.5'.
          'visible' => array(
            ':input[name="openlayers_layer_type_google[settings][openlayers_google_version]"]' => array('value' => '3.5'),
          ),
        ),
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    global $language;
    static $google_maps_included;

    if (!isset($google_maps_included)) {
      // Include files.
      drupal_add_js(drupal_get_path('module', 'openlayers') .
        '/plugins/layer_types/openlayers_layer_type_google.js');

      $mapdomain = variable_get('openlayers_layers_google_mapdomain', 'maps.google.com');
      $version = variable_get('openlayers_google_version', '3.5');

      if ($version == '2') {
        // Create URL for google include
        $url = '//' . $mapdomain . '/maps?file=api&sensor=false&v=' . $version;
        $key = variable_get('openlayers_layers_google_api', variable_get('googlemap_api_key', ''));
        $url .= !empty($key) ? '&key=' . $key : '';
      }
      else {
        // Create URL for google include
        $url = '//' . $mapdomain . '/maps/api/js?sensor=false&v=' . $version;
      }

      $lang = variable_get('openlayers_layers_google_language', '');
      $lang == '' ? $language->language : $lang;
      // Google v2 uses hl and v3 uses language
      $url .= !empty($lang) ? '&hl=' . $lang : '';
      $url .= !empty($lang) ? '&language=' . $lang : '';

      $libraries = variable_get('openlayers_layers_google_libraries', '');
      $url .= !empty($libraries) ? '&libraries=' . $libraries : '';

      drupal_add_js($url, 'external');
      $google_maps_included = TRUE;
    }
  }
}
