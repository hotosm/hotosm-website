/**
 * @file
 * Javascript for OL Styles UI.
 *
 * @ingroup openlayers
 */

// Namespace jQuery
(function ($) {

/**
 * Drupal behaviors for OpenLayers UI form.
 */
Drupal.behaviors.openlayers_ui_styles = {
  'attach': function(context, settings) {
    var maps = {};

    // Go through each preview
    $('.openlayers-ui-style-preview:not(.openlayers-ui-style-preview-processed)').each(function() {
      $thisPreview = $(this);
      $thisPreview.addClass('openlayers-ui-style-preview-processed');
      var id = $thisPreview.attr('id');
      var style = Drupal.settings.openlayers_ui.style_preview[id].data;

      // We want to create a very simple map with a style on
      // top.  There's no need to use the Drupal API for this as we
      // want to keep it lean.
      maps[id] = new OpenLayers.Map(id, { controls: [] });
      var mapquest = new OpenLayers.Layer.OSM(Drupal.t('MapQuest-OSM Tiles'),
        [(location.protocol === 'https:' ? '//otile1-s' : '//otile1') + '.mqcdn.com/tiles/1.0.0/osm/${z}/${x}/${y}.png']);
      maps[id].addLayer(mapquest);
      var point = new OpenLayers.LonLat(Math.random() * 175, Math.random() * 80).transform(
        new OpenLayers.Projection("EPSG:4326"), maps[id].getProjectionObject()
      );
      maps[id].setCenter(point, (Math.floor(Math.random() * 4) + 1));

      // Now add a point with the preview style.
      var feature = new OpenLayers.Feature.Vector(
        new OpenLayers.Geometry.Point(point.lon, point.lat));
      var vector = new OpenLayers.Layer.Vector(Drupal.t('Preview'), {
        styleMap: new OpenLayers.StyleMap(style)
      });
      vector.addFeatures([ feature ]);
      maps[id].addLayer(vector);

      // And finally, lets add a little crosshair so that
      // the user can see how the style is centered.  If it is
      // enabled;
      if (Drupal.settings.openlayers_ui.style_preview[id + '_crosshairs']) {
        $thisPreview.find('.olMapViewport')
          .append('<div class="openlayers-ui-style-preview-top"></div>')
          .append('<div class="openlayers-ui-style-preview-left"></div>');
      }
    });
  }
};

})(jQuery);
