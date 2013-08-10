<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_argparser_openlayers_behaviors() {
  return array(
    'title' => t('Argument Parser'),
    'description' => t('Parses Permalink-formatted arguments without adding a
    Permalink link to the map.  Permalink is usually similar to:
    ?zoom=1&lat=11&lon=11&layers=B0F'),
    'type' => 'layer',
    'behavior' => array(
      'file' => 'openlayers_behavior_argparser.inc',
      'class' => 'openlayers_behavior_argparser',
      'parent' => 'openlayers_behavior',
    ),
  );
}

/**
 * Attribution Behavior
 */
class openlayers_behavior_argparser extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'anchor' => FALSE,
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.ArgParser');
  }

  function options_form($defaults = array()) {
    return array(
      'anchor' => array(
        '#type' => 'checkbox',
        '#title' => t('Anchor'),
        '#description' => t('Permalink is in the form of an anchor (#) instead of a query (?).'),
        '#default_value' => (isset($defaults['anchor'])) ? $defaults['anchor'] : FALSE,
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_argparser.js');
    return $this->options;
  }
}
