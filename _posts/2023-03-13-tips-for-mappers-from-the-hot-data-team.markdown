---
title: Tips for Mappers from the HOT Data Team
date: 2023-03-13 18:28:00 Z
Summary Text: Whether you just started mapping to support the earthquake response
  in Turkey and Syria or if you have been mapping for years, it is always helpful
  to read tips and watch tutorials to improve your skills and maintain best practices.
  Here are some top tips from members of the HOT Data Team.
Feature Image: https://cdn.hotosm.org/website/GAL+Group+for+Mapping+Tips+Post.jpg
Person:
- Dinar Adiatma
- Samson Ngumenawe
---

## Mapping through the HOT Tasking Manager
* Please read all the instructions for a specific mapping project and concentrate your efforts on the features requested in the project. You can map other features, but be aware that they may not be mapped in other tasks in the project. This can affect the data's completeness and impact the time it takes to validate the data.
* Use the imagery specified in the instructions. (Of course, use other imagery if the specified imagery is not clear in a given task or to check your edits.)
* Focus on the priority area first, usually drawn in red polygon in each project. Here is the example from project #14234.

![Mapping Tips 1.png](https://cdn.hotosm.org/website/Mapping+Tips+1.png)

<figcaption align = "left"><h6>Fig 1. Priority areas in Tasking Manager</h6></figcaption>
<br>

## Highway Connectivity
Data from OpenStreetMap is heavily used in routing applications. See the Wiki page (https://wiki.openstreetmap.org/wiki/Routing). Here are some tips to make your edits in OpenStreetMap useful to other people:
* **Make sure only to map highways and roads that are connected.** The disconnected highways that lead to nowhere shouldn't be mapped.
* **All highways and roads should connect to each other at least from the start** of the highway or road segment or from where the segment joins another highway or road. This can be achieved by snapping newly created segments to the existing highways and roads. The best practice is to start by snapping to an existing highway or road while tracing the new highway.


![Mapping Tips 2.png](https://cdn.hotosm.org/website/Mapping+Tips+2.png)

<figcaption align = "left"><h6>Fig 2. An unconnected highway should be linked to a nearby route.</h6></figcaption>
<br>
## Geometry/Positional Accuracy
Incorrect geometry can result in bad visualization, inaccurate routing, and potentially serious safety risks if the data is used for navigation. Inaccurate geometry can also impact the quality of data analysis and visualization, making it more difficult for data users to understand and use the data to make decisions. For example, suppose the geometry of a building or land-use region is incorrect. In that case, it might be difficult to perform spatial analysis, such as determining the distance between two locations or the size of a specific land use. Some tips to make your edits in OpenStreetMap useful to other people:
* Square the buildings (by pressing Q in both JOSM and iD Editor). Unless satellite imagery clearly indicates something different, the majority of buildings can be assumed to be rectangular.

![Mapping Tips 3.png](https://cdn.hotosm.org/website/Mapping+Tips+3.png)

<figcaption align = "left"><h6>Fig 3. Unsquared building in iD Editor</h6></figcaption>
<br>
* Only map objects you are sure about and can clearly see.
* Do not draw objects that are crossing each other. If the nodes/way need to be connected, do it by sharing nodes.

![Connected Node not Overlap.png](https://cdn.hotosm.org/website/Connected+Node+not+Overlap.png)

<figcaption align = "left"><h6>Fig 4. Unconnected paths vs. connected paths</h6></figcaption>

## Managing / Authoring Projects on the Tasking Manager 

**For project managers or authors**
* Projects in densely developed urban areas should be prioritized for intermediate and advanced mappers. However, projects in peri-urban or rural developed areas should be made open for all mapper levels. This speeds up the validation process.
* Sometimes, overdue projects can become stale, and to stay on schedule, project creators should publish projects one at a time. If the project takes a long time to complete, imagery may change during the mapping or validation process, affecting the data's recency.
* Invite experienced mappers to become validators. People can establish [their own team](https://tasks.hotosm.org/manage/teams/new/) or sign up for the [HOT Global Validator](https://tasks.hotosm.org/teams/7/membership/) community. For Turkey/Syria mapping activation, validation is only carried out by the validator teams.
* Keep an eye on the topic in the Questions & Comments section. Feedback is important for ensuring good data quality.
* You can [review detailed project management guidelines here](https://learnosm.org/en/coordination/tm-admin/).

**A message from Ralph to all validators:**
> "Validators, your role is to check the standard of the work. If it is of an acceptable standard, then you validate it. If it has a few errors, then you can decide to fix it yourself and validate it. If there is an appreciable amount of errors, then you invalidate it. If the work was done recently, you can message the mapper to advise them on improving their mapping. It is not the prime task of validators to clean up the mapping (although we use validators for that as they have the necessary skills to do that efficiently). Remember that by invalidating a task, you are sending a message to the Project Creators that there is something wrong with the mapping, and this can result in the project creator raising the level of mapper allowed to map and trainers revising the way they train the mappers. That does not mean that you are not allowed to fix up mapping. You are volunteers, and that is your decision to make. We are all concerned about maintaining the standard of the mapping we put onto OpenStreetMap."