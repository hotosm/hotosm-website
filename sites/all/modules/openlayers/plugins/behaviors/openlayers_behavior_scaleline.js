/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Scale Line Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_scaleline', function (data, options) {
  Drupal.openlayers.addControl(data.openlayers, 'ScaleLine');
});
