/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Layer Switcher Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_layerswitcher', function (data, options) {
  options.ascending = !! options.ascending;
  Drupal.openlayers.addControl(data.openlayers, 'LayerSwitcher', options);

  // Maximize if needed.
  if (!! options.maximizeDefault == true) {
    data.openlayers.getControlsByClass('OpenLayers.Control.LayerSwitcher')[0].maximizeControl();
  }
});
