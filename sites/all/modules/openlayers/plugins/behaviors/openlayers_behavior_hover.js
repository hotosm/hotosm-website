/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Hover Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_hover', function (data, options) {

  var map = data.openlayers;

  var layers = map.getLayersBy('drupalID', {
    test: function(id) {
      for (var i in options.layers) {
        if (options.layers[i] == id) {
          return true;
        }
      }
      return false;
    }
  });

  jQuery(layers).each(function(index, layer) {

    var highlightCtrl = new OpenLayers.Control.SelectFeature(layer, {
      hover: true,
      highlightOnly: true,
      renderIntent: 'temporary'
    });

    map.addControl(highlightCtrl);
    highlightCtrl.activate();
  });

});
