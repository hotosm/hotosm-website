---
title: Experimenting with Analytics for Health
date: 2018-05-25 12:55:00 Z
tags:
- analytics
- malaria
---

Malaria prevention experts are moving towards OpenStreetMap (OSM) data to plan spraying campaigns, distribute supplies, and prioritize tasks. In order to improve this crucial data infrastructure, we're working on OpenStreetMap Analytics for Health, a tool to assess the quality and accuracy of local OpenStreetMap using population data and machine learning. https://health.osm-analytics.org/

The Humanitarian OpenStreetMap Team, Development Seed, and Azavea have rolled out a first version of HOT Analytics for Health for districts in Botswana. We invite you try it out and give us feedback. https://github.com/hotosm/osma-health/issues

[INSERT IMAGE]
Measure with OSM analytics module, the Gumare district in Botswana has a relative completeness and accuracy score of FAIR. 

### Why analytics for health?
Over the last month, we’ve been in Botswana conducting a full assessment of households and validating a remote mapping campaign completed by the HOT community. This work is driving IRS planning in the coming year by generating a high resolution building dataset for malaria elimination.

A question when looking to leverage OSM data for health applications, understanding quality is paramount. Through working with the Clinton Health Access Initiative and other partners, we’ve built the analysis around five lenses:

1. Geographic coverage. How does OSM data compare to a population dataset?
2. Attribute relevance. Does the data have attributes that are relevant and complete for certain health applications?
3. Recency of Edits. Has the data been recently edited? What was the age of the source imagery used?
4. Data errors. What is the degree of errors within the data? Are there overlapping or duplicate data?
5. Logical consistency. Are buildings located within a lake or a swamp?

All of these questions help answer trustworthiness and potential use of OSM data for health analyses. We’re taking a focus on malaria elimination programming initially as we experiment and prototype.

### What’s Next? 

We’re taking a hard look at how we communicate this data to help public health practitioners and data analysts use the tool to assess OSM. Do you have some feedback or want to give input on the direction of the tool? Join the discussion here: https://github.com/hotosm/osma-health/issues. 

Over the next month we’ll be working on improving performance and further developing the tool. Keep a watch here for updates on the progress. 

