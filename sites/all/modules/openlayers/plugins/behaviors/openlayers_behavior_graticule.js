/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Graticule Behavior.  Implements the Graticule Control.
 */
Drupal.openlayers.addBehavior('openlayers_behavior_graticule', function (data, options) {
  Drupal.openlayers.addControl(data.openlayers, 'Graticule', options);
});
