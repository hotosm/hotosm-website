<?php

/**
 * @file
 * This file holds the functions for the main openlayers Admin settings.
 *
 * @ingroup openlayers
 */

/**
 * Menu callback; displays the openlayers module settings page.
 *
 * @see system_settings_form()
 */
function openlayers_ui_admin_settings() {
  $client_check = variable_get('openlayers_ui_version_check', 'no-check');
  $source_description =
    t('<p>By default the your site will point to a hosted version of the
      OpenLayers library at %ol_api_url.</p>
      <p>For better performance and reliability, you should <a href="!ol_url">download the
      OpenLayers library</a>, and add it to your Drupal installation. For instance,
      you could use a Drupal relative path like: %suggested_path. You can also use a double backslash
      before the domain name (eg. //www.example.com/OpenLayers.js) which
      then respects the use of both HTTPS and HTTP protocols.</p>
      <ul>
        <li>The default suggested, compatible version: <strong>%suggested_api</strong></li>
        <li>The default suggested, compatible hosted URL:  <strong>%ol_api_url</strong></li>
        <li>Your version found from client-side, Javascript check: <strong>%client</strong></li>
      </ul>',
      array(
        '%ol_api_url' => OPENLAYERS_DEFAULT_LIBRARY,
        '%suggested_api' => OPENLAYERS_SUGGESTED_LIBRARY,
        '!ol_url' => 'http://openlayers.org/',
        '%suggested_path' => 'sites/all/libraries/OpenLayers/OpenLayers.js',
        '%client' => ($client_check == 'no-check') ? t('(not checked)') : $client_check,
      )
    );

  // Define Form
  $form['openlayers_source'] = array(
    '#type' => 'textfield',
    '#title' => t('OpenLayers Source'),
    '#description' => $source_description,
    '#default_value' => variable_get('openlayers_source', OPENLAYERS_DEFAULT_LIBRARY),
  );

  $form['openlayers_default_map'] = array(
    '#type' => 'select',
    '#title' => t('OpenLayers Default Map'),
    '#description' => t('This is the default map that will be used
      in cases where one is not defined.  It will also be used as
      the default when creating new maps.'),
    '#options' => openlayers_map_options(),
    '#default_value' => variable_get('openlayers_default_map', 'default'),
  );

  $form['openlayers_ui_preview_map'] = array(
    '#type' => 'checkbox',
    '#title' => t('Preview Map'),
    '#description' => t('Turning this on will show you a map preview when editing it through the !link.',
      array('!link' => l(t('Map Interface'), 'admin/structure/openlayers/maps'))),
    '#default_value' => variable_get('openlayers_ui_preview_map', FALSE),
  );

  // A hidden value to reset client check
  $form['openlayers_ui_version_check'] = array(
    '#type' => 'hidden',
    '#value' => '',
  );

  // Make a system setting form and return
  return system_settings_form($form);
}

/**
 * Callback endpoint for sending in OL version from client JS.
 */
function openlayers_ui_version_check($version = 0) {
  $version = check_plain($version);

  // Set variable with version for hook_requirements
  // and so we dont do this on every page load.
  variable_set('openlayers_ui_version_check', $version);

  // Do a basic check
  if (strpos($version, (string) OPENLAYERS_SUGGESTED_LIBRARY) !== FALSE) {
    $status = 'valid';
    $message = t('Valid library found with a Javascript client check; version: %version', array('%version' => $version));
  }
  else {
    $status = 'invalid';
    $message = t('Could not find a valid library with a Javascript client-side check;  Value found: %version.  Please visit the !settings for more details.',
      array(
        '%version' => $version,
        '!settings' => l(t('OpenLayers settings page'), 'admin/structure/openlayers'),
      )
    );
  }

  // Kind of a hack, but since we are using messages for this, let's clear the
  // messages queue out.
  $messages = drupal_get_messages();

  // We just want to send some markup back.
  drupal_json_output(array(
    'status' => $status,
    'response' => $message,
  ));
}
