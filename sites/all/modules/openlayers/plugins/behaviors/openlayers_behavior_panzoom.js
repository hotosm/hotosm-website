/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Pan Zoom Bar Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_panzoom', function (data, options) {
  Drupal.openlayers.addControl(data.openlayers, 'PanZoom');
});
