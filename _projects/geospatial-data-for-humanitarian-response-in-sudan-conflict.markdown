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

<div style="background-color: #f5f5f5; padding: 15px; border-radius: 5px;">

## <span style="color: red;">Table of Contents</span>

1. [Background](#background)  
2. [Understanding the Geospatial Gaps in Sudan](#understanding-the-geospatial-gaps-in-sudan)  
    - [OSM Building Completeness Estimates Map](#osm-building-completeness-estimates-map)  
3. [The Role of the Sudanese Diaspora](#the-role-of-the-sudanese-diaspora)  
4. [Participatory Mapping to Leverage Local Knowledge](#participatory-mapping-to-leverage-local-knowledge)  
5. [Innovative Tools for Data Consolidation](#innovative-tools-for-data-consolidation)  
6. [Building Trust Through Ethical Mapping](#building-trust-through-ethical-mapping)  
7. [What’s Next? Upcoming Work and Focus Areas](#whats-next-upcoming-work-and-focus-areas)  
8. [Conclusion](#conclusion)  
9. [Get Involved](#get-involved)  

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
<iframe width="120%" height="610px" frameborder="0" allowfullscreen allow="geolocation" src="https://claurt07.github.io/sudan-completness-map/"></iframe>
<div style="text-align: center;">
    <div style="font-size: 0.8em; color: #778899; margin-top: 10px;">
        Interactive map depicting OSM completness based on AI estimates by <a href="https://www.kontur.io/solutions/disaster-ninja/">Kontur</a>. These numbers are a rough guide on completness, and are only used to drive inform the priority areas for mapping.
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
                    text: 'Datasets Buildings Count by Source',
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
<div style="text-align: center;">
    <div style="font-size: 0.8em; color: #778899; margin-top: 10px;">
        This chart highlights the discrepancies between building datasets produced by Overture, Microsoft, and Google. Despite advances in automation and AI, human validation remains crucial for ensuring accuracy and reliability, particularly in situations with bad imagery.
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

## What’s Next? Upcoming Work and Focus Areas

As of January 2025, HOT’s work in Sudan is far from complete. The next phase will focus on scaling these efforts to cover underrepresented areas such as **Darfur**, **Kordofan**, and regions heavily impacted by displacement. Key initiatives include:

- **Expanding Mapping Coverage**: Leveraging tools like **MapSwipe** to involve more volunteers in mapping remote regions.
- **In-Person Training**: Starting in January, in-person workshops will equip volunteers with advanced mapping skills.
<br>
---

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