<?php
class openlayers_projections_ui extends ctools_export_ui {
  function edit_form(&$form, &$form_state) {
    parent::edit_form($form, $form_state);

    // Hide internal identifier from user
    $form['info']['identifier']['#type'] = 'hidden';
    $form['info']['identifier']['#required'] = FALSE;

    $projectionData = $form_state['item'];

    $form['info']['authority'] = array(
      '#id' => 'projectionauthority',
      '#type' => 'textfield',
      '#weight' => 1,
      '#title' => t('Projection Authority'),
      '#default_value' => $projectionData->authority,
      '#description' => t('Authority defining the projection'),
      '#required' => TRUE
    );
    $form['info']['code'] = array(
      '#id' => 'projectioncode',
      '#type' => 'textfield',
      '#weight' => 2,
      '#title' => t('Projection Code'),
      '#default_value' => $projectionData->code,
      '#description' => t('Identifier (unique within authority)'),
      '#required' => TRUE
    );
    $form['info']['definition'] = array(
      '#id' => 'projectiondefinition',
      '#type' => 'textarea',
      '#weight' => 3,
      '#title' => t('proj4 Definition'),
      '#default_value' => $projectionData->definition,
      '#description' => t('Description that can be used to handle rough conversions between coordinate systems. A correct definition is essential for coordinate displays or scale bars to work properly.'),
      '#required' => TRUE
    );
    $form['info']['projectedextentleft'] = array(
      '#id' => 'projectionprojectedextentleft',
      '#type' => 'textfield',
      '#weight' => 4,
      '#title' => t('Left Extent Boundary'),
      '#default_value' => $projectionData->projectedextentleft,
      '#description' => t("Leftmost value in this projection's coordinates"),
      '#required' => TRUE
    );
    $form['info']['projectedextentbottom'] = array(
      '#id' => 'projectionprojectedextentbottom',
      '#type' => 'textfield',
      '#weight' => 5,
      '#title' => t('Bottom Extent Boundary'),
      '#default_value' => $projectionData->projectedextentbottom,
      '#description' => t("Bottommost value in this projection's coordinates"),
      '#required' => TRUE
    );
    $form['info']['projectedextentright'] = array(
      '#id' => 'projectionprojectedextentright',
      '#type' => 'textfield',
      '#weight' => 6,
      '#title' => t('Right Extent Boundary'),
      '#default_value' => $projectionData->projectedextentright,
      '#description' => t("Rightmost value in this projection's coordinates"),
      '#required' => TRUE
    );
    $form['info']['projectedextenttop'] = array(
      '#id' => 'projectionprojectedextenttop',
      '#type' => 'textfield',
      '#weight' => 7,
      '#title' => t('Top Extent Boundary'),
      '#default_value' => $projectionData->projectedextenttop,
      '#description' => t("Topmost value in this projection's coordinates"),
      '#required' => TRUE
    );
  }

  function edit_form_submit(&$form, &$form_state) {
    // Fill identifier with data from required fields. No empty string must result as ctools can't handle it.
    $form_state['values']['identifier'] = $form_state['values']['authority'].':'.$form_state['values']['code'];

    parent::edit_form_submit($form, $form_state);
  }

  function hook_menu(&$items) {
    parent::hook_menu($items);
    $items['admin/structure/openlayers/projections']['type'] = MENU_LOCAL_TASK;
  }
}