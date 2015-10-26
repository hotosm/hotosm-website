<?php

/**
 * @file
 * Wrapper class around the Mailchimp API.
 */

/**
 * Class DrupalMailchimp
 *
 * Extend the MailChimp class to add some Drupalisms.
 */
class DrupalMailchimp extends Mailchimp {

  protected $timeout;
  protected $userAgent = 'MailChimp-PHP/2.0.6';

  /**
   * Override __construct().
   *
   * The parent constructor sets curl settings that we need to avoid. Much of
   * code is duplicated from the parent.
   */
  public function __construct($apikey = NULL, $opts = array()) {
    if (!$apikey) {
      $apikey = getenv('MAILCHIMP_APIKEY');
    }
    if (!$apikey) {
      $apikey = $this->readConfigs();
    }
    if (!$apikey) {
      throw new Mailchimp_Error(t('You must provide a MailChimp API key'));
    }
    $this->apikey = $apikey;
    $dc = "us1";
    if (strstr($this->apikey, "-")) {
      $key_parts = explode("-", $this->apikey, 2);
      $dc = (isset($key_parts[1])) ? $key_parts[1] : 'us1';
    }
    $this->root = str_replace('https://api', 'https://' . $dc . '.api', $this->root);
    $this->root = rtrim($this->root, '/') . '/';

    $this->timeout = (isset($opts['timeout']) && is_int($opts['timeout'])) ? $opts['timeout'] : 600;

    $this->folders = new Mailchimp_Folders($this);
    $this->templates = new Mailchimp_Templates($this);
    $this->users = new Mailchimp_Users($this);
    $this->helper = new Mailchimp_Helper($this);
    $this->mobile = new Mailchimp_Mobile($this);
    $this->ecomm = new Mailchimp_Ecomm($this);
    $this->neapolitan = new Mailchimp_Neapolitan($this);
    $this->lists = new Mailchimp_Lists($this);
    $this->campaigns = new Mailchimp_Campaigns($this);
    $this->vip = new Mailchimp_Vip($this);
    $this->reports = new Mailchimp_Reports($this);
    $this->gallery = new Mailchimp_Gallery($this);

  }

  /**
   * Override the parent to eliminate the call to curl_close().
   */
  public function __destruct() {}

  /**
   * Override MCAPI::callServer() to leverage Drupal's core HTTP handling.
   */
  public function call($url, $params) {
    $params['apikey'] = $this->apikey;
    $params = drupal_json_encode($params);

    $response = drupal_http_request(
      $this->root . $url . '.json',
      array(
        'method' => 'POST',
        'data' => $params,
        'headers' => array(
          'Content-type' => 'application/json',
          'Accept-Language' => language_default()->language,
          'User-Agent' => $this->userAgent,
        ),
        'timeout' => $this->timeout,
      )
    );

    $result = drupal_json_decode($response->data);

    if (!empty($response->error)) {
      throw new Mailchimp_HttpError(t("MailChimp API call to %url failed: @msg: @error", array('%url' => $url, '@msg' => $response->error, '@error' => $result['error'])));
    }

    if (floor($response->code / 100) >= 4) {
      throw $this->castError($result);
    }

    return $result;
  }

}
