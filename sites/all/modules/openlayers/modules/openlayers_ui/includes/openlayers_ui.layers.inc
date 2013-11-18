<?php

/**
 * @file
 * This file holds the functions handling layers in the
 * Openlayers UI.
 *
 * @ingroup openlayers
 */

/**
 * Layer-wide-settings form
 */
function openlayers_ui_layers_settings($form, &$form_state, $layer = NULL) {
  $form = array();

  foreach (openlayers_layer_types() as $name => $type_def) {
    $type = openlayers_layer_type_load($name);
    if ($type->settings_form()) {
      $form[$name] = array(
        '#type' => 'fieldset',
        '#tree' => TRUE,
        '#title' => $type_def['title']
      );
      $form[$name]['settings'] = $type->settings_form();
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Submit handler for openlayers_ui_layers_settings
*/
function openlayers_ui_layers_settings_submit(&$form, &$form_state) {
  $layer_types = openlayers_layer_types();
  foreach ($form_state['values'] as $key => $value) {
    if (in_array($key, array_keys($layer_types))) {
      foreach ($value['settings'] as $k => $v) {
        variable_set($k, $v);
      }
    }
  }
}
