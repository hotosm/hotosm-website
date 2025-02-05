---
title: Geospatial Data for Humanitarian Response in Sudan Conflict
date: 2024-10-25 18:48:00 Z
Project Summary Text: Amid Sudan’s crisis, a global effort led by HOT, with support
  of the H2H Network and the Sudanese diaspora, is transforming fragmented maps into
  a better response. By connecting local knowledge with tech, we are creating data
  and maps that can support humanitarian organizations deliver aid where it's needed
  most.
Feature Image: "/uploads/Khartoum_ISS010E23451_lrg.jpg"
Country:
- Sudan
Impact Area:
- Disasters & Climate Resilience
Person:
- Jessica Pechmann
- Geoffrey Kateregga
Partner:
- H2H
- OSM Sudan
- HDX
Duration:
  Start Date: 2024-06-16 00:00:00 Z
  End Date: 2025-02-16 00:00:00 Z
Tools:
- tool: Tasking Manager
- link: 
- Tool: uMap
---

---
<div>
  <h2>Table of Contents</h2>
  <ol style="color: black;">
    <li><a href="#background" style="color: black;">Background</a></li>
    <li><a href="#understanding-the-geospatial-gaps-in-sudan" style="color: black;">Understanding the Geospatial Gaps in Sudan</a></li>
    <li><a href="#the-role-of-the-sudanese-diaspora" style="color: black;">The Role of the Sudanese Diaspora</a></li>
    <li><a href="#participatory-mapping-to-leverage-local-knowledge" style="color: black;">Participatory Mapping to Leverage Local Knowledge</a></li>
    <li><a href="#innovative-tools-for-data-consolidation" style="color: black;">Innovative Tools for Data Consolidation</a></li>
    <li><a href="#building-trust-through-ethical-mapping" style="color: black;">Building Trust Through Ethical Mapping</a></li>
    <li><a href="#data-access-and-use" style="color: black;">Data Access and Use</a></li>
    <li><a href="#whats-next-upcoming-work-and-focus-areas" style="color: black;">What’s Next? Upcoming Work and Focus Areas</a></li>
    <li><a href="#conclusion" style="color: black;">Conclusion</a></li>
    <li><a href="#get-involved" style="color: black;">Get Involved</a></li>
  </ol>
</div>

---

## Background 

The humanitarian crisis in Sudan has reached a scale that requires innovative, collaborative, and data-driven solutions. As the conflict continues into 2025, millions of Sudanese face access to food, healthcare, and essential services. The conflict has also created the largest internal displacement crises globally, with millions of internally displaced persons (IDPs) and refugees spread across an increasingly fragmented landscape.

In such a context, reliable geospatial data becomes not just useful but life-saving. To bridge critical information gaps, the **Humanitarian OpenStreetMap Team (HOT)**, supported by the **H2H Network**, has initiated a project to enhance Sudan’s mapped infrastructure and geographies. By addressing deficiencies in road networks, populated places, and cultural information, this initiative provides aid organizations with the tools they need to reach vulnerable populations and understand the impact on the ground. Crucially, the project is also incorporating the expertise of Sudanese diaspora communities, whose local knowledge offers insights into the geography and cultural nuances of the region.

---

## Understanding the Geospatial Gaps in Sudan
Sudan’s vast and diverse geography, combined with the ongoing conflict, has exacerbated challenges in acquiring accurate and actionable data. 

- **At least 63% Buildings** of buildings in OSM are missing in 2024 according to estimates by <a href="https://www.kontur.io/solutions/disaster-ninja/">Kontur</a>. The lack of reliable data can affect the efficiency of humanitarian efforts like aid delivery, and damage estimates for instance.   
- **Roads** in remote areas are poorly mapped, and existing road datasets for urban centers often lack critical details like surface type or accessibility.  
- **Rural regions** face a near-complete absence of reliable geospatial data, hampering the ability of humanitarian organizations to plan logistics or assess infrastructure damage.

Beyond the physical terrain, another critical dimension is often overlooked: **cultural and administrative data**. Place names, boundaries, and locally significant landmarks—essential for contextualized humanitarian response—are frequently missing or mislabeled in existing datasets. This disconnect is not merely technical; it risks creating a mismatch between the aid provided and the communities' actual needs to recover.
<br>
### OSM Building Completness Estimates Map
<iframe width="120%" height="610px" frameborder="0" allowfullscreen allow="geolocation" src="//umap.hotosm.org/en/map/sudan-completeness-map_84?scaleControl=false&miniMap=false&scrollWheelZoom=false&zoomControl=true&editMode=disabled&moreControl=true&searchControl=null&tilelayersControl=null&embedControl=null&datalayersControl=true&onLoadPanel=caption&captionBar=false&captionMenus=true"></iframe><p><a href="//umap.hotosm.org/en/map/sudan-completeness-map_84?scaleControl=false&miniMap=false&scrollWheelZoom=true&zoomControl=true&editMode=disabled&moreControl=true&searchControl=null&tilelayersControl=null&embedControl=null&datalayersControl=true&onLoadPanel=caption&captionBar=false&captionMenus=true">See full screen</a></p>
<div style="text-align: center;">
    <div style="font-size: 0.8em; color: #778899; margin-top: 10px;">
        Interactive map depicting Data Gaps and OSM completness based on AI estimates by <a href="https://www.kontur.io/solutions/disaster-ninja/">Kontur</a>. These numbers are a rough guide on completness, and are only used to drive inform the priority areas for mapping. Additional layer called "confidence_null_buildings" shows the total sum of buildings with no confidence in Overture data. 
    </div>
</div>

<br>
<br>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Building Dataset Completeness</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        #chartContainer {
            max-width: 800px;
            margin: 0 auto;
        }
    </style>
</head>
<body>

<div id="chartContainer">
    <canvas id="buildingChart"></canvas>
</div>

<script>
    const data = [
        { label: 'OSM', value: 1476231 },
        { label: 'Microsoft', value: 10313711 },
        { label: 'Overture', value: 25848372, components: { osm: 1529984, microsoft: 7295229, google: 17023159 } },
        { label: 'Google', value: 26619729 }
    ];

    // Sort data in ascending order
    data.sort((a, b) => a.value - b.value);

    const ctx = document.getElementById('buildingChart').getContext('2d');
    const buildingChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: data.map(item => item.label),
            datasets: [
                {
                    label: 'OSM',
                    data: data.map(item => (item.label === 'OSM' ? item.value : (item.label === 'Overture' ? item.components.osm : 0))),
                    backgroundColor: '#8ED587',
                    stack: 'Stack 0'
                },
                {
                    label: 'Microsoft',
                    data: data.map(item => (item.label === 'Microsoft' ? item.value : (item.label === 'Overture' ? item.components.microsoft : 0))),
                    backgroundColor: '#FFA500',
                    stack: 'Stack 0'
                },
                {
                    label: 'Google',
                    data: data.map(item => (item.label === 'Google' ? item.value : (item.label === 'Overture' ? item.components.google : 0))),
                    backgroundColor: '#87CEEB',
                    stack: 'Stack 0'
                }
            ]
        },
        options: {
            responsive: true,
            scales: {
                y: {
                    beginAtZero: true,
                    title: {
                        display: true,
                        text: 'Total Buildings',
                        font: { size: 16 }
                    }
                }
            },
            plugins: {
                title: {
                    display: true,
                    text: 'Datasets Buildings Count by Source',
                    font: { size: 18 }
                },
                tooltip: {
                    callbacks: {
                        label: function(context) {
                            const label = context.dataset.label || '';
                            const value = context.raw || 0;
                            const total = context.dataset.data.reduce((a, b) => a + b, 0);
                            if (context.dataset.label === 'OSM' && context.label === 'Overture') {
                                return `OSM: ${context.raw.toLocaleString()} (Total: ${context.dataset.data[2].toLocaleString()})`;
                            } else if (context.dataset.label === 'Microsoft' && context.label === 'Overture') {
                                return `Microsoft: ${context.raw.toLocaleString()} (Total: ${context.dataset.data[2].toLocaleString()})`;
                            } else if (context.dataset.label === 'Google' && context.label === 'Overture') {
                                return `Google: ${context.raw.toLocaleString()} (Total: ${context.dataset.data[2].toLocaleString()})`;
                            } else {
                                return `${label}: ${value.toLocaleString()}`;
                            }
                        }
                    }
                }
            }
        }
    });
</script>
</body>
</html>
<div style="text-align: center;">
    <div style="font-size: 0.8em; color: #778899; margin-top: 10px;">
        This chart highlights the discrepancies between building datasets produced by Overture, Microsoft, and Google. Despite advances in automation and AI, human validation remains crucial for ensuring accuracy and reliability, particularly in situations with bad imagery.
    </div>
</div>

<br>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Overture by Confidence Level</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/chartjs-plugin-datalabels"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        #chartContainer {
            max-width: 800px;
            margin: 0 auto;
        }
        #confidenceChart {
            width: 55% !important; /* Set width to 40% */
            height: auto !important; /* Maintain aspect ratio */
        }
    </style>
</head>
<body>

<div id="chartContainer">
    <canvas id="confidenceChart"></canvas>
</div>

<script>
    // Register the datalabels plugin
    Chart.register(ChartDataLabels);

    const confidenceData = {
        labels: ['0.9+', '0.81 - 0.9', '0.71 - 0.8', '0.61 - 0.7', 'NA'],
        datasets: [{
            data: [4607635, 4669182, 8570290, 3553592, 4447117],
            backgroundColor: [
                'rgba(255, 99, 132, 0.8)', // Red for 0.9+
                'rgba(255, 159, 64, 0.8)', // Orange for 0.81 - 0.9
                'rgba(211, 211, 211, 0.6)', // Soft Grey for 0.71 - 0.8
                'rgba(211, 211, 211, 0.4)', // Softer Grey for 0.61 - 0.7
                'rgba(211, 211, 211, 0.2)'  // Lightest Grey for NA
            ],
            borderWidth: 1
        }]
    };

    const total = confidenceData.datasets[0].data.reduce((a, b) => a + b, 0); // Calculate total for percentages

    const confidenceCtx = document.getElementById('confidenceChart').getContext('2d');
    const confidenceChart = new Chart(confidenceCtx, {
        type: 'doughnut',
        data: confidenceData,
        options: {
            responsive: true,
            plugins: {
                title: {
                    display: true,
                    text: 'Overture by Confidence Level',
                    font: { size: 18 }
                },
                tooltip: {
                    callbacks: {
                        label: function(context) {
                            const label = context.label || '';
                            const value = context.raw || 0;
                            const percentage = ((value / total) * 100).toFixed(2) + '%';
                            return `${label}: ${value.toLocaleString()} (${percentage})`;
                        }
                    }
                },
                datalabels: {
                    display: true,
                    color: '#000',
                    formatter: (value) => {
                        const percentage = ((value / total) * 100).toFixed(2) + '%';
                        return percentage;
                    },
                    font: {
                        weight: 'bold',
                        size: 14
                    }
                }
            }
        }
    });
</script>
</body>
</html>
<div style="text-align: center;">
    <div style="font-size: 0.8em; color: #778899; margin-top: 10px;">
        This chart shows the distribution of buildings in the Overture dataset by confidence level. The confidence levels are color-coded, with red and orange highlighting the highest confidence intervals. Percentages are displayed on the chart.
    </div>
</div>
<br>

## The Role of the Sudanese Diaspora
The Sudanese diaspora plays a crucial role. Members of these communities possess intimate knowledge of cultural landmarks, traditional names, and the intricate socio-political dynamics of their regions of origin. HOT’s project aims to amplify these voices, integrating their knowledge into the mapping process to create datasets that are both accurate and culturally sensitive. Together, we are fostering an OSM community for Sudan by connecting Sudanese with HOT staff and global OSM expert volunteers.

<br>
<br>
<div style="text-align: center;">
    <img src="/uploads/sudan-training-2025.jpeg" alt="Map showing data quality issues such as lack of completness and innacurate shapes for Microsoft ML buildings" style="width: 75%; height: auto;">
    <div style="font-size: 0.8em; color: #778899; margin-top: 10px;">
        Two-day OpenStreetMap training with Sudanese refugees in Kampala in 2025. Participants explored different open source mapping tools, and learned about basic concepts Geographic Information Systems(GIS) concepts.
    </div>
</div>
<br>
<br>

---

## Participatory Mapping to Leverage Local Knowledge

Mapping Sudan remotely requires engagement with Sudanese diaspora communities and local networks. By inviting these groups to contribute to the mapping effort, HOT ensures that the data reflects on-the-ground realities, from the names of areas to the locations of critical infrastructure. 

Using HOT’s **Tasking Manager** platform, volunteers are assigned specific areas to map, allowing them to focus on regions where they have direct or inherited knowledge. For example, a member of the diaspora might map roads and villages in a region they once lived in, providing accurate names and connections that no satellite imagery or automated tool could deduce. This participatory approach transforms the diaspora into active contributors, ensuring that cultural and administrative details—often overlooked—are preserved.

## Innovative Tools for Data Consolidation

HOT leverages a suite of advanced tools to integrate and validate data from multiple sources:

- **MapRoulette**: Helps volunteers refine and verify road data by addressing small but significant inconsistencies in road names and providing translations.
- **uMap**: Used for coordinating and creating a common operational dataset for boundaries that can be utilized across multiple organizations.
- **HOT Export Tool**: Enables organizations to download custom datasets tailored to specific humanitarian needs.
- **iD Editor and JOSM**: Allow volunteers to edit and enrich OpenStreetMap (OSM) data, adding attributes such as road names, surface types, and accessibility details.

These tools are integral to addressing gaps in both physical infrastructure and cultural data. For instance, OSM data already provides excellent rural road coverage, identifying over 300,000 km of roads not found in other datasets. By adding diaspora-provided names and attributes to these roads, the project creates a far more robust dataset for aid organizations.

## Building Trust Through Ethical Mapping

Recognizing the sensitivity of mapping in conflict zones, HOT has implemented a robust ethical framework to safeguard contributors and data users. This includes:

- Anonymizing submissions.
- Conducting risk assessments.
- Restricting access to potentially sensitive datasets.

By adhering to these principles, HOT ensures that the mapping process supports humanitarian goals without compromising the safety of contributors or the communities they aim to help. For more information check [HOT's data principles](https://www.hotosm.org/tools-and-data/data-principles/)

## Data Access and Use

Country level data OSM data can be downloaded from HDX. Scroll through this [filtered HDX list](https://data.humdata.org/organization/hot?groups=sdn&q=&sort=last_modified%20desc&ext_page_size=25) or choose from the categories bellow to visit a specific dataset:
- **[Roads](https://data.humdata.org/dataset/hotosm_sdn_roads)**
- **[Buildings](https://data.humdata.org/dataset/hotosm_sdn_buildings)**
- **[Waterways](https://data.humdata.org/dataset/hotosm_sdn_waterways)**
- **[Railways](https://data.humdata.org/dataset/hotosm_sdn_railways)**
- **[Health Facilities](https://data.humdata.org/dataset/hotosm_sdn_health_facilities)**
- **[Financial Services](https://data.humdata.org/dataset/hotosm_sdn_financial_services)**
- **[Populated Places](https://data.humdata.org/dataset/hotosm_sdn_populated_places)**
- **[Education Facilities](https://data.humdata.org/dataset/hotosm_sdn_education_facilities)**
- **[Sea Ports](https://data.humdata.org/dataset/hotosm_sdn_sea_ports)**
- **[Airports](https://data.humdata.org/dataset/hotosm_sdn_airports)**
- **[Points of Interest](https://data.humdata.org/dataset/hotosm_sdn_points_of_interest)**

### Download based on areas of interest
Downloads based on areas where HOT and partners have improved the data through Tasking Manager Projects:
- [West Darfur Border Area Buildings](https://s3.dualstack.us-east-1.amazonaws.com/production-raw-data-api/default/West_Darfur_Border___Buildings_geojson_uid_683010d0-c3a5-41ab-b180-7e6f8196bf0b.zip)
<br>
You can also create your own export using the [HOT Export Tool](https://export.hotosm.org/v3/exports/new/describe), an open service that creates customized extracts of up-to-date OSM data in various file formats.

## What’s Next? Upcoming Work and Focus Areas

As of January 2025, HOT’s work in Sudan is far from complete. The next phase will focus on scaling these efforts to cover underrepresented areas such as **Darfur**, **Kordofan**, and regions heavily impacted by displacement. Key initiatives include:

- **Expanding Mapping Coverage**: Leveraging tools like **MapSwipe** to involve more volunteers in mapping remote regions.
- **In-Person Training**: Starting in January, in-person workshops will equip volunteers with advanced mapping skills.
<br>

## Conclusion

Accurate and inclusive maps are a cornerstone of effective humanitarian response. In Sudan, where infrastructure is devastated, and access is constrained, reliable data ensures aid reaches those who need it most.

By bridging gaps in physical and cultural data, HOT’s work is not just enabling immediate relief but also setting the stage for long-term recovery and resilience. The active involvement of the Sudanese diaspora has been critical to this effort, proving that local knowledge and global tools can converge to create a powerful force for change.


---

### Get Involved

As this project continues, it will require sustained commitment from volunteers, partners, and the global community. Together, we can ensure that a map for Sudan is more suitable for recovery, relief, and planning. 

If you would like to help, please refer to the [wiki](https://wiki.openstreetmap.org/wiki/Sudan_Crisis_2023%E2%80%93) where you can find different projects, initiatives, and activities.

### *Are you with an organization working in Sudan or other conflict affected areas or interested in supporting other ways? Contact us at info@hotosm.org to partner, volunteer, or donate to ongoing efforts in conflict-affected areas worldwide*.
<br>
<span style="font-size: 0.8em;"><font color="#778899"><a> Cover photo: </a><a href="https://commons.wikimedia.org/wiki/File:Khartoum_ISS010E23451_lrg.jpg">Wikipedia</a> - NASA, Satellite picture of Khartoum, Omdurman and Bahri - Licensed under <a href="https://creativecommons.org/licenses/by-sa/4.0/">CC BY-SA 4.0</a></font></span>
<br>
<br>
**Sponsored by:**
<br>
<br>
<img src="https://www.hotosm.org/uploads/h2h-logo-new-400x400.png" width="100" height="100">