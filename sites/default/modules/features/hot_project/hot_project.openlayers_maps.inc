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
    'image_path' => '',
    'css_path' => '',
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
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
      ),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'project_ol_map_openlayers_2',
        'point_zoom_level' => '3',
      ),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'project_ol_map_openlayers_2' => 'project_ol_map_openlayers_2',
    ),
    'layer_styles' => array(
      'project_ol_map_openlayers_2' => 'invisible',
    ),
    'layer_activated' => array(
      'project_ol_map_openlayers_2' => 'project_ol_map_openlayers_2',
    ),
    'layer_switcher' => array(),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['project_map'] = $openlayers_maps;

  return $export;
}
