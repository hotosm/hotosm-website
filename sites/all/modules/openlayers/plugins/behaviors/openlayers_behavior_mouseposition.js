/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
* Mouse Position Behavior
*/
Drupal.openlayers.addBehavior('openlayers_behavior_mouseposition', function (data, options) {
  Drupal.openlayers.addControl(data.openlayers, 'MousePosition', options);
});
