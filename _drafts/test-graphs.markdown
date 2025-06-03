---
title: test graphs
date: 2025-06-03 18:55:00 Z
---

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Total Building Dataset Comparison - Lebanon</title>
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
    <h1>Total Building Dataset Comparison - Southern Lebanon</h1>

    <div class="table-container">
        <table>
            <thead>
                <tr>
                    <th>District</th>
                    <th>Overture</th>
                    <th>Microsoft Buildings</th>
                    <th>OSM Buildings</th>
                    <th>% OSM > MS</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td>Bint Jbeil</td>
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


<!DOCTYPE html>
<html>
<head>
    <title>Damage Assessment Comparison Table</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            max-width: 900px;
            margin: 0 auto;
            padding: 20px;
            color: #333;
        }
        h1 {
            text-align: center;
            margin-bottom: 30px;
        }
        .data-table {
            width: 100%;
            border-collapse: collapse;
            margin: 20px 0;
            box-shadow: 0 2px 10px rgba(0,0,0,0.1);
        }
        .data-table th, .data-table td {
            padding: 12px 15px;
            text-align: left;
            border-bottom: 1px solid #ddd;
        }
        .data-table th {
            background-color: #f8f9fa;
            font-weight: bold;
            position: sticky;
            top: 0;
        }
        .data-table tr:hover {
            background-color: #f5f5f5;
        }
        .method-sar {
            background-color: rgba(31, 119, 180, 0.1);
            border-left: 4px solid #1f77b4;
        }
        .method-optical {
            background-color: rgba(255, 127, 14, 0.1);
            border-left: 4px solid #ff7f0e;
        }
        .method-label {
            display: inline-block;
            padding: 3px 8px;
            border-radius: 4px;
            font-size: 12px;
            font-weight: bold;
        }
        .sar-label {
            background-color: #1f77b4;
            color: white;
        }
        .optical-label {
            background-color: #ff7f0e;
            color: white;
        }
        .value-cell {
            font-weight: bold;
            text-align: right;
        }
        @media (max-width: 600px) {
            .data-table {
                display: block;
                overflow-x: auto;
            }
        }
    </style>
</head>
<body>
    <h1>Damage Assessment Comparison</h1>
    
    <table class="data-table">
        <thead>
            <tr>
                <th>Organization</th>
                <th>Assessment Method</th>
                <th>Damage Classification</th>
                <th>Date</th>
                <th class="value-cell">Structures Affected</th>
            </tr>
        </thead>
        <tbody>
            <tr class="method-sar">
                <td>Scher, Van Den Hoek</td>
                <td><span class="method-label sar-label">SAR</span></td>
                <td>inSAR coherent change detection</td>
                <td>5 Dec 2024</td>
                <td class="value-cell">4,796</td>
            </tr>
            <tr class="method-optical">
                <td>UN Habitat Commissioned</td>
                <td><span class="method-label optical-label">Optical</span></td>
                <td>Optical visual inspection</td>
                <td>3 Dec 2024</td>
                <td class="value-cell">5,129</td>
            </tr>
            <tr class="method-optical">
                <td>ESRI Deep Learning</td>
                <td><span class="method-label optical-label">Optical</span></td>
                <td>Optical deep learning</td>
                <td>21 Oct 2024</td>
                <td class="value-cell">5,400</td>
            </tr>
            <tr class="method-sar">
                <td>Miyamoto</td>
                <td><span class="method-label sar-label">SAR</span></td>
                <td>SAR backscattering + other</td>
                <td>22 Nov 2024</td>
                <td class="value-cell">12,282</td>
            </tr>
            <tr class="method-sar">
                <td>MercyCorps</td>
                <td><span class="method-label sar-label">SAR</span></td>
                <td>SAR backscattering</td>
                <td>31 Oct 2024</td>
                <td class="value-cell">14,916</td>
            </tr>
        </tbody>
    </table>

    <div style="margin-top: 40px; text-align: center;">
        <div style="display: inline-block; margin-right: 20px;">
            <span style="display: inline-block; width: 15px; height: 15px; background-color: #1f77b4; margin-right: 5px;"></span>
            <span>SAR Methods</span>
        </div>
        <div style="display: inline-block;">
            <span style="display: inline-block; width: 15px; height: 15px; background-color: #ff7f0e; margin-right: 5px;"></span>
            <span>Optical Methods</span>
        </div>
    </div>
</body>
</html>
