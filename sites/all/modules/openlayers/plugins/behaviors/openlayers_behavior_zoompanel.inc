<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_zoompanel_openlayers_behaviors() {
  return array(
    'title' => t('Zoom Control'),
    'description' => t('Provides a control that can Zoom In, Zoom Out, and Zoom to Max Extent Button.  Do not use with Pan Zoom Bar Control or Pan Zoom Control.'),
    'type' => 'map',
    'behavior' => array(
      'file' => 'openlayers_behavior_zoompanel.inc',
      'class' => 'openlayers_behavior_zoompanel',
      'parent' => 'openlayers_behavior',
    ),
  );
}

/**
 * Zoom Panel Behavior
 */
class openlayers_behavior_zoompanel extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'panzoom' => '',
    );
  }

  function js_dependency() {
    return array(
      'OpenLayers.Control.ZoomPanel'
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_zoompanel.js');
    return $this->options;
  }
}
