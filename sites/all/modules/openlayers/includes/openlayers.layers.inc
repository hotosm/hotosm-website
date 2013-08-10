<?php

/**
 * @file
 *
 * OpenLayers default packaged layers
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
    'baselayer' => TRUE,
    'type' => 'satellite',
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_google',
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'google_hybrid';
  $layer->title = 'Google Maps Hybrid';
  $layer->description = 'Google Maps with roads and terrain.';
  $layer->data = array(
    'baselayer' => TRUE,
    'type' => 'hybrid',
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_google',
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'google_normal';
  $layer->title = 'Google Maps Normal';
  $layer->description = 'Standard Google Maps Roads';
  $layer->data = array(
    'baselayer' => TRUE,
    'type' => 'normal',
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_google',
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'google_physical';
  $layer->title = 'Google Maps Physical';
  $layer->description = 'Google Maps Hillshades';
  $layer->data = array(
    'baselayer' => TRUE,
    'type' => 'physical',
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_google',
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'mapquest_osm';
  $layer->title = 'MapQuest OSM';
  $layer->description = 'MapQuest’s rendering of OpenStreetMap.';
  $layer->data = array(
    'baselayer' => TRUE,
    'attribution' => t('&copy;<a href="@ccbysa">CCBYSA</a> '.
      '<a href="@openstreetmap">&copy; OpenStreetMap contributors</a>',
      array(
        '@openstreetmap' => 'http://www.openstreetmap.org/copyright',
        '@ccbysa' => 'http://creativecommons.org/licenses/by-sa/2.0/',
      )
    ) . '. '. t('Tiles Courtesy of <a href="http://www.mapquest.com/">MapQuest</a>.'),
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_xyz',
    'url' => array(
      '//otile1' . $mapquest_host . '/tiles/1.0.0/osm/${z}/${x}/${y}.png',
      '//otile2' . $mapquest_host . '/tiles/1.0.0/osm/${z}/${x}/${y}.png',
      '//otile3' . $mapquest_host . '/tiles/1.0.0/osm/${z}/${x}/${y}.png',
      '//otile4' . $mapquest_host . '/tiles/1.0.0/osm/${z}/${x}/${y}.png',
    ),
    'wrapDateLine' => TRUE,
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'mapquest_openaerial';
  $layer->title = 'MapQuest Open Aerial';
  $layer->description = 'MapQuest’s aerial photo map.';
  $layer->data = array(
    'baselayer' => TRUE,
    'attribution' => t('Portions Courtesy NASA/JPL-Caltech and U.S. Depart. of Agriculture, Farm Service Agency.')
      . ' '. t('Tiles Courtesy of <a href="http://www.mapquest.com/">MapQuest</a>.'),
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_xyz',
    'url' => array(
      '//oatile1' . $mapquest_host . '/naip/${z}/${x}/${y}.png',
      '//oatile2' . $mapquest_host . '/naip/${z}/${x}/${y}.png',
      '//oatile3' . $mapquest_host . '/naip/${z}/${x}/${y}.png',
      '//oatile4' . $mapquest_host . '/naip/${z}/${x}/${y}.png',
    ),
    'wrapDateLine' => TRUE,
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'yahoo_satellite';
  $layer->title = 'Yahoo Maps Satellite';
  $layer->description = 'Yahoo satellite imagery tiles.';
  $layer->data = array(
    'baselayer' => TRUE,
    'type' => 'satellite',
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_yahoo',
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'yahoo_street';
  $layer->title = 'Yahoo Maps Street';
  $layer->description = 'Yahoo streets tiles.';
  $layer->data = array(
    'baselayer' => TRUE,
    'type' => 'street',
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_yahoo',
  );
  $layers[$layer->name] = $layer;

  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'yahoo_hybrid';
  $layer->title = 'Yahoo Maps Hybrid';
  $layer->description = 'Yahoo hybrid of streets and satellite tiles.';
  $layer->data = array(
    'baselayer' => TRUE,
    'type' => 'hybrid',
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_yahoo',
  );
  $layers[$layer->name] = $layer;

  // Bing Road
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'bing_road';
  $layer->title = 'Bing Road';
  $layer->description = 'Bing Road tiles.';
  $layer->data = array(
    'baselayer' => TRUE,
    'type' => 'Road',
    'projection' => array('900913'),
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
    'baselayer' => TRUE,
    'type' => 'Aerial',
    'projection' => array('900913'),
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
    'baselayer' => TRUE,
    'type' => 'AerialWithLabels',
    'projection' => array('900913'),
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
    'baselayer' => TRUE,
    'attribution' => t('&copy;<a href="@ccbysa">CCBYSA</a> '.
        '<a href="@openstreetmap">&copy; OpenStreetMap contributors</a>',
      array(
        '@openstreetmap' => 'http://www.openstreetmap.org/copyright',
        '@ccbysa' => 'http://creativecommons.org/licenses/by-sa/2.0/',
      )
    ),
    'projection' => array('900913'),
    'layer_type' => 'openlayers_layer_type_xyz',
    'url' => '//tile.openstreetmap.org/${z}/${x}/${y}.png',
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
    'baselayer' => TRUE,
    'attribution' => t('&copy;<a href="@ccbysa">CCBYSA</a> '.
        '<a href="@openstreetmap">&copy; OpenStreetMap contributors</a>',
      array(
        '@openstreetmap' => 'http://www.openstreetmap.org/copyright',
        '@ccbysa' => 'http://creativecommons.org/licenses/by-sa/2.0/',
      )
    ),
    'projection' => array('900913'),
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
    'baselayer' => FALSE,
    'attribution' => t('&copy;<a href="@ccbysa">CCBYSA</a> '.
        '<a href="@openstreetmap">&copy; OpenStreetMap contributors</a>',
      array(
        '@openstreetmap' => 'http://www.openstreetmap.org/copyright',
        '@ccbysa' => 'http://creativecommons.org/licenses/by-sa/2.0/',
      )
    ),
    'projection' => array('4326'),
    'layer_type' => 'openlayers_layer_type_wms',
    'url' => 'http://oam.hypercube.telascience.org/tiles',
    'params' => array(
      'isBaseLayer' => FALSE,
      'layers' => 'osm-4326-hybrid',
    ),
    'options' => array(
      'buffer' => 1,
    ),
  );
  $layers[$layer->name] = $layer;

  // MetaCarts base map
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'wms_default';
  $layer->title = 'Default OpenLayers WMS';
  $layer->description = 'MetaCarta basemap of province and water boundaries';
  $layer->data = array(
    'projection' => array('4326'),
    'baselayer' => TRUE,
    'layer_type' => 'openlayers_layer_type_wms',
    'base_url' => '//labs.metacarta.com/wms-c/Basic.py',
    'params' => array(
      'isBaseLayer' => TRUE,
    ),
    'options' => array(
      'layers' => array('basic'),
      'maxExtent' => openlayers_get_extent('4326'),
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
    'layer_type' => 'openlayers_layer_type_geojson',
    'layer_handler' => 'geojson',
    'projection' => array('4326'),
    'baselayer' => FALSE,
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
    t('Yahoo hybrid of streets and satellite tiles.'),
    t('Yahoo satellite imagery tiles.'),
    t('Yahoo streets tiles.'),
    t('MapQuest’s rendering of OpenStreetMap.'),
    t('MapQuest’s aerial photo map.'),
  );
}
