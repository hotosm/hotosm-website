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
