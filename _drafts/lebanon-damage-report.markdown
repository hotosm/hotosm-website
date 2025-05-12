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
