
/**
 * Process Google Layers
 *
 * @param layerOptions
 *   Object of options.
 * @param map
 *   Reference to OpenLayers object.
 * @return
 *   Valid OpenLayers layer.
 */
Drupal.openlayers.layer.google = function(title, map, options) {
  // if G_ vars exists we're using gmap v2
  var google_type_map = {
    'normal': window['G_NORMAL_MAP'] || null,
    'satellite': window['G_SATELLITE_MAP'] || google.maps.MapTypeId.SATELLITE,
    'hybrid': window['G_HYBRID_MAP'] || google.maps.MapTypeId.HYBRID,
    'physical': window['G_PHYSICAL_MAP'] || google.maps.MapTypeId.TERRAIN
  };

  options.type = google_type_map[options.type];
  options.projection = new OpenLayers.Projection(options.projection);

  return new OpenLayers.Layer.Google(title, options);
};
