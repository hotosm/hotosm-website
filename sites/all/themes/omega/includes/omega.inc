<?php

/**
 * @file
 * Helper functions for the Omega base theme.
 */

/**
 * Retrieve a setting for the current theme or for a given theme.
 *
 * The final setting is obtained from the last value found in the following
 * sources:
 * - the default global settings specified in this function
 * - the default theme-specific settings defined in any base theme's .info file
 * - the default theme-specific settings defined in the theme's .info file
 * - the saved values from the global theme settings form
 * - the saved values from the theme's settings form
 * To only retrieve the default global theme setting, an empty string should be
 * given for $theme.
 *
 * @param $setting_name
 *   The name of the setting to be retrieved.
 * @param $default
 *   (optional) A default value. Defaults to NULL.
 * @param $theme
 *   (optional) The name of a given theme. Defaults to the NULL which
 *   evaluates to the current theme.
 *
 * @return
 *   The value of the requested setting, or the $default value if the setting
 *   does not exist.
 *
 * @see theme_get_setting().
 */
function omega_theme_get_setting($setting_name, $default = NULL, $theme = NULL) {
  $cache = &drupal_static('theme_get_setting', array());

  // If no key is given, use the current theme if we can determine it.
  if (!isset($theme)) {
    $theme = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }

  if (empty($cache[$theme])) {
    // If the cache has not been filled yet, invoke theme_get_setting to
    // retrieve the value. This will populate the cache and make it available
    // for subsequent requests.
    if (($setting = theme_get_setting($setting_name, $theme)) !== NULL) {
      // Use the default value if the setting does not exist.
      return $setting;
    }
  }
  elseif (isset($cache[$theme][$setting_name])) {
    // Retrieve the value from the cache.
    return $cache[$theme][$setting_name];
  }

  // Use the default value if the setting does not exist.
  return $default;
}

/**
 * Builds the full theme trail (deepest base theme first, subtheme last) for a
 * theme.
 *
 * @param $theme
 *   (Optional) The key (machine-readable name) of a theme. Defaults to the key
 *   of the current theme.
 *
 * @return array
 *   An array of all themes in the trail, keyed by theme key.
 */
function omega_theme_trail($theme = NULL) {
  $theme = isset($theme) ? $theme : $GLOBALS['theme_key'];

  if (($cache = &drupal_static(__FUNCTION__)) && isset($cache[$theme])) {
    return $cache[$theme];
  }

  $cache[$theme] = array();

  if ($theme == $GLOBALS['theme'] && isset($GLOBALS['theme_info']->base_themes)) {
    $cache[$theme] = $GLOBALS['theme_info']->base_themes;
  }

  $themes = list_themes();
  if (empty($cache[$theme]) && isset($themes[$theme]->info['base theme'])) {
    $cache[$theme] = system_find_base_themes($themes, $theme);
  }

  // Add our current subtheme ($key) to that array.
  $cache[$theme][$theme] = $themes[$theme]->info['name'];

  return $cache[$theme];
}

/**
 * Helper function for generating a regex from a list of paths.
 *
 * Generates a single regex from a list of file paths that can be used to match
 * JS or CSS files using preg_grep() for example in hook_css_alter() or
 * hook_js_alter(). The '*' (asterisk) character can be used as a wild-card.
 *
 * @param $paths
 *   An array of file paths.
 *
 * @return string
 *   The generated regex.
 *
 * @see hook_js_alter()
 * @see hook_css_alter()
 */
function omega_generate_path_regex($paths) {
  foreach ($paths as &$item) {
    // The first segment (everything before the first slash) is the namespace.
    // This rule only applies to local files... So if the namespace can not be
    // mapped to a module, profile or theme engine we assume that the we are
    // trying to target an external file.
    list($namespace) = explode('/', $item);

    // Check if the namespace refers to a file residing in the 'misc' folder or
    // if it is a global wildcard.
    if ($namespace !== '*' && $namespace !== 'misc') {
      // Otherwise, check if it refers to a theme, module, profile or theme
      // engine.
      foreach (array('theme', 'module', 'profile', 'theme_engine') as $type) {
        // We can't use drupal_get_path() directly because that uses dirname()
        // internally which returns '.' if no filename was found.
        if ($filename = drupal_get_filename($type, $namespace)) {
          $prefix = dirname($filename);
          $item = substr_replace($item, $prefix, 0, strlen($namespace));
          break;
        }
      }
    }

    // Escape any regex characters and turn asterisk wildcards into actual regex
    // wildcards.
    $item = preg_quote($item, '/');
    $item = str_replace('\*', '(.*)', $item);
  }

  return '/^' . implode('|', $paths) . '$/';
}

/**
 * Helper function for eliminating elements from an array using a simplified
 * regex pattern.
 *
 * @param $elements
 *   The array of elements that should have some of its items removed.
 * @param $regex
 *   A regex as generated by omega_generate_path_regex().
 */
function omega_exclude_assets(&$elements, $regex) {
  $mapping = omega_generate_asset_mapping($elements);

  // Finally, implode the array of items to exclude into a proper regex and
  // invoke in on the array of files to be excluded.
  $elements = array_diff_key($elements, preg_grep($regex, $mapping));
}

/**
 * Helper function for generating a map of assets based on the data attribute.
 *
 * We can not rely on the array keys of the JS and CSS file arrays in Drupal
 * because in case of inline JS or CSS (which uses numerical array keys) and due
 * to potential overrides of the 'data' attribute which holds the actual,
 * reliable path of the file. This function returns a single-level array of
 * reliable JS/CSS file paths using the original array keys as keys. Elements of
 * type 'inline' or 'setting' are ignored.
 *
 * @param $elements
 *   An array of JS or CSS files as given in hook_css_alter() or
 *   hook_js_alter().
 *
 * @return array
 *   A map of file paths generated from $elements.
 *
 * @see hook_js_alter()
 * @see hook_css_alter()
 */
function omega_generate_asset_mapping($elements) {
  $mapping = array();
  foreach ($elements as $key => $item) {
    if ($item['type'] == 'inline' || $item['type'] == 'setting') {
      // Naturally, in-line CSS is not supported.
      continue;
    }

    // We need to build an array containing just the 'data' attribute because
    // that's the actual path of the file. The array key of the elements can
    // be something else if someone is sneaky enough to use drupal_add_js() or
    // drupal_add_css() with a bogus first argument (normally, that is the
    // path to the file) and then specify the actual path through the 'data'
    // attribute in the $options array.
    $mapping[$key] = $item['data'];
  }

  return $mapping;
}

/**
 * Retrieves the array of enabled extensions for a theme. Extensions can be
 * registered through the .info file. Each extension can define a theme settings
 * form altering function named
 * 'THEMENAME_extension_EXTENSION_theme_settings_form_alter()' through a file
 * named 'THEME_ROOT/includes/EXTENSION/EXTENSION.settings.inc' to have it
 * automatically included whenever the theme settings form is displayed. Each
 * extension can also define a
 * 'THEMENAME_extension_EXTENSION_theme_registry_alter()' function through a
 * file named 'THEME_ROOT/includes/EXTENSION/EXTENSION.inc' to register custom
 * hooks with the theme registry.
 *
 * @param $theme
 *   (Optional) The key (machine-readable name) of a theme. Defaults to the key
 *   of the current theme.
 *
 * @return array
 *   The theme info array of the passed or current theme.
 *
 * @see _system_default_theme_features()
 * @see omega_extension_development_theme_settings_form_alter()
 * @see omega_extension_development_theme_registry_alter()
 */
function omega_extensions($theme = NULL, $reset = FALSE) {
  $theme = isset($theme) ? $theme : $GLOBALS['theme_key'];

  if (!$reset) {
    if (($extensions = &drupal_static(__FUNCTION__)) && isset($extensions[$theme])) {
      return $extensions[$theme];
    }

    if (($cache = cache_get('omega:' . $theme . ':extensions')) !== FALSE) {
      return $extensions[$theme] = $cache->data;
    }
  }

  // Extensions can't be hidden.
  $extensions[$theme] = omega_discovery('extension', $theme);

  foreach ($extensions[$theme] as $extension => &$info) {
    // Make sure that the theme variable is never altered.
    $context = $theme;
    drupal_alter('omega_extension_info', $info, $context);

    // Determine if the extension is enabled.
    $info['enabled'] = omega_theme_get_setting('omega_toggle_extension_' . $extension, !empty($info['info']['enabled']));

    // Check if all dependencies are met.
    $info['errors'] = FALSE;
    if (!empty($info['info']['dependencies'])) {
      foreach ($info['info']['dependencies'] as $dependency) {
        $dependency = drupal_parse_dependency($dependency);

        if ((!$module = system_get_info('module', $dependency['name'])) || omega_check_incompatibility($dependency, $module['version'])) {
          $info['errors'] = TRUE;
        }
      }
    }
  }

  // Write to the cache.
  cache_set('omega:' . $theme . ':extensions', $extensions[$theme]);

  return $extensions[$theme];
}

/**
 * Determines if an extension is enabled.
 *
 * @param $extension
 *   The machine-readable name of an extension.
 * @param $theme
 *   (Optional) The key (machine-readable name) of a theme. Defaults to the key
 *   of the current theme.
 *
 * @return bool
 *   TRUE if the extension is enabled, FALSE otherwise.
 */
function omega_extension_enabled($extension, $theme = NULL) {
  $theme = isset($theme) ? $theme : $GLOBALS['theme_key'];
  if (($extensions = omega_extensions($theme)) && isset($extensions[$extension])) {
    return empty($extensions[$extension]['errors']) && !empty($extensions[$extension]['enabled']) && variable_get('omega_toggle_extension_' . $extension, TRUE);
  }
}

/**
 * Looks up the info array of all themes in the theme trail and retrieves a
 * particular info array element.
 */
function omega_theme_trail_info($element, $merge = TRUE, $theme = NULL) {
  $output = array();

  // Loop over all themes in the theme trail and look up $element in the .info
  // array.
  foreach (omega_theme_trail($theme) as $key => $name) {
    $info = omega_theme_info($key);

    // If $merge is TRUE we combine all the results of all themes in the theme
    // trail. Otherwise we just return the first occurrence.
    if (isset($info[$element]) && is_array($info[$element])) {
      $output = array_merge($info[$element], $output);

      if (!$merge) {
        return array('theme' => $key, 'info' => $output);
      }
    }
  }

  return $output;
}

/**
 * Retrieves the full info array of a theme.
 *
 * @param $theme
 *   (Optional) The key (machine-readable name) of a theme. Defaults to the key
 *   of the current theme.
 *
 * @return array
 *   The theme info array of the passed or current theme.
 */
function omega_theme_info($theme = NULL) {
  $theme = isset($theme) ? $theme : $GLOBALS['theme_key'];

  // If this is the current theme, just load the theme info from the globals.
  // Note: The global 'theme_key' property is not reliable in this case because
  // it gets overridden on theme settings pages.
  if ($theme == $GLOBALS['theme']) {
    return $GLOBALS['theme_info']->info;
  }

  $themes = list_themes();
  return $themes[$theme]->info;
}

/**
 * Invoke a hook in all themes in the theme trail that implement it.
 *
 * @param $hook
 *   The name of the hook to invoke.
 * @param $theme
 *   (Optional) The key (machine-readable name) of a theme. Defaults to the key
 *   of the current theme.
 * @param ...
 *   Arguments to pass to the hook.
 *
 * @return array
 *   An array of return values of the hook implementations. If themes return
 *   arrays from their implementations, those are merged into one array.
 *
 * @see module_invoke_all()
 */
function omega_invoke_all($hook, $theme = NULL) {
  $theme = isset($theme) ? $theme : $GLOBALS['theme_key'];

  $args = func_get_args();
  // Remove $hook from the arguments.
  unset($args[0], $args[1]);

  $return = array();
  foreach (omega_theme_trail($theme) as $key => $name) {
    $function = $key . '_' . $hook;

    if (function_exists($function)) {
      $result = call_user_func_array($function, array_merge(array($theme), array_values($args)));
      if (isset($result) && is_array($result)) {
        // Append the 'theme' property to each array element.
        foreach ($result as &$item) {
          $item['theme'] = $key;
        }
        $return = array_merge_recursive($return, $result);
      }
      elseif (isset($result)) {
        $return[] = $result;
      }
    }
  }
  return $return;
}

/**
 * Custom implementation of drupal_array_get_nested_value() that also supports
 * objects instead of just arrays.
 *
 * @param $object
 *   The array or object from which to get the value.
 * @param $parents
 *   An array of parent keys of the value, starting with the outermost key.
 * @param $key_exists
 *   (optional) If given, an already defined variable that is altered by
 *   reference.
 *
 * @return mixed
 *   The requested nested value. Possibly NULL if the value is NULL or not all
 *   nested parent keys exist. $key_exists is altered by reference and is a
 *   Boolean that indicates whether all nested parent keys exist (TRUE) or not
 *   (FALSE). This allows to distinguish between the two possibilities when NULL
 *   is returned.
 *
 * @see drupal_array_get_nested_value()
 */
function omega_get_nested_value(&$object, array $parents, &$key_exists = NULL) {
  $ref = &$object;
  foreach ($parents as $parent) {
    if (is_array($ref) && array_key_exists($parent, $ref)) {
      $ref = &$ref[$parent];
    }
    elseif (is_object($ref) && property_exists($ref, $parent)) {
      $ref = &$ref->$parent;
    }
    else {
      $key_exists = FALSE;
      return NULL;
    }
  }
  $key_exists = TRUE;
  return $ref;
}

/**
 * Retrieves the info array for all available layouts.
 *
 * @return array
 *   An array of available layouts for the given theme.
 */
function omega_layouts_info() {
  if (($layouts = &drupal_static(__FUNCTION__)) !== NULL) {
    return $layouts;
  }

  // Try to retrieve the layouts definitions from cache.
  if (($cache = cache_get('omega:layouts')) !== FALSE) {
    return $layouts = $cache->data;
  }

  // Layouts do not have a specific theme scope.
  $layouts = omega_discovery('layout', FALSE);
  foreach ($layouts as $layout => &$info) {
    $info['attached'] = array();
    $info['template'] = isset($info['info']['template']) ? $info['info']['template'] : $layout;
    $root = drupal_get_path('theme', $info['theme']);

    if (isset($info['info']['stylesheets'])) {
      foreach ($info['info']['stylesheets'] as $media => $files) {
        foreach ($files as $key => $file) {
          if (is_file($info['path'] . '/' . $file)) {
            // First, check if the file exists in the layout's path.
            $path = $info['path'] . '/' . $file;
          }
          elseif (is_file($root . '/' . $file)) {
            // Otherwise, check if the file exists in the theme's path.
            $path = $root . '/' . $file;
          }
          else {
            // The specified file does not exist.
            continue;
          }

          $info['attached']['css']["$media:$key"] = array(
            'data' => $path,
            'media' => $media,
            'group' => CSS_THEME,
            'every_page' => TRUE,
            'weight' => -10,
          );
        }
      }
    }

    // Look up possible CSS and JS file overrides.
    if (isset($info['info']['scripts'])) {
      foreach ($info['info']['scripts'] as $key => $file) {
        if (is_file($info['path'] . '/' . $file)) {
          // First, check if the file exists in the layout's path.
          $path = $info['path'] . '/' . $file;
        }
        elseif (is_file($root . '/' . $file)) {
          // Otherwise, check if the file exists in the theme's path.
          $path = $root . '/' . $file;
        }
        else {
          // The specified file does not exist.
          continue;
        }

        $info['attached']['js'][$key] = array(
          'data' => $path,
          'group' => JS_THEME,
          'every_page' => TRUE,
          'weight' => -10,
        );
      }
    }
  }

  // Give modules and themes a chance to alter the layout info array.
  drupal_alter('omega_layouts_info', $layouts);

  // Cache the layout definitions in the database.
  cache_set('omega:layouts', $layouts);

  return $layouts;
}

/**
 * Retrieves the active layout for the current page.
 *
 * @return array|bool
 *   The info array for the active layout or FALSE if the current page does not
 *   use an alternative page layout.
 */
function omega_layout() {
  if (($cache = &drupal_static(__FUNCTION__)) !== NULL) {
    return $cache;
  }

  // Load the default layout from the theme settings.
  $layout = omega_theme_get_setting('omega_layout', 'simple');
  drupal_alter('omega_layout', $layout);

  $layouts = omega_layouts_info();
  $cache = isset($layouts[$layout]) ? $layouts[$layout] : FALSE;

  return $cache;
}

/**
 * Allow themes to easily define libraries.
 *
 * @param $theme
 *   (Optional) The key (machine-readable name) of a theme. Defaults to the key
 *   of the current theme.
 *
 * @return array
 *   An array of libraries defined by themes in the theme trail of the given
 *   theme.
 */
function omega_theme_libraries_info($theme = NULL) {
  $theme = isset($theme) ? $theme : $GLOBALS['theme_key'];

  // Check if the libraries have already been statically cached.
  if (($libraries = &drupal_static(__FUNCTION__)) && isset($libraries[$theme])) {
    return $libraries[$theme];
  };

  $libraries[$theme] = omega_invoke_all('omega_theme_libraries_info');

  $context = $theme;
  // Give modules and themes a chance to alter the libraries info array.
  drupal_alter('omega_theme_libraries_info', $libraries[$theme], $context);

  return $libraries[$theme];
}

/**
 * Helper function for discovering layouts, extensions or other plugins of any
 * sort in the theme trail.
 *
 * @param $type
 *   A theme extension type (e.g. layout or extension).
 * @param $theme
 *   (Optional) The key (machine-readable name) of a theme. Defaults to the key
 *   of the current theme.
 *
 * @return array
 *   An array containing the discovered definitions.
 */
function omega_discovery($type, $theme = NULL) {
  $theme = isset($theme) ? $theme : $GLOBALS['theme_key'];

  if (($discovery = &drupal_static(__FUNCTION__, array())) && isset($discovery[$theme][$type])) {
    return $discovery[$theme][$type];
  }

  $discovery[$theme][$type] = array();

  // Retrieve all themes from the theme trail of the given theme.
  $themes = $theme === FALSE ? list_themes() : omega_theme_trail($theme);

  // Collect paths to all sub-themes grouped by base themes. These will be
  // used for filtering. This allows base themes to have sub-themes in its
  // folder hierarchy without affecting the base themes template discovery.
  $paths = array();
  foreach ($themes as $key => $info) {
    if (!empty($info->base_theme)) {
      $paths[$info->base_theme][$key] = dirname($info->filename);
    }
  }
  foreach ($paths as $basetheme => $subthemes) {
    foreach ($subthemes as $subtheme => $path) {
      if (isset($paths[$subtheme])) {
        $paths[$basetheme] = array_merge($paths[$basetheme], $paths[$subtheme]);
      }
    }
  }

  $strlen = strlen($type) + 1;
  foreach ($themes as $key => $label) {
    // Retrieve the array of paths that should be ignored for this theme.
    $ignore = isset($paths[$key]) ? $paths[$key] : array();
    $path = drupal_get_path('theme', $key);

    // Support files without '.inc' extension for backwards compatibility.
    foreach (file_scan_directory($path, '/\.' . $type . '(\.inc)?$/', array('key' => 'name')) as $name => $file) {
      // Ignore sub-theme templates for the current theme.
      if (strpos($file->uri, str_replace($ignore, '', $file->uri)) !== 0) {
        continue;
      }

      if (substr($name, -$strlen) === '.' . $type) {
        $name = substr($name, 0, strlen($name) - $strlen);
      }

      if ($info = drupal_parse_info_file($file->uri)) {
        $discovery[$theme][$type][$name] = array(
          'name' => $name,
          'path' => dirname($file->uri),
          'file' => $file->uri,
          'info' => $info,
          'theme' => $key,
        );
      }
    }
  }

  return $discovery[$theme][$type];
}

/**
 * Checks whether a version is compatible with a given dependency.
 *
 * This is a wrapper for drupal_check_incompatibility() which strips the core
 * version and any potential development version suffix from the given string.
 *
 * @param $dependency
 *   The parsed dependency structure from drupal_parse_dependency().
 * @param $current
 *   The version to check against (like 4.2).
 *
 * @return
 *   NULL if compatible, otherwise the original dependency version string that
 *   caused the incompatibility.
 *
 * @see drupal_check_incompatibility()
 * @see drupal_parse_dependency()
 */
function omega_check_incompatibility($dependency, $current) {
  // Remove the core version from the version string.
  $current = preg_replace('/^' . DRUPAL_CORE_COMPATIBILITY . '-/', '', $current);
  // Remove any potential development version suffixes from the string.
  $current = preg_replace('/-dev$/', '', $current);

  return drupal_check_incompatibility($dependency, $current);
}
