
/**
 * @file
 * Layer handler for OSM layers
 */

/**
 * Openlayer layer handler for OSM layer
 */
Drupal.openlayers.layer.osm = function(title, map, options) {
    return new OpenLayers.Layer.OSM(title, options.url, options);
};
