/**
 * OpenLayers Image Layer Handler
 */
Drupal.openlayers.layer.image = function(title, map, options) {
  var maxExtent;
  if (options.maxExtent === null) {
    // Stretch image to cover whole map if not specified.
    maxExtent = map.maxExtent;
  } else {
    maxExtent = options.maxExtent;
  }

  return new OpenLayers.Layer.Image(
    title,
    options.file,
    OpenLayers.Bounds.fromArray(maxExtent),
    new OpenLayers.Size(options.size.w/options.factors.x, options.size.h/options.factors.y),
    {
      drupalID: options.drupalID,
      numZoomLevels: options.numZoomLevels,
      opacity: options.opacity,
      projection: new OpenLayers.Projection(options.projection),
      transitionEffect: options.transitionEffect,
      isBaseLayer: options.isBaseLayer,
      attribution: options.attribution
    }
  );
};
