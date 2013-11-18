
/**
 * @file
 * Layer handler for XYZ layers
 */

/**
 * Openlayer layer handler for XYZ layer
 */
Drupal.openlayers.layer.xyz = function(title, map, options) {
  if (OpenLayers.Util.isArray(options.maxExtent)) {
    options.maxExtent = OpenLayers.Bounds.fromArray(options.maxExtent);
  }

  // Legacy goodnes
  if (typeof options.base_url == 'string' && typeof options.url == 'undefined') {
    options.url = options.base_url;
  }

  // Server resolutions are very particular in OL 2.11
  var r = options.serverResolutions;
  if (r == null || typeof r == 'undefined' || r.length == 0) {
    options.serverResolutions = null;
  }

  // Wrap Date Line does not seem to work for 2.10.  This may
  // have something to do with our extent definitions.
  if (OpenLayers.VERSION_NUMBER.indexOf('2.10') >= 0) {
    options.wrapDateLine = null;
  }

  options.projection = new OpenLayers.Projection(options.projection);

  return new OpenLayers.Layer.XYZ(title, options.url, options);
};
