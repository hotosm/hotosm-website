/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

// Not the best, but gets around scoping;
var selections_layer;

/**
 * Box Select Behavior.  Allows user to select a bounding box.
 *
 * TODO: This is currently hard coded for the center UI form.
 */
Drupal.openlayers.addBehavior('openlayers_behavior_boxselect', function (data, options) {
  // Callback to set extent into a specific form item.
  function setRestrictedExtent(box) {
    var bounding_box = box.geometry.getBounds().toBBOX();
    jQuery('#edit-center-restrict-restrictedextent').val(bounding_box);

    // Check box
    if (!(jQuery('#restrictextent').attr('checked'))) {
      jQuery('#restrictextent')
        .attr('checked', 'checked')
        .trigger('change');
    }

    // Remove any other features.
    jQuery(selections_layer.features).each(function(index, feature) {
      if (feature != box) {
        selections_layer.features[index].destroy();
      }
    });
  }

  // Create layer to draw with and handle events.
  var selections_layer = new OpenLayers.Layer.Vector('Temporary Box Layer');
  var control = new OpenLayers.Control.DrawFeature(selections_layer,
    OpenLayers.Handler.RegularPolygon, {
      featureAdded: setRestrictedExtent
    }
  );
  control.handler.setOptions({
    'keyMask': OpenLayers.Handler.MOD_SHIFT,
    'sides': 4,
    'irregular': true
  });
  control.events.on({'featureAdded': this.setRestrictedExtent});
  data.openlayers.addLayer(selections_layer);
  data.openlayers.addControl(control);

  // If there already is a value, then update the map appropriately.
  if (jQuery('#edit-center-restrict-restrictedextent').val()) {
    bounds = jQuery('#edit-center-restrict-restrictedextent').val();
    geometry = new OpenLayers.Bounds.fromString(bounds).toGeometry();
    feature = new OpenLayers.Feature.Vector(geometry);
    selections_layer.addFeatures([feature]);
  }
  control.activate();
});
