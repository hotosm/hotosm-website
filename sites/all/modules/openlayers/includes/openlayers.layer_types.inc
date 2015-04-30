<?php

/**
 * @file
 * This file contains layer types implementations.
 *
 * @ingroup openlayers
 */

/**
 * Internal callback
 * Helper function to return default layer types.
 *
 * @return mixed
 */
function _openlayers_openlayers_layer_types() {
  $layer_types['openlayers_layer_type_bing'] = array(
    'title' => t('Bing'),
    'description' => t('Microsoft Bing.')
  );
  $layer_types['openlayers_layer_type_cloudmade'] = array(
    'title' => t('CloudMade'),
    'description' => t('<a href="!url">CloudMade</a> Custom Map', array('!url' => 'http://cloudmade.com/')),
  );
  $layer_types['openlayers_layer_type_dummy'] = array(
    'title' => t('Blank layer'),
    'description' => t('Blank layer. Dummy blank layer to be used as a placeholder for other module (with <code>hook_openlayers_map_preprocess</code> for example).')
  );
  $layer_types['openlayers_layer_type_geojson'] = array(
    'title' => t('GeoJSON'),
    'description' => t('Provides a vector layer based on <a href="!url">GeoJSON</a>.', array('!url' => 'http://geojson.org/')),
  );
  $layer_types['openlayers_layer_type_google'] = array(
    'title' => t('Google'),
    'description' => t('Google Maps API Map'),
  );
  $layer_types['openlayers_layer_type_gpx'] = array(
    'title' => t('GPX'),
    'description' => t('GPX Overlay'),
  );
  $layer_types['openlayers_layer_type_image'] = array(
    'title' => t('Image'),
    'description' => t('Use an image as a layer.'),
  );
  $layer_types['openlayers_layer_type_kml'] = array(
    'title' => t('KML'),
    'description' => t('<a href="!url">KML</a> overlay.', array('!url' => 'http://en.wikipedia.org/wiki/Keyhole_Markup_Language')),
  );
  $layer_types['openlayers_layer_type_maptiler'] = array(
    'title' => t('MapTiler'),
    'description' => t('<a href="!url">MapTiler</a> or GDAL2Tiles', array('!url' => 'http://www.maptiler.org/')),
  );
  $layer_types['openlayers_layer_type_osm'] = array(
    'title' => t('OSM'),
    'description' => t('OpenStreetMap Standard'),
  );
  $layer_types['openlayers_layer_type_pointgrid'] = array(
    'title' => t('PointGrid Layer'),
    'description' => t('A point grid layer dynamically generates a regularly spaced grid of point features.'),
  );
  $layer_types['openlayers_layer_type_raw'] = array(
    'title' => t('Raw'),
    'description' => t('Layer type for raw data input - not meant to be added with the UI.'),
  );
  $layer_types['openlayers_layer_type_tms'] = array(
    'title' => t('TMS'),
    'description' => t('<a href="!url">Tile Map Service</a>', array('!url' => 'http://en.wikipedia.org/wiki/Tile_Map_Service')),
  );
  $layer_types['openlayers_layer_type_wms'] = array(
    'title' => t('WMS'),
    'description' => t('<a href="!url">Web Map Service</a>', array('!url' => 'http://en.wikipedia.org/wiki/Web_Map_Service')),
  );
  $layer_types['openlayers_layer_type_wmts'] = array(
    'title' => t('WMTS'),
    'description' => t('<a href="!url">Web Map Tile Service</a>', array('!url' => 'http://en.wikipedia.org/wiki/Tile_Map_Service')),
  );
  $layer_types['openlayers_layer_type_xyz'] = array(
    'title' => t('XYZ'),
    'description' => t('XYZ layer type.  These are tiles sets usually in the form of {z}/{x}/{y}.png.'),
  );

  foreach ($layer_types as $key => $data) {
    $layer_types[$key]['path'] = drupal_get_path('module', 'openlayers') . '/' . openlayers_ctools_plugin_directory('openlayers', 'layer_types');
    $layer_types[$key]['layer_type'] = array(
      'class' => $key,
      'file' => $key . '.inc',
      'parent' => 'openlayers_layer_type',
    );
  }

  return $layer_types;
}
