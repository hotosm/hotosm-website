/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * ArgParser Behavior.  Implements the ArgParser OpenLayers
 * Control.
 */
Drupal.openlayers.addBehavior('openlayers_behavior_argparser', function (data, options) {
  Drupal.openlayers.addControl(data.openlayers, 'ArgParser', options);
});
