/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

(function ($) {
  /**
   * Map Form Values Behavior
   */
  Drupal.openlayers.addBehavior('openlayers_behavior_mapformvalues', function (data, options) {
    function updateForm(evt) {
      if (evt.object.centerpoint_form) {
        center = evt.object.getCenter().transform(
          evt.object.projection,
          new OpenLayers.Projection('EPSG:4326')).toShortString();
          evt.object.centerpoint_form.val(center);
      }
      if (evt.object.zoom_form) {
        zoom = evt.object.getZoom();
        evt.object.zoom_form.val(zoom);
      }
    }
    centerpoint_form = $(options.center_form);
    zoom_form = $(options.zoom_form);

    if (centerpoint_form.length) {
      data.openlayers.centerpoint_form = centerpoint_form;
      center_point = centerpoint_form.val();
      data.openlayers.setCenter(
        OpenLayers.LonLat.fromString(center_point).transform(
          new OpenLayers.Projection('EPSG:4326'),
          data.openlayers.projection)
        );
    }

    if (zoom_form.length) {
      data.openlayers.zoom_form = zoom_form;
      zoom = zoom_form.val();
      data.openlayers.zoomTo(parseInt(zoom));
    }

    data.openlayers.events.on({'moveend': updateForm});
  });
}(jQuery));
