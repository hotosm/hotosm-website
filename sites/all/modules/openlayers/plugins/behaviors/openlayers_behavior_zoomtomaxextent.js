/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Zoom Max Extent Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_zoomtomaxextent', function (data, options) {
  options.allowSelection = options.allowSelection || true;
  var panel = Drupal.openlayers.addControl(data.openlayers, 'Panel', options);

  var button = new OpenLayers.Control.ZoomToMaxExtent();
  panel.addControls([button]);
});
