View MailChimp campaign activity for any entity with a valid email address.
Activity keys off of an email address and is cached after the initial load.
If a list has webhooks enabled, than the cache is cleared when a new campaign
is sent.

## Installation

1. Enable the MailChimp Activity module and the Entity Module
2. To use MailChimp Activity module, you will need to install and enable the
   Entity API module [http://drupal.org/project/entity]([http://drupal.org/project/entity)

## Usage

1. Define which entity types you want to show campaign activity for at
/admin/config/services/mailchimp/activity.
  * Select a Drupal entity type.
  * Select a bundle.
  * Select the email entity property.
2. Configure permissions for viewing campaign activity.
3. Once setup, a new MailChimp activity local task will appear for any
configured entity.

## Notes

1. The "Import mailchimp activity entity" button on the Activity admin tab will
throw a PHP error due to a bug in Entity API. You can prevent this error by
applying the patch in https://drupal.org/comment/8648215#comment-8648215 to
the entity module.
