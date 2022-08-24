---
title: 'Field Mapping is the Future: A Tasking Manager Workflow Using ODK'
date: 2022-08-24 10:05:00 Z
Summary Text: "While we have pretty good field mapping applications, we don’t have
  great tools to coordinate field mapping. However, we have most of the elements needed
  to create a field mapping-oriented version of the HOT Tasking Manager, which allows
  people to select specific areas and complete tasks in a coordinated, organized fashion.
  \n\nIt’s already possible to implement a sort of Field Mapping Tasking Manager workflow
  using existing tools (mostly based on ODK, particularly the new ‘select from map’
  functionality), but it’s pretty labor-intensive and tricky. We’re working on some
  automation to ease the pain points, which moves us closer to a fully-fledged Tasking
  Manager.\n\nIn collaboration with the Tech and Communities team, and the Community
  and Training Working Groups, the HOT Field Programs Team will be hosting a [skill
  share session on September 9th, 2022,](https://www.eventbrite.com/e/field-mapping-is-the-future-a-tasking-manager-workflow-for-open-data-kit-tickets-400186387257)
  during which people can gain an understanding and some experience with the idea;
  we’ll be using the feedback from this session to gauge interest and participation
  to continue development. We encourage individuals and communities interested in
  field mapping coordination tools to attend!"
Feature Image: "/uploads/2022-09-09_skillshare_poster%20(1).png"
---

Field mapping by local people is key to the future of open mapping. However, the tools available for field mapping—despite many being of high quality—do not form a coherent ecosystem to unleash the potential of community field mapping. Something is missing! Could it be a Tasking Manager for Field Mapping?

**Tasking enables better remote mapping**

One of the most impactful elements of the open mapping ecosystem in the last ten years has been the [HOT Tasking Manager](https://tasks.hotosm.org/). [OpenStreetMap](https://www.openstreetmap.org/#map=19/75.56995/-116.60797) itself created a massively scalable, open repository for geographical data, and tools like [ID Editor](http://ideditor.com/) and the [Java OpenStreetMap Editor (JOSM)](https://josm.openstreetmap.de/) provided first-rate tools to add data to the map remotely. However, between the editing tools and the repository, there was a gap: how could people easily choose areas to map completely and with high quality?

Something was needed: a way to allocate small, manageable tasks to individuals, keep track of their progress, quality-check and validate their work, and seamlessly integrate the new data into OpenStreetMap without damaging existing data. The HOT Tasking Manager served as the rug that tied the room together; a tool for the community to define data needs, and for individual mappers to contribute with ease and confidence.

![Screen Shot 2022-08-24 at 3.14.13 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.14.13%20PM.png)


**What about tasking for field mapping?**

There are a number of great field data collection tools! 

The mighty [OpenDataKit](https://getodk.org/) and the many platforms built from it such as [Kobo Toolbox](https://www.kobotoolbox.org/) make it possible for anyone with an Android device to collect data using flexible, powerful forms designed in a spreadsheet. 

![Screen Shot 2022-08-24 at 3.15.46 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.15.46%20PM.png)

*The spreadsheet on the left creates the questionnaire and “Select From Map” activity on the phone.*


[Vespucci](https://vespucci.io/) brings much of the power of JOSM to a mobile editor. [EveryDoor](https://every-door.app/) gives both Android and iPhone users a simple platform to edit OSM data, and StreetComplete does the same for Android users. [OSMAND](https://osmand.net/) and [Organic Maps](https://organicmaps.app/) allow navigation and offline map viewing with OSM data, as well as some basic capacity to add or edit features to contribute back to OSM.


![Screen Shot 2022-08-24 at 3.27.54 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.27.54%20PM.png)

*EveryDoor, Vespucci, OSMAnd, and Organic Maps screenshots*

Just as with remote mapping, we have an excellent data repository (OSM) and great editing and/or data collection tools, but there is no coordination platform to facilitate large-scale, high-quality field mapping for OpenStreetMap. 

We propose a Field Mapping Tasking Manager to fill this need.

**The components of a field mapping Tasking Manager are mostly already built!**

If we were starting from scratch, this would be a daunting proposition. However, thanks to the incredible work of [Nafundi](https://nafundi.com/), the lead developers of OpenDataKit (ODK), and some related work happening within HOT and the wider open mapping community, the pieces are mostly already in place.

**What is needed for a field mapping Tasking Manager?**

What’s needed to implement a Field Mapping Tasking Manager? We need a way to:
* Define an Area of Interest and divide it into smaller tasks
* Allocate tasks to individuals such that there is neither duplication nor gaps
* Monitor progress of field mapping tasks
* Convert the field mapping results (submissions) into an appropriate format for validation 
* Validate the work and provide feedback to the mappers if needed (including asking them to revisit or correct errors)
* Integrate the new data into OSM or other platforms
  * Ideally with specific attribution to the field mapper for the data they created, a long-standing request from the OSM community who value individual responsibility for edits over aggregated data imports

**What do we already have?**

As of mid-2022, we have tools that can accomplish all of the above requirements. A Tasking Manager-like functionality can already be achieved with (a great deal of) manual work. With a bit of simple automation, we can already make this much smoother, and eventually create a highly accessible and functional Field Mapping Tasking Manager workflow. 

**New ODK “select from map” functionality and individual form allocation**

As of mid-2022, ODK incorporates a new functionality, [select from map](https://forum.getodk.org/t/odk-collect-v2022-2-beta-select-from-map-geojson-datasets/36913), that allows field mappers to select an object from a map, view the existing attributes, and fill out a form adding new information and attributes to that object. For example, a mapper can approach a building, select that building from a map view within ODK on their mobile phone, and add the opening hours, number of floors, construction material, or any number of useful attributes in a well-structured questionnaire format*.

 *This mostly replicates the functionality of the much-lamented [OpenMapKit](http://www.openmapkit.org/), a very useful fork of ODK created by the American Red Cross with support from HOT and other agencies, which allowed users to launch forms from a map view and select buildings/features to add attributes to. Unfortunately OMK is no longer maintained and can’t be reliably used.

![Screen Shot 2022-08-24 at 3.34.04 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.34.04%20PM.png)

Additionally, the new [ODK Central](https://docs.getodk.org/central-intro/) web server application contains very granular tools to allocate forms to individual users. It is possible, in fact, to create individual questionnaires for an arbitrary number of small areas (such as neighborhoods), each with their own set of features (such as buildings). These forms can then be allocated to specific “app users,” with access to specific forms (and therefore neighborhoods/areas) defined by a QR code.

![Screen Shot 2022-08-24 at 3.35.11 PM.png](/uploads/Screen%20Shot%202022-08-24%20at%203.35.11%20PM.png)

*ODK Central supports allocation of individual forms—and corresponding features like buildings—to individual users*

How does this “app user” system facilitate a Tasking Manager? We’re so glad you asked! By creating a QR code for each neighborhood (or “task”), and allocating them one-by-one to individuals, we can:
* Assign specific areas to specific people (either by allocating them directly, or by providing a selection of areas and letting people choose)
* Keep track of which areas have been allocated, and completed (and, with a bit more work, validated)Keep track of who mapped which area
* Allocate new areas to people who have finished theirs
* Keep track of which areas still require mapping (or completion/correction after validation)

At the moment, this is a lot of manual work. However, ODK Central has a [powerful and well-documented API](https://odkcentral.docs.apiary.io/#), and the creation of individual tasks/areas, allocation to specific users, tracking of incoming results and freezing of forms that are already allocated, can be automated!

While we can already allocate tasks manually, the obvious next step is a web map allowing field mappers to select an area easily. The [OpenMapDevelopment Tanzania (OMDTZ)](https://www.omdtz.or.tz/about/) team has pioneered i[nteractive web maps that integrate with ODK Central](https://millmaps.org/), demonstrating a promising way forward.

**Conversion of ODK submissions to OSM XML for validation and upload**

The HOT Tech Team has already created a set of scripts that convert submission from ODK forms into OSM XML, the native data format of OpenStreetMap. This allows the submissions from field mapping to easily enter the traditional data pipeline of validation in JOSM, followed by upload to OSM attributed to the OSM ID of the field mapper. 

The existence of these scripts facilitates more Tasking Manager-like functionality, as the conversion of submissions into datasets ready for validation is straightforward and easily automated. The scripts are particularly easy to adapt when they target good-quality standardized ODK forms, a key benefit of this entire system.

**What do we need to build?**

In principle, we can already implement a Field Mapping Tasking Manager workflow, but it requires a lot of tricky manual work. Our plan is to do so, and incrementally automate away the pain points! The most likely path probably looks like:

1.Create a mobile-friendly web map (not a mobile app, just a web app) that:
* Displays all of the individual tasks in a project, color-coded by allocation/completion status
* Allows mappers to click on a task near their physical location and have it allocated to them (either with a QR code or a direct launch of ODK Collect with the relevant configuration)
* Allows mappers, validators, and managers to see progress and select tasks for further mapping or validation

2. Create a web map for computer screens that facilitates the creation of projects and individual tasks
* Ideally uses road and waterway networks to divide tasks sensibly for field mapping rather than arbitrary squares
* Automates the process of downloading OSM data (likely buildings as the first priority) for the area covered by each task and converting it into selectable features in an ODK form for each task area

 *Similar to and possibly based on the HOT Tasking Manager UI, though optimized for mobile; people using the Tasking Manager are by definition using a computer screen, while field mappers are by definition using a mobile device.*


3. Refine and expand the form(s) available to cover the most critical field mapping data needs of communities

 *Most field mapping data is currently uploaded to OSM as bulk imports attributed to the organization, project, or validator. This is a source of frustration to the OSM community, who greatly value individual responsibility for individual edits added to the map.*

4. Streamline the data validation and import process

5. And so on…

Next steps

In collaboration with the Tech and Communities team, and the Community and Training Working Groups, the HOT Field Programs Team will be hosting a skill share on September 9th, 2022, where we’ll demonstrate the use of a rudimentary Field Mapping Tasking Manager workflow. All are welcome! 

French and English sessions will be held in several time zones, and additional sessions may be added if there is interest from additional time zones and languages (we can probably manage a Spanish-language session if the participants are prepared to hear the language of Cervantes mercilessly butchered). 

If, following the skill share session, there is substantial community interest in using this workflow, we will continue building it in collaboration with those users. So if you think this is something you might want or need, make sure you sign up for the skill share at [tinyurl.com/field-mapping-tools1.
](https://www.eventbrite.com/e/field-mapping-is-the-future-a-tasking-manager-workflow-for-open-data-kit-tickets-400186387257)



https://manage.siteleaf.com/pages/63061740babb35480722431e/edit

hotosm-website.siteleaf.net/el-mapeo-de-campo-es-el-futuro-un-flujo-de-trabajo-del-gestor-de-tareas-utilizando-odk.html edit








