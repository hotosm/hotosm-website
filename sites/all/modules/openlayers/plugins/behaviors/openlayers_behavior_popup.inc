<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Popup Behavior
 */
class openlayers_behavior_popup extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layers' => array(),
      'panMapIfOutOfView' => FALSE,
      'keepInMap' => TRUE,
    );
  }

  /**
   * Form defintion for per map customizations.
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
      'layers' => array(
        '#title' => t('Layers'),
        '#type' => 'checkboxes',
        '#options' => $vector_layers,
        '#description' => t('Select layer to apply popups to.'),
        '#default_value' => isset($defaults['layers']) ?
          $defaults['layers'] : array(),
      ),
      'panMapIfOutOfView' => array(
        '#type' => 'checkbox',
        '#title' => t('Pan map if popup out of view'),
        '#description' => t('When drawn, pan map such that the entire popup is visible in the current viewport (if necessary).'),
        '#default_value' => isset($defaults['panMapIfOutOfView']) ? $defaults['panMapIfOutOfView'] : FALSE
        ),
      'keepInMap' => array(
        '#type' => 'checkbox',
        '#title' => t('Keep in map'),
        '#description' => t('If panMapIfOutOfView is false, and this property is true, contrain the popup such that it always fits in the available map space.'),
        '#default_value' => isset($defaults['keepInMap']) ? $defaults['keepInMap'] : TRUE
        ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    // Put weight on JS so that we know navigation is included already as this
    // will affect touch devices.
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_popup.js', array('weight' => 10));
    return $this->options;
  }
}
