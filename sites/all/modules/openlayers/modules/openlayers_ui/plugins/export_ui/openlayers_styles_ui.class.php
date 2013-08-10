<?php
/**
 * @file
 */

class openlayers_styles_ui extends ctools_export_ui {

  /**
   * Prepare the tag values before they are added to the database.
   */
  function edit_form_submit(&$form, &$form_state) {
    $style_data = $form_state['values']['style_data'];

    // Cast and unset values so JS can handle them better,
    // Unless values are in the form ${attribute}
    foreach ($form_state['values']['data'] as $key => $value) {
      if ($form_state['values']['data'][$key] === '') {
        unset($form_state['values']['data'][$key]);
      }
      elseif (isset($style_data[$key]['type']) &&
        strpos($form_state['values']['data'][$key], '${') !== 0) {
        if ($style_data[$key]['type'] == 'integer') {
          $form_state['values']['data'][$key] =
            (int) $form_state['values']['data'][$key];
        }
        elseif ($style_data[$key]['type'] == 'float') {
          $form_state['values']['data'][$key] =
            (float) $form_state['values']['data'][$key];
        }
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

    // Add the icon as an image in the row if it exists.
    if (isset($item->data['externalGraphic'])) {
      $style = theme('image', array('path' => $item->data['externalGraphic']));
    }
    else {
      $style = openlayers_ui_style_preview($item);
    }

    $this->rows[$name]['data'][] = array('data' => $style, 'class' => array('ctools-export-ui-preview'));

    // If we have an admin title, make it the first row.
    if (!empty($this->plugin['export']['admin_title'])) {
      $this->rows[$name]['data'][] = array('data' => check_plain($item->{$this->plugin['export']['admin_title']}), 'class' => array('ctools-export-ui-title'));
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
