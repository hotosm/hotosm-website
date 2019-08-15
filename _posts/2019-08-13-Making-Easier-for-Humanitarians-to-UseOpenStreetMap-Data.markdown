---
title: How We're Making it Easier for Humanitarians to Use OpenStreetMap Data
date: 2019-08-13 01:02:00 Z
Summary Text: At HOT, we’re constantly looking to improve our tools to address user
  needs and help OpenStreetMap data be delivered in the right format at the right
  time. In July we started a new round of software development on the [Export Tool](https://export.hotosm.org/en/v3/)
  to continue to help humanitarian partners get the data they need. We continue to
  update and develop the Export Tool as we attempt to provide our users with the best
  possible experience and answer a wider variety of their needs.
Feature Image: "/uploads/Screen%20Shot%202019-08-06%20at%2017.58.06.png"
Person: Mhairi O'Hara
Working Group:
- Technical
Country:
- Global
Project:
- Export Tool
---

## The right tool for the right job

There are many tools out there that help us create data in [OpenStreetMap](https://www.openstreetmap.org/), whether you’re looking to outline building footprints or add attribute information to features. [iD Editor](http://ideditor.com/) and [JOSM](https://josm.openstreetmap.de/) are some favourites for digitising features by tracing visible geometries from aerial imagery, while mobile phone applications like [Maps.ME](https://maps.me/) and [OpenMapKit](http://openmapkit.org/) let you add details to these features observed on the ground.

But what about tools for when we want to use data from OpenStreetMap when we want to analyze distance to a hospital or simulate the impact of a disaster? There are some great tools out there, such as [Overpass Turbo](https://overpass-turbo.eu/) which is a powerful tool for querying and exporting OpenStreetMap data for an area of interest into a variety of file formats. There is even [GeoFabrik](https://www.geofabrik.de/), a platform which hosts regularly updated OpenStreetMap data extracts at the country and continent level. But every tool has its limitations, and Overpass Turbo is no exception. Although brilliant at querying and viewing OpenStreetMap data, it can be slightly perplexing for users with little knowledge of OpenStreetMap.

![](https://paper-attachments.dropbox.com/s_512B01FC0F3AB3136BE50AE5A252375639A06472CADC109B782DFBD989DD4637_1564596081817_Screen\+Shot\+2019-07-31\+at\+11.00.37.png)

This is why the [Export Tool ](https://export.hotosm.org/en/v3/)was built — create an online tool that would allow users and our partners with little to no technical expertise or OpenStreetMap knowledge to extract data easily. The Export Tool allows users to define an area of interest and select map features and quickly export in a GIS-friendly file format to start to analyze. A user does not have to know how tags are set up in OpenStreetMap for map features and can simply select from a list of options to start exporting the data.


[![](https://paper-attachments.dropbox.com/s_512B01FC0F3AB3136BE50AE5A252375639A06472CADC109B782DFBD989DD4637_1564596152616_Screen\+Shot\+2019-07-31\+at\+10.56.11.png)](export.hotosm.org/en/v3/)

## Making HOT data more complementary for humanitarians

The last big round of development took place in 2017, which focused on opening up the tool for global exports, improving the way features are filtered, adding additional file formats and integrating the OSM2HDX extension to push datasets onto the Humanitarian Data Exchange (HDX) platform. The collaboration with HDX was a great success, enabling us to get OSM datasets to more humanitarians which have gone on to be among the most downloaded datasets in 2018 and 2019! As we continue to support partner organisations respond to numerous crises across the globe, we are looking to make OSM datasets even more useful for humanitarians. Part of this includes breaking out the Points of Interests (POIs) datasets – which are specific points on the map about places – on HDX into standalone datasets for airports, health and education facilities, as well as the addition of populated places. This more granular level of detail can make the difference when you’re working in a crisis and need to understand where is the closest health centre. This will help support the new ‘Data Grid’ feature from HDX, which aims to get the right data to the right people, depending on who is looking and what they are looking for.

![](https://paper-attachments.dropbox.com/s_512B01FC0F3AB3136BE50AE5A252375639A06472CADC109B782DFBD989DD4637_1564595467749_hdx-download-stats.png)

HDX groups crisis data into six categories:

* Affected people

* Coordination and context

* Food security and nutrition

* Geography and infrastructure

* Health and education

* Population and socio-economic indicators

The Data Grid looks at these datasets at the country level and assesses whether the data is in a common format, tidy, geo-spatially referenced, comprehensive, and up-to-date. Additional OpenStreetMap datasets provided through the Export Tool will help support this.

## Plan for upcoming development on Export Tool

For the latest round of development, we’re focused on making the tool easier for users to create Exports, help administrators at HOT to manage the tool, and add external integrations for more humanitarian partners. This round of development looks at improving the overall functionality of the tool while optimising the administrative tasks to service more external integrations. We are streamlining the technology infrastructure setup to help future code updates and encourage contributions from the public to improve the tool and better support a variety of use cases. A major focus is also on enhancing the Export Tool admin functionality so that we can capture user statistics to get a better understanding of how, where, what and when the service is being used. This will help pave the way for future rounds of development.

> ### Examples of metrics we will add

* no. of visitors

* no. of unique visitors

* geospatial distribution of visitors (city, country, continent)

* most visited page

* most time spent on page

* no. of jobs created

* no. of downloads

* no. of file formats exported

* types of features exported

* most downloaded job

* geospatial distribution of jobs created (city, country, continent)

* geospatial distribution of jobs downloaded (city, country, continent)

> \*\* *all of the stats should be able to be filtered and disaggregated based on day/week/year*

We will introduce a secondary data processing pipeline to help ease the ability of anyone getting access to full country extracts of OSM data. We currently experience bottlenecks in the processing and we will help support the speed of exports as the demand for OpenStreetMap datasets grows, particularly for country-wide datasets through HDX. Extracting, filtering and converting data into different file formats can be machine intensive and we are looking at ways to distribute the tasks a little more evenly across demands. Lastly, we will be building out a new extension that will push OpenStreetMap data to the [Pacific Disaster Center (PDC)](https://www.pdc.org/) InAWARE platform.

## Helping partners access OpenStreetMap Data with new integrations

The last major component of the development will be to extend external integration to include the Pacific Disaster Center. HOT has partnered with PDC since 2016 in Indonesia, focusing on the data collection of key lifeline infrastructure data in OpenStreetMap. These datasets were then brought in as base maps to their early warning and decision support system, InAWARE, which is a customised version of their core [DisasterWare](https://www.pdc.org/apps/disasteraware/) product specifically for the Indonesian Disaster Management Agency, [Badan Nasional Penanggulangan Bencana (BNPB)](https://bnpb.go.id/). As OpenStreetMap data is always evolving to reflect changes occurring on the ground, it is important to ensure that the lifeline infrastructure base map is kept up-to-date. This can be an intensive manual procedure, so we are looking to automate the process for the whole of Indonesia, where previously data was only provided for the cities of Surabaya, Jakarta, and Semarang.

Have an idea for a new integration? [Get in touch with us on Github. ](https://github.com/hotosm/osm-export-tool/issues)

![](https://paper-attachments.dropbox.com/s_512B01FC0F3AB3136BE50AE5A252375639A06472CADC109B782DFBD989DD4637_1564697640861_Screen\+Shot\+2019-08-01\+at\+15.13.37.png)
