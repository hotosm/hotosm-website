/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Attribution Behavior.  Implements the Attribution OpenLayers
 * Control.
 */
Drupal.openlayers.addBehavior('openlayers_behavior_attribution', function (data, options) {
  Drupal.openlayers.addControl(data.openlayers, 'Attribution', options);
});
