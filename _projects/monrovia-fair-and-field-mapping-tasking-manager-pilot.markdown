---
title: Monrovia - Improving Map Quality using fAIr & Field Mapping Tasking Manager
  - Pilot
date: 2024-04-17 09:33:00 Z
published: false
tags:
- tech
- fmtm
- fair
- e2e
Project Summary Text: HOT is currently employing fAIr technology to digitize a specific
  area within Monrovia, Liberia. This effort is conducted in partnership with the
  local Liberian team and WNAH. The digitization process utilizes drone imagery that
  we are promptly acquiring in preparation for a household enumeration project. This
  project is facilitated through the HOT Field Mapping Tasking Manager, administered
  by our partner, Slum Dwellers International.
Feature Image: "/uploads/fair-fmtm-monrovia-osm-footprints.jpg.jpg"
Country:
- Liberia
Impact Area:
- Disasters & Climate Resilience
Person:
- Ivan Buendía Gayton
Partner:
- sdi
Tools:
- tool: Field Mapping Tasking Manager
---

<h3>Context</h3>

Slum Dwellers International is currently undertaking a significant project, supported by the World Bank, involving a team of 60 individuals deployed in the field for a duration of three months. The objective of this project is to conduct house-to-house enumeration surveys within a crucial context for the HOT West and North Africa Hub, specifically focusing on informal settlements in Monrovia. Notably, the project benefits from two sets of drone imagery with a resolution of 5 cm, captured in 2019 and 2024 (between February 27th and 29th) respectively, utilizing a local Mavic 2 drone. These imagery sets are meticulously georeferenced to each other.

Covering an area of 1.5 square kilometers, the targeted region encompasses approximately 6,000 buildings. Initial digitization efforts within a sub-area of 0.17 square kilometers yielded 650 buildings, providing a basis for extrapolating the total number of buildings within the entire area.

![Monrovia AOI](/uploads/fair-fmtm-monrovia-aoi.jpg)
*Area overview showing the extent of 2014 drone imagery and initial manual digitization*

<h3>Need for Digitization</h3>

Selecting a discrete building from typical OSM digitization is difficult; most of the time there’s not a great 1:1 correspondence between building footprints and actual structures. With the digitization seen above, the local mappers are—for the most part—easily and accurately locating and selecting the appropriate buildings.

However, there’s a lot more area still to be covered, and this is a great opportunity to use fAIr in collaboration with a local community.

![Monrovia AOI OSM](/uploads/fair-fmtm-monrovia-basemap.jpg.jpg)
*A cursory glance at the OSM coverage for this part of Monrovia (New Kru Town) would seem to indicate that it’s “complete,” at least in the sense that the area is full of digitized building footprints. Unfortunately, a closer look reveals that it’s not as good as it may seem.*

Buildings are quite visible and clear in the drone imagery. When we overlay the OSM digitized building footprints, we immediately see that many buildings are missed, and the footprints that do exist don’t match the visible buildings very well. For field mapping purposes, a mapper needs to arrive at a building in the real world, identify its corresponding footprint, select it, and proceed with their survey. When the footprints don’t match the buildings, this is impossible. A few mismatches are tolerable; a missed building here, a group of buildings digitized as a single structure there, or an offset footprint that’s near but not precisely aligned with the actual structure are OK. But in the case of New Kru Town―and the majority of informal settlements around the world—the correspondence between buildings and OSM digitized footprints isn’t better than 50%. We need to do better to support selection of buildings for addition of local information attributes in the field using mobile data collection. 

![Monrovia AOI OSM Footprints](/uploads/fair-fmtm-monrovia-osm-footprints.jpg.jpg)
*The existing digitization of Monrovia’s informal areas in OpenStreetMap is not fit for purpose for field mapping. The correspondence between structures and polygons is not close enough.*

We do not often have sets of similarly-georeferenced, high-resolution imagery from different times in exactly the same location. Urban changesets are a product in massive demand from many data users (not to mention donors) and we have very few practical opportunities to generate them at this high a resolution and quality level (note that the 2014 imagery was acquired using a cheap DJI Mavic 2 belonging to a local person, not with an expensive mapping-specific drone, but it was done using the best practices from HOT’s experience gather local drone imagery with inexpensive devices). 

![FMTM-Explanation.jpg](https://cdn.hotosm.org/website/FMTM-Explanation.jpg)
*A project manager who has just created an FMTM project on their laptop demonstrates to a field mapper how they can select their assigned buildings on their phone*

<h3>Implementation</3>

<h4>FMTM</h4>

The Liberian team is doing household enumeration surveys, and have been trained using the FMTM to locate each precise building on the map, select it, and complete a detailed form that resembles a long-form census. There is a lot of value in the addition of the building selection; it ties the data to a specific structure, vastly reduces (practically to the point of elimination) duplication and missed structures, and creates a powerful advocacy tool for the local residents seeking better recognition and services for their community. 

![Monrovia AOI](/uploads/fair-fmtm-monrovia-aoi-zoom.jpg.jpg)
*Undigitized area at 1:300 scale; most of the AOI looks a lot like this and needs digitization*

<h4>fAIr</h4>

A model was trained from the more recent 2024 imagery, and another from the building footprints on the 2019 imagery, giving us what will likely be one of the first practical uses of AI to quantify change in informal urban areas. 

![Monrovia Timelaps](/uploads/fair-fmtm-monrovia-timelaps.gif)
*There’s a great deal of change in 5 years. In this typical small area of New Kru Town in Monrovia, six structures have been demolished, five have been newly constructed, and most have changed some or all of their roofing material.*


