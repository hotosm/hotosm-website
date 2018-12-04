---
title: 'Tasking Manager Update: New Version Released!'
date: 2018-12-04 01:44:00 Z
Summary Text: As December has started we’ve also released another update to the Tasking
  Manager. Head to [tasks.hotosm.org](https://tasks.hotosm.org/) and start mapping
  to check them out.
Feature Image: "/uploads/tm-history-update.png"
Person: Nate Smith
Working Group:
- Technical
---

October and November have been busy months and today we updated the [Tasking Manager](https://tasks.hotosm.org/) with new features and fixes. We received nearly 60 different commits from around the globe through [Hacktoberfest](https://hacktoberfest.digitalocean.com/) in October. In November we've worked to review and integrate these contributions. The new work included documentation updates, layout improvements, and bug fixes large and small. Below is a run down of what we completed and how it will impact your mapping.

Want to hear more about what’s next or see some of the [new features live](https://tasks.hotosm.org/)? Join us on Tuesday for the monthly Tech Working Group meeting. Check out the meeting details. 

## What’s new?

### New layout for mapping tab
We’ve improved the layout of the mapping tab to better separate the different actions you can take on a task grid. We’ve separated the split or mark as bad imagery actions from the stop or complete mapping actions to better communicate these actions. We’ve also ordered the actions to help encourage users to choose the correct action to stop or complete mapping.

![tm-mapping-layout.png](/uploads/tm-mapping-layout.png) 

### New layout for history of a task
We improved the layout for the history of a task for readability. It is helpful to see the state and the progress of the task grid and the new layout improves readability by separating history by user, color coding the status according to the map, and ordering by most recently updated. 

![tm-history.png](/uploads/tm-history.png)

### Write in markdown for task description and contribute card
You can now write in Markdown for the task description and contribute card. This should help give users options to improve readability when writing longer descriptions or itemizing a comment while mapping. 

![tm-markdown-comments.png](/uploads/tm-markdown-comments.png)

### Expert Mode foundation
Expert mode will be a new function for exposing more advanced mapping or validation features. We started the foundation for this mode and you are able to turn if on via your profile. Expert mode will include improved links to Achavi and enabling opening of Overpass queries to compare specific task changes. The new features are not fully implemented yet but will be available in the next few releases. 

![tm-expert-mode.png](/uploads/tm-expert-mode.png)

### Pesky bug fixes
When building web applications, you're bound to run into browser issues or other problems that can make your user experience difficult. We’ve been able to address several problems that should make usability easier: 

- Fixed the scroll issue when clicking Map or Validate tabs on the project pages

- Fixed the login redirect loop. You now are not stuck endlessly logging in trying to get where you want to be. 

- When paging through the Contribute page, each new page brings you back to the top

- Fixed some map legend issues and the mini map sizing issue on certain screen sizes 

Check out the release versions for a full changelog: https://github.com/hotosm/tasking-manager/releases. 

A huge thank you to all the contributors who joined in during the month. And thank you to Github, Digital Ocean, and Twilio for sponsoring and coordinating Hacktoberfest.