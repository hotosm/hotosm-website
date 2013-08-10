/**
 * @file
 * OpenLayers Behavior implementation for clustering.
 */

/**
 * OpenLayers Cluster Behavior.
 */
Drupal.openlayers.addBehavior('openlayers_behavior_cluster', function (data, options) {
  var map = data.openlayers;
  var distance = parseInt(options.distance, 10);
  var threshold = parseInt(options.threshold, 10);
  var layers = [];
  for (var i in options.clusterlayer) {
    var selectedLayer = map.getLayersBy('drupalID', options.clusterlayer[i]);
    if (typeof selectedLayer[0] != 'undefined') {
      layers.push(selectedLayer[0]);
    }
  }

  // Go through chosen layers
  for (var i in layers) {
    var layer = layers[i];
    // Ensure vector layer
    if (layer.CLASS_NAME == 'OpenLayers.Layer.Vector') {
      var cluster = new OpenLayers.Strategy.Cluster(options);
      layer.addOptions({ 'strategies': [cluster] });
      cluster.setLayer(layer);
      cluster.features = layer.features.slice();
      cluster.activate();
      cluster.cluster();
    }
  }
});

/**
 * Override of callback used by 'popup' behaviour to support clusters
 */
Drupal.theme.openlayersPopup = function (feature) {
  if (feature.cluster) {
    var output = '';
    var visited = []; // to keep track of already-visited items
    var classes = [];

    for (var i = 0; i < feature.cluster.length; i++) {
      var pf = feature.cluster[i]; // pseudo-feature
      if (typeof pf.drupalFID != 'undefined') {
        var mapwide_id = feature.layer.drupalID + pf.drupalFID;
        if (mapwide_id in visited) continue;
        visited[mapwide_id] = true;
      }

      classes = ['openlayers-popup', 'openlayers-popup-feature'];
      if (i == 0) {
        classes.push('first');
      }
      if (i == (feature.cluster.length - 1)) {
        classes.push('last');
      }

      output += '<div class="'+classes.join(' ')+'">' +
        Drupal.theme.prototype.openlayersPopup(pf) + '</div>';
    }
    return output;
  }
  else {
    return Drupal.theme.prototype.openlayersPopup(feature);
  }
};
