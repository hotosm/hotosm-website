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
        * { box-sizing: border-box; margin: 0; padding: 0; }
        body {
            font-family: Arial, sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            background-color: #f3f5f7;
            padding: 1rem;
        }
        .stats-container {
            display: flex;
            gap: 1rem;
            flex-wrap: wrap;
            justify-content: center;
            max-width: 800px;
            width: 100%;
        }
        .card {
            background: #fff;
            padding: 1rem;
            border-radius: 8px;
            width: 150px; /* Smaller width */
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            text-align: center;
            flex: 1 1 auto; /* Allow cards to grow and shrink */
        }
        .card h2 {
            font-size: 1.5rem; /* Smaller font size */
            margin: 0;
            color: #489FD8;
        }
        .card p {
            font-size: 0.875rem; /* Smaller font size */
            margin: 0.5rem 0 0;
            color: #000;
        }

        /* Responsive behavior */
        @media (max-width: 600px) {
            .stats-container {
                flex-direction: column;
                align-items: center;
            }
            .card {
                width: 100%; /* Full width on small screens */
                max-width: 200px; /* Limit max width for better readability */
            }
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
    <title>OSM Buildings Growth in Sudan</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
</head>
<body>
    <canvas id="osmChart"></canvas>
    <script>
        const ctx = document.getElementById('osmChart').getContext('2d');
        const labels = [
            '2014-01', '2014-02', '2014-03', '2014-04', '2014-05', '2014-06', '2014-07', '2014-08', '2014-09', '2014-10', '2014-11', '2014-12',
            '2015-01', '2015-02', '2015-03', '2015-04', '2015-05', '2015-06', '2015-07', '2015-08', '2015-09', '2015-10', '2015-11', '2015-12',
            '2016-01', '2016-02', '2016-03', '2016-04', '2016-05', '2016-06', '2016-07', '2016-08', '2016-09', '2016-10', '2016-11', '2016-12',
            '2017-01', '2017-02', '2017-03', '2017-04', '2017-05', '2017-06', '2017-07', '2017-08', '2017-09', '2017-10', '2017-11', '2017-12',
            '2018-01', '2018-02', '2018-03', '2018-04', '2018-05', '2018-06', '2018-07', '2018-08', '2018-09', '2018-10', '2018-11', '2018-12',
            '2019-01', '2019-02', '2019-03', '2019-04', '2019-05', '2019-06', '2019-07', '2019-08', '2019-09', '2019-10', '2019-11', '2019-12',
            '2020-01', '2020-02', '2020-03', '2020-04', '2020-05', '2020-06', '2020-07', '2020-08', '2020-09', '2020-10', '2020-11', '2020-12',
            '2021-01', '2021-02', '2021-03', '2021-04', '2021-05', '2021-06', '2021-07', '2021-08', '2021-09', '2021-10', '2021-11', '2021-12',
            '2022-01', '2022-02', '2022-03', '2022-04', '2022-05', '2022-06', '2022-07', '2022-08', '2022-09', '2022-10', '2022-11', '2022-12',
            '2023-01', '2023-02', '2023-03', '2023-04', '2023-05', '2023-06', '2023-07', '2023-08', '2023-09', '2023-10', '2023-11', '2023-12',
            '2024-01', '2024-02', '2024-03', '2024-04', '2024-05', '2024-06', '2024-07', '2024-08', '2024-09', '2024-10', '2024-11', '2024-12',
            '2025-01', '2025-02'
        ];
        const data = [
            27927, 27932, 27937, 27938, 27938, 27972, 28154, 28269, 28274, 28296, 28732, 29151,
            29417, 31376, 31583, 31703, 31877, 31978, 32198, 32285, 32610, 33926, 34437, 45234,
            46489, 46594, 46686, 46887, 46933, 48076, 52344, 53035, 55354, 56851, 56944, 57570,
            58466, 61221, 62145, 64144, 75093, 81458, 81508, 81559, 81606, 81629, 81755, 81937,
            83410, 83482, 83620, 83775, 83776, 83866, 85747, 88036, 92317, 96014, 99823, 104896,
            104961, 105283, 108720, 109229, 109836, 110455, 110490, 110406, 111263, 111353, 111547, 111891,
            111970, 112489, 112795, 113030, 113744, 114671, 115600, 116584, 117717, 118476, 118988, 130725,
            213380, 219911, 225847, 226291, 256889, 276207, 286988, 287435, 289823, 297835, 302593, 329857,
            339471, 343543, 346265, 347813, 355449, 388207, 406714, 413843, 431835, 550623, 601177, 621198,
            625271, 627655, 630888, 647913, 648700, 651772, 661625, 725068, 798396, 850846, 929626, 1056326,
            1130988, 1199709, 1288413, 1354823, 1403610, 1425249, 1430701, 1430470, 1431686, 1434167, 1444426, 1482139,
            1497606, 1617831
        ];
        
        const osmChart = new Chart(ctx, {
            type: 'line',
            data: {
                labels: labels,
                datasets: [{
                    label: 'Buildings Mapped',
                    data: data,
                    borderColor: '#489FD8',
                    backgroundColor: 'rgba(209, 228, 244, 0.2)',
                    fill: true,
                    tension: 0.4,
                    pointRadius: labels.map(label => label.endsWith('-01') ? 4 : 0)
                }]
            },
            options: {
                responsive: true,
                plugins: { legend: { display: true } },
                scales: { x: { title: { display: true, text: 'Year' }, grid: { display: false } }, y: { title: { display: true, text: 'Number of Buildings' },grid: { display: false } } }
            }
        });
    </script>
</body>
</html>
<div style="font-size: 0.8em; color: #778899; line-height: 1.2; margin-top: 10px;">
        <span>
    Total number of buildings mapped in OpenStreetMap (OSM) across Sudan from 21 August 2014 to 21 August 2024, showing a 4,958% growth rate. Source: <a href="https://dashboard.ohsome.org/">HeiGIT</a>.
</span>

    </div>

<br>

But is this data usable? Perceptions are mixed, with some of the interviewees from the study still considering OSM data in Sudan as unreliable due to lag in satellite imagery updates and a dynamic situation on the ground. Other respondents see the strength of OSM data coming from the “crowd’s intelligence”, meaning that when many are contributing together, errors are detected and corrected. But with all edits to OSM being live, and therefore reflected in countrywide exports on OCHA’s Humanitarian Data Exchange (HDX) or through [HOT’s Export Tool](https://export.hotosm.org/v3/), how can users know what OSM data is good? 

<br>

**Finding Updated -and High Quality- OSM Data in Sudan**

Navigating what data in OSM is usable in crisis affected countries can be challenging. Through our [Conflict and Displacement Program](https://www.hotosm.org/programs/conflict-displacement), HOT has been working to facilitate the identification of higher quality data in OSM and to perform comparisons with other data sources.

<br>

**For example, we have introduced summary statistics** to most of our pages on HDX, including spatial coverage and attribute completeness for better understanding and comparison to other data sources. See [Sudan’s OSM roads page](https://data.humdata.org/dataset/hotosm_sdn_buildings)~ for an example. Additionally, when HOT’s partners through Missing Maps and other organizations use ~[HOT’s Tasking Manager](https://tasks.hotosm.org/), a project is only considered “complete” if an expert volunteer has double checked each area mapped for quality and completeness. To understand what data in OSM has been updated through a recent and dedicated humanitarian mapping campaign, [HOT has compiled this information on our dedicated Sudan projects webpage.](https://www.hotosm.org/projects/geospatial-data-for-humanitarian-response-in-sudan-conflict/#data-access-and-use) The page includes download links to all datasets that have been updated and validated through Tasking Manager projects since the onset of the war in Sudan. Nationwide datasets for Sudan are also available on our Sudan [HOTOSM HDX page](https://data.humdata.org/dataset/?groups=sdn&organization=hot&q=&sort=last_modified+desc&ext_page_size=25).

<br>
<div style="text-align: center;">
    <img src="/uploads/sdn_sudan_crisis_2023_aoi.png" alt="Map1 AP Sherni River Museum 2023" style="width: 75%; height: auto;">
    <div style="font-size: 0.8em; color: #778899; line-height: 1.2; margin-top: 10px;">
        <span>Map of the Areas of interest and data improvements part of the campaign on Tasking Manager.</span>
    </div>
</div>
<br>

**What’s next**

With support from the H2H network, HOT has been working with community organizers from Sudan to grow an OSM community amongst the Sudanese diaspora and others from Sudan. The growing community has been busy improving the quality of roads, buildings, points of interest and other infrastructure in Sudan. Learn more about the project [here](https://www.hotosm.org/projects/geospatial-data-for-humanitarian-response-in-sudan-conflict/)~ or sign up for our ~[Data for Good newsletter](https://mailchi.mp/hotosm.org/stories-of-tech-data-and-local-open-mapping-for-good) for more updates on our work.

<br>

<div style="background-color: #f0f0f0; padding: 10px; border-radius: 5px;">
    Are you looking to get involved in our efforts in Sudan, learn more about OSM availability in Sudan, or want to discuss a partnership? Let us know at <a href="mailto:data@hotosm.org">data@hotosm.org</a>.
</div>
