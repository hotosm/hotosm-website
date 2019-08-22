---
title: A map editor for the Tasking Manager
date: 2019-07-31 09:00:00 Z
Feature Image: "/uploads/tm-and-id.jpg"
Person: Felix Delattre
Working Group:
- Technical
Project:
- 'Integrating Deep Learning: AI-Assisted Humanitarian Mapping'
---

The mappers of the HOT Tasking Manager are our driving force to generate vital data for humanitarian response. Over the past six months, we have been hard at work to put their experience first. Earlier this year we reached out to the community to understand what they think of the [Tasking Manager](https://tasks.hotosm.org) – the open source software that coordinates mapping for OpenStreetMap – and looked at how our mappers use the tool. What problems were they facing? How easy is it for them to map? Do they want to return? Our findings have helped us identify ways forward for making mapping for OpenStreetMap more user friendly, and I'm excited to share some of our ideas with the community.

## What did the user experience review say?

Until now, when a mapper chooses a task on the Tasking Manager, to carry out the task, it  sent them over to external map editor applications, such as [iD](http://ideditor.com/), OpenStreetMap’s web-based map editor. This workflow required mappers to manually navigate back to the Tasking Manager when they finished with their assigned task.

In February and March, we conducted a [user experience study](https://www.hotosm.org/updates/tasking-manager-design-discovery/) including a number of tests on how mappers are using the Tasking Manager, and dug into the data to see how this workflow could be improved. We also checked usage statistics, followed people's mapping journey during mapathons, and analyzed session recordings to see how users were spending time within the software.

*Some highlights from the data:*

* 97% of mappers are OpenStreetMap beginners.

* Registration numbers follow an upward trend every year. And the rate of people actually mapping once they have registered has dropped from 80% to 50%.

* 21% of users contributed to at least two projects.

*Key findings from the analysis:*

* Users spend a lot of time moving between projects before choosing one to contribute.

* Users spend a lot of time previewing different tasks in the map editor applications before mapping.

* Users got stuck in the process of choosing a project or a task, with many never even attempting to map a task.

* Low conversion rates may be due to the fact that users start mapping but never mark the task complete.

* Mappers don't know they need to return to the Tasking Manager and mark tasks as complete, which leads to inaccuracy in project completeness.

Because there is no optimized technical integration between Tasking Manager and any map editor, it’s not obvious to users what to do. Do they have to save their work twice? Report twice? Or save in one, and report in the other?

## How we plan to improve the workflow

New mappers usually rely on the web-based OpenStreetMap editor, called iD, and we can work to optimize the integration between the iD editor and the Tasking Manager to solve some of the challenges identified in the user experience review. We are currently working on better integrating these two programs, in order to improve the experience for our mappers and provide user instructions in one tool. This will allow the mapper to report back from a task directly from inside the integrated iD editor.

![TM and iD together](/uploads/tm-and-id-2.jpg)

Here are a some of the ways we’re working to integrate iD and Tasking Manager:

1. Improved instructions and support for mappers

2. Streamlined submission and task completion process

3. Adding a User Interface so mappers can jump immediately into a new task to keep mapping

## With an included editor - what else can we do?

*Extend mapping - for example with AI*

Last week’s [announcement of Facebook’s Map with AI service](https://tech.fb.com/ai-is-supercharging-the-creation-of-maps-around-the-world/) is an exciting development in how machine learning can predict roads from satellite imagery for mapping. This can also support mapping volunteers and professional teams to pull AI-detected map features step-by-step, and verify, adjust and improve with the human eye to build the map with the quality standard OpenStreetMap is famous for.

![Rapid editor](/uploads/rapid-editor.jpg)

*Prepare data schema for projects*

The step of integrating iD into the Tasking Manager, not only will improve the user experience itself, it also opens the way to dynamically populate the iD editor with [tagging presets and specific validation rules](https://medium.com/radiant-solutions/maprules-custom-tagging-presets-and-validation-rules-for-openstreetmap-581f8fa6df3d) depending on the map features that are requested by humanitarian organizations in each of the different projects.

## The collaboration

This year, there is [a Google Summer of Code project](https://wiki.openstreetmap.org/wiki/Google_Summer_of_Code/2019/Project_ideas#iD_editor) project by [Thomas Hervey](https://thomas-hervey.github.io/) and the iD editor developers to optimize the capabilities of iD to communicate to other software, like the Tasking Manager. The technical team of HOT is complementing the work with the iD editor and the outcomes of the usability study mentioned before through a full redesign of the Tasking Manager for the next major version, expected for the end of the summer. The goal is to make it so that users won’t need to switch back and forth between the iD editor an the Tasking Manager. We are excited about this collaboration which will make the Tasking Manager enjoyable for everybody.