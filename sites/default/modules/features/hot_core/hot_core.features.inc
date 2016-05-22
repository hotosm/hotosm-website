<?php
/**
 * @file
 * hot_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hot_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "openlayers" && $api == "openlayers_layers") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hot_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function hot_core_image_default_styles() {
  $styles = array();

  // Exported image style: banner.
  $styles['banner'] = array(
    'label' => 'Banner',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1024,
          'height' => 450,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: big.
  $styles['big'] = array(
    'label' => 'Big',
    'effects' => array(
      11 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1024,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: medium_square.
  $styles['medium_square'] = array(
    'label' => 'Medium Square',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: normal.
  $styles['normal'] = array(
    'label' => 'Normal',
    'effects' => array(
      10 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 450,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: small_square.
  $styles['small_square'] = array(
    'label' => 'Small Square',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_mailchimp_signup().
 */
function hot_core_default_mailchimp_signup() {
  $items = array();
  $items['hot_newsletter'] = entity_import('mailchimp_signup', '{
    "name" : "hot_newsletter",
    "mc_lists" : { "6cd8f1ed72" : "6cd8f1ed72" },
    "mode" : "1",
    "title" : "Subscribe to the HOT newsletter.",
    "settings" : {
      "path" : "",
      "submit_button" : "Sign up",
      "confirmation_message" : "You have been successfully subscribed to the HOT newsletter!",
      "destination" : "\\/",
      "mergefields" : {
        "EMAIL" : {
          "name" : "Email Address",
          "req" : true,
          "field_type" : "email",
          "public" : true,
          "show" : true,
          "order" : "1",
          "default" : null,
          "helptext" : null,
          "size" : "25",
          "tag" : "EMAIL",
          "id" : 0
        },
        "FNAME" : 0,
        "LNAME" : 0
      },
      "description" : "",
      "doublein" : 0,
      "send_welcome" : 1,
      "include_interest_groups" : 0
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function hot_core_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Static page'),
      'base' => 'node_content',
      'description' => t('A <em>static page</em> is a page of content, organized into a collection of related entries collectively known as a <em>book</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
