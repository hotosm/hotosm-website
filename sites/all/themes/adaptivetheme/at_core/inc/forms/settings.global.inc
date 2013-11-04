<?php

/**
 * @file
 * Generate form elments for the Global CSS settings.
 *
 * TODO: review documentation and provide links to help pages.
 */

// Set variable for mode, we want to show a message based on this
$mode = variable_get('preprocess_css', '') == 1 ? TRUE : FALSE;
$performance_settings_path = url('admin/config/development/performance');
$file_settings_path = url('admin/config/media/file-system');

// Global Settings
$form['at-settings']['global-settings'] = array(
  '#type' => 'fieldset',
  '#title' => t('CSS'),
  '#description' => t('<h3>CSS Global Settings</h3><p>These settings are primarly set during development - do not change these unless you are actively developing or modifying your theme. If you need to globally unset core CSS or other CSS files use the <em>Unset CSS Files</em> extension.</p>'),
);

// Set message depending on the mode
if ($mode == TRUE) {
  $mode_message = t('<p><a href="!settings_path" target="_blank">CSS aggregation</a> is ON. Changes to your themes responsive CSS files will not show until you <strong>re-save the theme settings</strong> (click "Save configuration" at the bottom of this form).</p><div class="description"><p>This is required to re-write the production version of the responsive styles and is a performance optimization in Adaptivetheme, which saves your site at least 4 HTTP requests.</p></div>', array('!settings_path' => $performance_settings_path));
}
elseif ($mode == FALSE) {
  $mode_message = t('<p><a href="!settings_path" target="_blank">CSS aggregation</a> is OFF. Changes to your themes responsive CSS files will show automatically.</p><p><div class="description"><p>Note: when CSS aggregation is ON you need to re-save the theme settings if you make any changes to your themes responsive stylesheets. This is required to re-write the production version of the responsive styles and is a performance optimization in Adaptivetheme, which saves your site at least 4 HTTP requests.</p></div>', array('!settings_path' => $performance_settings_path));
}

// Mode
$form['at-settings']['global-settings']['mode'] = array(
  '#type' => 'fieldset',
  '#title' => t('CSS Mode'),
  '#description' => t('<h3>Mode</h3>') . $mode_message,
  '#states' => array(
    'invisible' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);

// Custom media queries
$form['at-settings']['global-settings']['custom-mediaqueries'] = array(
  '#type' => 'fieldset',
  '#title' => t('Custom Media Queries'),
  '#description' => t('<h3>Custom Media Queries</h3>'),
  '#states' => array(
    'invisible' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);
$form['at-settings']['global-settings']['custom-mediaqueries']['enable_custom_media_queries'] = array(
  '#type' => 'checkbox',
  '#title'  => t('Enable the responsive.custom.css file'),
  '#description' => t('Use this file if you need to use custom media queries, such as <a href="!zomigi" target="_blank">overlapped media queries</a>. This file is located here: <code>themeName/css/responsive.custom.css</code>. Adaptivetheme will load this file automagically when this setting enabled.', array('!zomigi' => 'http://zomigi.com/blog/essential-considerations-for-crafting-quality-media-queries/#mq-overlap-stack')),
  '#default_value' => at_get_setting('enable_custom_media_queries'),
);

// Set default layout
$form['at-settings']['global-settings']['default-layout'] = array(
  '#type' => 'fieldset',
  '#title' => t('Mobile first or Mobile last'),
  '#description' => t('<h3>Mobile first or Desktop first</h3>'),
  '#states' => array(
    'invisible' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);
$form['at-settings']['global-settings']['default-layout']['global_default_layout_toggle'] = array(
  '#type' => 'checkbox',
  '#title' => t('Change default layout method <small>(checking this will expose new settings)</small>'),
  '#description' => t('<strong>Use with caution!</strong> If you are using a pre-styled sub-theme such as Pixture Reloaded, Sky, Corolla, AT Commerce or any of the commerical sub-themes you should NOT change this!'),
  '#default_value' => at_get_setting('global_default_layout_toggle'),
);
$form['at-settings']['global-settings']['default-layout']['toggle'] = array(
  '#type' => 'fieldset',
  '#title' => t('Change default layout method'),
  '#states' => array(
    'visible' => array('input[name="global_default_layout_toggle"]' => array('checked' => TRUE)),
  ),
);
$form['at-settings']['global-settings']['default-layout']['toggle']['global_default_layout'] = array(
  '#type' => 'radios',
  '#description' => t('<p>Adaptivetheme supports both mobile first and desktop first design approaches. Please review the <a href="!docs_link" target="_blank">online documentation</a>.</p><p>This setting fundementally alters what CSS is loaded and how it is loaded. At the most basic level if you select Mobile first the Smartphone portrait layout will load as the default, if you select Desktop first the Standard layout will load as the default. Many other changes take place regarding loading of CSS for Internet Explorer, Responsive Gpanels and Panels as well.</p> ', array('!docs_link' => 'http://adaptivethemes.com/documentation/mobile-first-design-with-adaptivetheme')),
  '#default_value' => at_get_setting('global_default_layout'),
  '#options' => array(
    'smartphone-portrait' => t('Mobile first'),
    'standard-layout' => t('Desktop first'),
  ),
);

// Path to Generated files
$public_files = variable_get('file_public_path', conf_path() . '/files') . '/adaptivetheme/' . $theme_name . '_files/';
$theme_directory = drupal_get_path('theme', $theme_name) . '/generated_files/';
$form['at-settings']['global-settings']['files-path'] = array(
  '#type' => 'fieldset',
  '#title' => t('Path to Generated Files'),
  '#description' => t('<h3>Path to Generated Files</h3>'),
);
$form['at-settings']['global-settings']['files-path']['global_files_path'] = array(
  '#type' => 'select',
  '#title' => t('By default the generated files are saved in <a href="!file_settings_path" target="_blank">public files</a>. You can change this to your theme directory or a custom directory. These files include all the generated CSS files, the info file backup and color scheme backups if you are using the Color module. For more information see the docs on the <a href="!file_generation_system" target="_blank">file generation system</a>.', array('!file_settings_path' => $file_settings_path, '!file_generation_system' => 'http://adaptivethemes.com/documentation/file-generation-system')),
  '#default_value' => at_get_setting('global_files_path'),
  '#options' => array(
    'public_files' => t('Public files'),
    'theme_directory' => t('Theme directory'),
    'custom_path' => t('Custom path'),
  ),
);
// Message for public files
$form['at-settings']['global-settings']['files-path']['public_files_path'] = array(
  '#type' => 'fieldset',
  '#states' => array(
    'visible' => array('select[name="global_files_path"]' => array('value' => 'public_files')),
  ),
);
$form['at-settings']['global-settings']['files-path']['public_files_path']['message'] = array(
  '#markup' => t('<div class="description">Files will be saved to: <code>@public_files</code></div>', array('@public_files' => $public_files)),
);
// message for theme dir
$form['at-settings']['global-settings']['files-path']['theme_directory_files_path'] = array(
  '#type' => 'fieldset',
  '#states' => array(
    'visible' => array('select[name="global_files_path"]' => array('value' => 'theme_directory')),
  ),
);
$form['at-settings']['global-settings']['files-path']['theme_directory_files_path']['message'] = array(
  '#markup' => t('<div class="description">Files will be saved to: <code>@theme_directory</code></div>', array('@theme_directory' => $theme_directory)),
);
// Text field for custom path
$form['at-settings']['global-settings']['files-path']['custom_files_path'] = array(
  '#type' => 'textfield',
  '#title' => t('Enter the custom path:'),
  '#default_value' => at_get_setting('custom_files_path'),
  '#description' => t('This directory must exist and be writable by Drupal. This directory must be relative to the Drupal installation directory and be accessible over the web. Do not try to use something like <code>../css</code>, it will fail. Use someting like <code>sites/default/css</code>.'),
  '#states' => array(
    'visible' => array('select[name="global_files_path"]' => array('value' => 'custom_path')),
  ),
);

// Disable responsive layout
$form['at-settings']['global-settings']['disable-rs'] = array(
  '#type' => 'fieldset',
  '#title' => t('Disable Responsive CSS'),
  '#description' => t('<h3>Disable Responsive CSS</h3>'),
);
$form['at-settings']['global-settings']['disable-rs']['disable_responsive_styles'] = array(
  '#type' => 'checkbox',
  '#title' => t('Disable responsive layout and styles'),
  '#description' => t('By checking this setting the site will use only the Standard layout and the global styles. You can turn this back on at any time.'),
  '#default_value' => at_get_setting('disable_responsive_styles'),
);
