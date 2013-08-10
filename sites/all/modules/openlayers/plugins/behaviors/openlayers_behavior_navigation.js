/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Navigation Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_navigation', function (data, options) {
  options.documentDrag = !!options.documentDrag;
  Drupal.openlayers.addControl(data.openlayers, 'Navigation', options);
});
