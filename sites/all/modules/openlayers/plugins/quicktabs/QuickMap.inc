<?php

/**
 * Class for tab content of type "map" - this is for rendering a map as tab
 * content.
 */
class QuickMap extends QuickContent {

  public static function getType() {
    return 'map';
  }

  public function optionsForm($delta, $qt) {
    $tab = $this->settings;
    $form = array();
    $form['map']['map'] = array(
      '#type' => 'select',
      '#title' => t('OpenLayers Map'),
      '#options' => openlayers_map_options(),
      '#default_value' => isset($tab['map']) ? $tab['map'] : '',
    );
    return $form;
  }

  public function render($hide_empty = FALSE, $args = array()) {
    if ($this->rendered_content) {
      return $this->rendered_content;
    }
    $output = array();
    $item = $this->settings;

    // We should add a JS file here to automatically resize the map when
    // the map is not the default tab.

    $map = openlayers_map_load($item['map']);
    $render = openlayers_render_map($map);

    $output['#markup'] = $render;
    $this->rendered_content = $output;
    return $output;
  }

  public function getAjaxKeys() {
    return array('map');
  }

}

