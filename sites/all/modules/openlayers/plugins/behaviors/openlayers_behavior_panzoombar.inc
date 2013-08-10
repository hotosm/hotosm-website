<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Ctools plugin definition.
 */
function openlayers_openlayers_behavior_panzoombar_openlayers_behaviors() {
  return array(
    'title' => t('Pan and Zoom Bar Controls'),
    'description' => t('Gives user ability to pan and zoom, with a full zoom bar in the map interface.  Do not use with Pan Zoom Contols or Zoom Panel Controls.'),
    'type' => 'map',
    'behavior' => array(
      'file' => 'openlayers_behavior_panzoombar.inc',
      'class' => 'openlayers_behavior_panzoombar',
      'parent' => 'openlayers_behavior',
    ),
  );
}

/**
 * Pan Zoom Bar Behavior
 */
class openlayers_behavior_panzoombar extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'zoomWorldIcon' => FALSE,
      'panIcons' => TRUE,
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.PanZoomBar');
  }

  function options_form($defaults = array()) {
    return array(
      'zoomWorldIcon' => array(
        '#type' => 'checkbox',
        '#title' => t('World Icon'),
        '#description' => t('This puts the world icon in the pan controls.  This button will zoom to the max extent when it is pressed.'),
        '#default_value' => isset($defaults['zoomWorldIcon']) ? $defaults['zoomWorldIcon'] : FALSE
      ),
      'panIcons' => array(
        '#type' => 'checkbox',
        '#title' => t('Pan Icons'),
        '#description' => t('Enable the pan controls.  Without it, then the user will only see a zoom bar.'),
        '#default_value' => isset($defaults['panIcons']) ? $defaults['panIcons'] : TRUE
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_panzoombar.js');
    return $this->options;
  }
}
