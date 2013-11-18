
/**
 * Process MS Bing Layers
 *
 * @param layerOptions
 *   Object of options.
 * @param mapid
 *   Map ID.
 * @return
 *   Valid OpenLayers layer.
 */
Drupal.openlayers.layer.bing = function(title, map, options) {
  options.projection = new OpenLayers.Projection(options.projection);
  return new OpenLayers.Layer.Bing(options);
};
