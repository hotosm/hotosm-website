
/**
 * OpenLayers PointGrid Layer Handler
 */
Drupal.openlayers.layer.pointgrid = function(title, map, options) {

  return new OpenLayers.Layer.PointGrid({
    name: options.name,
    drupalID: options.drupalID,
    layer_handler: options.layer_handler,
    styleMap: Drupal.openlayers.getStyleMap(map, options.drupalID),
    dx: options.dx,
    dy: options.dy,
    ratio: options.ratio,
    maxFeatures: options.maxFeatures,
    rotation: options.rotation
  });

};
