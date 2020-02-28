---
title: User Experience Discovery with the Tasking Manager
date: 2019-04-30 10:00:00 Z
Summary Text: Conducting design research to evaluate mapping and validation workflows
  within the Tasking Manager.
Feature Image: "/uploads/major-mapping-userflow.png"
Person: Leihla Pinho
Working Group:
- Technical
Project:
- 'Integrating Deep Learning: AI-Assisted Humanitarian Mapping'
---

_Guest post by Leihla Pinho from [Major](http://wegomajor.com/)_

Over the last few months, our team at Major, a digital design studio based in Lisbon, have taken a deep dive into the Tasking Manager. Our goal in working with HOT was to find ways to evolve the mapping and validation workflows to improve data quality, increase the speed of mapping, and improve user return rate. All of this work has a focus on helping move the Tasking Manager to the next major version to [bring in machine learning and more open data](https://www.hotosm.org/updates/bringing-machine-learning-and-open-data-to-the-tasking-manager/). 

We’re sharing our research insights here to show where the Tasking Manager has been extremely successful but also where we’ve identified or documented known gaps. 

## Understand the ecosystem through research

In order to understand the Tasking Manager, we started with a discovery phase. It was important for us to understand what are the different jobs the Tasking Manager does, who is using it and why, and what is currently impacting their productivity. 

When planning our research, we wanted to have complementary data points that allowed us to analyse user intent vs user action. We combined key research methods to understand user needs, motivations and pain-points with data analysis of logged behavioral data that helps us understand real platform usage. We employed a mix of website usability analysis, user flow analysis, benchmarking, web analytics/tracking data, user interviews, and conducted an in-person workshop with the Open Source community around the Tasking Manager.

To begin all of this work, we started with identifying what we wanted to understand. We focused our work around a number of questions. We saw a high number of registered users that never mapped a task and we were curious to know why. We asked users during in a mapathan and user interviews, whether the multiple platforms are having an impact in participation. We wanted to know, whether the mapping process is understandable and which information needs to be presented and each step, to provide a welcoming experience, and facilitate the environment to produce good data quality for OpenStreetMap.

We were interested in how users choose a project over another. And how they select specific tasks. And what are the factors that drive the persons to take these decisions? And then to come up with recommendations to improve the Tasking Manager’s interaction with the users.

## Usability Analysis

![usability](/uploads/major-usability.jpg)
*Website usability review*

We started by performing a [usability analysis](https://invis.io/TAQL0SMCXH3) where we looked at individual pages and flows to understand how easy they are to use if they follow best practices and standards and if they ultimately help users achieve their goals. We looked at usability heuristics like the visibility of system status, user control and freedom, consistency and standards, flexibility and efficiency and also aesthetics in order to look for improvement points.

Key Findings:

* There is a lack of system feedback and error prevention
* Tasking Manager is not following new HOT style guidelines yet
* Lack of affordance and content overload, especially in project pages when presented to new mappers
* There are too many buttons competing for attention, making it harder for users to know where they should click next

## User Flow Analysis

After our initial research, we focused our analysis on user flows within the Tasking Manager. A user flow is the path and steps taken by a user to complete a task. While we are focused on mapping and validation flows, we looked at four key user flows in the Tasking Manager: 

1. [On-boarding](https://projects.invisionapp.com/share/W3Q5Q01MYNE#/screens/342897260) of new users (how users join the Tasking Manager)
2. [Mapping a task](https://projects.invisionapp.com/share/W3Q5Q01MYNE#/screens/342897259) (choosing a project and a task, mapping and marking as complete)
3. [Validating a task](https://projects.invisionapp.com/share/W3Q5Q01MYNE#/screens/342897258) (both for individual tasks and validation of multiple tasks)
4. [Creating a project](https://projects.invisionapp.com/share/W3Q5Q01MYNE#/screens/342897257) (all the steps a project manager go through to create a project)

Within each user flow, we looked at the actions the user has to take, where the action is taken, and documented pain-points and initial recommendations. 

![mapping-flow](/uploads/major-mapping-userflow.png)
*Mapping user flow document*

### Mapping user flow key challenge 

One of the strongest challenges, which we have identified is the jump to the iD editor when starting to map, which confused a lot of users. Then, whether to know or not that they have to save and report back on their work on both platforms, the iD editor and the Tasking Manager, is one of the biggest bottlenecks and causes for users’ unpleasant experience.

![user-flow](/uploads/major-validation-userflow.png)
*Validation user flow analysis document*

### Validation user flow key challenge

While there are many similar findings as to the ones of the mapping workflow, some are particular to the validation of tasks. In these, we found the process of how people become validators are essential. Currently, these are ad-hoc processes between people who trust each other, and this works at a small scale. However, the steps people are doing to identify and promote people to validators are very limited and manual. The Tasking Manager should facilitate this process better.

### Overall Key Findings

* User flows are scattered among too many platforms, forcing users to register in OSM, choosing a project and task in the Tasking Manager and Mapping in their preferred editor, having to return to TM to mark a task complete.
* The onboarding process is quite long and time-consuming
* There are too many steps needed to achieve the main action (map or validate)
* It is not always obvious what the user needs to do in order to achieve his goal during the workflow

## What’s next?

This is just a slice of the work we’ve completed during this first phase of work. You can [view slides](https://docs.google.com/presentation/d/1H9uM0gJyAcScrHoeJQug9sVwl_AX2M_FX0ipr6RydLY/edit?usp=sharing) with the summary of our research notes. 

All of this work has been the stepping stones for us to understand and evaluate where the Tasking Manager can be improved and how AI-assisted mapping workflows can have an impact. As we’ve taken this research and findings into our next design phase, we’re looking at key points where AI can assist mappers, validators, and project managers to improve the work they do and make their experience enjoyable. 

We’ll be focusing on:

1. Simplify the process of choosing a project/task to map
2. Promote engagement and return rate of mappers 
3. Make it easier for mappers to return to their tasks
4. Improve communication between mappers and validators 

In the coming weeks, we’ll be sharing how these findings have evolved into wireframes. You can always watch this in real-time on [Github](https://github.com/hotosm/tasking-manager) and on [Slack](http://slack.hotosm.org). Join the conversation and be a part of this process of evolving the Tasking Manager.
