<?php
/**
 * CTools Export UI required function for plugin definition
 * See function ctools_plugin_load_includes() in the module ctools.
 */
function openlayers_ui_openlayers_layers_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_layers',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'layers',
      'menu title' => 'Layers',
      'menu description' => 'Administer OpenLayers Layers presets.',
    ),

    'handler' => array(
      'class' => 'openlayers_layers_ui',
    ),

    'export' => array(
      'admin_title' => 'name',
      'admin_description' => 'description',
    ),

    'title singular' => t('layer'),
    'title plural' => t('layers'),
    'title singular proper' => t('OpenLayers Layer preset'),
    'title plural proper' => t('OpenLayers Layers presets'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Layer saved.'),
        ),
        'delete' => array(
          'success' => t('Layer was deleted.'),
        )
      )
    ),

    'form' => array(
      'settings' => 'openlayers_layers_ctools_export_ui_form_settings',
      'validate' => 'openlayers_layers_ctools_export_ui_form_validate',
    ),
  );
}

function openlayers_layers_ctools_export_ui_form_settings(&$form, &$form_state) {
  $layer = $form_state['item'];
  if (empty($layer->name)) {
    $layer = NULL;
  }
  else {
    $layer = openlayers_get_layer_object($layer);
  }
  module_load_include('inc', 'openlayers_ui', 'includes/openlayers_ui.layers');
  $form = openlayers_ui_layers_form($form_state, $layer);
}

function openlayers_layers_ctools_export_ui_form_validate(&$form, &$form_state) {
  $values = $form_state['values'];
  if (empty($values['layer_type'])) {
    form_set_error('layer_type', t('Layer type must be set.'));
  }
}
