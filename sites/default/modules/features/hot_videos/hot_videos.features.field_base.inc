<?php
/**
 * @file
 * hot_videos.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hot_videos_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_video'
  $field_bases['field_video'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_video',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'video_embed_field',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'video_embed_field',
  );

  return $field_bases;
}
