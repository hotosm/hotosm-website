TABLE OF CONTENTS:
 * Introduction
 * Features
 * Installation
 * Configuration and setup
 * More information
 * Changes from Drupal 6 to Drupal 7
 * Troubleshooting


INTRODUCTION:
The Mass Contact module started out as a modified version of the core Contact
module. It allows anyone with permission to send a message to users, defined
by the role or group of roles (or even to all registered users) they belong
to.


FEATURES:
Here are a list of some of the features this module has:
 * You can send a message to one or more groups (referred to as categories) of
   users, which are specified by role.
 * Large recipient lists may be broken up into smaller chunks.
 * The smaller chunks may be sent at later intervals, using cron.
 * The site administrator can control how many messages are allowed to be sent
   by a single person in an hour.
 * The message may be sent such that the recipients' email addresses are
   hidden from each other, via the BCC (blind carbon copy) field.
 * The message may be sent as plain text or HTML, even specifying the input
   format filter to use.
 * The message may include one or more binary file attachments.
 * The site administrator may specify different texts to be placed at the
   beginning and/or the end of every message that is sent out.
 * A copy of the message may be saved as a node.
 * Users may opt-out, by category, of receiving mass mailings on their account
   settings page.


INSTALLATION:
This module is installed in a standard way. Generic instructions for how to do
that can be found here: http://drupal.org/getting-started/install-contrib


CONFIGURATION AND SETUP:
While an attempt has been made at setting sensible defaults, the configuration
should be reviewed and tweaked before sending any messages. It is located at
admin/config/system/mass_contact/settings.

Before sending any mass email messages, at least one category needs to be
created, which can be done at the same location where the administrative
settings are.

By default, the email messages are sent as plain text. If the MIME Mail module
is enabled, the email messages may be sent as HTML and may include one or more
binary file attachments (if permitted by admin).


UPGRADING FROM 6.x:
When upgradign from the Drupal 6 version, the path for the attachment directory
should be verified, and most likely changed. Check the Attachment location
setting on the Message body settings page, here:
admin/config/system/mass_contact/settings/body. If it is the default of
site/default/files/mass_contact_attachments, change it to just
mass_contact_attachments. In other words, remove the site/default/files/ part of
the path, since Drupal handles that part now.


MORE INFORMATION:
This module works by sending a single email to your mail server with the
recipients' email addresses in either the 'To:' or 'Bcc:' field. The mail
server is then responsible for parsing out the recipients' addresses and
forwarding the message along to everyone.

When using the Bcc option, recipients are not potentially left open to abuse
due to their email addresses being visible to all other recipients.

Here is some scaling information:
 * This module retrieves user ids and emails in a scaled way: no
 * This module sends email in a scaled way: yes, within server limits
 * This module keeps connections up while the long process continues: no

Here are all the menu items/links that are available and what they do:
URL               | Label             | Description        | To have access to
                  |                   |                    | this URL, users
                  |                   |                    | must have this
                  |                   |                    | permission
------------------------------------------------------------------------------
/admin/config/    | Mass Contact      | The main           | administer mass
system/           |                   | administrative     | contact
mass_contact      |                   | interface, which   |
                  |                   | defaults to the    |
                  |                   | Category list page |
                  |                   | below.             |
------------------------------------------------------------------------------
/admin/config/    | Category list     | List the currently | administer mass
system/           |                   | defined            | contact
mass_contact/list |                   | categories.        |
------------------------------------------------------------------------------
/admin/config/    | Add category      | Add a new          | administer mass
system/           |                   | category.          | contact
mass_contact/add  |                   |                    |
------------------------------------------------------------------------------
/admin/config/    | Edit Mass Contact | Edit an existing   | administer mass
system/           | category (the     | category.          | contact
mass_contact/     | 'edit' operation  |                    |
edit/$category_id | in the Category   |                    |
                  | list)             |                    |
------------------------------------------------------------------------------
/admin/config/    | Delete Mass       | Delete an existing | administer mass
system/           | Contact category  | category.          | contact
mass_contact/     | (the 'delete'     |                    |
delete/           | operation in the  |                    |
$category_id      | Category list)    |                    |
------------------------------------------------------------------------------
/admin/config/    | Settings          | Administrative     | administer mass
system/           |                   | settings to modify | contact
mass_contact/     |                   | how Mass Contact   |
settings          |                   | operates. There    |
                  |                   | are three sub      |
                  |                   | pages under this   |
                  |                   | one.               |
------------------------------------------------------------------------------
/mass_contact     | Mass Contact      | The main Mass      | send mass
                  |                   | Contact form for   | contact email
                  |                   | sending messages.  | messages
------------------------------------------------------------------------------
/node/add/        | Mass Contact      | The form for       | create
mass_contact      |                   | adding a Mass      | mass_contact
                  |                   | Contact content    | content
                  |                   | item. This is not  |
                  |                   | really useful on   |
                  |                   | its own.           |


CHANGES FROM DRUPAL 6 TO DRUPAL 7:
Over time, this module has evolved to something more than just a basic contact
multiple users module. Due to that fact, the Drupal 7 version diverges from
what this module originally did to what people expect of a contributed module.
As an example, I've moved the module's configuration settings to where most
people expect to find them: the Configuration page. I also now have the main
menu item enabled by default.

I'm also changing the way I develop modules, such that they will interact with
other modules more and take advantage thier features. In the past, I chose to
do everything myself, rather than depend on others for bits of functionality.
Instead, I'm going to try creating more modular code and playing nice with
other modules. This may mean more dependencies, and dealing with other
people's broken code (rather than just my own), but I'm hoping this will
ultimately lead to a better module.

With that in mind, and due to the fact that Drupal 7 now assumes everything is
an HTML email and converts it to plain text by default,  I'm using the Mime
Mail module (http://drupal.org/project/mimemail) to send HTML email and email
with attachments, rather than do that part myself. I'll still handle the basic
plain text email messages.


TROUBLESHOOTING:
 * Verify the permissions are set correctly.
 * When sending messages as Bcc (hiding the recipients from each other) and
   breaking up a large recipient list into smaller chunks or sending to
   multiple categories while retaining the category name in the subject, keep
   in mind that the sender will receive a copy of the message for every group
   of recipients the list is broken up into. That is normal behavior and
   cannot be changed.
 * If your category permissions are not showing up correctly, check your
   category name and make sure you do not have any stray characters or any
   characters that Drupal does not allow, especially the single quote
   character: '.
 * If you experience "return-path" errors when sending email, you can try the
   Return-Path module (http://drupal.org/project/returnpath) to see if that
   solves your problem.
 * If PHP's mail() function encounters an error, it just returns FALSE and
   Drupal presents a message like this: 'Unable to send email. Contact the
   site administrator if the problem persists. To find what the cause of the
   error is, you may need to reference a number of logs:
   * Drupal's log messages in the Reports section
   * The host server's system logs. For most Linux systems, the log files are
     usually stored in /var/log. The system messages are usually stored in
    /var/log/messages or /var/log/syslog.
   * The HTTP server software's logs. For Apache on Linux, it's log files are
     usually found in /var/log/httpd, /var/log/apache or /var/log/apache2.
   * The mail server software's logs. Most mail servers store thier logs in
     /var/log/mail*, where "mail*" might be a directory or it might be a
     number of files in /var/log, including (but not limited to) mail.log,
     mail.info, mail.warn and mail.err.
 * If you are also using other mail related modules on your Drupal
   installation (like HTML Mail, Mime Mail, PHPMailer, SMTP Authentication
   Support, etc.), be sure to check the issue queues for those modules for
   solutions, as well.
* When you upload a file, you get the following error in red:

    File upload error. Could not move uploaded file.
    There was an error uploading the "<name of file here>" attachment.

  This is caused by the attachment directory being incorrect. Most likely, due
  to an upgrade from Drupal 6.  Check the Attachment location setting on the
  Message body settings page, here:
  admin/config/system/mass_contact/settings/body. If it is the default of
  site/default/files/mass_contact_attachments, change it to just
  mass_contact_attachments. In other words, remove the site/default/files/ part
  of the path, since Drupal handles that part now.
