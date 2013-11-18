<?php

/**
 * @file
 * Holds testing maps
 */

/**
 * Separated implementation of hook_openlayers_maps().
 */
function _openlayers_test_openlayers_maps() {
  $items = array();

  // Map with some behaviors
  $behaviors_test = new stdClass();
  $behaviors_test->api_version = 1;
  $behaviors_test->name = 'behaviors_test';
  $behaviors_test->title = t('Test: Behaviors');
  $behaviors_test->description = t('This is a test map.');
  $behaviors_test->data = array(
    'projection' => 'EPSG:900913',
    'displayProjection' => 'EPSG:4326',
    'width' => 'auto',
    'default_layer' => 'osm_mapnik',
    'height' => '400px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'center' => array(
      'initial' => array(
        'centerpoint' => '0,0',
        'zoom' => '2'
      )
    ),
    'behaviors' => array(
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_layerswitcher' => array(),
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(),
      'openlayers_behavior_fullscreen' => array(),
      'openlayers_behavior_mouseposition' => array(),
      'openlayers_behavior_dragpan' => array(),
      'openlayers_behavior_boxselect' => array(),
      'openlayers_behavior_permalink' => array(),
      'openlayers_behavior_scaleline' => array(),
      'openlayers_behavior_zoombox' => array(),
      'openlayers_behavior_zoomtomaxextent' => array(),
    ),
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
    )
  );
  $items['behaviors_test'] = $behaviors_test;

  // Map integrating a Views overlay
  $openlayers_maps_cck_views = new stdClass;
  $openlayers_maps_cck_views->api_version = 1;
  $openlayers_maps_cck_views->name = 'openlayers_test_map_cck_views';
  $openlayers_maps_cck_views->title = 'Test: OpenLayers Test Views';
  $openlayers_maps_cck_views->description = 'This map tests a custom content type with a WKT field and a views layer.';
  $openlayers_maps_cck_views->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
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
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(),
      'openlayers_behavior_navigation' => array(),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_popup' => array(),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'openlayers_test_view_openlayers_1' => 'openlayers_test_view_openlayers_1',
    ),
    'layer_styles' => array(),
    'layer_activated' => array(
      'openlayers_test_view_openlayers_1' => 'openlayers_test_view_openlayers_1',
    ),
    'layer_switcher' => array(
      'openlayers_test_view_openlayers_1' => 'openlayers_test_view_openlayers_1',
    ),
    'projection' => 'EPSG:900913',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
    'options' => NULL,
  );

  // GeoJSON example
  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE;
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'geojson';
  $openlayers_maps->title = 'Test: Using GeoJSON';
  $openlayers_maps->description = 'This map uses direct data in a GeoJSON layer, as well as a URL based GeoJSON layer.';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
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
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'test_geojson_direct_data' => 'test_geojson_direct_data',
          'test_geojson_url' => 'test_geojson_url',
        ),
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'test_geojson_direct_data' => 'test_geojson_direct_data',
      'test_geojson_url' => 'test_geojson_url',
    ),
    'layer_styles' => array(
      'test_geojson_direct_data' => 'default',
      'test_geojson_url' => 'default_marker_blue',
    ),
    'layer_styles_select' => array(
      'test_geojson_direct_data' => 'default_select',
      'test_geojson_url' => 'default_marker_green',
    ),
    'projection' => 'EPSG:900913',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $items[$openlayers_maps->name] = $openlayers_maps;

  // GeoJSON example
  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE;
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'kml';
  $openlayers_maps->title = 'Test: Using KML';
  $openlayers_maps->description = 'This map uses a KML feed.';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'center' => array(
      'initial' => array(
        'centerpoint' => '-122.08452530529, 37.421872987049',
        'zoom' => '17',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'test_geojson_direct_data' => 'test_kml_url',
        ),
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'test_kml_url' => 'test_kml_url',
    ),
    'layer_styles' => array(
      'test_kml_url' => 'default',
    ),
    'layer_styles_select' => array(
      'test_kml_url' => 'default_select',
    ),
    'projection' => 'EPSG:900913',
    'displayProjection' => 'EPSG:4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $items[$openlayers_maps->name] = $openlayers_maps;

  // We only want to provide the Views/CCK map if the
  // modules are installed and the view is provide
  if (module_exists('content') && module_exists('views') && module_exists('content_copy')) {
    $layers = openlayers_layers_load();
    if (!empty($layers['openlayers_test_view_openlayers_1'])) {
      $items['openlayers_test_map_cck_views'] = $openlayers_maps_cck_views;
    }
  }

  // Return maps
  return $items;
}
