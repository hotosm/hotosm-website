<?php

/**
 * @file
 * All Preprocess functions for templates and theme fucntions.
 * If you need to add or modify preprocess functions do it in your sub-theme.
 */

/**
 * Preprocess variables for all templates.
 */
function adaptivetheme_preprocess(&$vars) {
  // Provide a variable to all templates to test for a mobile context, this
  // requires the Browscap module and returns TRUE or FALSE.
  $vars['is_mobile'] = at_get_browser();
}

/**
 * Preprocess variables for html.tpl.php
 */
function adaptivetheme_preprocess_html(&$vars) {
  global $theme_key, $language;
  $theme_name = $theme_key;

  // Set variable for the base path
  $vars['base_path'] = base_path();

  // Get the info file data
  $info = at_get_info($theme_name);

  // DOCTYPE
  // AT no longer uses doctype switching or $rdf_profile, these maintain
  // backwards compatibility with pre 7.x-2.1 versions of html.tpl.php
  $vars['doctype'] = '<!DOCTYPE html>' . "\n";
  $vars['rdf_profile'] = '';

  // Use a proper attributes array for the html attributes
  $vars['html_attributes_array']['lang'][] = $language->language;
  $vars['html_attributes_array']['dir'][] = $language->dir;

  // Convert RDF Namespaces into structured data using drupal_attributes.
  $vars['rdf_namespaces'] = array();
  if (function_exists('rdf_get_namespaces')) {
    foreach (rdf_get_namespaces() as $prefix => $uri) {
      $prefixes[] = $prefix . ': ' . $uri;
    }
    $vars['rdf_namespaces_array']['prefix'] = implode(' ', $prefixes);
  }

  // Get the path to the directory where our CSS files are saved
  $path = variable_get('theme_' . $theme_name . '_files_directory');

  // Load Layout
  load_layout_css($path, $theme_name);

  // Load Responsive Styles.
  if (at_get_setting('disable_responsive_styles', $theme_name) === 0) {
    load_responsive_css($path, $theme_name);
  }

  // Load fonts and/or Custom CSS
  if (at_get_setting('enable_extensions', $theme_name) === 1) {
    // Fonts CSS
    if (at_get_setting('enable_font_settings', $theme_name) === 1) {
      load_fonts($path, $theme_name);
    }
    // Custom CSS
    if (at_get_setting('enable_custom_css', $theme_name) === 1) {
      load_custom_css($path, $theme_name);
    }
    // Load Extension Settings CSS
    load_extensions_css($theme_name);
  }

  // Load conditional stylesheets declared in the info file
  if (isset($info['ie_stylesheets'])) {
    load_subtheme_conditional_styles($theme_name);
  }

  // Load specific subtheme scripts
  if (at_get_setting('load_onmediaqueryjs', $theme_name) === 1) {
    load_subtheme_script('scripts/media_queries.js', $theme_name, 'footer', '100');
  }

  // Build an array of polyfilling scripts
  $vars['polyfills_array'] = '';
  $vars['polyfills_array'] = load_polyfills($theme_name, $vars);

  // Set the skip link target id
  $vars['skip_link_target'] = '#main-content';
  if (at_get_setting('skip_link_target', $theme_name)) {
    $skip_link_target = at_get_setting('skip_link_target', $theme_name);
    $vars['skip_link_target'] = check_plain($skip_link_target);
  }

  // Generate body classes
  if ($html_classes = generate_html_classes($vars, $theme_name)) {
    foreach ($html_classes as $class_name) {
      $vars['classes_array'][] = $class_name;
    }
  }

  // Do some legacy stuff for 7.x-2.x themes that have google webfonts running
  // on the old system. Scan for the existence of a "release" key and
  // conditionally load google.web.fonts.inc
  if (!isset($info['release']) || $info['release'] === '7.x-2.x') {
    include_once(drupal_get_path('theme', 'adaptivetheme') . '/inc/google.web.fonts.inc');
  }

  // Load debuggers if enabled. Panels page debugger is a menu item, see alter.inc
  if (at_get_setting('expose_regions', $theme_name) === 1 || at_get_setting('show_window_size', $theme_name) === 1 || at_get_setting('load_all_panels', $theme_name) === 1) {
    load_debuggers($theme_name);
  }
}

/**
 * Preprocess variables for page.tpl.php
 */
function adaptivetheme_preprocess_page(&$vars) {
  global $theme_key;
  $theme_name = $theme_key;

  // Set up logo element
  if (at_get_setting('toggle_logo', $theme_name) === 1) {
    $vars['site_logo'] = drupal_static('adaptivetheme_preprocess_page_site_logo');
    if (empty($vars['site_logo'])) {
      $logo_path = check_url($vars['logo']);
      $logo_alt = check_plain(variable_get('site_name', t('Site logo')));
      $logo_vars = array('path' => $logo_path, 'alt' => $logo_alt, 'attributes' => array('class' => 'site-logo'));
      $vars['logo_img'] = theme('image', $logo_vars);
      $vars['site_logo'] = $vars['logo_img'] ? l($vars['logo_img'], '<front>', array('attributes' => array('title' => t('Home page')), 'html' => TRUE)) : '';
    }
    // Maintain backwards compatibility with 7.x-2.x sub-themes
    $vars['linked_site_logo'] = $vars['site_logo'];
  }
  else {
    $vars['site_logo'] = '';
    $vars['logo_img'] = '';
    $vars['linked_site_logo'] = '';
  }

  // Site name
  $vars['site_name'] = &drupal_static('adaptivetheme_preprocess_page_site_name');
  if (empty($vars['site_name'])) {
    $vars['site_name_title'] = variable_get('site_name', 'Drupal');
    $vars['site_name'] = l($vars['site_name_title'], '<front>', array('attributes' => array('title' => t('Home page'))));
    $vars['site_name_unlinked'] = $vars['site_name_title'];
  }

  // Site name visibility and other classes and variables
  $vars['site_name_attributes_array'] = array();
  $vars['visibility'] = '';
  $vars['hide_site_name'] = FALSE;
  if (at_get_setting('toggle_name', $theme_name) === 0) {
    // Keep the visibility variable to maintain backwards compatibility
    $vars['visibility'] = 'element-invisible';
    $vars['site_name_attributes_array']['class'][] = $vars['visibility'];
    $vars['hide_site_name'] = TRUE;
  }

  // Build a variable for the main menu
  if (isset($vars['main_menu'])) {
    $vars['primary_navigation'] = theme('links', array(
      'links' => $vars['main_menu'],
      'attributes' => array(
        'class' => array('menu', 'primary-menu', 'clearfix'),
       ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }

  // Build a variable for the secondary menu
  if (isset($vars['secondary_menu'])) {
    $vars['secondary_navigation'] = theme('links', array(
      'links' => $vars['secondary_menu'],
      'attributes' => array(
        'class' => array('menu', 'secondary-menu', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Secondary navigation'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }

  // Build variables for Primary and Secondary local tasks
  $vars['primary_local_tasks'] = menu_primary_local_tasks();
  $vars['secondary_local_tasks'] = menu_secondary_local_tasks();

  // Add back the $search_box var to D7
  if (module_exists('search')) {
    $search_box = drupal_get_form('search_form');
    $vars['search_box'] = '<div id="search-box">' . drupal_render($search_box) . '</div>';
  }

  // Process enabled Extensions
  if (at_get_setting('enable_extensions', $theme_name) === 1) {
    // Generate page classes, in AT Core these are all Extensions
    if ($page_classes = generate_page_classes($vars, $theme_name)) {
      foreach ($page_classes as $class_name) {
        $vars['classes_array'][] = $class_name;
      }
    }
    // Process modify markup settings
    if (at_get_setting('enable_markup_overides', $theme_name) === 1) {
      // Remove the infernal feed icons
      if (at_get_setting('feed_icons_hide', $theme_name) === 1) {
        $vars['feed_icons'] = '';
      }
    }
  }

  // Strip stupid contextual-links-region class, wtf?
  $vars['classes_array'] = array_values(array_diff($vars['classes_array'], array('contextual-links-region')));

  // page attributes
  $vars['page_attributes_array']['id'][] = 'page';
  $vars['page_attributes_array']['class'] = $vars['classes_array'];

  // header attributes
  $vars['header_attributes_array']['id'][] = 'header';
  $vars['header_attributes_array']['class'][] = 'clearfix';
  $vars['header_attributes_array']['role'][] = 'banner';

  // hgroup attributes
  $vars['hgroup_attributes_array'] = array();
  if (!$vars['site_slogan'] && $vars['hide_site_name']) {
    $vars['hgroup_attributes_array']['class'][] = $vars['visibility'];
  }

  // branding attributes
  $vars['branding_attributes_array']['id'][] = 'branding';
  $vars['branding_attributes_array']['class'][] = 'branding-elements';
  $vars['branding_attributes_array']['class'][] = 'clearfix';

  // hgroup attributes
  $vars['hgroup_attributes_array']['id'][] = 'name-and-slogan';

  // site name attributes
  $vars['site_name_attributes_array']['id'][] = 'site-name';

  // site slogan attributes
  $vars['site_slogan_attributes_array']['id'][] = 'site-slogan';

  // main content header attributes
  $vars['content_header_attributes_array']['id'][] = 'main-content-header';
  $vars['content_header_attributes_array']['class'][] = 'clearfix';

  // footer attributes
  $vars['footer_attributes_array']['id'][] = 'footer';
  $vars['footer_attributes_array']['class'][] = 'clearfix';
  $vars['footer_attributes_array']['role'][] = 'contentinfo';

  // Attribution variable used in admin theme and some others
  $vars['attribution'] = "<small class=\"attribution\"><a href=\"http://adaptivethemes.com\">Premium Drupal Themes</a></small>";

  // Work around a perculier bug/feature(?) in Drupal 7 which incorrectly sets
  // the page title to "User account" for all three of these pages.
  if (arg(0) === 'user') {
    if (arg(1) === 'login' || arg(1) == '') {
      drupal_set_title(t('User login'));
    }
    if (arg(1) === 'password') {
      drupal_set_title(t('Request new password'));
    }
    if (arg(1) === 'register') {
      drupal_set_title(t('Create new account'));
    }
  }
}

/**
 * Preprocess variables for region.tpl.php
 */
function adaptivetheme_preprocess_region(&$vars) {
  global $theme_key;
  $theme_name = $theme_key;

  $region = $vars['region'];

  // Add a "sidebar" class to sidebar regions
  if (strpos($region, 'sidebar_') === 0) {
    $vars['classes_array'][] = 'sidebar';
    // Allow a region-specific template to override the region--sidebar suggestion.
    array_unshift($vars['theme_hook_suggestions'], 'region__sidebar');
  }

  // Float region block classes
  if (at_get_setting('enable_extensions', $theme_name) === 1) {
    if (at_get_setting('enable_float_region_blocks', $theme_name) === 1) {

      // Make sure there is something set for the region, get the column count
      if ($float_blocks_regions_class = at_get_setting('float_block_' . $region)) {

        // Do nothing if its <none>
        if ($float_blocks_regions_class !== '<none>') {

          // Set a class for the number of columns selected, default to nothing
          $float_blocks_regions_class = isset($float_blocks_regions_class) ? check_plain($float_blocks_regions_class) : '';
          $vars['classes_array'][] = 'float-blocks-' . $float_blocks_regions_class;

          // Add the float direction class, default to left if the setting fails
          if ($float_block_direction_class = at_get_setting('float_block_direction_' . $region)) {
            $float_block_direction_class = isset($float_block_direction_class) ? check_plain($float_block_direction_class) : 'left';
            $vars['classes_array'][] = 'float-blocks-' . $float_block_direction_class;
          }
        }
      }
    }
  }

  // Add classes to conditional stack regions in Gpanel regions, in the Panels
  // layout plugins these are hard coded.
  $conditional_stack_regions = &drupal_static(__FUNCTION__, array());
  if (empty($conditional_stack_regions)) {
    $conditional_stack_regions = array(
      'three_25_25_50_top',
      'three_25_25_50_bottom',
      'three_25_50_25_top',
      'three_25_50_25_bottom',
      'three_50_25_25_top',
      'three_50_25_25_bottom',
      'three_33_top',
      'three_33_bottom',
      'two_50_top',
      'two_50_bottom',
      'two_33_66_top',
      'two_33_66_bottom',
      'two_66_33_top',
      'two_66_33_bottom',
      'two_brick_top',
      'two_brick_middle',
      'two_brick_bottom',
      'threecol_inset_left_top',
      'threecol_inset_left_bottom',
      'threecol_inset_right_top',
      'threecol_inset_right_bottom',
    );
  }
  if (in_array($region, $conditional_stack_regions)) {
    $vars['classes_array'][] = 'region-conditional-stack';
  }
}

/**
 * Preprocess variables for block.tpl.php
 */
function adaptivetheme_preprocess_block(&$vars) {
  global $theme_key;
  $theme_name = $theme_key;

  // Block subject, under certain conditions, is not set
  $vars['tag'] = 'div';
  $vars['title'] = '';

  if (isset($vars['block']->subject)) {
    if (!empty($vars['block']->subject)) {
      // Generate the wrapper element, if there's a title use section
      $vars['tag'] = 'section';

      // Use a $title variable instead of $block->subject
      $vars['title'] = $vars['block']->subject;
    }
    // subject can be set and empty, i.e. using <none>
    else {
      $vars['classes_array'][] = 'no-title';
    }
  }
  // sometimes subject is not set at all
  else {
    $vars['classes_array'][] = 'no-title';
  }

  // Search is never a section, its just a div
  if ($vars['block_html_id'] === 'block-search-form') {
    $vars['tag'] = 'div';
  }

  // Initialize and populate the inner wrapper variables
  $vars['inner_prefix'] = '<div class="block-inner clearfix">';
  $vars['inner_suffix'] = '</div>';

  // Use nav element for menu blocks and provide a suggestion for all of them
  $nav_blocks = array('navigation', 'main-menu', 'management', 'user-menu');
  if (in_array($vars['block']->delta, $nav_blocks)) {
    $vars['tag'] = 'nav';
    array_unshift($vars['theme_hook_suggestions'], 'block__menu');
  }
  $nav_modules = array('superfish', 'nice_menus', 'menu_block');
  if (in_array($vars['block']->module, $nav_modules)) {
    $vars['tag'] = 'nav';
    array_unshift($vars['theme_hook_suggestions'], 'block__menu');
  }

  // The menu bar region gets special treatment for the block template
  if ($vars['block']->region === 'menu_bar') {
    // They are always menu blocks, right?
    $vars['tag'] = 'nav';
  }

  // The menu bar region gets special treatment for the block template
  if ($vars['block']->region === 'menu_bar') {
    // Hide titles, very unlikey to want it show, ever
    $vars['title_attributes_array']['class'][] = 'element-invisible';
    $vars['classes_array'][] = 'menu-wrapper menu-bar-wrapper clearfix';
  }

  // Add extra classes if required
  if (at_get_setting('extra_block_classes', $theme_name) === 1) {

    // Zebra
    $vars['classes_array'][] = $vars['block_zebra'];

    // Position?
    if ($vars['block_id'] === 1) {
      $vars['classes_array'][] = 'first';
    }
    if (isset($vars['block']->last_in_region)) {
      $vars['classes_array'][] = 'last';
    }

    // Count
    $vars['classes_array'][] = 'block-count-' . $vars['id'];

    // Region
    $vars['classes_array'][] = drupal_html_class('block-region-' . $vars['block']->region);

    // Delta
    $vars['classes_array'][] = drupal_html_class('block-' . $vars['block']->delta);
  }

  // Add classes to theme the horizontal block option
  if (at_get_setting('enable_extensions', $theme_name) === 1) {
    if (at_get_setting('enable_markup_overides', $theme_name) === 1) {
      if (at_get_setting('horizontal_login_block', $theme_name) === 1 && $vars['block']->module === 'user' && $vars['block']->delta === 'login') {
        $vars['classes_array'][] = 'lb-h';
        $vars['title_attributes_array']['class'][] = 'element-invisible';
      }
      if (at_get_setting('slider_login_block', $theme_name) === 1 && $vars['block']->module === 'user' && $vars['block']->delta === 'login') {
        $vars['classes_array'][] = 'lb-s';
      }
    }
  }

  // Give our block titles and content some additional class
  $vars['title_attributes_array']['class'][] = 'block-title';
  $vars['content_attributes_array']['class'][] = 'block-content';
  $vars['content_attributes_array']['class'][] = 'content';

  // Add Aria Roles via attributes
  switch ($vars['block']->module) {
    case 'system':
      switch ($vars['block']->delta) {
        case 'main':
          // Note: the "main" role goes in the page.tpl, not here.
          break;
        case 'help':
        case 'powered-by':
          $vars['attributes_array']['role'] = 'complementary';
          break;
        default:
          // Any other "system" block is a menu block.
          $vars['attributes_array']['role'] = 'navigation';
          break;
      }
      break;
    case 'menu':
    case 'menu_block':
    case 'blog':
    case 'book':
    case 'comment':
    case 'forum':
    case 'shortcut':
    case 'statistics':
      $vars['attributes_array']['role'] = 'navigation';
      break;
    case 'search':
      $vars['attributes_array']['role'] = 'search';
      break;
    case 'help':
    case 'aggregator':
    case 'locale':
    case 'poll':
    case 'profile':
      $vars['attributes_array']['role'] = 'complementary';
      break;
    case 'node':
      switch ($vars['block']->delta) {
        case 'syndicate':
          $vars['attributes_array']['role'] = 'complementary';
          break;
        case 'recent':
          $vars['attributes_array']['role'] = 'navigation';
          break;
      }
      break;
    case 'user':
      switch ($vars['block']->delta) {
        case 'login':
          $vars['attributes_array']['role'] = 'form';
          break;
        case 'new':
        case 'online':
          $vars['attributes_array']['role'] = 'complementary';
          break;
      }
      break;
  }
}

/**
 * Preprocess variables for panels_pane.tpl.php
 */
function adaptivetheme_preprocess_panels_pane(&$vars) {
  // Top level wrapper
  $vars['tag'] = $vars['title'] ? 'section' : 'div';

  // Add the same classes as blocks
  if (empty($vars['title'])) {
    $vars['classes_array'][] = 'no-title';
  }
  $vars['classes_array'][] = 'block';

  // Use the attributes arrays to add classes.
  $vars['title_attributes_array']['class'][] = 'block-title';
  $vars['attributes_array']['class'] = $vars['classes_array'];
  $vars['content_attributes_array']['class'][] = 'block-content';
}

/**
 * Preprocess variables for field.tpl.php
 */
function adaptivetheme_preprocess_field(&$vars) {
  global $theme_key;
  $theme_name = $theme_key;

  $element = $vars['element'];

 // Set the top level element as either <section> (if the field label is showing),
 // or <div> if the field label is hidden.
  $vars['tag'] = 'section';
  if (isset($vars['label_hidden']) && $vars['label_hidden'] == TRUE) {
    $vars['tag'] = 'div';
  }

  $vars['field_view_mode'] = '';
  if (isset($element['#view_mode'])) {
    // add a view mode class to fields
    $vars['classes_array'][] = 'view-mode-' . $element['#view_mode'];
    // Set variable for view mode, appears to be not gettable in a template
    $vars['field_view_mode'] = $element['#view_mode'];
  }

  // Image fields
  if ($element['#field_type'] === 'image') {

    // Set some vars for image captioning, these always need to be initialized
    $vars['image_caption_teaser'] = FALSE;
    $vars['image_caption_full'] = FALSE;

    // Dont run anything if extensions or image settings are disabled
    if (at_get_setting('enable_extensions', $theme_name) === 1) {
      if (at_get_setting('enable_image_settings', $theme_name) === 1) {

        // Reduce number of images in teaser view mode to single image
        if (at_get_setting('image_teaser', $theme_name) === 1) {
          if ($element['#view_mode'] == 'teaser') {
            $item = reset($vars['items']);
            $vars['items'] = array($item);
          }
        }

        // Captions
        if (at_get_setting('image_caption_teaser', $theme_name) === 1) {
          $vars['image_caption_teaser'] = TRUE;
        }
        if (at_get_setting('image_caption_full', $theme_name) === 1) {
          $vars['image_caption_full'] = TRUE;
        }
      }
    }
  }
}

/**
 * Preprocess variables for node.tpl.php
 */
function adaptivetheme_preprocess_node(&$vars) {
  global $theme_key;
  $theme_name = $theme_key;

  // article class to attempt backwards compatibility
  $vars['classes_array'][] = 'article';

  // Extra classes if required
  if (at_get_setting('extra_article_classes', $theme_name) === 1) {

    // Zebra
    $vars['classes_array'][] = $vars['zebra'];

    // Langauge
    if (module_exists('translation')) {
      if ($vars['node']->language) {
        $vars['classes_array'][] = 'node-lang-' . $vars['node']->language;
      }
    }

    // User picture?
    if (at_get_setting('toggle_node_user_picture', $theme_name) === 1) {
      if ($vars['display_submitted'] && !empty($vars['picture'])) {
        $vars['classes_array'][] = 'node-with-picture';
      }
    }

    // Class for each view mode, core assumes we only need to target teasers but neglects custom view modes or full
    if ($vars['view_mode'] !== 'teaser') {
      $vars['classes_array'][] = drupal_html_class('node-' . $vars['view_mode']);
    }
  }

  // Image alignment and caption classes
  if (at_get_setting('enable_extensions', $theme_name) === 1) {
    if (at_get_setting('enable_image_settings', $theme_name) === 1) {
      if ($vars['view_mode'] !== 'teaser') {
        if ($image_caption_full = at_get_setting('image_caption_full', $theme_name)) {
          $vars['classes_array'][] = $image_caption_full;
        }
        if ($image_alignment = at_get_setting('image_alignment', $theme_name)) {
          $vars['classes_array'][] = $image_alignment;
        }
      }
      if ($vars['view_mode'] == 'teaser') {
        if ($image_caption_teaser = at_get_setting('image_caption_teaser', $theme_name)) {
          $vars['classes_array'][] = $image_caption_teaser;
        }
        if ($image_alignment_teaser = at_get_setting('image_alignment_teaser', $theme_name)) {
          $vars['classes_array'][] = $image_alignment_teaser;
        }
      }
    }
  }

  // ARIA Role
  $vars['attributes_array']['role'][] = 'article';

  // Classes and attributes
  $vars['title_attributes_array']['class'][] = 'node-title';
  $vars['content_attributes_array']['class'][] = 'node-content';
  $vars['title_attributes_array']['rel'][] = 'nofollow';

  // header, submitted and links wrappers have their own attributes
  $vars['header_attributes_array']['class'][] = 'node-header';
  $vars['footer_attributes_array']['class'][] = 'submitted';
  if ($vars['user_picture']) {
    $vars['footer_attributes_array']['class'][] = 'with-user-picture';
  }
  $vars['links_attributes_array']['class'][] = 'clearfix';

  //
  // AT Core builds additional time and date variables for use in templates
  //
  // datetime stamp formatted correctly to ISO8601
  $vars['datetime'] = format_date($vars['created'], 'custom', 'Y-m-d\TH:i:sO'); // PHP 'c' format is not proper ISO8601!

  // Publication date, formatted with time element
  $vars['publication_date'] = '<time datetime="' . $vars['datetime'] . '" pubdate="pubdate">' . $vars['date'] . '</time>';

  // Last update variables
  $vars['datetime_updated'] = format_date($vars['node']->changed, 'custom', 'Y-m-d\TH:i:sO');
  $vars['custom_date_and_time'] = date('jS F, Y - g:ia', $vars['node']->changed);

  // Last updated formatted in time element
  $vars['last_update'] = '<time datetime="' . $vars['datetime_updated'] . '" pubdate="pubdate">' . $vars['custom_date_and_time'] . '</time>';

  // Build the submitted variable used by default in node templates
  if (variable_get('node_submitted_' . $vars['node']->type, TRUE)) {
    $vars['submitted'] = t('Submitted by !username on !datetime',
      array(
        '!username' => $vars['name'],
        '!datetime' => $vars['publication_date'],
      )
    );
  }
  else {
    $vars['submitted'] = '';
  }

  // Unpublished?
  $vars['unpublished'] = ''; // Initialize for backwards compatibility
  if (!$vars['status']) {
    // Use the title prefix to render the unpublished message
    $vars['title_prefix']['unpublished']['#markup'] = '<p class="unpublished">' . t('Unpublished') . '</p>';
  }

  // Add nofollow to Book module print/export links
  if (isset($vars['content']['links']['book']['#links']['book_printer'])) {
    $vars['content']['links']['book']['#links']['book_printer']['attributes'] = array('rel' => array('nofollow'));
  }
}

/**
 * Preprocess variables for comment.tpl.php
 */
function adaptivetheme_preprocess_comment(&$vars) {
  global $theme_key;
  $theme_name = $theme_key;

  // Extra comment classes if required
  if (at_get_setting('extra_comment_classes', $theme_name) === 1) {

    // Zebra
    $vars['classes_array'][] = $vars['zebra'];

    // Position?
    if ($vars['id'] === 1) {
      $vars['classes_array'][] = 'first';
    }
    if ($vars['id'] === $vars['node']->comment_count) {
      $vars['classes_array'][] = 'last';
    }

    // Title hidden?
    if (at_get_setting('comments_hide_title', $theme_name) === 1) {
      $vars['classes_array'][] = 'comment-title-hidden';
    }

    // User picture?
    if (at_get_setting('toggle_comment_user_picture', $theme_name) === 1) {
      if (!empty($vars['picture'])) {
        $vars['classes_array'][] = 'comment-with-picture';
      }
    }

    // Signature?
    if (!empty($vars['signature'])) {
      $vars['classes_array'][] = 'comment-with-signature';
    }
  }

  // Classes for comment title
  $vars['title_attributes_array']['class'][] = 'comment-title';

  // Title hidden?
  if (at_get_setting('enable_extensions', $theme_name) === 1) {
    if (at_get_setting('enable_markup_overides', $theme_name) === 1) {
      if (at_get_setting('comments_hide_title', $theme_name) === 1) {
        $vars['title_attributes_array']['class'][] = 'element-invisible';
      }
    }
  }

  // Classes for comment content
  $vars['content_attributes_array']['class'][] = 'comment-content';

  // header, submitted and links wrappers have their own attributes
  $vars['header_attributes_array']['class'][] = 'comment-header';
  $vars['footer_attributes_array']['class'][] = 'submitted';
  if ($vars['picture']) {
    $vars['footer_attributes_array']['class'][] = 'with-user-picture';
  }
  $vars['links_attributes_array']['class'][] = 'clearfix';

  // Build the submitted by and time elements
  $uri = entity_uri('comment', $vars['comment']);
  $uri['options'] += array('attributes' => array('rel' => 'bookmark'));
  $vars['title'] = l($vars['comment']->subject, $uri['path'], $uri['options']);
  $vars['permalink'] = l(t('Permalink'), $uri['path'], $uri['options']); // Permalinks are embedded in the time element, aka Wordpress
  $vars['created'] = '<span class="date-time permalink">' . l($vars['created'], $uri['path'], $uri['options']) . '</span>';
  $vars['datetime'] = format_date($vars['comment']->created, 'custom', 'Y-m-d\TH:i:s\Z'); // Generate the timestamp, PHP "c" format is wrong
  $vars['submitted'] = t('Submitted by !username on !datetime',
    array(
      '!username' => $vars['author'],
      '!datetime' => '<time datetime="' . $vars['datetime'] . '" pubdate="pubdate">' . $vars['created'] . '</time>',
    )
  );

  // Unpublished?
  $vars['unpublished'] = ''; // Initialize for backwards compatibility
  if ($vars['status'] === 'comment-unpublished') {
    // Use the title prefix to render the unpublished message
    $vars['title_prefix']['unpublished']['#markup'] = '<p class="unpublished">' . t('Unpublished') . '</p>';
  }
}

/**
 * Preprocess variables for the search block form.
 */
function adaptivetheme_preprocess_search_block_form(&$vars) {
  // Changes the search form to use the "search" input element attribute (HTML5)
  // We have to replace the string because FAPI don't know what type=search is, i.e.
  // no way we can do this in a form alter hook.
  $vars['search_form'] = str_replace('type="text"', 'type="search"', $vars['search_form']);
}

/**
 * Preprocess variables for aggregator-item.tpl.php
 */
function adaptivetheme_preprocess_aggregator_item(&$vars) {
  $item = $vars['item'];
  // We want the same highly accurate time stamp feature as nodes and comments
  $vars['datetime'] = format_date($item->timestamp, 'custom', 'Y-m-d\TH:i:sO');
  // Give our aggregator items some class
  $vars['classes_array'][] = 'feed-item clearfix';
  $vars['title_attributes_array']['class'][] = 'title feed-item-title';
  $vars['content_attributes_array']['class'][] = 'content feed-item-content';
}

/**
 * Preprocess variables for adaptivtheme_menubar()
 */
function adaptivetheme_preprocess_menubar(&$vars) {
  $type = $vars['type'];
  $vars['menubar_id'] = $type . '-menu-bar';
  $vars['classes_array'][] = 'nav clearfix';
  $vars['content_attributes_array']['role'][] = 'navigation';
  $vars['content_attributes_array']['class'][] = $type . '-menu-wrapper menu-wrapper clearfix';
  // Add suggstions per menu type
  $vars['theme_hook_suggestions'][] = 'menubar__' . $type;
}

/**
 * Preprocess variables for the username.
 */
function adaptivetheme_preprocess_username(&$vars) {
  global $theme_key;
  $theme_name = $theme_key;
  // Add rel=author for SEO and supporting search engines
  if (at_get_setting('enable_extensions', $theme_name) === 1) {
    if (at_get_setting('enable_markup_overides', $theme_name) === 1) {
      if (at_get_setting('rel_author', $theme_name) === 1) {
        if (isset($vars['link_path'])) {
          $vars['link_attributes']['rel'][] = 'author';
        }
        else {
          $vars['attributes_array']['rel'][] = 'author';
        }
      }
    }
  }
}

/**
 * Preprocess variables for theme_image()
 */
function adaptivetheme_preprocess_image(&$vars) {

  // Initialize the variable if there isn't one
  if (!isset($vars['attributes']['class'])) {
    $vars['attributes']['class'] = array();
  }

  // Some modules set the style name even when its empty, such as User Badges
  // module, so initialize the class name variable with a "none" class
  $style_name_class = 'none';
  
  // If there really is a style name use it for the class
  if (isset($vars['style_name']) && !empty($vars['style_name'])) {
    $style_name_class = drupal_html_class($vars['style_name']);
  }

  // In the first instance we assume class attributes is an array, as it should be,
  // and add the image style class
  if (is_array($vars['attributes']['class'])) {
    $vars['attributes']['class'][] = 'image-style-' . $style_name_class;
  }
  else {
    // Else it's a string, workaround for Media module bug: http://drupal.org/node/1722146
    // and User Badges bug: http://drupal.org/node/1748394
    $vars['attributes']['class'] .= ' image-style-' . $style_name_class;
  }
}

/**
 * Preprocess variables for maintenance-page.tpl.php
 */
function adaptivetheme_preprocess_maintenance_page(&$vars) {
  global $theme_key;
  $theme_name = $theme_key;

  // Get the path to the directory where our CSS files are saved
  $path = variable_get('theme_' . $theme_name . '_files_directory');

  // Load Layout
  load_layout_css($path, $theme_name);

  // Load Responsive Styles.
  if (at_get_setting('disable_responsive_styles', $theme_name) === 0) {
    load_responsive_css($path, $theme_name);
  }

  // Load fonts and/or Custom CSS
  if (at_get_setting('enable_extensions', $theme_name) === 1) {
    // Fonts CSS
    if (at_get_setting('enable_font_settings', $theme_name) === 1) {
      load_fonts($path, $theme_name);
    }
    // Custom CSS
    if (at_get_setting('enable_custom_css', $theme_name) === 1) {
      load_custom_css($path, $theme_name);
    }
    // Load Extension Settings CSS
    load_extensions_css($theme_name);
  }

  // Build an array of polyfilling scripts
  $vars['polyfills_array'] = '';
  $vars['polyfills_array'] = load_polyfills($theme_name, $vars);

  // Load the colors stylesheet for the active color scheme. This only works
  // for maintenance mode, when there is a database error the default color
  // scheme will be used.
  if (module_exists('color')) {
    $color_file = variable_get('color_' . $theme_name . '_stylesheets', NULL);
    if (file_exists($color_file[0])) {
      drupal_add_css($color_file[0], array(
        'group' => CSS_THEME,
        'weight' => 99,
        )
      );
    }
  }

  $vars['attribution'] = "<small id=\"attribution\"><a href=\"http://adaptivethemes.com\">Premium Drupal Themes</a></small>";
}
