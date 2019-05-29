---
title: Hands on Assisted Tasks
date: 2019-05-29 18:00:00 Z
Summary Text: Launch of an experimental playground Tasking Manager supported by state-of-the-art
  machine learning techniques to assist mappers, validators and project managers.
Feature Image: "/uploads/ml4tm-complexity.jpg"
Person: Felix Delattre
Working Group:
- Technical
Project:
- 'Integrating Deep Learning: AI-Assisted Humanitarian Mapping'
---

In March we shared an update about how we've started [to move towards bringing machine learning and more open data into the Tasking Manager](https://www.hotosm.org/updates/bringing-machine-learning-and-open-data-to-the-tasking-manager/). Machine learning is making real progress and - of course not being a solution for everything - it is starting to become a reality for specific use cases, where especially deep learning techniques can improve our existing mechanisms for voice detection (Alexa, Siri and Google voice features are all based on machine learning technology), voice generation and imitation ([Wavenet](https://deepmind.com/blog/wavenet-generative-model-raw-audio/)), automated text translations ([DeepL](https://www.deepl.com)) and computer vision or image processing ([DeepArt](https://deepart.io/)). In OpenStreetMap, significant progress is being made and ready for testing. As a first step we are launching a testing environment for machine learning and OpenStreetMap - an experimental Tasking Manager instance - [tasks-assisted.hotosm.org](https://tasks-assisted.hotosm.org).

Why do we need a place for experimenting?

Especially the advancements on computer vision and image processing are opening promising perspectives for using machine learning produced data derived from satellite imagery. While the whole field is under strong development, there might be some useful tools based on deep learning for OpenStreetMap, too. For example, check out the recent work Development Seed has done [to find unmapped schools in Colombia](https://medium.com/devseed/finding-unmapped-schools-from-space-with-ai-28459f68c2f3).

One of HOT’s first tools that uses machine learning derived data to is [OpenStreetMap Analytics’ Gap Detection tool](https://osm-analytics.org/#/gaps), which uses machine learning to compare population and urban areas with existing OSM data to produce gap analyses and completeness measures.

![osm-analytics-gaps](/uploads/osm-analytics-gaps.jpg)
*OSM Analytics gap analysis of buildings in OpenStreetMap*

We’re moving from analyzing the map to assisting the mapping with machine learning. We’re beginning to experiment and research around the rising innovation and we are teaming up in an open effort, everybody is welcome to join, to test different machine learning applications and whether they are beneficial for the use in OpenStreetMap, and which workflow around them are providing meaningful input to mappers.

Our new experimental testing Tasking Manager is a playground for new ideas. On this application different machine learning supported mapping and quality assurance workflows will be tried out and improved over time.

![tasks-complexity-calculations](/uploads/ml4tm-complexity.jpg)
*Machine learning based complexity measures for tasks*

On this testing version of the Tasking Manager we are partnering with Development Seed, Microsoft and Facebook for researching different machine learning assisted functionalities:

* Complexity measurements for better project creation and to facilitate tasks better, depending on their complexity, to the most suitable mappers.
* Helping mappers map with explicit data derived from satellite imageries through machine learning models (see [Facebook's OSM diary post](https://www.openstreetmap.org/user/DrishT/diary/368711)).

Please stay tuned for more follow up blog posts we are going to write to document and share with you the insights and experiences we are gathering from this testing.
