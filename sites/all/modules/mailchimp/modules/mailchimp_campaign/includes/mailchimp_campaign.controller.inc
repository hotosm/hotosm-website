<?php

/**
 * @file
 * MailChimpCampaign controller class.
 */

class MailChimpCampaignController extends EntityAPIController {

  /**
   * Implement in order to attach MailChimp data to campaign entities.
   */
  protected function attachLoad(&$campaigns, $revision_id = FALSE) {
    $ids = array();
    if (!empty($campaigns)) {
      foreach ($campaigns as $campaign) {
        $ids[] = $campaign->mc_campaign_id;
      }
    }
    $mc_campaigns = mailchimp_campaign_get_campaigns($ids);

    foreach ($campaigns as $mc_campaign_id => $campaign) {
      $campaign->mc_data = $mc_campaigns[$mc_campaign_id];

      // Lists are cached separately, but we want to load them here.
      if (isset($campaign->mc_data['list_id']) && $campaign->mc_data['list_id']) {
        $campaign->list = mailchimp_get_list($campaign->mc_data['list_id']);
      }

      if (isset($campaign->mc_data['template_id']) && $campaign->mc_data['template_id']) {
        $campaign->mc_template = mailchimp_campaign_get_template($campaign->mc_data['template_id']);
      }
    }

    parent::attachLoad($campaigns, $revision_id);
  }

  /**
   * Implement to clear MailChimp campaign data caches.
   *
   * @param array $ids
   *   Optional array of campaign IDs to clear cache for.
   */
  public function resetCache(array $ids = NULL) {
    parent::resetCache($ids);
    if ($cached_campaigns = cache_get('campaigns', 'cache_mailchimp')) {
      // Reset granular campaigns.
      if (isset($ids)) {
        foreach ($cached_campaigns->data as $id => $cached_campaign) {
          if (in_array($id, $ids)) {
            unset($cached_campaigns->data[$id]);
          }
        }
      }

      $cache_data = (isset($cached_campaigns)) ? $cached_campaigns->data : NULL;

      cache_set('campaigns', $cache_data, 'cache_mailchimp');
    }
  }

  /**
   * Overrides EntityAPIController::buildQuery().
   *
   * Implement to order by created date since our IDs are not numeric.
   */
  protected function buildQuery($ids, $conditions = array(), $revision_id = FALSE) {
    $query = parent::buildQuery($ids, $conditions, $revision_id);
    $query->orderBy('created', 'DESC');
    return $query;
  }

}
