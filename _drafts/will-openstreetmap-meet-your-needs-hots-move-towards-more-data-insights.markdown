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
It is not possible to recreate the exact color formatting in Markdown alone, as Markdown does not natively support background colors for table cells. However, you can use HTML alongside Markdown to style the table with colors. Here's a Markdown table with inline HTML to match the color scheme from the image:

```html
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
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
  </tr>
  <tr>
    <td>Burkina Faso</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
  </tr>
  <tr>
    <td>Cameroon</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue">HDX</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
  </tr>
  <tr>
    <td>CAR</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">HDX</td>
    <td style="background-color:lightblue">OCHA</td>
  </tr>
  <tr>
    <td>Chad</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">HDX</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
  </tr>
  <tr>
    <td>Colombia</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OurAirports</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
  </tr>
  <tr>
    <td>Democratic Congo</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
  </tr>
  <tr>
    <td>Ethiopia</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">HDX</td>
    <td style="background-color:lightblue">OCHA</td>
  </tr>
  <tr>
    <td>Haiti</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
  </tr>
  <tr>
    <td>Mali</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
  </tr>
  <tr>
    <td>Mozambique</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue">WHO</td>
    <td style="background-color:lightblue">OCHA</td>
  </tr>
  <tr>
    <td>Myanmar</td>
    <td style="background-color:lightblue">MIMU</td>
    <td style="background-color:lightblue">MIMU</td>
    <td style="background-color:lightblue">MIMU</td>
    <td style="background-color:lightblue">MIMU</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue">MIMU</td>
  </tr>
  <tr>
    <td>Niger</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
  </tr>
  <tr>
    <td>Nigeria</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue">HDX</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
  </tr>
  <tr>
    <td>Somalia</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue;color:red;">HOT</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">WHO</td>
    <td style="background-color:lightblue">OCHA</td>
  </tr>
  <tr>
    <td>South Sudan</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">HDX</td>
    <td style="background-color:lightblue">IOM</td>
  </tr>
  <tr>
    <td>State of Palestine</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</td>
    <td style="background-color:lightblue">OCHA</>