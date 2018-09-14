---
title: 'Website Update: Interactive Maps'
date: 2018-09-14 00:00:00 Z
Feature Image: "/uploads/our-work-map-view.png"
Person: Ramya Ragupathy
Working Group:
- Technical
Summary Text: A round up of recent major pushes to the website through Outreachy.
---

The current round of [Outreachy program](https://www.hotosm.org/updates/welcoming-summer-work-on-open-source-tools-through-outreachy-and-google-summer-of-code/) closed this mid-August. Starting mid-May, for about 3 months I’ve been working with HOT on improving map visualisations and packing more data into the new website. [The previous update](https://www.hotosm.org/updates/powering-our-maps-with-data/) was focused on map integration across pages & key HOT statistics at the country level. From then on, I’ve been working on bringing more interactivity to the [Our Work page](https://www.hotosm.org/our-work) and the [Country Overview](https://www.hotosm.org/where-we-work/uganda/).  


## Active Project Countries & Project distribution

[Our Work page](https://www.hotosm.org/our-work) has two map views now:


- A map highlighting HOT’s project & member countries with a red pulsing dot indicating countries with active tasking manager projects in the last 24 hrs.
- A cluster map presenting tasking manager project distribution across the world with an ability to zoom into and view individual projects on [tasking manager page](http://tasks.hotosm.org).


![ou-work-page](https://d2mxuefqeaa7sj.cloudfront.net/s_39F3C0903840B3812C9E8B2BBB1A07BB5BF51CB7140E96FE99950467588D46E3_1536913037411_our-work.gif)

## More Stats in Country Overview

Our Work page lets you navigate to individual country pages. These pages have an interactive map loaded with centroids of all the country specific tasking manager projects. A side-bar next to the map provides a summary of HOT activity for the country: 


- Number of tasking manager projects/mapping campaigns 
- Total number of HOT projects - these are the larger umbrella projects which are executed through multiple field mapping/tasking manager campaigns 
- Voting member count
- Local HOT presence/contact details


![uganda-screenshot](https://d2mxuefqeaa7sj.cloudfront.net/s_39F3C0903840B3812C9E8B2BBB1A07BB5BF51CB7140E96FE99950467588D46E3_1536913248235_image.png)


Map interaction lets you:

  - Jump to the respective tasking manager campaign project page, and
  - Filter mapping campaigns across different years & status using the `Campaign Filters` tab. This provides you insight on the most active year for the country and the current active tasking manager campaigns for the community.


![uganda-campaign-filters](https://d2mxuefqeaa7sj.cloudfront.net/s_39F3C0903840B3812C9E8B2BBB1A07BB5BF51CB7140E96FE99950467588D46E3_1536913553892_country-filters.gif)


Country level stats bar, present below the map view now lets you toggle between stats for edits via HOT Tasking Manager and all OSM edits within each country.


![country-stats](https://d2mxuefqeaa7sj.cloudfront.net/s_39F3C0903840B3812C9E8B2BBB1A07BB5BF51CB7140E96FE99950467588D46E3_1536913381234_country-stats.gif)

## There’s more coming soon

In the coming days, I’ll be focusing on:

  - [OSM Community Index](https://github.com/osmlab/osm-community-index) integration for the Country page to pull in contact information, specific to each OpenStreetMap Community.
  - An interactive map for each HOT project page, highlighting the mapping areas, key statistics, and data available for download at project level.
  - Faster maps and lighter data load on the website.

Inputs from the community has been integral in shaping the website.  Very soon we’ll be organising a community discussion to gather ideas on directions. Keep watching our [Slack](http://hotosm.slack.com) & [Twitter](https://twitter.com/hotosm) for announcement. Meanwhile, if you’d like to discuss further or work on any of these ideas, here’s where [you begin](https://github.com/hotosm/hotosm-website/issues)! 





