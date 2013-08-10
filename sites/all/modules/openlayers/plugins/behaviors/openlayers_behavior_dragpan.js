/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * DragPan Behavior.  Implements the DragPan OpenLayers
 * Control.
 */
Drupal.openlayers.addBehavior('openlayers_behavior_dragpan', function (data, options) {
  Drupal.openlayers.addControl(data.openlayers, 'DragPan', options);
});
