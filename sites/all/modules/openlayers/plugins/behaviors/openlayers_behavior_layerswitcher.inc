<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Layer Switcher Behavior
 */
class openlayers_behavior_layerswitcher extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layerswitcher' => '',
      'ascending' => TRUE,
      'sortBaseLayer' => '0',
      'roundedCorner' => TRUE,
      'roundedCornerColor' => '#222222',
      'maximizeDefault' => FALSE,
      'div' => FALSE,
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.LayerSwitcher');
  }

  function options_form($defaults = array()) {
    return array(
      'ascending' => array(
        '#type' => 'checkbox',
        '#title' => t('Show layers in ascending order'),
        '#description' => t('Higher layers shown toward the bottom'),
        '#default_value' => isset($defaults['ascending']) ? $defaults['ascending'] : TRUE,
      ),
      'sortBaseLayer' => array(
        '#type' => 'select',
        '#title' => t('Sort Base Layers by Title'),
        '#description' => t('Display the layers in the layer switcher by title'),
        '#default_value' => isset($defaults['sortBaseLayer']) ? $defaults['sortBaseLayer'] : 0,
        '#options' => array('0' => t('- None -'), 'ASC' => t('ASC'), 'DESC' => 'DESC'),
      ),
      'roundedCorner' => array(
        '#type' => 'checkbox',
        '#title' => t('Rounded corners'),
        '#description' => t('If true the Rico library is used for rounding the corners of the layer switcher box.'),
        '#default_value' => isset($defaults['roundedCorner']) ? $defaults['roundedCorner'] : TRUE,
      ),
      'roundedCornerColor' => array(
        '#type' => 'textfield',
        '#title' => t('Rounded corners color'),
        '#description' => t('For rounded corners, this is the CSS color to use for the corners.'),
        '#default_value' => isset($defaults['roundedCornerColor']) ? $defaults['roundedCornerColor'] : '#222222',
      ),
      'maximizeDefault' => array(
        '#type' => 'checkbox',
        '#title' => t('Maximize by Default'),
        '#description' => t('Turn on to have the Layer Switcher open by default.'),
        '#default_value' => isset($defaults['maximizeDefault']) ? $defaults['maximizeDefault'] : FALSE,
      ),
      'div' => array(
        '#type' => 'textfield',
        '#title' => t('DIV element for LayerSwitcher'),
        '#description' => t('To create the LayerSwitcher outside of the map, pass the ID attribute of an HTML div element.'),
        '#default_value' => isset($defaults['div']) ? $defaults['div'] : FALSE,
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    // Legacy code for maps not using the default images now
    // provided with the code, or for maps that dont have images
    // set.  We have to set the rounded corner color and add a
    // class for CSS to style
    if (empty($map['image_path'])) {
      $this->options['roundedCornerColor'] = 'darkblue';
      $this->options['displayClass'] = 'olControlLayerSwitcher legacy';
    }
    if ($this->options['sortBaseLayer'] == 'ASC' || $this->options['sortBaseLayer'] == 'DESC') {
      uasort($map['layers'], 'drupal_sort_title');
      if ($this->options['sortBaseLayer'] == 'ASC') {
        $map['layers'] = array_reverse($map['layers'], TRUE);
      }
    }

    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_layerswitcher.js');
    return $this->options;
  }
}
