---
title: Geospatial Data for Humanitarian Response in Sudan Conflict
date: 2024-10-25 18:48:00 Z
published: false
Project Summary Text: Amid Sudan’s crisis, a global effort led by HOT, with support
  of the H2H network and the Sudanese diaspora is transforming fragmented maps into
  life-saving tools. By blending local knowledge with tech, we are creating data and
  maps that can support humanitarian organizations deliver aid where it's needed most.
Feature Image: "/uploads/Khartoum_ISS010E23451_lrg.jpg"
Country:
- Sudan
Impact Area:
- Disasters & Climate Resilience
Person:
- Jessica Pechmann
Partner:
- H2H
- OSM Sudan
- HDX
Duration:
  Start Date: 2024-06-01 00:00:00 Z
  End Date: 2025-02-28 00:00:00 Z
Tools:
- tool: Tasking Manager
- link: 
- Tool: uMap
---

<h3> Background </h3>

The humanitarian crisis in Sudan has reached a scale that demands innovative, collaborative, and data-driven solutions. As the conflict continues into 2025, millions of Sudanese face acute shortages of food, healthcare, and essential services. This has created one of the largest displacement crises globally, with millions of internally displaced persons (IDPs) and refugees spread across an increasingly fragmented landscape.

In such a context, reliable geospatial data becomes not just useful but life-saving. To bridge critical information gaps, the **Humanitarian OpenStreetMap Team (HOT)**, supported by the **H2H Network**, has initiated a project to enhance Sudan’s mapping infrastructure and geographies. By addressing deficiencies in road networks, populated places, and cultural information, this initiative provides aid organizations with the tools they need to reach vulnerable populations. Crucially, the project also incorporates the expertise of Sudanese diaspora communities, whose local knowledge offers unparalleled insights into the cultural and geographic nuances of the region.

---

## Understanding the Geospatial Gaps in Sudan
Sudan’s vast and diverse geography, combined with the ongoing conflict, has exacerbated challenges in acquiring accurate and actionable data. 

- **Around 63% Buildings** of buildings are missing in 2024 according to estimates by <a href="https://www.kontur.io/solutions/disaster-ninja/">Kontur</a>. The lack of reliable data can affect the efficiency of humanitarian efforts like aid delivery, and damage estimates for instance.   
- **Roads** in remote areas are poorly mapped, and existing datasets for urban centers often lack critical details like surface type or accessibility.  
- **Rural regions** face a near-complete absence of reliable geospatial data, hampering the ability of humanitarian organizations to plan logistics or assess infrastructure damage.

Beyond the physical terrain, another critical dimension is often overlooked: **cultural and administrative data**. Place names, boundaries, and locally significant landmarks—essential for contextualized humanitarian response—are frequently missing or mislabeled in existing datasets. This disconnect is not merely technical; it risks creating a mismatch between the aid provided and the communities' actual needs.
<br>
<iframe width="120%" height="610px" frameborder="0" allowfullscreen allow="geolocation" src="https://claurt07.github.io/sudan-completness-map/"></iframe>

<small>*Interactive map depicting OSM completness based on AI estimates by <a href="https://www.kontur.io/solutions/disaster-ninja/">Kontur</a>. These numbers are a rough guide on completness, and are only used to drive inform the priority areas where we map.*</small>

<br>

<!DOCTYPE html>
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
    const ctx = document.getElementById('buildingChart').getContext('2d');
    const buildingChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: ['OSM', 'Overture', 'Microsoft', 'Google'],
            datasets: [
                {
                    label: 'Total Buildings',
                    data: [1476231, 25848372, 10313711, 26619729],
                    backgroundColor: 'rgba(83, 141, 153, 1)',
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
                        font: {
                            size: 16
                        }
                    }
                }
            },
            plugins: {
                title: {
                    display: true,
                    text: 'Building Dataset Completeness by Source',
                    font: {
                        size: 18
                    }
                }
            }
        }
    });
</script>

</body>
</html>



### The Role of the Sudanese Diaspora
Here, the Sudanese diaspora plays a crucial role. Members of these communities possess intimate knowledge of cultural landmarks, traditional names, and the intricate socio-political dynamics of their regions of origin. HOT’s project aims to amplify these voices, integrating their knowledge into the mapping process to create datasets that are both accurate and culturally sensitive.

---

<br>

<h3>Get Involved</h3>

### *Are you with an organization working in Sudan or other conflict affected areas or interested in supporting other ways? Contact us at info@hotosm.org to partner, volunteer, or donate to ongoing efforts in conflict-affected areas worldwide*.
<br>
<span style="font-size: 0.8em;"><font color="#778899"><a> Cover photo: </a><a href="https://commons.wikimedia.org/wiki/File:Khartoum_ISS010E23451_lrg.jpg">Wikipedia</a> - NASA, Satellite picture of Khartoum, Omdurman and Bahri - Licensed under <a href="https://creativecommons.org/licenses/by-sa/4.0/">CC BY-SA 4.0</a></font></span>
<br>
<br>
**Sponsored by:**
<br>
<br>
<img src="https://www.hotosm.org/uploads/h2h-logo-new-400x400.png" width="100" height="100">