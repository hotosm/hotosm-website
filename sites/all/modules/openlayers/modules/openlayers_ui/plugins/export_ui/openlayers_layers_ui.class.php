<?php
/**
 * @file
 */

class openlayers_layers_ui extends ctools_export_ui {

  function edit_form(&$form, &$form_state) {
    parent::edit_form($form, $form_state);

    $layer_types = openlayers_layer_types();
    $options = array('' => t('Select the layer type'));

    $layer = NULL;
    if ($form_state['op'] == 'edit' && $form_state['form type'] == 'edit') {
      $layer = openlayers_layer_load($form_state['item']->name);
    }
    if ($form_state['op'] == 'add' && $form_state['form type'] == 'clone') {
      $layer = openlayers_layer_load($form_state['function args'][2]->name);
      $layer->title = t('Clone of ') . $layer->title;
    }

    $form['info']['title'] = array(
      '#id' => 'layertitle',
      '#type' => 'textfield',
      '#weight' => -1,
      '#title' => t('Layer Title'),
      '#default_value' => isset($layer->title) ? $layer->title : '',
      '#description' => t('The friendly name of your layer, which will appear in the administration interface as well on the map interface if it is exposed.'),
    );
    $form['info']['name']['#machine_name']['source'] = array('info', 'title');

    $layers_options = array();

    // Go trough all layer types and get each options form.
    foreach ($layer_types as $layer_type) {

      if (is_object($layer) && get_class($layer) == $layer_type['layer_type']['class']) {
          // Layer is of current layer type.
        $layer_type_object = $layer;
      } else {
        // Otherwise load layer object for current layer type.
        $layer_type_object = openlayers_layer_type_load($layer_type['name']);
      }

      $layer_options_form = array();
      if (method_exists($layer_type_object, 'options_form')) {
        // This is because the class openlayers_layer_type
        // is not abstract.
        // Maybe there's a better way to do ?
        $parent = get_parent_class($layer_type_object);
        $parent_object = new $parent;
        $layer_options_form = $layer_type_object->options_form() + $parent_object->options_form($layer);
      }
      // TODO First case can never be true without crashing earlier
      if ($layer_type_object == FALSE || empty($layer_options_form)) {
        continue;
      }

      $layers_option = array(
        '#type' => 'fieldset',
        '#tree' => TRUE,
        '#title' => t('Layer specific options for @layer_title', array('@layer_title' => $layer_type['title'])),
      );

      $layers_option += $layer_options_form;
      $layers_option['#states'] = array(
        'visible' => array(
          ':input[name="layer_type"]' => array('value' => $layer_type['name']),
        ),
      );

      $layers_option['layer_type'] = array(
        '#type' => 'hidden',
        '#value' => $layer_type['name'],
      );

      $layers_options[$layer_type['name']] = $layers_option;

      $options[$layer_type['name']] = $layer_type['title'];
    }

    $form['layer_type'] = array(
      '#type' => 'select',
      '#title' => t('Layer Type'),
      '#default_value' => isset($layer->data['layer_type']) ? $layer->data['layer_type']: '',
      '#description' => t('Select the type of layer.'),
      '#options' => $options,
    );

    $form += $layers_options;

    $form['buttons']['submit']['#weight'] = 0;
    $form['buttons']['delete']['#weight'] = 20;

    $form['buttons']['saveandedit'] = array(
      '#type' => 'submit',
      '#value' => t('Save and edit'),
      '#weight' => 10
    );
  }

  function edit_form_validate(&$form, &$form_state) {
    ctools_get_plugins('openlayers', 'layer_types');

    $layer = openlayers_layer_type_load($form_state['values']['layer_type']);
    $form_state['values']['data'] = $form_state['values'][$form_state['values']['layer_type']];

    if (empty($form_state['values']['layer_type'])) {
      form_set_error('layer_type', 'Layer type cannot be empty.');
    }

    $parent = get_parent_class($layer);
    $parent_object = new $parent;
    $form_state['values']['data'] += $layer->options_init();
    $form_state['values']['data'] += $parent_object->options_init();

    $layer_types = openlayers_layer_types();

    foreach($layer_types as $layer_type) {
      unset($form_state['values'][$layer_type['name']]);
    }

    unset($form_state['values']['layer_type']);

    if (method_exists($layer, 'options_form_validate')) {
      $layer->options_form_validate($form, $form_state['values']);
    }
    parent::edit_form_validate($form, $form_state);
  }

  /**
   * Prepare the tag values before they are added to the database.
   */
  function edit_form_submit(&$form, &$form_state) {
    $layer = openlayers_layer_type_load($form_state['values']['data']['layer_type']);
    $layer->options_form_submit($form, $form_state);

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
        $path = ('add' != $op) ? current_path() : 'admin/structure/openlayers/layers/list/' . $name . '/edit';
        $this->plugin['redirect'][$op] = array($path, $options);
      }
    }
    return $output;
  }

  /**
   * Deletes exportable items from the database.
   */
  function delete_form_submit(&$form_state) {

    $item = $form_state['item'];

    $layer = openlayers_layer_type_load($item->data['layer_type']);
    if (method_exists($layer, 'delete')) {
      $layer->delete($item);
    }

    parent::delete_form_submit($form_state);
  }

  /**
   * hook_menu() entry point.
   *
   * Child implementations that need to add or modify menu items should
   * probably call parent::hook_menu($items) and then modify as needed.
   */
  function hook_menu(&$items) {
    parent::hook_menu($items);
    $items['admin/structure/openlayers/layers']['type'] = MENU_LOCAL_TASK;
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

    $layers_types = openlayers_layer_types();
    if (!isset($layers_types[$item->data['layer_type']])) {
      return;
    }

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

    $this->rows[$name]['data'][] = array('data' => $item->title, 'class' => array('ctools-export-ui-title'));
    $this->rows[$name]['data'][] = array('data' => $layers_types[$item->data['layer_type']]['title'], 'class' => array('ctools-export-ui-layer-type'));
    $this->rows[$name]['data'][] = array('data' => $item->description, 'class' => array('ctools-export-ui-description'));
    $this->rows[$name]['data'][] = array('data' => check_plain($item->{$schema['export']['export type string']}), 'class' => array('ctools-export-ui-storage'));

    // This should be in the module openlayers_views, but I'm still looking
    // for a solution to do it properly.
    // Temporarily removed.
    /*
    if ($item->data['layer_type'] == 'openlayers_views_vector') {
      $operations['edit']['href'] = 'admin/structure/views/view/' . $item->data['views']['view'] . '/edit/' . $item->data['views']['display'];
      $operations['disable']['href'] = 'admin/structure/views/view/' . $item->data['views']['view'] . '/disable/' . $item->data['views']['display'];
      $operations['clone']['href'] = 'admin/structure/views/view/' . $item->data['views']['view'] . '/clone/' . $item->data['views']['display'];
      $operations['export']['href'] = 'admin/structure/views/view/' . $item->data['views']['view'] . '/export/' . $item->data['views']['display'];
    }
    */
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
    $header[] = array('data' => t('Type'), 'class' => array('ctools-export-ui-layer-type'));
    $header[] = array('data' => t('Description'), 'class' => array('ctools-export-ui-description'));
    $header[] = array('data' => t('Storage'), 'class' => array('ctools-export-ui-storage'));
    $header[] = array('data' => t('Operations'), 'class' => array('ctools-export-ui-operations'));

    return $header;
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
