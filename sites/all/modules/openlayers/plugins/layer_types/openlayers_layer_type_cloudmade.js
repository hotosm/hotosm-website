
/**
 * Process CloudMade Layers
 *
 * @param layerOptions
 *   Object of options.
 * @param map
 *   Reference to OpenLayers object.
 * @return
 *   Valid OpenLayers layer.
 */
Drupal.openlayers.layer.cloudmade = function(title, map, options) {
  return new OpenLayers.Layer.CloudMade(title, options);
};
