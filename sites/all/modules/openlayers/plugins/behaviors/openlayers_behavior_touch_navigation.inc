<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_touch_navigation_openlayers_behaviors() {
  return array(
    'title' => t('Touch Navigation'),
    'description' => t('Provides specific navigation controls for touch enabled devices only.  <strong>This is included with the Navigation behavior</strong>.  Only enable this if you are targeting only touch enabled devices.'),
    'type' => 'map',
    'behavior' => array(
      'file' => 'openlayers_behavior_touch_navigation.inc',
      'class' => 'openlayers_behavior_touch_navigation',
      'parent' => 'openlayers_behavior',
    ),
  );
}

/**
 * Touch Navigation Behavior
 */
class openlayers_behavior_touch_navigation extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'documentDrag' => FALSE,
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.TouchNavigation');
  }

  function options_form($defaults = array()) {
    return array(
      'documentDrag' => array(
        '#type' => 'checkbox',
        '#title' => t('Document Drag'),
        '#description' => t('Allow panning of the map by dragging outside map viewport.'),
        '#default_value' => isset($defaults['documentDrag']) ? $defaults['documentDrag'] : FALSE
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_touch_navigation.js');
    return $this->options;
  }
}
