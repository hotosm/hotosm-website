<?php

/**
 * @file
 * This file contains behaviors implementations.
 *
 * @ingroup openlayers
 */

/**
 * Internal callback
 * Helper function to return default behaviors.
 *
 * @return mixed
 */
function _openlayers_openlayers_behaviors() {
  $behaviors['openlayers_behavior_argparser'] = array(
    'title' => t('Argument Parser'),
    'description' => t('Parses Permalink-formatted arguments without adding a
    Permalink link to the map.  Permalink is usually similar to:
    ?zoom=1&lat=11&lon=11&layers=B0F'),
    'type' => 'layer',
  );
  $behaviors['openlayers_behavior_attribution'] = array(
    'title' => t('Layer Attribution'),
    'description' => t('Allows layers to provide attribution to the map if it exists.  Most third-party layer will have some sort of attribution, but this may come with the actual tiles as well.'),
    'type' => 'layer',
  );
  $behaviors['openlayers_behavior_boxselect'] = array(
    'title' => t('Bounding Box Select'),
    'description' => t('Allows the selection and display of a bounding box.  Currently hard-coded for the map making interface.'),
    'type' => 'map',
    'ui_visibility' => FALSE,
  );
  $behaviors['openlayers_behavior_cluster'] = array(
    'title' => t('Cluster Features'),
    'description' => t('Provides vector layer features clustering by proximity.  This will not always respect the styles that assigned to the layer.'),
    'type' => 'layer',
  );
  $behaviors['openlayers_behavior_dragpan'] = array(
    'title' => t('Mouse Drag Pan'),
    'description' => t('Provides the ability to pan in the map interface with the mouse.  The Navigation Control includes this control.  You should only use this behavior if you want fine control over what interactions you want on your map.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_drawfeatures'] = array(
    'title' => t('Draw Features'),
    'description' => t('Provides functionality for adding features to a map.'),
    'type' => 'layer',
  );
  $behaviors['openlayers_behavior_fullscreen'] = array(
    'title' => t('Fullscreen'),
    'description' => t('Provides a button that expands maps to the size of the page.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_geolocate'] = array(
    'title' => t('Geolocate Client'),
    'description' => t('Provides the geolcoation control that simply zooms to users location on map load.  Based on HTML5 geolocation, so this will not be supported in all browsers.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_graticule'] = array(
    'title' => t('Graticule'),
    'description' => t('Adds a graticule control to the map to display a grid of latitude and longitude.'),
    'type' => 'layer',
  );
  $behaviors['openlayers_behavior_hover'] = array(
    'title' => t('Hover features'),
    'description' => t('Provides on hover behavior on features. A temporary style will be applied on features when hovering them.'),
    'type' => 'layer',
  );
  $behaviors['openlayers_behavior_keyboarddefaults'] = array(
    'title' => t('Keyboard Controls'),
    'description' => t('Provides keyboard shortcuts to pan and zoom the map, such as the up, down, left, and right arrows.  This is included with the Navigation control.  This should not be enabled unless you want to have finer control on how the user interacts with the map.'),
    'type' => 'layer',
  );
  $behaviors['openlayers_behavior_layerswitcher'] = array(
    'title' => t('Layer Switcher'),
    'description' => t('Provides the ability to switch layers in the map interface.  This provides an expandable box on the map to enable and disable layers.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_layerzoom'] = array(
    'title' => t('Zoom restrictions for non-base layers.'),
    'description' => t('Enables restriction of layer display based on zoom level.'),
    'type' => 'layer',
  );
  $behaviors['openlayers_behavior_mapformvalues'] = array(
    'title' => t('Map Form Values'),
    'description' => t('Provides a way of updating form elements with zoom level and centering from a map.'),
    'type' => 'map',
    'ui_visibility' => FALSE,
  );
  $behaviors['openlayers_behavior_mouseposition'] = array(
    'title' => t('Mouse Position'),
    'description' => t('Provides a visual indication of the mouse position to the user.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_navigation'] = array(
    'title' => t('Navigation'),
    'description' => t('Provides the ability to navigate the map interface.  This is just for user interactions and does not show any visual controls.  This behavior automatically includes the Pan Zoom, Zoom Box, and Pinch Zoom controls.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_panzoom'] = array(
    'title' => t('Pan and Zoom Control'),
    'description' => t('Provides controls with the ability to pan and zoom in the map interface.  Do not use with the Pan Zoom Bar Control or the Zoom Panel Control.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_panzoombar'] = array(
    'title' => t('Pan and Zoom Bar Controls'),
    'description' => t('Gives user ability to pan and zoom, with a full zoom bar in the map interface.  Do not use with Pan Zoom Contols or Zoom Panel Controls.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_permalink'] = array(
    'title' => t('Permalink'),
    'description' =>  t('Provides a link that will create an URL that will link to a specific map position.  Permalink is usually similar to: ?zoom=1&lat=11&lon=11&layers=B0F'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_popup'] = array(
    'title' => t('Pop Up for Features'),
    'description' => t('Adds clickable info boxes to points or shapes on maps.  This does not work with the Tooltip behavior due to limitation of event handling in the OpenLayers library.'),
    'type' => 'layer',
  );
  $behaviors['openlayers_behavior_scaleline'] = array(
    'title' => t('Scale Line'),
    'description' => t('Provides a line of scale in the map interface.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_tooltip'] = array(
    'title' => t('Tooltip for Features'),
    'description' => t('Adds info boxes on hover to points or shapes on maps.  This does not work with the Popup behavior due to limitation of event handling in the OpenLayers library.'),
    'type' => 'layer',
  );
  $behaviors['openlayers_behavior_touch_navigation'] = array(
    'title' => t('Touch Navigation'),
    'description' => t('Provides specific navigation controls for touch enabled devices only.  <strong>This is included with the Navigation behavior</strong>.  Only enable this if you are targeting only touch enabled devices.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_zoombox'] = array(
    'title' => t('Zoom Box Clicking'),
    'description' => t('Provides a zoom box that can be drawn on SHIFT + click.  Please note that by default the Navigation control behavior includes this, so there is no need to have both.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_zoompanel'] = array(
    'title' => t('Zoom Control'),
    'description' => t('Provides a control that can Zoom In, Zoom Out, and Zoom to Max Extent Button.  Do not use with Pan Zoom Bar Control or Pan Zoom Control.'),
    'type' => 'map',
  );
  $behaviors['openlayers_behavior_zoomtolayer'] = array(
    'title' => t('Zoom to Layer'),
    'description' => t('Zooms to the extent of a given layer(s) on map loading. If multiple layers are chosen, zooms to the extent that includes all chosen layers.'),
    'type' => 'layer',
  );
  $behaviors['openlayers_behavior_zoomtomaxextent'] = array(
    'title' => t('Zoom to Max Extent'),
    'description' => t('Provides button to zoom to the maximum extent of the map.'),
    'type' => 'map',
  );

  foreach ($behaviors as $key => $data) {
    $behaviors[$key]['path'] = drupal_get_path('module', 'openlayers') . '/' . openlayers_ctools_plugin_directory('openlayers', 'behaviors');
    $behaviors[$key]['behavior'] = array(
      'class' => $key,
      'file' => $key . '.inc',
      'parent' => 'openlayers_behavior',
    );
  }

  return $behaviors;
}
