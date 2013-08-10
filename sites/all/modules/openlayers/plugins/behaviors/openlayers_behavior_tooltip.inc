<?php
/**
 * @file
 * Implementation of OpenLayers behavior for tooltips.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_tooltip_openlayers_behaviors() {
  return array(
    'title' => t('Tooltip for Features'),
    'description' => t('Adds info boxes on hover to points or shapes on maps.  This does not work with the Popup behavior due to limitation of event handling in the OpenLayers library.'),
    'type' => 'layer',
    'behavior' => array(
      'file' => 'openlayers_behavior_tooltip.inc',
      'class' => 'openlayers_behavior_tooltip',
      'parent' => 'openlayers_behavior',
    ),
  );
}

/**
 * Attribution Behavior
 */
class openlayers_behavior_tooltip extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'attribution' => '',
      'layers' => array(),
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
        '#description' => t('Select layer to apply tooltips to.'),
        '#default_value' => isset($defaults['layers']) ?
          $defaults['layers'] : array(),
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_tooltip.js');
    return $this->options;
  }
}
