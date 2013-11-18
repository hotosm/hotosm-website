<?php
/**
 * @file
 */

class openlayers_maps_ui extends ctools_export_ui {

  function edit_form(&$form, &$form_state) {
    parent::edit_form($form, $form_state);

    $map = $form_state['item'];
    if (empty($map->name)) {
      $map = NULL;
    }

    module_load_include('inc', 'openlayers_ui', 'includes/openlayers_ui.maps');

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
    $defaults['projection'] = openlayers_get_projection_by_identifier($defaults['projection']);
    $defaults['displayProjection'] = openlayers_get_projection_by_identifier($defaults['displayProjection']);

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
    $form['info']['#type'] = 'fieldset';
    $form['info']['#group'] = 'ui';
    $form['info']['#title'] = 'Infos';

    $form['info']['title'] = array(
      '#id' => 'maptitle',
      '#type' => 'textfield',
      '#title' => t('Map Title'),
      '#description' => t('This is the descriptive title of the map and will show up most often in the interface.'),
      '#maxlength' => 255,
      '#default_value' => !empty($map->title) ? $map->title : '',
      '#required' => TRUE,
      '#weight' => -1
    );
    $form['info']['name']['#machine_name']['source'] = array('info', 'title');

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
      '#type' => 'fieldset',
      '#title' => t('Layers & Styles'),
      '#description' => t('Layer settings.  The Layer options will change based on the projection chosen.'),
      '#theme' => 'openlayers_ui_maps_form_layers',
      '#tree' => TRUE,
      '#group' => 'ui',
      '#prefix' => '',
      '#suffix' => ''
    );

    // Projection options
    $projections = array();
    foreach (openlayers_ui_get_projection_options() as $projection) {
      $projection_layers = array_merge(
        openlayers_ui_get_layer_options('baselayer', $projection),
        openlayers_ui_get_layer_options('overlay', $projection));

      $projections[$projection->identifier] = theme(
        'openlayers_ui_form_projection_description',
        array(
          'projection' => $projection,
          'available_layers' => $projection_layers
        )
      );
    }

    $form['layerstyles']['projections'] = array(
      '#type' => 'fieldset',
      '#title' => t('Projections'),
      '#description' => t('<p><strong>WARNING: Projections are not well supported in
      this module.  If you need to handle non spherical mercator projections
      you may be better using the API directly.</strong></p>
      <p>Select the !link_proj for your map.  The list next
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
      '#default_value' => $defaults['projection']->identifier,
      '#options' => $projections,
      '#attributes' => array('class' => array('openlayers-form-easy-projection')),
      '#ajax' => array(
        'callback' => 'openlayers_map_layerlist',
        'wrapper' => 'edit-layerstyles',
        'method' => 'replace',
        'event' => 'change'
      )
    );
    $displayProjectionOptions = array();
    foreach(openlayers_ui_get_projection_options() as $projectionIdentifier => $projection){
      $displayProjectionOptions[$projectionIdentifier] = $projection->getLocalizedMessage();
    }
    $form['layerstyles']['projections']['displayProjection'] = array(
      '#type' => 'select',
      '#title' => t('Display Projection'),
      '#description' => t('All interaction with the map - drawing, panning,
      centering, and more - occurs in the display projection. The vast majority
      of maps use 4326 (latitude/longitude) for this value.'),
      '#default_value' => !empty($defaults['displayProjection']) ?
        $defaults['displayProjection']->identifier : openlayers_get_projection('EPSG', '4326')->identifier,
      '#options' => $displayProjectionOptions,
    );

    $form['layerstyles']['layers'] = array(
      '#title' => t('Layers & Styles'),
      '#description' => t('Layer settings.  The Layer options will change based on the projection chosen.'),
      '#type' => 'fieldset',
    );

    // Construct data for theme_openlayers_ui_maps_form_layers
    $form['layerstyles']['layers']['#tree'] = TRUE;
    $form['layerstyles']['layers']['baselabels'] = array();
    if(isset($form_state['values']['layerstyles']['projections']['easy_projection'])){
      // Projection was choosen by editing the form
      $easy_projection = openlayers_get_projection_by_identifier($form_state['values']['layerstyles']['projections']['easy_projection']);
    } else {
      // Form was not yet edited, use default
      $easy_projection = $defaults['projection'];
    }
    $base_options = openlayers_ui_get_layer_options('baselayer', $easy_projection);
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
    $overlay_options = openlayers_ui_get_layer_options('overlay', $easy_projection);
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
      $form['layerstyles']['layer_styles_temporary']['#tree'] = TRUE;
      $form['layerstyles']['layer_weight']['#tree'] = TRUE;
      foreach ($overlay_options_keys as $id) {
        $description = $overlay_options[$id];
        $form['layerstyles']['layers']['overlaylabels'][$id] = array('#markup' => $description);

        // Layer styles that define the default style of layer.
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

        // Layer temporary style.
        $form['layerstyles']['layer_styles_temporary'][$id] = array(
          '#type' => 'select',
          '#options' => array('<' . t('use default style') . '>') + openlayers_ui_get_style_options(),
          '#default_value' => !empty($defaults['layer_styles_temporary'][$id]) ?
            $defaults['layer_styles_temporary'][$id] : '',
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

    $form['buttons']['submit']['#weight'] = 0;
    $form['buttons']['delete']['#weight'] = 20;

    $form['buttons']['saveandedit'] = array(
      '#type' => 'submit',
      '#value' => t('Save and edit'),
      '#weight' => 10
    );

    // Add preview button.
    $form['buttons']['preview'] = array(
      '#type' => 'button',
      '#value' => t('Preview'),
      '#weight' => 30
    );
  }

  /**
   * Prepare the tag values before they are added to the database.
   */
  function edit_form_submit(&$form, &$form_state) {
    module_load_include('inc', 'openlayers_ui', 'includes/openlayers_ui.maps');
    $form_state['values']['data'] = openlayers_ui_maps_form_process($form_state['values']);
    parent::edit_form_submit($form, $form_state);
  }

  /**
   * Implements ctools_export_ui::edit_execute_form().
   *
   * This is hacky, but since CTools Export UI uses drupal_goto() we have to
   * effectively change the plugin to modify the redirect path dynamically.
   */
  function edit_execute_form(&$form_state) {
    $output = parent::edit_execute_form($form_state);
    if (!empty($form_state['executed'])) {
      $clicked = $form_state['clicked_button']['#value'];
      if (t('Save and edit') == $clicked) {
        // We always want to redirect back to this page when adding an item,
        // but we want to preserve the destination so we can be redirected back
        // to where we came from after clicking "Save".
        $options = array();
        if (!empty($_GET['destination'])) {
          $options['query']['destination'] = $_GET['destination'];
          unset($_GET['destination']);
        }

        // Sets redirect path and options.
        $op = $form_state['op'];
        $name = $form_state['values']['name'];
        $path = ('add' != $op) ? current_path() : 'admin/structure/openlayers/maps/list/' . $name . '/edit';
        $this->plugin['redirect'][$op] = array($path, $options);
      }
    }
    return $output;
  }

  /**
   * Build a row based on the item.
   *
   * By default all of the rows are placed into a table by the render
   * method, so this is building up a row suitable for theme('table').
   * This doesn't have to be true if you override both.
   */
  function list_build_row($item, &$form_state, $operations) {
    // Set up sorting
    $name = $item->{$this->plugin['export']['key']};
    $schema = ctools_export_get_schema($this->plugin['schema']);

    // Note: $item->{$schema['export']['export type string']} should have already been set up by export.inc so
    // we can use it safely.
    switch ($form_state['values']['order']) {
      case 'disabled':
        $this->sorts[$name] = empty($item->disabled) . $name;
        break;
      case 'title':
        $this->sorts[$name] = $item->{$this->plugin['export']['admin_title']};
        break;
      case 'name':
        $this->sorts[$name] = $name;
        break;
      case 'storage':
        $this->sorts[$name] = $item->{$schema['export']['export type string']} . $name;
        break;
    }

    $this->rows[$name]['data'] = array();
    $this->rows[$name]['class'] = !empty($item->disabled) ? array('ctools-export-ui-disabled') : array('ctools-export-ui-enabled');

    // If we have an admin title, make it the first row.
    if (!empty($this->plugin['export']['admin_title'])) {
      $this->rows[$name]['data'][] = array('data' => check_plain($item->{$this->plugin['export']['admin_title']}), 'class' => array('ctools-export-ui-title'));
    }

    $layers = openlayers_layers_load();
    $layers_names = array();
    foreach ($item->data['layers'] as $layer) {
      if (isset($layers[$layer])) {
        $layers_names[] = empty($layers[$layer]->title) ? $layer : filter_xss_admin($layers[$layer]->title);
      }
    }

    sort($layers_names);
    $layers_names = implode(',', $layers_names);

    $this->rows[$name]['data'][] = array('data' => $item->title, 'class' => array('ctools-export-ui-title'));
    $this->rows[$name]['data'][] = array('data' => $layers_names, 'class' => array('ctools-export-ui-layers'));
    $this->rows[$name]['data'][] = array('data' => $item->description, 'class' => array('ctools-export-ui-description'));
    $this->rows[$name]['data'][] = array('data' => check_plain($item->{$schema['export']['export type string']}), 'class' => array('ctools-export-ui-storage'));

    $ops = theme('links__ctools_dropbutton', array('links' => $operations, 'attributes' => array('class' => array('links', 'inline'))));

    $this->rows[$name]['data'][] = array('data' => $ops, 'class' => array('ctools-export-ui-operations'));

    // Add an automatic mouseover of the description if one exists.
    if (!empty($this->plugin['export']['admin_description'])) {
      $this->rows[$name]['title'] = $item->{$this->plugin['export']['admin_description']};
    }
  }

  /**
   * Provide the table header.
   *
   * If you've added columns via list_build_row() but are still using a
   * table, override this method to set up the table header.
   */
  function list_table_header() {
    $header = array();
    if (!empty($this->plugin['export']['admin_title'])) {
      $header[] = array('data' => t('Name'), 'class' => array('ctools-export-ui-name'));
    }

    $header[] = array('data' => t('Title'), 'class' => array('ctools-export-ui-title'));
    $header[] = array('data' => t('Layers'), 'class' => array('ctools-export-ui-layers'));
    $header[] = array('data' => t('Description'), 'class' => array('ctools-export-ui-description'));
    $header[] = array('data' => t('Storage'), 'class' => array('ctools-export-ui-storage'));
    $header[] = array('data' => t('Operations'), 'class' => array('ctools-export-ui-operations'));

    return $header;
  }

  /**
   * hook_menu() entry point.
   *
   * Child implementations that need to add or modify menu items should
   * probably call parent::hook_menu($items) and then modify as needed.
   */
  function hook_menu(&$items) {
    parent::hook_menu($items);
    $items['admin/structure/openlayers/maps']['type'] = MENU_LOCAL_TASK;
    $items['admin/structure/openlayers/maps/list/%ctools_export_ui/clone']['context'] = MENU_CONTEXT_INLINE;
    $items['admin/structure/openlayers/maps/list/%ctools_export_ui/edit']['context'] = MENU_CONTEXT_INLINE;
    $items['admin/structure/openlayers/maps/list/%ctools_export_ui/export']['context'] = MENU_CONTEXT_INLINE;
    $items['admin/structure/openlayers/maps/list/%ctools_export_ui/revert']['context'] = MENU_CONTEXT_INLINE;
    $items['admin/structure/openlayers/maps/list/%ctools_export_ui/clone']['type'] = MENU_LOCAL_TASK;
    $items['admin/structure/openlayers/maps/list/%ctools_export_ui/edit']['type'] = MENU_LOCAL_TASK;
    $items['admin/structure/openlayers/maps/list/%ctools_export_ui/export']['type'] = MENU_LOCAL_TASK;
    $items['admin/structure/openlayers/maps/list/%ctools_export_ui/revert']['type'] = MENU_LOCAL_TASK;
  }

  /**
   * Provide a list of sort options.
   *
   * Override this if you wish to provide more or change how these work.
   * The actual handling of the sorting will happen in build_row().
   */
  function list_sort_options() {
    if (!empty($this->plugin['export']['admin_title'])) {
      $options = array(
        'disabled' => t('Enabled, title'),
        $this->plugin['export']['admin_title'] => t('Title'),
      );
    }
    else {
      $options = array(
        'disabled' => t('Enabled, title'),
      );
    }

    $options += array(
      'storage' => t('Storage'),
    );

    return $options;
  }


}
