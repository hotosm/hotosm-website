<?php
/**
 * @file
 */

class openlayers_styles_ui extends ctools_export_ui {

  function edit_form(&$form, &$form_state) {
    parent::edit_form($form, $form_state);

    $style = $form_state['item'];
    if (empty($style->name)) {
      $style = NULL;
    }

    module_load_include('inc', 'openlayers_ui', 'includes/openlayers_ui.styles');

    $properties = array(
      'externalGraphic' => array(
        'default' => '',
        'desc' => t('The URL of an icon for points in a layer.  The following options are available:
        <ul><li>Full path, such as http://example.com/icon.png</li>
        <li>Relative Drupal path, such as sites/all/modules/example/icon.png</li>
        <li>Absolute path, such as /icon.png (though this is not suggested for maintainability reasons)</li></ul>'),
        'maxlength' => 2083
      ),
      'imageStyle' => array(
        'type'    => 'select',
        'title'    => 'Image style',
        'options' => array(''=> 'None (original image)') + image_style_options(FALSE),
        'default' => '',
        'desc'    => t('The Drupal Image Style to apply to the marker.'),
      ),
      'pointRadius' => array(
        'default' => 6,
        'desc' => t('The radius of a vector point or the size of
        an icon. Note that, when using icons, this value should be half the
        width of the icon image.'),
        'type' => 'integer',
      ),
      'fillColor' => array(
        'default' => '#EE9900',
        'desc' => t('This is the color used for
        filling in Polygons. It is also used in the center of marks for
        points: the interior color of circles or other shapes. It is
        not used if an externalGraphic is applied to a point.  This should be
        a hexadecimal value like #FFFFFF.'),
      ),
      'strokeColor' => array(
        'default' => '#EE9900',
        'desc' => t('This is color of the line on features. On
        polygons and point marks, it is used as an outline to the feature.
        On lines, this is the representation of the feature.  This should be
        a hexadecimal value like #FFFFFF.'),
      ),
      'strokeWidth' => array(
        'default' => 1,
        'desc' => t('This is width of the line on features. On
        polygons and point marks, it is used as an outline to
        the feature. On lines, this is the representation of the
        feature.  This is a value in pixels.'),
        'type' => 'integer',
        'element_validate' => array('element_validate_integer_positive'),
      ),
      'fillOpacity' => array(
        'default' => 1,
        'desc' => t('This is the opacity used for filling in Polygons.
        It is also used in the center of marks for points: the interior
        color of circles or other shapes. It is not used if an
        externalGraphic is applied to a point.  This should be a value
        between 0 and 1.'),
        'type' => 'float',
        'element_validate' => array('_element_validate_between_zero_and_one', 'element_validate_number'),
      ),
      'strokeOpacity' => array(
        'default' => 1,
        'desc' => t('This is opacity of the line on features.
        On polygons and point marks, it is used as an outline to the
        feature. On lines, this is the representation of the feature.
        This should be a value between 0 and 1.'),
        'type' => 'float',
        'element_validate' => array('_element_validate_between_zero_and_one', 'element_validate_number'),
      ),
      'strokeLinecap' => array(
        'default' => 'round',
        'desc' => t('Options are butt, round, square. This property
        is similar to the SVG stroke-linecap property. It determines
        what the end of lines should look like. See the SVG link for
        image examples.'),
        'options' => array(
          'butt' => t('Butt'),
          'round' => t('Round'),
          'square' => t('Square'),
        ),
      ),
      'strokeDashstyle' => array(
        'default' => 'solid',
        'desc' => t('Options are dot, dash, dashdot, longdash, longdashdot, solid.'),
        'options' => array(
          'dot' => t('Dot'),
          'dash' => t('Dash'),
          'dashdot' => t('Dash-dot'),
          'longdash' => t('Long-dash'),
          'longdashdot' => t('Long-dash-dot'),
          'solid' => t('Solid'),
        ),
      ),
      'cursor' => array(
        'default' => '',
        'desc' => t('Cursor used when mouse is over the feature. Default
        is an empty string, which inherits from parent elements.  See
        <a href="!url">CSS cursor styles</a>.', array(
          '!url' => 'http://www.w3schools.com/css/pr_class_cursor.asp',
        )),
      ),
      'graphicWidth' => array(
        'default' => '',
        'desc' => t('This properties define the width of an externalGraphic.
        This is an alternative to the pointRadius symbolizer property
        to be used when your graphic has different sizes in the X and
        Y direction.  This should be in pixels.'),
        'type' => 'integer',
        'element_validate' => array('element_validate_integer_positive'),
      ),
      'graphicHeight' => array(
        'default' => '',
        'desc' => t('This properties define the height of an externalGraphic.
        This is an alternative to the pointRadius symbolizer property
        to be used when your graphic has different sizes in the X and
        Y direction.  This should be in pixels.'),
        'type' => 'integer',
        'element_validate' => array('element_validate_integer_positive'),
      ),
      'graphicOpacity' => array(
        'default' => '1',
        'desc' => t('Opacity of an external graphic.  This should be a
        value between 0 and 1. Graphics that are already semitransparent,
        like alpha PNGs, should have this set to 1, or rendering problems in
        Internet Explorer will ensue.'),
        'type' => 'float',
        'element_validate' => array('_element_validate_between_zero_and_one', 'element_validate_number'),
      ),
      'graphicXOffset' => array(
        'default' => '',
        'desc' => t('Where the X value of the "center" of an
      externalGraphic should be.  This should be in pixels.'),
        'type' => 'integer',
        'element_validate' => array('element_validate_integer'),
      ),
      'graphicYOffset' => array(
        'default' => '',
        'desc' => t('Where the Y value of the "center" of an
      externalGraphic should be.  This should be in pixels.'),
        'type' => 'integer',
        'element_validate' => array('element_validate_integer'),
      ),
      'graphicName' => array(
        'default' => '',
        'desc' => t('Name of a type of symbol to be used
        for a point mark.'),
      ),
      'rotation' => array(
        'default' => '',
        'desc' => t('The rotation angle in degrees clockwise for
        a point symbolizer.'),
      ),
      'display' => array(
        'default' => '',
        'desc' => t('Can be set to "none" to hide features
        from rendering.'),
        'options' => array(
          '' => t('On'),
          'none' => t('None (off)'),
        ),
      ),
      'label' => array(
        'default' => '',
        'desc' => t('A label to show for features. '
          . 'Typically used with ${attribute} syntax.')
      ),
      'labelAlign' => array(
        'default' => 'cm',
        'desc' => t('Label alignment.'),
        'options' => array(
          'cm' => t('Center, middle'),
          'ct' => t('Center, top'),
          'cb' => t('Center, bottom'),
          'lm' => t('Left, middle'),
          'lt' => t('Left, top'),
          'lb' => t('Left, bottom'),
          'rm' => t('Right, middle'),
          'rt' => t('Right, top'),
          'rb' => t('Right, bottom'),
        ),
      ),
      'labelXOffset' => array(
        'default' => '',
        'desc' => t('Label X offset. Positive numbers move label right.'),
        'type' => 'integer',
        'element_validate' => array('element_validate_integer'),
      ),
      'labelYOffset' => array(
        'default' => '',
        'desc' => t('Label Y offset. Positive numbers move label up.'),
        'type' => 'integer',
        'element_validate' => array('element_validate_integer'),
      ),
      'fontColor' => array(
        'default' => '',
        'desc' => t('Label font color.'),
      ),
      'fontSize' => array(
        'default' => '',
        'desc' => t('Label font size.'),
      ),
      'fontFamily' => array(
        'default' => '',
        'desc' => t('Label font family.'),
      ),
      'fontWeight' => array(
        'default' => '',
        'desc' => t('Label font weight.'),
      ),
    );

    // Provide a preview of the style
    if (isset($form_state['clicked_button']['#id']) && ($form_state['clicked_button']['#id'] == 'edit-preview')) {
      $preview_style = new stdClass();
      $preview_style->name = $form_state['values']['name'];
      $preview_style->title = $form_state['input']['title'];
      $preview_style->description = $form_state['input']['description'];
      $preview_style->data = $form_state['input']['data'];

      $form['info']['preview_style_container'] = array(
        '#type' => 'item',
        '#title' => t('Preview'),
        '#markup' => openlayers_ui_style_preview($preview_style, TRUE),
        '#description' => t('If you are using attribute replacement, the style may not show properly.  The crosshairs point out where the feature is centered.'),
      );
    }

    $form['info']['title'] = array(
      '#id' => 'styletitle',
      '#type' => 'textfield',
      '#weight' => -1,
      '#title' => t('Style title'),
      '#default_value' => isset($style->title) ? $style->title : '',
      '#description' => t('The friendly name of your style, which will appear in the administration interface as well on the map interface.'),
    );
    $form['info']['name']['#machine_name']['source'] = array('info', 'title');

    // OpenLayers style properties
    $form['data'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => t('Style Properties'),
      '#description' => t('The specific properties for the style.'),
    );
    foreach ($properties as $key => $prop) {
      $form['data'][$key] = array(
        '#type' => !isset($prop['options']) ? 'textfield' : 'select',
        '#title' => !isset($prop['title']) ? check_plain($key) : check_plain($prop['title']),
        '#description' => filter_xss($prop['desc']),
        '#default_value' => isset($style->data[$key]) ?
          $style->data[$key] : $prop['default'],
        '#element_validate' => isset($prop['element_validate']) ?
          $prop['element_validate'] : array(),
        '#element_validate' => isset($prop['element_validate']) ?
          $prop['element_validate'] : array()    );

      // Add options if needed
      if (isset($prop['options']) && is_array($prop['options'])) {
        $form['data'][$key]['#options'] = $prop['options'];
      }
      // Add maxlength if needed
      if (isset($prop['maxlength']) && is_numeric($prop['maxlength'])) {
        $form['data'][$key]['#maxlength'] = $prop['maxlength'];
      }
    }

    // Add preview button.
    $form['buttons']['preview'] = array(
      '#type' => 'button',
      '#value' => t('Preview'),
    );

  }

  function edit_form_validate(&$form, &$form_state) {}

  /**
   * Prepare the tag values before they are added to the database.
   */
  function edit_form_submit(&$form, &$form_state) {
    // Cast and unset values so JS can handle them better,
    // Unless values are in the form ${attribute}
    foreach ($form_state['values']['data'] as $key => $value) {
      if (is_numeric($form_state['values']['data'][$key])) {
        $form_state['values']['data'][$key] = (float) $form_state['values']['data'][$key];
      }
      if (empty($form_state['values']['data'][$key])) {
        unset($form_state['values']['data'][$key]);
      }
    }

    parent::edit_form_submit($form, $form_state);
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

    $this->rows[$name]['data'][] = array('data' => openlayers_ui_style_preview($item), 'class' => array('ctools-export-ui-preview'));

    // If we have an admin title, make it the first row.
    if (!empty($this->plugin['export']['admin_title'])) {
      $this->rows[$name]['data'][] = array('data' => check_plain($item->{$this->plugin['export']['admin_title']}), 'class' => array('ctools-export-ui-admin-title'));
    }

    $this->rows[$name]['data'][] = array('data' => $item->title, 'class' => array('ctools-export-ui-title'));
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

    $header[] = array('data' => t('Preview'), 'class' => array('ctools-export-ui-preview'));
    if (!empty($this->plugin['export']['admin_title'])) {
      $header[] = array('data' => t('Name'), 'class' => array('ctools-export-ui-name'));
    }
    $header[] = array('data' => t('Title'), 'class' => array('ctools-export-ui-title'));
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
    $items['admin/structure/openlayers/styles']['type'] = MENU_LOCAL_TASK;
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

/**
 * Custom validations functions.
 * See #element_validate in Form API.
 */
function _element_validate_between_zero_and_one($element, &$form_state, $form) {
  if ($element['#value'] < 0 || $element['#value'] > 1) {
    form_error($element, t('The @property property must be between 0 and 1.', array('@property' => $element['#title'])));
  }
}

function _element_validate_number_positive($element, &$form_state, $form) {
  if ($element['#value'] <= 0) {
    form_error($element, t('The @property property must be a positive number.', array('@property' => $element['#title'])));
  }
}
