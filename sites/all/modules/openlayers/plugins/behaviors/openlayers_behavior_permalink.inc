<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_permalink_openlayers_behaviors() {
  return array(
    'title' => t('Permalink'),
    'description' =>  t('Provides a link that will create an URL that will link to a specific map position.  Permalink is usually similar to: ?zoom=1&lat=11&lon=11&layers=B0F'),
    'type' => 'map',
    'behavior' => array(
      'file' => 'openlayers_behavior_permalink.inc',
      'class' => 'openlayers_behavior_permalink',
      'parent' => 'openlayers_behavior',
    ),
  );
}

/**
 * PermaLink Behavior
 */
class openlayers_behavior_permalink extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'anchor' => FALSE,
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.Permalink');
  }

  function options_form($defaults = array()) {
    return array(
      'anchor' => array(
        '#type' => 'checkbox',
        '#title' => t('Anchor'),
        '#description' => t('Permalink is in the form of an anchor (#) instead of a query (?).  Also, this means that the URL location will be constantly updated, and no link will appear.'),
        '#default_value' => (isset($defaults['anchor'])) ? $defaults['anchor'] : FALSE,
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_permalink.js');
    return $this->options;
  }
}
