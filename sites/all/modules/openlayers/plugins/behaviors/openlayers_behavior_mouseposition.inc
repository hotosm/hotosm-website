<?php
/**
 * @file
 * Implementation of OpenLayers behavior.
 */

/**
 * Mouse Position Behavior
 */
class openlayers_behavior_mouseposition extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'prefix' => '',
      'separator' => ', ',
      'suffix' => '',
      'numDigits' => 4,
      'emptyString' => '',
    );
  }

  function js_dependency() {
    return array('OpenLayers.Control.MousePosition');
  }

  function options_form($defaults = array()) {
    return array(
      'prefix' => array(
        '#title' => t('Prefix'),
        '#type' => 'textfield',
        '#description' => t('A textual prefix to the mouse position.'),
        '#default_value' => isset($defaults['prefix']) ? $defaults['prefix'] : '',
      ),
      'separator' => array(
        '#title' => t('Separator'),
        '#type' => 'textfield',
        '#description' => t('A textual separator between the first and second value.'),
        '#default_value' => isset($defaults['separator']) ? $defaults['separator'] : ', ',
      ),
      'suffix' => array(
        '#title' => t('Suffix'),
        '#type' => 'textfield',
        '#description' => t('A textual suffix to the mouse position.'),
        '#default_value' => isset($defaults['suffix']) ? $defaults['suffix'] : '',
      ),
      'numDigits' => array(
        '#title' => t('Number of Decimal Digits'),
        '#type' => 'textfield',
        '#description' => t('Number of decimal digits to show.'),
        '#default_value' => isset($defaults['numDigits']) ? $defaults['numDigits'] : '',
      ),
      'emptyString' => array(
        '#title' => t('Empty Value'),
        '#type' => 'textfield',
        '#description' => t('What will be seen if there is no value for the mouse position.'),
        '#default_value' => isset($defaults['emptyString']) ? $defaults['emptyString'] : '',
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/behaviors/openlayers_behavior_mouseposition.js');
    return $this->options;
  }
}
