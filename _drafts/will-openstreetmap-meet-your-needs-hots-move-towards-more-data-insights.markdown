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
