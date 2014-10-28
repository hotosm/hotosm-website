<?php
/**
 * @file
 * hot_project.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function hot_project_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'project_map';
  $openlayers_maps->title = 'Project Location';
  $openlayers_maps->description = 'preset for project node pages';
  $openlayers_maps->data = array(
    'width' => '250px',
    'height' => '250px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '0,0',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(
        'separator' => '',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => array(
          'project_ol_map_openlayers_1' => 'project_ol_map_openlayers_1',
          'osm_mapnik' => 0,
        ),
        'point_zoom_level' => '3',
        'zoomtolayer_scale' => '1',
      ),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'project_ol_map_openlayers_1' => 'project_ol_map_openlayers_1',
    ),
    'layer_weight' => array(
      'project_ol_map_openlayers_1' => '0',
      'openlayers_kml_example' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'openlayers_kml_example' => '0',
      'project_ol_map_openlayers_1' => '0',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'openlayers_kml_example' => '0',
      'project_ol_map_openlayers_1' => '0',
    ),
    'layer_styles_temporary' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'openlayers_kml_example' => '0',
      'project_ol_map_openlayers_1' => '0',
    ),
    'layer_activated' => array(
      'project_ol_map_openlayers_1' => 0,
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'openlayers_kml_example' => 0,
    ),
    'layer_switcher' => array(
      'project_ol_map_openlayers_1' => 0,
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'openlayers_kml_example' => 0,
    ),
    'projection' => 'EPSG:3857',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['project_map'] = $openlayers_maps;

  return $export;
}
