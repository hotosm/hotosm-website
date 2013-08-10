
/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Keyboard Defaults Behavior.  Implements the KeyboardDefaults OpenLayers
 * Control.
 */
Drupal.openlayers.addBehavior('openlayers_behavior_keyboarddefaults', function (data, options) {
  Drupal.openlayers.addControl(data.openlayers, 'KeyboardDefaults');
});
