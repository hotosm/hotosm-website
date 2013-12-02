<?php
/**
 * @file
 * hot_sharing.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hot_sharing_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_update';
  $strongarm->value = 'edit-comment';
  $export['additional_settings__active_tab_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_additional_html';
  $strongarm->value = '';
  $export['addtoany_additional_html'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_additional_html_placement';
  $strongarm->value = 'before';
  $export['addtoany_additional_html_placement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_additional_js';
  $strongarm->value = '';
  $export['addtoany_additional_js'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_buttons_size';
  $strongarm->value = '16';
  $export['addtoany_buttons_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_custom_image';
  $strongarm->value = '';
  $export['addtoany_custom_image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_display_in_nodecont';
  $strongarm->value = 1;
  $export['addtoany_display_in_nodecont'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_display_in_nodelink';
  $strongarm->value = 0;
  $export['addtoany_display_in_nodelink'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_display_in_teasers';
  $strongarm->value = 0;
  $export['addtoany_display_in_teasers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_display_weight';
  $strongarm->value = '40';
  $export['addtoany_display_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_image';
  $strongarm->value = 'share_save_171_16.png|171|16';
  $export['addtoany_image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_image_attributes';
  $strongarm->value = 'alt="Share"';
  $export['addtoany_image_attributes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_link_text';
  $strongarm->value = '';
  $export['addtoany_link_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_nodetypes';
  $strongarm->value = array(
    'project' => 'project',
    'book' => 'book',
    'update' => 'update',
  );
  $export['addtoany_nodetypes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addtoany_no_3p';
  $strongarm->value = 0;
  $export['addtoany_no_3p'] = $strongarm;

  return $export;
}
