---
title: test graphs
date: 2025-06-03 18:55:00 Z
---

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Building Dataset Comparison - Lebanon</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            line-height: 1.6;
        }
        .table-container {
            max-width: 900px;
            margin: 0 auto;
            overflow-x: auto;
        }
        h1 {
            text-align: center;
            color: #333;
            margin-bottom: 20px;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin: 20px 0;
            box-shadow: 0 2px 10px rgba(0,0,0,0.1);
        }
        th, td {
            padding: 12px 15px;
            text-align: center;
            border: 1px solid #ddd;
        }
        th {
            background-color: #f2f2f2;
            font-weight: bold;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
        .osm { background-color: #e6f7e6; }
        .ms { background-color: #fff2e6; }
        .overture { background-color: #e6f2ff; }
        .highlight { font-weight: bold; }
        .highlight-second { font-style: italic; }
        .legend {
            display: flex;
            justify-content: center;
            flex-wrap: wrap;
            margin: 20px 0;
            gap: 15px;
        }
        .legend-item {
            display: flex;
            align-items: center;
            margin: 0 15px;
        }
        .legend-color {
            width: 20px;
            height: 20px;
            margin-right: 8px;
            border: 1px solid #555;
        }
        .footer {
            text-align: center;
            font-size: 0.8em;
            color: #778899;
            margin-top: 30px;
        }
    </style>
</head>
<body>
    <h1>Building Dataset Comparison - Southern Lebanon</h1>

    <div class="table-container">
        <table>
            <thead>
                <tr>
                    <th>City</th>
                    <th>Overture</th>
                    <th>Microsoft Buildings</th>
                    <th>OSM Buildings</th>
                    <th>% OSM > MS</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td>Bint-Jbayl</td>
                    <td class="overture">36,730</td>
                    <td class="ms highlight-second">31,176</td>
                    <td class="osm highlight">48,470</td>
                    <td>+55.5%</td>
                </tr>
                <tr>
                    <td>Maarjyoun</td>
                    <td class="overture">30,889</td>
                    <td class="ms highlight-second">28,647</td>
                    <td class="osm highlight">39,462</td>
                    <td>+37.8%</td>
                </tr>
                <tr>
                    <td>Nabatiyeh</td>
                    <td class="overture">53,739</td>
                    <td class="ms highlight-second">45,365</td>
                    <td class="osm highlight">78,388</td>
                    <td>+72.8%</td>
                </tr>
                <tr>
                    <td>Sour</td>
                    <td class="overture">70,393</td>
                    <td class="ms highlight-second">60,515</td>
                    <td class="osm highlight">87,344</td>
                    <td>+44.3%</td>
                </tr>
            </tbody>
        </table>
    </div>

    <div class="footer">
        This table compares building datasets from OpenStreetMap, Microsoft, and Overture in Southern Lebanon.<br>
        The "% OSM > MS" column shows how much larger the OSM dataset is compared to Microsoft's dataset.
    </div>
</body>
</html>