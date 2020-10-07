---
title: Improved notifications and better performance on Tasking Manager
date: 2020-10-07 10:00:00 Z
Summary Text: Every two weeks we push a new version of Tasking Manager with new features, bug fixes and enhancements. It has been a while since our last update, so let’s take a look on what is new on Tasking Manager.
Feature Image: "/uploads/tm-stats-10-2020.jpg"
Person:
- Wille Marcel
---

This week we released the [version 4.1.10](https://github.com/hotosm/tasking-manager/releases/tag/v4.1.10). The main focus of the recent releases was to improve the notification system in order to allow a better communication between mappers, validators and project managers.

We improved the notification bell component, assuring that it will always show your last 5 unread messages. When a new message arrives, the list updates automatically.

![Notifications popup](/uploads/tm-notifications-popup.png)
<br><br>

On the [notifications page](https://tasks.hotosm.org/inbox), we now have the possibility of filtering the Teams notifications, a new message type added recently to Tasking Manager. You can also delete multiple messages in batch.

![Notifications page](/uploads/tm-notifications-page.png)
<br><br>

As we mentioned about team messages, now it’s possible for managers to send messages to all their team members. It can be done from the Manage Team page:

![](/uploads/tm-team-notifications.gif)
<br><br>

We believe it will be useful to give instructions to team members, announce new projects or any other communication needed within the teams. Users have the possibility to customise from their [settings page](https://tasks.hotosm.org/settings) to opt in or out for receiving emails about the Teams Notifications.<br><br>

## Drag & drop image upload

For a seamless experience, users can now drag and drop images in any input forms like shown in the graphic below or when commenting on projects and tasks. Project managers can also use the drag and drop image upload when drafting the project’s instructions or when sending messages to the project’s contributors.

![](/uploads/tm-drag-drop-upload.gif)
<br><br>

## Markdown support

We also added full support to Markdown on input forms. If you don’t know Markdown, it’s a markup language that allows us to easily format the text for the web. For example, a text between asterisks is formatted as italic (`*hot*` → *hot*). If you use two asterisks on the beginning and on the end, if will be bold (`**hot**` → **hot**).  Check out the [syntax guide](https://www.markdownguide.org/basic-syntax/) to know more. Remember to separate paragraphs with a blank line.<br><br>

## Better performance

The performance of Tasking Manager API has greatly improved since the 4.0 release. In the beginning of August we reached the mark of 250K users, since then our user base is growing faster and right now we have more than 265K registered users. Some weeks ago we had moments with almost 500 users mapping simultaneously. The improvements made on the software allowed the servers to support that higher demand, and therefore contribute to the HOT’s goal of putting the world's most vulnerable people and places on the map.<br><br>

## Next steps

In the coming weeks, we plan to do some additional work on notifications and continue improving the API performance. We are also continuously identifying bugs and small improvements that needs attention. If you want to contribute with the Tasking Manager development, checkout [our communication channels](https://github.com/hotosm/tasking-manager/blob/develop/docs/working-groups.md) and join us.
