/**
 * @file
 * Layer handler for GeoJSON layers
 */

/**
 * Openlayer layer handler for KML layer
 */
Drupal.openlayers.layer.geojson = function(title, map, options) {
  var features = null;
  options.projection = new OpenLayers.Projection(options.projection);
  options.styleMap = Drupal.openlayers.getStyleMap(map, options.drupalID);

  // GeoJSON Projection handling
  var geojson_options = {
    'internalProjection': new OpenLayers.Projection(map.projection),
    'externalProjection': options.projection
  };

  // If GeoJSON data is provided with the layer, use that.  Otherwise
  // check if BBOX, then finally use AJAX method.
  if (options.geojson_data) {
    var layer = new OpenLayers.Layer.Vector(title, options);

    // Read data in.
    features = new OpenLayers.Format.GeoJSON(geojson_options).read(options.geojson_data);
    if (features) {
      // If not array (ie only one feature)
      if (features.constructor != Array) {
        features = [features];
      }
    }

    // Add features, if needed
    if (features) {
      layer.addFeatures(features);
      layer.events.triggerEvent('loadend');
    }
  }
  else {
    // @todo Add more strategies. Paging strategy would be really interesting
    //   to use with views_geojson.
    // @see http://dev.openlayers.org/releases/OpenLayers-2.12/doc/apidocs/files/OpenLayers/Strategy/Paging-js.html
    if (options.useBBOX) {
      // BBOX strategy.
      // @see http://dev.openlayers.org/releases/OpenLayers-2.12/doc/apidocs/files/OpenLayers/Strategy/BBOX-js.html
      options.strategies = [ new OpenLayers.Strategy.BBOX(options.resFactor) ];
    }
    else {
      // Fixed strategy.
      // @see http://dev.openlayers.org/releases/OpenLayers-2.12/doc/apidocs/files/OpenLayers/Strategy/Fixed-js.html
      options.strategies = [new OpenLayers.Strategy.Fixed()];
    }
    if(options.useScript){
      //use Script protocol to get around xss issues and 405 error
      options.protocol = new OpenLayers.Protocol.Script({
        url: options.url,
        callbackKey: options.callbackKey,
        callbackPrefix: "callback:",
        filterToParams: function(filter, params) {
         // example to demonstrate BBOX serialization
         if (filter.type === OpenLayers.Filter.Spatial.BBOX) {
           params.bbox = filter.value.toArray();
           if (filter.projection) {
              params.bbox.push(filter.projection.getCode());
            }
          }
          return params;
        }
      });
    }
    else{
      options.protocol = new OpenLayers.Protocol.HTTP({
        url: options.url,
        format: new OpenLayers.Format.GeoJSON()
      });
    }
    var layer = new OpenLayers.Layer.Vector(title, options);
  }

  return layer;
};
