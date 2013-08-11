<?php

/**
 * @file
 * Template overrides and (pre-)process hooks for the Omega base theme.
 */

require_once dirname(__FILE__) . '/includes/omega.inc';
require_once dirname(__FILE__) . '/includes/scripts.inc';

if ($GLOBALS['theme'] === $GLOBALS['theme_key'] && ($GLOBALS['theme'] == 'omega' || (!empty($GLOBALS['base_theme_info']) && $GLOBALS['base_theme_info'][0]->name == 'omega'))) {
  // Managing debugging (flood) messages and a few development tasks. This also
  // lives outside of any function declaration to make sure that the code is
  // executed before any theme hooks.
  if (omega_extension_enabled('development') && user_access('administer site configuration')) {
    if (variable_get('theme_' . $GLOBALS['theme'] . '_settings') && flood_is_allowed('omega_' . $GLOBALS['theme'] . '_theme_settings_warning', 3)) {
      // Alert the user that the theme settings are served from a variable.
      flood_register_event('omega_' . $GLOBALS['theme'] . '_theme_settings_warning');
      drupal_set_message(t('The settings for this theme are currently served from a variable. You might want to export them to your .info file.'), 'warning');
    }

    // Rebuild the theme registry / aggregates on every page load if the
    // development extension is enabled and configured to do so.
    if (omega_theme_get_setting('omega_rebuild_theme_registry', FALSE)) {
      // Rebuild the theme data.
      system_rebuild_theme_data();
      // Rebuild the theme registry.
      drupal_theme_rebuild();

      if (flood_is_allowed('omega_' . $GLOBALS['theme'] . '_rebuild_registry_warning', 3)) {
        // Alert the user that the theme registry is being rebuilt on every
        // request.
        flood_register_event('omega_' . $GLOBALS['theme'] . '_rebuild_registry_warning');
        drupal_set_message(t('The theme registry is being rebuilt on every request. Remember to <a href="!url">turn off</a> this feature on production websites.', array("!url" => url('admin/appearance/settings/' . $GLOBALS['theme']))), 'warning');
      }
    }

    if (omega_theme_get_setting('omega_rebuild_aggregates', FALSE) && variable_get('preprocess_css', FALSE) && (!defined('MAINTENANCE_MODE') || MAINTENANCE_MODE != 'update')) {
      foreach (array('css', 'js') as $type) {
        variable_del('drupal_' . $type . '_cache_files');

        foreach (file_scan_directory('public://' . $type . '', '/.*/') as $file) {
          // Delete files that are older than 20 seconds.
          if (REQUEST_TIME - filemtime($file->uri) > 20) {
            file_unmanaged_delete($file->uri);
          }
        };
      }

      if (flood_is_allowed('omega_' . $GLOBALS['theme'] . '_rebuild_aggregates_warning', 3)) {
        // Alert the user that the theme registry is being rebuilt on every
        // request.
        flood_register_event('omega_' . $GLOBALS['theme'] . '_rebuild_aggregates_warning');
        drupal_set_message(t('The CSS and JS aggregates are being rebuilt on every request. Remember to <a href="!url">turn off</a> this feature on production websites.', array("!url" => url('admin/appearance/settings/' . $GLOBALS['theme']))), 'warning');
      }
    }
  }
}

/**
 * Implements hook_element_info_alter().
 */
function omega_element_info_alter(&$elements) {
  $elements['scripts'] = array(
    '#items' => array(),
    '#pre_render' => array('omega_pre_render_scripts'),
    '#group_callback' => 'omega_group_js',
    '#aggregate_callback' => 'omega_aggregate_js',
  );
}

/**
 * Implements hook_css_alter().
 */
function omega_css_alter(&$css) {
  $omega = drupal_get_path('theme', 'omega');

  // The CSS_SYSTEM aggregation group doesn't make any sense. Therefore, we are
  // pre-pending it to the CSS_DEFAULT group. This has the same effect as giving
  // it a separate (low-weighted) group but also allows it to be aggregated
  // together with the rest of the CSS.
  foreach ($css as &$item) {
    if ($item['group'] == CSS_SYSTEM) {
      $item['group'] = CSS_DEFAULT;
      $item['weight'] = $item['weight'] - 100;
    }
  }

  // Clean up core and contrib module CSS.
  $overrides = array(
    'aggregator' => array(
      'aggregator.css' => array(
        'theme' => 'aggregator.theme.css',
      ),
      'aggregator-rtl.css' => array(
        'theme' => 'aggregator.theme-rtl.css',
      ),
    ),
    'block' => array(
      'block.css' => array(
        'admin' => 'block.admin.css',
        'demo' => 'block.demo.css',
      ),
    ),
    'book' => array(
      'book.css' => array(
        'theme' => 'book.theme.css',
        'admin' => 'book.admin.css',
      ),
      'book-rtl.css' => array(
        'theme' => 'book.theme-rtl.css',
      ),
    ),
    'color' => array(
      'color.css' => array(
        'admin' => 'color.admin.css',
      ),
      'color-rtl.css' => array(
        'admin' => 'color.admin-rtl.css',
      ),
    ),
    'comment' => array(
      'comment.css' => array(
        'theme' => 'comment.theme.css',
      ),
      'comment-rtl.css' => array(
        'theme' => 'comment.theme-rtl.css',
      ),
    ),
    'contextual' => array(
      'contextual.css' => array(
        'base' => 'contextual.base.css',
        'theme' => 'contextual.theme.css',
      ),
      'contextual-rtl.css' => array(
        'base' => 'contextual.base-rtl.css',
        'theme' => 'contextual.theme-rtl.css',
      ),
    ),
    'field' => array(
      'theme/field.css' => array(
        'theme' => 'field.theme.css',
      ),
      'theme/field-rtl.css' => array(
        'theme' => 'field.theme-rtl.css',
      ),
    ),
    'field_ui' => array(
      'field_ui.css' => array(
        'admin' => 'field_ui.admin.css',
      ),
      'field_ui-rtl.css' => array(
        'admin' => 'field_ui.admin-rtl.css',
      ),
    ),
    'file' => array(
      'file.css' => array(
        'theme' => 'file.theme.css',
      ),
    ),
    'filter' => array(
      'filter.css' => array(
        'theme' => 'filter.theme.css',
      ),
    ),
    'forum' => array(
      'forum.css' => array(
        'theme' => 'forum.theme.css',
      ),
      'forum-rtl.css' => array(
        'theme' => 'forum.theme-rtl.css',
      ),
    ),
    'image' => array(
      'image.css' => array(
        'theme' => 'image.theme.css',
      ),
      'image-rtl.css' => array(
        'theme' => 'image.theme-rtl.css',
      ),
      'image.admin.css' => array(
        'admin' => 'image.admin.css',
      ),
    ),
    'locale' => array(
      'locale.css' => array(
        'admin' => 'locale.admin.css',
      ),
      'locale-rtl.css' => array(
        'admin' => 'locale.admin-rtl.css',
      ),
    ),
    'openid' => array(
      'openid.css' => array(
        'base' => 'openid.base.css',
        'theme' => 'openid.theme.css',
      ),
      'openid-rtl.css' => array(
        'base' => 'openid.base-rtl.css',
        'theme' => 'openid.theme-rtl.css',
      ),
    ),
    'poll' => array(
      'poll.css' => array(
        'admin' => 'poll.admin.css',
        'theme' => 'poll.theme.css',
      ),
      'poll-rtl.css' => array(
        'theme' => 'poll.theme-rtl.css',
      ),
    ),
    'search' => array(
      'search.css' => array(
        'theme' => 'search.theme.css',
      ),
      'search-rtl.css' => array(
        'theme' => 'search.theme-rtl.css',
      ),
    ),
    'system' => array(
      'system.base.css' => array(
        'base' => 'system.base.css',
      ),
      'system.base-rtl.css' => array(
        'base' => 'system.base-rtl.css',
      ),
      'system.theme.css' => array(
        'theme' => 'system.theme.css',
      ),
      'system.theme-rtl.css' => array(
        'theme' => 'system.theme-rtl.css',
      ),
      'system.admin.css' => array(
        'admin' => 'system.admin.css',
      ),
      'system.admin-rtl.css' => array(
        'admin' => 'system.admin-rtl.css',
      ),
      'system.menus.css' => array(
        'theme' => 'system.menus.theme.css',
      ),
      'system.menus-rtl.css' => array(
        'theme' => 'system.menus.theme-rtl.css',
      ),
      'system.messages.css' => array(
        'theme' => 'system.messages.theme.css',
      ),
      'system.messages-rtl.css' => array(
        'theme' => 'system.messages.theme-rtl.css',
      ),
    ),
    'taxonomy' => array(
      'taxonomy.css' => array(
        'admin' => 'taxonomy.admin.css',
      ),
    ),
    'user' => array(
      'user.css' => array(
        'base' => 'user.base.css',
        'admin' => 'user.admin.css',
        'theme' => 'user.theme.css',
      ),
      'user-rtl.css' => array(
        'admin' => 'user.admin-rtl.css',
        'theme' => 'user.theme-rtl.css',
      ),
    ),
  );

  // Check if we are on an admin page. Otherwise, we can skip admin CSS.
  $path = current_path();
  $types = path_is_admin($path) ? array('base', 'theme', 'admin') : array('base', 'theme');
  // Add a special case for the block demo page.
  $types = strpos($path, 'admin/structure/block/demo') === 0 ? array_merge($types, array('demo')) : $types;

  // Override module provided CSS with clean and modern alternatives provided
  // by Omega.
  foreach ($overrides as $module => $files) {
    // We gathered the CSS files with paths relative to the providing module.
    $path = drupal_get_path('module', $module);

    foreach ($files as $file => $items) {
      if (isset($css[$path . '/' . $file])) {
        // Keep a copy of the original file array so we can merge that with our
        // overrides in order to keep the 'weight' and 'group' declarations.
        $original = $css[$path . '/' . $file];
        unset($css[$path . '/' . $file]);

        // Omega 4.x tries to follow the pattern described in
        // http://drupal.org/node/1089868 for declaring CSS files. Therefore, it
        // may take more than a single file to override a .css file added by
        // core. This gives us better granularity when overriding .css files
        // in a sub-theme.
        foreach ($types as $type) {
          if (isset($items[$type])) {
            $css[$omega . '/css/modules/' . $module . '/' . $items[$type]] = array(
              'data' => $omega . '/css/modules/' . $module . '/' . $items[$type],
            ) + $original;
          }
        }
      }
    }
  }

  // Exclude CSS files as declared in the theme settings.
  if (omega_extension_enabled('assets') && $regex = omega_theme_get_setting('omega_css_exclude_regex')) {
    // Make sure that RTL styles are excluded as well when a file name has been
    // specified with it's full .css file extension.
    $regex = preg_replace('/\\\.css$/', '(\.css|-rtl\.css)', $regex);
    omega_exclude_assets($css, $regex);
  }
}

/**
 * Implements hook_js_alter().
 */
function omega_js_alter(&$js) {
  if (!omega_extension_enabled('assets')) {
    return;
  }

  if ($regex = omega_theme_get_setting('omega_js_exclude_regex')) {
    omega_exclude_assets($js, $regex);
  }

  // Move the specified JavaScript files to the footer.
  if (($footer = omega_theme_get_setting('omega_js_footer')) && is_array($footer)) {
    $regex = omega_generate_path_regex($footer);
    $mapping = omega_generate_asset_mapping($js);

    foreach (preg_grep($regex, $mapping) as $key => $match) {
      $js[$key]['scope'] = 'footer';
    }
  }
}

/**
 * Implements hook_form_alter().
 */
function omega_form_alter(&$form, &$form_state, $form_id) {
  // Duplicate the form ID as a class so we can reduce specificity in our CSS.
  $form['#attributes']['class'][] = drupal_clean_css_identifier($form['#id']);
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function omega_form_field_ui_display_overview_form_alter(&$form, &$form_state, $form_id) {
  // Add a class to use as a styling hook, instead of the ID attribute.
  $form['fields']['#attributes']['class'][] = 'field-display-overview';
}

/**
 * Implements hook_theme().
 */
function omega_theme() {
  $info['omega_chrome'] = array(
    'render element' => 'element',
  );

  $info['omega_layout'] = array(
    'base hook' => 'page',
  );

  foreach (omega_layouts_info() as $layout) {
    $info[$layout['template']] = array(
      'template' => $layout['template'],
      'path' => $layout['path'],
    );
  }

  return $info;
}

/**
 * Implements hook_theme_registry_alter().
 */
function omega_theme_registry_alter(&$registry) {
  // Fix for integration with the theme developer module.
  if (module_exists('devel_themer')) {
    $mapping = array(
      'preprocess' => 'devel_function_preprocess_intercept',
      'process' => 'devel_function_process_intercept',
      'theme' => 'devel_function_intercept',
    );
  }
  else {
    $mapping = array(
      'preprocess' => 'preprocess functions',
      'process' => 'process functions',
      'theme' => 'function',
    );
  }

  // We prefer the attributes array instead of the plain classes array used by
  // many core and contrib modules. In Drupal 8, we are going to convert all
  // occurrences of that into an attributes object. For now, we simply
  // synchronize our attributes array with the classes array to encourage
  // themers to use it.
  foreach ($registry as $hook => $item) {
    if (empty($item['base hook']) && empty($item[$mapping['theme']])) {
      if (($index = array_search('template_preprocess', $registry[$hook][$mapping['preprocess']], TRUE)) !== FALSE) {
        // Make sure that omega_initialize_attributes() is invoked first.
        array_unshift($registry[$hook][$mapping['process']], 'omega_cleanup_attributes');
        // Add omega_cleanup_attributes() right after template_preprocess().
        array_splice($registry[$hook][$mapping['preprocess']], $index + 1, 0, 'omega_initialize_attributes');
      }
    }
  }

  // Allow themers to split preprocess / process / theme code across separate
  // files to keep the main template.php file clean. This is really fast because
  // it uses the theme registry to cache the paths to the files that it finds.
  $trail = omega_theme_trail();

  // Keep track of theme function include files that are not directly loaded
  // into the theme registry. This is the case for previously unknown theme
  // hook suggestion implementations.
  $includes = array();
  foreach ($trail as $theme => $name) {
    // Remove the current element from the trail so we only iterate over
    // higher level themes during subsequent checks.
    unset($trail[$theme]);

    foreach ($mapping as $type => $map) {
      $path = drupal_get_path('theme', $theme);
      // Only look for files that match the 'something.preprocess.inc' pattern.
      $mask = '/.' . $type . '.inc$/';
      // This is the length of the suffix (e.g. '.preprocess') of the basename
      // of a file.
      $strlen = -(strlen($type) + 1);

      // Recursively scan the folder for the current step for (pre-)process
      // files and write them to the registry.
      foreach (file_scan_directory($path . '/' . $type, $mask) as $item) {
        $hook = strtr(substr($item->name, 0, $strlen), '-', '_');

        // If there is no hook with that name, continue. This does not apply to
        // theme functions because if we want to support theme hook suggestions
        // in .theme.inc files that have not previously been declared we need to
        // run the full discovery for theme functions.
        if (!array_key_exists($hook, $registry) && ($type !== 'theme' || strpos($hook, '__') === FALSE)) {
          continue;
        }

        // Name of the function (theme hook or theme function).
        $callback = $type == 'theme' ? $theme . '_' . $hook : $theme . '_' . $type . '_' . $hook;

        // Make sure we don't run into any fatal errors by including any
        // include file for a (pre)process or theme function if the same hook
        // has already been implemented in template.php or anywhere else.
        if (($type == 'theme' && isset($registry[$hook][$map]) && $registry[$hook][$map] == $callback) || ($type != 'theme' && in_array($callback, $registry[$hook][$map]))) {
          // Notify the administrator about this clash through watchdog.
          watchdog('omega', 'There are two declarations of %function in the %theme theme for the %hook %type hook. Therefore, the include file %file was skipped.', array(
            '%function' => $callback,
            '%theme' => $name,
            '%hook' => $hook,
            '%type' => $type,
            '%file' => $item->uri,
          ));

          continue;
        }

        // Furthermore, we don't want to re-override sub-theme template file or
        // theme function overrides with theme functions from include files
        // defined in a lower-level base theme. Without this check this would
        // happen because our alter hook runs after the template file and theme
        // function discovery logic from Drupal core (theme engine).
        if ($type == 'theme' && $theme != $GLOBALS['theme'] && in_array($registry[$hook]['type'], array('base_theme_engine', 'theme_engine'))) {
          // Now we know that there is a template file or theme function
          // override that has been defined somewhere in the theme trail. Now
          // we need to check if the declaration of that function or template
          // file lives further down the theme trail than the function we are
          // currently looking it.
          foreach ($trail as $subkey => $subtheme) {
            if ($registry[$hook]['theme path'] == drupal_get_path('theme', $subkey)) {
              continue(2);
            }
          }
        }

        // Load the file once so we can check if the function exists.
        require_once $item->uri;

        // Proceed if the callback doesn't exist.
        if (!function_exists($callback)) {
          continue;
        }

        // If we got this far and the following if() statement evaluates to true
        // then that means that the theme function override that is currently
        // being processed is a previously unknown theme hook suggestion.
        if ($type == 'theme' && !array_key_exists($hook, $registry) && $separator = strpos($hook, '__')) {
          $suggestion = $hook;
          $hook = substr($hook, 0, $separator);

          if (!isset($registry[$hook])) {
            // Bail out here if the base hook does not exist.
            continue;
          }

          // Register the theme hook suggestion.
          $arg_name = isset($registry[$hook]['variables']) ? 'variables' : 'render element';
          $registry[$suggestion] = array(
            $map => $callback,
            $arg_name => $registry[$hook][$arg_name],
            'base hook' => $hook,
          );
        }
        elseif ($type == 'theme') {
          // Inject our theme function. We will leave any potential 'template'
          // declarations in the registry as they don't hurt us anyways
          // because drupal gives precedence to theme functions.
          $registry[$hook][$map] = $callback;
        }
        else {
          // Append the included preprocess hook to the array of functions.
          $registry[$hook][$map][] = $callback;
        }

        // By adding this file to the 'includes' array we make sure that it is
        // available when the hook is executed.
        $registry[$hook]['includes'][] = $item->uri;
      }
    }
  }

  // Include the main extension file for every enabled extension. This is
  // required for the next step (allowing extensions to register hooks in the
  // theme registry).
  foreach (omega_extensions() as $extension => $info) {
    // Load all the implementations for this extensions and invoke the according
    // hooks.
    if (omega_extension_enabled($extension)) {
      $file = $info['path'] . '/' . $extension . '.inc';

      if (is_file($file)) {
        require_once $file;
      }

      // Give every enabled extension a chance to alter the theme registry.
      $hook = $info['theme'] . '_extension_' . $extension . '_theme_registry_alter';

      if (function_exists($hook)) {
        $hook($registry);
      }
    }
  }

  // Override pre-process and process functions for cases where we want to take
  // a completely different approach than what core does by default. In some
  // cases this is much more practical than altering or undoing things that were
  // added or changed in a previous hook.
  $overrides = array(
    'html' => array(
      'process' => array(
        'template_process_html' => 'omega_template_process_html_override',
      ),
    ),
  );

  foreach ($overrides as $hook => $types) {
    foreach ($types as $type => $overrides) {
      foreach ($overrides as $original => $override) {
        if (($index = array_search($original, $registry[$hook][$mapping[$type]], TRUE)) !== FALSE) {
          array_splice($registry[$hook][$mapping[$type]], $index, 1, $override);
        }
      }
    }
  }
}

/**
 * Initializes the attributes array from the classes array.
 */
function omega_initialize_attributes(&$variables) {
  $variables['attributes_array']['class'] = $variables['classes_array'];
  $variables['classes_array'] = &$variables['attributes_array']['class'];
}

/**
 * Processes the attributes and classes array.
 */
function omega_cleanup_attributes(&$variables, $hook) {
  // Break the reference between the classes array and the attributes array.
  unset($variables['classes_array']);

  // Clone the attributes array classes into the classes array for backwards
  // compatibility reasons. Note that we do not recommend using the classes in
  // classes array anyways.
  $variables['classes_array'] = isset($variables['attributes_array']['class']) ? $variables['attributes_array']['class'] : array();

  if (empty($variables['attributes_array']['class'])) {
    // Unset the 'class' attribute if it's empty so that we don't produce empty
    // class properties.
    unset($variables['attributes_array']['class']);
  }
}

/**
 * Overrides template_process_html().
 */
function omega_template_process_html_override(&$variables) {
  // Render page_top and page_bottom into top level variables.
  $variables['page_top'] = drupal_render($variables['page']['page_top']);
  $variables['page_bottom'] = drupal_render($variables['page']['page_bottom']);
  // Place the rendered HTML for the page body into a top level variable.
  $variables['page'] = $variables['page']['#children'];
  $variables['page_bottom'] .= omega_get_js('footer');

  $variables['head'] = drupal_get_html_head();
  $variables['css'] = drupal_add_css();
  $variables['styles']  = drupal_get_css();
  $variables['scripts'] = omega_get_js();
}

/**
 * Implements hook_block_list_alter().
 */
function omega_block_list_alter(&$blocks) {
  if (omega_extension_enabled('layouts') && $layout = omega_layout()) {
    // In case we are currently serving a Omega layout we have to make sure that
    // we don't process blocks that will never be shown because the active layout
    // does not even have a region for them.
    foreach ($blocks as $id => $block) {
      if (!array_key_exists($block->region, $layout['info']['regions'])) {
        unset($blocks[$id]);
      }
    }
  }

  // Hide the main content block on the front page if the theme settings are
  // configured that way.
  if (!omega_theme_get_setting('omega_toggle_front_page_content', TRUE) && drupal_is_front_page()) {
    foreach ($blocks as $key => $block) {
      if ($block->module == 'system' && $block->delta == 'main') {
        unset($blocks[$key]);
      }
    }

    drupal_set_page_content();
  }
}

/**
 * Implements hook_page_delivery_callback_alter().
 */
function omega_page_delivery_callback_alter(&$callback) {
  if (module_exists('overlay') && overlay_display_empty_page()) {
    $callback = 'omega_override_overlay_deliver_empty_page';
  }
}

/**
 * Delivery callback to display an empty page.
 *
 * This function is used to print out a bare minimum empty page which still has
 * the scripts and styles necessary in order to trigger the overlay to close.
 */
function omega_override_overlay_deliver_empty_page() {
  $empty_page = '<html><head><title></title>' . drupal_get_css() . omega_get_js() . '</head><body class="overlay"></body></html>';
  print $empty_page;
  drupal_exit();
}

/**
 * Implements hook_page_alter().
 */
function omega_page_alter(&$page) {
  // Place dummy blocks in each region if the 'demo regions' setting is active
  // to force regions to be rendered.
  if (omega_extension_enabled('development') && omega_theme_get_setting ('omega_demo_regions', TRUE) && user_access('administer site configuration')) {
    $item = menu_get_item();

    // Don't interfere with the 'Demonstrate block regions' page.
    if (strpos('admin/structure/block/demo/', $item['path']) !== 0) {
      $regions = system_region_list($GLOBALS['theme_key'], REGIONS_VISIBLE);
      $configured = omega_theme_get_setting('omega_demo_regions_list', array_keys($regions));

      // We don't explicitly load possible layout regions and instead really
      // just show demo regions for those regions that we can actually place
      // blocks in. Hence, there will only be demo regions for those regions
      // that have been declared through the theme's .info file.
      foreach (array_intersect_key($regions, array_flip($configured)) as $region => $name) {
        if (empty($page[$region])) {
          $page[$region]['#theme_wrappers'] = array('region');
          $page[$region]['#region'] = $region;
        }

        $page[$region]['#name'] = $name;
        $page[$region]['#debug'] = TRUE;
      }
    }
  }

  if (omega_extension_enabled('compatibility') && omega_theme_get_setting('omega_chrome_edge', TRUE) && omega_theme_get_setting('omega_chrome_notice', TRUE)) {
    $supported = omega_theme_get_setting('omega_internet_explorer_support', FALSE);

    $page['page_top']['omega_chrome'] = array(
      '#theme' => 'omega_chrome',
      '#pre_render' => array('drupal_pre_render_conditional_comments'),
      '#browsers' => array(
        'IE' => !$supported ? TRUE : 'lte IE ' . $supported,
        '!IE' => FALSE,
      ),
    );
  }
}

/**
 * Implements hook_html_head_alter().
 */
function omega_html_head_alter(&$head) {
  // Simplify the meta tag for character encoding.
  $head['system_meta_content_type']['#attributes'] = array('charset' => str_replace('text/html; charset=', '', $head['system_meta_content_type']['#attributes']['content']));
}

/**
 * Implements hook_omega_theme_libraries_info().
 */
function omega_omega_theme_libraries_info($theme) {
  $path = drupal_get_path('theme', 'omega');

  $libraries['selectivizr'] = array(
    'name' => t('Selectivizr'),
    'description' => t('Selectivizr is a JavaScript utility that emulates CSS3 pseudo-classes and attribute selectors in Internet Explorer 6-8. Simply include the script in your pages and selectivizr will do the rest.'),
    'vendor' => 'Keith Clark',
    'vendor url' => 'http://selectivizr.com/',
    'package' => t('Polyfills'),
    'files' => array(
      'js' => array(
        $path . '/libraries/selectivizr/selectivizr.min.js' => array(
          'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
          'weight' => 110,
          'every_page' => TRUE,
        ),
      ),
    ),
    'variants' => array(
      'source' => array(
        'name' => t('Source'),
        'description' => t('During development it might be useful to include the source files instead of the minified version.'),
        'files' => array(
          'js' => array(
            $path . '/libraries/selectivizr/selectivizr.js' => array(
              'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
              'weight' => 110,
              'every_page' => TRUE,
            ),
          ),
        ),
      ),
    ),
  );

  $libraries['css3mediaqueries'] = array(
    'name' => t('CSS3 Media Queries'),
    'description' => t('CSS3 Media Queries is a JavaScript library to make IE 5+, Firefox 1+ and Safari 2 transparently parse, test and apply CSS3 Media Queries. Firefox 3.5+, Opera 7+, Safari 3+ and Chrome already offer native support. Note: This library requires <a href="!url">CSS aggregation</a> to be enabled for it to work properly.', array('!url' => url('admin/config/development/performance'))),
    'vendor' => 'Wouter van der Graaf',
    'vendor url' => 'http://woutervandergraaf.nl/',
    'package' => t('Polyfills'),
    'callbacks' => array('omega_extension_library_requirements_css_aggregation'),
    'files' => array(
      'js' => array(
        $path . '/libraries/css3mediaqueries/css3mediaqueries.min.js' => array(
          'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
          'weight' => 100,
          'every_page' => TRUE,
        ),
      ),
    ),
    'variants' => array(
      'source' => array(
        'name' => t('Source'),
        'description' => t('During development it might be useful to include the source files instead of the minified version.'),
        'files' => array(
          'js' => array(
            $path . '/libraries/css3mediaqueries/css3mediaqueries.js' => array(
              'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
              'weight' => 100,
              'every_page' => TRUE,
            ),
          ),
        ),
      ),
    ),
  );

  $libraries['respond'] = array(
    'name' => t('Respond'),
    'description' => t('Respond is a fast & lightweight polyfill for min/max-width CSS3 Media Queries (for IE 6-8, and more). Note: This library requires <a href="!url">CSS aggregation</a> to be enabled for it to work properly.', array('!url' => url('admin/config/development/performance'))),
    'vendor' => 'Scott Jehl',
    'vendor url' => 'http://scottjehl.com/',
    'package' => t('Polyfills'),
    'callbacks' => array('omega_extension_library_requirements_css_aggregation'),
    'files' => array(
      'js' => array(
        $path . '/libraries/respond/respond.min.js' => array(
          'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
          'weight' => 120,
          'every_page' => TRUE,
        ),
      ),
    ),
    'variants' => array(
      'source' => array(
        'name' => t('Source'),
        'description' => t('During development it might be useful to include the source files instead of the minified version.'),
        'files' => array(
          'js' => array(
            $path . '/libraries/respond/respond.js' => array(
              'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
              'weight' => 120,
              'every_page' => TRUE,
            ),
          ),
        ),
      ),
    ),
  );

  $libraries['css3pie'] = array(
    'name' => t('CSS3 PIE'),
    'description' => t('PIE makes Internet Explorer 6-9 capable of rendering several of the most useful CSS3 decoration features.'),
    'vendor' => 'Keith Clark',
    'vendor url' => 'http://css3pie.com/',
    'options form' => 'omega_library_pie_options_form',
    'package' => t('Polyfills'),
    'files' => array(),
    'variants' => array(
      'js' => array(
        'name' => t('JavaScript'),
        'description' => t('While the .htc behavior is still the recommended approach for most users, the JS version has some advantages that may be a better fit for some users.'),
        'files' => array(
          'js' => array(
            $path . '/libraries/css3pie/PIE.js' => array(
              'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
              'weight' => 100,
              'every_page' => TRUE,
            ),
          ),
        ),
      ),
    ),
  );

  $settings = omega_theme_get_setting('omega_libraries');
  if (!empty($settings['css3pie']['selectors'])) {
    // Add the generated .css file to the corresponding variant.
    $destination = file_create_url('public://omega/' . $theme );
    $destination = substr($destination, strlen($GLOBALS['base_url']) + 1);
    file_prepare_directory($destination, FILE_CREATE_DIRECTORY);

    // Save the generated CSS in the public file system.
    $file = $destination . '/pie-selectors.css';
    $htc = base_path() . drupal_get_path('theme', 'omega');
    $contents = implode(",", $settings['css3pie']['selectors']) . "{behavior:url({$htc}/libraries/css3pie/PIE.htc)}";
    file_unmanaged_save_data($contents, $file, FILE_EXISTS_REPLACE);

    $libraries['css3pie']['files']['css'][$file] = array(
      'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
      'weight' => 100,
      'every_page' => TRUE,
    );

    // Save the generated JS in the public file system.
    $file = $destination . '/pie-selectors.js';
    $contents = '$(function(){Drupal.behaviors.css3pie={attach:function(context,settings){if(window.PIE){$("' . implode(",", $settings['css3pie']['selectors']) . '").each(function(){PIE.attach(this)})}}}})(jQuery);';
    file_unmanaged_save_data($contents, $file, FILE_EXISTS_REPLACE);

    $libraries['css3pie']['variants']['js']['files']['js'][$file] = array(
      'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
      'weight' => 100,
      'every_page' => TRUE,
    );
  }

  $libraries['html5shiv'] = array(
    'name' => t('HTML5 Shiv'),
    'description' => t('This script is the defacto way to enable use of HTML5 sectioning elements in legacy Internet Explorer, as well as default HTML5 styling in Internet Explorer 6 - 9, Safari 4.x (and iPhone 3.x), and Firefox 3.x.'),
    'vendor' => 'Alexander Farkas',
    'package' => t('Polyfills'),
    'files' => array(
      'js' => array(
        $path . '/libraries/html5shiv/html5shiv.min.js' => array(
          'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
          'weight' => 100,
          'every_page' => TRUE,
        ),
      ),
    ),
    'variants' => array(
      'source' => array(
        'name' => t('Source'),
        'description' => t('During development it might be useful to include the source files instead of the minified version.'),
        'files' => array(
          'js' => array(
            $path . '/libraries/html5shiv/html5shiv.js' => array(
              'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
              'weight' => 100,
              'every_page' => TRUE,
            ),
          ),
        ),
      ),
    ),
  );

  $libraries['messages'] = array(
    'name' => t('Discardable messages'),
    'description' => t("Adds a 'close' button to each message."),
    'package' => t('Goodies'),
    'files' => array(
      'js' => array(
        $path . '/js/omega.messages.js' => array(
          'weight' => -100,
          'every_page' => TRUE,
        ),
      ),
      'css' => array(
        $path . '/css/omega.messages.css' => array(
          'weight' => -100,
          'every_page' => TRUE,
        ),
      ),
    ),
  );

  return $libraries;
}

/**
 * Theme callback for rendering an Omega layout.
 */
function omega_omega_layout($variables) {
  drupal_process_attached(array('#attached' => $variables['omega_layout']['attached']));

  // Clean up the theme hook suggestion so we don't end up in an infinite loop.
  unset($variables['theme_hook_suggestion'], $variables['theme_hook_suggestions']);
  return theme($variables['omega_layout']['template'], $variables);
}

/**
 * Shows a notice when Google Chrome Frame is not installed.
 */
function omega_omega_chrome($variables) {
  $message = t('You are using an outdated browser! <a href="!upgrade">Upgrade your browser today</a> or <a href="!install">install Google Chrome Frame</a> to better experience this site.', array(
    '!upgrade' => url('http://browsehappy.com'),
    '!install' => url('http://www.google.com/chromeframe', array(
      'query' => array('redirect' => 'true')
    )),
  ));

  return '<p class="chromeframe">' . $message . '</p>';
}
