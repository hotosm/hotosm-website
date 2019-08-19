---
title: Using machine learning to identify the effort and complexity of mapping areas
date: 2019-08-15 09:00:00 Z
Summary Text: Testing more machine learning integrations with the Tasking Manager
Feature Image: "/uploads/tm-ml-project-creation.jpg"
Person: 
- Matthias Funke
- Felix Delattre
Working Group:
- Technical
Project:
- 'Integrating Deep Learning: AI-Assisted Humanitarian Mapping'
---

HOT has been experimenting with how machine learning will help us provide a better mapping experience and more accurate and effective maps for people responding to crises. One area where machine learning can add value without the risk of alienating human users is by estimating the size and difficulty of Tasking Manager tasks. We’re testing this idea through [our AI-assisted mapping work](https://www.hotosm.org/projects/ai-assisted-humanitarian-mapping/) to enhance how users map within the Tasking Manager.

Mapping projects come in many shapes and sizes. The entire project area of interest (AOI) gets cut into tasks for each user to take on. Some tasks may be much harder to map than others. Up until now, each task covered the same area size no matter the difficulty of mapping required. One may have few buildings and roads, and another may have many buildings, roads, and bridges over a river. By adding machine learning to the Tasking Manager, we can suggest smaller task sizes or split complex tasks into smaller quadrants, distributing the workload and assuring a balanced amount of time it takes to complete the task.

> Artificial intelligence and it’s topic of machine learning are advanced computing methods of computer vision, which can be used to detect objects from satellite imagery. These methods may help generate data about where there are data gaps within OSM; assess complexity or time required to map; or, evaluate and compare mapping for validation.

## How to determine effort of a task without looking at the map?

Machine learning models can look at satellite imagery and predict the number of buildings, roads, and other artifacts in an area. This estimated information is then compared with OpenStreetMap data and works out a score that indicates the expected scale of the mapping that needs to be carried out in one task area. HOT took the first step to integrate machine learning into the Tasking Manager in September 2018, when [Development Seed](https://medium.com/devseed/weaving-automation-into-the-mapping-workflow-adding-ai-to-the-tasking-manager-52172ed2ece8) helped us test if more information on the map view could better inform mappers. As the testing continued, we have evolved how to display this type of information to users within the Tasking Manager. Project creators can now use the information delivered by machine learning to decide how to allocate tasks to the appropriate mapper according to their profile and experience levels.

![ML assisted project creation](/uploads/tm-ml-project-creation-manual.gif)

## How does this fit into the Tasking Manager?

Imagine someone needs to set up a project on Tasking Manager to map an area hit by a hurricane. When creating your new project there could be a small ‘Add ML layer’ button (as seen in the above image) indicating machine learning predictions are available for that region. By activating the layer button, each task will turn a shade of red, color-coded to indicate task difficulty level. The more missing data needs to be mapped, the deeper the shade. Using this layer, the project creator is able to split specific areas into smaller tasks, reducing the complexity of tasks.

Automated splitting is also available for users to choose to split based on expected complexity. By clicking the “Split (ML)” button, the Tasking Manager can select tasks identified with high difficulty and split them into smaller tasks.

In addition, we also see an opportunity to use this predicted estimation to help the Tasking Manager assign the tasks to the right mappers, depending on the estimated complexity and the experience level of the users. And for example, assign highly complex tasks to more experienced mappers.

Here, machine learning is being used as a decision support tool, making the job of the project manager easier, and enabling faster completion of the mapping project with right-sized chunks of work for mappers of different skill levels.