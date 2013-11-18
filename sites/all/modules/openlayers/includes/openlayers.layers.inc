<?php

/**
 * @file
 * This file contains layers implementations.
 *
 * @ingroup openlayers
 */

/**
 * Internal callback
 * Helper function to return default layers.
 *
 * @return mixed
 */
function _openlayers_openlayers_layers() {
  global $is_https;
  $mapquest_host = $is_https ? '-s.mqcdn.com' : '.mqcdn.com';

  $layers = array();

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'google_satellite';
  $layer->title = 'Google Maps Satellite';
  $layer->description = 'Google Maps Satellite Imagery.';
  $layer->data = array(
    'isBaseLayer' => TRUE,
    'type' => 'satellite',
    'projection' => array('EPSG:3857', 'EPSG:900913'),
    'layer_type' => 'openlayers_layer_type_google',
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'google_hybrid';
  $layer->title = 'Google Maps Hybrid';
  $layer->description = 'Google Maps with roads and terrain.';
  $layer->data = array(
    'isBaseLayer' => TRUE,
    'type' => 'hybrid',
    'projection' => array('EPSG:3857', 'EPSG:900913'),
    'layer_type' => 'openlayers_layer_type_google',
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'google_normal';
  $layer->title = 'Google Maps Normal';
  $layer->description = 'Standard Google Maps Roads';
  $layer->data = array(
    'isBaseLayer' => TRUE,
    'type' => 'normal',
    'projection' => array('EPSG:3857', 'EPSG:900913'),
    'layer_type' => 'openlayers_layer_type_google',
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'google_physical';
  $layer->title = 'Google Maps Physical';
  $layer->description = 'Google Maps Hillshades';
  $layer->data = array(
    'isBaseLayer' => TRUE,
    'type' => 'physical',
    'projection' => array('EPSG:3857', 'EPSG:900913'),
    'layer_type' => 'openlayers_layer_type_google',
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'mapquest_osm';
  $layer->title = 'MapQuest OSM';
  $layer->description = 'MapQuest’s rendering of OpenStreetMap.';
  $layer->data = array(
    'isBaseLayer' => TRUE,
    'attribution' => t('&copy;<a href="@ccbysa">CCBYSA</a> ' .
      '<a href="@openstreetmap">&copy; OpenStreetMap contributors</a>',
      array(
        '@openstreetmap' => 'http://www.openstreetmap.org/copyright',
        '@ccbysa' => 'http://creativecommons.org/licenses/by-sa/2.0/',
      )
    ) . '. ' . t('Tiles Courtesy of <a href="http://www.mapquest.com/">MapQuest</a>.'),
    'projection' => array('EPSG:3857', 'EPSG:900913'),
    'layer_type' => 'openlayers_layer_type_xyz',
    'url' => array(
      '//otile1' . $mapquest_host . '/tiles/1.0.0/osm/${z}/${x}/${y}.png',
      '//otile2' . $mapquest_host . '/tiles/1.0.0/osm/${z}/${x}/${y}.png',
      '//otile3' . $mapquest_host . '/tiles/1.0.0/osm/${z}/${x}/${y}.png',
      '//otile4' . $mapquest_host . '/tiles/1.0.0/osm/${z}/${x}/${y}.png',
    ),
    'wrapDateLine' => TRUE,
    'resolutions' => openlayers_get_resolutions('EPSG:900913', 0, 19)
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'mapquest_openaerial';
  $layer->title = 'MapQuest Open Aerial';
  $layer->description = 'MapQuest’s aerial photo map.';
  $layer->data = array(
    'isBaseLayer' => TRUE,
    'attribution' => t('Portions Courtesy NASA/JPL-Caltech and U.S. Depart. of Agriculture, Farm Service Agency.')
      . ' ' . t('Tiles Courtesy of <a href="http://www.mapquest.com/">MapQuest</a>.'),
    'projection' => array('EPSG:3857', 'EPSG:900913'),
    'layer_type' => 'openlayers_layer_type_xyz',
    'url' => array(
      '//oatile1' . $mapquest_host . '/tiles/1.0.0/sat/${z}/${x}/${y}.png',
      '//oatile2' . $mapquest_host . '/tiles/1.0.0/sat/${z}/${x}/${y}.png',
      '//oatile3' . $mapquest_host . '/tiles/1.0.0/sat/${z}/${x}/${y}.png',
      '//oatile4' . $mapquest_host . '/tiles/1.0.0/sat/${z}/${x}/${y}.png'
    ),
    'wrapDateLine' => TRUE,
  );
  $layers[$layer->name] = $layer;

  // Bing Road
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'bing_road';
  $layer->title = 'Bing Road';
  $layer->description = 'Bing Road tiles.';
  $layer->data = array(
    'name' => 'Bing Road',
    'isBaseLayer' => TRUE,
    'type' => 'Road',
    'projection' => array('EPSG:3857'),
    'layer_type' => 'openlayers_layer_type_bing',
  );
  $layers[$layer->name] = $layer;

  // Bing Aerial
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'bing_aerial';
  $layer->title = 'Bing Aerial';
  $layer->description = 'Bing Aerial tiles.';
  $layer->data = array(
    'name' => 'Bing Aerial',
    'isBaseLayer' => TRUE,
    'type' => 'Aerial',
    'projection' => array('EPSG:3857'),
    'layer_type' => 'openlayers_layer_type_bing',
  );
  $layers[$layer->name] = $layer;

  // Bing Hybrid
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'bing_hybrid';
  $layer->title = 'Bing Hybrid';
  $layer->description = 'Bing Hybrid tiles.';
  $layer->data = array(
    'name' => 'Bing Hybrid',
    'isBaseLayer' => TRUE,
    'type' => 'AerialWithLabels',
    'projection' => array('EPSG:3857'),
    'layer_type' => 'openlayers_layer_type_bing',
  );
  $layers[$layer->name] = $layer;

  // OpenStreetMap Mapnik
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'osm_mapnik';
  $layer->title = 'OSM Mapnik';
  $layer->description = 'The main OpenStreetMap map';
  $layer->data = array(
    'isBaseLayer' => TRUE,
    'attribution' => t('&copy;<a href="@ccbysa">CCBYSA</a> ' .
        '<a href="@openstreetmap">&copy; OpenStreetMap contributors</a>',
      array(
        '@openstreetmap' => 'http://www.openstreetmap.org/copyright',
        '@ccbysa' => 'http://creativecommons.org/licenses/by-sa/2.0/',
      )
    ),
    'projection' => array('EPSG:3857'),
    'layer_type' => 'openlayers_layer_type_xyz',
    'url' => 'http://tile.openstreetmap.org/${z}/${x}/${y}.png',
    'wrapDateLine' => TRUE,
  );
  $layers[$layer->name] = $layer;

  // OpenStreetMap Cycling Map
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'osm_cycle';
  $layer->title = 'OSM Cycling Map';
  $layer->description = 'OpenStreetMap with highlighted bike lanes';
  $layer->data = array(
    'isBaseLayer' => TRUE,
    'attribution' => t('&copy;<a href="@ccbysa">CCBYSA</a> ' .
        '<a href="@openstreetmap">&copy; OpenStreetMap contributors</a>',
      array(
        '@openstreetmap' => 'http://www.openstreetmap.org/copyright',
        '@ccbysa' => 'http://creativecommons.org/licenses/by-sa/2.0/',
      )
    ),
    'projection' => array('EPSG:3857'),
    'layer_type' => 'openlayers_layer_type_xyz',
    'url' => '//a.tile.opencyclemap.org/cycle/${z}/${x}/${y}.png',
    'wrapDateLine' => TRUE,
  );
  $layers[$layer->name] = $layer;

  // OpenStreetMap 426 hybrid overlay
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'osm_4326_hybrid';
  $layer->title = 'OSM Overlay';
  $layer->description = 'Semi-transparent hybrid overlay. Projected into
    WSG84 for use on non spherical-mercator maps.';
  $layer->data = array(
    'isBaseLayer' => FALSE,
    'attribution' => t('&copy;<a href="@ccbysa">CCBYSA</a> ' .
        '<a href="@openstreetmap">&copy; OpenStreetMap contributors</a>',
      array(
        '@openstreetmap' => 'http://www.openstreetmap.org/copyright',
        '@ccbysa' => 'http://creativecommons.org/licenses/by-sa/2.0/',
      )
    ),
    'projection' => array('EPSG:4326'),
    'layer_type' => 'openlayers_layer_type_wms',
    'url' => 'http://oam.hypercube.telascience.org/tiles',
    'params' => array(
      'isBaseLayer' => FALSE,
      'layers' => array(
        'osm-4326-hybrid'
      ),
    ),
    'options' => array(
      'buffer' => 1,
    ),
  );
  $layers[$layer->name] = $layer;

  /* Example with KML layer */
  $layer = new stdClass();
  $layer->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $layer->api_version = 1;
  $layer->name = 'openlayers_kml_example';
  $layer->title = 'KML Example Layer';
  $layer->description = 'A simple example of KML Layer Type.';
  $layer->data = array(
    'method' => 'raw',
    'raw' => '<?xml version="1.0" encoding="UTF-8"?><kml xmlns="http://www.opengis.net/kml/2.2"><Placemark><name>Simple placemark</name><description>Attached to the ground. Intelligently places itself at the height of the underlying terrain.</description><Point><coordinates>-122.0822035425683,37.42228990140251,0</coordinates></Point></Placemark></kml>',
    'formatOptions' => array(
      'extractStyles' => TRUE,
      'extractTracks' => FALSE,
      'extractAttributes' => TRUE,
    ),
    'projection' => array(
      'EPSG:4326',
    ),
    'isBaseLayer' => 0,
    'layer_type' => 'openlayers_layer_type_kml',
    'layer_handler' => 'kml',
    'vector' => TRUE,
  );
  $layers[$layer->name] = $layer;

  // MetaCarts base map
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'wms_default';
  $layer->title = 'Default OpenLayers WMS';
  $layer->description = 'MetaCarta basemap of province and water boundaries';
  $layer->data = array(
    'projection' => array('EPSG:4326'),
    'isBaseLayer' => TRUE,
    'layer_type' => 'openlayers_layer_type_wms',
    'base_url' => '//labs.metacarta.com/wms-c/Basic.py',
    'params' => array(
      'isBaseLayer' => TRUE,
    ),
    'options' => array(
      'layers' => array('basic'),
    ),
  );
  $layers[$layer->name] = $layer;

  // GeoJSON example with direct data
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'openlayers_geojson_picture_this';
  $layer->title = t('Example GeoJSON, "Picture This"');
  $layer->description = t('Example that puts GeoJSON directly in layer without Views.');
  $layer->data = array(
    'resolutions' => openlayers_get_resolutions('EPSG:900913'),
    'serverResolutions' => openlayers_get_resolutions('EPSG:4326'),
    'layer_type' => 'openlayers_layer_type_geojson',
    'layer_handler' => 'geojson',
    'projection' => array('EPSG:4326'),
    'isBaseLayer' => FALSE,
    'vector' => TRUE,
    'geojson_data' => '
      {
        "type": "Feature",
        "properties": {
          "name": "' . t('Picture This') . '",
          "description": "' . t('Outside of the North Carolina Museum of Art.') . '"
        },
        "geometry": {
          "type": "Point",
          "coordinates": [
            -78.702798,
            35.809411
          ]
        },
        "crs": {
          "type": "name",
          "properties": {
              "name": "urn:ogc:def:crs:OGC:1.3:CRS84"
          }
        }
      }
    ',
  );
  $layers[$layer->name] = $layer;

  $info = _mapbox_layers_info();
  $resolutions = openlayers_get_resolutions('EPSG:900913');
  $resolutions = array_combine(range(0, count($resolutions)-1), $resolutions);


  foreach ($info as $key => $item) {
    $openlayers_layers = new stdClass;
    $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
    $openlayers_layers->api_version = 1;
    $openlayers_layers->name = $key;
    $openlayers_layers->title = $item['name'];
    $openlayers_layers->description = $item['description'];
    $openlayers_layers->data = array(
      'url' => array(
        0 => 'http://a.tiles.mapbox.com/',
        1 => 'http://b.tiles.mapbox.com/',
        2 => 'http://c.tiles.mapbox.com/',
        3 => 'http://d.tiles.mapbox.com/',
      ),
      'layername' => $item['layername'],
      'layer_type' => 'openlayers_layer_type_tms',
      'osm' => FALSE,
      'isBaseLayer' => TRUE,
      'type' => 'png',
      'resolutions' => array_intersect_key($resolutions, array_flip(range($item['minzoom'], $item['maxzoom']))),
      'projection' => array('EPSG:3857'),
    );
    $layers[$key] = $openlayers_layers;
  }

  return $layers;
}

/**
 * This function is for the po editor to be able to find these strings,
 * since in the codebase they are not in t()'s, because they are later
 * run through t() in the layer loader function
 */
function _openlayers_openlayers_layers_i18n() {
  $translatable_strings = array(
    // titles
    t('Google Maps Satellite'),
    t('Google Maps Hybrid'),
    t('Google Maps Normal'),
    t('Google Maps Physical'),
    t('Bing Road'),
    t('Bing Aerial'),
    t('Bing Hybrid'),
    t('Yahoo Maps Street'),
    t('Yahoo Maps Hybrid'),
    t('Yahoo Maps Satellite'),
    t('OSM Mapnik'),
    t('OSM Cycling Map'),
    t('OSM Overlay'),
    t('Default OpenLayers WMS'),
    // descriptions
    t('Alternative, community-rendered OpenStreetMap'),
    t('Google Maps Hillshades'),
    t('Google Maps Satellite Imagery.'),
    t('Google Maps with roads and terrain.'),
    t('MetaCarta basemap of province and water boundaries'),
    t('OpenStreetMap with highlighted bike lanes'),
    t('Semi-transparent hybrid overlay. Projected into
      WSG84 for use on non spherical-mercator maps.'),
    t('Standard Google Maps Roads'),
    t('The main OpenStreetMap map'),
    t('Bing Road tiles.'),
    t('Bing Aerial tiles.'),
    t('Bing Hybrid tiles.'),
    t('MapQuest’s rendering of OpenStreetMap.'),
    t('MapQuest’s aerial photo map.'),
  );
}

function _mapbox_layers_info() {
  $info = array();
  $info['mapbox_world_bright'] = array(
    'name' => t('MapBox World Bright'),
    'description' => t('MapBox World Bright'),
    'layername' => 'world-bright',
    'minzoom' => 0,
    'maxzoom' => 11,
  );
  $info['mapbox_world_dark'] = array(
    'name' => t('MapBox World Dark'),
    'description' => t('MapBox World Dark'),
    'layername' => 'world-dark',
    'minzoom' => 0,
    'maxzoom' => 11,
  );
  $info['mapbox_world_light'] = array(
    'name' => t('MapBox World Light'),
    'description' => t('MapBox World Light'),
    'layername' => 'world-light',
    'minzoom' => 0,
    'maxzoom' => 11,
  );
  $info['mapbox_world_print'] = array(
    'name' => t('MapBox World Print'),
    'description' => t('MapBox World Print'),
    'layername' => 'world-print',
    'minzoom' => 0,
    'maxzoom' => 9,
  );
  $info['mapbox_world_black'] = array(
    'name' => t('MapBox World Black'),
    'description' => t('MapBox World Black'),
    'layername' => 'world-black',
    'minzoom' => 0,
    'maxzoom' => 11,
  );

  return $info;
}
