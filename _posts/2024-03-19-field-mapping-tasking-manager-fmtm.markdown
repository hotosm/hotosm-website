---
title: Field Mapping Tasking Manager (FMTM)
date: 2024-03-19 00:58:00 Z
tags:
- tech
Summary Text: Collaboration and communication among key players are critical to a
  successful field mapping campaign and data collection effort. Leveraging the right
  tools, such as the Field Mapping Tasking Manager (FMTM), can significantly enhance
  coordination and streamline communication among team members, improving field survey
  efforts and making them more efficient and accurate.
Feature Image: https://cdn.hotosm.org/website/FMTM-Monrovia.jpg
Person: Ivan Buendía Gayton
---

Conducting field surveys can be a valuable method for collecting map data. However, field data collection can be a challenging and complex task that requires careful planning, coordination, and execution. The process involves various key players —Project Managers, Field Managers, Mappers, and Validators— each with specific roles and responsibilities.

Particularly when working with large groups of mappers in dense settings, it can be difficult to coordinate mapping activities. Challenges include: 
* Ensuring each mapper knows which area/features they are responsible for visiting and gathering data on,
* Avoiding missed areas or features,
* Minimizing unintentional duplication of areas or features (multiple mappers visiting the same place),
* Evaluating the quality and completeness of submissions,
* Cleaning, managing, and getting the submission data into maps and other data products for use. In particular *conflation* —the process of adding new data to map features that may already have data attached to them— can be difficult and time-consuming,
* Keeping public data (such as information that should go to OpenStreetMap) cleanly separate from private data. 
 
With these challenges in mind, HOT's Tech team, along with our partner in Nepal, [NAXA](https://naxa.com.np/), and contributors from all around the world, have developed the Field Mapping Tasking Manager (FMTM).

![FMTM-FieldMapping1.jpg](https://cdn.hotosm.org/website/FMTM-FieldMapping1.jpg)
*Using OpenDataKit Collect to gather data from local residents in an informal settlement in Monrovia*

## What is FMTM?

### The Field Mapping Tasking Manager (FMTM) helps teams add local knowledge to map features by coordinating mapping in the field. 

The FMTM is a standalone mobile and web application that was designed and built to facilitate large teams' mapping to cover urban areas effectively, efficiently, and with good quality. It uses [OpenDataKit Collect (ODK Collect)](https://getodk.org/), a powerful data collection platform that leverages commonly available mobile Android devices to enable people to input information, including geospatial data in the field. Open Data Kit allows field mappers to create questionnaires adapted to gather the information they need for their campaigns. 

The FMTM allows mapping coordinators to create campaigns that assign individual areas and/or features to different field mappers, keep track of their contributions, and manage the resulting data. It helps field mappers know which areas and features they are responsible for covering and avoid missing or duplicating features.

![FMTM-Explanation.jpg](https://cdn.hotosm.org/website/FMTM-Explanation.jpg)
*A project manager who has just created an FMTM project on their laptop demonstrates to a field mapper how they can select their assigned buildings on their phone*

Using the FMTM, each mapper using ODK Collect on their mobile device can select —or be assigned— a single area at a time to map, with a specific set of features (such as buildings) to visit. They can easily see where they must go and which features they must visit to complete their “*tasked*” area. Since each task area is specifically defined by a boundary and/or a set of features, it’s easy to avoid missed areas or duplication (whereby more than one person visits the same structure).

## The ease and quality of field mapping

FMTM has been tested in several mapping campaigns in  Zanzibar, Rwanda, Dar es Salaam, Monrovia, Dominica, Cambodia, and Nepal, amongst others.

FMTM was successfully used in Janakpur Sub-Metropolitan City, Nepal, to conduct a 15-day field survey of approximately 3400 buildings for the digital metric addressing system project implemented by NAXA with financial assistance from The Asia Foundation. A total of fifteen local enumerators (seven men and eight women) learned how to log in to FMTM, assign tasks for themselves, download QR codes, and collect data via ODK Collect. Despite the initial challenge of the enumerators lacking proficiency in spatial knowledge, this deployment was considered an achievement.

![FMTM-MappingAndCell.jpeg](https://cdn.hotosm.org/website/FMTM-MappingAndCell.jpeg)
*Field mappers navigate using their phones (in this case, high-quality drone imagery makes it particularly easy to see where they are going) and select buildings to survey*

## How can I try the FMTM?

HOT operates a public FMTM instance at [https://fmtm.hotosm.org](https://fmtm.hotosm.org)

As of 06/03/2024, this instance is in public beta, and any user can create a new project for testing.

However, FMTM is not fully mature software yet, and users should be cautious as there are occasional bugs, although it’s unlikely that they’ll actually lose data or otherwise suffer a catastrophe.

To register an organization account on FMTM, visit [https://fmtm.hotosm.org/create-organization](https://fmtm.hotosm.org/create-organization)
This will require you to have an administrative account on a working ODK Central server.

If you do not have an administrative account on an ODK Central server and do not know how to get one, you should contact [ivan.gayton@hotosm.org](ivan.gayton@hotosm.org) and/or [susmina.naxa1@gmail.com. ](ivan.gayton@hotosm.org) 
