---
title: Filling OSM Buildings Data Gaps in Lebanon
date: 2025-01-07 15:53:00 Z
published: false
Summary Text: Recent conflict has impacted the humanitarian situation in Lebanon.
  With damaged buildings estimated at up to 25% near the southern border, accurate
  data is needed to plan a humanitarian response. HOT is working with volunteers to
  crowdsource the mapping of pre-conflict building footprints to serve as a baseline
  dataset and improve the accuracy of damage estimates.
Feature Image: "/uploads/lebanon_banner.JPG"
Person: Jessica Pechmann
Country:
- Lebanon
- 
---

Following conflict escalation from October 2023 to November 2024, a ceasefire deal was reached between relevant actors on 27 November 2024. As the country begins to recover from the months of war, information on the extent of the damage is needed to inform humanitarian programming. Accurate damage estimates are necessary to estimate economic impact, service disruption, and general shelter needs. A key factor in estimating damage from the conflict is identifying the location of buildings before any were damaged, pre-conflict. Following the principles of our Conflict and Displacement program, we partnered with humanitarian analysts and volunteer mappers around the world to improve the state of pre-conflict building footprints in Lebanon.

### Data Needs

Based on requests from humanitarian analysts needing accurate building footprints for precise damage analyses, HOT did an initial assessment of OpenSteetMap (OSM) and Microsoft Machine Learning (ML) buildings. We found that these go-to data sources for open data lacked the accuracy needed for reliable damage assessments. 

In the case of **[Microsoft ML](https://github.com/microsoft/GlobalMLBuildingFootprints)**, a visual analysis of buildings identified poor precision. Some buildings are missed, and in some cases, multiple buildings are grouped together. Example Microsoft ML buildings in Lebanon: 

<br>
<br>
<div style="text-align: center;">
    <img src="/uploads/lebanon_gaps.png" alt="Map showing data quality issues such as lack of completness and innacurate shapes for Microsoft ML buildings" style="width: 75%; height: auto;">
    <div style="font-size: 0.8em; color: #778899; margin-top: 10px;">
        Map showing data quality issues such as lack of completness and innacurate shapes for Microsoft ML buildings.
    </div>
</div>
<br>
<br>
On the other hand, OSM buildings had major coverage gaps in Lebanon, as seen in the map below of estimated OSM buildings completeness, calculated using Kontur’s [DisasterNinja](https://disaster.ninja/active/map?layers=kontur_lines%2CactiveContributors%2CeventShape%2ChotProjects_outlines%2Cpopulation_density), which takes into account population density vs OSM data availability:

<br>
<br>
<div style="text-align: center;">
    <img src="/uploads/lebanon_gaps2.png" alt="Estimated OSM building Gaps southern Lebanon, Novemeber 2024" style="width: 75%; height: auto;">
</div>
<br>
<br>

### Filling the Data Gap in OSM
 
To create a precise pre-conflict building footprint dataset that’s needed to refine locations of damage detected remotely through satellite, HOT kicked off a crowdsourced mapping project in October 2024 with global volunteers and a growing OSM community in Lebanon.  

By the end of December 2024, over 100 volunteers had already contributed over 150,000 map edits! We anticipate completion of the 3 southern states of Sour, Bent Jbeil, and Marjayoun by early February 2025. We will then review priority areas, but anticipate mapping Jezzine, Saida, El Nabatieh, Hasbaya, and southern Beirut. We’ve been prioritizing areas based on humanitarian requests and initial damage estimates. You can track the progress of areas mapped and validated in this [map](https://umap.openstreetmap.fr/en/map/lebanon-conflict-2024-tasking-manager-project-prog_1132719#10/33.3758/35.2359) (screenshot below as of 6 Jan ‘25), and learn more [here](https://wiki.openstreetmap.org/wiki/Lebanon:_Conflict_-_October_2024). 

<br>
<br>
<div style="text-align: center;">
    <img src="/uploads/lebanon_aoi.png" alt="Area of Interest for Tasking Manager. " style="width: 75%; height: auto;">
    <div style="font-size: 0.8em; color: #778899; margin-top: 10px;">
        Area of Interest for Tasking Manager. Map credits: Tiles courtesy of jawgmaps - Map data © OpenStreetMap contributors, under ODbL. Powered by Leaflet and Django, glued by uMap project (version 2.8.2).
    </div>
</div>
<br>
<br>


### Early Data Improvements in OSM 

The first district completed in the update was Marjayoun, in southeast Lebanon. The data improvement is evident by the increase in of buildings in OSM and compared to Microsoft ML building counts in all of Marjayoun District: 

<br>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Responsive Chart</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
        }

        #chartContainer {
            max-width: 900px;
            margin: 20px auto;
        }
    </style>
</head>
<body>

<div id="chartContainer">
    <canvas id="buildingChart"></canvas>
</div>

<script>
    const ctx = document.getElementById('buildingChart').getContext('2d');
    const buildingChart = new Chart(ctx, {
        type: 'bar', // Use 'bar' for horizontal bars
        data: {
            labels: ['Microsoft ML Buildings', 'OSM, October 2024', 'OSM, January 2025'],
            datasets: [
                {
                    label: 'Microsoft ML Buildings',
                    data: [28905, 0, 0], // Only show data for Microsoft ML Buildings
                    backgroundColor: 'rgba(99, 161, 255, 1)', // Microsoft ML Buildings
                    borderWidth: 1
                },
                {
                    label: 'OSM Buildings', // Label for OSM Buildings
                    data: [0, 4426, 36605], // Only show data for OSM Buildings
                    backgroundColor: 'rgba(255, 94, 118, 1)', // OSM Buildings
                    borderWidth: 1
                }
            ]
        },
        options: {
            responsive: true,
            indexAxis: 'y', // Set indexAxis to 'y' for horizontal bars
            plugins: {
                title: {
                    display: true,
                    text: 'Building Data Comparison',
                    font: {
                        size: 18
                    }
                },
                tooltip: {
                    callbacks: {
                        label: function(tooltipItem) {
                            return tooltipItem.raw.toLocaleString();
                        }
                    }
                }
            },
            scales: {
                x: {
                    beginAtZero: true,
                    title: {
                        display: true,
                        text: 'Number of Buildings',
                        font: {
                            size: 14
                        }
                    },
                    ticks: {
                        callback: function(value) {
                            return value.toLocaleString();
                        }
                    }
                },
                y: {
                    title: {
                        display: true,
                        text: 'Categories',
                        font: {
                            size: 14
                        }
                    }
                }
            }
        }
    });
</script>

</body>
</html>

<br>

The comparison below between Microsoft ML buildings and OSM buildings (post update in this area) show OSM edits have better coverage and precision of buildings shapes. 

<br>
<br>
<div style="text-align: center;">
    <img src="/uploads/lebanon_comp.png" alt="Data comparison in Mais Al-Jabal, Lebanon" style="width: 75%; height: auto;">
</div>
<br>

### Accessing and Using Building Data 

Building footprints are commonly used as a data input in remote damage analyses. With support from the [H2H Network](https://h2hnetwork.org/h2hsupport-package-conflict-lebanon/)’s Lebanon Activation, HOT is working to better understand how OSM buildings are used by partner-led damage analyses. Remote damage analyses differ depending on the leading organization and method (e.g., UNOSAT or the Decentralized Damage Mapping Group). HOT plans to create an overview of different remote damage detection methods to serve as a data-usage guide. The overview will contain information on the data inputs (including OSM), and how the information contained in each output can be used by humanitarians. 

As of now, all map edits are live in OSM. You can access the most updated OSM data through [HOT’s export tool](http://export.hotosm.org/) or [HDX](https://data.humdata.org/dataset/hotosm_lbn_buildings).

**How to get involved**

**Mapping**: If you are interested in mapping (digitizing) buildings in Lebanon, check out HOT’s [Tasking Manager](https://tasks.hotosm.org/) and look for projects in Lebanon! 

**Damage analyses**: If you are a humanitarian data analyst conducting or using damage assessments or OSM data in Lebanon, we’d love to hear from you about your experience at[data@hotosm.org](mailto:data@hotosm.org). We’d also appreciate any input on priority areas to map next. 

**All of HOT’s work in conflict is in line with [HOT’s Data Principles](https://www.hotosm.org/tools-and-data/data-principles/). See our [Program on Conflict & Displacement](https://www.hotosm.org/programs/conflict-displacement) for more information.**