<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

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
