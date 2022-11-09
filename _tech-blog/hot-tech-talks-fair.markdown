---
title: 'hot_tech_talk | fAIr: AI-assisted mapping'
date: 2022-11-02 15:03:00 Z
categories:
- hot-tech
tags:
- ai-assisted-mapping
- ai
- open-ai
Summary Text: 'Here is all you need to know about HOT’s open AI-assisted mapping service:
  fAIr.'
Feature Image: "/uploads/fAIr.png"
Person: Omran Najjar
---


# About fAIr

Back in 2020, [HOT and the Netherlands Red Cross](https://www.hotosm.org/projects/reseach-on-mapping-with-machine-learning/) worked on having an evidence-based look at current AI-supported mapping flows and took the next step towards using OSM data for training machine learning models. Today, we are a few months away from launching HOT’s open AI-assisted mapping service: fAIr.

## Glossary

**fAIr** is the product name. How come?:

* **f:** for freedom and free and open-source software

* **AI:** for Artificial Intelligence

* **r:** for resilience and our responsibility for our communities and the role we play within humanitarian mapping

**AI models:** AI is wide term and it includes lots of approaches and techniques. In our (mapping) context, we refer to computer vision techniques to detect objects from satellite imagery. These objects can be buildings, roads, water ways, trees, and potentially other objects.
fAIr intersects with Machine Learning, Deep Learning, Computer Vision as below:

![Screenshot 2022-11-02 at 08.23.42.png](/uploads/Screenshot%202022-11-02%20at%2008.23.42.png)

Source: Chandaliya, Rishabh (2020).

## Why fAIr?

The Humanitarian OpenStreetMap Team (HOT) sees that mappers can, on average, map between 1000-1500 buildings per working day without AI assistance. During an AI-assisted mapping pilot (2019-2020) supported by Microsoft, 18 million building footprints were extracted from satellite imagery for all of Tanzania and Uganda. HOT discovered during this pilot that this **average mapping nearly doubled** to 2500-3000 buildings being added to OpenStreetMap (OSM) per day with the assistance of high-quality AI open-source datasets.

fAIr seek to solve three foreseen problems:

* **1. AI models openness:** AI-assisted mapping for humanitarian purposed feels like a black box. Useful open-source results coming from AI exists (e.g. [META's global roads dataset](https://mapwith.ai/) available in RapiD, [Microsoft’s global buildings dataset](https://github.com/microsoft/GlobalMLBuildingFootprints) and [Google’s open building in Africa](https://sites.research.google/open-buildings/)). However, the models (code) are currently not open-sourced.

* **2. Model bias:** Having model biases means predicting over satellite imagery would be biassed toward the training dataset used to teach the AI model and the nature and quality of imagery is very different across the globe. Here are three different images from Asia and Africa show totally different nature of imagery:

![OAM pics.png](/uploads/OAM%20pics.png)

Source: [OpenAerialMap](https://openaerialmap.org/)

* **3. Lack of feedback:** There is no enhancement applied easily on the intelligence and accuracy of the AI models and humans are out of the loop when building the AI models, this due to AI models being either closed source or were built once and made available to end users so enhancements would require repeating the process from scratch..

## fAIr: for whom?

fAIr is an AI-assisted mapping service currently being developed for **humanitarian OSM mappers** who want or need to map more efficiently. The goal is to provide humanitarian OSM mappers access to AI-assisted mapping across mobile and in-browser editors using “community-created AI models”. Yes, you read it right, an OSM community member will be able to create their own open-source AI model and use it for mapping in their region of interest and/or humanitarian need.

## What is fAIr exactly?

Unlike other AI data producers, fAIr is an intuitive, fair and open-source **AI-assisted mapping tool** where AI models are created and trained by the people living and working in the local communities. By working with the local communities (and getting constant feedback on the models), we strive to eliminate model biases as we ensure the models are relevant to the communities where the maps are being created to improve the conditions of the people living there.

## How does fAIr work?

fAIr uses AI models (built by humanitarian OSM mappers) to detect map features based on open-source satellite and UAV imagery from HOT's [OpenAerialMap (OAM)](https://openaerialmap.org/) and suggest detected features to be added to [OpenStreetMap (OSM)](https://openstreetmap.org/). It is crucial that models will NOT produce mass features and NO mass import into OSM is planned. Unlike other AI data producers, fAIr is a free and open-source AI service that offers local communities accurate feedback loops through the efforts of OSM community mappers. This results in progressive intelligence of computer vision models. Whenever an OSM mapper uses the AI models for assisted mapping and completes corrections, fAIr can take those corrections as feedback to enhance the AI model’s accuracy.

## Where are we coming from?

We recognized the Open Cities Challenge for building segmentation mid-2020, and then around the end of 2020, HOT conducted research in collaboration with the Netherland Red Cross. Last year, HOT contributed to an academic research project investigating the capability of UAV imagery to be used for AI-assisted mapping on refugees camps in Africa, which proved that the use of localised AI models produces higher prediction accuracy in comparison to wide trained models.

In March 2022, we participated in an AI for Social good seminar in Frankfurt, Germany where data scientists and nonprofit organisations came together pursuing various social good goals. Around mid-2022, we (the hot_tech team) set our strategy and defined our direction. From the beginning of 2022, we have played an advisory role in the RAMP project, until its release in October 2022. Currently (November 2022), we have reached the midpoint on the Omdena-HOT innovation challenge and built the fAIr roadmap ([read this for key takeaways](https://www.hotosm.org/tech-blog/hot-tech-talk-open-ai-challenge/)) .

Go to [this link](https://docs.google.com/presentation/d/1kR2Gezh3yOhEZBSjtoJR37rJ1JX9Q3m6T43BO55puIU/edit?usp=sharing) to see the updated timeline with links:

![Screenshot 2022-11-02 at 14.09.40.png](/uploads/Screenshot%202022-11-02%20at%2014.09.40.png)
![Screenshot 2022-11-02 at 14.09.49-94d2eb.png](/uploads/Screenshot%202022-11-02%20at%2014.09.49-94d2eb.png)