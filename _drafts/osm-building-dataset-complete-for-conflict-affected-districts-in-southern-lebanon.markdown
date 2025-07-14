---
title: OSM Building Dataset Complete for Conflict Affected Districts in Southern Lebanon
date: 2025-07-11 17:33:00 Z
Summary Text: 'Accurate building footprints are needed to identify the impact of conflict
  on affected communities. After a dedicated volunteer effort, OSM building footprints
  are now the leading data source in the southern Lebanon districts of Sour, Bint
  Jbeil, Marjayoun, and El Nabatieh. '
---

Conflict in southern Lebanon escalated sharply from October - November 2024, following the 2023 Gaza/Israeli conflict that heightened tensions among Israel, Lebanon, and Palestine ([ACLED: Lebanon ceasefire](https://acleddata.com/2025/01/29/lebanon-ceasefire-despite-extensive-demolitions-israel-says-its-job-isnt-finished/)). In order to understand the impact of the conflict on communities, an accurate building footprint dataset was needed, but Microsoft and OpenStreetMap building footprints were quickly identified as incomplete, see [Filling OSM Buildings Data Gaps for Recovery in Lebanon](https://www.hotosm.org/updates/filling-osm-buildings-data-gaps-in-lebanon/). Identifying potentially impacted buildings in a rural mountainous region proved difficult for humanitarian analysts.

<br>
<div style="text-align: center;">
    <img src="/uploads/lebanon-buildigns-2025.png" alt="Added buildings in Lebanon" style="width: 95%; height: auto;">
    <div style="font-size: 0.8em; color: #778899; line-height: 1.2; margin-top: 10px;">
        <span>The following map shows the areas where HOTOSM mapped for the Lebanon 2024 campagin. It covered 4 districts and mapped almost 200k buidlings thanks to 356 contributors.</span>
    </div>
</div>

<br>

To fill the buildings data gap in southern Lebanon, HOT coordinated 357 volunteer OSM contributors, who made over 319,00 edits to OSM from November 2024-March 2025. Some of those mappers came from a new and growing OSM community in Lebanon, see [Mapping Hope: Rebuilding Lebanon After Conflict](https://hsph.harvard.edu/atrocity-prevention-lab/news/mapping-hope-rebuilding-lebanon-after-conflict/). 

HOT Tasking Manager Campaign [Statistics](https://stats.now.ohsome.org/dashboard#hashtag=LebanonUpdate2024&start=2024-10-01T06:00:00Z&end=2025-07-04T06:00:00Z&interval=P1M&active_topic=edit&countries=&topics=building,contributor,road,edit), #LebanonUpdate2024
**OSM building activity below in fuchsia**  


<br>
<div style="text-align: center;">
    <img src="/uploads/ohsome-dashboard-lebanonupdate2024.png" alt="Added buildings in Lebanon according to OHSOME dashboard" style="width: 95%; height: auto;">
    <div style="font-size: 0.8em; color: #778899; line-height: 1.2; margin-top: 10px;">
        <span>Number of buildings as shown with the <a href="https://stats.now.ohsome.org/dashboard#hashtag=lebanonupdate2024&start=2024-10-31T20:00:00Z&end=2025-03-31T21:00:00Z&interval=P1W&active_topic=building&countries=&topics=building,contributor,road,edit">OHSOME dashboard</a> for the Lebanon HOTOSM campaign.
</span>
    </div>
</div>

<br>

**Is OSM now complete in the 4 southern districts in Lebanon?** 

Yes. Besides the entire area being double checked by expert OSM validators (see [validation example from Turkey earthquake](https://www.hotosm.org/updates/hot-approach-to-osm-data-validation-to-eq-mapping-projects/) for more on validation), AI estimates also give confidence the OSM dataset is near complete. Using AI calculations by Kontur derived from population and density, **OSM coverage in the 4 districts can be considered nearly complete**. See the graph below where blue are OSM counts, and yellow are AI estimated counts. 


<br>
<div id="chartContainer">
    <canvas id="buildingChart"></canvas>
</div>

<script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
<script>
    const ctx = document.getElementById('buildingChart').getContext('2d');
    const buildingChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: ['Bint Jbeil', 'Maariyoun', 'Nabatiyeh', 'Sour'],
            datasets: [
                {
                    label: 'OSM Buildings',
                    data: [48000, 39000, 78000, 85000], // Approximate lower values (adjust as needed)
                    backgroundColor: 'rgba(75, 192, 192, 0.7)', // Teal for OSM
                    borderColor: 'rgba(75, 192, 192, 1)',
                    borderWidth: 1
                },
                {
                    label: 'AI Estimated Buildings',
                    data: [50000, 40000, 80000, 90000], // Approximate higher values (adjust as needed)
                    backgroundColor: 'rgba(255, 159, 64, 0.7)', // Orange for AI
                    borderColor: 'rgba(255, 159, 64, 1)',
                    borderWidth: 1
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
                        text: 'Number of Buildings',
                        font: { size: 16 }
                    },
                    ticks: {
                        // Match the scale in your image
                        callback: function(value) {
                            return value.toLocaleString();
                        },
                        stepSize: 10000,
                        max: 90000
                    }
                },
                x: {
                    grid: {
                        display: false
                    }
                }
            },
            plugins: {
                title: {
                    display: true,
                    text: 'Building Count Comparison',
                    font: { size: 18 }
                },
                tooltip: {
                    callbacks: {
                        label: function(context) {
                            return `${context.dataset.label}: ${context.raw.toLocaleString()}`;
                        }
                    }
                }
            }
        }
    });
</script>

<div style="text-align: center;">
    <div style="font-size: 0.8em; color: #778899; margin-top: 10px;">
        Building count comparison across the different districts where mapping took place, showing the OSM numbers almost equal to predicted total of buildings done by AI. 
    </div>
</div>

<br>



**How does OSM building footprints compare to other popular data sources?** 

In areas of dedicated crowdsourced OpenStreetMap efforts, **OSM has been shown to outperform automated machine learning datasets in terms of coverage and precision,** such as [in Gaza last year](https://www.hotosm.org/updates/gaza-osm-buildings-update-2024/)**.**  The same holds true in Lebanon, where **OSM also has 65% more buildings in the 4 districts than the other leading open buildings footprints dataset from Microsoft (165,703 vs 253,664).**   Overture, an emerging aggregator of open data, can lags behind OSM updates, as shown by the lower numbers of Overture than OSM as of May 2025 below. 


<br>

<div class="lebanon-building-table">
  <h2>Total Building Dataset Comparison - Southern Lebanon</h2>
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
        <td>36,730</td>
        <td>31,176</td>
        <td class="osm-cell">48,470</td>
        <td class="percent-cell">+55.5%</td>
      </tr>
      <tr>
        <td>Maarjyoun</td>
        <td>30,889</td>
        <td>28,647</td>
        <td class="osm-cell">39,462</td>
        <td class="percent-cell">+37.8%</td>
      </tr>
      <tr>
        <td>Nabatiyeh</td>
        <td>53,739</td>
        <td>45,365</td>
        <td class="osm-cell">78,388</td>
        <td class="percent-cell">+72.8%</td>
      </tr>
      <tr>
        <td>Sour</td>
        <td>70,393</td>
        <td>60,515</td>
        <td class="osm-cell">87,344</td>
        <td class="percent-cell">+44.3%</td>
      </tr>
    </tbody>
  </table>
  <div class="table-footer">
    This table compares building datasets from OpenStreetMap, Microsoft, and Overture in Southern Lebanon.<br>
    The "% OSM > MS" column shows how much larger the OSM dataset is compared to Microsoft's dataset.
  </div>
</div>

<style>
.lebanon-building-table {
  font-family: Arial, sans-serif;
  max-width: 800px;
  margin: 20px auto;
  box-shadow: 0 0 10px rgba(0,0,0,0.1);
  padding: 20px;
  border-radius: 5px;
}

.lebanon-building-table h2 {
  color: #333;
  font-size: 1.3em;
  margin-bottom: 15px;
  text-align: center;
}

.lebanon-building-table table {
  width: 100%;
  border-collapse: collapse;
}

.lebanon-building-table th {
  background-color: #f2f2f2;
  padding: 12px 15px;
  text-align: left;
  border-bottom: 2px solid #ddd;
  font-weight: bold;
}

.lebanon-building-table td {
  padding: 10px 15px;
  border-bottom: 1px solid #eee;
}

.lebanon-building-table tr:hover {
  background-color: #f9f9f9;
}

.osm-cell {
  color: #4bc0c0;
  font-weight: bold;
}

.percent-cell {
  color: #2ecc71;
  font-weight: bold;
}

.table-footer {
  margin-top: 15px;
  font-size: 0.9em;
  color: #666;
  line-height: 1.5;
}
</style>

<br>

### Beyond counts, is OSM more accurate than other data sources? 

Humans-in-the-loop validated OSM data also produces more precise building footprint geometries than automated methods. On visual inspection in Lebanon, OSM building geometry is more accurate when compared with Microsoft Machine Learning Buildings Footprints in Lebanon, see examples below.


<br>
<div style="text-align: center;">
    <img src="/uploads/lebanon-buildigns-2025.png" alt="Added buildings in Lebanon" style="width: 95%; height: auto;">
    <div style="font-size: 0.8em; color: #778899; line-height: 1.2; margin-top: 10px;">
        <span>The following map shows the areas where HOTOSM mapped for the Lebanon 2024 campagin. It covered 4 districts and mapped almost 200k buidlings thanks to 356 contributors.</span>
    </div>
</div>

<br>

**Fast building data immediately vs better data later**

While coverage of building footprints in OSM is improving constantly, there are still gaps globally, see [Analysis of OSM building data completeness using new data](https://heigit.org/analysis-of-osm-building-data-completeness-using-new-data/). When HOT launches a campaign to improve building footprints in a given area after a rapid onset crisis, it usually will not be complete enough for immediate rapid humanitarian needs. Other open automated datasets (such as from Microsoft), are used. **As crowdsourced and validated OSM is shown to outperform these datasets, it is important to update any analysis in southern Lebanon that originally used  Microsoft or other automated footprints.** 

**Buildings use in damage assessments**

Supported by the [H2H Network](https://h2hnetwork.org/h2hsupport-package-conflict-lebanon/), HOT has been reviewing damage assessments completed after the increase of conflict in Southern Lebanon at the end of 2024. Damage assessments use building footprints as a reference to where infrastructure is located. There were at least four remote damage assessments from different organizations that came out before January 2025 that used Microsoft Buildings. **As Microsoft had 65% fewer buildings than OSM, it is possible that these early assessments were not representative estimates of damage**. Watch for HOT’s publication expected this quarter of an overview on navigating the different organization’s damage assessments.

**What’s next**

To make OSM more useful earlier in disaster response cycles, there is promising research on integrating AI into OSM workflows, see [AI-generated buildings in OpenStreetMap: frequency of use and differences from non-AI-generated buildings](https://www.tandfonline.com/doi/full/10.1080/17538947.2025.2473637#d1e176). HOT’s [fAIR](https://www.hotosm.org/tech-suite/fair/) tool also can increase the rate of mapping by incorporating machine learning into OSM workflows when there is higher resolution imagery available. **In the meantime, expect OSM to take time, but be more accurate.** 

We can also do better as an OpenStreetMap community to map buildings in anticipation of need. In conflict, that can mean proactively mapping before detailed remote sensing analysis is conducted or in partnership with conflict analysts. In Khartoum, Sudan, we are doing just that: [OpenStreetMap Contributors Needed to Map Khartoum Ahead of New Radar Satellite Imagery](https://www.hotosm.org/updates/openstreetmap-contributors-needed-to-map-khartoum-ahead-of-new-radar-satellite-imagery-2025/).

**Partner with us!** 

Resources are needed to engage more OSM communities and students to complete OSM buildings in conflicted affected areas. Please reach out to [data@hotosm.org](mailto:data@hotosm.org) to donate or work with us on data priorities and collection. 

[Read more about HOT’s Conflict and Displacement Program.](https://www.hotosm.org/programs/conflict-displacement)

<br>

---

<br>

<div style="font-size: 0.8em; color: #778899; line-height: 1.2; margin-top: 10px; background-color: #f0f0f0; padding: 10px; border-radius: 5px;">
        <span>
    Cover Photo: European Union, Copernicus Emergency Management Service Data | Copernicus 2025-03-31<a  href="https://commons.wikimedia.org/wiki/File:Catastrophic_earthquake_in_Myanmar_(Copernicus_2025-03-31).png"> / Wikimedia </a>  
</span>

    </div>
