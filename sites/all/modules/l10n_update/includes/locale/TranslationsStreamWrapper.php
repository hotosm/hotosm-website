<?php

/**
 * @file
 * Definition of TranslationStreamWrapper.
 */

/**
 * A Drupal interface translations (translations://) stream wrapper class.
 *
 * Supports storing translation files.
 */
class TranslationsStreamWrapper extends DrupalLocalStreamWrapper {
  /**
   * Implements abstract public function getDirectoryPath()
   */
  public function getDirectoryPath() {
    return variable_get('l10n_update_download_store', L10N_UPDATE_DEFAULT_TRANSLATION_PATH);
  }

  /**
   * Overrides getExternalUrl().
   */
  function getExternalUrl() {
    throw new Exception('PO files URL should not be public.');
  }
}
