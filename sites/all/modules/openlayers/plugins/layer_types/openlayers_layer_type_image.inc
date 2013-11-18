<?php
/**
 * @file
 * Image Layer Type
 * http://dev.openlayers.org/docs/files/OpenLayers/Layer/Image-js.html
 */

/**
 * OpenLayers Image Layer Type class
 */
class openlayers_layer_type_image extends openlayers_layer_type {

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_handler' => 'image',
      'file' => NULL,
      'image_style' => NULL,
      'opacity' => 1,
      'factors' => array(
        'x' => 1,
        'y' => 1
      ),
      'numZoomLevels' => 1
    ) + parent::options_init();
  }

  /**
   * Options form which generates layers
   */
  function options_form($defaults = array()) {
    return array(
      'file' => array(
        '#name' => 'files[imagelayer]',
        '#type' => 'managed_file',
        '#title' => t('Image'),
        '#default_value' => isset($this->data['file']) ? $this->data['file'] : '',
        '#upload_location' =>  'public://',
      ),
      'image_style' => array(
        '#type' => 'select',
        '#options' => array(''=> 'None (original image)') + image_style_options(FALSE),
        '#default_value' => isset($this->data['image_style']) ? $this->data['image_style'] : NULL,
        '#description' => t('Apply an image style.'),
      ),
      'factors' => array(
        '#tree' => TRUE,
        'x' => array(
           '#title' => 'Width divider',
           '#type' => 'textfield',
           '#default_value' => isset($this->data['factors']['x']) ? $this->data['factors']['x'] : 1,
           '#description' => t('Width divider.'),
        ),
        'y' => array(
           '#title' => 'Height divider',
           '#type' => 'textfield',
           '#default_value' => isset($this->data['factors']['y']) ? $this->data['factors']['y'] : 1,
           '#description' => t('Height divider.'),
        ),
      ),
      'maxExtent' => array(
        '#type' => 'textfield',
        '#title' => t('Max Extent'),
        '#default_value' => isset($this->data['maxExtent']) ? implode(', ', $this->data['maxExtent']) : '',
        '#description' => t('Should consist of four values (left, bottom, right, top). The maximum extent for the layer. Image is stretched to cover whole map if left empty.'),
      ),
      'numZoomLevels' => array(
         '#title' => 'Zoomlevels',
         '#type' => 'textfield',
         '#default_value' => isset($this->data['numZoomLevels']) ? $this->data['numZoomLevels'] : 1
      ),
    );
  }

 /**
  * hook_validate() of the form.
  */
  function options_form_validate($form, &$form_state) {
    parent::options_form_validate($form, $form_state);
    $form_state['data']['numZoomLevels'] = intVal($form_state['data']['numZoomLevels']);
    $form_state['data']['factors']['x'] = intVal($form_state['data']['factors']['x']);
    $form_state['data']['factors']['y'] = intVal($form_state['data']['factors']['y']);

    if ($file = file_load($form_state['data']['file'])) {
      // Do something with the file if needed.
    } else {
      form_set_error($form_state['data']['layer_type'].'][file', 'Cannot access the file.');
    }
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
      file_usage_add($file, 'openlayers', 'openlayers_layer_type', $user->uid);
    }

    $style = $form_state['values']['data']['image_style'];

    if (!empty($style)) {
      $uri = image_style_path($style, $file->uri);
      image_style_create_derivative(image_style_load($style), $file->uri, $uri);
    } else {
      $uri = $file->uri;
    }

    $infos = image_get_info($uri);
    $form_state['values']['data']['size'] = array();
    $form_state['values']['data']['size']['w'] = $infos['width'];
    $form_state['values']['data']['size']['h'] = $infos['height'];
    $form_state['values']['data']['maxExtent'] = array_map('floatval', explode(",", $form_state['values']['data']['maxExtent']));
    if(count($form_state['values']['data']['maxExtent'])!==4){
      // Ignore invalid input.
      $form_state['values']['data']['maxExtent'] = NULL;
    }
  }

  /*
   * What to do when we delete the layer: delete the file.
   */
  function delete($item) {
    $file = file_load($item->data['file']);
    file_delete($file);
   }

  /**
   * Render.
   */
  function render(&$map) {
    if (isset($this->data['file'])) {
      if ($file = file_load($this->data['file'])) {
        $this->data['file'] = array();
        if (!empty($this->data['image_style'])) {
          $this->data['file'] = image_style_url($this->data['image_style'] ,$file->uri);
        } else {
          $this->data['file'] = file_create_url($file->uri);
        }
        unset($this->data['image_style']);

        drupal_add_js(drupal_get_path('module', 'openlayers') .
          '/plugins/layer_types/openlayers_layer_type_image.js');
      }
    }
  }
}
