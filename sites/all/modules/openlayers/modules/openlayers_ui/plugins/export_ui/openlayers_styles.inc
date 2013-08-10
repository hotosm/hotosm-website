<?php
/**
 * CTools Export UI required function for plugin definition
 * See function ctools_plugin_load_includes() in the module ctools.
 */
function openlayers_ui_openlayers_styles_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_styles',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'styles',
      'menu title' => 'Styles',
      'menu description' => 'Administer OpenLayers Styles presets.',
    ),

    'handler' => array(
      'class' => 'openlayers_styles_ui',
    ),

    'export' => array(
      'admin_title' => 'name',
      'admin_description' => 'description',
    ),

    'title singular' => t('style'),
    'title plural' => t('styles'),
    'title singular proper' => t('OpenLayers Style preset'),
    'title plural proper' => t('OpenLayers Styles presets'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Style saved.'),
        ),
        'delete' => array(
          'success' => t('Style was deleted.'),
        )
      )
    ),

    'form' => array(
      'settings' => 'openlayers_styles_ctools_export_ui_form_settings',
    ),
  );
}

function openlayers_styles_ctools_export_ui_form_settings(&$form, &$form_state) {
  $style = $form_state['item'];
  if (empty($style->name)) {
    $style = NULL;
  }

  module_load_include('inc', 'openlayers_ui', 'includes/openlayers_ui.styles');

  if ($form_state['op'] == 'add') {
    $form = openlayers_ui_styles_form($form, $form_state, $style, FALSE);
  }

  if ($form_state['op'] == 'edit') {
    $form = openlayers_ui_styles_form($form, $form_state, $style, TRUE);
  }
}

