<?php

/**
 * Implementation of hook_data_default().
 */
function hot_blog_data_default() {
  $export = array();
  $data_table = new stdClass;
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'HOT blog';
  $data_table->name = 'feeds_data_hot';
  $data_table->table_schema = array(
    'fields' => array(
      'feed_nid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'timestamp' => array(
        'description' => 'The Unix timestamp for the data.',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => FALSE,
      ),
      'title' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'description' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'url' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'guid' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
    ),
    'indexes' => array(
      'feed_nid' => array(
        0 => 'feed_nid',
      ),
      'id' => array(
        0 => 'id',
      ),
      'timestamp' => array(
        0 => 'timestamp',
      ),
    ),
    'primary key' => array(
      0 => 'id',
    ),
  );
  $data_table->meta = FALSE;

  $export['feeds_data_hot'] = $data_table;
  return $export;
}
