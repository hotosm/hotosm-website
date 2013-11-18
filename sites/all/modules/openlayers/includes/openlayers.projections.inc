<?php

/**
 * @file
 * This file contains projections implementations.
 *
 * @ingroup openlayers
 */

/**
 * Internal callback
 * Helper function to return default projections.
 *
 * @return mixed
 */
function _openlayers_openlayers_projections() {
  $projections = array();

  // CH1903+ / LV95
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:2056';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '2056';
  $openlayers_projections->definition = '+proj=somerc +lat_0=46.95240555555556 +lon_0=7.439583333333333 +k_0=1 +x_0=2600000 +y_0=1200000 +ellps=bessel +towgs84=674.374,15.056,405.346,0,0,0,0 +units=m +no_defs';
  $openlayers_projections->projectedextentleft = '2485869.5728';
  $openlayers_projections->projectedextentbottom = '1076443.1884';
  $openlayers_projections->projectedextentright = '2837076.5648';
  $openlayers_projections->projectedextenttop = '1299941.7864';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // Pulkovo 1942(83) / 3-degree Gauß-Krüger zone 4
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:2398';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '2398';
  $openlayers_projections->definition = '+proj=tmerc +lat_0=0 +lon_0=12 +k=1 +x_0=4500000 +y_0=0 +ellps=krass +towgs84=24,-123,-94,0.02,-0.25,-0.13,1.1 +units=m +no_defs';
  $openlayers_projections->projectedextentleft = '4390150.9946';
  $openlayers_projections->projectedextentbottom = '5419736.8531';
  $openlayers_projections->projectedextentright = '4610103.4021';
  $openlayers_projections->projectedextenttop = '6067242.1812';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // Pulkovo 1942(83) / 3-degree Gauß-Krüger zone 5
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:2399';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '2399';
  $openlayers_projections->definition = '+proj=tmerc +lat_0=0 +lon_0=15 +k=1 +x_0=5500000 +y_0=0 +ellps=krass +towgs84=24,-123,-94,0.02,-0.25,-0.13,1.1 +units=m +no_defs';
  $openlayers_projections->projectedextentleft = '5384982.9245';
  $openlayers_projections->projectedextentbottom = '5152896.3049';
  $openlayers_projections->projectedextentright = '5615270.6353';
  $openlayers_projections->projectedextenttop = '6053880.2778';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // Former EPSG:900913
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:3857';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '3857';
  $openlayers_projections->definition = '+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +wktext  +no_defs';
  $openlayers_projections->projectedextentleft = '-20037508.34';
  $openlayers_projections->projectedextentbottom = '-20037508.34';
  $openlayers_projections->projectedextentright = '20037508.34';
  $openlayers_projections->projectedextenttop = '20037508.34';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // ETRS89
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:4258';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '4258';
  $openlayers_projections->definition = '+proj=longlat +ellps=GRS80 +no_defs';
  $openlayers_projections->projectedextentleft = '-10.6700';
  $openlayers_projections->projectedextentbottom = '34.5000';
  $openlayers_projections->projectedextentright = '31.5500';
  $openlayers_projections->projectedextenttop = '71.0500';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:4326';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '4326';
  $openlayers_projections->definition = '+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs';
  $openlayers_projections->projectedextentleft = '-180';
  $openlayers_projections->projectedextentbottom = '-90';
  $openlayers_projections->projectedextentright = '180';
  $openlayers_projections->projectedextenttop = '90';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // CH1903 / LV03
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:21781';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '21781';
  // Warning: Conversions without grid shift file yield errors of up to 2.5m
  $openlayers_projections->definition = '+proj=somerc +lat_0=46.95240555555556 +lon_0=7.439583333333333 +k_0=1 +x_0=600000 +y_0=200000 +ellps=bessel +towgs84=674.374,15.056,405.346,0,0,0,0 +units=m +no_defs';
  $openlayers_projections->projectedextentleft = '485869.5728';
  $openlayers_projections->projectedextentbottom = '76443.1884';
  $openlayers_projections->projectedextentright = '837076.5648';
  $openlayers_projections->projectedextenttop = '299941.7864';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // ETRS89 / UTM zone 32N
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:25832';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '25832';
  $openlayers_projections->definition = '+proj=utm +zone=32 +ellps=GRS80 +units=m +no_defs';
  $openlayers_projections->projectedextentleft = '265948.8191';
  $openlayers_projections->projectedextentbottom = '6421521.2254';
  $openlayers_projections->projectedextentright = '677786.3629';
  $openlayers_projections->projectedextenttop = '7288831.7014';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // ETRS89 / UTM zone 33N
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:25833';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '25833';
  $openlayers_projections->definition = '+proj=utm +zone=33 +ellps=GRS80 +units=m +no_defs';
  $openlayers_projections->projectedextentleft = '227879.8880';
  $openlayers_projections->projectedextentbottom = '3932632.6543';
  $openlayers_projections->projectedextentright = '1044484.3835';
  $openlayers_projections->projectedextenttop = '8893131.0281';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // OSGB 1936 / British National Grid
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:27700';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '27700';
  $openlayers_projections->definition = '+proj=tmerc +lat_0=49 +lon_0=-2 +k=0.9996012717 +x_0=400000 +y_0=-100000 +ellps=airy +datum=OSGB36 +units=m +no_defs';
  $openlayers_projections->projectedextentleft = '1393.0196';
  $openlayers_projections->projectedextentbottom = '13494.9764';
  $openlayers_projections->projectedextentright = '671196.3657';
  $openlayers_projections->projectedextenttop = '1230275.0454';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // DHDN / 3-degree Gauß-Krüger zone 2
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:31466';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '31466';
  $openlayers_projections->definition = '+proj=tmerc +lat_0=0 +lon_0=6 +k=1 +x_0=2500000 +y_0=0 +ellps=bessel +datum=potsdam +units=m +no_defs';
  $openlayers_projections->projectedextentleft = '2490547.1867';
  $openlayers_projections->projectedextentbottom = '5440321.7879';
  $openlayers_projections->projectedextentright = '2609576.6008';
  $openlayers_projections->projectedextenttop = '5958700.0208';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // DHDN / 3-degree Gauß-Krüger zone 3
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:31467';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '31467';
  $openlayers_projections->definition = '+proj=tmerc +lat_0=0 +lon_0=9 +k=1 +x_0=3500000 +y_0=0 +ellps=bessel +datum=potsdam +units=m +no_defs';
  $openlayers_projections->projectedextentleft = '3386564.9400';
  $openlayers_projections->projectedextentbottom = '5237917.9109';
  $openlayers_projections->projectedextentright = '3613579.2251';
  $openlayers_projections->projectedextenttop = '6104500.7393';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // DHDN / 3-degree Gauß-Krüger zone 4
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:31468';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '31468';
  $openlayers_projections->definition = '+proj=tmerc +lat_0=0 +lon_0=12 +k=1 +x_0=4500000 +y_0=0 +ellps=bessel +datum=potsdam +units=m +no_defs';
  $openlayers_projections->projectedextentleft = '4386596.4101';
  $openlayers_projections->projectedextentbottom = '5237914.5325';
  $openlayers_projections->projectedextentright = '4613610.5843';
  $openlayers_projections->projectedextenttop = '6104496.9694';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // DHDN / 3-degree Gauß-Krüger zone 5
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:31469';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '31469';
  $openlayers_projections->definition = '+proj=tmerc +lat_0=0 +lon_0=15 +k=1 +x_0=5500000 +y_0=0 +ellps=bessel +datum=potsdam +units=m +no_defs';
  $openlayers_projections->projectedextentleft = '5386627.6162';
  $openlayers_projections->projectedextentbottom = '5237909.9506';
  $openlayers_projections->projectedextentright = '5613641.6401';
  $openlayers_projections->projectedextenttop = '6104491.8566';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  // TODO Remove before publishing as replaced by EPSG:3857
  $openlayers_projections = new stdClass();
  $openlayers_projections->disabled = FALSE; /* Edit this to true to make a default openlayers_projections disabled initially */
  $openlayers_projections->api_version = 1;
  $openlayers_projections->identifier = 'EPSG:900913';
  $openlayers_projections->authority = 'EPSG';
  $openlayers_projections->code = '900913';
  $openlayers_projections->definition = '+proj=merc +a=6378137 +b=6378137 +lat_ts=0.0 +lon_0=0.0 +x_0=0.0 +y_0=0 +k=1.0 +units=m +nadgrids=@null +wktext  +no_defs';
  $openlayers_projections->projectedextentleft = '-20037508.34';
  $openlayers_projections->projectedextentbottom = '-20037508.34';
  $openlayers_projections->projectedextentright = '20037508.34';
  $openlayers_projections->projectedextenttop = '20037508.34';
  $openlayers_projections->data = '';
  $projections[$openlayers_projections->identifier] = $openlayers_projections;

  return $projections;
}
