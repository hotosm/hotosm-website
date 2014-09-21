<?php
/**
 * @file
 * hot_project.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function hot_project_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|project|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|feature';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'feature';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '4',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb' => 'Featured project',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'node_link' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more...',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|project|feature'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|project|list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'project';
  $ds_fieldsetting->view_mode = 'list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'list',
        'ft' => array(),
      ),
    ),
    'field_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'left',
        ),
      ),
    ),
  );
  $export['node|project|list'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function hot_project_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'links',
        1 => 'body',
      ),
    ),
    'fields' => array(
      'links' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|project|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|feature';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'feature';
  $ds_layout->layout = 'panels-two_66_33';
  $ds_layout->settings = array(
    'regions' => array(
      'two_66_33_first' => array(
        0 => 'field_image',
      ),
      'two_66_33_second' => array(
        1 => 'title',
        2 => 'body',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_image' => 'two_66_33_first',
      'title' => 'two_66_33_second',
      'body' => 'two_66_33_second',
      'node_link' => 'two_66_33_second',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'two_66_33_second' => array(
        'feature' => 'feature',
      ),
    ),
    'wrappers' => array(
      'two_66_33_top' => 'div',
      'two_66_33_first' => 'div',
      'two_66_33_second' => 'div',
      'two_66_33_bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|project|feature'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'list';
  $ds_layout->layout = 'panels-one';
  $ds_layout->settings = array(
    'regions' => array(
      'one_main' => array(
        0 => 'field_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_image' => 'one_main',
      'title' => 'one_main',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'one_main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|project|list'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|project|title';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'project';
  $ds_layout->view_mode = 'title';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|project|title'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function hot_project_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'feature';
  $ds_view_mode->label = 'Feature';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['feature'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'list';
  $ds_view_mode->label = 'List';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
    'user' => 'user',
  );
  $export['list'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'title';
  $ds_view_mode->label = 'Title';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['title'] = $ds_view_mode;

  return $export;
}
