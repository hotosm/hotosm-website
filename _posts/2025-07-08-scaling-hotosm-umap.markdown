---
title: 'Scaling HOT''s uMap: Exciting Updates for Humanitarian Geospatial Data Visualization
  and Use'
date: 2025-07-08 15:28:00 Z
published: false
---

As any mapper knows, the way you choose to visualize and use your geospatial data is the key to a successful mapping project. Having an accessible, flexible, and dependable tool has the potential to facilitate this process. This is why we are moving forward with [our own instance of uMap](umap.hotosm.org). 

## uMap: A Perfect Fit for Map Data Visualization & Use

[uMap](https://umap.openstreetmap.fr/en/) is a free and open source online map application, initially created by Yohan Boniface and hosted by OpenStreetMap (OSM) France. With uMap, users can create their own maps using customized data, symbology, and layers. HOT's Tech team analyzed various open source tools for map display and use, and determined that uMap best meets our needs due to its ease of use, flexibility, and customization options.

Having our own uMap instance (to which we will temporarily refer to as "HOT's uMap") offers more control over the platform, enabling customization for our mission. It allows for the integration of features such as connecting to [OpenAerialMap](https://openaerialmap.org/) imagery, creating teams, and providing custom humanitarian data visualization templates. Here's a deeper look into these features:

### Templates: Simplifying Data Visualization

One of the latest additions to uMap is initial templates, which provide a starting point for common use cases. We're developing a set of initial templates **specifically designed for humanitarian and disaster relief situations**. This feature will help users create maps with minimal setup, focusing on visualizing their data effectively, lowering the barrier for map visualization and use.

<iframe width="100%" height="300px" frameborder="0" allowfullscreen allow="geolocation" src="//umap.hotosm.org/en/map/damage-mapping-for-flooding_353?scaleControl=false&miniMap=false&scrollWheelZoom=false&zoomControl=true&editMode=disabled&moreControl=true&searchControl=null&tilelayersControl=null&embedControl=null&datalayersControl=true&onLoadPanel=caption&captionBar=false&captionMenus=true"></iframe><p><a href="//umap.hotosm.org/en/map/damage-mapping-for-flooding_353?scaleControl=false&miniMap=false&scrollWheelZoom=true&zoomControl=true&editMode=disabled&moreControl=true&searchControl=null&tilelayersControl=null&embedControl=null&datalayersControl=true&onLoadPanel=caption&captionBar=false&captionMenus=true">See full screen</a></p>

### Integrations: Unlocking the Full Potential

To integrate HOT's uMap with our [ChatMap tool](http://chatmap.hotosm.org) (for generating maps using instant messaging apps such as WhatsApp), we added a new feature to enable seamless data transfer between the two platforms. This integration has already shown its value in real-world scenarios. We're now exploring further integrations with HOT products like [OpenAerialMap](https://openaerialmap.org/) and [Drone Tasking Manager](https://dronetm.org/).

<iframe width="560" height="315" src="https://www.youtube.com/embed/QHuV4aE9VIg?si=7P9rP4z-VWKjYjKO" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

## Future Plans: Expanding HOT's uMap Capabilities

We aim to enhance HOT's uMap by adding new core functionalities, including supporting multiple backgrounds, both raster and vector, allowing for layer management and timeline visualization. These improvements will make HOT's uMap an even more powerful tool for data visualization and map creation. Using the importer, people can write an OSM tag and easily get data from OSM. 

For example, in the case of the flood disaster template at the beginning of this article, you can import damaged buildings (damage=*). Now, we want to add other importers that will get data from HOT products. See our GitHub repository with future plans [here](https://github.com/hotosm/umap/tree/6a3ee137517155700689e6a6d34b38aaaf8c7fff).


## Building a Comprehensive Mapping Platform

By incorporating templates, data connectors, integrations, and new core functionalities, we'll create a robust open platform for humanitarian and climate mapping. This expanded version of uMap will enable users to visualize, interact with, and share geospatial data effectively, driving meaningful decision-making in the humanitarian and climate sectors.

## HOT's uMap in Action
See practical examples of uMap in action, 
* [Myanmar earthquake](https://umap.hotosm.org/en/map/myanmar-earthquake-2025-tasking-manager-projects_161#8/21.282/97.130) 
* [Collaborative Mapping Workshop for Teachers in Mexico](https://www.hotosm.org/updates/cultivating-open-knowledge-collaborative-mapping-workshop-for-tec-de-monterrey-teachers-and-librarians/)
* [Mapping Dhaka’s Informal Settlements for Climate Resilience and Urban Development](https://www.hotosm.org/updates/mapping-dhakas-informal-settlements-for-climate-resilience-and-urban-development/)
* [Sudan Data Gaps](https://umap.hotosm.org/en/map/sudan-data-gaps-map_84#6/16.046/30.333)
* [Luján Floods](https://umap.hotosm.org/en/map/lujan-inundaciones-mayo-2025_247)
* [Improving access to healthcare services for women and girls in the Matam region of Senegal](https://umap.hotosm.org/en/map/improving-access-to-healthcare-services-for-women-_174)

## Completing the Workflow: HOT’s uMap as part of out End-To-End Open Mapping Solution

HOT’s instance of uMap is a key part of the HOT’s Tech team end-to-end mapping workflow, which includes solutions for generating and using geospatial data, from creating aerial imagery to digitization, enrichment with local knowledge, and easy access. Make sure to [check out the full range of our tools](https://www.hotosm.org/tech-suite) and see how HOT's uMap fits into the full workflow.

----
**Are you a developer and/or do you want to contribute?** Check out the project’s [GitHub repository](https://github.com/hotosm/umap) or [write to us.](mailto:tech@hotosm.org)


