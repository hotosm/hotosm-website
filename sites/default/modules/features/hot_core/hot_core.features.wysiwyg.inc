<?php
/**
 * @file
 * hot_core.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function hot_core_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: text_editor
  $profiles['text_editor'] = array(
    'format' => 'text_editor',
    'editor' => 'tinymce',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => '',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'justifyleft' => 1,
          'justifyright' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'link' => 1,
          'unlink' => 1,
          'anchor' => 1,
          'image' => 1,
          'styleselect' => 1,
          'blockquote' => 1,
          'code' => 1,
          'removeformat' => 1,
        ),
        'drupal' => array(
          'break' => 1,
        ),
      ),
      'theme_advanced_toolbar_location' => 'top',
      'theme_advanced_toolbar_align' => 'left',
      'theme_advanced_statusbar_location' => 'bottom',
      'theme_advanced_resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 0,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 0,
      'css_setting' => 'theme',
      'css_path' => '',
      'theme_advanced_styles' => '',
      'theme_advanced_blockformats' => 'p,h2,h3,h4,div,blockquote,code',
      'advanced__active_tab' => 'edit-paste',
      'paste_auto_cleanup_on_paste' => 1,
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}
