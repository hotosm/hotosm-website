---
title: Will OpenStreetMap meet your needs? HOT’s move towards more data insights
date: 2024-10-17 21:10:00 Z
Summary Text: 'At Humanitarian OpenStreetMap Team (HOT), we often get asked, “how
  good is OpenStreetMap data” in a given area? In the spirit of <a href="https://en.wikipedia.org/wiki/FAIR_data">FAIR
  data</a> (findable, accessible, interoperable, and reusable) and with support from
  the <a href="https://www.hotosm.org/updates/improving-osm-for-anticipatory-action-with-h2h/">H2H
  Network</a>, HOT is improving the reusability of OpenStreetMap (OSM) data through
  improved metadata of its datasets. With better information on a dataset’s spatial
  coverage and attribute completeness, users can make quicker and more efficient decisions
  on what data source to use.

'
Person: Jessica Pechmann
Country:
- Ethiopia
- Mozambique
- Somalia
- South Sudan
Project:
- Analyzing and Improving OpenStreetMap Data for Anticipatory Action in the Humanitarian
  System
---

If a user needs a quick answer to the question, “what is the best dataset in the Humanitarian Data Exchange”, [HDX’s Data Grids](https://data.humdata.org/group/afg) has a recommended source for all countries with Humanitarian Response Plans for six spatial datasets (administrative divisions, populated places, roads, airports, and health and education facilities). 

The two most common data sources for spatial datasets are HOT and OCHA. HOT provides data exports directly from OpenStreetMap. [OSM](https://wiki.openstreetmap.org/wiki/About_OpenStreetMap) datasets are crowdsourced and community generated. OCHA data comes from a variety of sources and is usually created by a single entity. The table below shows the top recommended data source per country and dataset, according to the Data Grids. 

<br>
<br>

<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    table {
      width: 100%;
      border-collapse: collapse;
    }
    th, td {
      padding: 8px;
      text-align: center;
      border: 1px solid #ddd;
    }
    th {
      background-color: #f4f4f4;
    }
    td.OCHA {
      background-color: #1E90FF; /* Dark blue */
      color: white;
    }
    td.HOT {
      background-color: #FF4500; /* Red */
      color: white;
    }
    td.lightOCHA {
      background-color: #87CEEB; /* Lighter blue */
      color: white;
    }
    td.HDX {
      background-color: #ADD8E6; /* Very light blue */
      color: white;
    }
    td.OurAirports {
      background-color: #f0f0f0; /* Light grey for OurAirports */
      color: black;
    }
    @media screen and (max-width: 600px) {
      td, th {
        font-size: 12px;
        padding: 4px;
      }
    }
  </style>
</head>
<body>

<table>
  <tr>
    <th>Country</th>
    <th>Administrative Divisions</th>
    <th>Populated Places</th>
    <th>Roads</th>
    <th>Airports</th>
    <th>Health Facilities</th>
    <th>Education Facilities</th>
  </tr>
  <tr>
    <td>Afghanistan</td>
    <td class="lightOCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
  </tr>
  <tr>
    <td>Burkina Faso</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
  </tr>
  <tr>
    <td>Cameroon</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
    <td class="HDX">HDX</td>
    <td class="HOT">HOT</td>
  </tr>
  <tr>
    <td>CAR</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="OCHA">OCHA</td>
    <td class="HDX">HDX</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Chad</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="HDX">HDX</td>
    <td class="HOT">HOT</td>
  </tr>
  <tr>
    <td>Colombia</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OurAirports">OurAirports</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Democratic Congo</td>
    <td class="OCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
  </tr>
  <tr>
    <td>Ethiopia</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="HDX">HDX</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Haiti</td>
    <td class="OCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Mali</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="HOT">HOT</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Mozambique</td>
    <td class="OCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="OCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="HDX">WHO</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Myanmar</td>
    <td class="OCHA">MIMU</td>
    <td class="OCHA">MIMU</td>
    <td class="OCHA">MIMU</td>
    <td class="OCHA">MIMU</td>
    <td class="HOT">HOT</td>
    <td class="OCHA">MIMU</td>
  </tr>
  <tr>
    <td>Niger</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Nigeria</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="HDX">HDX</td>
    <td class="HOT">HOT</td>
  </tr>
  <tr>
    <td>Somalia</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="OCHA">OCHA</td>
    <td class="HDX">WHO</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>South Sudan</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="HDX">HDX</td>
    <td class="OCHA">IOM</td>
  </tr>
  <tr>
    <td>State of Palestine</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="HDX">HDX</td>
    <td class="OCHA">OCHA</td>
  </tr>
</table>

</body>
</html>
*Chart Showing HDX Recommended Resources by Organization and if they are Considered Complete or Incomplete: <a style="color:blue">Complete</a>, <a style="color:red">Incomplete</a>*

<br>
A dataset is considered “complete” by HDX if it’s: 
1. In a readable format
2. Covers the whole country
3. Follows an update cycle

50% of the recommended spatial datasets above are considered “complete”. Of the 35 HOT datasets recommended in the Data Grids, 30 are identified by HDX as “incomplete”.

Is an “incomplete” dataset still usable? And what about its attributes (OSM tags)? It depends on the use case. Based on user feedback, we’ve developed resources to better understand OSM data before downloading. 

Starting with roads and populated place datasets, we surveyed OSM data users for the most important factors they consider when determining if a dataset is usable. We found that spatial coverage is the most important factor, especially for populated places, while precision and attributes also remain important. 

<br>
***Chart 2***
<br>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>OSM User Survey Chart</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        #chartContainer {
            max-width: 700px;
            margin: 0 auto;
        }
    </style>
</head>
<body>

<div id="chartContainer">
    <canvas id="osmChart"></canvas>
</div>

<script>
    const ctx = document.getElementById('osmChart').getContext('2d');
    const osmChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: ['Populated Places', 'Roads'],
            datasets: [
                {
                    label: 'Spatial Coverage',
                    data: [60, 50],
                    backgroundColor: 'rgba(83, 141, 153, 1)',
                },
                {
                    label: 'Geometric Precision',
                    data: [40, 45],
                    backgroundColor: 'rgba(151, 213, 211, 1)',
                },
                {
                    label: 'Attribute Completeness',
                    data: [30, 35],
                    backgroundColor: 'rgba(243, 177, 100, 1)',
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
                        text: 'Importance Ranking',
                        font: {
                            size: 16
                        }
                    }
                }
            },
            plugins: {
                title: {
                    display: true,
                    text: 'OSM User Survey: Quality Metric Importance Ranking',
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

<br>
***In the same survey, we found feature categorization was the most important attribute (OSM tag) for both datasets.***
<br>


<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Users Reporting Use of Attribute</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        #chartContainer {
            max-width: 900px;
            margin: 0 auto;
        }
    </style>
</head>
<body>

<div id="chartContainer">
    <canvas id="attributeChart"></canvas>
</div>

<script>
    const ctx2 = document.getElementById('attributeChart').getContext('2d');
    const attributeChart = new Chart(ctx2, {
        type: 'bar',
        data: {
            labels: [
                'classification or type',
                'name - english',
                'population',
                'surface',
                'source',
                'name - local language',
                'bridge',
                'oneway',
                'lanes',
                'width'
            ],
            datasets: [
                {
                    label: 'Roads',
                    data: [96, 58, 0, 65, 46, 46, 50, 46, 42, 35],
                    backgroundColor: 'rgba(83, 141, 153, 1)',
                    borderWidth: 1
                },
                {
                    label: 'Populated Places',
                    data: [92, 72, 68, 0, 56, 14, 0, 0, 0, 0],
                    backgroundColor: 'rgba(243, 177, 100, 1)',
                    borderWidth: 1
                }
            ]
        },
        options: {
            indexAxis: 'y', // Horizontal bar chart
            responsive: true,
            scales: {
                x: {
                    beginAtZero: true,
                    title: {
                        display: true,
                        text: 'Percentage of Users (%)',
                        font: {
                            size: 16
                        }
                    },
                    ticks: {
                        callback: function(value) {
                            return value + '%'; // Add percentage symbol
                        }
                    }
                }
            },
            plugins: {
                title: {
                    display: true,
                    text: 'Users Reporting Use of Attribute (OSM tag)',
                    font: {
                        size: 18
                    }
                },
                tooltip: {
                    callbacks: {
                        label: function(tooltipItem) {
                            return tooltipItem.raw + '%';
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

### How this will help data users?
HOT has created a [data quality report](https://h2h.observablehq.cloud/h2h-stats/) as a sample to reviewing OSM data quality and completeness. In the report, we compare HOT/OSM and OCHA data sources (as the two most popular data sources for spatial datasets in HDX) for greater context. **In general, we found HOT data has larger spatial coverage, but less completed attributes.** Here we share two country-specific examples of these findings, but we encourage you to check out the full report to view similar comparisons! 

**Example 1. Country: Somalia, Dataset: Populated Places** 
* **Coverage**: HOT has 80% more populated places than OCHA, with **HOT’s 57,822**, to **OCHA’s 11,283.**  
* **Name**: OCHA’s dataset has *significantly* more places with names. **13% of the places from HOT’s dataset have a name, vs. 100% in OCHA**. 

⠀**“Type”**: HOT’s OSM dataset categorizes points as **isolated dwellings, hamlet, and village**, while OCHA’s dataset is mostly classified as **settlements, with very few nomadic settlements and IDP camps.**



