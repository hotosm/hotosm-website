---
title: 'Filling the gaps: Improving available geospatial data in Sudan through OpenStreetMap'
date: 2025-03-18 13:16:00 Z
Summary Text: 'Humanitarian mapping in Sudan has been improving data quality in OpenStreetMap
  (OSM) in otherwise uncovered areas. For those interested in using this OSM data,
  Humanitarian OpenStreetMap Team is making it easier than ever to find what data
  (and where!) in Sudan has been updated. '
Feature Image: "/uploads/pexels-ammad-rasool-sudan-56680900-15745290.jpg"
Person: Jessica Pechmann
Country:
- Sudan
Project:
- Geospatial Data for Humanitarian Response in Sudan Conflict
---

**Geospatial Data Creation in Response to Crisis**

Since its creation over 20 years ago, OpenStreetMap (OSM) has grown to a one of a kind global geospatial platform with thousands of datasets anybody can [export](https://export.hotosm.org/v3/) and use. But, despite this global coverage, there are still gaps. A 2021 study on [The evolution of humanitarian mapping within the OpenStreetMap community](https://www.nature.com/articles/s41598-021-82404-z) found that while areas of low and medium human development accounted for an estimated 46% of the population, these areas only accounted for 28% of buildings and 16% of roads in OSM. While development projects are changing this, sometimes a large emergency can push forward data representation for an affected area.

Take Sudan, for example. The ongoing civil war has sparked interest and investment in reflecting the territory accurately in OSM. [A recent research paper published in the journal Frontiers in Climate](https://www.frontiersin.org/journals/climate/articles/10.3389/fclim.2024.1439940/full) demonstrates that 83% of the buildings currently in OSM have been edited recently, between August 2021 and August 2024, aligning with the lead up to, and outbreak of, the current humanitarian crisis in Sudan. 

<br>
<html lang="en">
<head>
    <title>Mapping Stats</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css" />
    <style>
        * { box-sizing: border-box; }
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            display: flex;
            flex-direction: column;
            align-items: center;
            background-color: #f3f5f7;
        }
        .stats-container {
            display: flex;
            gap: 1.5rem;
            flex-wrap: wrap;
            justify-content: center;
            max-width: 1200px;
            margin-top: 2rem;
        }
        .card {
            background: #fff;
            padding: 1.5rem;
            border-radius: 8px;
            width: 250px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            text-align: center;
        }
        .card h2 {
            font-size: 2rem;
            margin: 0;
            color: #d8433f;
        }
        .card p {
            font-size: 1rem;
            margin: 0.5rem 0;
            color: #000;
        }
    </style>
</head>
<body>
    <div class="stats-container">
        <div class="card">
            <h2>28.3 K</h2>
            <p>2014-08-21</p>
        </div>
        <div class="card">
            <h2>1432 K</h2>
            <p>2024-08-21</p>
        </div>
        <div class="card">
            <h2>4958 %</h2>
            <p>Growth Rate</p>
        </div>
    </div>
</body>
</html>

<br>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>OSM Building Growth in Sudan</title>
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
    const labels = ["2014", "2015", "2016", "2017", "2018", "2019", "2020", "2021", "2022", "2023", "2024"];
    const dataPoints = [0, 10_000, 20_000, 40_000, 70_000, 100_000, 200_000, 400_000, 600_000, 1_000_000, 1_500_000];
    
    const ctx = document.getElementById('buildingChart').getContext('2d');
    const buildingChart = new Chart(ctx, {
        type: 'line',
        data: {
            labels: labels,
            datasets: [{
                label: 'Buildings Mapped',
                data: dataPoints,
                backgroundColor: 'rgba(54, 162, 235, 0.2)',
                borderColor: 'rgba(54, 162, 235, 1)',
                borderWidth: 2,
                fill: true
            }]
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
                    text: 'Total Number of Buildings Mapped in Sudan (OSM)',
                    font: { size: 18 }
                }
            }
        }
    });
</script>

<div style="text-align: center; margin-top: 10px; font-size: 0.8em; color: #778899;">
    <p>Total number of buildings mapped in OpenStreetMap (OSM) across Sudan from 21 August 2014 to 21 August 2024, showing a 4,958% growth rate. Source: <a href="https://dashboard.ohsome.org/" target="_blank">HeiGIT</a>.</p>
</div>

</body>
</html>

--- 

<br>

But is this data usable? Perceptions are mixed, with some of the interviewees from the study still considering OSM data in Sudan as unreliable due to lag in satellite imagery updates and a dynamic situation on the ground. Other respondents see the strength of OSM data coming from the “crowd’s intelligence”, meaning that when many are contributing together, errors are detected and corrected. But with all edits to OSM being live, and therefore reflected in countrywide exports on OCHA’s Humanitarian Data Exchange (HDX) or through [HOT’s Export Tool](https://export.hotosm.org/v3/), how can users know what OSM data is good? 

**Finding Updated -and High Quality- OSM Data in Sudan**

Navigating what data in OSM is usable in crisis affected countries can be challenging. Through our [Conflict and Displacement Program](https://www.hotosm.org/programs/conflict-displacement), HOT has been working to facilitate the identification of higher quality data in OSM and to perform comparisons with other data sources.

**For example, we have introduced summary statistics** to most of our pages on HDX, including spatial coverage and attribute completeness for better understanding and comparison to other data sources. See [Sudan’s OSM roads page](https://data.humdata.org/dataset/hotosm_sdn_buildings)~ for an example. Additionally, when HOT’s partners through Missing Maps and other organizations use ~[HOT’s Tasking Manager](https://tasks.hotosm.org/), a project is only considered “complete” if an expert volunteer has double checked each area mapped for quality and completeness. To understand what data in OSM has been updated through a recent and dedicated humanitarian mapping campaign, [HOT has compiled this information on our dedicated Sudan projects webpage.](https://www.hotosm.org/projects/geospatial-data-for-humanitarian-response-in-sudan-conflict/#data-access-and-use) The page includes download links to all datasets that have been updated and validated through Tasking Manager projects since the onset of the war in Sudan. Nationwide datasets for Sudan are also available on our Sudan [HOTOSM HDX page](https://data.humdata.org/dataset/?groups=sdn&organization=hot&q=&sort=last_modified+desc&ext_page_size=25).

<br>
<div style="text-align: center;">
    <img src="/uploads/sdn_sudan_crisis_2023_aoi.png" alt="Map1 AP Sherni River Museum 2023" style="width: 75%; height: auto;">
    <div style="font-size: 0.8em; color: #778899; line-height: 1.2; margin-top: 10px;">
        <span>Example of people living in internal displacement in Somalia, as seen by smaller structures above.</span>
    </div>
</div>
<br>

**What’s next**

With support from the H2H network, HOT has been working with community organizers from Sudan to grow an OSM community amongst the Sudanese diaspora and others from Sudan. The growing community has been busy improving the quality of roads, buildings, points of interest and other infrastructure in Sudan. Learn more about the project [here](https://www.hotosm.org/projects/geospatial-data-for-humanitarian-response-in-sudan-conflict/)~ or sign up for our ~[Data for Good newsletter](https://mailchi.mp/hotosm.org/stories-of-tech-data-and-local-open-mapping-for-good) for more updates on our work.

Are you looking to get involved in our efforts in Sudan, learn more about OSM availability in Sudan, or want to discuss a partnership? Let us know at [data@hotosm.org](mailto:data@hotosm.org).