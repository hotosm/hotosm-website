/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Permalink Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_permalink', function (data, options) {
  Drupal.openlayers.addControl(data.openlayers, 'Permalink', options);
});
