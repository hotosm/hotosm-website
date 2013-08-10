/**
 * @file
 * Layer handler for KML layers
 */

/**
 * Openlayer layer handler for KML layer
 */
(function($) {

Drupal.openlayers.layer.kml = function(title, map, options) {

  var features = null;
  options.projection = 'EPSG:' + options.projection;
  options.styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);
  var layer = new OpenLayers.Layer.Vector(title, options);

  // KML Projection handling and formating options
  var kml_options = options.formatOptions;
  kml_options.internalProjection = new OpenLayers.Projection('EPSG:' + map.projection);
  kml_options.externalProjection = new OpenLayers.Projection(options.projection);

  // Use an AJAX like call to get data from URL
  OpenLayers.Request.GET({
    url: options.url,
    callback: function (response) {
      var format = new OpenLayers.Format.KML(kml_options);
      var features = format.read(response.responseText);
      // Add features, if needed
      if (features) {
        layer.addFeatures(features);
        layer.events.triggerEvent('loadend');
      }
    }
  });

  // Extend options with a Fixed strategy fo getting from URL.
  //
  // This seems a bit more natural but does not
  // seem to work.
  /*
  var layer = new OpenLayers.Layer.Vector(
    title,
    $.extend(options, {
    strategies: [new OpenLayers.Strategy.Fixed()],
    protocol: new OpenLayers.Protocol.HTTP({
        url: options.url,
        format: new OpenLayers.Format.KML(
          options.formatOptions
        )
      })
    })
  );
  */

  return layer;
};

})(jQuery);
