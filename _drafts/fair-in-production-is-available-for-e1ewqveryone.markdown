---
title: fAIr in Production is Available for Everyone
date: 2024-06-04 15:47:00 Z
tags:
- tech
Summary Text: We are nearly halfway through 2024 and are excited to share some updates
  on HOT's AI-assisted mapping service (fAIr) - specifically the successful fAIr production
  release on 31 May 2024!
Feature Image: "/uploads/fAIrJune2024A.png"
Is image top aligned: true
Person: Omran Najjar
---

The fAIr production release is a crucial milestone in fAIr’s roadmap in 2024. It means that main testing and verification have taken place, any major blockers have been fixed, and fAIr is now available for wider OSM communities on the production URL: [https://fair.hotosm.org/](https://fair.hotosm.org/).  You can explore more about the roadmap [here](https://app.asana.com/read-only/fAIr/33036889070162/c021cbff3e3f986c02f01e891065c849/timeline). 

We have tested with up to 100 users using fAIr to predict buildings on open aerial imagery OAM simultaneously with zero failures and [documented in github](https://github.com/hotosm/fairpredictor/issues/9#issuecomment-2127000592). 

![fAIrJune2024B.gif](/uploads/fAIrJune2024B.gif)

**Read below for more technical details about the load-testing scenarios we have followed.**

fAIr deployed on an automatically scalable cloud infrastructure that scales up based on usages. The technical cloud services used in the fAIr production environment include Elastic Container Services with automatic scaling features to add more tasks based on CPU usage. There are 4 different services currently:
1. fAIr API, which handles all requests and manages the AI model's training, documented on [https://api-prod.fair.hotosm.org/api/swagger/ ](https://api-prod.fair.hotosm.org/api/swagger/).
2. fAIr workers, which handles AI model's training requests in queues and currently supports one model training with availability to scale upon request to handle multiple model trainings simultaneously. The current specs for each worker is 4 vCPU, 16 GB RAM, and 1 GPU.
3. fAIr predictor, which is a separate API for prediction. All its code is documented in [GitHub - hotosm/fairpredictor: Standalone Module for Running Predictions](https://github.com/hotosm/fairpredictor).
4. fAIr Flower for queue monitoring, deployed on [https://flower.fair.hotosm.org/](https://flower.fair.hotosm.org/). However, it is for developer usage to monitor model trainings.

**Load Testing**

Multiple load-testing scenarios have been applied to the development and production environments. All scenarios are documented in this [github issue](https://github.com/hotosm/fairpredictor/issues/9). 

Scenarios 3, 4, 5, and 6 are applied in production environments with different device specs and configurations to auto-scale and simulate different user numbers.

Each load-testing scenario shows some configurations, and we will take one example and detail it for better understanding.

In the following picture, the period of time the load testing kept running was 6.22 PM till 7:12 PM =~ 50 mins. The green line represents the total number of requests per seconds and the red one represents the number of failed requests.

In the second chart, the average response time for each prediction ranged from 10 to 14 seconds over the whole 50-minute testing period.

Finally, the bottom figure shows the total number of predictions requested, with +19k requests sent within 50 minutes and an average response time of 13.9 seconds.

![fAIrJune2024C.png](/uploads/fAIrJune2024C.png)

In conclusion, fAIr production can confidently support 100 users attending a mapathon to map using AI assistance and scale up based on usage.

What next?

* Wider OSM communities are welcome to use fAIr, pilot projects and provide feedback to us on Slack or by reaching out to [omran.najjar@hotosm.org](mailto:omran.najjar@hotosm.org) or [tech-data@hotosm.org](mailto:tech-data@hotosm.org)
* Stay tuned for mid-year report coming soon illustrating what we have achieved in Q1 and Q2 2024 and drawing the direction of Q3 and Q4 2024
* Want to contribute to fAIr? Then we hope to hear from you - if any questions or suggestions for improvement, go to our [Github repository](https://github.com/hotosm/fAIr) or join the HOTOSM slack channel #fair-coord

