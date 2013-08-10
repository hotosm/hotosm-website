<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_dragpan_openlayers_behaviors() {
  return array(
    'title' => t('Mouse Drag Pan'),
    'description' => t('Provides the ability to pan in the map interface with the mouse.  The Navigation Control includes this control.  You should only use this behavior if you want fine control over what interactions you want on your map.'),
    'type' => 'map',
    'behavior' => array(
      'file' => 'openlayers_behavior_dragpan.inc',
      'class' => 'openlayers_behavior_dragpan',
      'parent' => 'openlayers_behavior',
    ),
  );
}

/**
 * DragPan Behavior
 */
class openlayers_behavior_dragpan extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'enableKinetic' => FALSE,
      'kineticInterval' => 10,
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.DragPan');
  }

  function options_form($defaults = array()) {
    $form = array();

    // This options seem to be buggy.  Shoudl look into more.
    /*
    $form = array(
      'enableKinetic' => array(
        '#title' => t('Enable Kinetic Dragging'),
        '#type' => 'checkbox',
        '#description' => t('Enables dragging and panning to have acceleration.'),
        '#default_value' => isset($defaults['enableKinetic']) ? $defaults['enableKinetic'] : FALSE,
      ),
      'kineticInterval' => array(
        '#title' => t('Kinetic Interval'),
        '#type' => 'textfield',
        '#description' => t('An integer of millseconds of time between steps in "Kinetic Scrolling".'),
        '#default_value' => isset($defaults['kineticInterval']) ? $defaults['kineticInterval'] : 10,
      ),
    );
    */

    return $form;
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_dragpan.js');
    return $this->options;
  }
}
