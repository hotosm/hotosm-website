/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * ZoomPanel Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_zoompanel', function (data, options) {
  Drupal.openlayers.addControl(data.openlayers, 'ZoomPanel');
});
