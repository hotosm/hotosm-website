<?php
/**
 * @file
 * OpenLayers Views Vector Layer Type
 */

/**
 * Ctools plugin definition
 */
function openlayers_views_openlayers_views_vector_openlayers_layer_types() {
  return array(
    'title' => t('OpenLayers Views'),
    'description' => t('OpenLayers Views Vector'),
    'layer_type' => array(
      'file' => 'openlayers_views_vector.inc',
      'class' => 'openlayers_layer_type_openlayers_views_vector',
      'parent' => 'openlayers_layer_type',
    ),
  );
}

class openlayers_layer_type_openlayers_views_vector
  extends openlayers_layer_type {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_handler' => 'openlayers_views_vector',
      'layer_type' => 'openlayers_views_vector',
      'projection' => array('EPSG:4326'),
      'isBaseLayer' => FALSE,
      'vector' => TRUE,
      'type' => 'Vector',
      'url' => array(),
      'options' => array(
        'rendererOptions' => array(
          'yOrdering' => TRUE
        )
      ),
      'events' => array(),
      'views' => array(),
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    $form = array();

    $views = views_get_all_views();

    $options = array('' => '<none>');
    foreach ($views as $view) {
      foreach ($view->display as $display => $data) {
        $view->set_display($display);
        if ($data->display_plugin == 'openlayers' && ($view->display_handler->get_option('style_plugin') == 'openlayers_data')) {;
          $options[$view->name . '::' . $display] = $view->human_name . ': ' . $display;
        }
      }
    }

    $default = NULL;
    if (isset($this->data['views']['view']) && isset($this->data['views']['display'])) {
      $default = $this->data['views']['view'] . '::' . $this->data['views']['display'];
    }

    $form['views']['composite'] = array(
      '#type' => 'select',
      '#options' => $options,
      '#title' => 'View name',
      '#default_value' => isset($default) ?
        $default : '',
    );
    return $form;
  }

  function options_form_validate($form, &$form_state) {
    if (!empty($form_state['data']['views']['composite'])) {
      list($view, $display) = explode('::', $form_state['data']['views']['composite']);
      $form_state['data']['views']['view'] = $view;
      $form_state['data']['views']['display'] = $display;
      unset($form_state['data']['views']['composite']);
    }
    else {
      $field = $form_state['data']['layer_type'] . '][views][composite';
      form_set_error($field, t('A View must be set.'));
    }
  }


  /**
   * Get features for this view
   *
   * @param $view_name
   *   the view name
   * @param $display_name
   *   the view display name
   * @return
   *   array of features
   */
  function get_features() {
    if ($view = views_get_view($this->data['views']['view'])) {
      $args = array();
      // Retrieve args/filters from current view
      // to pass on to our vector layer.
      $current_view = views_get_current_view();
      if (!empty($current_view)) {
        $args = $current_view->args;
        if (isset($current_view->exposed_input)) {
          $view->set_exposed_input($current_view->exposed_input);
        }
      }

      if (isset($this->data['views']['arguments'])) {
        $args = $this->data['views']['arguments'];
      }

      $features = $view->execute_display($this->data['views']['display'], $args);

      // Get dynamic title from view
      $this->title = $view->get_title();

      $view->destroy();
    }

    $this->data['features'] = isset($features) ? $features : array();
    return $this->data['features'];
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openlayers_views') .
      '/plugins/layer_types/openlayers_views_vector.js');
    $this->get_features();
  }
}
