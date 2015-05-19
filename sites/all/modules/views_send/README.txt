
Views Send allow mass mailing using Views.
The messages are queued in a spool table and delivered only on cron.
You can control how many messages will be send per cron run.

CONFIGURATION

General settings can be configured at: Site Configuration > Views Send

USAGE

 1. Create a view and add at least one column containing e-mail addresses.
 2. [Optional] Expose Views filters to let the user easily build list of
    recipients using UI.
 3. Add the "Global: Send e-mail" field to your view. This field provides the checkboxes
    that allow the user to select multiple rows.
 4. Save the view, load the page, use exposed filters to build the list, select
    all or some rows and choose "Send e-mail".
 5. Fill the message form to configure the e-mail. Use tokens to personalize
    your e-mail.
 6. Preview and send the message.

DEPENDENCIES & INTEGRATION

 * Views Send depends on Views.
 * The module integrates features from:
  o Mime Mail. When the Mime Mail module is enabled, the user can choose to send
    rich HTML messages and/or use attachments.
  o Tokens. When the Tokens module is enabled, the user can insert context tokens
    into the subject or body of the message. Note that row-based tokens are
    available even if Tokens module is disabled.
  o Rules. When the Rules module is enabled, the user can define actions 
    for when emails are sent and/or placed in the spool.

FOR DEVELOPERS / HOOKS

The module provides two hooks: 
 * hook_views_send_mail_queued($message, $view, $row_id)
   Called just after each message is queued. 
 * hook_views_send_mail_alter(&$message)
   Called just before each message is queued.

SIMILAR MODULES

You may want to try also:

 * Views Mail | http://drupal.org/project/views_mail
   See what's different: http://drupal.org/node/795782
 * Simplenews | http://drupal.org/project/simplenews
   Some pieces of code were inspired by Simplenews module.

HOW CAN YOU GET INVOLVED?

 * Write a review for this module on http://drupalmodules.com/module/views-send
 * Help translate this module at Drupal Localize Server
   http://localize.drupal.org/translate/projects/views_send

MAINTAINERS & SPONSORS

 * Module maintainer
   Hans Fredrik Nordhaug (hansfn) | http://drupal.org/user/40521
 * Module author of original Drupal 6 version
   Claudiu Cristea (claudiu.cristea) | http://drupal.org/user/56348
 * The Drupal 6 version of this module was sponsored by Grafit SRL, 
   now Webikon | http://www.webikon.com
