---
title: 'hot_tech_talks | fAIr: AI-assisted mapping'
date: 2022-10-26 15:03:00 Z
published: false
categories:
- hot-tech
tags:
- ai-assisted-mapping
- ai
- open-ai
Summary Text: 'Over the past few years, HOT has taken a leadership role in experimenting
  with, and facilitating for, the application of open-source and fair artificial intelligence
  in mapping. Here is all you need to know about HOT’s open AI-assisted mapping service:
  fAIr.'
Feature Image: "/uploads/AI-assisted%20mapping.png"
Person: Omran Najjar
---

* Technical level: low
* Estimate read: 5 min


Back in 2020, [HOT and the Netherlands Red Cross](https://www.hotosm.org/projects/reseach-on-mapping-with-machine-learning/) worked on having an evidence-based look at current AI-supported mapping flows and took the next step towards using OSM data for training machine learning models. Today, we are a few months away from launching HOT’s open AI-assisted mapping service: fAIr.

# About fAIr

## Glossary

fAIr is the product name. Why?: 

* **f:** for freedom and free and open source software 
* **AI:** for Artificial Intelligence 
* **r:** for resilience and our responsibility for our communities and the role we play within humanitarian mapping 


* **AI models:** AI is wide term and it includes lots of approaches and techniques. In our (mapping) context, we refer to computer vision techniques to detect objects from satellite imagery. These objects can be buildings, roads, water ways, trees, and potentially other objects.
fAIr intersects with Machine Learning, Deep Learning, Computer Vision as below:

![Screenshot 2022-11-02 at 08.23.42.png](/uploads/Screenshot%202022-11-02%20at%2008.23.42.png)

Source: Chandaliya, Rishabh (2020).

## Why fAIr? 
The Humanitarian OpenStreetMap Team (HOT) sees that mappers can, on average, map between 1000-1500 buildings per working day without AI assistance. During an AI-assisted mapping pilot (2019-2020) supported by Microsoft, 18 million building footprints were extracted from satellite imagery for all of Tanzania and Uganda. HOT discovered during this pilot that this average nearly doubled to 2500-3000 buildings being added to OpenStreetMap (OSM) per day with the assistance of high-quality AI open source datasets. 

fAIr is trying to solve three foreseen problems:

* **AI Models openness:** where AI around humanitarian mapping feels like a black box. Although, the results are open-source, for example Microsoft’s global buildings dataset, Google’s open building in Africa and META global roads dataset available in RapiD, but models themselves are resident in the labs.

* **Model Bias:** which means predicting over satellite imagery would be biassed toward the training dataset used to teach the AI model and the nature and quality of imagery is very different across the globe.
Here are 3 different imageries from Asia and Africa show totally different nature of imagery.

![OAM pics.png](/uploads/OAM%20pics.png)
Source: [OpenAerialMap](https://openaerialmap.org/)

* **Lack of feedback:** which means that there is no enhancements applied easily on the intelligence of the AI models and human is out of the loop when building the AI models.

## fAIr: for whom?
fAIr is an AI-assisted mapping service currently being developed for humanitarian OSM mappers who want or need to map more efficiently. The goal is to provide humanitarian OSM mappers access to AI-assisted mapping across mobile and in-browser editors using “community-created AI models”. Yes, you read it right, an OSM community member will be able to create their own open-source AI model and use it for mapping in their region of interest and/or humanitarian need.

## What is fAIr exactly?
Unlike other AI data producers, fAIr is an intuitive, fair and open-source **AI-assisted mapping tool** where AI models are created and trained by the people living and working in the local communities. By working with the local communities (and getting constant feedback on the models), we strive to eliminate model biases as we ensure the models are relevant to the communities where the maps exist to improve the conditions of the people living there. 

## How does fAIr work?
fAIr uses AI models to detect map features based on open source (satellite) imagery from OpenAerialMap (OAM) and add them into OpenStreetMap (OSM). Unlike other AI data producers, fAIr is a free and open-source AI service that offers local communities accurate feedback (loops) through the efforts of OSM community mappers. This results in progressive intelligence of computer vision models, meaning: whenever an OSM mapper uses the AI models for assisted mapping and completes corrections, fAIr can take those corrections as feedback to enhance the AI model’s accuracy. 

## What is the story behind fAIr?
Go to [this link](https://docs.google.com/presentation/d/1kR2Gezh3yOhEZBSjtoJR37rJ1JX9Q3m6T43BO55puIU/edit?usp=sharing) to see the updated timeline with links: 

![Screenshot 2022-11-02 at 08.18.36.png](/uploads/Screenshot%202022-11-02%20at%2008.18.36.png)
![Screenshot 2022-11-02 at 08.19.16-959bb1.png](/uploads/Screenshot%202022-11-02%20at%2008.19.16-959bb1.png)

### Want to go into a more technical level?
[Click here](https://docs.google.com/presentation/d/1kR2Gezh3yOhEZBSjtoJR37rJ1JX9Q3m6T43BO55puIU/edit?usp=sharing) to see the full timeline, code and all details of the developments. 

# Want to engage in fAIr or HOT technologies?
We are always looking for tech enthusiasts. Do you have an interest in learning about AI, or perhaps have technical skills in python, JOSM or design? Reach out to tech@hotosm.org or directly to our tech collective facilitator Petya Kangalova at petya.kangalova@hotosm.org! 