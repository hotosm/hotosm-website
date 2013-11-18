/**
 * @file
 * Layer handler for KML layers
 */

/**
 * Openlayer layer handler for GPX layer
 */
Drupal.openlayers.layer.gpx = function(title, map, options) {
  return new OpenLayers.Layer.Vector(title, {
    drupalID: options.drupalID,
    strategies: [new OpenLayers.Strategy.Fixed()],
    protocol: new OpenLayers.Protocol.HTTP({
      url: options.url,
      format: new OpenLayers.Format.GPX(options.formatOptions)
    }),
    styleMap: Drupal.openlayers.getStyleMap(map, options.drupalID),
    projection: new OpenLayers.Projection("EPSG:4326")
  });
};
