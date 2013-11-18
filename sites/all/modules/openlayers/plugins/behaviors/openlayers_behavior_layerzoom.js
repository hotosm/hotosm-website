/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * OpenLayers Zoom to Layer Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_layerzoom', function (data, options) {
  var map = data.openlayers;
  for (var layerName in options) {
    if (options[layerName].enable) {
      var layers = map.getLayersBy('drupalID', layerName);
      jQuery(layers).each(function(index, layer){
        // Basically replicate Object.keys because it is not available in IE8.
        var keys = [];
        for(var key in options[layerName].resolutions){
          if(options[layerName].resolutions.hasOwnProperty(key)){
            keys.push(key);
          }
        }
        
        // Restrict zoom level range.
        layer.alwaysInRange = false;
        layer.minResolution = options[layerName].resolutions[keys[keys.length-1]];
        layer.maxResolution = options[layerName].resolutions[keys[0]];
        
        if(layer.getVisibility() && layer.calculateInRange()===false){
          // Ensure layer is redraw if it should be invisible initially due to
          // the resolutions set above.
          layer.setVisibility(false);
          layer.setVisibility(true);
        }
      });
    }
  }
});
