<?php

/**
 * @file
 * This file contains styles implementations.
 *
 * @ingroup openlayers
 */

/**
 * Internal callback
 * Helper function to return default styles.
 *
 * @return mixed
 */
function _openlayers_openlayers_styles() {
  $styles = array();

  // Default style
  $style = new stdClass();
  $style->api_version = 1;
  $style->name = 'default';
  $style->title = t('Default style');
  $style->description = t('Basic default style.');
  $style->data = array(
    'pointRadius' => '6',
    'fillColor' => '#888888',
    'strokeColor' => '#222222',
    'strokeWidth' => '4',
    'fillOpacity' => '0.5',
    'strokeOpacity' => '0.7',
  );
  $styles[$style->name] = $style;

  // Hides features
  $style = new stdClass();
  $style->api_version = 1;
  $style->name = 'invisible';
  $style->title = t('Invisible style');
  $style->description = t('Invisible default style.');
  $style->data = array(
    'pointRadius' => '0',
    'strokeWidth' => '0',
    'fillOpacity' => '0'
  );
  $styles[$style->name] = $style;

  // Default select style
  $style = new stdClass();
  $style->api_version = 1;
  $style->name = 'default_select';
  $style->title = t('Default select style');
  $style->description = t('Default style for selected geometries');
  $style->data = array(
    'pointRadius' => '6',
    'fillColor' => '#222222',
    'strokeColor' => '#888888',
    'strokeWidth' => '4',
    'fillOpacity' => '0.7',
    'strokeOpacity' => '0.8',
  );
  $styles[$style->name] = $style;

  // Marker styles
  $markers = array(
    'red' => t('Red'),
    'green' => t('Green'),
    'gold' => t('Gold'),
    'blue' => t('Blue'),
  );
  foreach ($markers as $marker => $color) {
    $style = new stdClass();
    $style->api_version = 1;
    $style->name = 'default_marker_' . $marker;
    $style->title = t('Marker !color', array('!color' => $color));
    $style->description = t('!color marker provided by the OpenLayers module.',
      array('!color' => $color));
    $style->data = array(
      'externalGraphic' => drupal_get_path('module', 'openlayers') .
        '/themes/default_dark/img/marker-' . $marker . '.png',
      'graphicWidth' => 21,
      'graphicHeight' => 25,
      'graphicXOffset' => -10,
      'graphicYOffset' => -25,
    );
    $styles[$style->name] = $style;
  }

  // Custom black markers
  $style = new stdClass();
  $style->api_version = 1;
  $style->name = 'default_marker_black';
  $style->title = t('Marker Black');
  $style->description = t('Black marker provided by the OpenLayers module.');
  $style->data = array(
    'externalGraphic' => drupal_get_path('module', 'openlayers') .
      '/themes/default_dark/markers/marker-black.png',
    'graphicWidth' => 25,
    'graphicHeight' => 41,
    'graphicXOffset' => -12,
    'graphicYOffset' => -41,
  );
  $styles[$style->name] = $style;

  $style = new stdClass();
  $style->api_version = 1;
  $style->name = 'default_marker_black_small';
  $style->title = t('Marker Black Small');
  $style->description = t('Small black marker provided by the OpenLayers module.');
  $style->data = array(
    'externalGraphic' => drupal_get_path('module', 'openlayers') .
      '/themes/default_dark/markers/marker-black-small.png',
    'graphicWidth' => 16,
    'graphicHeight' => 26,
    'graphicXOffset' => -8,
    'graphicYOffset' => -26,
  );
  $styles[$style->name] = $style;

  return $styles;
}
