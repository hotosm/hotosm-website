Integrates with MailChimp campaigns, enabling creating and sending campaigns,
and viewing statistics on those already sent.

## Creating Campaigns
1. Click Add a Campaign in the overview
2. Fill out the required fields
  * **Title:** An internal name to identify the campaign
  * **Subject:** Message subject
  * **List:** The MailChimp list to use
  * **Segment:** List segment to use (optional, only appears if any exist)
  * **From Email:** Email address for the campaign
  * **From Name:** Name to attach to the 'From Email'
  * **Template:** MailChimp template to use
  * **Content Sections:** Each section (if applicable) of content for the
  campaign
3. Click Save as draft

Once saved as a draft, the new campaign will be available in both Drupal and
MailChimp as a draft until it is sent. After sending, campaigns can no longer
be edited.

## Using Merge Tags
Mailchimp Templates use Merge Tags to load data from Mailchimp Merge Fields into
the emails. In the Content Sections area you will see a list of available Merge
Tags. While typing into any of the content areas, you can click on the Merge Tag
to put that tag in at your cursor.

## Site Content Import
Any entity on your site with a Title can be placed into any of the Content
Sections. Simply select the Entity Type, type in the Title to locate the entity,
and select a configured View Mode to include. The "Add entity token" link will
now embed this content at your cursor in any of the content areas. It will
appear as a long token surrounded by brackets.

If you are using a javascript text editor, instead of typing the token in at the
cursor, instead a text field will appear with the token, and you must copy/paste
the token manually into the editing region.

## Troubleshooting
### Campaigns, lists, or templates have not updated from MailChimp?
  Try clearing the Drupal cache and reloading the page.
### Cannot edit a campaign?
  Check to see if the campaign has already been sent. Sent campaigns cannot be
  edited.
