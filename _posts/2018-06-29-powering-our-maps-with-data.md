---
title: 'Website Update: Powering our maps with data'
date: 2018-06-29 00:00:00 Z
Feature Image: "/uploads/hotosm-dot-org-3-compressor.png"
Person: Ramya Ragupathy
Working Group:
- Technical
Summary Text: An update on how we are integrating data and visulisations across the
  site.
---

Making maps and operationalizing data is core at the [Humanitarian OpenStreetMap Team (HOT)](https://www.hotosm.org/). Starting mid-May, as an [Outreachy participant](https://www.outreachy.org/), I've been working with HOT on improving map visualisations and how we integrate data into the new website. I'd like to share the progress so far and what's cooking next!

### Numbers & Impact filters

With the [fresh new website for HOTOSM](https://www.hotosm.org/updates/a-fresh-look-for-hotosm-dot-org/) that was launched two weeks ago, there's been new additions including:

* Map view to navigate across countries and to see where projects and members are located, and

* Key statistics on mappers & edits to give an overview on the mapping activity within that country through HOT

![country-data](/uploads/data-driven-maps-country.png)

All the numbers on home page & country page are now collated using [stats-collector](https://github.com/hotosm/stats-collector ) (an [AWS lambda](https://docs.aws.amazon.com/lambda/latest/dg/welcome.html) function) that sources numbers from [Missing Maps](https://www.missingmaps.org/) & [Tasking Manager](https://tasks.hotosm.org/) endpoints. These numbers are auto-refreshed once every 6 hours, starting at 12 AM UTC time. This method allows the website to be fast and always showing recent mapping numbers.

While the [Our Work](https://www.hotosm.org/our-work) page lets you navigate to countries, there's also an impact areas section at the bottom of the map view. Clicking on an impact area filters out respective countries in the map view and highlights only related projects in the web page.

![impact-area](/uploads/data-driven-maps-impact-area.gif)

### In the pipeline

Here's what we'll be focusing on in the coming days:

* Along with country level highlights on the [Our Work](https://www.hotosm.org/our-work) page, there'll be additional visualisations highlighting:

  - Countries with active tasking manager projects. Active field mapping projects will be added in the future. 

  - Tasking Manager project distribution across the world with an ability to zoom into and select individual projects.


* While selecting country level overview, map view will indicate the centroid of all the tasking manager projects within that country. There will be options to: 

  - Jump to the respective project tasking manager page, and

  - Filter projects across different years.

* Country page statistics at present is restricted to just Tasking Manager projects. A toggle view is planned to alternate between edits via HOT Tasking Manager and all OSM edits within each country. 

* Within each country page, we're also planning to integrate the work on the [OSM Community Index](https://github.com/osmlab/osm-community-index).

* At present there is a separate page for each project listing out coordinators, duration, impact areas and description of the project. A map view is being planned for this page to highlight the geographical coverage & let anyone visualize the progress of the project. Similar to the country page, there will be numbers on area covered, mappers & edit counts.

* Data that powers the site is fast and performant. A seamless and lightweight performance of the maps and statistics data is vital in low-bandwidth environments. In addition to getting the pipeline ready for all our stats need, [Wille Marcel](https://www.hotosm.org/people/wille-marcel/) and I will continue to be looking at ways to load the data faster on the new website.

While working through different ideas, we [capture all our conversations in Github](https://github.com/hotosm/hotosm-website/issues). Do let us know your thoughts on the new changes planned!
