---
title: Will OpenStreetMap meet your needs? HOT’s move towards more data insights
date: 2024-10-17 21:10:00 Z
published: false
Summary Text: 'In the spirit of <a href="https://en.wikipedia.org/wiki/FAIR_data">FAIR
  data</a> (findable, accessible, interoperable, and reusable) and with support from
  the <a href="https://www.hotosm.org/updates/improving-osm-for-anticipatory-action-with-h2h/">H2H
  Network</a>, HOT is improving the reusability of OpenStreetMap (OSM) data through
  improved metadata of its datasets.

'
Feature Image: "/uploads/fair-fmtm-monrovia-osm-footprints.jpg.jpg"
Person:
- Jessica Pechmann
- Claudio de los Reyes
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

<br>
> At Humanitarian OpenStreetMap Team (HOT), we often get asked, **“how good is OpenStreetMap data” in a given area?** With better information on a dataset’s spatial coverage and attribute completeness, users can make quicker and more efficient decisions on what data source to use.


<br>

The two most common data sources for spatial datasets are HOT and OCHA. HOT provides data exports directly from OpenStreetMap. [OSM](https://wiki.openstreetmap.org/wiki/About_OpenStreetMap) datasets are crowdsourced and community generated. OCHA data comes from a variety of sources and is usually created by a single entity. The table below shows the top recommended data source, and its completness per country and dataset, according to the Data Grids. 

**A dataset is considered “complete” by HDX if it’s:** 
* In a readable format
* Covers the whole country
* Follows an update cycle

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
      background-color: #d63f3e; /* Red */
      color: white;
    }
    td.lightHOT {
      background-color: #eca8a7; /* Lighter Red */
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
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Burkina Faso</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
  </tr>
  <tr>
    <td>Cameroon</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
    <td class="lightOCHA">HDX</td>
    <td class="lightHOT">HOT</td>
  </tr>
  <tr>
    <td>CAR</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">HDX</td>
    <td class="lightOCHA">OCHA</td>
  </tr>
  <tr>
    <td>Chad</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">HDX</td>
    <td class="lightHOT">HOT</td>
  </tr>
  <tr>
    <td>Colombia</td>
    <td class="lightOCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">OurAirports</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Democratic Congo</td>
    <td class="OCHA">OCHA</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
  </tr>
  <tr>
    <td>Ethiopia</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">HDX</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Haiti</td>
    <td class="OCHA">OCHA</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Mali</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Mozambique</td>
    <td class="OCHA">OCHA</td>
    <td class="lightHOT">HOT</td>
    <td class="OCHA">OCHA</td>
    <td class="lightHOT">HOT</td>
    <td class="HDX">WHO</td>
    <td class="OCHA">OCHA</td>
  </tr>
  <tr>
    <td>Myanmar</td>
    <td class="OCHA">MIMU</td>
    <td class="OCHA">MIMU</td>
    <td class="lightOCHA">MIMU</td>
    <td class="lightOCHA">MIMU</td>
    <td class="lightHOT">HOT</td>
    <td class="lightOCHA">MIMU</td>
  </tr>
  <tr>
    <td>Niger</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
  </tr>
  <tr>
    <td>Nigeria</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="lightHOT">HOT</td>
    <td class="lightOCHA">HDX</td>
    <td class="lightHOT">HOT</td>
  </tr>
  <tr>
    <td>Somalia</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightHOT">HOT</td>
    <td class="OCHA">OCHA</td>
    <td class="HDX">WHO</td>
    <td class="lightOCHA">OCHA</td>
  </tr>
  <tr>
    <td>South Sudan</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">HDX</td>
    <td class="lightOCHA">IOM</td>
  </tr>
  <tr>
    <td>State of Palestine</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
  </tr>
  <tr>
    <td>Sudan</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="lightOCHA">HDX</td>
    <td class="lightOCHA">OCHA</td>
  </tr>
  <tr>
    <td>Syrian Arab Republic</td>
    <td class="OCHA">OCHA</td>
    <td class="lightOCHA">OCHA</td>
    <td class="OCHA">WFP</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
  </tr>
  <tr>
    <td>Ukraine</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="HOT">HOT</td>
    <td class="OCHA">OCHA</td>
    <td class=""></td>
    <td class=""></td>
  </tr>
  <tr>
    <td>Venezuela</td>
    <td class="lightOCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class=""></td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
    <td class="lightHOT">HOT</td>
  </tr>
  <tr>
    <td>Yemen</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="OCHA">OCHA</td>
    <td class="lightHOT">HOT</td>
  </tr>
</table>

</body>
</html>
*<span style="color: #1E90FF;">■</span><span style="color: #d63f3e;">■</span> Complete, <span style="color: #87CEEB;">■</span><span style="color: #eca8a7;">■</span> Incomplete*

<br>

50% of the recommended spatial datasets above are considered “complete”. **Of the 35 HOT datasets recommended in the Data Grids, 30 are identified by HDX as “<a style="color:#eca8a7">incomplete</a>”.**

Is an “incomplete” dataset still usable? And what about its attributes (OSM tags)? It depends on the use case. Based on user feedback, we’ve developed resources to better understand OSM data before downloading. 

Starting with roads and populated place datasets, we surveyed OSM data users for the most important factors they consider when determining if a dataset is usable. We found that spatial coverage is the most important factor, especially for populated places, while precision and attributes also remain important. 

<br>

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
HOT has created a [data quality report](https://h2h.observablehq.cloud/h2h-stats/) as a prototype of how automate the assessment of OSM data quality and completeness that can use similar datasets in HDX or AI generated ones as benchmark. 

In the report, we compare HOT/OSM and OCHA data sources (as the two most popular data sources for spatial datasets in HDX) for greater context. **In general, we found HOT data has larger spatial coverage, but less completed attributes.** Here we share two country-specific examples of these findings, but we encourage you to check out the full report to view similar comparisons!
<br>
<br>
**Example 1. Country: Somalia, Dataset: Populated Places** 
* **Coverage**: HOT has 80% more populated places than OCHA, with **<a style="color:#d63f3e">HOT’s 57,822</a>**, to **<a style="color:#1E90FF">OCHA’s 11,283.</a>**  
* **Name**: OCHA’s dataset has *significantly* more places with names. **<a style="color:#d63f3e">13% of the places from HOT’s dataset have a name</a>, vs. <a style="color:#1E90FF">100% in OCHA</a>**. 

⠀**“Type”**: HOT’s OSM dataset categorizes points as **<a style="color:#d63f3e">isolated dwellings, hamlet, and village</a>**, while OCHA’s dataset is mostly classified as **<a style="color:#1E90FF">settlements, with very few nomadic settlements and IDP camps.</a>**

<br>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>OCHA and HOT 'Place' Values Chart (Sorted)</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        #chartContainer {
            max-width: 1000px;
            margin: 0 auto;
        }
    </style>
</head>
<body>

<div id="chartContainer">
    <canvas id="placeValuesChart"></canvas>
</div>

<script>
    // Original data
    const labels = [
        'isolated_dwelling',
        'hamlet',
        'village',
        'town',
        'city',
        'Settlement',
        'Temporary nomadic settlement',
        'IDP Camp',
        'Part of town',
        'District Capital',
        'Regional Capital',
        'Town',
        'National Capital'
    ];
    
    const hotData = [40759, 11400, 5502, 125, 36, 0, 0, 0, 0, 0, 0, 0, 0]; // HOT data
    const ochaData = [0, 0, 0, 0, 0, 9746, 732, 533, 186, 55, 17, 13, 1];  // OCHA data
    
    // Combine HOT and OCHA data for sorting
    let combinedData = labels.map((label, index) => ({
        label: label,
        hotCount: hotData[index],
        ochaCount: ochaData[index],
        totalCount: hotData[index] + ochaData[index]
    }));

    // Sort by total count (descending order)
    combinedData.sort((a, b) => b.totalCount - a.totalCount);

    // Extract sorted labels and data
    const sortedLabels = combinedData.map(item => item.label);
    const sortedHotData = combinedData.map(item => item.hotCount);
    const sortedOchaData = combinedData.map(item => item.ochaCount);

    // Create the chart
    const ctx3 = document.getElementById('placeValuesChart').getContext('2d');
    const placeValuesChart = new Chart(ctx3, {
        type: 'bar',
        data: {
            labels: sortedLabels,
            datasets: [
                {
                    label: 'HOT',
                    data: sortedHotData,
                    backgroundColor: '#d63f3e', // Blue color for HOT
                    borderWidth: 1
                },
                {
                    label: 'OCHA',
                    data: sortedOchaData,
                    backgroundColor: '#1E90FF', // Yellow color for OCHA
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
                        text: 'Count',
                        font: {
                            size: 16
                        }
                    }
                }
            },
            plugins: {
                title: {
                    display: true,
                    text: "OCHA and HOT 'Place' Values",
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

**Example 2. Country: South Sudan, Dataset:Roads**
* **Coverage**
  * HOT has 99% more features than OCHA, with **<a style="color:#d63f3e">176,345 road features in OSM</a>** vs **<a style="color:#1E90FF">976 in OCHA</a>**.  
  * Despite having significantly less individual features, OCHA has decent spatial coverage with 69% of HOT’s coverage (**<a style="color:#1E90FF">43,164 kms</a>** vs **<a style="color:#d63f3e">137,476 kms</a>**). 
* **“Type”**
  * OCHA only has **<a style="color:#1E90FF">river and road</a>** for transportation “type”, while HOT’s OSM dataset has **<a style="color:#d63f3e">path, track, residential, tertiary, and primary, secondary, footway, etc.</a>**  

<br>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Combined 'Highway' Values Chart</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        #chartContainer999 {
            max-width: 1000px;
            margin: 0 auto;
        }
    </style>
</head>
<body>

<div id="chartContainer999">
    <canvas id="highwayValuesChart999"></canvas>
</div>

<script>
    // Data for HOT and OCHA
    const data999 = [
        { label: 'path', HOT: 46258.15, OCHA: 0 },
        { label: 'track', HOT: 31315.61, OCHA: 0 },
        { label: 'unclassified', HOT: 29588.21, OCHA: 0 },
        { label: 'residential', HOT: 10545.83, OCHA: 0 },
        { label: 'tertiary', HOT: 7551.10, OCHA: 0 },
        { label: 'primary', HOT: 5845.09, OCHA: 0 },
        { label: 'secondary', HOT: 3989.70, OCHA: 0 },
        { label: 'service', HOT: 1229.47, OCHA: 0 },
        { label: 'footway', HOT: 595.02, OCHA: 0 },
        { label: 'proposed', HOT: 393.31, OCHA: 0 },
        { label: 'construction', HOT: 138.20, OCHA: 0 },
        { label: 'bridleway', HOT: 7.84, OCHA: 0 },
        { label: 'road', HOT: 7.24, OCHA: 38094.87 },
        { label: 'pedestrian', HOT: 4.56, OCHA: 0 },
        { label: 'living_street', HOT: 3.61, OCHA: 0 },
        { label: 'primary_link', HOT: 1.57, OCHA: 0 },
        { label: 'trunk', HOT: 0.94, OCHA: 0 },
        { label: 'tertiary_link', HOT: 0.34, OCHA: 0 },
        { label: 'steps', HOT: 0.23, OCHA: 0 },
        { label: 'secondary_link', HOT: 0.16, OCHA: 0 },
        { label: 'river', HOT: 0, OCHA: 5066.71 },
        { label: 'small_river', HOT: 0, OCHA: 2.52 }
    ];

    // Sort the data by the total of HOT and OCHA combined in descending order
    data999.sort((a, b) => (b.HOT + b.OCHA) - (a.HOT + a.OCHA));

    // Prepare the labels and datasets
    const labels999 = data999.map(item => item.label);
    const hotData999 = data999.map(item => item.HOT);
    const ochaData999 = data999.map(item => item.OCHA);

    const ctx4999 = document.getElementById('highwayValuesChart999').getContext('2d');
    const highwayValuesChart999 = new Chart(ctx4999, {
        type: 'bar',
        data: {
            labels: labels999,
            datasets: [
                {
                    label: 'HOT',
                    data: hotData999,
                    backgroundColor: '#d63f3e',
                    borderWidth: 1
                },
                {
                    label: 'OCHA',
                    data: ochaData999,
                    backgroundColor: '#1E90FF',
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
                        text: 'Distance (km)',
                        font: {
                            size: 16
                        }
                    },
                    ticks: {
                        callback: function(value) {
                            return value + ' km'; // Add km symbol
                        }
                    }
                },
                y: {
                    ticks: {
                        autoSkip: false, // Prevent labels from disappearing
                        font: {
                            size: 12 // Adjust font size to fit more labels
                        },
                        padding: 5 // Add padding to make the labels more visible
                    }
                }
            },
            plugins: {
                title: {
                    display: true,
                    text: "Combined 'Highway' Values",
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

***What’s next?***

Based on these insights, we are currently working on adding additional data quality statistics to the metadata of our OSM exports. Attributes like feature name, spatial coverage, or how can a “type” of feature (primary road, capitol city, etc.) be used for humanitarian purposes are some of the top considerations when deciding to use a dataset, so we strive to make that information more understandable when reviewing an OSM data export.

With clearer OSM data insights, humanitarians can spend more time on analyzing data and making informed decisions than on figuring out what dozens of data source with poor metadata are actually about. Organizations planning aid delivery will be able to identify crisis impacted populated centers, and road transportation to reach an impacted population and deliver aid.  

**Excited for these new resources on OSM insights? Have a request? Don’t hesitate to contact us at [data@hosm.org](mailto:data@hosm.org).** 
<br>
<br>
**Sponsored by:**
<br>
<br>
<img src="https://www.hotosm.org/uploads/h2h-logo-new-400x400.png" width="100" height="100">



