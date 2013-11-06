<?php
/**
 * @file
 * hot_theme.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hot_theme_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme';
  $strongarm->value = 'seven';
  $export['admin_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_at_hot_files_directory';
  $strongarm->value = 'public://adaptivetheme/at_hot_files';
  $export['theme_at_hot_files_directory'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_at_hot_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 0,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 0,
    'default_logo' => 0,
    'logo_path' => 'sites/default/themes/images/logo.png',
    'logo_upload' => '',
    'default_favicon' => 0,
    'favicon_path' => 'sites/default/themes/images/favicon.ico',
    'favicon_upload' => '',
    'bigscreen_layout' => 'three_col_grail',
    'bigscreen_sidebar_unit' => '%',
    'bigscreen_sidebar_first' => '25',
    'bigscreen_sidebar_second' => '25',
    'bigscreen_page_unit' => '%',
    'bigscreen_page_width' => '100',
    'bigscreen_set_max_width' => 1,
    'bigscreen_max_width_unit' => 'px',
    'bigscreen_max_width' => '800',
    'bigscreen_media_query' => 'only screen and (min-width:1025px)',
    'tablet_landscape_layout' => 'three_col_grail',
    'tablet_landscape_sidebar_unit' => '%',
    'tablet_landscape_sidebar_first' => '20',
    'tablet_landscape_sidebar_second' => '20',
    'tablet_landscape_page_unit' => '%',
    'tablet_landscape_page_width' => '100',
    'tablet_landscape_media_query' => 'only screen and (min-width:769px) and (max-width:1024px)',
    'tablet_portrait_layout' => 'one_col_vert',
    'tablet_portrait_sidebar_unit' => '%',
    'tablet_portrait_sidebar_first' => '50',
    'tablet_portrait_sidebar_second' => '50',
    'tablet_portrait_page_unit' => '%',
    'tablet_portrait_page_width' => '100',
    'tablet_portrait_media_query' => 'only screen and (min-width:481px) and (max-width:768px)',
    'smartphone_landscape_layout' => 'one_col_vert',
    'smartphone_landscape_sidebar_unit' => '%',
    'smartphone_landscape_sidebar_first' => '50',
    'smartphone_landscape_sidebar_second' => '50',
    'smartphone_landscape_media_query' => 'only screen and (min-width:321px) and (max-width:480px)',
    'smartphone_landscape_page_width' => '100',
    'smartphone_landscape_page_unit' => '%',
    'smartphone_portrait_media_query' => 'only screen and (max-width:320px)',
    'smartphone_portrait_page_width' => '100',
    'smartphone_portrait_page_unit' => '%',
    'smartphone_portrait_sidebar_first' => '100',
    'smartphone_portrait_sidebar_second' => '100',
    'smartphone_portrait_sidebar_unit' => '%',
    'smartphone_portrait_layout' => 'one_col_stack',
    'bigscreen_two_33_66' => 'two-33-66',
    'bigscreen_two_66_33' => 'two-66-33',
    'bigscreen_two_50' => 'two-50',
    'bigscreen_two_brick' => 'two-brick',
    'bigscreen_four_4x25' => 'four-4x25',
    'bigscreen_three_50_25_25' => 'three-50-25-25',
    'bigscreen_three_25_50_25' => 'three-25-50-25',
    'bigscreen_three_25_25_50' => 'three-25-25-50',
    'bigscreen_three_3x33' => 'three-3x33',
    'bigscreen_five_5x20' => 'five-5x20-2x3-grid',
    'bigscreen_six_6x16' => 'six-6x16-3x2-grid',
    'bigscreen_three_inset_right' => 'three-inset-right',
    'bigscreen_three_inset_left' => 'three-inset-left',
    'tablet_landscape_two_33_66' => 'two-33-66',
    'tablet_landscape_two_66_33' => 'two-66-33',
    'tablet_landscape_two_50' => 'two-50',
    'tablet_landscape_two_brick' => 'two-brick',
    'tablet_landscape_four_4x25' => 'four-4x25',
    'tablet_landscape_three_50_25_25' => 'three-50-25-25',
    'tablet_landscape_three_25_50_25' => 'three-25-50-25',
    'tablet_landscape_three_25_25_50' => 'three-25-25-50',
    'tablet_landscape_three_3x33' => 'three-3x33',
    'tablet_landscape_five_5x20' => 'five-5x20-2x3-grid',
    'tablet_landscape_six_6x16' => 'six-6x16-3x2-grid',
    'tablet_landscape_three_inset_right' => 'three-inset-right',
    'tablet_landscape_three_inset_left' => 'three-inset-left',
    'tablet_portrait_two_33_66' => 'two-33-66',
    'tablet_portrait_two_66_33' => 'two-66-33',
    'tablet_portrait_two_50' => 'two-50',
    'tablet_portrait_two_brick' => 'two-brick',
    'tablet_portrait_four_4x25' => 'four-4x25-2x2-grid',
    'tablet_portrait_three_50_25_25' => 'three-50-25-25-stack-top',
    'tablet_portrait_three_25_50_25' => 'three-25-50-25-stack-top',
    'tablet_portrait_three_25_25_50' => 'three-25-25-50-stack-top',
    'tablet_portrait_three_3x33' => 'three-3x33-stack-top',
    'tablet_portrait_five_5x20' => 'five-5x20-1x2x2-grid',
    'tablet_portrait_six_6x16' => 'six-6x16-2x3-grid',
    'tablet_portrait_three_inset_right' => 'three-inset-right-wrap',
    'tablet_portrait_three_inset_left' => 'three-inset-left-wrap',
    'smartphone_landscape_two_33_66' => 'two-33-66-stack',
    'smartphone_landscape_two_66_33' => 'two-66-33-stack',
    'smartphone_landscape_two_50' => 'two-50-stack',
    'smartphone_landscape_two_brick' => 'two-brick-stack',
    'smartphone_landscape_four_4x25' => 'four-4x25-stack',
    'smartphone_landscape_three_50_25_25' => 'three-50-25-25-stack',
    'smartphone_landscape_three_25_50_25' => 'three-25-50-25-stack',
    'smartphone_landscape_three_25_25_50' => 'three-25-25-50-stack',
    'smartphone_landscape_three_3x33' => 'three-3x33-stack',
    'smartphone_landscape_five_5x20' => 'five-5x20-stack',
    'smartphone_landscape_six_6x16' => 'six-6x16-stack',
    'smartphone_landscape_three_inset_right' => 'three-inset-right-stack',
    'smartphone_landscape_three_inset_left' => 'three-inset-left-stack',
    'enable_custom_media_queries' => 1,
    'global_default_layout_toggle' => 0,
    'global_default_layout' => 'smartphone-portrait',
    'global_files_path' => 'public_files',
    'custom_files_path' => '',
    'disable_responsive_styles' => 0,
    'load_html5js' => 1,
    'load_onmediaqueryjs' => 0,
    'load_ltie8css' => 0,
    'load_respondjs' => 0,
    'load_scalefixjs' => 0,
    'adaptivetheme_meta_viewport' => 'width=device-width, initial-scale=1',
    'adaptivetheme_meta_mobileoptimized' => 'width',
    'adaptivetheme_meta_handheldfriendly' => 'true',
    'adaptivetheme_meta_apple_mobile_web_app_capable' => 'yes',
    'chrome_edge' => 0,
    'clear_type' => 0,
    'expose_regions' => 0,
    'show_window_size' => 0,
    'atcore_version_test' => 0,
    'load_all_panels' => 0,
    'load_all_panels_no_sidebars' => 0,
    'enable_extensions' => 1,
    'enable_font_settings' => 0,
    'enable_heading_settings' => 0,
    'enable_image_settings' => 0,
    'enable_apple_touch_icons' => 0,
    'enable_exclude_css' => 0,
    'enable_custom_css' => 0,
    'enable_context_regions' => 0,
    'enable_float_region_blocks' => 0,
    'enable_markup_overides' => 0,
    'at-settings__active_tab' => 'edit-debug',
    'at__active_tab' => '',
    'at_core' => '7.x-3.x',
    'favicon_mimetype' => 'image/vnd.microsoft.icon',
  );
  $export['theme_at_hot_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'at_hot';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'default_logo' => 0,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
  );
  $export['theme_settings'] = $strongarm;

  return $export;
}
