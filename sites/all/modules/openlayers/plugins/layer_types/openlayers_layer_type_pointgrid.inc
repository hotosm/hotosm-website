<?php
/**
 * @file
 * PointGrid Layer Type
 */

/**
 * @file
 * OpenLayers PointGrid Layer Type
 */
class openlayers_layer_type_pointgrid extends openlayers_layer_type {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_handler' => 'pointgrid',
      'vector' => TRUE,
      'dx' => 100,
      'dy' => 100,
      'ratio' => 1.5,
      'maxFeatures' => 250,
      'rotation' => 0
    ) + parent::options_init();
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array(
      'dx' => array(
        '#type' => 'textfield',
        '#title' => t('X-axis point grid spacing'),
        '#default_value' => !empty($this->data['dx']) ? $this->data['dx'] : 100,
        '#maxlength' => 10,
        '#description' => t('Point grid spacing in the x-axis direction (map units).'),
      ),
      'dy' => array(
        '#type' => 'textfield',
        '#title' => t('Y-axis point grid spacing'),
        '#default_value' => !empty($this->data['dy']) ? $this->data['dy'] : 100,
        '#maxlength' => 10,
        '#description' => t('Point grid spacing in the y-axis direction (map units).'),
      ),
      'ratio' => array(
        '#type' => 'textfield',
        '#title' => t('Ratio of the desired grid size to the map viewport size.'),
        '#default_value' => !empty($this->data['ratio']) ? $this->data['ratio'] : 1.5,
        '#maxlength' => 10,
        '#description' => t('Ratio of the desired grid size to the map viewport size.  Default is 1.5.  Larger ratios mean the grid is recalculated less often while panning.  The maxFeatures setting has precedence when determining grid size.'),
      ),
      'maxFeatures' => array(
        '#type' => 'textfield',
        '#title' => t('The maximum number of points to generate in the grid.'),
        '#default_value' => !empty($this->data['maxFeatures']) ? $this->data['maxFeatures'] : 250,
        '#maxlength' => 10,
        '#description' => t('The maximum number of points to generate in the grid.  Default is 250.'),
      ),
      'rotation' => array(
        '#type' => 'textfield',
        '#title' => t('Grid rotation (in degrees clockwise from the positive x-axis).'),
        '#default_value' => !empty($this->data['rotation']) ? $this->data['rotation'] : 0,
        '#maxlength' => 10,
        '#description' => t('Grid rotation (in degrees clockwise from the positive x-axis).  Default is 0.'),
      ),
    );
  }

  function options_form_validate($form, &$form_state) {
    $form_state['data']['dx'] = (int) $form_state['data']['dx'];
    $form_state['data']['dy'] = (int) $form_state['data']['dy'];
    $form_state['data']['ratio'] = (float) $form_state['data']['ratio'];
    $form_state['data']['maxFeatures'] = (int) $form_state['data']['maxFeatures'];
    $form_state['data']['rotation'] = (int) $form_state['data']['rotation'];
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers') .
      '/plugins/layer_types/openlayers_layer_type_pointgrid.js');
  }
}

