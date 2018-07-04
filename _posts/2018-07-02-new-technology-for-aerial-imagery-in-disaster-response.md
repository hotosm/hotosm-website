---
title: 'Fast, Powerful, and Practical: New Technology for Aerial Imagery in Disaster
  Response'
date: 2018-07-02 06:30:00 Z
Summary Text: How rugged, portable AWS servers can be used for post-disaster imagery
  operations.
Feature Image: "/uploads/sbe.png"
Is image top aligned: true
Person: Seth Fitzsimmons
Working Group:
- Technical
---

_Aerial imagery can play an important role in disaster response operations, enabling response teams to identify and prioritize hardest-hit areas, conduct damage assessments, and plan response activities. Existing tools make this relatively easy in connected environments; users can browse high-resolution satellite imagery catalogs and download the relevant imagery, and can process drone imagery using online tools. Current solutions don’t work well in disconnected environments, however. Even offline tools lack the storage space and processing power to be effective for addressing large areas._

_This blog post shows how rugged, portable Amazon Web Services (AWS) servers can be turned into a kit that’s mega-powerful, deployable, and purpose-built for post-disaster imagery operations. This can help humanitarians and government agencies to more accurately and efficiently conduct damage assessments and identify hardest-hit areas, potentially making a real difference in the aftermath of a natural disaster._

_Top image: A pair of AWS Snowball Edges after playing “checked luggage.”_

### Overview: So what is this thing?

I was recently at the [Amazon Web Services (AWS) Public Sector Summit](https://aws.amazon.com/summits/public-sector-summit-washington-dc-2018/) in Washington, DC demonstrating a rugged and portable (47 lbs!) piece of hardware that had been transformed into an incredibly powerful offline aerial imagery catalog, processing tool, and data-sharing device. With support from [DroneDeploy](https://www.dronedeploy.com/) and [AWS](https://aws.amazon.com/), we were able to put together a fully offline, field-deployable version of [OpenAerialMap](https://openaerialmap.org/) (OAM) and [Portable OpenStreetMap](http://posm.io/) (POSM) running on an [AWS Snowball Edge](https://aws.amazon.com/snowball-edge/). While not yet available off-the-shelf, we envision this as a powerful combination for disaster response activities.

The souped-up Snowball Edge enables a workflow for capturing, annotating, collecting, and producing post-disaster assessments. It combines imagery browsing and analysis capabilities of OAM with [DroneDeploy’s real-time stitched maps](https://www.dronedeploy.com/live-map.html), and POSM’s information management capabilities and mapping tools This enables responders to generate and share detailed  real-time maps and assessments in the field.

Here’s how it works:

![How it works](/uploads/poam-how-it-works.png)

The AWS Snowball Edge has many unique qualities that make it the perfect piece of hardware for this purpose. We chose it because it features:

* _TONS of available storage (100TB - **much** more than is available on a laptop)_
* _AWS APIs for (almost) drop-in compatibility with existing tools_
* _More compute power than is available on a laptop_
* _A rugged, dust- and water-resistant case_
* _A total weight of 47 pounds, just under most airlines’ checked baggage weight limit (because it doesn’t matter how great a solution is if you can’t actually get it to the field)_

Here’s what it looks like in action:

![Santa Rosa wildfires](/uploads/poam-santa-rosa.png)
_Imagery from DroneDeploy showing conditions in the wake of the October, 2017 Santa Rosa wildfires in California._

![Mexico City earthquake](/uploads/poam-mx-earthquake.png)
_Imagery from DroneDeploy showing a damaged alcaldía in Mexico City after September, 2017’s earthquake used within OSM’s iD editor, which is included as a component of POSM._

We shared a booth with members of [the newly-formed AWS Disaster Response Program (DRP)](https://aws.amazon.com/government-education/nonprofits/disaster-response/), who also hosted an AWS Snowball Edge demo of their own. The AWS DRP enables customers to focus on mission-critical functions; the AWS Disaster Response Action Team (AWS DRT), comprised of AWS technical experts, will provision critical data and applications for disaster-responding customers, transport hardware to their base of operations, and implement a deployable infrastructure to meet the customer’s needs during a disaster.

Our OAM/SBE demo was an “art of the possible” concept; it’s the type of solution that the DRT could help deploy. The demo project shows one way in which the open source tools we develop can be quickly deployed to facilitate completely-offline workflows through services like AWS as they increase their “offline cloud” footprint. We believe this kit has great potential for use in disaster response operations. It is not fully “off the shelf” ready at the moment but with further funding and investment we’ll look to bring this tool the last mile.

### For more technical audiences: How does this thing work?

The AWS Snowball Edge allows prospective users of these tools to "create a job" (in AWS parlance) after a disaster strikes, which will provision a 100TB ruggedized device with content from S3 buckets--large volumes of satellite imagery showing pre- and post-event conditions. The AWS Snowball Edge will then be shipped out by AWS and can be further transported by other means (I checked the Snowball Edge on my flight from Oregon to Dulles). Once on-site, all that’s needed is to connect to power and a local network. A generator and and a mesh network (no internet connectivity necessary) would suffice.

Satellite imagery acquired ahead of time can be browsed locally with OpenAerialMap, inspected with [QGIS](https://qgis.org/), and traced into offline OpenStreetMap using POSM (easily [pre-loaded with data](http://posm.io/preparing-for-the-field/) for the affected area).

Geographic areas identified for additional attention can be identified, informing UAV pilots where they should plan their flights with DroneDeploy. Live Map will produce ortho images from UAV flights in real-time.

These ortho images can be loaded into OAM for overhead, visual assessments and further annotation of offline OpenStreetMap data using the suite of mapping tools included with POSM (iD Editor or JOSM).

Areas that require field visits can be identified using imagery and OSM data and provisioned as [OpenMapKit](http://openmapkit.org/) deployments. This then allows staff and volunteers to engage in field assessments using standard OpenMapKit/[Open Data Kit](https://opendatakit.org/) and [Field Papers](http://fieldpapers.org/) workflows.

Data that’s collected in the field can be merged with existing OSM data and turned into printed maps using QGIS or Field Papers.

When a field deployment has completed, the AWS Snowball Edge is powered off, turning its Kindle Paperwhite-powered status display into a shipping label, and returned to an AWS region where data that’s been created in the field and added to the local S3 buckets (UAV imagery, augmented OSM data, and ODK submissions) will be copied into internet-accessible buckets for subsequent use and analysis.

<img src="/uploads/sbe-shipping.png" style="width:30%;">
_Return shipping mode: activated._

We believe that this solution has a lot of potential to allow organizations to embrace fully offline workflows, complete with access to large quantities of imagery and tools to collect more. We hope to expand and polish this more, including investigating how other open source tools like [OpenDroneMap](http://opendronemap.org/) and [Tasking Manager](https://tasks.hotosm.org/) can be integrated. Over the next few months we’ll be working with groups like [WeRobotics](https://werobotics.org/) to test this further and document how Portable OpenAerialMap can be made available for disaster response.

Want to dig into the technical details? I’ll be posting a full technical dive once I’m able with a rundown of how we went about getting everything to run within the Snowball Edge. Taking imagery and tools fully offline is a technical challenge and, as always, there are limitations. If you’re interested in working on this, [contact me](mailto:seth.fitzsimmons@hotosm.org) and we’ll get you involved.
