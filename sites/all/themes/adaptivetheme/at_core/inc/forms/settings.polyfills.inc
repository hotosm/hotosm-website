<?php

/**
 * @file
 * Generate form elments for the Polyfills settings.
 *
 * TODO: review documentation and provide links to help pages.
 */

$form['at-settings']['polyfills'] = array(
  '#type' => 'fieldset',
  '#title' => t('Polyfills'),
  '#description' => t('<h3>Polyfills</h3><p>Here you can enable commonly used Polyfills supplied with the core theme. Adaptivetheme also supports loading <a href="!docspage" target="_blank">scripts and CSS for Internet Explorer</a> using your sub-themes info file.', array('!docspage' => 'http://adaptivethemes.com/documentation/ie-styles-and-scripts')),
);

$form['at-settings']['polyfills']['fills'] = array(
  '#type' => 'fieldset',
  '#title' => t('Polyfills'),
);

// HTML5 shiv
$form['at-settings']['polyfills']['fills']['load_html5js'] = array(
  '#type' => 'checkbox',
  '#title' => t('HTML5 support in IE'),
  '#description' => t('By checking this setting the site will load the <a href="!html5shiv_link" target="_blank">html5shiv</a>. Turning this off will be bad news for IE6-8.', array('!html5shiv_link' => '//github.com/aFarkas/html5shiv')),
  '#default_value' => at_get_setting('load_html5js'),
);

// OnMediaQuery.js
$script_filepath = '/' . $theme_name . '/scripts/media_queries.js';
$form['at-settings']['polyfills']['fills']['load_onmediaqueryjs'] = array(
  '#type' => 'checkbox',
  '#title' => t('Responsive JavaScript <sup>beta</sup>'),
  '#description' => t('Load the <a href="!onmediaquery_link" target="_blank">JS Media Queries</a> plugin to enable responsive JavaScript. See <code>@script_filepath</code> for instructions on how to use. This is an alternative to using matchMedia and hard coding breakpoints in JavaScript. This is bleeding edge and must be considered beta, but its wickedly cool, and useful.', array('!onmediaquery_link' => '//github.com/JoshBarr/js-media-queries', '@script_filepath' => $script_filepath)),
  '#default_value' => at_get_setting('load_onmediaqueryjs'),
);

// Rounding error fix (CSS)
$form['at-settings']['polyfills']['fills']['load_ltie8css'] = array(
  '#type' => 'checkbox',
  '#title' => t('Fix CSS rounding errors in IE6-7'),
  '#description' => t('Load a stylesheet that fixes percentage rounding errors in IE6-7. You need this if you are using Gpanels or Panels layouts.'),
  '#default_value' => at_get_setting('load_ltie8css'),
);

// Respond.js
$form['at-settings']['polyfills']['fills']['load_respondjs'] = array(
  '#type' => 'checkbox',
  '#title' => t('Media query support for IE6-8'),
  '#description' => t('By checking this setting IE6, 7 and 8 will rely on <a href="!respondjs_link" target="_blank">respond.js</a> to set the layout.', array('!respondjs_link' => '//github.com/scottjehl/Respond')),
  '#default_value' => at_get_setting('load_respondjs'),
  '#states' => array(
    'invisible' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);

// Scalefix
$form['at-settings']['polyfills']['fills']['load_scalefixjs'] = array(
  '#type' => 'checkbox',
  '#title' => t('Scalefix for iOS'),
  '#description' => t('Fixes the iOS Orientationchange zoom bug.'),
  '#default_value' => at_get_setting('load_scalefixjs'),
  '#states' => array(
    'invisible' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);
