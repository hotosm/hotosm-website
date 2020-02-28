---
title: The Machine Learning Enabler
date: 2019-07-10 14:00:00 Z
Summary Text: 
Feature Image: "/uploads/ml-enabler.jpg"
Person: Sajjad Anwar
Working Group:
- Technical
Project:
- 'Integrating Deep Learning: AI-Assisted Humanitarian Mapping'
---

The Humanitarian OpenStreetMap Team is partnering with Development Seed, Facebook, and Microsoft to build AI-based mapping tools to empower mappers around the world. We believe this will help volunteers to make sure their time is utilized well, and improve the quality of the map where it’s most needed.

As a member of HOT and [Development Seed](https://developmentseed.org/), I’m excited to share some of our work over the last few weeks. We completed a key piece of the AI-Assist pipeline called the “[ML Enabler](https://github.com/hotosm/ml-enabler).” The ML Enabler, as the name suggests, enables applications to take advantage of Machine Learning. It organizes and efficiently stores ML-derived map data so Tasking Manager and other tools can draw on this information via a standardized API and enhance their own functionality. You have already seen some examples of how Tasking Manager and iD would use [ML-derived data in a previous blog post](https://www.hotosm.org/updates/hands-on-assisted-tasks/). With the ML Enabler, we hope to bring more models to support project managers plan task areas better, and help mappers add new map features faster.

**Why another API?**

There are some key problems that the ML Enabler attempts to solve:


- **Integrates many models** — there are several models out there from our partners and the community. Some of them are open source, while some remain proprietary. To take full advantage of all these models, we need an API that acts as a registry. The models are independent projects and have their own goals. They get new versions and learn to predict in new geographies all the time.
- **Support different schematics** — models have their own schematics on input data (for example, tiled satellite imagery), and publishing predictions. ML Enabler tries to expose a standard set of utilities to work with any model, and also sets some expectations from the model publishers.
- **Aggregate and augment predictions** — often times, we want to take predictions from a model and do some kind of augmentation before it can be useful to a mapper. For example, comparing predicted building area in a region to actual areas mapped in OSM. ML Enabler gives an interface to build these augmentations. Sometimes models publish data at very granular levels that’s too inefficient for clients like Tasking Manager. This means one would have to aggregate every time for a new prediction.

The ML Enabler solves the above through a standard set of APIs, and a command-line utility called the [ml-enabler-cli](https://github.com/hotosm/ml-enabler-cli/). The API and the CLI are extensively documented in their respective repositories, but we will do a quick walk-through and how Tasking Manager will implement these soon.

One of the fundamental assumption ML Enabler makes is that a model is hosted behind an API. For example, we’ve integrated Development Seed’s [Looking Glass](https://github.com/developmentseed/looking-glass-pub) building area predictor model. Looking Glass is packaged using TensorFlow Serving. Anyone can run this model on their computer or on the cloud using Docker. The API accepts satellite imagery tiles and responds with prediction for that particular tile. The ML Enabler CLI turns any arbitrary bounding box into tiles and sends them [directly to the hosted looking-glass API](https://github.com/hotosm/ml-enabler-cli/blob/master/ml_enabler/predictors/LookingGlassPredictor.py). The [aggregator utility](https://github.com/hotosm/ml-enabler-cli/blob/master/ml_enabler/aggregators/LookingGlassAggregator.py) takes the predictions, aggregates to the given zoom level, compares the building area with OpenStreetMap, and prepares a JSON payload that can be submitted to the ML Enable API.

```sh
    ml-enabler fetch_predictions \
      --name looking_glass \
      --bbox "-77.04, 38.88, -77.01, 38.91" \
      --endpoint http://192.168.1.3:8501/v1/models/looking_glass \
      --tile-url https://api.mapbox.com/v4/mapbox.satellite/{z}/{x}/{y}.jpg?access_token={token}' \
      --token <token_here> \
      --zoom 18 \
      --outfile /tmp/looking_glass_output.json \
      --errfile /tmp/looking_glass_errors.json
```

*Command to fetch predictions from looking-glass for a bbox*

The API stores predictions indexed by [quadkeys](https://wiki.openstreetmap.org/wiki/QuadTiles). The predictor and aggregator can decide what tile size makes the most sense. For example, looking-glass prediction is best at z18, but these predictions can be aggregated to z16 for ease of storage and retrieval. The tile is converted to the quadkey before posting the API. A key advantage of using quadkeys is its binning strategy. Practically, this allows us to fetch all predictions for an arbitrary bounding box extremely quickly and even for large datasets. A typical use case from Tasking Manager is to get building area for a polygon while creating a new project, so this can help the project manager determine what priority areas are for mapping. The API already has functionality to augment the Tasking Manager project geojson with prediction data stored in the [Task Annotation API](https://github.com/hotosm/tasking-manager/blob/develop/server/api/project_apis.py#L454).

**Future work**

It’s relatively straightforward to integrate a new predictor and aggregator. At the moment, we’ve integrated looking-glass, and Microsoft’s building footprints API. We hope you’ll try integrating your models and find this API useful. In the near future, we’re looking to add geometry storage support so ML Enabler can interface directly with tools like iD. Storing the docker information about each model allows us to build a job management system to run the model containers on AWS and fetch predictions automatically for new areas. This in the future would allow us to scale models as necessary, and update the map as accurately as possible.
