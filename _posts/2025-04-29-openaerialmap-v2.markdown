---
title: 'OpenAerialMap v2: Faster, Better Imagery Access for Humanitarian Mapping'
date: 2025-04-29 14:43:00 Z
Summary Text: OpenAerialMap is evolving to provide faster, more reliable access to
  satellite and drone imagery for humanitarian mapping. With a new STAC-based infrastructure
  and modern tools, HOT and Development Seed are rebuilding OAM to meet today’s urgent
  mapping needs. Discover how this upgrade will improve interoperability, speed, and
  usability for disaster response and recovery efforts.
Feature Image: https://cdn.hotosm.org/website/OAMv2Banner.jpg
Person: Cristiano Giovando
---

**[Versión en español](https://www.hotosm.org/updates/openaerialmap-v2-acceso-mas-rapido-y-mejorado-a-imagenes-para-el-mapeo-humanitario/)**

High-resolution satellite and drone imagery is critical for effective humanitarian mapping. It allows us to see the situation on the ground, identify affected areas, plan responses, and monitor recovery efforts. Since 2015, the Humanitarian OpenStreetMap Team (HOT) has developed and maintained [OpenAerialMap](https://openaerialmap.org/) (OAM) as a critical platform for hosting, sharing, and accessing this vital imagery.

A foundational principle of OAM is its commitment to open data. Every image available through OAM is openly licensed, ensuring it can be freely used and shared by anyone. This commitment is fundamental to the mission of organizations like HOT and the broader open mapping community, especially during disaster response, where rapid, unrestricted access is vital. From the Nepal Earthquake response in 2015 to recent tropical cyclones, the 2023 earthquake in Turkey and Syria, and the recent Myanmar earthquake response, OAM has been instrumental in quickly getting imagery into the hands of mappers.

![OAM Screenshot.jpg](https://cdn.hotosm.org/website/OAM+Screenshot.jpg)
*Example of drone imagery from central Monrovia uploaded to OpenAerialMap*

However, finding the right and accessible imagery, and making it easily usable, remains challenging. Mapping projects, especially rapid responses coordinated through [HOT's Tasking Manager](https://tasks.hotosm.org/), need a seamless way to assess available imagery and access it through standard tile map services (TMS).

## Time for an Upgrade: Explore What’s Coming

While OAM has served the community well, it has primarily received maintenance fixes since its initial development between 2015 and 2017. The underlying technology and infrastructure are aging and need modernization to keep pace with current standards, tools, and demand. On average, over 100 new images are uploaded to OAM every month, and more than 5,000 users access OAM and its imagery via the map interface and tile services.

Interestingly, OAM’s original design [pioneered the idea of a distributed catalog](https://openimagerynetwork.github.io/) – indexing imagery hosted in different "buckets" by various providers, all accessible through a single interface. This concept is remarkably similar to the [SpatioTemporal Asset Catalog (STAC)](https://stacspec.org/en/) specification, which has become the modern standard for describing geospatial assets.

That's why we're thrilled to announce a major upgrade effort! Thanks to a generous grant from [Cisco](https://www.cisco.com/) via its [CyberGrants crisis response program](https://www.cisco.com/c/m/en_us/about/csr/esg-hub/social-impact/crisis-response.html), HOT is partnering with [Development Seed](https://developmentseed.org/) to rebuild OAM's backend infrastructure, fully embracing the STAC standard.

## Why STAC?

Adopting STAC offers significant advantages:

* Interoperability: Major imagery providers like Maxar, Planet, Satellogic, and Umbra—as well as organizations like NASA and ESA—have widely adopted STAC. As a result, OAM can more easily index imagery from their Open Data programs.

* Efficiency: By leveraging existing STAC catalogs, we can drastically reduce the time it takes to display, review, and access imagery after a disaster strikes. No more lengthy ingestion processes for data already available in STAC format!

* Modern Infrastructure: We'll be using robust, modern tools like Cloud Optimized GeoTIFFs (COGs), PostgreSQL with pgstac, stac-fastapi, and the powerful [TiTiler](https://developmentseed.org/titiler/) for dynamic map tile generation, making OAM faster and more reliable.

## A Fresh Look: Revamping the OAM Browser

Alongside the backend overhaul, we're looking to rebuild the OAM Browser interface. We'll leverage the[ excellent design work done by the Kontur team](https://www.kontur.io/blog/oam-redesign/) and existing open source STAC and web mapping libraries.

![OAM-prototype.png](https://cdn.hotosm.org/website/OAM-prototype.png)
*Prototype of the new version. Source: Kontur.*

## Get Involved & Learn More!

This is an exciting evolution for OAM, and we want the community involved!

* Follow development: Track our progress on the [dedicated GitHub project board](https://github.com/orgs/hotosm/projects/42).

* Join the conversation: discuss ideas and ask questions in the #OpenAerialMap channel on the [HOT Slack](https://slack.hotosm.org/).

* Stay updaed: Reach out to [info@openaerialmap.org](mailto:ty6nfo@openaerialmap.org) to be added to an email list for bi-weekly development meeting updates.
  Meet us in person: Learn more about the new OAM at upcoming conferences!

* We'll be presenting at [CNG 2025](https://conference.cloudnativegeo.org/CNGConference2025) (Utah, Apr 30-May 2) and [State of the Map US](https://openstreetmap.us/events/state-of-the-map-us/2025/) (Boston, June 19-21)

We believe these upgrades will significantly enhance OAM's utility, making crucial satellite and aerial imagery more accessible and actionable for humanitarian efforts worldwide. Stay tuned for more updates!