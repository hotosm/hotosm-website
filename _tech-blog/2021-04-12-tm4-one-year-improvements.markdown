---
title: Tasking Manager 4 - a year of improvement!
date: 2021-04-12 12:00:00 Z
Summary Text: 'April marks one year of the launch of Tasking Manager 4.'
Feature Image: https://cdn.hotosm.org/website/blog-post-2-image1.gif
Person:
- Wille Marcel
---

Since then, we have made 37 releases and crossed a few exciting milestones, like more than 10,000 Projects published, 300K Users registered and 100 Million buildings mapped. With feedback from the community, we identify areas that need to be enhanced and work hard to release a [new version](https://github.com/hotosm/tasking-manager/releases) every two weeks. This blog post highlights some of the most relevant improvements we have made recently.

One of the deficiencies noticed some months ago was the lack of performance metrics. We would like to have answers to questions like how many tasks were mapped in a day or month or how many new users registered in a week. To tackle this problem we developed two new pages.

## The Statistics Page

The general statistics page brings task metrics from across all projects in the Tasking Manager. The bar chart shows information about the number of tasks mapped and validated on each day of the selected date range. In the example below, we can see the statistics for the second semester of 2020.

![Statistics page](/uploads/tm-stats.png)

At the bottom of the page, we list the number of users registered in the last 7 and 30 days, respectively. Furthermore, there is also percentage information  of new users that mapped at least one task and that confirmed their email addresses. We plan to enhance this page in the future with more meaningful statistics.

## Organization Statistics

The Organization Statistics page brings the same information about tasks mapped and validated that we mentioned previously, but considers only the projects of a specific organization. On both pages, it is also possible to apply filters by campaign or by country. We believe it will help organizations to track the activity on their projects.

![Organization statistics page](/uploads/tm-org-stats.png)

Additionally, we have the number of tasks that yet need mapping and validation across all published projects of the organization.

![Organization actions statistics](/uploads/tm-org-actions-stats.png)

## Organization Public Page

A central part of the HOT vision for the coming years is to support the communities that are already doing mapping activities through Tasking Manager. In order to give more visibility to these organizations, we developed a new page that highlights their projects, teams, and people involved. See below a screenshot of the [OSM Mali page](https://tasks.hotosm.org/organisations/osm-mali/).

![Organization Public page](/uploads/tm-org-page.png)

## Project Creation Page

The Project Creation page has been totally redesigned. The map is now bigger and the area of interest and task grid has a new colour palette. We also changed the style of the buttons and added icons to make them more intuitive.

![Project creation map](/uploads/tm-create-project.jpg)

 During the task trim step, we added the option to discard tasks that are smaller than 2,000 square meters. As you can see in the image below, those tiny tasks are highlighted with a pink colour.

![Animation showing the tasks trim process](/uploads/tm-task-grid.gif)

## Better Imagery Setup

Imagery is one of the most important pieces of information we need when creating or mapping a project, as it defines the main source of the data that will be generated on top of it.

The new imagery selection simplifies the process for Project Managers, Mappers, and Validators. Besides the custom option, where it is possible to add any TMS, WMS, or WMTS layer URL, we now provide the options of the main imagery sources available for OpenStreetMap. Tasking Manager now ensures that the iD, RapiD, and JOSM editors will load with the correct imagery configured for the project.

![Imagery settings](/uploads/tm-imagery-settings.png)

We hope all these updates will bring a better experience to everyone using Tasking Manager and improve the quality of the data pushed to OpenStreetMap. Remember that you can participate in the Tasking Manager development through  [User & Dev group meetings](https://github.com/hotosm/tasking-manager/blob/develop/docs/working-groups.md#online-meetings) or reporting bugs and proposing features on [our GitHub repository](https://github.com/hotosm/tasking-manager). Another way to keep in contact is the #tasking-manager channel on the [HOT Slack](https://slack.hotosm.org).

Thanks for all your support throughout and happy mapping!
