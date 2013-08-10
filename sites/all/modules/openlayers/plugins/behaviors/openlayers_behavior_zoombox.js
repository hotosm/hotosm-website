/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Zoom Box Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_zoombox', function (data, options) {
  Drupal.openlayers.addControl(data.openlayers, 'ZoomBox');
});
