---
title: hot_tech_talk | Takeaways from our open AI challenge
date: 2022-11-03 07:43:00 Z
categories:
- hot-tech
- tech
tags:
- ai
- ai-assisted-mapping
- open-ai
- hot_tech
- tools
Summary Text: 'Over the past few years, HOT has taken a leadership role in experimenting
  with, and facilitating for, the application of open-source and fair artificial intelligence
  in mapping. What is the status? Well, let me tell you: we are only a few months
  away now from launching our open AI-mapping service - fAIr. As we speak, around
  50  AI engineers from the Omdena community are crunching code with us to narrow
  down which of the models will give the most optimal AI-assisted mapping for our
  communities.'
Feature Image: https://cdn.hotosm.org/website/AI-assisted+mapping.png
Person: Synne Olsen
---

# TL;DR

* HOT’s is not far away from launching [fAIr: an open AI-assisted mapping service,](https://www.hotosm.org/tech-blog/hot-tech-talks-fair/) which allows communities to map more efficiently with the assistance of AI.

* [HOT’s tech team](https://twitter.com/hotosm_tech) is currently hosting an [open AI challenge with Omdena](https://omdena.com/projects/mapping-tool-for-disaster-management/). The aim of the challenge is to support the decision of which models to adopt into fAIr (looking at performance and accuracy of the models).

* Feeling a little lost here? I feel you! Below is all you need to know about fAIr and AI-assisted mapping.

* Read a background interview from HOT Tech team member Omran Najjar [here](https://www.hotosm.org/tech-blog/hot-tech-talks-fair/).

# OPEN AI CHALLENGE

As we speak, a team of 50\+ AI engineers from the Omdena community have been crunching code to see which of the models will give the most optimal AI-assisted mapping for our communities. They have been going on for over 5 weeks now - and are soon completing the challenge! I interviewed [our fAIr lead and AI engineer Omran Najjar](https://www.hotosm.org/people/omran-najjar/) about the challenge and the outcomes:

## My coffee conversation with Omran on the AI challenge:

> **Hi Omran. How are you doing? You are busy these days! Very excited about the open AI challenge, and curious to hear your take on it all.  For most of us (non-technical) people, AI is a little hard to understand.  Therefore, feel free to treat me and the readers as if we have no basis to really understand AI and how it works. (oh, and dear readers: if you want to read more about AI-assisted mapping and fAIr: check out [Omran's blog on fAIr](https://www.hotosm.org/tech-blog/hot-tech-talks-fair/)).**

> **Q: Another AI challenge was conducted a few years back (the [Open Cities challenge](https://www.drivendata.org/competitions/60/building-segmentation-disaster-resilience/leaderboard/)). Aren't we just repeating what has already been done?**

No, we are actually building on the top of it. The output from the Open Cities challenge had an approximately 86% intersection over union score, which is good, but not great. This was before my time, so I am not sure, but I guess there was a hope that someone would pick up this model and build upon it. What did happen was that a student (now a HOT volunteer), Christopher Chan, reached out because he wanted to do some research on AI-assisted mapping. This research was just published actually (see this overview). What we learned from Chris’ research was pretty amazing: it proved that small, local datasets actually increased the accuracy of the models, hence the **local AI models predict better buildings and roads than a global model**! (explained below) So now, during this Omdena challenge, we have: i) the knowledge of Chris’ research and ii) the training datasets (explained below):

> **Q: Could you elaborate a little: what exactly are AI models and training datasets in this context?**

An AI model in our context is a software code that you show it the left image below, then it runs and tells you what features presents in it like the right image (building detection in this example).

![Screenshot 2022-11-03 at 15.03.39.png](https://cdn.hotosm.org/website/Screenshot+2022-11-03+at+15.03.39.png)

Source: [OpenAerialMap](https://openaerialmap.org/)

For training datasets, imagine a 5 years old child who has never seen a satellite imagery before and you challenge them to tell you what are the buildings in the following image:

![Screenshot 2022-11-03 at 15.04.46.png](https://cdn.hotosm.org/website/Screenshot+2022-11-03+at+15.04.46.png)

Source: [OpenAerialMap](https://openaerialmap.org/)

Initially, they don’t know how a building looks from the top, they might struggle knowing what is a shadow of a building and what is the ground in the image! To teach them, you create a couple pages book as a curriculum, where you put images and highlight what is a building. Then you train the child to enhance their ability to detect buildings. Then maybe extend the curriculum to train them to detect a road, a tree, a swimming pool etc. Here is one page of that book:

![Screenshot 2022-11-03 at 15.06.03.png](https://cdn.hotosm.org/website/Screenshot+2022-11-03+at+15.06.03.png)

Source: [OpenAerialMap](https://openaerialmap.org/)

The child is an AI model and the curriculum is a training dataset. The curriculum seems to be like OpenStreetMap data, right?

> **Q: Oh, love this analogy! Ok, so to nail it down: why exactly are we doing this open AI challenge with Omdena?**

In short, we want to ensure that fAIr ultimately provides as accurate and precise models as possible for AI-assisted mapping in our communities and [Omdena’s Innovation Challenge approach](https://omdena.com/civil-society/) is a community-driven approach of engineers as collaborators. To get there, we teamed up with Omdena, and are now working together with a diverse team of 50\+ AI engineers who support the decision on which models to use in our fAIr service. To get a little more technical; we had a baseline model before the challenge started. The Omdena team is now using other open AI models (including the [Open Cities model](https://github.com/drivendataorg/open-cities-ai-challenge) and [RAMP model](https://rampml.global/ramp-use-cases/)) to re-train/fine tune the models and together discuss and advise on the direction to go.

> **Q: This is such a good example of the power of collective intelligence - very cool! Ok, last question: what are your key takeaways so far? Anything that has surprised you with this challenge?**

Yes! I will highlight two things about the team and the challenge that really surprised me:

1. The **diversity** of knowledge coming from Omdena's collaborators is amazing! For instance, the various team members all have different techniques within deep learning and machine learning techniques in their  “toolbox”. Different models - new models by ourselves, and we are trying RAMP.

2. The **efficiency** of Omdena’s coordination is the second. I am amazed how organised and delivery-oriented they are. Normally projects don’t work this well! It has all been very professional.

## Want to know more?

* [Read all about fAIr (HOT's open AI_assisted mapping service)](https://www.hotosm.org/tech-blog/hot-tech-talks-fair/)

* [See full timeline with links to fAIr timeline and research](https://docs.google.com/presentation/d/1kR2Gezh3yOhEZBSjtoJR37rJ1JX9Q3m6T43BO55puIU/edit?usp=sharing)

# Want to engage in fAIr or HOT's technologies?

We are always looking for tech enthusiasts! Do you have an interest in learning about AI, or perhaps have technical skills in python, JOSM or graphic design? Feel free to reach out to me at synne.olsen@hotosm.org. If you would like to get involved in any other HOT tech projects or curious to hear more, contact our colleague Petya Kangalova at petya.kangalova@hotosm.org.