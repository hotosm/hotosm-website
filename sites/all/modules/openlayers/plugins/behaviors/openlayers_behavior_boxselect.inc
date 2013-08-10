<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_boxselect_openlayers_behaviors() {
  return array(
    'title' => t('Bounding Box Select'),
    'description' => t('Allows the selection and display of a bounding box.  Currently hard-coded for the map making interface.'),
    'type' => 'map',
    'ui_visibility' => FALSE,
    'behavior' => array(
      'file' => 'openlayers_behavior_boxselect.inc',
      'class' => 'openlayers_behavior_boxselect',
      'parent' => 'openlayers_behavior',
    ),
  );
}
/**
 * BoxSelect Behavior
 */
class openlayers_behavior_boxselect extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'input_fields' => '',
    );
  }

  function js_dependency() {
    return array(
      'OpenLayers.Control.DrawFeature',
      'OpenLayers.Layer.Vector',
      'OpenLayers.Handler.RegularPolygon'
    );
  }

  function options_form($defaults = array()) {
    return array(
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_boxselect.js');
    return $this->options;
  }
}
