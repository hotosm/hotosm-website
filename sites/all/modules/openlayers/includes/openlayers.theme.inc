<?php

/**
 * @file
 * This file holds the theme and preprocess functions for openlayers module
 *
 * @ingroup openlayers
 */

/**
 * Preprocess function for openlayers_map
 */
function openlayers_preprocess_openlayers_map(&$variables, $hook) {
  $map = $variables['map'];

  $map['map_name'] = isset($map['map_name']) ? $map['map_name'] : '';
  $css_map_name = drupal_clean_css_identifier($map['map_name']);

  $links = array();
  if (!empty($map['map_name'])) {
    $links = array(
      '#type' => 'contextual_links',
      '#contextual_links' => array(
        'openlayers' => array(
          'admin/structure/openlayers/maps/list', array($map['map_name']),
        ),
      )
    );
  }

  $variables['links'] = render($links);
  $variables['container']['classes'] = implode(" ", array(
    'contextual-links-region',
    'openlayers-container',
    'openlayers-container-map-' . $css_map_name
  ));
  $variables['container']['width'] = $map['width'];
  $variables['container']['height'] = $map['height'];
  $variables['container']['id'] = 'openlayers-container-' . $map['id'];
  $variables['classes_array'][] = 'openlayers-map-' . $css_map_name;
}


/**
 * Theme function to be able to override styles
 */
function theme_openlayers_styles($args) {
  return $args['styles'];
}
