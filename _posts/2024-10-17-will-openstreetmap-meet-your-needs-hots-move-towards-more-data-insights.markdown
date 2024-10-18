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
Feature Image: "/uploads/HAITI%20(1).jpg"
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

<br>
***IMAGE CHART HERE***
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Combined 'Point' Values Chart</title>
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
    <canvas id="pointValuesChart"></canvas>
</div>

<script>
    const ctx3 = document.getElementById('pointValuesChart').getContext('2d');
    const pointValuesChart = new Chart(ctx3, {
        type: 'bar',
        data: {
            labels: [
                'isolated_dwelling',
                'hamlet',
                'Settlement',
                'village',
                'nomadic settlement',
                'IDP Camp',
                'Part of town',
                'town',
                'District Capital',
                'city',
                'Regional Capital',
                'Town',
                'National Capital'
            ],
            datasets: [
                {
                    label: 'HOT',
                    data: [38000, 18000, 0, 9000, 2000, 0, 0, 1000, 500, 200, 100, 0, 0],
                    backgroundColor: 'rgba(60, 120, 216, 1)',
                    borderWidth: 1
                },
                {
                    label: 'OCHA',
                    data: [0, 0, 14000, 0, 2000, 500, 0, 0, 0, 0, 0, 0, 0],
                    backgroundColor: 'rgba(243, 177, 70, 1)',
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
                    },
                    ticks: {
                        callback: function(value) {
                            return value; // Add count label
                        }
                    }
                }
            },
            plugins: {
                title: {
                    display: true,
                    text: "Combined 'Point' Values",
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
*Comparing the amount of HOT’s vs. OCHA’s “types” of populated places in Somalia*
<br>

**Example 2. Country: South Sudan, Dataset:Roads**
* **Coverage**
  * HOT has 99% more features than OCHA, with **176,345 road features in OSM** vs **976 in OCHA**.  
  * Despite having significantly less individual features, OCHA has decent spatial coverage with 69% of HOT’s coverage (**43,164 kms** vs **137,476 kms**). 
* **“Type”**
  * OCHA only has **river and road** for transportation “type”, while HOT’s OSM dataset has **path, track, residential, tertiary, and primary, secondary, footway, etc.**  

<br>
***IMAGE CHART HERE***

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
        #chartContainer {
            max-width: 1000px;
            margin: 0 auto;
        }
    </style>
</head>
<body>

<div id="chartContainer">
    <canvas id="highwayValuesChart"></canvas>
</div>

<script>
    const ctx4 = document.getElementById('highwayValuesChart').getContext('2d');
    const highwayValuesChart = new Chart(ctx4, {
        type: 'bar',
        data: {
            labels: [
                'path',
                'road',
                'track',
                'unclassified',
                'residential',
                'tertiary',
                'primary',
                'river',
                'secondary',
                'service',
                'footway',
                'proposed',
                'construction',
                'bridleway',
                'pedestrian',
                'living_street',
                'small_river',
                'primary_link',
                'trunk',
                'tertiary_link',
                'steps',
                'secondary_link'
            ],
            datasets: [
                {
                    label: 'HOT',
                    data: [44000, 30000, 10000, 8000, 5000, 5000, 4000, 0, 3000, 2000, 1000, 500, 500, 500, 500, 500, 0, 0, 0, 0, 0, 0],
                    backgroundColor: 'rgba(60, 120, 216, 1)',
                    borderWidth: 1
                },
                {
                    label: 'OCHA',
                    data: [0, 27000, 0, 0, 3000, 0, 4000, 2000, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 0, 0, 0],
                    backgroundColor: 'rgba(243, 177, 70, 1)',
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

*Comparing the amount of HOT’s vs. OCHA’s “types” of roads in South Sudan*
<br>

*** What’s next? ***

Based on these insights, we are currently working on adding additional data quality statistics to the metadata of our OSM exports. Attributes like feature name, spatial coverage, or how can a “type” of feature (primary road, capitol city, etc.) be used for humanitarian purposes are some of the top considerations when deciding to use a dataset, so we strive to make that information more understandable when reviewing an OSM data export.

With clearer OSM data insights, humanitarians can spend more time on analyzing data and making informed decisions than on data sources. Organizations planning aid delivery will be able to identify crisis impacted populated centers, and road transportation to reach an impacted population and deliver aid. 

**Excited for these new resources on OSM insights? Have a request? Don’t hesitate to contact us at [data@hosm.org](mailto:data@hosm.org).** 

