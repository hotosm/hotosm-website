<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Hover Behavior
 */
class openlayers_behavior_hover extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layers' => '',
    );
  }

  function options_form($defaults = array()) {

    $vector_layers = array();
    foreach ($this->map['layers'] as $id => $name) {
      $layer = openlayers_layer_load($id);
      if (isset($layer->data['vector']) && $layer->data['vector'] == TRUE) {
        $vector_layers[$id] = $name;
      }
    }

    return array(
      'layers' => array(
        '#type' => 'checkboxes',
        '#options' => $vector_layers,
        '#description' => t('Select vector layer(s).'),
        '#default_value' => isset($defaults['layers']) ? $defaults['layers'] : array(),
      )
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_hover.js');
    return $this->options;
  }
}
