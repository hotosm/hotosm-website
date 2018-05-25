---
title: Experimenting with Analytics for Health
date: 2018-05-25 12:55:00 Z
tags:
- analytics
- malaria
---

Malaria prevention experts are moving towards OpenStreetMap (OSM) data to plan spraying campaigns, distribute supplies, and prioritize tasks. In order to improve this crucial data infrastructure, we're working on **[OpenStreetMap Analytics for Health. ](https://health.osm-analytics.org/)**This analytics tool is a general purpose validator applied to Malaria prevention specifically. It is designed assess the quality and accuracy of local OpenStreetMap using population data and machine learning.


The Humanitarian OpenStreetMap Team, Development Seed, and Azavea have rolled out a first version of HOT Analytics for Health for districts in Botswana. We invite you try and give us feedback. https://github.com/hotosm/osma-health/issues

![Screen Shot 2018-05-18 at 1.58.35 PM.png](/uploads/Screen%20Shot%202018-05-18%20at%201.58.35%20PM.png)
*Measure with OSM analytics module, the Gumare district in Botswana has a relative completeness and accuracy score of FAIR.*

### Why Analytics for Health?

Over the last month, we’ve been in Botswana conducting a full assessment of households and validating a remote mapping campaign completed by the HOT community. This work is driving indoor residual spraying (IRS) planning in the coming year by generating a high resolution building dataset for malaria elimination.

When looking to leverage OSM data for health applications, understanding the quality of OSM data is paramount. Through working with the[ Clinton Health Access Initiative ](https://clintonhealthaccess.org/)and other partners, we’ve built this health analysis tool around five lenses:

1. **Geographic Coverage** How does OSM data compare to a population dataset?

2. **Attribute Relevance** Does the data have characteristics that are complete for certain health applications?

3. **Recency of Edits** When has the data been edited? What was the age of the source imagery used?

4. **Data Errors** What seems to be a flaw within the data? Are there overlapping or duplicate data?

5. **Logical Consistency** Does it make sense? Are buildings located within a lake or a swamp?

All of these questions help answer trustworthiness and potential use of OSM data for real-world health applications. We’re taking a focus on malaria elimination programming initially as we experiment and prototype with what OSM analysis can look like more generally.

### What’s Next?

We’re taking a hard look at how we communicate this data to help public health practitioners and data analysts use OSM. Do you have some feedback or want to give input on the direction of the tool? Join the discussion here: https://github.com/hotosm/osma-health/issues.

Over the next month we’ll be working on improving performance and further developing the tool. Keep a watch here for updates on the progress.