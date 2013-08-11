<?php

/**
 * Implements hook_preprocess_html().
 */
function omega_preprocess_html(&$variables, $hook) {
  // Return early, so the maintenance page does not call any of the code below.
  if ($hook != 'html') {
    return;
  }

  // Add $grddl_profile as link-tag.
  drupal_add_html_head_link(array(
    'rel' => 'profile',
    'href' => $variables['grddl_profile'],
  ));

  // Serialize RDF Namespaces into an RDFa 1.1 prefix attribute.
  if ($variables['rdf_namespaces']) {
    $prefixes = array();
    foreach (explode("\n  ", ltrim($variables['rdf_namespaces'])) as $namespace) {
      // Remove xlmns: and ending quote and fix prefix formatting.
      $prefixes[] = str_replace('="', ': ', substr($namespace, 6, -1));
    }
    $variables['rdf_namespaces'] = ' prefix="' . implode(' ', $prefixes) . '"';
  }

  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.).
  if (!$variables['is_front']) {
    // Add unique class for each page.
    $path = drupal_get_path_alias($_GET['q']);
    // Add unique class for each section of the website.
    list($section, ) = explode('/', $path, 2);
    $arg = explode('/', $_GET['q']);

    if ($arg[0] == 'node' && isset($arg[1])) {
      if ($arg[1] == 'add') {
        $section = 'node-add';
      }
      elseif (isset($arg[2]) && is_numeric($arg[1]) && ($arg[2] == 'edit' || $arg[2] == 'delete')) {
        $section = 'node-' . $arg[2];
      }
    }

    $variables['attributes_array']['class'][] = drupal_html_class('section-' . $section);
  }

  // Add some styles in case the Omega theme is the active theme.
  if ($GLOBALS['theme'] == 'omega') {
    _omega_preprocess_html($variables);
  }
}

/**
 * Helper function for loading theme assets in case 'Omega' is the active theme.
 *
 * @see omega_preprocess_html()
 */
function _omega_preprocess_html(&$variables) {
  // @todo
}
