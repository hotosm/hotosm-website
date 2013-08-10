/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Touch Navigation Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_touch_navigation', function (data, options) {
  options.documentDrag = !!options.documentDrag;
  Drupal.openlayers.addControl(data.openlayers, 'TouchNavigation', options);
});
