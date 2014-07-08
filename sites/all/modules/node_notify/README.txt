Node Notify
===========

Introduction
------------

Node Notify is a lightweight module to allow subscription to comments
on nodes for registered and anonymous users.

It was specifically designed to integrate with Comment Notify, i.e. Node
Notify will not send email notifications if they are sent by Comment
Notify.

When configured, Node Notify will place:

- checkbox on a subscription enabled node's form for node author if
  he/she is registered user or text field for email address if
  anonymous;

- "Subscribe" or "Unsubscribe" link in node's links area for other
  users when in full view;

- "Subscriptions" tab on user profile page with ability to enable or
  disable existing subscriptions.


Requirements
------------

Node Notify requires Token module for email templates and core Node
and Comment modules.

Node Notify was tested against Comment Notify version 7.x-1.0. Comment
Notify is NOT required for Node Notify to work.


Installation
------------

There are no special installation steps. Drop it in site modules
folder and enable it. By default Node Notify does not alter appearance
of nodes and does not sent any notifications.


Configuration
-------------

You may configure Node Notify at Administration > Configuration >
People > Node Notify (admin/config/people/node_notify).

Configuration options include:

- Enabling subscription to particular node types.

- Removing outdated subscriptions with cron.

- Email template with tokens.

- Logging of notifications.


You should adjust permissions at Administration > People > Permissions
(admin/people/permissions). Available permissions are:

- Administer Node Notify

  Enables role to access Node Notify configuration page.

- Administer node subscriptions

  Enables role to disable or enable existing subscriptions on a node in
  "Subscriptions" tab on node page (node/%node/subscriptions). Allows changing
  node's subscription status for node's (registered) author when combined with
  ability to edit node.

  Enables role to see user's subscriptions on "Subscriptions" tab on user's page
  (user/%user/subscriptions) when combined with "View user profiles" (access
  user profiles) permission.

- Subscribe to node notifications

  Allows role to subscribe to comment notifications on nodes.


Contact
-------

Module was developed by CDLC (cdlc.dk). Current maintainer is
donatas@cdlc.lt.

Center for Digital Pædagogik (cfdp.dk) sponsored development of this
module.
