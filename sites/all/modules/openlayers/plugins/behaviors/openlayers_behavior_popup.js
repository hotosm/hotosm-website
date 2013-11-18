/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Javascript Drupal Theming function for inside of Popups
 *
 * To override
 *
 * @param feature
 *  OpenLayers feature object.
 * @return
 *  Formatted HTML.
 */
Drupal.theme.prototype.openlayersPopup = function(feature) {
  var output = '';

  if (feature.attributes.name) {
    output += '<div class="openlayers-popup openlayers-tooltip-name">' + feature.attributes.name + '</div>';
  }
  if (feature.attributes.description) {
    output += '<div class="openlayers-popup openlayers-tooltip-description">' + feature.attributes.description + '</div>';
  }

  return output;
};

// Make sure the namespace exists
Drupal.openlayers.popup = Drupal.openlayers.popup || {};

/**
 * OpenLayers Popup Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_popup', function (data, options) {
  var map = data.openlayers;
  var layers = [];
  var selectedFeature;

  // For backwards compatiability, if layers is not
  // defined, then include all vector layers
  if (typeof options.layers == 'undefined' || options.layers.length == 0) {
    layers = map.getLayersByClass('OpenLayers.Layer.Vector');
  }
  else {
    for (var i in options.layers) {
      var selectedLayer = map.getLayersBy('drupalID', options.layers[i]);
      if (typeof selectedLayer[0] != 'undefined') {
        layers.push(selectedLayer[0]);
      }
    }
  }

  // if only 1 layer exists, do not add as an array.  Kind of a
  // hack, see https://drupal.org/node/1393460
  if (layers.length == 1) {
    layers = layers[0];
  }

  var popupSelect = new OpenLayers.Control.SelectFeature(layers,
    {
      onSelect: function(feature) {
        // Create FramedCloud popup.
        popup = new OpenLayers.Popup.FramedCloud(
          'popup',
          feature.geometry.getBounds().getCenterLonLat(),
          null,
          Drupal.theme('openlayersPopup', feature),
          null,
          true,
          function(evt) {
            while( map.popups.length ) {
              map.removePopup(map.popups[0]);
              }
            Drupal.openlayers.popup.popupSelect.unselect(selectedFeature);
          }
        );

        // Assign popup to feature and map.
        popup.panMapIfOutOfView = options.panMapIfOutOfView;
        popup.keepInMap = options.keepInMap;
        selectedFeature = feature;
        feature.popup = popup;
        Drupal.attachBehaviors();
        map.addPopup(popup);
      },
      onUnselect: function(feature) {
        map.removePopup(feature.popup);
        feature.popup.destroy();
        feature.popup = null;
        this.unselectAll();
      }
    }
  );

  map.addControl(popupSelect);
  popupSelect.activate();
  Drupal.openlayers.popup.popupSelect = popupSelect;
});
