<?php
/**
 * CTools Export UI required function for plugin definition
 * See function ctools_plugin_load_includes() in the module ctools.
 */
function openlayers_ui_openlayers_maps_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_maps',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'maps',
      'menu title' => 'Maps',
      'menu description' => 'Administer OpenLayers Maps presets.',
    ),

    'handler' => array(
      'class' => 'openlayers_maps_ui'
    ),

    'export' => array(
      'admin_title' => 'name',
      'admin_description' => 'description',
    ),

    'title singular' => t('map'),
    'title plural' => t('maps'),
    'title singular proper' => t('Openlayers Map preset'),
    'title plural proper' => t('Openlayers Maps presets'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Map saved.'),
        ),
        'delete' => array(
          'success' => t('Map was deleted.'),
        )
      )
    ),

    'form' => array(
      'settings' => 'openlayers_maps_ctools_export_ui_form_settings',
      'validate' => 'openlayers_maps_ctools_export_ui_form_validate',
    ),
  );
}

function openlayers_maps_ctools_export_ui_form_settings(&$form, &$form_state) {
  $map = $form_state['item'];
  if (empty($map->name)) {
    $map = NULL;
  }

  module_load_include('inc', 'openlayers_ui', 'includes/openlayers_ui.maps');

  if ($form_state['op'] == 'add') {
    $form = openlayers_ui_maps_form($form, $form_state, $map, FALSE);
  }

  if ($form_state['op'] == 'edit') {
    $form = openlayers_ui_maps_form($form, $form_state, $map, TRUE);
  }
}

function openlayers_maps_ctools_export_ui_form_validate($form, $form_state) {

}
