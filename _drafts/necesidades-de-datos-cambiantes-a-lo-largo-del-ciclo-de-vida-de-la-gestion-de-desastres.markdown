---
title: Necesidades de datos cambiantes a lo largo del ciclo de vida de la gestión
  de desastres
date: 2023-04-06 23:36:00 Z
---

## Data Availability and Uses: OSM Data Across the Disaster Management Phases

During each phase of the ‘disaster management cycle,' there are different data needs, uses, and requirements. Let’s first take a brief look at the different phases.

**Response** activities immediately following a disaster event to help affected people include life-saving search and rescue and meeting basic humanitarian needs: water, food, clothing, medical aid, shelter, etc.

Initial data activities involve assessing OSM data availability and gaps, procuring as much pre- and post-event open-source imagery as possible (satellite and UAV), and supporting assessments of damage and humanitarian and logistical needs.

**Response-related Datasets:**

<table style="border-bottom: none">
<tr>
<th style="border-bottom-width: 2px"><span style="font-weight: bold">Dataset</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Data needs and use</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Source</span></th>
</tr>
<tr>
<td>Buildings</td>
<td style="border-left: 1px solid black">Population estimates and #/% affected.</td>
<td style="border-left: 1px solid black">OpenStreetMap</td>
</tr>
<tr>
<td>Roads</td>
<td style="border-left: 1px solid black">Routing and logistics.</td>
<td style="border-left: 1px solid black">OpenStreetMap</td>
</tr>
<tr>
<td>Place names</td>
<td style="border-left: 1px solid black">Routing and navigation.</td>
<td style="border-left: 1px solid black">OpenStreetMap</td>
</tr>
<tr>
<td>Event data</td>
<td style="border-left: 1px solid black">Area of impact & severity to estimate the affected population.</td>
<td style="border-left: 1px solid black"><a href="https://www.gdacs.org/">GDACS</a></td>
</tr>
<tr>
<td>Context-specific infrastructure data</td>
<td style="border-left: 1px solid black">Examples include health facilities, evacuation sites, airports, and helicopter landing sites.

        What’s relevant and needed depends on the type of disaster event and the context.
        </td>
        <td style="border-left: 1px solid black">Mix of OSM, <a href="https://data.humdata.org/dashboards/overview-of-data-grids">HDX data grids</a>, third party datasets</td>
    </tr>
    <tr>
        <td style="border-bottom: none;">Programmatic and needs data</td>
        <td style="border-left: 1px solid black; border-bottom: none;">Humanitarian needs assessments, program activities, etc.</td>
        <td style="border-left: 1px solid black; border-bottom: none;">Third-party datasets</td>
    </tr>

</table>
<br><br>

**Recovery** activities focus on returning the situation to normal (and ideally better and more resilient) conditions and circumstances for affected people. The focus is still meeting the basic needs of the affected population, but it is also shifting to more thorough safety and damage assessments, cleanup, and rebuilding and reconstruction.

**Recovery-related Datasets:**

<table style="border-bottom: none">
<tr>
<th style="border-bottom-width: 2px"><span style="font-weight: bold">Dataset</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Data needs and use</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Source</span></th>
</tr>
<tr>
<td>Buildings</td>
<td style="border-left: 1px solid black">Population estimates and addressing - the ability to analyze with other datasets.</td>
<td style="border-left: 1px solid black">OpenStreetMap</td>
</tr>
<tr>
<td>Roads</td>
<td style="border-left: 1px solid black">Routing and logistics for the ongoing delivery of humanitarian aid.</td>
<td style="border-left: 1px solid black">OpenStreetMap</td>
</tr>
<tr>
<td>Damage assessments</td>
<td style="border-left: 1px solid black">Combining OSM data with external & third-party datasets to assist in damage assessments.</td>
<td style="border-left: 1px solid black"><a href="https://unosat.org/products/">UNOSAT</a>, <a href="https://emergency.copernicus.eu/mapping/copernicus-emergency-management-service#zoom=3&lat=0.62225&lon=-2.25351&layers=0BT00">Copernicus</a>, etc.</td>
</tr>
<tr>
<td>Context-specific infrastructure data</td>
<td style="border-left: 1px solid black">What’s relevant and needed depends on the type of disaster event and the context. This could be for education, healthcare, markets, financial services, or other areas.</td>
<td style="border-left: 1px solid black">Mix of OSM and third-party datasets</td>
</tr>
<tr>
<td style="border-bottom: none;">Programmatic data</td>
<td style="border-left: 1px solid black; border-bottom: none;">Humanitarian and development needs assessments, program activities, etc.</td>
<td style="border-left: 1px solid black; border-bottom: none;">Third-party datasets</td>
</tr>
</table>
<br><br>

**Preparedness** activities include planning and preparation to improve local capacity and resilience to cope with future events and emergencies. Often, a separate “mitigation” phase is defined between recovery and preparedness, focusing on prevention and reducing the likelihood of effects and impacts. In this case, when looking at (geospatial) data needs, we’re combining mitigation with preparedness.

**Preparedness-related Datasets:**

<table style="border-bottom: none">
<tr>
<th style="border-bottom-width: 2px"><span style="font-weight: bold">Dataset</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Data needs and use</span></th>
<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Source</span></th>
</tr>
<tr>
<td>Key infrastructure (context-specific), such as water infrastructure and drainage, public transport, or health and education</td>
<td style="border-left: 1px solid black">Specific interventions in an area to improve resilience and preparedness.</td>
<td style="border-left: 1px solid black; border-bottom: none" rowspan="4">OpenStreetMap plus government or third-party datasets</td>
</tr>
<tr>
<td>Natural environment: such as wetlands, floodplains, and mangroves or river systems</td>
<td style="border-left: 1px solid black">Understand a wider ecosystem and the impacts of interventions and investments.</td>
</tr>
<tr>
<td>Project specific datasets</td>
<td style="border-left: 1px solid black">Specific interventions in an area to improve resilience and preparedness.</td>
</tr>
<tr>
<td style="border-bottom: none;">Evacuation sites and coping capacity</td>
<td style="border-left: 1px solid black; border-bottom: none;">Creating evacuation and escalation planning.</td>
</tr>
</table>
<br>

**[You can access OSM data via HOT’s HDX page](https://data.humdata.org/organization/hot.).**
<br><br>

## Data Requirements and Quality: Approaching Evolving Data Quality Needs at HOT

As data use differs for each phase of a response, so do the expectations and requirements of the data itself. Often, higher data quality standards are expected of data in ‘stable’ locations and times than in the immediate disaster response phase.

**Response Phase**

During the immediate **Response Phase**, data availability is key - and data quality is often good enough as long as it doesn’t hamper the primary use of the data. For example, while annoying, overlapping or non-square buildings don’t actually cause population estimates to be significantly off. However, major roads that don’t connect cause issues for route logistics and navigation.

![DataPhasesEq2.png](/uploads/DataPhasesEq2.png)
<figcaption align = "left"><h6>Comparison of mapping from 10 February (left) to 22 March (right). Light blue denotes areas of mapped buildings in OSM.</h6></figcaption>
<br>
Comprehensive data can be scarce and initially hard to get, especially if we’re dealing with an area that hasn’t been mapped well in the past. The pace of mapping on the Tasking Manager will invariably outpace data quality checks and validation.

To complement tasking and data creation, we run a Data Protection Risk Assessment to ensure we consider local risk factors and potential harms of mapping, and consider potential improvements and mitigations. For example, we are careful of issues around the representation and exclusion of rural populations or ethnic groups through our tasking areas and definitions and what types of infrastructure we request (or don’t request) to be mapped.

**Recovery Phase**

During the **Recovery Phase**, our focus will shift more toward putting a concerted effort into data cleanup and validation. Also, we may be supporting specific recovery efforts, such as more comprehensive damage assessments, providing ongoing humanitarian assistance to shelters and camps, and planning for reconstruction efforts. This does require data to be higher quality overall and link to or incorporate additional data items, such as detailed addressing.

**Preparedness Phase**

For the **Preparedness Phase**, high data quality and fidelity is required - especially when considering the implementation of specific projects for disaster risk reduction, resilience, or anticipatory action. Often, data collection and mapping outputs will go towards providing decision-making data and baseline information on specific interventions and investments. Examples of this kind of project can be found in the Open Cities program (for example, in [Accra, Ghana](https://www.hotosm.org/projects/open-cities-africa-accra-city-project-ghana/)). These projects aim to build the disaster resilience of the cities they take place in and require detailed and high-quality data on specific aspects of infrastructure, such as the exact layout and capacity of drainage and water systems, public transport systems, or health facilities.

![DataPhasesEq3.png](/uploads/DataPhasesEq3.png)

Want to contribute to OSM for humanitarian needs? Visit [HOT’s Tasking Manager](https://tasks.hotosm.org/explore) for projects starting at the beginner level, and read [HOT's Tips for Mappers](https://www.hotosm.org/updates/tips-for-mappers-from-the-hot-data-team/).
**[You can access OSM data via HOT’s HDX page](https://data.humdata.org/organization/hot.).**