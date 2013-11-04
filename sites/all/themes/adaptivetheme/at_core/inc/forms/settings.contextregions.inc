<?php

/**
 * @file
 * Generate form elments for the Mobile Regions settings.
 */

// Regions we don't want to include
$unset_mobile_regions = array(
  'dashboard_main',
  'dashboard_sidebar',
  'dashboard_inactive',
  'page_bottom',
  'page_top',
  'menu_bar', // exclude the menu bar, it has bespoke region markup and moving something to this will end in tears.
  'content', // exclude the main content region, we don't want to unset this?
);

// Prepare regions
foreach ($info_array['regions'] as $key => $value) {
  if (in_array($key, $unset_mobile_regions)) {
    unset($key);
  }
  if (isset($key)) {
    $mobile_regions[$key] = $value;
  }
}

// Add a <do-not-move> option to the move regions list
$do_not_move = array('do_not_move' => '<do-not-move>');
$move_regions_list = array_merge($do_not_move, $mobile_regions);
array_reverse($move_regions_list);

// Top level wrapper fieldset
$form['at']['context-regions'] = array(
  '#type' => 'fieldset',
  '#title' => t('Mobile Regions (beta)'),
  '#description' => t('<h3>Mobile Regions and Blocks <sup>(beta)</sup></h3><p>These settings allow you to either <abbr title="Unset means they won\'t print in the output at all, i.e. they are totally nuked">unset</abbr> regions in mobile devices, or move the regions blocks to another region when a mobile device is detected. Device detection is supplied by the Browscap module.</p><p>This feature should be considered beta at this time and has only been tested with the Drupal core block system, please post issues to the <a href="!issue_queue" target="_blank">issue queue</a>.</p><p>Caveats:<p><ol><li>Normal weight settings are lost when blocks are moved.</li><li>If the target region has no blocks by default, Adaptivetheme will generate the region markup. The markup is hard coded and does not account for modifications elsewhere in your theme, such as region template suggestion overrides.</li></ol>', array('!issue_queue' => 'http://drupal.org/project/issues/adaptivetheme')),
  '#weight' => 30,
);
if (!function_exists('browscap_get_browser')) {
  $form['at']['context-regions']['requirements'] = array(
    '#markup' => t('<strong>Required:</strong> To use these settings you must first install the <a href="!browscap_module" target="_blank">Browscap module</a>. New settings will appear after you have enabled Browscap.', array('!browscap_module' => 'http://drupal.org/project/browscap')),
  );
}
elseif (function_exists('browscap_get_browser')) {
  // Build form elements for each region
  foreach ($mobile_regions as $mobile_region_name => $mobile_region_label) {

    $mobile_region_title = check_plain($mobile_region_label);
    $mobile_region_name = check_plain($mobile_region_name);

    $form['at']['context-regions']['region-options-' . $mobile_region_name] = array(
      '#type' => 'fieldset',
      '#title' => t($mobile_region_title),
    );
    $form['at']['context-regions']['region-options-' . $mobile_region_name]['unset_' . $mobile_region_name] = array(
      '#type' => 'checkbox',
      '#title' => t('Unset'),
      '#default_value' => at_get_setting('unset_' . $mobile_region_name),
    );
    $form['at']['context-regions']['region-options-' . $mobile_region_name]['move_' . $mobile_region_name] = array(
      '#type' => 'select',
      '#title' => t('Move blocks:'),
      '#default_value' => at_get_setting('move_' . $mobile_region_name),
      '#options' => $move_regions_list,
      '#states' => array('invisible' => array('input[name=unset_' . $mobile_region_name . ']' => array('checked' => TRUE))),
    );
  }
}
