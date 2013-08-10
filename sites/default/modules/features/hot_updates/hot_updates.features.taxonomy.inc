<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function hot_updates_taxonomy_default_vocabularies() {
  return array(
    'update_tags' => array(
      'name' => 'Update Tags',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_update_tags',
      'weight' => '0',
      'nodes' => array(
        'update' => 'update',
      ),
    ),
  );
}
