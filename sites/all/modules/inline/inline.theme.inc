<?php

/**
 * @file
 * Output theming functions for Inline.
 */

/**
 * Return HTML for a link to a file.
 */
function theme_inline_as_link($variables) {
  $file = $variables['file'];

  // Prepare link text with title or filename.
  $linktext = isset($file->title) ? $file->title : $file->filename;

  return l($linktext, file_create_url($file->uri), array('attributes' => array('title' => t('Download: @name (@size)', array('@name' => $file->filename, '@size' => format_size($file->filesize))))));
}

/**
 * Return HTML for an image.
 */
function theme_inline_img($variables) {
  $file = $variables['file'];
  $viewmode = $variables['viewmode'];
  // Prepare link text with inline title, file description or filename.
  $title = (!empty($file->title) ? $file->title : (!empty($file->description) ? $file->description : $file->filename));
  $inline_preset = $viewmode == 'summary' ? 'inline_teaser_preset' : 'inline_full_preset';

  if (variable_get($inline_preset, '') != '') {
    $image = theme('image_style', array('style_name' => variable_get($inline_preset), 'path' => $file->uri, 'alt' => $file->alt, 'title' => $file->title, 'attributes' => array('class' => 'inline')));
  }
  else {
    $image = theme('image', array('path' => $file->uri, 'alt' => $title, 'title' => $title, 'attributes' => array('class' => 'inline')));
  }

  if (variable_get('inline_link_img', '1')) {
    $attributes = array(
      'class' => 'inline-image-link',
      'title' => t("View") . ': ' . $title,
    );
    $html = l($image, file_create_url($file->uri), array('attributes' => $attributes, 'html' => TRUE));
  }
  else {
    $html = $image;
  }

  return $html;
}
