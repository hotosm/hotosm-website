<?php
/**
 * @file
 * hot_people.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hot_people_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hot_people_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function hot_people_flag_default_flags() {
  $flags = array();
  // Exported flag: "Board member".
  $flags['board_member'] = array(
    'entity_type' => 'user',
    'title' => 'Board member',
    'global' => 1,
    'types' => array(),
    'flag_short' => 'Flag as board member',
    'flag_long' => 'This user is a HOT board member',
    'flag_message' => 'board member',
    'unflag_short' => 'Unflag as board member',
    'unflag_long' => 'This user is not a board member',
    'unflag_message' => 'Not a board member',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 0,
      'list' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => '',
    'module' => 'hot_people',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Voting member".
  $flags['voting_member'] = array(
    'entity_type' => 'user',
    'title' => 'Voting member',
    'global' => 1,
    'types' => array(),
    'flag_short' => 'Flag as voting member',
    'flag_long' => 'This user is a HOT voting member.',
    'flag_message' => 'Voting member',
    'unflag_short' => 'Unflag as voting membere',
    'unflag_long' => 'This user is not a voting member any more.',
    'unflag_message' => 'Not a voting member',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 0,
      'list' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => '',
    'module' => 'hot_people',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function hot_people_image_default_styles() {
  $styles = array();

  // Exported image style: avatar.
  $styles['avatar'] = array(
    'name' => 'avatar',
    'label' => 'avatar',
    'effects' => array(
      9 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 30,
          'height' => 30,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
