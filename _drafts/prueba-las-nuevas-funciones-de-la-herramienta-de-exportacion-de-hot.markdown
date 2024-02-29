---
title: "¡Prueba las nuevas funciones de la Herramienta de Exportación de HOT!"
date: 2024-02-29 19:10:00 Z
---

If you are looking for reliable OSM data in various file formats that are easy to download in a few easy steps and a couple of minutes, new features have been added to the [HOT Export Tool](https://export.hotosm.org/en/v3/)!  HOT’s developer, Kshitij, has been working for a number of months on these improvements, and we want to send a huge thanks to him!

Watch the Walkthrough that will guide you through all the features and explore them yourself! If you have any feedback, get in touch by adding an issue to [Github](https://github.com/hotosm/osm-export-tool) or joining #export-tool [Slack channel](https://slack.hotosm.org/).

<iframe width="560" height="315" src="https://www.youtube.com/embed/vxEDFAVfOTo?si=kdBJGdubn3UrqdnS" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

We have also explained all the updates below with screenshots.

**1. Export OSM Data with three new formats (FlatGeobuf, CSV, and SQL)**

* **Flat Geobuf** output is very fast compared to shapefile, enabling users to do spatial operations with spatial indexes. Export Tool now provides OSM data in flageobuf format
* **CSV** output will be useful for the data analyst and anyone interested in using osm [tagging](https://wiki.openstreetmap.org/wiki/Tags) data in their research/ work/education.
* **SQL** output will be very useful for programmers/visualizers who want to run their own queries and enable spatial analysis using the powerful features of PostGIS.

**2. Download everything in the Area**

The Export tool updates introduce a new feature allowing users to download all available OSM features within the area. You can utilize this Download all OSM data checkbox listed in the Data tab. This will include all tags in the attributes, allowing you to filter the data you need or create a basemap out of exported features.

![Export 1.png](/uploads/Export%201.png)


**3. Get HOT Tasking Manager project boundary on export tool**

Now, the Export Tool can support Tasking Manager Project ID as input directly to the search bar. The Project ID should be followed by the tm word. When a user selects a tasking manager project ID as an area of interest, OSM data associated with that project will be exported. 

![Export 2.png](/uploads/Export%202.png)

**4. Load individual OSM features as a boundary**

The export tool also now provides you an option to export data inside individual [OSM relation](https://wiki.openstreetmap.org/wiki/Relation) features. For example, to bring this [municipality boundary](https://www.openstreetmap.org/relation/6104486#map=11/28.2094/83.9733) from osm to the export tool, you can simply type OSM and its id like the following and export your required features.

![Export 3.png](/uploads/Export%203.png)

**5. Get your export area quick info before making an actual export request**

The export tool has a new feature called data completeness information. When you create a geom or upload in the export tool, after a couple of seconds, you will see information just above the system timestamp. We call it data completeness metrics possible through various sources can be found as listed [here](https://github.com/hotosm/raw-data-api/blob/develop/docs/src/stats/indicators.md). It will give a quick peek about the area where you are planning to export! 

![Export 4.png](/uploads/Export%204.png)

**6. OSM Oauth2.0 implementation**

We have implemented oauth2.0 authentication for OSM. This means this is a big change in terms of the way you login. You will need to log out first and then log in again to the export tool, and everything else should work as it used to! You will see a banner like the following on your screen.

![Export 5.png](/uploads/Export%205.png)

**7. New backend for the Export Tool: Raw Data API  (exciting news for developers), Area threshold has been increased by 50%**

Raw Data API (https://github.com/hotosm/raw-data-api/) now serves as a new backend to the OSM Export tool for all the selected formats in the attached image. I.e., GeoJSON, Shapefile, Geopackage, Google Earth KML, Flatgeobuf, and CSV. The area threshold for those formats has also been increased by 50%. You can access API documentation [here](https://api-prod.raw-data.hotosm.org/v1/redoc). Github link [here](https://github.com/hotosm/export-tool-api) and new [architecture diagram](https://miro.com/welcomeonboard/OFIxRlBWUHU0bmIyb2FPZkJqSDhYVzc1ektqZDFzSXRJU1VHTTdYRVlraFVkNUVmUTcweHRvZXRwTDJKZ0ZsMnwzNDU4NzY0NTE1MDkwMjQ0MzIzfDI=?share_link_id=26271906711). The new API enables you to perform country exports, custom exports and also data completeness metrics for the Area. Garmin, OSM, and OSMAnd format are not yet available through the API and may not be as performant as others.

fAIr, the HOT Tasking Manager, and FMTM already use the raw data API, SQL, and Mbtiles! This new backend integration will give you faster outputs for those selected file formats.

![Export 6.png](/uploads/Export%206.png)

**What more can you expect from the export tool?**

We plan to publish another blog about data exports at the country level and its related enhancement to HDX datasets. As always, we would love to hear from you and what you think of these new developments!  We would also welcome contributions from people to improve the Export Tool documentation [here](https://github.com/hotosm/osm-export-tool/tree/master/ui/app/components/help).
Join the #export-tool Slack channel or get in touch with [Kshitij](mailto:kshitij.sharma@hotosm.org) if you have any questions or want to send a note of appreciation!
