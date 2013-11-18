
/**
 * @file
 * Layer handler for TMS layers
 */

/**
 * Openlayer layer handler for TMS layer
 */
Drupal.openlayers.layer.maptiler = function(title, map, options) {
  if (OpenLayers.Util.isArray(options.maxExtent)) {
    options.maxExtent = OpenLayers.Bounds.fromArray(options.maxExtent);
  }

  options.getURL = function(bounds) {
    var res = this.map.getResolution();
    var x = Math.round((bounds.left - this.maxExtent.left) / (res * this.tileSize.w));
    var y = Math.round((bounds.bottom - this.tileOrigin.lat) / (res * this.tileSize.h));
    var z = this.map.getZoom();
    if (x >= 0 && y >= 0) {
      return this.url + z + "/" + x + "/" + y + "." + this.type;
    } else {
      return "http://www.maptiler.org/img/none.png";
    }
  }

  options.projection = new OpenLayers.Projection(options.projection);
  return new OpenLayers.Layer.TMS(title, options.base_url, options);
};
