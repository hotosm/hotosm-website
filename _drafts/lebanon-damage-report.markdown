---
title: Lebanon Damage Report
date: 2025-05-12 18:31:00 Z
---

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Building Dataset Completeness - Lebanon</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
        }
        #chartContainer {
            max-width: 1000px;
            margin: 0 auto;
        }
        .chart-row {
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            gap: 20px;
            margin-bottom: 30px;
        }
        .chart-wrapper {
            flex: 1;
            min-width: 400px;
        }
        h1 {
            text-align: center;
            color: #333;
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
    
    <div class="chart-row">
        <div class="chart-wrapper">
            <div id="chartContainer">
                <canvas id="totalChart"></canvas>
            </div>
        </div>
        <div class="chart-wrapper">
            <div id="chartContainer">
                <canvas id="overtureSourcesChart"></canvas>
            </div>
        </div>
    </div>

<script>
    // Data for total buildings comparison
    const totalData = [
        { city: 'Bint-Jbayl', osm: 48470, ms: 31176, overture: 36730 },
        { city: 'Maarjyoun', osm: 39462, ms: 28647, overture: 30889 },
        { city: 'Nabatiyeh', osm: 78388, ms: 45365, overture: 53739 },
        { city: 'Sour', osm: 87344, ms: 60515, overture: 70393 }
    ];

    // Data for Overture sources breakdown
    const overtureSourcesData = [
        { city: 'Bint-Jbayl', total: 36730, osm: 19285, ms: 17445 },
        { city: 'Maarjyoun', total: 30889, osm: 13861, ms: 17028 },
        { city: 'Nabatiyeh', total: 53739, osm: 29764, ms: 23975 },
        { city: 'Sour', total: 70393, osm: 47983, ms: 22410 }
    ];

    // Total buildings chart
    const totalCtx = document.getElementById('totalChart').getContext('2d');
    new Chart(totalCtx, {
        type: 'bar',
        data: {
            labels: totalData.map(item => item.city),
            datasets: [
                {
                    label: 'OpenStreetMap',
                    data: totalData.map(item => item.osm),
                    backgroundColor: '#8ED587',
                    borderColor: '#5DAE50',
                    borderWidth: 1
                },
                {
                    label: 'Microsoft',
                    data: totalData.map(item => item.ms),
                    backgroundColor: '#FFA500',
                    borderColor: '#CC8400',
                    borderWidth: 1
                },
                {
                    label: 'Overture',
                    data: totalData.map(item => item.overture),
                    backgroundColor: '#87CEEB',
                    borderColor: '#5F9EA0',
                    borderWidth: 1
                }
            ]
        },
        options: {
            responsive: true,
            plugins: {
                title: {
                    display: true,
                    text: 'Total Buildings by Dataset',
                    font: { size: 16 }
                },
                tooltip: {
                    callbacks: {
                        label: function(context) {
                            return `${context.dataset.label}: ${context.raw.toLocaleString()}`;
                        }
                    }
                }
            },
            scales: {
                y: {
                    beginAtZero: true,
                    title: {
                        display: true,
                        text: 'Number of Buildings',
                        font: { size: 14 }
                    }
                },
                x: {
                    title: {
                        display: true,
                        text: 'City',
                        font: { size: 14 }
                    }
                }
            }
        }
    });

    // Overture sources chart
    const sourcesCtx = document.getElementById('overtureSourcesChart').getContext('2d');
    new Chart(sourcesCtx, {
        type: 'bar',
        data: {
            labels: overtureSourcesData.map(item => item.city),
            datasets: [
                {
                    label: 'OSM Sources',
                    data: overtureSourcesData.map(item => item.osm),
                    backgroundColor: '#8ED587',
                    borderColor: '#5DAE50',
                    borderWidth: 1
                },
                {
                    label: 'Microsoft Sources',
                    data: overtureSourcesData.map(item => item.ms),
                    backgroundColor: '#FFA500',
                    borderColor: '#CC8400',
                    borderWidth: 1
                },
                {
                    label: 'Total Overture',
                    data: overtureSourcesData.map(item => item.total),
                    backgroundColor: 'rgba(135, 206, 235, 0.2)',
                    borderColor: '#87CEEB',
                    borderWidth: 2,
                    type: 'line',
                    fill: false,
                    pointBackgroundColor: '#87CEEB',
                    pointRadius: 5
                }
            ]
        },
        options: {
            responsive: true,
            plugins: {
                title: {
                    display: true,
                    text: 'Overture Buildings by Source',
                    font: { size: 16 }
                },
                tooltip: {
                    callbacks: {
                        label: function(context) {
                            const datasetLabel = context.dataset.label;
                            const value = context.raw;
                            if (datasetLabel === 'Total Overture') {
                                return `Total: ${value.toLocaleString()}`;
                            }
                            const percentage = Math.round((value / overtureSourcesData[context.dataIndex].total) * 100);
                            return `${datasetLabel}: ${value.toLocaleString()} (${percentage}%)`;
                        }
                    }
                }
            },
            scales: {
                y: {
                    beginAtZero: true,
                    title: {
                        display: true,
                        text: 'Number of Buildings',
                        font: { size: 14 }
                    }
                },
                x: {
                    title: {
                        display: true,
                        text: 'City',
                        font: { size: 14 }
                    }
                }
            }
        }
    });
</script>

<div class="footer">
    This visualization compares building datasets from OpenStreetMap, Microsoft, and Overture in Southern Lebanon. 
    Overture's data combines multiple sources, with varying contributions from OSM and Microsoft across different cities.
</div>
</body>
</html>




<br>
<br>


<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Building Dataset Completeness - Lebanon</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
        }
        #chartContainer {
            max-width: 900px;
            margin: 0 auto;
        }
        h1 {
            text-align: center;
            color: #333;
        }
        .footer {
            text-align: center;
            font-size: 0.8em;
            color: #778899;
            margin-top: 30px;
        }
        .legend {
            display: flex;
            justify-content: center;
            flex-wrap: wrap;
            margin: 20px 0;
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
    </style>
</head>
<body>
    <h1>Building Dataset Comparison - Southern Lebanon</h1>
    
    <div id="chartContainer">
        <canvas id="buildingChart"></canvas>
    </div>

    <div class="legend">
        <div class="legend-item">
            <div class="legend-color" style="background-color: #8ED587;"></div>
            <span>OpenStreetMap</span>
        </div>
        <div class="legend-item">
            <div class="legend-color" style="background-color: #FFA500;"></div>
            <span>Microsoft</span>
        </div>
        <div class="legend-item">
            <div class="legend-color" style="background-color: #5DAE50;"></div>
            <span>Overture (from OSM)</span>
        </div>
        <div class="legend-item">
            <div class="legend-color" style="background-color: #CC8400;"></div>
            <span>Overture (from Microsoft)</span>
        </div>
    </div>

<script>
    const cityData = [
        { city: 'Bint-Jbayl', osm: 48470, ms: 31176, overture: 36730, overtureOsm: 19285, overtureMs: 17445 },
        { city: 'Maarjyoun', osm: 39462, ms: 28647, overture: 30889, overtureOsm: 13861, overtureMs: 17028 },
        { city: 'Nabatiyeh', osm: 78388, ms: 45365, overture: 53739, overtureOsm: 29764, overtureMs: 23975 },
        { city: 'Sour', osm: 87344, ms: 60515, overture: 70393, overtureOsm: 47983, overtureMs: 22410 }
    ];

    const ctx = document.getElementById('buildingChart').getContext('2d');
    const buildingChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: cityData.map(item => item.city),
            datasets: [
                {
                    label: 'OpenStreetMap',
                    data: cityData.map(item => item.osm),
                    backgroundColor: '#8ED587',
                    borderColor: '#5DAE50',
                    borderWidth: 1
                },
                {
                    label: 'Microsoft',
                    data: cityData.map(item => item.ms),
                    backgroundColor: '#FFA500',
                    borderColor: '#CC8400',
                    borderWidth: 1
                },
                {
                    label: 'Overture (from OSM)',
                    data: cityData.map(item => item.overtureOsm),
                    backgroundColor: '#5DAE50',
                    borderColor: '#3d6e34',
                    borderWidth: 1,
                    stack: 'Overture'
                },
                {
                    label: 'Overture (from Microsoft)',
                    data: cityData.map(item => item.overtureMs),
                    backgroundColor: '#CC8400',
                    borderColor: '#996300',
                    borderWidth: 1,
                    stack: 'Overture'
                }
            ]
        },
        options: {
            responsive: true,
            plugins: {
                title: {
                    display: true,
                    text: 'Building Counts by Dataset and Source',
                    font: { size: 16 }
                },
                tooltip: {
                    mode: 'nearest',
                    intersect: false,
                    callbacks: {
                        label: function(context) {
                            return `${context.dataset.label}: ${context.raw.toLocaleString()}`;
                        },
                        afterLabel: function(context) {
                            if (context.dataset.label.includes('Overture')) {
                                const cityIndex = context.dataIndex;
                                const totalOverture = cityData[cityIndex].overture;
                                const percentage = Math.round((context.raw / totalOverture) * 100);
                                return `Part of Overture total: ${totalOverture.toLocaleString()} (${percentage}%)`;
                            }
                        }
                    }
                }
            },
            scales: {
                y: {
                    beginAtZero: true,
                    title: {
                        display: true,
                        text: 'Number of Buildings',
                        font: { size: 14 }
                    },
                    ticks: {
                        callback: function(value) {
                            return value.toLocaleString();
                        }
                    }
                },
                x: {
                    title: {
                        display: true,
                        text: 'City',
                        font: { size: 14 }
                    }
                }
            },
            interaction: {
                intersect: false,
                mode: 'nearest'
            }
        }
    });
</script>

<div class="footer">
    This visualization compares building datasets from OpenStreetMap, Microsoft, and Overture in Southern Lebanon. 
    Overture's data is shown as a stacked bar revealing its composition from OSM and Microsoft sources.
</div>
</body>
</html>


<br>
<br>
<br>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Overture Data Confidence Levels</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
        }
        #chartContainer {
            max-width: 900px;
            margin: 0 auto;
        }
        h1 {
            text-align: center;
            color: #333;
        }
        .footer {
            text-align: center;
            font-size: 0.8em;
            color: #778899;
            margin-top: 30px;
        }
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
        }
        .legend-color {
            width: 20px;
            height: 20px;
            margin-right: 8px;
            border: 1px solid #555;
        }
    </style>
</head>
<body>
    <h1>Overture Data Confidence Levels by City</h1>
    
    <div id="chartContainer">
        <canvas id="confidenceChart"></canvas>
    </div>

    <div class="legend">
        <div class="legend-item">
            <div class="legend-color" style="background-color: #FF6384;"></div>
            <span>Null Confidence</span>
        </div>
        <div class="legend-item">
            <div class="legend-color" style="background-color: #FFCE56;"></div>
            <span>Low Confidence (&lt;0.80)</span>
        </div>
        <div class="legend-item">
            <div class="legend-color" style="background-color: #36A2EB;"></div>
            <span>Medium Confidence (0.81-0.90)</span>
        </div>
        <div class="legend-item">
            <div class="legend-color" style="background-color: #4BC0C0;"></div>
            <span>High Confidence (0.91+)</span>
        </div>
    </div>

<script>
    const confidenceData = [
        { 
            city: 'Bint-Jbayl', 
            total: 36730,
            null: 19285,
            low: 70,
            medium: 573,
            high: 16500
        },
        { 
            city: 'Maarjyoun', 
            total: 30889,
            null: 13863,
            low: 41,
            medium: 438,
            high: 16290
        },
        { 
            city: 'Nabatiyeh', 
            total: 53739,
            null: 33032,
            low: 74,
            medium: 727,
            high: 19547
        },
        { 
            city: 'Sour', 
            total: 70393,
            null: 48332,
            low: 57,
            medium: 625,
            high: 21090
        }
    ];

    const ctx = document.getElementById('confidenceChart').getContext('2d');
    const confidenceChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: confidenceData.map(item => item.city),
            datasets: [
                {
                    label: 'Null Confidence',
                    data: confidenceData.map(item => item.null),
                    backgroundColor: '#FF6384',
                    borderColor: '#D04664',
                    borderWidth: 1
                },
                {
                    label: 'Low Confidence (<0.80)',
                    data: confidenceData.map(item => item.low),
                    backgroundColor: '#FFCE56',
                    borderColor: '#D9B04C',
                    borderWidth: 1
                },
                {
                    label: 'Medium Confidence (0.81-0.90)',
                    data: confidenceData.map(item => item.medium),
                    backgroundColor: '#36A2EB',
                    borderColor: '#2D8BCD',
                    borderWidth: 1
                },
                {
                    label: 'High Confidence (0.91+)',
                    data: confidenceData.map(item => item.high),
                    backgroundColor: '#4BC0C0',
                    borderColor: '#3DA8A8',
                    borderWidth: 1
                }
            ]
        },
        options: {
            responsive: true,
            plugins: {
                title: {
                    display: true,
                    text: 'Overture Data Quality by Confidence Level',
                    font: { size: 16 }
                },
                tooltip: {
                    callbacks: {
                        label: function(context) {
                            const label = context.dataset.label || '';
                            const value = context.raw;
                            const total = confidenceData[context.dataIndex].total;
                            const percentage = Math.round((value / total) * 100);
                            return `${label}: ${value.toLocaleString()} (${percentage}%)`;
                        },
                        afterLabel: function(context) {
                            return `Total: ${confidenceData[context.dataIndex].total.toLocaleString()}`;
                        }
                    }
                }
            },
            scales: {
                y: {
                    stacked: true,
                    beginAtZero: true,
                    title: {
                        display: true,
                        text: 'Number of Buildings',
                        font: { size: 14 }
                    },
                    ticks: {
                        callback: function(value) {
                            return value.toLocaleString();
                        }
                    }
                },
                x: {
                    stacked: true,
                    title: {
                        display: true,
                        text: 'City',
                        font: { size: 14 }
                    }
                }
            },
            interaction: {
                intersect: false,
                mode: 'index'
            }
        }
    });
</script>

<div class="footer">
    This visualization shows the confidence levels of Overture building data across cities in Southern Lebanon.
    Confidence values indicate the reliability of each building detection in the dataset.
</div>
</body>
</html>

<br>
<br>
<br>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Overture Data Confidence Levels</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            background-color: #f8f9fa;
        }
        #chartContainer {
            max-width: 900px;
            margin: 0 auto;
            background-color: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 10px rgba(0,0,0,0.05);
        }
        h1 {
            text-align: center;
            color: #333;
            margin-bottom: 5px;
            font-weight: 500;
        }
        .subtitle {
            text-align: center;
            color: #666;
            margin-bottom: 20px;
            font-size: 0.9em;
        }
        .footer {
            text-align: center;
            font-size: 0.8em;
            color: #778899;
            margin-top: 30px;
            line-height: 1.4;
        }
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
            font-size: 0.85em;
        }
        .legend-color {
            width: 16px;
            height: 16px;
            margin-right: 6px;
            border: 1px solid rgba(0,0,0,0.1);
            border-radius: 3px;
        }
    </style>
</head>
<body>
    <h1>Overture Data Confidence Levels</h1>
    <div class="subtitle">Southern Lebanon Cities</div>
    
    <div id="chartContainer">
        <canvas id="confidenceChart"></canvas>
    </div>

    <div class="legend">
        <div class="legend-item">
            <div class="legend-color" style="background-color: #ffcdd2; border-color: #ef9a9a;"></div>
            <span>Null Confidence</span>
        </div>
        <div class="legend-item">
            <div class="legend-color" style="background-color: #ffe0b2; border-color: #ffcc80;"></div>
            <span>Low/Medium Confidence (&lt;0.91)</span>
        </div>
        <div class="legend-item">
            <div class="legend-color" style="background-color: #c8e6c9; border-color: #a5d6a7;"></div>
            <span>High Confidence (0.91+)</span>
        </div>
    </div>

<script>
    const confidenceData = [
        { 
            city: 'Bint-Jbayl', 
            total: 36730,
            null: 19285,
            low_medium: 643,
            high: 16500
        },
        { 
            city: 'Maarjyoun', 
            total: 30889,
            null: 13863,
            low_medium: 479,
            high: 16290
        },
        { 
            city: 'Nabatiyeh', 
            total: 53739,
            null: 33032,
            low_medium: 801,
            high: 19547
        },
        { 
            city: 'Sour', 
            total: 70393,
            null: 48332,
            low_medium: 682,
            high: 21090
        }
    ];

    const ctx = document.getElementById('confidenceChart').getContext('2d');
    const confidenceChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: confidenceData.map(item => item.city),
            datasets: [
                {
                    label: 'Null Confidence',
                    data: confidenceData.map(item => item.null),
                    backgroundColor: 'rgba(255, 205, 210, 0.8)',
                    borderColor: 'rgba(239, 154, 154, 0.8)',
                    borderWidth: 1
                },
                {
                    label: 'Low/Medium Confidence (<0.91)',
                    data: confidenceData.map(item => item.low_medium),
                    backgroundColor: 'rgba(255, 224, 178, 0.8)',
                    borderColor: 'rgba(255, 204, 128, 0.8)',
                    borderWidth: 1
                },
                {
                    label: 'High Confidence (0.91+)',
                    data: confidenceData.map(item => item.high),
                    backgroundColor: 'rgba(200, 230, 201, 0.8)',
                    borderColor: 'rgba(165, 214, 167, 0.8)',
                    borderWidth: 1
                }
            ]
        },
        options: {
            responsive: true,
            plugins: {
                title: {
                    display: false
                },
                tooltip: {
                    callbacks: {
                        label: function(context) {
                            const label = context.dataset.label || '';
                            const value = context.raw;
                            const total = confidenceData[context.dataIndex].total;
                            const percentage = Math.round((value / total) * 100);
                            return `${label}: ${value.toLocaleString()} (${percentage}%)`;
                        },
                        afterLabel: function(context) {
                            return `Total: ${confidenceData[context.dataIndex].total.toLocaleString()}`;
                        }
                    }
                },
                legend: {
                    display: false
                }
            },
            scales: {
                y: {
                    stacked: true,
                    beginAtZero: true,
                    title: {
                        display: true,
                        text: 'Number of Buildings',
                        font: { size: 12, color: '#555' }
                    },
                    ticks: {
                        callback: function(value) {
                            return value.toLocaleString();
                        },
                        font: { color: '#666' }
                    },
                    grid: {
                        color: 'rgba(0,0,0,0.05)'
                    }
                },
                x: {
                    stacked: true,
                    title: {
                        display: true,
                        text: 'City',
                        font: { size: 12, color: '#555' }
                    },
                    grid: {
                        display: false
                    },
                    ticks: {
                        font: { color: '#666' }
                    }
                }
            },
            interaction: {
                intersect: false,
                mode: 'index'
            }
        }
    });
</script>

<div class="footer">
    This visualization shows the confidence levels of Overture building data across cities in Southern Lebanon.<br>
    Color progression from left (null confidence) to right (high confidence) indicates improving data quality.
</div>
</body>
</html>



<br>
<br>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>OSM Building Completeness Analysis</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            background-color: #f8f9fa;
        }
        .chart-container {
            max-width: 900px;
            margin: 20px auto;
            background-color: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 10px rgba(0,0,0,0.05);
        }
        h1 {
            text-align: center;
            color: #333;
            margin-bottom: 5px;
            font-weight: 500;
        }
        .footer {
            text-align: center;
            font-size: 0.8em;
            color: #778899;
            margin-top: 30px;
            line-height: 1.4;
        }
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
            font-size: 0.85em;
        }
        .legend-color {
            width: 16px;
            height: 16px;
            margin-right: 6px;
            border: 1px solid rgba(0,0,0,0.1);
            border-radius: 3px;
        }
    </style>
</head>
<body>
    <h1>OSM Building Completeness Analysis</h1>
    
    <div class="chart-container">
        <canvas id="countChart"></canvas>
    </div>
    
    <div class="chart-container">
        <canvas id="completenessChart"></canvas>
    </div>

    <div class="footer">
        Comparison of OSM building data against AI estimates in Southern Lebanon.<br>
        Completeness 2 percentage measures how thoroughly buildings are mapped in OSM.
    </div>

<script>
    // Data for both charts
    const cityData = [
        { city: 'Bint-Jbayl', osmCount: 48470, aiCount: 49026, completeness: 98.87 },
        { city: 'Maarjyoun', osmCount: 39462, aiCount: 40460, completeness: 97.53 },
        { city: 'Nabatiyeh', osmCount: 78388, aiCount: 80363, completeness: 97.54 },
        { city: 'Sour', osmCount: 87344, aiCount: 88929, completeness: 98.22 }
    ];

    // 1. Building Count Comparison Chart
    const countCtx = document.getElementById('countChart').getContext('2d');
    new Chart(countCtx, {
        type: 'bar',
        data: {
            labels: cityData.map(item => item.city),
            datasets: [
                {
                    label: 'OSM Buildings',
                    data: cityData.map(item => item.osmCount),
                    backgroundColor: 'rgba(100, 181, 246, 0.7)',
                    borderColor: 'rgba(66, 165, 245, 0.8)',
                    borderWidth: 1
                },
                {
                    label: 'AI Estimated Buildings',
                    data: cityData.map(item => item.aiCount),
                    backgroundColor: 'rgba(255, 213, 79, 0.7)',
                    borderColor: 'rgba(255, 202, 40, 0.8)',
                    borderWidth: 1
                }
            ]
        },
        options: {
            responsive: true,
            plugins: {
                title: {
                    display: true,
                    text: 'Building Count Comparison',
                    font: { size: 16 }
                },
                tooltip: {
                    callbacks: {
                        label: function(context) {
                            return `${context.dataset.label}: ${context.raw.toLocaleString()}`;
                        }
                    }
                }
            },
            scales: {
                y: {
                    beginAtZero: true,
                    title: {
                        display: true,
                        text: 'Number of Buildings'
                    },
                    ticks: {
                        callback: function(value) {
                            return value.toLocaleString();
                        }
                    }
                }
            }
        }
    });

    // 2. Completeness Percentage Chart
    const compCtx = document.getElementById('completenessChart').getContext('2d');
    new Chart(compCtx, {
        type: 'bar',
        data: {
            labels: cityData.map(item => item.city),
            datasets: [
                {
                    label: 'Completeness 2 (%)',
                    data: cityData.map(item => item.completeness),
                    backgroundColor: 'rgba(129, 199, 132, 0.7)',
                    borderColor: 'rgba(102, 187, 106, 0.8)',
                    borderWidth: 1
                }
            ]
        },
        options: {
            responsive: true,
            plugins: {
                title: {
                    display: true,
                    text: 'OSM Completeness 2 Percentage',
                    font: { size: 16 }
                },
                tooltip: {
                    callbacks: {
                        label: function(context) {
                            return `${context.dataset.label}: ${context.raw.toFixed(2)}%`;
                        }
                    }
                }
            },
            scales: {
                y: {
                    beginAtZero: false,
                    min: 97,
                    max: 100,
                    title: {
                        display: true,
                        text: 'Percentage (%)'
                    },
                    ticks: {
                        callback: function(value) {
                            return value + '%';
                        }
                    }
                }
            }
        }
    });
</script>
</body>
</html>




<!DOCTYPE html>
<html>
<head>
    <title>Damage Assessment Comparison</title>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
            max-width: 900px;
            margin: 0 auto;
            padding: 20px;
        }
        .chart-container {
            width: 100%;
            height: 500px;
            margin: 30px 0;
            position: relative;
        }
        h1 {
            color: #333;
            text-align: center;
        }
        .custom-labels {
            display: flex;
            justify-content: space-between;
            margin-top: 15px;
        }
        .custom-label {
            text-align: center;
            width: 18%;
        }
        .label-title {
            font-weight: bold;
            font-size: 14px;
            margin-bottom: 3px;
        }
        .label-subtitle {
            font-size: 13px;
            margin-bottom: 3px;
        }
        .label-date {
            font-size: 11px;
            color: #666;
        }
        .method-legend {
            display: flex;
            justify-content: center;
            margin-top: 20px;
            gap: 20px;
        }
        .legend-item {
            display: flex;
            align-items: center;
        }
        .legend-color {
            width: 20px;
            height: 20px;
            margin-right: 8px;
            border: 1px solid #333;
        }
    </style>
</head>
<body>
    <h1>Damage Assessment Comparison</h1>
    
    <div class="chart-container">
        <canvas id="damageChart"></canvas>
        <div class="custom-labels" id="customLabels"></div>
    </div>

    <div class="method-legend">
        <div class="legend-item">
            <div class="legend-color" style="background-color: #1f77b4;"></div>
            <span>SAR Methods</span>
        </div>
        <div class="legend-item">
            <div class="legend-color" style="background-color: #ff7f0e;"></div>
            <span>Optical Methods</span>
        </div>
    </div>

<script>
    // Updated data with method information
    const damageData = [
        { 
            source: "Scher, Van Den Hoek",
            assessment: "damaged or destroyed",
            date: "As of 5 Dec '24",
            value: 4796,
            method: "SAR",
            methodDetail: "inSAR coherent change detection"
        },
        { 
            source: "UN Habitat Commissioned",
            assessment: "partially/totally destroyed",
            date: "As of 3 Dec '24",
            value: 5129,
            method: "Optical",
            methodDetail: "Optical visual inspection"
        },
        { 
            source: "ESRI Deep Learning",
            assessment: "damaged structures",
            date: "As of 21 Oct '24",
            value: 5400,
            method: "Optical",
            methodDetail: "Optical deep learning"
        },
        { 
            source: "Miyamoto",
            assessment: "moderately or severely damaged",
            date: "As of 22 Nov '24",
            value: 12282,
            method: "SAR",
            methodDetail: "SAR backscattering + other"
        },
        { 
            source: "MercyCorps",
            assessment: "damaged or destroyed",
            date: "As of 31 Oct '24",
            value: 14916,
            method: "SAR",
            methodDetail: "SAR backscattering"
        }
    ];

    // Color definitions
    const sarColors = {
        base: '#1f77b4',
        light: '#5d9cec',
        dark: '#0d5ba8'
    };
    const opticalColors = {
        base: '#ff7f0e',
        light: '#ffa042',
        dark: '#d45b00'
    };

    // Assign colors based on method and specific technique
    function getBarColor(item) {
        if (item.method === "SAR") {
            if (item.methodDetail.includes("inSAR")) return sarColors.light;
            if (item.methodDetail.includes("+ other")) return sarColors.base;
            return sarColors.dark;
        } else { // Optical
            if (item.methodDetail.includes("visual")) return opticalColors.light;
            return opticalColors.base;
        }
    }

    // Function to create hierarchical labels
    function createLabelHtml(item) {
        let html = `<div class="custom-label">`;
        html += `<div class="label-title">${item.source}</div>`;
        html += `<div class="label-subtitle">${item.assessment}</div>`;
        html += `<div class="label-subtitle" style="font-style: italic;">${item.methodDetail}</div>`;
        html += `<div class="label-date">${item.date}</div>`;
        html += `</div>`;
        return html;
    }

    // Damage assessment chart
    const damageCtx = document.getElementById('damageChart').getContext('2d');
    new Chart(damageCtx, {
        type: 'bar',
        data: {
            labels: damageData.map(() => ''),
            datasets: [{
                label: 'Number of Structures',
                data: damageData.map(item => item.value),
                backgroundColor: damageData.map(item => getBarColor(item)),
                borderColor: damageData.map(item => {
                    return item.method === "SAR" ? sarColors.dark : opticalColors.dark;
                }),
                borderWidth: 1,
                barThickness: 'flex',
                categoryPercentage: 0.8,
                barPercentage: 0.9
            }]
        },
        options: {
            responsive: true,
            maintainAspectRatio: false,
            plugins: {
                title: {
                    display: true,
                    text: 'Damage Assessment Comparison by Organization and Method',
                    font: { size: 18 }
                },
                tooltip: {
                    callbacks: {
                        label: function(context) {
                            const item = damageData[context.dataIndex];
                            return [
                                `${item.source}: ${item.value.toLocaleString()}`,
                                `Method: ${item.methodDetail}`,
                                `Date: ${item.date}`
                            ];
                        }
                    }
                },
                legend: {
                    display: false
                }
            },
            scales: {
                y: {
                    beginAtZero: true,
                    grid: {
                        display: false
                    },
                    title: {
                        display: true,
                        text: 'Number of Structures',
                        font: { size: 14 }
                    },
                    ticks: {
                        callback: function(value) {
                            return value.toLocaleString();
                        }
                    }
                },
                x: {
                    grid: {
                        display: false
                    },
                    ticks: {
                        display: false
                    }
                }
            },
            animation: {
                onComplete: function() {
                    // Add value labels on top of bars
                    const ctx = this.ctx;
                    ctx.font = 'bold 12px Arial';
                    ctx.textAlign = 'center';
                    ctx.textBaseline = 'bottom';
                    ctx.fillStyle = '#333';
                    
                    this.data.datasets.forEach((dataset, i) => {
                        const meta = this.getDatasetMeta(i);
                        meta.data.forEach((bar, index) => {
                            const data = dataset.data[index];
                            ctx.fillText(data.toLocaleString(), bar.x, bar.y - 5);
                        });
                    });
                }
            }
        }
    });

    // Add custom labels after chart is created
    document.addEventListener('DOMContentLoaded', function() {
        const labelContainer = document.getElementById('customLabels');
        
        damageData.forEach(item => {
            labelContainer.innerHTML += createLabelHtml(item);
        });
    });
</script>

</body>
</html>