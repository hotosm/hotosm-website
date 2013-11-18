<?php
/**
 * @file
 *
 * OpenLayers default packaged layers
 */
function _openlayers_test_openlayers_layers() {
  $layers = array();

  // KML example with URL
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'test_kml_url';
  $layer->title = t('KML Test URL');
  $layer->description = t('Testing KML layer via an URL.');
  $layer->data = array(
    'layer_type' => 'openlayers_layer_type_kml',
    'layer_handler' => 'kml',
    'projection' => array('EPSG:4326'),
    'isBaseLayer' => FALSE,
    'vector' => TRUE,
    'method' => 'file',
    'formatOptions' => array(
      'extractStyles' => TRUE,
      'extractTracks' => FALSE,
      'extractAttributes' => TRUE,
    ),
    'url' => url(drupal_get_path('module', 'openlayers_test') . '/data/openlayers_test.kml'),
  );
  $layers[$layer->name] = $layer;

  // GeoJSON example with URL
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'test_geojson_url';
  $layer->title = t('GeoJSON Test URL');
  $layer->description = t('Testing GeoJSON layer via an URL.');
  $layer->data = array(
    'layer_type' => 'openlayers_layer_type_geojson',
    'layer_handler' => 'geojson',
    'projection' => array('EPSG:4326'),
    'isBaseLayer' => FALSE,
    'vector' => TRUE,
    'url' => url(drupal_get_path('module', 'openlayers_test') . '/data/openlayers_test.json'),
  );
  $layers[$layer->name] = $layer;

  // GeoJSON example with direct data
  $layer = new stdClass();
  $layer->api_version = 1;
  $layer->name = 'test_geojson_direct_data';
  $layer->title = t('GeoJSON Test Direct Data');
  $layer->description = t('Testing putting GeoJSON directly in layer.');
  $layer->data = array(
    'layer_type' => 'openlayers_layer_type_geojson',
    'layer_handler' => 'geojson',
    'projection' => array('EPSG:4326'),
    'isBaseLayer' => FALSE,
    'vector' => TRUE,
    'geojson_data' => '
{
    "type": "Feature",
    "properties": {
      "name": "Hello, World",
      "description": "This is a GeoJSON test with data directly in the layer."
    },
    "geometry": {
        "type": "Polygon",
        "coordinates": [
            [
                [
                    -17.578125,
                    -1.0546875
                ],
                [
                    -37.265625,
                    3.1640625
                ],
                [
                    -54.140625,
                    -3.8671875
                ],
                [
                    -48.515625,
                    -20.0390625
                ],
                [
                    -30.9375,
                    -24.9609375
                ],
                [
                    -21.796875,
                    -29.1796875
                ],
                [
                    -23.90625,
                    -36.9140625
                ],
                [
                    -39.375,
                    -42.5390625
                ],
                [
                    -51.328125,
                    -44.6484375
                ],
                [
                    -50.625,
                    -52.3828125
                ],
                [
                    -28.125,
                    -48.8671875
                ],
                [
                    -13.359375,
                    -41.1328125
                ],
                [
                    -11.953125,
                    -24.9609375
                ],
                [
                    -28.125,
                    -15.8203125
                ],
                [
                    -44.296875,
                    -11.6015625
                ],
                [
                    -35.859375,
                    -1.7578125
                ],
                [
                    -23.203125,
                    -9.4921875
                ],
                [
                    -17.578125,
                    -1.0546875
                ]
            ]
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
