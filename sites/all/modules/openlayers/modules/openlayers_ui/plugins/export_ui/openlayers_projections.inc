<?php
/**
 * @file Binds openlayers_projections with ctools
 */

/**
 * @return array
 */
function openlayers_ui_openlayers_projections_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_projections',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'projections',
      // TODO Translation?
      'menu title' => 'Projections',
      // TODO Translation?
      'menu description' => 'Administer OpenLayers projections.',
    ),

    'handler' => array(
      'class' => 'openlayers_projections_ui',
    ),

    'export' => array(
      'key' => 'identifier'
    ),

    // TODO What is this good for?
    'title singular' => t('projections'),
    'title plural' => t('projections'),
    'title singular proper' => t('OpenLayers projection'),
    'title plural proper' => t('OpenLayers projections'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Projection saved.'),
        ),
        'delete' => array(
          'success' => t('Projection was deleted.'),
        )
      )
    ),
  );
}
