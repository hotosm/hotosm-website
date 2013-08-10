<?php

/**
 * @file
 * This file holds the functions handling maps in the
 * Openlayers UI.
 *
 * @ingroup openlayers
 */

/**
 * Menu Callback for Add Map
 */
function openlayers_ui_maps_form($form, &$form_state, $map = FALSE, $edit = FALSE) {
  openlayers_include();
  ctools_include('dependent');
  drupal_add_js(drupal_get_path('module', 'openlayers_ui') .
    '/js/openlayers_ui.maps.js');
  drupal_add_css(drupal_get_path('module', 'openlayers_ui') .
    '/openlayers_ui.css');

  // If cloning or editing, attempt to get map.
  $defaults = array();
  if (empty($map)) {
    $default_map = openlayers_map_load(variable_get('openlayers_default_map', 'default'));
    if ($default_map) {
      $defaults = $default_map->data;
    }
  }
  else {
    $defaults = $map->data;
  }

  // Start the form
  $form = array(
    '#tree' => TRUE,
    '#cache' => TRUE,
    'map_edit' => array('#type' => 'value', '#value' => $edit),
    'default_map' => array('#type' => 'value', '#value' => $defaults),
  );

  // Map preview.  It's a little in the way, so we allow the user
  // to turn it on or off.  Show on preview, otherwise look at setting.
  // Might want to look at disableing the mousewheel zoom since
  // the map could be very in the way.
  if ( (isset($form_state['clicked_button']['#id'])
      && ($form_state['clicked_button']['#id'] == 'edit-buttons-preview'))
      || (variable_get('openlayers_ui_preview_map', TRUE)))  {

    $map_preview = isset($form_state['values']) ? openlayers_ui_maps_form_process($form_state['values']) : $map;

    $form['preview'] = array(
      '#tree' => FALSE,
      '#type' => 'fieldset',
      '#title' => t('Preview'),
      '#description' => t('The following is a preview of your map.  Click <em>Preview</em>
        to refresh the map with the new values.  ' .
        (!variable_get('openlayers_ui_preview_map', FALSE) ?
          t('Turn map previews on by default on the !link.',
          array('!link' => l(t('Settings page'), 'admin/structure/openlayers/settings'))) : ''
        )
      ),
    );
    $form['preview']['map'] = array(
      '#markup' => openlayers_render_map($map_preview),
    );
  } else {
    $form['preview'] = array();
    $form['preview']['map'] = array(
      '#markup' => '<p>' . t('Turn map previews on by default on the !link.',
        array('!link' => l(t('Settings page'), 'admin/structure/openlayers/settings'))) . '</p>',
    );
  }

  // Utilize vertical tabs for a better interface.
  $form['ui'] = array(
    '#type' => 'vertical_tabs',
    '#default_tab' => 'info'
  );

  // General map information.
  $form['info'] = array(
    '#title' => t('Basics'),
    '#tree' => FALSE,
    '#group' => 'ui',
    '#type' => 'fieldset'
  );
  $form['info']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Map Title'),
    '#description' => t('This is the descriptive title of the map and will show up most often in the interface.'),
    '#maxlength' => 255,
    '#default_value' => !empty($map->title) ? $map->title : '',
    '#required' => TRUE,
  );
  $form['info']['name'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($map->name) ? $map->name : '',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'openlayers_map_load',
      'source' => array('info', 'title'),
    ),
    '#description' => t('A unique machine-readable name for this block type. It must only contain lowercase letters, numbers, and underscores.'),
    '#disabled' => $edit,
  );
  $form['info']['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Map Description'),
    '#description' => t('This is full description of the map and is mostly used on the map overview list page.'),
    '#default_value' => !empty($map->description) ? $map->description : '',
    '#required' => FALSE,
    '#maxlength' => NULL,
  );
  $form['info']['width'] = array(
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#description' => t('The map\'s width. "auto" will make the map fill
      the space it is given; otherwise, enter a value in pixels, like 400px.'),
    '#default_value' => !empty($defaults['width']) ? $defaults['width'] : '',
    '#maxlength' => 128,
    '#required' => TRUE,
  );
  $form['info']['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#description' => t('The map\'s height. Enter a value in pixels,
      like 400px.'),
    '#default_value' => !empty($defaults['height']) ? $defaults['height'] : '',
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  // Only show this if Openlayers Views is enabled
  if (module_exists('openlayers_views')) {
    $form['info']['hide_empty_map'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide empty map for Views'),
      '#description' => t("Show views empty text or hide the map if there are
        no map overlays with features. Otherwise an empty map is displayed."),
      '#default_value' => isset($defaults['hide_empty_map']) ?
        $defaults['hide_empty_map'] : FALSE,
    );
  }

  $default_image_path = drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/';
  $form['info']['image_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Image Path'),
    '#description' => t('<p>The path to a directory of UI graphics. Use any of the
      following:</p>
      <ul>
        <li><strong>Leave blank</strong> for default graphics as provided
          by the OpenLayers library. </li>
        <li><strong>Relative Drupal path</strong> a path without leading slash and
          the base path will be prepended, ex. "sites/all/themes/path/to/images/"</li>
        <li><strong>Absolute path</strong> a path with leading slash and path will
          start from sites root directory, ex. "/path/to/images/"</li>
        <li><strong>Full URL</strong> such as "http://example.com/image/"</li>
      </ul>
      <p>Always include trailing slash.  The default path provided with this module
      is: %default</p>
      <p><strong>This is actually a setting for the OpenLayers
      object and will affect all maps on the same page.</strong></p>',
      array('%default' => $default_image_path)
    ),
    '#default_value' => !empty($defaults['image_path']) ?
      $defaults['image_path'] : '',
  );

  $default_css_path = drupal_get_path('module', 'openlayers') . '/themes/default_dark/style.css';
  $form['info']['css_path'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS Path'),
    '#description' => t('<p>The path to a CSS file for overriding CSS. You
      don\'t really need to override this as CSS is almost always overridable.
      Use any of the following:</p>
      <ul>
        <li><strong>Leave blank</strong> for default hosted OpenLayers which
          is !link</li>
        <li><strong>Relative Drupal path</strong> a path without leading slash and
          the base path will be prepended, ex. "sites/all/themes/path/to/style.css"</li>
        <li><strong>Absolute path</strong> a path with leading slash and path will
          start from sites root directory, ex. "/path/to/style.css"</li>
        <li><strong>Full URL</strong> such as "http://example.com/style.css"</li>
      </ul>
      <p>The default path provided with this module
      is: %default</p>
      <p><strong>This is actually a setting for the OpenLayers
      object and will affect all maps on the same page.</strong></p>',
      array(
        '!link' => l('http://openlayers.org/api/theme/default/style.css',
          'http://openlayers.org/api/theme/default/style.css'),
        '%default' => $default_css_path,
      )
    ),
    '#default_value' => !empty($defaults['css_path']) ?
      $defaults['css_path'] : '',
  );

  $form['info']['proxy_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Proxy Host'),
    '#description' => t('<p>A proxy (typically on the same domain as this site)
      which enables requests to cross-domain AJAX resources (including remote
      KML).  Use any of the following:</p>
      <ul>
        <li><strong>Leave blank</strong> no proxy path.</li>
        <li><strong>Relative Drupal path</strong> a path without leading slash and
          the base path will be prepended, ex. "proxy?request="</li>
        <li><strong>Absolute path</strong> a path with leading slash and path will
          start from sites root directory, ex. "/cgi_proxy?request="</li>
        <li><strong>Full URL</strong> such as "http://example.com/proxy?request="</li>
      </ul>
      <p><strong>This is actually a setting for the OpenLayers
      object and will affect all maps on the same page.</strong></p>'
    ),
    '#default_value' => !empty($defaults['proxy_host']) ?
      $defaults['proxy_host'] : '',
  );

  // Center
  $form['center'] = array(
    '#title' => t('Center & Bounds'),
    '#description' => t('Where the map will center itself initially.
      <strong>Shift-drag</strong> a box on the map to set the Restricted Extent.'),
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#group' => 'ui'
  );
  $form['center']['helpmap'] = array(
    '#markup' => '<div class="form-item openlayers-center-helpmap"
      style="display:block">' .
      openlayers_ui_maps_form_center_map($defaults) . '</div>'
  );
  $form['center']['initial'] = array(
    '#type' => 'fieldset',
    '#title' => t('Initial Map View')
  );
  $form['center']['initial']['centerpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Centerpoint'),
    '#description' => t('Coordinates that are the intial focus of the map.  This
      is formated like <em>longitude,latitude</em>.'),
    '#default_value' => $defaults['center']['initial']['centerpoint'],
    '#attributes' => array('class' => array('openlayers-form-centerpoint')),
    '#size' => 25,
  );
  $form['center']['initial']['zoom'] = array(
    '#type' => 'textfield',
    '#title' => t('Zoom Level'),
    '#description' => t('Initial Zoom Level when the map intially displays.
      Higher is more zoomed in.'),
    '#default_value' => $defaults['center']['initial']['zoom'],
    '#attributes' => array('class' => array('openlayers-form-zoom')),
    '#size' => 25,
  );
  $form['center']['restrict'] = array(
    '#type' => 'fieldset',
    '#title' => t('Restrict Extent')
  );
  $form['center']['restrict']['restrictextent'] = array(
    '#type' => 'checkbox',
    '#title' => t('Restrict Extent'),
    '#description' => t('Setting the restricted extent of a map prevents users
      from panning the map outside a specified area. This can be set
      interactively by <strong>holding the shift key and dragging a box</strong> over the map
      above. Setting the extent does not restrict how far users can zoom out,
      so setting restricted zoom levels (via individual layer settings) is
      recommended.'),
    '#id' => 'restrictextent',
    '#default_value' => isset($defaults['center']['restrict']['restrictextent']) ?
      $defaults['center']['restrict']['restrictextent'] : '',
  );
  $form['center']['restrict']['restrictedExtent'] = array(
    '#type' => 'textfield',
    '#title' => t('Restricted Extent'),
    '#description' => t('Prevents users from panning outside of a specific bounding box'),
    '#default_value' => isset($defaults['center']['restrict']['restrictedExtent']) ?
      $defaults['center']['restrict']['restrictedExtent'] : '',
    '#attributes' => array('class' => array('openlayers-form-restrictedExtent')),
    '#size' => 25,
    '#process' => array('ctools_dependent_process'),
    '#dependency' => array('restrictextent' => array(1))
  );


  // Layers & styles
  $form['layerstyles'] = array(
    '#title' => t('Layers & Styles'),
    '#description' => t('Layer settings.  The Layer options will change based on the projection chosen.'),
    '#theme' => 'openlayers_ui_maps_form_layers',
    '#tree' => FALSE,
    '#type' => 'fieldset',
    '#group' => 'ui'
  );

  // Projection options
  $projections = array();
  foreach (openlayers_ui_get_projection_options() as $projection) {
    $projection_layers = array_merge(
      openlayers_ui_get_layer_options('baselayer', $projection),
      openlayers_ui_get_layer_options('overlay', $projection));

    $projections[$projection] = theme(
      'openlayers_ui_form_projection_description',
      array(
        'projection_title' => $projection,
        'available_layers' => array_keys($projection_layers)
      )
    );
  }

  // Construct data for theme_openlayers_ui_maps_form_layers
  $form['layerstyles']['layers']['#tree'] = TRUE;
  $form['layerstyles']['layers']['baselabels'] = array();
  $base_options = openlayers_ui_get_layer_options('baselayer', $defaults['projection']);
  foreach ($base_options as $id => $description) {
    $form['layerstyles']['layers']['baselabels'][$id] =
      array('#markup' => $description);
  }
  $form['layerstyles']['layers']['baselayers'] = array(
    '#type' => 'checkboxes',
    '#options' => $base_options,
    '#default_value' => !empty($defaults['layers']) ?
      array_intersect_key($defaults['layers'], $base_options) :
      array()
  );
  $form['layerstyles']['layers']['default_layer'] = array(
    '#type' => 'radios',
    '#options' => $base_options,
    '#default_value' => !empty($defaults['default_layer']) &&
      isset($base_options[$defaults['default_layer']]) ?
      $defaults['default_layer'] :
      NULL,
  );

  // Overlay layers
  $overlay_options = openlayers_ui_get_layer_options('overlay', $defaults['projection']);
  $form['layerstyles']['layers']['overlaylabels'] = array();
  if (!empty($overlay_options)) {

    // Have enabled layers maintain their order
    $available = array_keys($overlay_options);
    $enabled = array_intersect(array_keys($defaults['layers']), $available);
    $disabled = array_diff($available, $enabled);
    $overlay_options_keys = array_merge($disabled, $enabled);

    // Create overlay options.
    $form['layerstyles']['layer_styles']['#tree'] = TRUE;
    $form['layerstyles']['layer_styles_select']['#tree'] = TRUE;
    $form['layerstyles']['layer_weight']['#tree'] = TRUE;
    foreach ($overlay_options_keys as $id) {
      $description = $overlay_options[$id];
      $form['layerstyles']['layers']['overlaylabels'][$id] = array('#markup' => $description);

      // Layer styles tha define the default style of layer.
      $form['layerstyles']['layer_styles'][$id] = array(
        '#type' => 'select',
        '#options' => array('<' . t('use default style') . '>') + openlayers_ui_get_style_options(),
        '#default_value' => !empty($defaults['layer_styles'][$id]) ?
          $defaults['layer_styles'][$id] : '',
      );

      // Layer select style.
      $form['layerstyles']['layer_styles_select'][$id] = array(
        '#type' => 'select',
        '#options' => array('<' . t('use default style') . '>') + openlayers_ui_get_style_options(),
        '#default_value' => !empty($defaults['layer_styles_select'][$id]) ?
          $defaults['layer_styles_select'][$id] : '',
      );

      // Weight of layer.  This will affect how the layer shows up in the
      // switcher and is rendered.
      $form['layerstyles']['layer_weight'][$id] = array(
        '#type' => 'weight',
        '#default_value' => !empty($defaults['layer_weight'][$id]) ? $defaults['layer_weight'][$id] : 0,
        '#attributes' => array(
          'class' => array('layer-weight')
        )
      );
    }

    // Checkbox options for overlay layers.
    $form['layerstyles']['layers']['overlays'] = array(
      '#type' => 'checkboxes',
      '#options' => $overlay_options,
      '#default_value' => !empty($defaults['layers']) ?
        array_intersect_key($defaults['layers'], $overlay_options) : array(),
    );
    $form['layerstyles']['layer_activated'] = array(
      '#type' => 'checkboxes',
      '#options' => $overlay_options,
      '#default_value' => !empty($defaults['layer_activated']) ?
        array_intersect_key($defaults['layer_activated'], $overlay_options) : array(),
    );
    $form['layerstyles']['layer_switcher'] = array(
      '#type' => 'checkboxes',
      '#options' => $overlay_options,
      '#default_value' => !empty($defaults['layer_switcher']) ?
        array_intersect_key($defaults['layer_switcher'], $overlay_options) : array(),
    );
  }

  // Data overlay help.
  $form['layerstyles']['help_data_overlays'] = array(
    '#type' => 'item',
    '#description' => t('<strong>Add Data Overlays</strong>: You can add regular
      overlays, like <a href="!geojson">GeoJSON</a> or <a href="!kml">KML</a>,
      or you can utilize <a href="!views_url">Views</a> to create data overlays.
      To create a Views-based overlay, you must choose the <strong>OpenLayers
      Data Overlay Display Type</strong>, and then explicitly set the the
      <strong>same for the Format</strong>.  The options in the <em>Format
      Settings</em> will only use fields you have added. To learn more, take
      a look at the <a href="!online_url">online documentation on Drupal.org</a>.',
      array(
        '!views_url' => url('admin/structure/views'),
        '!geojson' => url('admin/structure/openlayers/layers/add/openlayers_layer_type_geojson'),
        '!kml' => url('admin/structure/openlayers/layers/add/openlayers_layer_type_kml'),
        '!online_url' => url('http://drupal.org/node/595872'),
      )
    ),
  );


  // Styles
  $form['layerstyles']['styles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default Styles'),
    '#description' => t('Define default style designations for layers when there
      are no overrides.'),
    '#tree' => TRUE,
  );
  $form['layerstyles']['styles']['default'] = array(
    '#type' => 'select',
    '#title' => t('Default style'),
    '#description' => t('Default style for features in a vector.'),
    '#options' => openlayers_ui_get_style_options(),
    '#default_value' => !empty($defaults['styles']['default']) ?
      $defaults['styles']['default'] : NULL,
  );
  $form['layerstyles']['styles']['select'] = array(
    '#type' => 'select',
    '#title' => t('Select style'),
    '#description' => t('Style for features in a vector that are selected.'),
    '#options' => openlayers_ui_get_style_options(),
    '#default_value' => !empty($defaults['styles']['select']) ?
      $defaults['styles']['select'] : NULL,
  );
  $form['layerstyles']['styles']['temporary'] = array(
    '#type' => 'select',
    '#title' => t('Temporary Style'),
    '#description' => t('Default style for any temporary features in a vector.
      This will also be used for rollovers for things like Tooltips.'),
    '#options' => openlayers_ui_get_style_options(),
    '#default_value' => !empty($defaults['styles']['temporary']) ?
      $defaults['styles']['temporary'] : NULL,
  );

  // TODO: This projection stuff sucks.  See
  // http://drupal.org/node/1331410
  //
  // Grab default from submitted form values on AHAH rebuild.
  // Start AHAH Wrapper
  /*
  $form['layerstyles']['ahah-start'] = array('#value' => '<div id="openlayers-layers-select">');
  if (isset($form_state['values']['projections'])) {
    if ($form_state['values']['projections']['easy_projection'] == 'other') {
      $defaults['projection'] = $form_state['values']['projections']['projection'];
    }
    else {
      $defaults['projection'] = $form_state['values']['projections']['easy_projection'];
    }
  }
  */

  // Just kind of hide the projection stuff for now.
  $form['layerstyles']['projections'] = array(
    '#type' => 'fieldset',
    '#title' => t('Projections'),
    '#description' => t('<p><strong>WARNING: Projections are not well supported in
      this module.  If you need to handle non spherical mercator projections
      you may be better using the API directly.</strong></p>
      <p>Select the EPSG code of the !link_proj for your map.  The list next
      to each projection is the layers that support this projection.</p>',
      array('!link_proj' => l(t('geographical projection'),
        'http://en.wikipedia.org/wiki/Map_projection'))
    ),
    '#tree' => TRUE,
  );
  $form['layerstyles']['projections']['easy_projection'] = array(
    '#type' => 'radios',
    '#title' => t('Map Projection'),
    '#description' => t('The !link_proj of this map: all layers will either be requested or reprojected to this format.', array(
      '!link_proj' => l(
        t('geographical projection'),
        'http://en.wikipedia.org/wiki/Map_projection'),
    )),
    '#default_value' => isset($defaults['projection']) ? $defaults['projection'] : '900913',
    '#options' => $projections,
    '#attributes' => array('class' => array('openlayers-form-easy-projection')),
  );
  $form['layerstyles']['projections']['displayProjection'] = array(
    '#type' => 'textfield',
    '#title' => t('Display Projection'),
    '#description' => t('All interaction with the map - drawing, panning,
      centering, and more - occurs in the display projection. The vast majority
      of maps use 4326 (latitude/longitude) for this value.'),
    '#default_value' => !empty($defaults['displayProjection']) ?
      $defaults['displayProjection'] : '4326',
    '#maxlength' => 6
  );

  // Behaviors
  $form['behaviors'] = array(
    '#title' => t('Behaviors'),
    '#description' => t('Configure interactive map behaviors.  Behaviors are general interactions for the map, they can be anything from popups or keyboard handling.  Enable the ones you want and their respective options.  Note that some behaviors do not work with each other or one may encompass another.'),
    '#theme' => 'openlayers_ui_maps_form_behaviors',
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#group' => 'ui'
  );
  $form['behaviors'] = $form['behaviors'] + openlayers_ui_get_behavior_options('map', $defaults);

  // Displays
  $form['displays'] = array(
    '#title' => t('Displays'),
    '#description' => t('Learn how to display your maps.'),
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#group' => 'ui'
  );
  if (module_exists('openlayers_views')) {
    $form['displays']['views'] = array(
      '#type' => 'item',
      '#title' => t('Views'),
      '#description' => t('Utilize the <a href="!views_url">Views</a> module to
        display your map as page or in a block.  By creating a new Views Display of
        type <strong>Page</strong> or <strong>Block</strong> you can then choose
        the <strong>OpenLayers Map Format</strong>.  For more details, check out
        the <a href="!online_url">online documentation on Drupal.org</a>.',
        array(
          '!views_url' => url('admin/structure/views'),
          '!online_url' => url('http://drupal.org/node/595872')
        )
      ),
      '#suffix' => theme('image', array('path' =>
        'https://img.skitch.com/20111106-c6ukwxgpgykxx8m41yrn8qew4n.png')),
    );
    $form['displays']['api'] = array(
      '#type' => 'item',
      '#title' => t('API'),
      '#description' => t('You can always utilize the API to directly display
        your maps.  The key function to use is <code>openlayers_render_map()</code>.
        Most of the code is well documented.  To learn how to extend the module,
        take a look at the <a href="!online_url">online documentation on
        Drupal.org</a> as well as the files in the <code>docs/</code> folder.',
        array('!online_url' => url('http://drupal.org/node/595872'))
      ),
    );
  }

  // Add preview button.
  $form['buttons']['preview'] = array(
    '#type' => 'button',
    '#value' => t('Preview'),
  );

  return $form;
}

/**
 * Form submit for map add form, for the projection add ahah
 */
function openlayers_ui_maps_add_projection_submit($form, &$form_state) {
  unset($form_state['submit_handlers']);
  form_execute_handlers('submit', $form, $form_state);
  $form_state['rebuild'] = TRUE;
}


/**
 * OpenLayers AHAH
 *
 * Function to handle the AHAH request of the openlayers form
 */
function openlayers_ui_map_ahah() {
  $form_state = array('storage' => NULL, 'submitted' => FALSE);
  $form_build_id = $_POST['form_build_id'];
  $form = form_get_cache($form_build_id, $form_state);

  // Get variables
  $args = $form['#parameters'];
  $form_id = array_shift($args);
  $form_state['post'] = $form['#post'] = $_POST;
  $form['#programmed'] = $form['#redirect'] = FALSE;

  // Reprocess form with new form state
  drupal_process_form($form_id, $form, $form_state);

  // Rebuild form and remove any submit handlers
  $form = drupal_rebuild_form($form_id, $form_state, $args, $form_build_id);

  // Unset wrapper and create output
  $output = theme('status_messages') . drupal_render($form['layerstyles']);

  // Final rendering callback.
  drupal_json(array('status' => TRUE, 'data' => $output));
}

/**
 * Process form submission into a map array.
 *
 * @param $values
 *   Array of values to process.
 * @return
 *   Map data array.
 */
function openlayers_ui_maps_form_process($values = array()) {
  // Valid keys that we will cherry-pick from the form values.
  $keys = array(
    'width',
    'height',
    'image_path',
    'css_path',
    'proxy_host',
    'hide_empty_map',
    'center',
    'behaviors',
    'layers',
    'layer_weight',
    'layer_styles',
    'layer_styles_select',
    'layer_activated',
    'layer_switcher',
    'projections',
    'styles'
  );

  // TODO: eliminate this process, too much disconnect between
  // forms and data
  $processed = array();
  foreach ($keys as $key) {
    switch ($key) {
      case 'behaviors':
        $processed['behaviors'] = array();
        foreach ($values['behaviors'] as $behavior => $settings) {
          if ($settings['enabled']) {
            $processed['behaviors'][$behavior] =
              isset($settings['options_set']['options']) ?
              $settings['options_set']['options'] : array();
          }
        }
        break;

      case 'projections':
        $processed['projection'] = $values['projections']['easy_projection'];
        $processed['displayProjection'] = $values['projections']['displayProjection'];
        break;

      case 'layers':
        // Put the default layer in the right place.
        // TODO: finish port here
        $processed['default_layer'] = $values['layers']['default_layer'];
        $baselayers = array_filter($values['layers']['baselayers']);
        $overlays = (isset($values['layers']['overlays'])) ?
          array_filter($values['layers']['overlays']) : array();
        // Sort overlay layers by weight, in case browser didn't
        // send them already sorted
        if (isset($values['layer_weight'])) {
          $overlays = array();
          asort($values['layer_weight']);
          foreach (array_keys($values['layer_weight']) as $layer_key) {
            if ($values['layers']['overlays'][$layer_key]) {
               $overlays[$layer_key] = $layer_key;
            }
          }
          // TODO: Above code is terrrrrrrrible. rewrite when I have the time
        }

        // Merge our different layer sections together
        $processed['layers'] = array_merge($baselayers, $overlays);
        break;

      default:
        // $processed[$key] = is_array($values[$key]) ?
        //   array_filter($values[$key]) : $values[$key];
        $processed[$key] = isset($values[$key]) ? $values[$key] : array();
        break;
    }
  }

  // Ensure these values are arrays
  $ensure_array = array('behaviors', 'layers', 'layer_weight', 'layer_styles', 'layer_styles_select', 'styles');
  foreach ($ensure_array as $key) {
    if (empty($processed[$key])) {
      $processed[$key] = array();
    }
  }

  return $processed;
}

/**
 * Get behavior options.
 */
function openlayers_ui_get_behavior_options($type, $defaults) {
  $form = array();
  $behaviors = openlayers_behaviors();
  uasort($behaviors, '_openlayers_ui_sort_behaviors');
  foreach ($behaviors as $key => $plugin) {
    // Get behavior class
    $class = ctools_plugin_load_class(
      'openlayers',
      'behaviors',
      $key,
      'behavior');
    if (!empty($class)) {
      $options = isset($defaults['behaviors'][$key]) ?
        $defaults['behaviors'][$key] : array();

      $behavior = new $class($options, $defaults);

      if (!isset($plugin['ui_visibility']) || $plugin['ui_visibility']) {
        // Create basic form structure for behavior
        $form[$key] = array(
          'enabled' => array(
            '#type' => 'checkbox',
            '#title' => $plugin['title'],
            '#description' => $plugin['description'],
            '#default_value' => isset($defaults['behaviors'][$key]),
            '#id' => $key . '-enabled',
          ),
          'dependencies' => openlayers_dependency_widget(
            $behavior->js_dependency()),
          'options' => array(),
        );

        // Create options items
        $options = $behavior->options_form($options);
        if (!empty($options)) {
          // HACK.  In order to use ctools form
          // dependencies, we have to use a hidden
          // field as it supports processing and IDs.
          $form[$key]['options_set'][$key . '-prefix'] = array(
            '#type' => 'hidden',
            '#id' => $key . '-options',
            '#prefix' => '<div><fieldset id="' . $key . '-options' .
              '" class="collapsible">',
            '#process' => array('ctools_dependent_process'),
            '#dependency' => array($key . '-enabled' => array(1)),
            '#weight' => -1000,
          );
          $form[$key]['options_set']['options'] = $options;
          $form[$key]['options_set'][$key . '-suffix'] = array(
            '#value' => '</fieldset></div>',
            '#weight' => 1000,
          );
        }
      }
    }
    else {
    }
  }
  return $form;
}

/**
 * Callback sorting behaviors alphabetically
 */
function _openlayers_ui_sort_behaviors($a, $b) {
  return strnatcmp($a['title'], $b['title']);
}

/**
 * Create Centering Map
 *
 * Create map for interactive default centering
 *
 * @param $defaults
 *   Array of defults to use for the map of centering and zooming
 * @return
 *   Themed map array
 */
function openlayers_ui_maps_form_center_map($defaults = array()) {
  // Pass variables etc. to javascript
  $pass_values = array(
    'openlayersForm' => array(
      'projectionLayers' => openlayers_ui_get_projection_options(),
    ),
  );
  drupal_add_js($pass_values, 'setting');

  // centerpoint & zoom of this map are overridden
  // by the mapformvalues behavior on page load.
  //
  // Note that navigation screws up the boxselect
  // behavior for getting extent.
  $centermap_def = array(
    'id' => 'openlayers-center-helpmap',
    'projection' => '900913',
    'displayProjection' => '900913',
    'default_layer' => 'mapquest_osm',
    'width' => '500px',
    'height' => '400px',
    'center' => array(
      'initial' => array(
        'centerpoint' => "0, 0",
        'zoom' => 2,
      ),
    ),
    'image_path' => drupal_get_path('module', 'openlayers') . '/themes/default_dark/img/',
    'layers' => array(
      'mapquest_osm',
    ),
    'behaviors' => array(
      //'openlayers_behavior_navigation' => array(),
      //'openlayers_behavior_dragpan' => array(),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_mapformvalues' => array(),
      'openlayers_behavior_boxselect' => array(),
      'openlayers_behavior_attribution' => array(),
    ),
  );
  return openlayers_render_map_data($centermap_def);
}
