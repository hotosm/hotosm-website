/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * OpenLayers Zoom to Layer Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_zoomtolayer', function (data, options) {
  var map = data.openlayers;
  var layers = map.getLayersBy('drupalID', {
    test: function(id) {
      for (var i in options.zoomtolayer) {
        if (options.zoomtolayer[i] == id) {
          return true;
        }
      }
      return false;
    }
  });

  // Go through selected layers to get full extent.
  map.fullExtent = new OpenLayers.Bounds();
  for (var i in layers) {
    if (layers[i].features !== undefined) {
      var zoomtolayer_scale = data.map.behaviors['openlayers_behavior_zoomtolayer'].zoomtolayer_scale;
      // For KML layers, we need to wait until layer is loaded.  Ideally
      // we could check for any layer that is loading from an external
      // source, but for now, just check KML
      if (layers[i].layer_handler == 'kml' || layers[i].layer_handler == 'geojson') {
        layers[i].events.register('loadend', layers[i], function() {
          layerextent = layers[i].getDataExtent().scale(zoomtolayer_scale);
          map.fullExtent.extend(layerextent);
          map.zoomToExtent(map.fullExtent);

          // If unable to find width due to single point,
          // zoom in with point_zoom_level option.
          if (layerextent.getWidth() == 0.0) {
            map.zoomTo(options.point_zoom_level);
          }
        });
      }
      else {
        layerextent = layers[i].getDataExtent();
        // Check for valid layer extent
        if (layerextent != null) {
          map.fullExtent.extend(layerextent);
          map.zoomToExtent(map.fullExtent);
        }
      }
    }
  }

  // If unable to find width due to single point,
  // zoom in with point_zoom_level option.
  if (map.fullExtent.getWidth() == 0.0) {
    map.zoomTo(options.point_zoom_level);
  }
  else {
    map.zoomToExtent(map.fullExtent.scale(zoomtolayer_scale));
  }
});
