<?php
/**
 * @file
 * hot_core.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hot_core_taxonomy_default_vocabularies() {
  return array(
    'vocabulary_1' => array(
      'name' => 'Tags',
      'machine_name' => 'vocabulary_1',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'features_tags',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
