---
title: hot_tech_talk | Takeaways from the open AI challenge
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
  in mapping. What is the status? Well, let me tell you. We are only a few months
  away now from launching [our open AI-mapping service: fAIr](https://www.hotosm.org/tech-blog/hot-tech-talks-fair/)!
  And we are getting great help from 50+ AI engineers from the Omdena community who
  are currently crunching code with us!'
Feature Image: "/uploads/AI-assisted%20mapping.png"
Person: Synne Olsen
---

Technical level: low
Estimate read: 5 min

# TL;DR

* HOT’s is not far away from launching [fAIr: an open AI-assisted mapping service](https://www.hotosm.org/tech-blog/hot-tech-talks-fair/) which allows communities to map more efficiently with the assistance of AI

* [HOT’s tech team](https://twitter.com/hotosm_tech) is currently hosting an [open AI challenge with Omdena](https://omdena.com/projects/mapping-tool-for-disaster-management/). The aim of the challenge is to support the decision of which models to adopt into fAIr (looking at performance and accuracy of the models).

* Feeling a little lost here? I feel you! Here is all you need to know about fAIr and AI-assisted mapping

# OPEN AI CHALLENGE

As we speak, a team of 50\+ AI engineers have been crunching code to see which of the models will give the most optimal AI-assisted mapping for our communities. They have been going on for over 5 weeks now - and are soon completing the challenge! I interviewed [our fAIr lead and AI engineer Omran Najjar](https://www.hotosm.org/people/omran-najjar/) about the challenge and the outcomes:

## Coffee conversation with Omran on the AI challenge:

> Hi Omran. How are you doing? You are busy these days! Very excited about the open AI challenge, and curious to hear your take on it all.  For most of us (non-technical) people, AI is a little hard to understand.  Therefore, feel free to treat me and the readers as if we have no basis to really understand AI and how it works. (oh, and for those of you who want to better understand AI-assisted mapping and HOT's (soon-to-be-launched) fAIr product: you can read and enjoy [Omran's blog on fAIr](https://www.hotosm.org/tech-blog/hot-tech-talks-fair/))

> \[Synne\]: Another AI challenge was conducted a few years back (the so-called Open Cities challenge). Aren't we just repeating what has already been done?

> \[Omran\]: No, we are actually building upon it. The output from the Open Cities challenge had a 92% precision, which is good, but not great. This was before my time, so I am not sure, but I guess there was a hope that someone would pick up this model and build upon it, but this did not happen. What did happen was that a student (now a HOT volunteer), Christopher Chan, reached out because he wanted to do some research on AI-assisted mapping. This research was just published actually (see this overview). What we learned from Chris’ research was pretty amazing: it proved that small, local datasets actually increased the accuracy of the models (Synne’s translation: local AI models better predict buildings and roads than a global model)! So now, during this Omdena challenge, we have i) the knowledge of Chris’ research and ii) the datasets (=imagery) and learnings from the Open Cities challenge to enhance our (fAIr) services (=AI models for community to use to map more efficiently).

> \[Synne\]: So to nail it down; why exactly are we doing this open AI challenge with Omdena?

> \[Omran\]: In short, we want to ensure that fAIr ultimately provides as accurate and precise models as possible for AI-assisted mapping in our communities. To get there, we teamed up with Omdena, and are now working together with a diverse team of 50\+ AI engineers who will support our decision on which models to use in our fAIr service. To get a little more technical; we had a baseline model before the challenge started. The Omdena team is now using other open AI models (including the Open Cities model and RAMP models) to re-train the models and together discuss and advise us on which models to go for.

> \[Synne\]: Ok, cool! Thanks for that explanation. So what are some key outcomes so far? Something that has surprised you?

> \[Omran\]: I will highlight two things about the team and the challenge that really surprised me:

* > The diversity of knowledge coming from Omdena's collaborators is amazing! For instance, the various team members all have different techniques within deep learning and machine learning techniques in their  “toolbox”. Different models - new models by ourselves, and we are trying RAMP.

* > The efficiency of Omdena’s coordination is the second. I am amazed how organised and delivery-oriented they are. Normally projects don’t work this well! It has all been very professional.

## Want to know more?

* [Read all about fAIr in Omran's blog](https://www.hotosm.org/tech-blog/hot-tech-talks-fair/)  

* [Full timeline, code and all details of the developments](https://docs.google.com/presentation/d/1kR2Gezh3yOhEZBSjtoJR37rJ1JX9Q3m6T43BO55puIU/edit?usp=sharing)

# Want to engage in fAIr or HOT's technologies?

We are always looking for tech enthusiasts! Do you have an interest in learning about AI, or perhaps have technical skills in python, JOSM or graphic design? Feel free to reach out to me at synne.olsen@hotosm.org. If you would like to get involved in any other HOT tech projects or curious to hear more, contact our colleague Petya Kangalova at petya.kangalova@hotosm.org.