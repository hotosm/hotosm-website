
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
  var styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);

  options.sphericalMercator = true;
  options.projection = "EPSG:900913";
  options.maxExtent = new OpenLayers.Bounds(-20037508.34, -20037508.34, 20037508.34, 20037508.34);

  var layer = new OpenLayers.Layer.Bing(options);
  layer.styleMap = styleMap;
  return layer;
};
