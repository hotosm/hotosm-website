---
title: Getting to grips on tag quality with MapCampaigner
date: 2018-09-25 08:20:00 Z
Summary Text: Last year at State of the Map in Boulder we announced a new tool called
  MapCampaigner. Today we're opening it up to anyone to create campaigns.
Feature Image: "/uploads/mapcampaigner-landing.png"
Is image top aligned: true
Person: Nate Smith
Working Group:
- Technical
---

Last year at State of the Map in Boulder [we announced](https://2017.stateofthemap.us/program/humanitarian-openstreetmap-team.html) a new tool called [MapCampaigner](https://campaigns.hotosm.org/). Today we're opening it up to anyone to create campaigns. MapCampaigner gives anyone the ability to monitor the quality and progress of OpenStreetMap field mapping anywhere around the world. We built this tool to enable project managers to track and evaluate data quality — in this case, completeness of [OpenStreetMap tags](https://wiki.openstreetmap.org/wiki/Tags) — of an area. 

Our [initial announcement](https://www.hotosm.org/updates/2017-08-18_field_mapping_organizer_reaches_first_major_milestone) was a soft launch to test and see how mapping organizers or project managers could use the tool. Our goal with slowly rolling this out was to understand what was working, what wasn’t working, and how teams in the field could use it. Over the last three months, we’ve taken some of the primary feedback — speed and performance — and revamped how we process data to monitor an area. 

![mapcampaigner-landing.png](/uploads/mapcampaigner-landing.png)

## Easier tag tracking and faster processing

When we first launched, we had limited options for what tags could be tracked. Users could select predefined tagging schemas, or you could create custom tags one at a time. The custom method was difficult to use since you had to fill out one at a time and it limited you to how complex you could make your tagging schema. We’ve now improved how you can add custom tags by adding an edit in YAML mode ([YAML](https://en.wikipedia.org/wiki/YAML) is an easy to read data language). This allows you to create a more complex tag schema (in an easy to read format) to track and simply copy and paste into the editor. 

![mapcampaign-yaml.png](/uploads/mapcampaign-yaml.png)

To improve the experience when viewing a campaign, we evaluated the speed of how data was being shown on a campaign page. A key point of feedback has been that the data was slow to load or they were not able to process large areas of interest. Working with our partners [Kartoza](http://kartoza.com), we’ve been able to revamp how MapCampaigner queries data and makes it available for monitoring an area. Behind the scenes the application uses [AWS Lambda](https://aws.amazon.com/lambda/) to run functions that process data from HOT’s Overpass server for an active campaign area. We run this processing on an hourly basis to keep load on the Overpass server to a minimum and keep the data shown on the front-end fast for the user. 

## How to get started?

To get started using MapCampaigner, head over to [campaigns.hotosm.org](https://campaigns.hotosm.org) where you will see a map of active campaigns. You can filter by those that are nearby, inactive, or browse projects globally. 

Once you’ve signed in with OSM username, you can create a new campaign to track an area. As you fill in the details about your campaign, you choose the date range for what you want to monitor. You can go back in time to see what was previously collected and by whom, or you can set it for the future to monitor and create an active campaign to collect a feature with attributes. 

![mapcampaigner-create.png](/uploads/mapcampaigner-create.png)

After you have filled in the necessary details, you can define the area that you want to track. You can upload a single area of interest or split up an area to create sections that you will track over time. Many field projects separate these areas by team and collect data within each area. 

![mapcampaigner-aoi.png](/uploads/mapcampaigner-aoi.png)

The next step is to submit your campaign. The application will process the data and make it available on an unique campaign page (the data will update hourly). Within the campaign page, you will see three sections: 

1. Feature stats with a map
2. Errors and warnings
3. User engagement 

![mapcampaigner-page.gif](/uploads/mapcampaigner-page.gif)

*Check out this [example campaign](https://campaigns.hotosm.org/campaign/2d9946dc09a94ee8989fb3672fec44f9) across Lisbon, Portugal*

## Where is next?

We’ve launched today but are continuing to work on the application. Thanks to Kartoza for supporting us in this work. We wanted to push this work out as quick as possible to get it into the hands of the community to start using. We’re adding some features back that were left off this release and we will be rolling this out for wider use within projects. New features and updates will be rolled out periodically. 

Have some ideas about how we can improve or want to contribute to the development? Head over to the [GitHub repository](https://github.com/hotosm/MapCampaigner) and join the conversation online. Tweet your ideas or the campaign you created using the #MapCampaigner #hotosm hashtags. 