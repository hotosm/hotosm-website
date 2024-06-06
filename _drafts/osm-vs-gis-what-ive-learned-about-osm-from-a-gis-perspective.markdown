---
title: 'OSM vs GIS: What I’ve learned about OSM from a GIS Perspective'
date: 2024-06-06 18:33:00 Z
Summary Text: When I started at the Humanitarian OpenStreetMap Team (HOT) almost three
  years ago, I joined the organization with years of experience using geographic information
  systems (GIS) in the public and humanitarian sectors but little —okay, embarrassingly
  little— experience in OpenStreetMap (OSM).
Feature Image: "/uploads/GISOSMLead.png"
Person: Jessica Pechmann
---

Originally coming from a local government that had been [publishing open geospatial data](https://gis.utah.gov/about/history/) since the early 1980s, when I first heard of OpenStreetMap circa 2012, I didn’t see how it could fit into the GIS world. Fast forward over ten years, and I am excited to be part of the wider adoption of OpenStreetMap by the more “traditional” GIS community, as OpenStreetMap has proven to be a valuable resource for anyone using geospatial data. 

While it's easy to use OSM data in open and proprietary geospatial applications (for example, QGIS, ESRI, etc.), there are still some things to understand about OSM, and I wanted to share my experience to help others facing similar learning curves for anyone curious about either (or both!) technologies.

But first, here are some definitions to make sure we are all on the same page. 

**OpenStreetMap**, or OSM, is a project to build an open, collaborative “map” of the world. This map is built from an extensive open dataset of geospatial data that anyone can add and review. This data can then be queried in multiple ways to be downloaded or viewed as a reference map. 

**Geographic Information Systems**, or GIS, broadly speaking, refers to an approach to analyzing geospatial data, but people often use it interchangeably with desktop or web-based viewing and analysis software that applies it. The “system” consists of the application, user, data, and methods. GIS is a core part of the geospatial technology sector and ties many different types of data, use cases, and applications together. Geographers, data analysts, and many decision-makers use various forms of GIS to analyze and view spatial data. 

For those more familiar with either OSM or GIS, it's always good to identify the different ways the same topic is referred to in both. Here are five broad-strokes differences to know between OSM and GIS:

<table border="2">
<tbody>
<tr>
<td>Topic</td>
<td>In OpenStreetMap </td>
<td>In GIS</td>
</tr>
<tr>
<td>The process of creating spatial data, remotely or by direct observation.</td>
<td>“Mapping”</td>
<td>“Data collection” generally, and “Digitization” for remote data creation with an aerial image.</td>
</tr>
<tr>
<td>Types of spatial data that are used to represent the physical world.</td>
<td>Points (a discrete X & Y coordinate)
Way (a line segment)
Area (a figure made up of an enclosed way) 
Relations (a structured collection of the elements above) </td>
<td>Points
Lines
Polygons
</td>
</tr>
<tr>
<td>Non spatial information about a location </td>
<td>Tags. Features can have any number of tags. 
You can import tags into an attribute table, but you have to specify which tags you are looking for, and some features may not have corresponding tags. 
</td>
<td>Tabular. Each feature in a dataset has a corresponding row in an attribute table with a predefined set of columns for various attributes.</td>
</tr>
<tr>
<td>Data hosting and access</td>
<td>All data is stored in the XML OSM format, and you can access it via different services and export tools. </td>
<td>There is no one data source, and all data is owned and shared by various entities.</td>
</tr>
<tr>
<td>Governance</td>
<td>The (primarily online) OSM community monitors and approves tagging structures, organized editing, etc. </td>
<td>A mix of open and proprietary organizations that manage their own data and the usage of their applications</td>
</tr>
</tbody>
</table>
<br>

Why are the systems so different? That would be for another blog post, but it has to do with the backend of OSM being different and 20 years of grassroots open-source growth. These technological advances have made OSM more usable and accessible than ever. But it wasn’t until I started this job that I had to learn the technical opportunities OSM gives to humanitarian partners. After all, it was my job to promote OSM in the sector. In these conversations, I realized that now it is really easy to access OSM data in a GIS format. In addition, the nature of OSM provides unique opportunities to crowdsource (virtually and by direct observation) data, something that is always needed in the sector. 

![GISOSM.png](/uploads/GISOSM.png)
<figcaption align = "left"><h6>Global development of first activities of mappers in OpenStreetMap. Shading ranges from transparent to yellow to indicate the amount of first changesets per cell. From: <a href="https://link.springer.com/article/10.1007/s10708-021-10547-7">De/colonizing OpenStreetMap? Local mappers, humanitarian and commercial actors, and the changing modes of collaborative mapping.</a></h6></figcaption">
<br>
So, with that in mind, I want to share my Five Reasons to use OSM in GIS:

1. GIS people love data sharing. OSM is one common data source that anyone from any platform, sector, and location can access. The more we as a geospatial community invest and use it, the better for everyone. Check out [Rapid](https://wiki.openstreetmap.org/wiki/Rapid) to easily edit OSM in ESRI products or the open JOSM application. 

2. OSM’s geographic coverage. Created by the commons, and not solely funded by one source or interest, OSM can be more complete in many parts of the world, and of higher quality as people with direct local knowledge of the area contribute to the data.

3. The human perspective is still important. While AI has increased accuracy in image detection algorithms, accurately identifying everything still requires a human eye. Some information is only available locally, such as the name of a health center or classification of a water supply. OSM offers great crowdsourcing opportunity from global virtual volunteers to local communities. For example, detailed mapping of small internally displaced shelters in Somalia. 

4. Completely open data means you don’t have to worry about use restrictions. [Learn more](https://www.openstreetmap.org/copyright).  

5. OSM data access in GIS is easier than ever. There are tools that allow you to export data from OSM into GIS format with an attribute table. Some of my favorites are:

<ul>
  <li><a href="https://export.hotosm.org/v3/">HOT export tool</a>: best for custom exports worldwide</li>
  <li><a href="https://data.humdata.org/organization/hot?">HDX HOTOSM Exports</a>: download OSM data, humanitarian user target audience</li>
  <li><a href="https://www.arcgis.com/home/group.html?id=66d66956ab444ae89e8265f008704d4b#overview">ESRI Feature services</a>: You can even add ESRI feature services to <a href="https://www.geographyrealm.com/how-to-add-data-from-arcgis-online-to-qgis/">QGIS</a></li>
<li><a href="https://gisgeography.com/qgis-openstreetmap/">QGIS OSM Plugins</a>: check out QuickOSM.
<a href="https://link.springer.com/article/10.1007/s10708-021-10547-7)De/colonizing OpenStreetMap? Local mappers, humanitarian and commercial actors, and the changing modes of collaborative mapping.</a>
</ul>
<br> 

Are you someone who started in QGIS or ArcGIS and started to learn more about OSM? What surprised you? What am I missing?
