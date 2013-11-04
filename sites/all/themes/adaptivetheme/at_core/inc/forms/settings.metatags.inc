<?php

/**
 * @file
 * Generate form elments for the Metatags for Mobile settings.
 */

$form['at-settings']['meta'] = array(
  '#type' => 'fieldset',
  '#title' => t('Metatags'),
  '#description' => t('<h3>Mobile Metatags</h3><p>Configure metatags for mobile devices. To omit a metatag leave it empty.'),
);
$form['at-settings']['meta']['mobile'] = array(
  '#type' => 'fieldset',
  '#title' => t('Mobile Metatags'),
);

// Viewport
$form['at-settings']['meta']['mobile']['adaptivetheme_meta_viewport'] = array(
  '#type' => 'textfield',
  '#title' => t('viewport'),
  '#default_value' => check_plain(at_get_setting('adaptivetheme_meta_viewport')),
  '#states' => array(
    'invisible' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);

// MobileOptimized
$form['at-settings']['meta']['mobile']['adaptivetheme_meta_mobileoptimized'] = array(
  '#type' => 'textfield',
  '#title' => t('MobileOptimized'),
  '#default_value' => check_plain(at_get_setting('adaptivetheme_meta_mobileoptimized')),
  '#states' => array(
    'invisible' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);

// HandheldFriendly
$form['at-settings']['meta']['mobile']['adaptivetheme_meta_handheldfriendly'] = array(
  '#type' => 'textfield',
  '#title' => t('HandheldFriendly'),
  '#default_value' => check_plain(at_get_setting('adaptivetheme_meta_handheldfriendly')),
  '#states' => array(
    'invisible' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);

// apple-mobile-web-app-capable
$form['at-settings']['meta']['mobile']['adaptivetheme_meta_apple_mobile_web_app_capable'] = array(
  '#type' => 'textfield',
  '#title' => t('apple-mobile-web-app-capable'),
  '#default_value' => check_plain(at_get_setting('adaptivetheme_meta_apple_mobile_web_app_capable')),
  '#states' => array(
    'invisible' => array('input[name="disable_responsive_styles"]' => array('checked' => TRUE)),
  ),
);

// Chrome Edge
$form['at-settings']['meta']['mobile']['chrome_edge'] = array(
  '#type' => 'checkbox',
  '#title' => t('Enable Chrome Edge support for IE'),
  '#default_value' => at_get_setting('chrome_edge'),
);

// Clear type
$form['at-settings']['meta']['mobile']['clear_type'] = array(
  '#type' => 'checkbox',
  '#title' => t('Enable Cleartype in IE Mobile devices'),
  '#default_value' => at_get_setting('clear_type'),
);
