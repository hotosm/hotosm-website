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
  if ($module == "page_manager" && $api == "pages_default") {
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
    'weight' => -9,
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
  // Exported flag: "Executive director".
  $flags['executive_director'] = array(
    'entity_type' => 'user',
    'title' => 'Executive director',
    'global' => 1,
    'types' => array(),
    'flag_short' => 'Executive director',
    'flag_long' => 'This user is the HOT executive director',
    'flag_message' => 'executive director',
    'unflag_short' => 'Unflag as executive director',
    'unflag_long' => 'This user is not the HOT executive director',
    'unflag_message' => 'Not the HOT executive director',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'show_on_profile' => 1,
    'access_uid' => '',
    'module' => 'hot_people',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
    'status' => FALSE,
  );
  // Exported flag: "Staff or contractor".
  $flags['staff'] = array(
    'entity_type' => 'user',
    'title' => 'Staff or contractor',
    'global' => 1,
    'types' => array(),
    'flag_short' => 'Flag as staff or contractor',
    'flag_long' => 'This user is a HOT staff member or contractor',
    'flag_message' => 'staff or contaractor',
    'unflag_short' => 'Unflag as staff or contractor',
    'unflag_long' => 'This user is not a staff member',
    'unflag_message' => 'Not a staff member',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -8,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'show_on_profile' => 0,
    'access_uid' => '',
    'api_version' => 3,
    'module' => 'hot_people',
    'locked' => array(
      0 => 'name',
    ),
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
    'weight' => -10,
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
    'label' => 'avatar',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 30,
          'height' => 30,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: small_square.
  $styles['small_square'] = array(
    'label' => 'Small square',
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
