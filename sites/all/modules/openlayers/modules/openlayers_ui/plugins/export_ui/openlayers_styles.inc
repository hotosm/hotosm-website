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
  );
}
