/**
 * @file
 * JS Implementation of OpenLayers behavior.
 */

/**
 * Attribution Behavior
 */
Drupal.openlayers.addBehavior('openlayers_behavior_fullscreen', function (data, options) {
  // Create new panel control and add.
  var fullscreenPanel = new OpenLayers.Control.Panel({
    displayClass: 'openlayers_behavior_fullscreen_button_panel'
  });
  data.openlayers.addControl(fullscreenPanel);

  // Create toggleing control and cutton.
  var toggler = OpenLayers.Function.bind(
    Drupal.openlayers.fullscreenToggle, data);
  var button = new OpenLayers.Control.Button({
    displayClass: 'openlayers_behavior_fullscreen_button',
    title: Drupal.t('Fullscreen'),
    trigger: toggler
  });
  fullscreenPanel.addControls([button]);

  // Make fullscreen by default if activited.
  if (options.activated == true) {
    toggler();
  }
});

/**
 * Toggling function for FullScreen control.
 */
Drupal.openlayers.fullscreenToggle = function () {
  var $map = jQuery(this.openlayers.div);
  var extent = this.openlayers.getExtent();

  $map.parent().toggleClass('openlayers_map_fullscreen');
  $map.toggleClass('openlayers_map_fullscreen');
  $map.data('openlayers').openlayers.updateSize();
  $map.data('openlayers').openlayers.zoomToExtent(extent, true);
};
