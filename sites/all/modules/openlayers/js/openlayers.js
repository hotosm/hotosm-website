/*jslint white: false */
/*jslint forin: true */
/*global OpenLayers Drupal $ document jQuery window */

/**
 * @file
 * This file holds the main javascript API for OpenLayers. It is
 * responsable for loading and displaying the map.
 *
 * @ingroup openlayers
 */

/**
 * This is a workaround for a bug involving IE and VML support.
 * See the Drupal Book page describing this problem:
 * http://drupal.org/node/613002
 */

document.namespaces;

(function($) {

Drupal.settings.openlayers = {};
Drupal.settings.openlayers.maps = {};

/**
 * Minimal OpenLayers map bootstrap.
 * All additional operations occur in additional Drupal behaviors.
 */
Drupal.behaviors.openlayers = {
  'attach': function(context, settings) {
    Drupal.openlayers.loadProjections(context, settings);

    if (typeof(Drupal.settings.openlayers) === 'object' &&
        Drupal.settings.openlayers.maps &&
        !$(context).data('openlayers')) {
      $('.openlayers-map').once('openlayers-map', function() {
        // By setting the stop_render variable to TRUE, this will
        // halt the render process.  If set, one could remove this setting
        // then call Drupal.attachBehaviors again to get it started
        var map_id = $(this).attr('id');
        if (Drupal.settings.openlayers.maps[map_id] && Drupal.settings.openlayers.maps[map_id].stop_render != true) {
          var map = Drupal.settings.openlayers.maps[map_id];

          if(map.default_layer===null){
            Drupal.openlayers.console.error("Map configuration is invalid as it lacks a base layer.");
          }

          // Use try..catch for error handling.
          try {
            // Set OpenLayers language based on document language,
            // rather than browser language
            OpenLayers.Lang.setCode($('html').attr('lang'));

            var options = {};
            // This is necessary because the input JSON cannot contain objects
            options.projection = new OpenLayers.Projection(map.projection);
            options.displayProjection = new OpenLayers.Projection(map.displayProjection);

            // Restrict map to its extent (usually projection extent).
            options.maxExtent = OpenLayers.Bounds.fromArray(map.maxExtent);

            options.maxResolution = 'auto';
            options.controls = [];

            // Change image, CSS, and proxy paths if specified
            if (map.image_path) {
              OpenLayers.ImgPath = Drupal.openlayers.relatePath(map.image_path,
                Drupal.settings.basePath);
            }
            if (map.css_path) {
              options.theme = Drupal.openlayers.relatePath(map.css_path,
                Drupal.settings.basePath);
            }
            if (map.proxy_host) {
              OpenLayers.ProxyHost = Drupal.openlayers.relatePath(map.proxy_host,
                Drupal.settings.basePath);
            }

            // Initialize openlayers map
            var openlayers = new OpenLayers.Map(map_id, options);

            // Run the layer addition first
            Drupal.openlayers.addLayers(map, openlayers);

            // Ensure redraw as maps stays blank until first zoom otherwise (observed with EPSG:2056)
            openlayers.moveTo(openlayers.getCenter(), openlayers.getZoom(), {
              forceZoomChange: true
            });

            // Attach data to map DOM object
            $(this).data('openlayers', {'map': map, 'openlayers': openlayers});

            // Finally, attach behaviors
            Drupal.attachBehaviors(this);

            if ($.browser.msie) {
              $(window).load(function() {
                openlayers.render(map.id);
              });
            } else {
              openlayers.render(map.id);
            }
          }
          catch (e) {
            var errorMessage = e.name + ': ' + e.message;
            if (typeof console != 'undefined') {
              Drupal.openlayers.console.log(errorMessage);
            }
            else {
              $(this).text('Error during map rendering: ' + errorMessage);
            }
          }
        }
      });
    }
  }
};

/**
 * Collection of helper methods.
 */
Drupal.openlayers = {
  // Determine path based on format.
  'relatePath': function(path, basePath) {
    // Check for a full URL or an absolute path.
    if (path.indexOf('://') >= 0 || path.indexOf('/') == 0) {
      return path;
    }
    else {
      return basePath + path;
    }
  },
  /*
   * Redraw Vectors.
   * This is necessary because various version of IE cannot draw vectors on
   * $(document).ready()
   */
  'redrawVectors': function() {
    $(window).load(
      function() {
        var map;
        for (map in Drupal.settings.openlayers.maps) {
          $.each($('#' + map).data('openlayers')
            .openlayers.getLayersByClass('OpenLayers.Layer.Vector'),
            function(i, layer) {
              layer.redraw();
            }
          );
        }
      }
    );
  },
  /**
   * Add layers to the map
   *
   * @param map Drupal settings object for the map.
   * @param openlayers OpenLayers Map Object.
   */
  'addLayers': function(map, openlayers) {

    var sorted = [];
    for (var name in map.layers) {
      sorted.push({'name': name, 'weight': map.layers[name].weight, 'isBaseLayer': map.layers[name].isBaseLayer });
    }

    sorted.sort(function(a, b) {
      var x = parseInt(a.weight, 10), y = parseInt(b.weight, 10);
      return ((a.isBaseLayer && x < y) ? -1 : ((b.isBaseLayer || x > y) ? 1 : 0));
    });

    for (var i = 0; i < sorted.length; ++i) {
      var layer,
        name = sorted[i].name,
        options = map.layers[name];

      // Add reference to our layer ID
      options.drupalID = name;
      // Ensure that the layer handler is available
      if (options.layer_handler !== undefined &&
        Drupal.openlayers.layer[options.layer_handler] !== undefined) {
        layer = Drupal.openlayers.layer[options.layer_handler](map.layers[name].title, map, options);

        layer.visibility = !!(!map.layer_activated || map.layer_activated[name]);

        if (layer.isBaseLayer === false) {
          layer.displayInLayerSwitcher = (!map.layer_switcher || map.layer_switcher[name]);
        }

        openlayers.addLayer(layer);
      }
    }

    openlayers.setBaseLayer(openlayers.getLayersBy('drupalID', map.default_layer)[0]);

    // Set the restricted extent if wanted.
    // Prevents the map from being panned outside of a specfic bounding box.
    if (typeof map.center.restrict !== 'undefined' && map.center.restrict.restrictextent) {
      var desiredRestriction = OpenLayers.Bounds.fromString(
          map.center.restrict.restrictedExtent
      ).transform(new OpenLayers.Projection('EPSG:3857'), openlayers.projection);

      if(desiredRestriction.left>=openlayers.maxExtent.left && desiredRestriction.right<=openlayers.maxExtent.right
        && desiredRestriction.top<=openlayers.maxExtent.top && desiredRestriction.bottom>=openlayers.maxExtent.bottom){

        openlayers.restrictedExtent = desiredRestriction;
      } else {
        // Given the map to set the restricted extent is not dependent on the map projection
        // it does allow to set an extent outwith the valid bound of the map projection. As a
        // result no valid data could be requested and thus the wrong extent needs to be ignored.
        Drupal.openlayers.console.error("Restricted bounds ignored as not within projection bounds.");
      }
    }

    // Zoom & center
    if (map.center.initial) {
      var center = OpenLayers.LonLat.fromString(map.center.initial.centerpoint).transform(
        new OpenLayers.Projection('EPSG:4326'),
        new OpenLayers.Projection(map.projection));
      var zoom = parseInt(map.center.initial.zoom, 10);
      openlayers.setCenter(center, zoom, false, false);
    }
  },
  /**
   * Abstraction of OpenLayer's feature adding syntax to work with Drupal output.
   * Ideally this should be rolled into the PHP code, because we don't want to manually
   * parse WKT
   */
  'addFeatures': function(map, layer, features) {
    var newFeatures = [];

    // Go through features
    for (var key in features) {
      var feature = features[key];
      var newFeatureObject = this.objectFromFeature(feature);

      // If we have successfully extracted geometry add additional
      // properties and queue it for addition to the layer
      if (newFeatureObject) {
        var newFeatureSet = [];

        // Check to see if it is a new feature, or an array of new features.
        if (typeof(newFeatureObject[0]) === 'undefined') {
          newFeatureSet[0] = newFeatureObject;
        }
        else {
          newFeatureSet = newFeatureObject;
        }

        // Go through new features
        for (var i = 0; i < newFeatureSet.length; i++) {
          var newFeature = newFeatureSet[i];

          // Transform the geometry if the 'projection' property is different from the map projection
          if (feature.projection) {
            if (feature.projection !== map.projection) {
              var featureProjection = new OpenLayers.Projection(feature.projection);
              var mapProjection = new OpenLayers.Projection(map.projection);
              newFeature.geometry.transform(featureProjection, mapProjection);
            }
          }

          // Add attribute data
          if (feature.attributes) {
            // Attributes belong to features, not single component geometries
            // of them. But we're creating a geometry for each component for
            // better performance and clustering support. Let's call these
            // "pseudofeatures".
            //
            // In order to identify the real feature each geometry belongs to
            // we then add a 'fid' parameter to the "pseudofeature".
            // NOTE: 'drupalFID' is only unique within a single layer.
            newFeature.attributes = feature.attributes;
            newFeature.data = feature.attributes;
            newFeature.drupalFID = key;
          }

          // Add style information
          if (feature.style) {
            newFeature.style = jQuery.extend({},
                OpenLayers.Feature.Vector.style['default'],
                feature.style);
          }

          // Push new features
          newFeatures.push(newFeature);
        }
      }
    }

    // Add new features if there are any
    if (newFeatures.length !== 0) {
      layer.addFeatures(newFeatures);
    }
  },

  'getStyleMap': function(map, layername) {
    if (map.styles) {
      var stylesAdded = {};

      // Grab and map base styles.
      for (var style in map.styles) {
        stylesAdded[style] = new OpenLayers.Style(map.styles[style]);
      }

      // Implement layer-specific styles.  First default, then select.
      if (map.layer_styles !== undefined && map.layer_styles[layername]) {
        var style = map.layer_styles[layername];
        stylesAdded['default'] = new OpenLayers.Style(map.styles[style]);
      }
      if (map.layer_styles_select !== undefined && map.layer_styles_select[layername]) {
        var style = map.layer_styles_select[layername];
        stylesAdded['select'] = new OpenLayers.Style(map.styles[style]);
      }
      if (map.layer_styles_temporary !== undefined && map.layer_styles_temporary[layername]) {
        var style = map.layer_styles_temporary[layername];
        stylesAdded['temporary'] = new OpenLayers.Style(map.styles[style]);
      }

      return new OpenLayers.StyleMap(stylesAdded);
    }
    else {
      return new OpenLayers.StyleMap({
        'default': new OpenLayers.Style({
          pointRadius: 5,
          fillColor: '#ffcc66',
          strokeColor: '#ff9933',
          strokeWidth: 4,
          fillOpacity: 0.5
        }),
        'select': new OpenLayers.Style({
          fillColor: '#66ccff',
          strokeColor: '#3399ff'
        })
      });
    }
  },

  'objectFromFeature': function(feature) {
    var wktFormat = new OpenLayers.Format.WKT();
    // Extract geometry either from wkt property or lon/lat properties
    if (feature.wkt) {
      return wktFormat.read(feature.wkt);
    }
    else if (feature.lon) {
      return wktFormat.read('POINT(' + feature.lon + ' ' + feature.lat + ')');
    }
  },

  /**
   * Add Behavior.
   *
   * This is a wrapper around adding behaviors for OpenLayers.
   * a module does not have to use this, but it helps cut
   * down on code.
   *
   * @param id
   *   The identifier of the behavior that is attached to
   *   the map.
   * @param attach
   *   The callback function for the attach part of the
   *   Drupal behavior.
   * @param detach
   *   The callback function for the detach part of the
   *   Drupal behavior.
   */
  'addBehavior': function(id, attach, detach) {
    // Add as a Drupal behavior.  Add a prefix, just to be safe.
    Drupal.behaviors['openlayers_auto_' + id] = {
      attach: function (context, settings) {
        var data = $(context).data('openlayers');

        // Ensure that there is a map and that the appropriate
        // behavior exists.  Need "data &&" to avoid js crash
        // when data is empty
        var localBehavior = data && data.map.behaviors[id];

        // Ensure scope in the attach callback
        var that = this;
        if (localBehavior) {
          $(context).once('openlayers-' + id, function () {
            attach.apply(that, [data, data.map.behaviors[id], context, settings]);
          });
        }
      },
      // Maybe we need a little more handling here.
      detach: detach
    };
  },

  /**
   * Add Control.
   *
   * This is a wrapper around adding controls to maps.  It
   * is not needed but saves some code.
   */
  'addControl': function(openlayers, controlName, options) {
    var control = new OpenLayers.Control[controlName](options);
    openlayers.addControl(control);
    control.activate();
    return control;
  },

  /**
   * Instructs the Proj4js module to make projection definitions available
   * to Proj4js and thus OpenLayers, too.
   *
   * Triggering the initialization of Proj4js this way guarantees projection
   * definitions are available.
   */
  'loadProjections': function(context, settings){
    // Proj4js is not necessarily present as we only load it when OpenLayers
    // can't handle the projections is use without its help.
    if(Drupal.behaviors.proj4js){
      Drupal.behaviors.proj4js.attach(context, settings);
    }
  },

  /**
   * Logging implementation that logs using the browser's logging API.
   * Falls back to doing nothing in case no such API is available. Simulates
   * the presece of Firebug's console API in Drupal.openlayers.console.
   */
  'console': (function(){
    var api = {};
    var logger;
    if(typeof(console)==="object" && typeof(console.log)==="function"){
      logger = function(){
        // Use console.log as fallback for missing parts of API if present.
        console.log.apply(console, arguments);
      }
    } else {
      logger = function (){
        // Ignore call as no logging facility is available.
      };
    }
    jQuery(["log", "debug", "info", "warn", "exception", "assert", "dir",
      "dirxml", "trace", "group", "groupEnd", "groupCollapsed", "profile",
      "profileEnd", "count", "clear", "time", "timeEnd", "timeStamp", "table",
      "error"]).each(function(index, functionName){
      if(typeof(console)!=="object" || typeof(console[functionName])!=="function"){
        // Use fallback as browser does not provide implementation.
        api[functionName] = logger;
      } else {
        api[functionName] = function(){
          // Use browsers implementation.
          console[functionName].apply(console, arguments);
        };
      }
    });
    return api;
  })()
};

Drupal.openlayers.layer = {};
})(jQuery);
