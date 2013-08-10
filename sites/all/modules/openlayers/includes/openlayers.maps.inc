<?php

/**
 * @file
 * This file contains map implementations
 *
 * @ingroup openlayers
 */

/**
 * Map definitions
 *
 * Internal callback for openlayers map implementation.
 *
 * @return
 *   Array of maps
 */
function _openlayers_openlayers_maps() {
  $items = array();

  // Default map with MapQuest
  $default = new stdClass();
  $default->api_version = 1;
  $default->name = 'default';
  $default->title = t('Default Map');
  $default->description = t('This is the default map that will be the basis for all maps, unless you have changed the !settings.  This is also a good example of a basic map.', array('!settings' => l(t('OpenLayers main settings'), 'admin/structure/openlayers')));
  $default->data = array(
    'projection' => '900913',
    'width' => 'auto',
    'height' => '400px',
    'default_layer' => 'mapquest_osm',
    'center' => array(
      'initial' => array(
        'centerpoint' => '0,0',
        'zoom' => '2'
      )
    ),
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'displayProjection' => '4326',
    'maxExtent' => openlayers_get_extent('4326'),
    'behaviors' => array(
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_layerswitcher' => array(),
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(),
    ),
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
    ),
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $items['default'] = $default;

  // An example Google map
  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE;
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'example_google';
  $openlayers_maps->title = t('Example Google Map');
  $openlayers_maps->description = t('An example map using Google Maps API layers.');
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'center' => array(
      'initial' => array(
        'centerpoint' => '93.339846804269, 17.644019117279',
        'zoom' => '3',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(
        'seperator' => '',
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_permalink' => array(
        'anchor' => 1,
      ),
      'openlayers_behavior_zoompanel' => array(),
    ),
    'default_layer' => 'google_physical',
    'layers' => array(
      'google_satellite' => 'google_satellite',
      'google_hybrid' => 'google_hybrid',
      'google_normal' => 'google_normal',
      'google_physical' => 'google_physical',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $items['default_google'] = $openlayers_maps;

  // Example map with MapQuest and GeoJSON
  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE;
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'example_geojson';
  $openlayers_maps->title = t('Example GeoJSON Map');
  $openlayers_maps->description = t('A simple map with a custom GeoJSON layer with direct data.  Also an example of zooming into a layer.');
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
      'openlayers_behavior_attribution' => array(
        'seperator' => '',
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'openlayers_geojson_picture_this' => 'openlayers_geojson_picture_this',
        ),
      ),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'openlayers_geojson_picture_this',
        'point_zoom_level' => '18',
      ),
    ),
    'default_layer' => 'mapquest_openaerial',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'openlayers_geojson_picture_this' => 'openlayers_geojson_picture_this',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $items["example_geojson"] = $openlayers_maps;

  // Example Virtual Earth map
  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE;
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'example_bing';
  $openlayers_maps->title = t('Example Microsoft Bing Map');
  $openlayers_maps->description = t('This map uses the Microsoft Bing map API.');
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-63.281250000007, -20.46819494553',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(
        'seperator' => '',
      ),
      'openlayers_behavior_fullscreen' => array(
        'activated' => 0,
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoom' => array(),
    ),
    'default_layer' => 'virtualearth_street',
    'layers' => array(
      'bing_road' => 'bing_road',
      'bing_hybrid' => 'bing_hybrid',
      'bing_aerial' => 'bing_aerial',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $items['example_bing'] = $openlayers_maps;

  // Example OpenStreetMap
  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE;
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'example_osm';
  $openlayers_maps->title = 'Example OpenStreetMap Map';
  $openlayers_maps->description = 'Map to show off the OpenStreetMap layers.';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'css_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '-0.093009923589588, 51.500381463117',
        'zoom' => '12',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(
        'seperator' => '',
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_zoompanel' => array(),

      'openlayers_behavior_scaleline' => array(),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'osm_cycle' => 'osm_cycle',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $items["example_osm"] = $openlayers_maps;

  // Backwards compatibilty for features presets.  Since features
  // no longers cares about the preset hooks, we need to manually include
  // the preset file that stores the old hooks.
  $found_features = FALSE;
  if (module_exists('features')) {
    $features = features_get_features();

    foreach ($features as $feature) {
      // Only utilize enabled features and look for presets
      if ($feature->status > 0 && !empty($feature->info['features']['openlayers_map_presets'])) {
        $found_features = TRUE;
        // Include the file we need.
        $presets = $feature->info['features']['openlayers_map_presets'];
        $module = $feature->name;
        $inc = module_load_include('inc', $module, $module . '.openlayers_presets');
      }
    }
  }

  // If features found, we have to explicilty reset the implement
  // cache.  This could be a significant performance hit on a site
  // that has a high number of modules installed.
  if ($found_features) {
    module_implements('openlayers_presets', FALSE, TRUE);
  }

  // Backwards compatibilty for normal presets
  $data = module_invoke_all('openlayers_presets');
  if (count($data) > 0) {
    $items = $items + $data;
  }


  return $items;
}
