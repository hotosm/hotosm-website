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
***Chart 3***
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
    const ctx = document.getElementById('attributeChart').getContext('2d');
    const attributeChart = new Chart(ctx, {
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
