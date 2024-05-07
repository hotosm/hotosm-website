---
title: Our End-to-End Mapping Solution , Mapping exercise at CliGeos Summer School
date: 2024-04-23 20:45:00 Z
tags:
- tech
- e2e
Summary Text: In April 2024, we had the opportunity to demonstrate the power of open
  mapping tools and workflows at the CLImbing for CLImate GEOspatial School (CLIGEOS-2024)
  in Annapurna-3, Lumle-Pokhara, Nepal.
Feature Image: https://www.hotosm.org/uploads/CLIGEOS-2024-fAIr.png
Person: Kshitij Sharma
Country:
- Nepal
---

<head>
<style>
.row::after {
  content: "";
  clear: both;
  display: table;
}
.column {
  float: left;
  width: 50%;
  padding: 5px;
}
@media screen and (max-width: 500px) {
  .column {
    width: 100%;
  }
}
.align { 
  display: block;
  margin-left: auto;
  margin-right: auto;
  width: 120%;
}
.align2 { 
  display: block;
  margin-left: auto;
  margin-right: auto;
  width: 100%;
}
.align3 { 
  display: block;
  margin-left: auto;
  margin-right: auto;
  width: 80%;
}
.align3 { 
  display: block;
  margin-left: auto;
  margin-right: auto;
  width: 70%;
}
.center {
  display: block;
  margin-left: auto;
  margin-right: auto;
  width: 80%;
}
</style>
</head>

This summer school was jointly organized by the Center for Space Science and Geomatics Studies (CSSGS) at Tribhuvan University, the University of Udine in Italy, and LJ University in India The primary goal was to train participants from diverse backgrounds, including students, geospatial professionals, and government representatives, on conducting an end-to-end mapping exercise using open-source software. We aimed to showcase how these tools can support decisions around climate change challenges. With the help of the organizing team and more than 30 participants, we were able to carry out the entire end-to-end mapping workflow. 

<br>

> <h3>“With the help of the organizing team and more than 30 participants, we were able to carry out the entire end-to-end mapping workflow.” </h3>

<br>

# Area of Interest 

<br>

The area for our exercise was the beautiful, diverse perimeter of the Agriculture Research Center, located approximately 20 km northwest of Pokhara. This area, outlined on OpenStreetMap [(OSM/way/742793744)](https://www.openstreetmap.org/way/742793744), is situated in Lumle, a town in the Annapurna Rural Municipality, Kaski District, in the Gandaki Zone of northern-central Nepal. Lumle is known for being the highest rainfall area in Nepal and relies on its hilly terrain with beautiful views.

<br>
<div class="row align">
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-flower.png" alt="flower">
  </div>
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-porters.png" alt="porters" style="width:48%">
  </div>
</div>
<figcaption align = "center"><h6>Left: National flower Rhododendron - Photographer Beneesh Shrestha <br> Right: Farmers carrying organic manure to field seen during our field exercise <br>photo by Ritika Sunar  </h6></figcaption><br>
<br>

# Step-by-Step Approach

<br>
<br>

**STEP 1 - Acquire base & sensor data**

----

<br>
- OpenDroneMap (ODM): [website](https://openaerialmap.org/)<br/>
- HOT OpenAerialMap (OAM):[Product Page](/tech-suite/open-aerial-map) - [website](https://openaerialmap.org/) - [docs](https://docs.hotosm.org/)


<br>
<strong>Drone Data Collection:</strong> We flew a Phantom 4 RTK Multispectral drone over the testing area to collect recent, high-resolution aerial imagery. The drone's multispectral capabilities allowed us to capture data across multiple spectral bands, including the Near-Infrared (NIR) band, which is useful for vegetation analysis.

<br>
<div class="row align2">
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-drone-demonstration.png" alt="Drone demostration" style="width:100%">
  </div>
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-drone-lecture.png" alt="Drone lecture" style="width:100%">
  </div>
</div>
<figcaption align = "center"><h6>A HOT Staff member, Kshitij demonstrating how drone work  and how to capture imagery.</h6></figcaption><br>
<br>

<strong>Drone Data Processing:</strong> The raw drone imagery was processed using OpenDroneMap (ODM), an open-source photogrammetry toolkit. ODM allowed us to generate valuable data products from the imagery, such as Digital Surface Models (DSMs) representing the elevation of objects and surfaces, Digital Terrain Models (DTMs) representing the bare earth terrain, a six-band orthophoto with visible and NIR bands, and indices like the Normalized Difference Vegetation Index (NDVI).

<br>
<div class="row align2">
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-lecture.png" alt="Lecture in progress" style="width:100%">
  </div>
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-OAM.png" alt="Analysis of Aerial Imagery" style="width:100%">
  </div>
</div>
<figcaption align = "center"><h6>Walking through the steps and instructions to process drone image and upload</h6></figcaption><br>
<br>

<strong>OpenAerialMap Upload:</strong> The processed orthophoto was uploaded to [OpenAerialMap](https://openaerialmap.org/), an open repository for aerial imagery. Uploading the data to OpenAerialMap makes it accessible with the broader community, including everyone at the school.

<br>

**STEP 2 - Process based & sensor data**

----

<br>
- HOT Tasking Manager (TM): [Product Page](/tech-suite/tasking-manager) - [website](tasks.hotosm.org) - [docs](https://hotosm.github.io/tasking-manager/)<br/>
- HOT fAIr: [Product Page](/tech-suite/fair) - [website](https://fair-dev.hotosm.org/) - [docs](https://docs.hotosm.org/)
<br>
<br>

<strong>Tasking Manager Project:</strong> Using the orthophoto hosted on OpenAerialMap, we created a project on the [HOT Tasking Manager dev server link](https://tasks-dev.hotosm.org/projects/5). The Tasking Manager is a collaborative mapping tool that divides an area into smaller tasks, enabling distributed mapping by multiple participants.

<strong>Remote Mapping and Validation:</strong> A total of 30 participants contributed to remotely mapping the testing area by tracing building footprints, roads, and other features visible in the orthophoto. Participants also validated each other's work to ensure accuracy and completeness of the data..

<br>
<div class="row align">
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-task.png" alt="Tasking Manager">
  </div>
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-workshop.png" alt="Workshop participants" style="width:63%">
  </div>
</div>
<figcaption align = "center"><h6>Participants doing remote mapping using Tasking Manager </h6></figcaption><br>
<br>

<strong>Local AI Model Creation:</strong> Using the manually traced remote mapping data as training data as input for AI modeling,, we created a [local AI model link](https://fair-dev.hotosm.org/ai-models/143) specific to our testing area. This model can be used for AI-assisted mapping tasks in similar contexts, potentially accelerating the mapping process, allowing to map in an AI-assisted way, in which the AI generates the new features which can then we validated by humans..


<br>
<div class="center">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-fAIr.png" alt="fAIr results">
</div>
<figcaption align = "center"><h6>A HOT Staff member, Kshitij demonstrating how drone work <br> and how to capture imagery.</h6></figcaption><br>
<br>



**STEP 3 - Add local knowledge to the data**

----


<br>
- HOT Field Mapping Tasking Manager (FMTM): [Product Page](/tech-suite/field-mapping-tasking-manager) - [website](https://fmtm.hotosm.org/) - [docs](https://fmtm.dev/)<br/>
- ODK Collect: [website](https://getodk.org/) 
<br>
<br>

<strong>Field Mapping Tasking Manager:</strong> To incorporate local knowledge and ground-level details, we established a [Field Mapping Tasking Manager project link](https://fmtm.hotosm.org/project_details/MTAxMTAxMA==). This tool allows for the creation of custom data collection forms and divides the area into tasks for field mapping.


<br>
<div class="center">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-FMTM.png" alt="FMTM tasks">
</div>
<figcaption align = "center"><h6>Participant locking tasks before heading towards field mapping</h6></figcaption><br>
<br>

<strong>Data Collection in the Field:</strong> Participants used mobile devices with the ODK Collect app to conduct field mapping within the testing area. They collected additional data points and attributes based on a custom survey form, such as building materials, vulnerability to erosion, and the number of people residing in each building. This local knowledge complemented the remote mapping data. 

<br>
<div class="row align3">
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-building.png" alt="Drone demostration" style="width:100%">
  </div>
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-survey.png" alt="Drone lecture" style="width:100%">
  </div>
</div>
<figcaption align = "center"><h6>Participants collecting field data using FMTM, Asking house owners for the information</h6></figcaption><br>
<br>

**STEP 4 - Make map data accessible**

----

<br>
- HOT Export Tool: [Product Page](/tech-suite/export-tool) - [website](https://export.hotosm.org/v3/) - [docs](https://github.com/hotosm/osm-export-tool)
<br>
<br>

<strong>Data Download (OSM Export Tool):</strong> To consolidate and access the mapping data, we used the [OSM Export Tool link](https://export.hotosm.org/v3/exports/eecdb3b1-b690-40b9-b8db-dc6a898eef1b) to download the OpenStreetMap data for the project area.
<br>
<br>
<div class="center">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-export-tool.png" alt="Export tool">
</div>
<figcaption align = "center"><h6>Export containing the data from the field survey</h6></figcaption><br>
<br>


**STEP 5 - Analyze map data for impact**

----
<br>
- QGIS: [website](https://www.qgis.org/en/site/)
<br>
<br>

<strong>QGIS Visualization and Analysis:</strong> Participants loaded the downloaded remotely mapped data, field mapped data, and data collected from aerial surveys into QGIS, an open-source geographic information system (GIS) software. Within QGIS, they visualized and analyzed the data, including creating 3D visualizations of the buildings and visualizing plant health. Not all data collected from the field necessarily needed to be uploaded to OpenStreetMap. Therefore, participants performed data cleaning and processing within QGIS itself. They downloaded the Field Mapping Tasking Manager (FMTM) data as a GeoJSON file directly from the FMTM services for further analysis and integration with other datasets.

<br>
<div class="row align">
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-analysis.png" alt="Data layers on GIS program" style="width:100%">
  </div>
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-data-collected.png" alt="Data collected in the field" style="width:80%">
  </div>
</div>
<figcaption align = "center"><h6>Left: Visualization of remotely mapped data and drone data <br>Right: Data collected from the field</h6></figcaption><br>
<br>

<strong>Group Projects:</strong> The participants were divided into groups to work on specific projects utilizing the generated data. These projects focused on identifying vulnerable areas, assessing disaster risk, and exploring the potential impact of climate change on the local community.


<br>
<div class="row alig3">
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-visualization.png" alt="Group presentations" style="width:100%">
  </div>
  <div class="column">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-methodology.png" alt="Methodology" style="width:100%">
  </div>
</div>
<figcaption align = "center"><h6>One of the group presenting their work based on the data collected</h6></figcaption><br>
<br>

Throughout the exercise, participants actively engaged in hands-on activities, ranging from drone operation and data collection to remote and field mapping, data processing, and analysis using open-source tools like QGIS.

<br>


**Conclusion**

----


<br>

This end-to-end mapping exercise at CLIGEOS-2024 demonstrated the effectiveness of using free and open-source tools in a collaborative environment to conduct comprehensive mapping activities. <strong>Within a short time frame and at a low cost, we were able to generate valuable geospatial data, including orthophotos, digital surface models, vegetation indices, local AI models, and both remote and field mapping data.</strong> The collaborative nature of tools like the HOT Tasking Manager , Field Mapping Tasking Manager and Local Model predictions from fAIr enabled efficient task allocation and resource utilization, maximizing the collective efforts of the participants.


<br>
<div class="center">
    <img src="https://www.hotosm.org/uploads/CLIGEOS-2024-group.png" alt="Participants">
</div>
<figcaption align = "center"><h6>Team and Participants of Summer School</h6></figcaption><br>
<br>

The success of this exercise highlights the potential of open mapping workflows to support climate change objectives, community resilience, and sustainable development initiatives. 

<br>

> <h3>“By empowering local communities with accessible tools and knowledge, we can foster data-driven decision-making and improve preparedness for environmental challenges. “ </h3>

<br>

We are thankful for the organizers and the International Society for Photogrammetry and Remote Sensing (ISPRS), for giving us this opportunity to perform the entire activity, and we look forward to many more such opportunities in the future. I would also like to thank members of OSGeo Nepal for helping us troubleshoot technical problems during the activity  and the energy and commitment of all participants truly made this a successful and rewarding experience.

<br>
----

🌟 Kshitij Raj Sharma 🌟

