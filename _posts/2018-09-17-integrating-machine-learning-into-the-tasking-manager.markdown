---
title: 'Integrating Machine Learning into the Tasking Manager: Notes on a Direction'
date: 2018-09-17 16:12:00 Z
Summary Text: We're moving towards how we leverage machine learning tools to improve
  data quality and help mappers map. Above is a shot from our design workshop we held
  at the HOT Summit in Dar es Salaam on August 31. Read more below about our ideas
  and a direction we'd like to see within the Tasking Manager.
Feature Image: "/uploads/tm-ml-workshop-compressor.jpg"
Person: Nate Smith
Working Group:
- Technical
---

For the past year we've been discussing ideas around how to integrate machine learning (ML)/artificial intelligence (AI) tools into an OpenStreetMap and Tasking Manager workflow. We recently outlined our initial ideas and direction with the HOT voting members, board, and staff. Below is a summary of the note which that outlines the initial ways how we plan to use Tasking Manager integration as a catalyst for leveraging machine learning within an OSM editing workflow.

## What do we mean by ML/AI?

Right now we mean using a computer program that looks at aerial imagery and automatically extracts data, making it available for mappers to use. In the same way humans use their eyes to look at satellite imagery to digitally trace buildings, a computer program can now perform that same type of operation. Our approach with using computers has been that they support mapping, not replace mapping. Read more about [ML/AI here](https://builtin.com/data-science/introduction-to-machine-learning) or read Daniel J.H.’s [post on ML + OSM](https://www.openstreetmap.org/user/daniel-j-h/diary/44145).

## What we've heard from the HOT community

Last year at the HOT Summit 2017, Development Seed and other groups outlined an initial idea for HOT to use machine learning as a starting point for mappers to map. [Read more](https://developmentseed.org/blog/2017/09/15/power-mapping-with-machine-learning/) about the straw man version. In our conversations in 2018 we set out to look to operationalize the ML work. Many partners have built tools and outlined processes to make this happen. We don't necessarily need to research or generate new machine learning algorithms for use. We need to start using existing models in an appropriate way to improve the mapping workflow and OSM data quality. Heidelberg has also [outlined some workflows with Mapswipe 2.0](https://docs.google.com/presentation/d/1ln1hzcsXPOrykK6gJ4quxedUnxRolmnIeMEMVRzLzGI/edit?usp=sharing).

At the HOT Summit we have further fleshed out the ways ML can plug into remote mapping work (the main area of integration at the moment). We held a design workshop to dig into identifying not only priority areas but also specific ways ML could feed into the remote mapping work through the Tasking Manager (another big part of this is editors like iD and JOSM).

Three overarching areas to use ML came out of the workshop:

1. Tasking Manager project setup and task prioritization

2. Mapping quality and efficiency

3. Validation quality and efficiency

Within each of these areas, we categorized and evaluated each of the ideas around feasibility and impact. The results showed two ideas of high priority around task prioritization (how complex are tasks) and task validation (helping validators the validate), which also seem very feasible to implement. These are focused on improving data quality — getting mappers to the right task difficulty and setting expectations when mapping; and, helping tasks be correctly validated in an efficient manner. **There is a lot of assumption that the priority for ML integration in OSM right now is just to get automatically extracted data into mappers hands to then upload. Right now there are easier and higher impact wins around data quality checks and mapping guidance.**

To implement and work on any of these three areas, there are a few components of ML we need to consider:

1. Running the models with relevant aerial imagery, includes generating and using training data

2. Evaluating a model's fit for use in different geographic areas, with different feature patterns

3. Integrating the outputs into a Tasking Manager or OSM editor workflow

From our priorities and areas of consideration, we’ve come up with an initial direction for how we will start building and testing ML integrations into the Tasking Manager. This will get started next week through the Tasking Manger working group.

## Phases for an initial direction

Our initial direction for ML integration into the Tasking Manager follows the areas we need to work on and considers both feasibility for automating and potential impact. There are things we can do now that are high impact and highly feasible that pave the way for other high impact but harder to implement/lower feasibility.

### MVP

At the moment, our initial direction is focused around items 1 (running the models) and 3 (integrating into TM). We will need to build the infrastructure (an API that can spin up and deploy a model) to consistently and quickly run ML models and generate outputs for specific functions into Tasking Manager. For an initial Minimum Viable Product (MVP) prototype, the functions that are related to item #3 and seem to be the most feasible with high impact for improving quality:

- building or road estimates for project and task complexity and prioritization
- building or road estimates for validation and data quality checks
- mapping training/self-assessment based off of building or road estimates

The infrastructure would be a simple API that receives a request (that includes AOI and what imagery to use in TMS form) from a new Tasking Manager project, spins up the necessary severs to run the model, and then generates estimates for the project AOI. The ML service then returns the necessary outputs, compares with existing OSM data for the same area, and makes it available in the Tasking Manager to use. Being an asynchronous service, there will be a time delay upon project creation and when it can be used by a project manager.

### Next version

Builds upon the initial work to better address training data generation and use, plus looks to help improve the evaluation process (item #2). Improving the evaluation process would then be a precursor to helping extend use of ML beyond feature estimates for validation or prioritization, and begins to build out what is needed for feature extraction (building outlines to be edited, or automatically draw roads to be edited).

At the same time the evaluation work is happening, there would be a research and design phase to consider the optimal mapping workflows for using feature extraction data within TM and iD/JOSM.

### Further versions

Further work would look to improve automatic road classification and other automatic tagging work. This could also extend into supporting activations with project setup through automated change detection or damage assessment

## Ways we will get started on this

We are planning for a design and code sprint right after the upcoming [SatSummit conference](https://2018.satsummit.io/) in Washington, DC this week. We’ll look to sketch out some implementation ideas plus begin building the initial pieces to get things working.

Furthermore, this work will be a big driver within our Tasking Manager roadmap. Next week the Tasking Manager working group will be meeting to review the roadmap and discuss any other components of beginning to work on this.

Want to join in on this process? Contribute to the ideas by jumping into [our shared document](https://docs.google.com/document/d/1O964dO7YAqp-GMzzzeI2t3U0g4sFaSIzlgngYDHizxU/edit?usp=sharing) which includes these notes. We'd like to see this grow and are open to ideas and ways the direction can be improved. You can also join the discussion online through HOT's Slack community ([register here](http://slack.hotosm.org/)).