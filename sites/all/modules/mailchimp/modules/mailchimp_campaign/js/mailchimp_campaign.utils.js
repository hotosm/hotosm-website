/**
 * @file
 * Mailchimp Campaign javascript extras.
 */

(function ($) {

  /**
   * Utility methods for MailChimp campaign management.
   * Some text field manipulation code is adapted from
   * the Tokens module.
   */
  Drupal.behaviors.mailchimp_campaign_utils = {
    attach: function(context, settings) {
      // Keep track of which textfield was last selected/focused.
      $('textarea', context).focus(function() {
        Drupal.settings.mailchimpCampaignFocusedField = this;
        console.log('Got text field focus: ' + $(this).attr('id'));
      });

      /**
       * Add entity token click handler.
       */
      $('.add-entity-token-link', context).unbind('click').bind('click', function() {
        var element_id = $(this).attr('id');
        var section = element_id.replace('-add-entity-token-link', '');

        // Start with import tag field hidden.
        $('#' + section + '-entity-import-tag-field').hide();

        // Get the last selected text field.
        var target_element = Drupal.settings.mailchimpCampaignFocusedField;

        // Get the selected entity ID.
        var entity_id = '';
        var entity_value = $('#' + section + '-entity-import-entity-id').val();
        if ((entity_value) && (entity_value.length > 0)) {
          var entity_parts = entity_value.split(' ');
          var entity_id_string = entity_parts[entity_parts.length - 1];

          entity_id = entity_id_string.replace('[', '').replace(']', '');
        }

        if (entity_id.length == 0) {
          alert(Drupal.t('Select an entity to import before adding the token.'));
          return;
        }

        // Generate token based on user input.
        var entity_type = $('.' + section + '-entity-import-entity-type').val();
        var view_mode = $('#' + section + '-entity-import-entity-view-mode').val();

        var token = '[mailchimp_campaign'
          + '|entity_type=' + entity_type
          + '|entity_id=' + entity_id
          + '|view_mode=' + view_mode
          + ']';

        // Insert token into last selected text field.
        if (target_element) {
          console.log('Inserting token: ' + token);

          Drupal.behaviors.mailchimp_campaign_utils.addTokenToElement(target_element, token);
        }
        else {
          // Missing a selected text field. Insert token into token field,
          // where it can be manually copied by the user.
          $('#' + section + '-entity-import-tag-field').html(token);
          $('#' + section + '-entity-import-tag-field').show();
        }

        // Unset last focused field.
        Drupal.settings.mailchimpCampaignFocusedField = null;
      });

      /**
       * Add merge var click handler.
       */
      $('.add-merge-var', context).unbind('click').bind('click', function() {
        // Get the last selected text field.
        var target_element = Drupal.settings.mailchimpCampaignFocusedField;

        // Get the merge var.
        var element_id = $(this).attr('id');
        var merge_var = element_id.replace('merge-var-', '');
        var token = '*|' + merge_var + '|*';

        // Insert token into last selected text field.
        if (target_element) {
          console.log('Inserting token: ' + token);

          Drupal.behaviors.mailchimp_campaign_utils.addTokenToElement(target_element, token);
        }

        // Unset last focused field.
        Drupal.settings.mailchimpCampaignFocusedField = null;
      });
    },

    /**
     * Inserts a token at the last selected point in a text field element.
     *
     * @param object target_element
     *   The text field element to insert the token into.
     * @param string token
     *   The token to insert.
     */
    addTokenToElement: function(target_element, token) {
      // IE support.
      if (document.selection) {
        target_element.focus();
        sel = document.selection.createRange();
        sel.text = token;
      }

      // MOZILLA/NETSCAPE support.
      else if (target_element.selectionStart || target_element.selectionStart == '0') {
        var startPos = target_element.selectionStart;
        var endPos = target_element.selectionEnd;
        target_element.value = target_element.value.substring(0, startPos)
          + token
          + target_element.value.substring(endPos, target_element.value.length);
      } else {
        target_element.value += token;
      }
    }
  }

})(jQuery);
