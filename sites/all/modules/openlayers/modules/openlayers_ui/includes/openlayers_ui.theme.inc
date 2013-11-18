<?php

/**
 * @file
 * This file holds the theme functions for openlayers ui module
 *
 * @ingroup openlayers
 */

/**
 * Theme function for form description of layers
 */
function theme_openlayers_ui_form_layer_description($args) {
  if (!empty($args['layer_link'])) {
    $args['layer_title'] = l($args['layer_title'], $args['layer_link'], array('query' => drupal_get_destination()));
  }
  return $args['layer_title'] . ($args['layer_description'] ?
    ' <span class="openlayers-form-layer-description">' .
    $args['layer_description'] . '</span>' :
    '');
}

/**
 * Theme function for form description of projection
 */
function theme_openlayers_ui_form_projection_description($args) {
  $output = $args['projection']->getLocalizedMessage();
  if (count($args['available_layers'])) {
    $names = implode(', ', $args['available_layers']);
    $output .= " - <span class='openlayers-form-projection-description'>$names</span>";
  }
  return $output;
}

function theme_openlayers_ui_maps_form_layers($args) {
  $form = $args['elements'];

  $output = drupal_render($form['projections'])
    . drupal_render($form['help_data_overlays']);

  // Base layers
  $rows = array();
  foreach (element_children($form['layers']['baselabels']) as $key) {
    unset($form['layers']['default_layer'][$key]['#title']);
    unset($form['layers']['baselayers'][$key]['#title']);

    $rows[] = array(
      drupal_render($form['layers']['baselabels'][$key]),
      drupal_render($form['layers']['baselayers'][$key]),
      drupal_render($form['layers']['default_layer'][$key]));
  }
  $output_layer_list = theme('table', array(
    'header' => array(t('Base layers'), t('Enabled'), t('Default')),
    'rows' => $rows)
  );

  // Overlay layers
  $rows = array();
  foreach (element_children($form['layers']['overlaylabels']) as $key) {
    unset($form['overlays'][$key]['#title']);
    unset($form['layers']['overlays'][$key]['#title']);
    unset($form['layer_activated'][$key]['#title']);
    unset($form['layer_switcher'][$key]['#title']);

    $rows[] = array(
      'data' => array(
        drupal_render($form['layers']['overlaylabels'][$key]),
        drupal_render($form['layer_weight'][$key]),
        drupal_render($form['layers']['overlays'][$key]),
        drupal_render($form['layer_activated'][$key]),
        drupal_render($form['layer_switcher'][$key]),
        drupal_render($form['layer_styles'][$key]),
        drupal_render($form['layer_styles_select'][$key]),
        drupal_render($form['layer_styles_temporary'][$key]),
      ),
      'class' => array('draggable')
    );
  }
  $output_layer_list .= theme('table',
    array(
      'header' => array(
        t('Overlay layers'), t('Weight'), t('Enabled'),
        t('Activated'), t('In Switcher'), t('Style'), t('Select Style'),
        ('Temporary Style')
      ),
      'rows' => $rows,
      array('id' => 'overlay-layer-table')
    )
  );
  $form['layers']['layerlist']['#markup'] = $output_layer_list;
  $output .= drupal_render($form['layers']);

  drupal_add_tabledrag('overlay-layer-table', 'order', 'sibling',
    'layer-weight');
  return $form['#prefix'] . $output . drupal_render_children($form) . $form['#suffix'];
}
