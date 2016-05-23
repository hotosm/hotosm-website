<?php
/**
 * @file
 * hot_updates.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function hot_updates_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|update|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'update';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'author' => array(
      'weight' => '6',
      'label' => 'above',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '6',
      'label' => 'above',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|update|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|update|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'update';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more...',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'submitted_by' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
  );
  $export['node|update|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function hot_updates_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|update|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'update';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_images',
        1 => 'field_information',
        2 => 'body',
        3 => 'upload',
      ),
    ),
    'fields' => array(
      'field_images' => 'ds_content',
      'field_information' => 'ds_content',
      'body' => 'ds_content',
      'upload' => 'ds_content',
    ),
    'limit' => array(
      'field_images' => '1',
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
    'layout_disable_css' => FALSE,
  );
  $export['node|update|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|update|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'update';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'panels-one';
  $ds_layout->settings = array(
    'regions' => array(
      'one_main' => array(
        0 => 'title',
        1 => 'submitted_by',
        2 => 'body',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'title' => 'one_main',
      'submitted_by' => 'one_main',
      'body' => 'one_main',
      'node_link' => 'one_main',
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
  $export['node|update|teaser'] = $ds_layout;

  return $export;
}
