---
title: fAIr in Production is Available for Everyone
date: 2024-06-04 15:47:00 Z
Summary Text: Hi everyone,  we are nearly halfway through 2024 and are excited to
  share some updates of HOT's AI-assisted mapping service (fAIr) - specifically the
  successful fAIr production release on 31st May 2024!
Feature Image: "/uploads/fAIrJune2024A.png"
---

fAIr production release is a crucial milestone in fAIr’s roadmap in 2024. It means that main testing and verification has taken place, any major blockers have been fixed and fAIr is now available for wider OSM communities on the production url https://fair.hotosm.org/.  You can explore more about the roadmap in the public link in Asana, here. 


We have tested with up to 100 users using fAIr to predict buildings on open aerial imagery OAM simultaneously with zero failures and documented in github. 

Read below more technical  details about the load testing scenarios we have followed.

fAIr deployed on an automatically scalable cloud infrastructure that scales up based on usages.
The technical cloud services used in fAIr production environment includes Elastic Container Services with automatic scaling features to add more tasks based on CPU usage. There are 4 different services currently:
fAIr API which handles all requests and managed AI models trainings and it is documented on https://api-prod.fair.hotosm.org/api/swagger/ 
fAIr workers which handles AI models training requests in queues and currently supporting one model training with availability to scale upon request to handle multiple models training simultaneously. The current used specs for each worker is 4 vCPU	and 16 GB RAM and 1 GPU
fAIr predictor which is a separated API for prediction and all its code is documented in GitHub - hotosm/fairpredictor: Standalone Module for Running Predictions 
fAIr Flower for queue monitoring and deployed on https://flower.fair.hotosm.org/ . However, it is for developer usages to monitor model trainings


Load Testing
Multiple load testing scenarios have been applied to the development and production environment. All scenarios have been documented in the following github issue 
https://github.com/hotosm/fairpredictor/issues/9 

Scenarios 3,4,5,6 are applied on production environments with different device specs and configurations for auto scaling and simulating different numbers of users.

Each load testing scenario shows some configurations and we will take one example and detail it for better understanding.
In the following picture the period of time the load testing kept running is 6.22 PM till 7:12 PM =~ 50 mins. The green line represents the total number of requests per seconds and the red one represents the number of failed requests.

In the second chart, the average response time for each prediction ranged from 10-14 seconds over the whole period of 50 minutes of testing.

Finally, the bottom figure shows the total number of predictions requested with +19k requests sent within the 50 minutes and average response time of 13.9 seconds.


In conclusion, fAIr production can confidently support 100 users attending a mapathon to map using AI assistance and scale up based on usage.

What next?

* Wider OSM communities are welcome to use fAIr, pilot projects and provide feedback to us on slack or by reaching out to omran.najjar@hotosm.org and or tech-data@hotosm.org
* Stay tuned for mid year report coming soon illustrating what we have achieved in Q1,Q2 2024 and drawing the direction of Q3, Q4 2024
* Want to contribute to fAIr? Then we hope to hear from you - if any questions or suggestions for improvement, go to our Github repository or join the HOTOSM slack channel #fair-coord

