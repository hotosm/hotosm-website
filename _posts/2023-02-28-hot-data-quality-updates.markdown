---
title: HOT Data Quality Updates for March 2023
date: 2023-02-28 02:40:00 Z
Summary Text: 'To support organizations that use OpenStreetMap data for disaster response,
  the HOT Data Team is strengthening our data quality and fitness measures. '
Feature Image: "https://cdn.hotosm.org/website/fAIr+data.png"
Person: Samson Ngumenawe
---

Several teams at HOT, including the Data Team, the Tech Team, and the regional hubs, are collaborating to develop resources, tools, skill sharing, and community feedback mechanisms that will be avenues for data creators and data users to collaborate to improve OpenStreetMap data quality.

## Data Team:

The HOT Data Team presented the [top 10 data quality issues](https://www.openstreetmap.org/user/ngumenawesamson/diary/399636) in a [lightning talk](https://2022.stateofthemap.org/sessions/HLTKHD/) at [State of the Map 2022](https://2022.stateofthemap.org/) in Florence. We categorize these data quality issues into three main categories:
* Semantic Accuracy 
* * Tagging
* * Tasking Manager project consistencies
* Positional Accuracy 
* * Spatial offsets 
* * Feature tracing inconsistencies 
* * Logical consistencies of map features
* Completeness 
* * Temporal inconsistencies 
* * Road network inconsistencies 
* * Completeness of health facilities 
* * Completeness of public service data for sustainable communities 
* * Administrative boundaries

The Data Team is also defining use cases and data quality metrics. Measuring data quality starts with identifying core datasets for each of our [impact areas](https://www.hotosm.org/impact-areas/). Examples include highways and health facilities for **Public Health**, water & sanitation, transportation, and education for **Sustainable Cities & Communities**, and waterways, buildings, and highways for **Disasters & Climate Resilience**. 

We then evaluated the use cases and the metrics for assessing the quality of each dataset, enabling us to identify ways of improving data quality.

## Tech Team:

The Tech Team is implementing automated tools for measuring OpenStreetMap data quality. 

One tool in development combines data quality metrics, defined data quality issues, and data models to provide baseline tagging information. This includes approved tags for the impact area dataset and primary and secondary attributes that create a basis for detecting and querying live data quality issues. We have seen the tool play a valuable role in tracking quality issues by generating real-time data quality reports in the ongoing Türkiye-Syria mapping activation.

The tool uses the defined data quality metrics of **bad tag value**, **missing tags**, and **incomplete tags** to validate and improve semantic data quality in OpenStreetMap. 

![Data Quality Spring 2023 1.png](https://cdn.hotosm.org/website/Data+Quality+Spring+2023+1.png)

For positional data quality aspects, the tool uses the defined metrics of **bad geometry**, **overlaps, duplicates**, and **orphan nodes** to validate the geometry of mapped features.

![Data Quality Spring 2023 2.png](https://cdn.hotosm.org/website/Data+Quality+Spring+2023+2.png)

## What the tool will look like:

**Before mappers upload data**, data quality measurement will be available for them to see in the Tasking Manager, helping them review their mapping and find issues. The tool will offer the mapper tips on how data quality issues can be detrimental to the impact of their mapping. 

![Data Quality Spring 2023 3.png](https://cdn.hotosm.org/website/Data+Quality+Spring+2023+3.png)

**As mappers edit the map and upload their changes to OSM**, the tool will provide live data quality assessments to the project managers and mappers within the Tasking Manager. 

![Data Quality Spring 2023 4.png](https://cdn.hotosm.org/website/Data+Quality+Spring+2023+4.png)

## Regional Hubs:

The regional Open Mapping Hubs are working on their individual approaches to data quality. They are publishing summaries of their plans, sharing their definitions of data quality, common data quality issues and requirements for their region, the tools they use, and open mapping best practices for regional mappers. 

The Open Mapping Hub - Asia-Pacific has already published [their approach to improving data quality](https://wiki.openstreetmap.org/wiki/Humanitarian_OSM_Team/Open_Mapping_Hub_-_Asia_Pacific/Data_Quality_Approach) on the OpenStreetMap Wiki. As one of the ways to implement their approach, they will be activating a road validation campaign for some of their priority countries.

## Coming up next: 

The Data, Tech, and Community teams are collaborating with the regional hubs to compile a Global Data Quality Strategy that will guide teams across HOT in collaborating to implement standards for improving the quality of data produced by HOT and community partners.

Stay tuned for the call for public review of the HOT Global Data Quality Strategy soon! 
