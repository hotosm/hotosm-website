---
title: Helping Communicate Operational Status of HOT Tools
date: 2019-09-05 06:19:00 Z
Summary Text: Sharing up to date information about the current status and operation
  of all our tools through a simple status dashboard.
Feature Image: "/uploads/status-blog-1.png"
Is image top aligned: true
Person:
- Ramya Ragupathy
- Dakota Benjamin
Working Group:
- Technical
---

We’re very happy to formally introduce our HOT status page! You can find it at [status.hotosm.org](https://status.hotosm.org/). 

HOT has a [lot of tools](https://www.hotosm.org/tools-and-data) spread across many resources and sometimes these tools encounter an error or need maintenance. Everyone asks the same questions — is the issue just on my end or are others experiencing it as well? I am planning a mapathon soon, is there planned maintenance or issues with the Tasking Manager I should be aware of? The Status page was built to consolidate information into a central point for reporting issues and ensuring all our users are up to date with the latest information. 

What does it do and what kind of information can I get? 

Our Status page is a simple web-page, built upon an open-source project called [lambstatus](https://lambstatus.github.io/). It describes the current status of all tools within the HOT ecosystem - server status, scheduled maintenance windows and other server disruptions affecting the regular user experience.

![status-blog-1.png](/uploads/status-blog-1.png)
*HOT Status page*

During our planned tool downtimes in the past,  we used our [Slack community](https://slack.hotosm.org/) as a primary means of communication. Going forward, along with the Slack updates, we encourage you to visit our status page to know if our systems are 100% operational and what to expect if there is an issue.

So, if you ever experience an interruption in service, be sure to check the status page first. As soon as an issue arises, we’ll post about it there, and will then follow up with the resolution, cause, and other relevant details.

![status-blog-2.png](/uploads/status-blog-2.png)
*Scheduled maintenance and incident history*

The status page also supports updates notifications via email,  so you can sign up to be notified via email when an issue comes up. There is also a dedicated slack channel `#status-rss` that has notifications enabled for any operational issues.

We hope you’re as excited about our status page as we are. There are [plans in the pipeline](https://github.com/hotosm/hotosm-status-lambda/issues) to pass on status updates to third-party tools, we’re working to help ensure all our tools are available on the page and add on additional issue-reporting mechanisms.  While we continue improving our status communication, please reach out to us at sysadmin@hotosm.org if you do find any issues or problems with the status site. Interested in helping us develop our tools? [Check how to get involved](https://www.hotosm.org/get-involved) for ways to volunteer. We are committed running stable services that the community can always rely on. Happy Mapping!
