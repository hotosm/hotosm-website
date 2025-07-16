---
title: Frontend Developer for the Field Tasking Manager
date: 2024-12-10 16:54:00 Z
Deadline Date: 2025-01-04 23:59:00 Z
Page Contact:
  Contact Email: sam.woodcock@hotosm.org
  Label: Send your application
---

<table style="border-bottom: 1px solid black">
	<tr>
		<td>Role:</td>
		<td style="border-left: 1px solid black">Frontend Developer(s)</td>
	</tr>
	<tr>
		<td>Application close date:</td>
		<td style="border-left: 1px solid black">4th of January 2025</td>
	</tr>
	<tr>
		<td>Duration of project:</td>
		<td style="border-left: 1px solid black">20 January 2025  - +- 30th of May 2025 </td>
	</tr>
<tr>
		<td>Work location:</td>
		<td style="border-left: 1px solid black">Remote</td>
	</tr>
<tr>
		<td>Type of contract:</td>
		<td style= "border-left: 1px solid black">Temporary contractor. Open for individuals, organizations, or teams</td>
	</tr>
<tr>
		<td>Supervision:</td>
		<td style="border-left: 1px solid black">Senior Tech Lead</td>
	</tr>
</table>

<br>

## About the Humanitarian OpenStreetMap Team 

[Humanitarian OpenStreetMap Team (HOT)](https://www.hotosm.org/) sits at the nexus of participatory mapping, community-led development, humanitarian response, open data, and tech. With a talented and diverse team spread around the globe, HOT is an NGO that supports a dynamic global community of thousands of dedicated volunteers using maps and open data for humanitarian response and advancing the Sustainable Development Goals. Working with humanitarian and development partners like the Red Cross, Médecins Sans Frontières, UN agencies, governments, and others, the HOT community maps in solidarity with those affected by or at risk of disaster, contributing the maps and data that aid workers need to do their lifesaving work.

In 2020, the work of the HOT community was recognized by [TED's Audacious Project](https://www.ted.com/talks/rebecca_firth_can_we_call_it_a_world_map_if_it_s_missing_a_billion_people), a collaborative philanthropic initiative that serves as a springboard for social impact on a grand scale, leading to an exciting new phase of growth. HOT is expanding its activities, including scaling up its support to local mapping communities through decentralizing and opening four regional Open Mapping Hubs.

## Background

HOT has developed the Field Tasking Manager (FieldTM) over the past two years. The tool ([https://fmtm.dev/](https://fmtm.dev/)) allows field mapping in a coordinated manner. FieldTM is an open-source project, and all source code is available on [GitHub](https://github.com/hotosm/field-tm). The awarded developer(s) would contribute pull requests to the GitHub repository and maintain the credit of their contributions.

Currently, the project source code includes a frontend in React and Svelte and a backend project in Python. It currently connects to the [ODK](https://getodk.org) ecosystem via the Central data collection server and Collect mobile data collection app. Full documentation is available [here.](https://docs.fmtm.dev/)

The backend is reasonably mature, particularly regarding the functionality required to complete this contract. 
The frontend is split into two parts: a desktop management frontend written in React, and a mobile mapper application written in Svelte. The management frontend also has many features implemented and it is unlikely this contract will touch development of either components very much.

Development of the mapper frontend started around August 2024, with the goal to streamline a mobile-optimized mapper experience and many advanced functionalities to aid the mapper workflow:
* Very fast and lightweight Svelte application.
* Local-first state management, via embedded PGLite database.
* Real-time sync of mapping status via Electric-SQL.
* Storage and usage of entirely offline OPFS-based maps for navigation.
* A planned embedded navigation system.
* Many other things arising from user requirements!

One of the main obstacles to mapping at present is the complexity of managing ODK alongside FieldTM. While we are certain that ODK integration is key to the project's success, from a user perspective they do not wish to have to swap between applications during the mapping process (FieldTM → ODK Collect → FieldTM).

With the introduction of [Web Forms](https://github.com/getodk/web-forms) from ODK in recent months, we have the beginnings of a fully integrated application where both feature navigation/selection can be carried out alongside survey data collection.

## Objective of the Assignment

*Objective 1*: Creation of a new FieldTM workflow for survey data collection via Web Forms. Web Forms are still under active development, so part of this may involve implementing and contributing features to the ODK git repos (with whom we have a good working relationship).

*Objective 2*: Integration of a generic localization solution for the mapper frontend (translations for ODK survey forms are already handled by the user-defined XLSForm when they specify questions), likely including Weblate as a community-driven translation platform. The key initial targets are English and Brazilian Portuguese. Ideally, the solution should also serve the React management frontend for easy integration into both.

*Objective 3*: Enable a fully functional local-first approach using browser-based Postgres. Ideally, this could include saving of submissions to the local database when offline, and syncing when the user has connectivity restored.


## Scope of Work

The work will involve frontend development using *Svelte*. There will likely also be an element of developing generic Web Components (customElement) via the *Lit* framework. There is an [existing early-stage library](https://github.com/hotosm/ui) of Web Components that may require extension or utilization.

If work alongside ODK is required, this may include but is not limited to:
* Work on the XForm data transformation and sending subsequent submission data to ODK Central.
* Implementation of components in custom components related to ODK question types, ideally as Web Components to benefit the ODK community. For example, an icon selection question (easy UX).

Depending on workload, there may also be an aspect of assisting in the UI/UX of the mapper frontend workflow. Fixing and troubleshooting of issues during and after the implementation will also be required.

All programming languages, libraries, and packages used in this project need to be free and open-source.

The developer(s) will work alongside the Senior Technical Lead at HOTOSM, with guidance from the start and regular check-ins.


## Required skills and experience

### Education

Preferred: university degree(s) in any STEM discipline, but we are flexible on this requirement. Experience over education is key.

### Experience

* **At least 5 years of professional experience in frontend development.**
* **Experience in user interface/user experience design and implementation.**
* **Proven experience in and knowledge of TypeScript / JavaScript, regardless of framework.**
* Planning/organizational skills.
* Experience in Agile development methodology and sprint planning.
* Great collaboration skills and responsiveness to modifications, revisions, and edits as required in consultation with the supervisor.
* Ability to prioritize, meet deadlines, and manage time efficiently.
* Preferred: knowledge and usage of Svelte or Lit (or Web Components in general).
* Preferred: knowledge and usage of modern localization tools in a frontend context.
* Preferred: basic knowledge of backend development, in particular using Python, or full-stack experience.
* Preferred: Working experience in development or humanitarian environment is recommended.

### Language Requirements 

Advanced English language skills. Portuguese is a bonus.

## Final products and deliverables

* The expected deliverable will be software code merged into the FieldTM repository for the frontend project. Detailed deliverables are in the table below;
* Documentation for the methodology and test cases;

The maximum budget for this assignment is $25k. Payment is initiated based on an invoice submitted by the developer(s) according to the following deliverables table, all taxes, local regulations, and other expenses should be handled by the developer(s):

<br>
<table style= "border-bottom: none">
<tr>
		<th style="border-bottom-width: 2px"><span style="font-weight: bold">Deliverable</span></th>
		<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Estimated work efforts/days</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Amount/USD</span></th>
	</tr>
	<tr>
		<td>1-2 pages report illustrating understanding the requirements/ recommendations + onboarding.</td>
		<td style="border-left: 1px solid black">5 days (1 weeks)</td>
<td style="border-left: 1px solid black">$1500</td>
	</tr>
	<tr>
		<td>Approved pull requests (PR) implementing a prototype Web Form based submission workflow.</td>
		<td style="border-left: 1px solid black">25 days (5 weeks)</td>
<td style="border-left: 1px solid black">$7500</td>
	</tr><tr>
		<td>Approved PRs implementing the additional requirements for Web Forms, including custom components and finalized design.</td>
		<td style="border-left: 1px solid black">20 days (4 weeks)</td>
<td style="border-left: 1px solid black">$5000</td>
	</tr>
<tr>
		<td>Approved PRs for the localization support, including Weblate project and structure in place for easy community contribution.</td>
<td style="border-left: 1px solid black">10 days (3 weeks)</td>
<td style="border-left: 1px solid black">$3000</td>
	</tr>		
<tr>
		<td>Approved PRs improving the UI/UX for the mapper frontend, based on field feedback. There may be scope to improve upon final data visualizations.</td>
<td style="border-left: 1px solid black">20 days (4 weeks)</td>
<td style="border-left: 1px solid black">$5000</td>
	</tr>			
<tr>
		<td>Close all testing and issues raised during the assignment</td>
		<td style="border-left: 1px solid black">10 days (2 weeks)</td>
<td style="border-left: 1px solid black">$3000</td>
	</tr>
</table>
<br>

## Application Process

Interested developer(s) (individuals, organizations, or teams) can send a maximum 1-page cover letter and CV(s)/portfolio(s) to [sam.woodcock@hotosm.org](sam.woodcock@hotosm.org) by the 4th of January, 2025.

HOT will invite only shortlisted applicants for an interview and preserve the right to start interviews on a rolling basis following applications as they are received.