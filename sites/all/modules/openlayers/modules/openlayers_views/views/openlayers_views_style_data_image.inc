<?php

/**
 * @file
 * This file holds style plugin for OpenLayers Views
 *
 * @ingroup openlayers
 */

/**
 * @class
 * Extension of the Views Plugin Style for OpenLayers
 *
 * This class extended the default views plugin class to provide
 * a style plugin for the Open Layers module.
 */
class openlayers_views_style_data_image extends views_plugin_style {

  /**
   * Set default options
   *
   * Overrides views_plugin_style->option_definition
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['config'] = array();
    return $options;
  }

  /**
   * Render the map.
   *
   * Overrides views_plugin_style->render
   */
  function render() {
    $view = $this->view;

    // Render fields to trigger rewriting and other field processing.
    $this->view->style_plugin->render_fields($this->view->result);
    $image_field = isset($this->options['config']['image_field']) ? $this->options['config']['image_field'] : NULL;
    $factor_x = !empty($this->options['config']['factors']['x']) ? $this->options['config']['factors']['x'] : 1;
    $factor_y = !empty($this->options['config']['factors']['y']) ? $this->options['config']['factors']['y'] : 1;
    $numzoomlevels = !empty($this->options['config']['numZoomLevels']) ? $this->options['config']['numZoomLevels'] : 1;
    $maxextent = !empty($this->options['config']['maxExtent']) ? $this->options['config']['maxExtent'] : NULL;

    foreach ($this->view->result as $count => $row) {
      if (isset($view->style_plugin->rendered_fields[$count][$image_field])) {
        $image = $view->style_plugin->rendered_fields[$count][$image_field];
        $value = $view->style_plugin->get_field_value($count, $image_field);
        $field_output = array_shift($value);

        $data[] = array(
          'file' => $image,
          'size' => array(
            'w' => floatval($field_output['width']),
            'h' => floatval($field_output['height'])
          ),
          'factors' => array(
            'x' => floatval($factor_x),
            'y' => floatval($factor_y)
          ),
          'numZoomLevels' => floatval($numzoomlevels),
          'maxExtent' => $maxextent
        );
      }
    }

    if (!empty($data)) {
      // Skip rendering if view is being edited or previewed.
      if (empty($this->view->live_preview)) {
        return $data[0];
      } else {
        return print_r($data[0], 1);
      }
    } else {
      return '';
    }
  }

  /**
   * Options form
   *
   * Overrides views_plugin_style->options_form
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Get list of fields in this view & flag available geodata fields
    $handlers = $this->display->handler->get_handlers('field');

    // Check for any fields, as the view needs them
    if (empty($handlers)) {
      $form['error_markup'] = array(
        '#value' => t('You need to enable at least one field before you can '
          . 'configure your field settings'),
        '#prefix' => '<div class="error form-item description">',
        '#suffix' => '</div>',
      );
      return;
    }

    $fields = array();
    foreach ($handlers as $field_id => $handler) {
      $fields[$field_id] = $handler->ui_name();
    }

    $form['config'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => t('Image Source'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['config']['image_field'] = array(
      '#type' => 'select',
      '#title' => t('Map Data Sources'),
      '#description' => t('Choose which sources of data that the map will '
      . 'provide features for.'),
      '#options' => $fields,
      '#default_value' => $this->options['config']['image_field'],
    );
    $form['config']['factors'] = array(
      '#tree' => TRUE,
      'x' => array(
        '#title' => 'Width divider',
        '#type' => 'textfield',
        '#default_value' => isset($this->options['config']['factors']['x']) ? $this->options['config']['factors']['x'] : 1,
        '#description' => t('Width divider.'),
      ),
      'y' => array(
        '#title' => 'Height divider',
        '#type' => 'textfield',
        '#default_value' => isset($this->options['config']['factors']['y']) ? $this->options['config']['factors']['y'] : 1,
        '#description' => t('Height divider.'),
      ),
    );
    $form['config']['maxExtent'] = array(
      '#type' => 'textfield',
      '#title' => t('Max Extent'),
      '#default_value' => isset($this->options['config']['maxExtent']) ? implode(', ', $this->options['config']['maxExtent']) : '',
      '#description' => t('Should consist of four values (left, bottom, right, top). The maximum extent for the layer. Image is stretched to cover whole map if left empty.'),
    );
    $form['config']['numZoomLevels'] = array(
      '#title' => 'Zoomlevels',
      '#type' => 'textfield',
      '#default_value' => isset($this->options['config']['numZoomLevels']) ? $this->options['config']['numZoomLevels'] : 1
    );
  }
}
