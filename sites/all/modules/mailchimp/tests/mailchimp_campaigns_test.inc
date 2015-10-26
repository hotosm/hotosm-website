<?php
/**
* @file
* A virtual MailChimp Campaigns API implementation for use in testing.
*/

define('MAILCHIMP_TEST_CAMPAIGN_A', 'mailchimp_test_campaign_a');
define('MAILCHIMP_TEST_CAMPAIGN_B', 'mailchimp_test_campaign_b');
define('MAILCHIMP_TEST_CAMPAIGN_C', 'mailchimp_test_campaign_c');

class MailChimp_CampaignsTest {
  public function __construct(MailChimpTest $master) {
  }

  /**
   * @see Mailchimp_Campaigns::getList()
   */
  public function getList($filters=array(), $start=0, $limit=25, $sort_field='create_time', $sort_dir='DESC') {
    $campaigns = $this->loadCampaigns();

    $response = array(
      'total' => 0,
      'data' => array(),
    );

    foreach ($campaigns as $campaign) {
      foreach ($filters as $filter => $value) {
        if ($filter == 'campaign_id') {
          $filter = 'id';
        }
        if ($campaign[$filter] != $value) {
          continue;
        }
      }
      $response['data'][] = $campaign;
      $response['total']++;
    }

    return $response;
  }

  /**
   * Loads campaign values, initializing if necessary.
   *
   * @return array
   *   Stored campaigns.
   */
  protected function loadCampaigns() {
    $campaign_data = variable_get('mailchimp_test_campaign_data', $this->defaultCampaigns());

    return $campaign_data;
  }

  /**
   * Creates initial campaign values.
   *
   * @return array
   *   Basic campaigns.
   */
  protected function defaultCampaigns() {
    $campaigns = array(
      MAILCHIMP_TEST_CAMPAIGN_A => array(
        'id' => MAILCHIMP_TEST_CAMPAIGN_A,
        'name' => 'Test Campaign A',
        'list_id' => MAILCHIMP_LISTS_TEST_LIST_A,
        'status' => 'sent',
        'type' => 'regular',
      ),
      MAILCHIMP_TEST_CAMPAIGN_B => array(
        'id' => MAILCHIMP_TEST_CAMPAIGN_B,
        'name' => 'Test Campaign B',
        'list_id' => MAILCHIMP_LISTS_TEST_LIST_B,
        'status' => 'save',
        'type' => 'plaintext',
      ),
      MAILCHIMP_TEST_CAMPAIGN_C => array(
        'id' => MAILCHIMP_TEST_CAMPAIGN_C,
        'name' => 'Test Campaign C',
        'list_id' => MAILCHIMP_LISTS_TEST_LIST_C,
        'status' => 'paused',
        'type' => 'absplit',
      ),
    );
    return $campaigns;
  }

  /**
   * Saves campaign changes.
   */
  protected function writeCampaigns($campaigns) {
    variable_set('mailchimp_test_campaign_data', $campaigns);
  }
}
