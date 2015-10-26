<?php

/**
 * @file
 * MailChimpCampaign entity class.
 */

class MailChimpCampaign extends Entity {

  public $mc_campaign_id, $template, $created, $updated, $mc_data, $list, $mc_template;

  /**
   * Overrides parent::__construct().
   */
  public function __construct(array $values = array(), $entity_type = 'mailchimp_campaign') {
    parent::__construct($values, $entity_type);
  }

  /**
   * Assemble html representation of the Campaign content.
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {
    $build = parent::buildContent($view_mode, $langcode);

    // Prepare rendered content:
    $content = mailchimp_campaign_render_template($this->template);
    $rendered = '';
    foreach ($content as $key => $section) {
      $rendered .= "<h3>$key</h3>" . $section;
    }

    // Get the template name:
    $mc_template = mailchimp_campaign_get_template($this->mc_data['template_id']);
    $mc_template_name = isset($mc_template) ? $mc_template['name'] : '';

    $list_segment_name = 'N/A';

    $list_segments = mailchimp_campaign_get_list_segments($this->list['id'], 'saved');
    if (isset($this->mc_data['saved_segment']['id'])) {
      foreach ($list_segments as $list_segment) {
        if ($list_segment['id'] == $this->mc_data['saved_segment']['id']) {
          $list_segment_name = $list_segment['name'];
        }
      }
    }

    $fields = array(
      'subject' => array(
        'label' => t('Subject'),
        'value' => $this->mc_data['subject'],
      ),
      'list' => array(
        'label' => t('MailChimp List'),
        'value' => l($this->list['name'], 'https://admin.mailchimp.com/lists/dashboard/overview?id=' . $this->list['web_id'], array(
          'attributes' => array('target' => '_blank'),
        )),
      ),
      'list_segment' => array(
        'label' => t('List Segment'),
        'value' => $list_segment_name,
      ),
      'from_email' => array(
        'label' => t('From Email'),
        'value' => $this->mc_data['from_email'],
      ),
      'from_name' => array(
        'label' => t('From Name'),
        'value' => $this->mc_data['from_name'],
      ),
      'template' => array(
        'label' => t('Template'),
        'value' => $mc_template_name,
      ),
      'type' => array(
        'label' => t('List type'),
        'value' => $this->mc_data['type'],
      ),
      'status' => array(
        'label' => t('Status'),
        'value' => $this->mc_data['status'],
      ),
      'emails_sent' => array(
        'label' => t('Emails sent'),
        'value' => $this->mc_data['emails_sent'],
      ),
      'send_time' => array(
        'label' => t('Send time'),
        'value' => $this->mc_data['send_time'],
      ),
      'content' => array(
        'label' => t('Rendered template HTML (!archive)',
          array(
            '!archive' => l(t('View MailChimp archive'), $this->mc_data['archive_url'], array(
              'attributes' => array('target' => '_blank'),
            )),
          )),
        'value' => $rendered,
      ),
    );

    foreach ($fields as $key => $field) {
      $build[$key] = array(
        '#prefix' => "<div class=\"field campaign-{$key}\"><div class=\"field-label\">{$field['label']}</div>",
        '#markup' => $field['value'],
        '#suffix' => '</div>',
      );
    }

    return $build;
  }

  /**
   * Provide a label based on the campaign title.
   */
  public function label() {
    return $this->mc_data['title'];
  }

}
