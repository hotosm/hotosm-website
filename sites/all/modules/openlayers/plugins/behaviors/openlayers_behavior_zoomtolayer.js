/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * OpenLayers Zoom to Layer Behavior.
 *
 * Zooms to the data extent of the selected layers.
 */
Drupal.openlayers.addBehavior('openlayers_behavior_zoomtolayer', function (data, options) {
  var map = data.openlayers;
  var zoomtolayer_scale = parseInt(options.zoomtolayer_scale, 10);
  var point_zoom_level = parseInt(options.point_zoom_level, 10);

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

  // Combined extent of all layers.
  var fullExtent = undefined;

  // Go through selected layers to get full extent.
  jQuery(layers).each(function(index, layer) {
    accumulate_extent(layer);

    if (layer instanceof OpenLayers.Layer.Vector) {
      // This should not register the handler in case no data is available.
      if (layer.getDataExtent() === null) {
        // Try again to determine the extent after layer has loaded.
        layer.events.register('loadend', layer, handle_loadend_once);
      }
    }
  });
  // Zoom if some data was sychronously loaded.
  show_extent_if_determined();

  /**
   * Handler for loadend event of layer that is still loading.
   */
  function handle_loadend_once(event) {
    var layer = event.object;
    layer.events.unregister('loadend', layer, handle_loadend_once);

    accumulate_extent(layer);
    // Zoom if bound have been determined.
    show_extent_if_determined();
  }

  /**
   * Add data extent of layer to total data extent.
   */
  function accumulate_extent(layer){
    var layerextent = layer.getDataExtent();
    if(fullExtent instanceof OpenLayers.Bounds){
      fullExtent.extend(layerextent);
    } else if(layerextent instanceof OpenLayers.Bounds) {
      fullExtent = layerextent;
    }
  }

  /**
   * Zooms map if bounds are at least partially known.
   */
  function show_extent_if_determined(){
    if(fullExtent instanceof OpenLayers.Bounds){
      if (fullExtent.getWidth()===0 && fullExtent.getHeight()===0) {
        // If extent is a single point,
        // zoom in with point_zoom_level option.
        map.setCenter(fullExtent.getCenterLonLat(), point_zoom_level)
      } else {
        var scaled = fullExtent.scale(zoomtolayer_scale);
        map.zoomToExtent(scaled);
        if(!map.getExtent().contains(scaled)){
          // OpenLayers silently ignores zoom in case the date line would need
          // to be displayed more than once. Move map to where the data is at
          // least.
          map.setCenter(scaled.getCenterLonLat());
        }
      }
    }
  }
});
