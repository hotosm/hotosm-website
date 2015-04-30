<?php
/**
 * @file
 * GPX Layer Type
 */

/**
 * OpenLayers GPX Layer Type class
 */
class openlayers_layer_type_gpx extends openlayers_layer_type {

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_handler' => 'gpx',
      'projection' => array('EPSG:4326'),
      'resolutions' => openlayers_get_resolutions('EPSG:4326'),
      'serverResolutions' => openlayers_get_resolutions('EPSG:4326'),
      'maxExtent' => openlayers_get_extent('EPSG', '4326'),
      'isBaseLayer' => FALSE,
      'vector' => TRUE,
      'formatOptions' => array(
        'extractWaypoints' => TRUE,
        'extractRoutes' => TRUE,
        'extractTracks' => TRUE,
        'extractAttributes' => TRUE,
      ),
      'file' => '',
    ) + parent::options_init();
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array(
      'method' => array(
        '#type' => 'select',
        '#options' => array(
          '' => 'Choose the method',
          'url' => 'Provides an URL',
          'file' => 'Upload a file',
          'raw' => 'Write GPX'
        ),
        '#default_value' => isset($this->data['method']) ?
          $this->data['method'] : '',
      ),
      'url' => array(
        '#type' => 'textfield',
        '#title' => t('URL'),
        '#description' => t('The URL of the GPX file.'),
        '#maxlength' => 2083,
        '#default_value' => isset($this->data['url']) ?
          $this->data['url'] : '',
        '#states' => array(
          'visible' => array(
            ':input[name="openlayers_layer_type_gpx[method]"]' => array('value' => 'url'),
          )
        )
      ),
      'file' => array(
        '#name' => 'files[imagelayer]',
        '#type' => 'managed_file',
        '#title' => t('GPX file'),
        '#default_value' => isset($this->data['file']) ? $this->data['file'] : '',
        '#upload_location' =>  'public://',
        '#upload_validators' => array(
          'file_validate_extensions' => array('gpx')
        ),
        '#states' => array(
          'visible' => array(
            ':input[name="openlayers_layer_type_gpx[method]"]' => array('value' => 'file'),
          )
        )
      ),
      'raw' => array(
        '#type' => 'textarea',
        '#title' => t('Raw GPX'),
        '#description' => t('Copy your GPX in this textarea. Don\'t forget that this is not intented to have a big length.'),
        '#default_value' => isset($this->data['raw']) ?
          $this->data['raw'] : '',
        '#states' => array(
          'visible' => array(
            ':input[name="openlayers_layer_type_gpx[method]"]' => array('value' => 'raw'),
          )
        )
      ),
      'formatOptions' => array(
        'extractWaypoints' => array(
          '#type' => 'checkbox',
          '#title' => t('Extract Waypoints'),
          '#description' => t('Extract waypoints from GPX.'),
          '#default_value' => isset(
            $this->data['formatOptions']['extractWaypoints']) ?
            $this->data['formatOptions']['extractWaypoints'] : TRUE,
        ),
        'extractTracks' => array(
          '#type' => 'checkbox',
          '#title' => t('Extract Tracks'),
          '#description' => t('Extract tracks from GPX.'),
          '#default_value' => isset(
          $this->data['formatOptions']['extractTracks']) ?
            $this->data['formatOptions']['extractTracks'] : TRUE,
        ),
        'extractRoutes' => array(
          '#type' => 'checkbox',
          '#title' => t('Extract Routes'),
          '#description' => t('Extract routes from GPX.'),
          '#default_value' => isset(
          $this->data['formatOptions']['extractRoutes']) ?
            $this->data['formatOptions']['extractRoutes'] : TRUE,
        ),
        'extractAttributes' => array(
          '#type' => 'checkbox',
          '#title' => t('Extract Attributes'),
          '#description' => t('Extract attributes from GPX.'),
          '#default_value' => isset(
            $this->data['formatOptions']['extractAttributes']) ?
            $this->data['formatOptions']['extractAttributes'] : TRUE,
        ),
      ),
    );
  }

  /*
 * The file is mandatory.
 */
  function options_form_validate($form, &$form_state) {
    $method = $form_state['data']['method'];

    if (empty($form_state['data'][$method])) {
      form_set_error($form_state['data']['layer_type'] . '][' . $method, 'The field cannot be empty');
    }

    if ($method == 'file') {
      if ($file = file_load($form_state['data']['file'])) {
        // TODO Why nothing here?
      }
      else {
        form_set_error($form_state['data']['layer_type'] . '][' . $method, 'Cannot access the file.');
      }
    }

    $form_state['data']['formatOptions']['extractWaypoints'] = $form_state['data']['formatOptions']['extractWaypoints']!=0?TRUE:FALSE;
    $form_state['data']['formatOptions']['extractRoutes'] = $form_state['data']['formatOptions']['extractRoutes']!=0?TRUE:FALSE;
    $form_state['data']['formatOptions']['extractTracks'] = $form_state['data']['formatOptions']['extractTracks']!=0?TRUE:FALSE;
    $form_state['data']['formatOptions']['extractAttributes'] = $form_state['data']['formatOptions']['extractAttributes']!=0?TRUE:FALSE;
  }

  /**
   * hook_submit() of the form.
   */
  function options_form_submit($form, &$form_state) {
    parent::options_form_submit($form, $form_state);
    global $user;

    $item = $form_state['item'];
    if (isset($item->data['file']) && $file = file_load($item->data['file'])) {
      file_delete($file);
    }

    if (isset($form_state['values']['data']['file']) && $file = file_load($form_state['values']['data']['file'])) {
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      file_usage_add($file, 'openlayers', 'layer_type', $user->uid);
      $form_state['values']['data']['url'] = file_create_url($file->uri);
    }
  }

  /*
   * What to do when we delete the layer: delete the file.
   */
  function delete($item) {
    if (is_numeric($item->data['file']) && $item->data['file'] > 0) {
      $file = file_load($item->data['file']);
      file_delete($file);
    }
  }

  /**
   * Render.
   */
  function render(&$map) {
    $this->data['url'] = !empty($this->data['url']) ? file_create_url($this->data['url']) : '';
    drupal_add_js(drupal_get_path('module', 'openlayers')
      . '/plugins/layer_types/openlayers_layer_type_gpx.js');
  }
}
