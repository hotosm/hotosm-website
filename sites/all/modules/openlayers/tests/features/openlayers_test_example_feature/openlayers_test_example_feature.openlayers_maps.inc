<?php
/**
 * @file
 * openlayers_test_example_feature.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function openlayers_test_example_feature_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'openlayers_test_openlayers_example_map';
  $openlayers_maps->title = 'Example Map of Example Content';
  $openlayers_maps->description = 'Example map of OpenLayers Example Content.';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => 'proxy?request=',
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
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_attribution' => array(
        'separator' => '',
      ),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
        'maximizeDefault' => 0,
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoom' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'openlayers_example_data_overlay_openlayers_1' => 'openlayers_example_data_overlay_openlayers_1',
        ),
      ),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'openlayers_example_data_overlay_openlayers_1',
        'point_zoom_level' => '5',
        'zoomtolayer_scale' => '1',
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'openlayers_example_data_overlay_openlayers_1' => 'openlayers_example_data_overlay_openlayers_1',
    ),
    'layer_weight' => array(
      'geo_nodes_data_overlay_openlayers_1' => '0',
      'views_geojson_example_page_1' => '0',
      'openlayers_example_data_overlay_openlayers_1' => '0',
      'test_geojson_direct_data' => '0',
      'test_geojson_url' => '0',
      'openlayers_geojson_picture_this' => '0',
      'test_kml_url' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'test_kml_url' => '0',
      'test_geojson_url' => '0',
      'test_geojson_direct_data' => '0',
      'geo_nodes_data_overlay_openlayers_1' => '0',
      'views_geojson_example_page_1' => '0',
      'openlayers_example_data_overlay_openlayers_1' => 'default_marker_green',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'test_kml_url' => '0',
      'test_geojson_url' => '0',
      'test_geojson_direct_data' => '0',
      'geo_nodes_data_overlay_openlayers_1' => '0',
      'views_geojson_example_page_1' => '0',
      'openlayers_example_data_overlay_openlayers_1' => 'default_marker_gold',
    ),
    'layer_activated' => array(
      'openlayers_example_data_overlay_openlayers_1' => 'openlayers_example_data_overlay_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'test_kml_url' => 0,
      'test_geojson_url' => 0,
      'test_geojson_direct_data' => 0,
      'geo_nodes_data_overlay_openlayers_1' => 0,
      'views_geojson_example_page_1' => 0,
    ),
    'layer_switcher' => array(
      'openlayers_example_data_overlay_openlayers_1' => 'openlayers_example_data_overlay_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'test_kml_url' => 0,
      'test_geojson_url' => 0,
      'test_geojson_direct_data' => 0,
      'geo_nodes_data_overlay_openlayers_1' => 0,
      'views_geojson_example_page_1' => 0,
    ),
    'projection' => 'EPSG:900913',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $export['openlayers_test_openlayers_example_map'] = $openlayers_maps;

  return $export;
}
