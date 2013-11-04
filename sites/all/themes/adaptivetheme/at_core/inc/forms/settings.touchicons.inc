<?php

/**
 * @file
 * Generate form elments for the Apple touch icons settings.
 */

$form['at']['ati'] = array(
  '#type' => 'fieldset',
  '#title' => t('Touch Icons'),
  '#description' => t('<h3>Touch Icons</h3><p>Different devices can support different sized touch icons:</p><ul><li>57x57 - non-retina iPhone, iPod Touch, Nokia and Android 2.1+ devices</li><li>72x72 - first gen iPad</li><li>114x114 - iPhone 4 with high-res retina display</li></ul><p>Enter the path to each touch icon. Paths must be relative to your theme folder.</p>'),
  '#weight' => 10,
);
$form['at']['ati']['icon-paths'] = array(
  '#type' => 'fieldset',
  '#title' => t('Touch Icons'),
);

// Low
$form['at']['ati']['icon-paths']['apple_touch_icon_path_l'] = array(
  '#type' => 'textfield',
  '#title' => t('57x57'),
  '#description' => t('If you only enter a path for this size it will be used by all devices.'),
  '#field_prefix' => $theme_name . '/',
  '#default_value' => check_plain(at_get_setting('apple_touch_icon_path_l')),
  '#states' => array(
    'required' => array('input[name="enable_apple_touch_icons"]' => array('checked' => TRUE)),
  ),
);

// Medium
$form['at']['ati']['icon-paths']['apple_touch_icon_path_m'] = array(
  '#type' => 'textfield',
  '#title' => t('72x72'),
  '#description' => t('Apple touch icon for old iPads.'),
  '#field_prefix' => $theme_name . '/',
  '#default_value' => check_plain(at_get_setting('apple_touch_icon_path_m')),
);

// High
$form['at']['ati']['icon-paths']['apple_touch_icon_path_h'] = array(
  '#type' => 'textfield',
  '#title' => t('114x114'),
  '#description' => t('Apple touch icon for iPhone 4 with high-res retina display.'),
  '#field_prefix' => $theme_name . '/',
  '#default_value' => check_plain(at_get_setting('apple_touch_icon_path_h')),
);
