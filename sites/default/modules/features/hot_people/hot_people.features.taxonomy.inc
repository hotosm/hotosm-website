<?php
/**
 * @file
 * hot_people.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hot_people_taxonomy_default_vocabularies() {
  return array(
    'hot_leadership' => array(
      'name' => 'HOT Board function',
      'machine_name' => 'hot_leadership',
      'description' => 'Role of the person in the HOT Board',
      'hierarchy' => 0,
      'module' => 'taxonomy',
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
