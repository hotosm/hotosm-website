<?php
/**
 * @file
 * hot_project.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hot_project_taxonomy_default_vocabularies() {
  return array(
    'vocabulary_2' => array(
      'name' => 'Projects',
      'machine_name' => 'vocabulary_2',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
