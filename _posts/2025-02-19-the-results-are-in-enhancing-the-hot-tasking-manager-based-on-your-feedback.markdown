---
title: The Results Are In! Enhancing the HOT Tasking Manager Based on Your Feedback
date: 2025-02-19 18:01:00 Z
published: false
Summary Text: A tool is nothing without its users. Over the years, the HOT Tasking
  Manager has evolved and improved thanks to the input of all the contributors around
  the world, who have shared with us what they love and the improvements they would
  like to see. In this blog, Ramya Ragupathy, the TM product owner, shares key insights
  from our latest user survey along with the roadmap for 2025.
Feature Image: https://cdn.hotosm.org/website/Screen+Shot+2021-12-16+at+12.26.52+pm-de2129.png
Project:
- Tasking Manager
---

“As an open-source platform, the Tasking Manager reflects the values of collaboration and transparency, allowing communities worldwide to adapt and use it for localized needs.”* This was one of the answers submitted by one of the 67 users from across the globe who participated in last December’s ~[NPS \(Net Promoter Score\)](https://en.wikipedia.org/wiki/Net_promoter_score)~ for the HOT Tasking Manager (TM). The TM has ~[gone through a lot of changes since the launch of its first version in 2011](https://wiki.openstreetmap.org/wiki/History_of_the_OSM_Tasking_Manager)~, and with time it has become our flagship tool, enabling volunteers and organizations to add geospatial data to OpenStreetMap in a collaborative and efficient way.
Now in its fifth version (Tasking Manager v5), we have prioritized our users in guiding our improvement efforts by conducting the NPS since the beginning of last year. Over the last round of the survey, the TM got an **NPS score of 75**, indicating an overall positive and highly satisfactory experience with the tool. This also shows a great increase compared to last year’s score of 33.89, demonstrating the commitment of the HOT tech team and our partner Naxa in making significant improvements to the HOT Tasking Manager and focusing our approach to incorporating our users' experience into the product’s roadmap. 
The NPS is calculated by subtracting the percentage of detractors from the percentage of promoters (see image below), and in general (depending on the sources) it is considered that having a score of -100 to 0 means that a product or service needs improvement, from 1-29 is good or favorable, above 50 is excellent and above 70 or 80 is world-class. We are pretty excited about having reached that level!

<br>
<br>
<div style="text-align: center;">
    <img src="/uploads/sherni-river-museum-2023.png" alt="Map1 AP Sherni River Museum 2023" style="width: 75%; height: auto;">
    <div style="font-size: 0.8em; color: #778899; line-height: 1.2; margin-top: 10px;">
        <span><a> Photo by: </a>
        <a href="https://www.hotosm.org/hubs/open-mapping-hub-latin-america-and-the-caribbean/">AP Hub</a> - 
        Monitoring rivers is vital as droughts and drying riverbeds threaten water resources. With data collection points becoming scarcer, we must remain vigilant to protect these ecosystems and the communities that rely on them. This image of a child playing in a dried-up riverbed highlights the urgent need for sustainable water management. 
        <a href="https://creativecommons.org/licenses/by-sa/4.0/">CC BY-SA 4.0</a></span>
    </div>
</div>


However, there is always room for improvement, and users highlighted key areas for enhancement as well. In the following table, you will find both what people love most about TM and areas where the experience could be better:

<br>

<table border="1" cellspacing="0" cellpadding="5">
  <thead>
    <tr>
      <th><strong>What do you love most about the Tasking Manager?</strong></th>
      <th><strong>What could we do to make your experience even better?</strong></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><em>“The platform fosters a strong sense of community among mappers.”</em></td>
      <td>UI/UX redesign for better navigation and improved task discovery.</td>
    </tr>
    <tr>
      <td><em>“The interface is intuitive and easy for beginners to navigate.”</em></td>
      <td>Task management could benefit from bulk task splitting, multiple-task locking, and dynamic task sizing based on project type.</td>
    </tr>
    <tr>
      <td><em>“I love how it enables large-scale collaborative mapping with clear workflows.”</em></td>
      <td>Imagery and data access need upgrades, such as better satellite and drone imagery with improved clarity.</td>
    </tr>
    <tr>
      <td><em>“Leaderboard stats and progress tracking help engage users.”</em></td>
      <td>AI-powered automation could enhance task recommendations, prioritization, and imagery processing.</td>
    </tr>
    <tr>
      <td><em>“Integration with OSM editors and ability to customize exports is very useful.”</em></td>
      <td>Additionally, community engagement can be strengthened through more tutorials, gamification elements, and training webinars to support and retain users.</td>
    </tr>
  </tbody>
</table>

<br>

Based on these responses, we are excited to say that our 2025 roadmap for TM will incorporate the feedback provided on the NPS.
**🛠️ Tasking Manager: What’s Coming in 2025?**
The Tasking Manager Roadmap for this year includes key updates in technical infrastructure, a new mapper level, expanding mapping project types, AI integration, and better user recognition features.
Two focused areas of work that are already underway:
**1** **Technical Stack Upgrades**

To modernize Tasking Manager, several backend and infrastructure improvements have been underway since the beginning of 2024. 
The transition to ***FastAPI*** will introduce an asynchronous framework for better performance, while adopting ***~[TypeScript and Vite](https://github.com/hotosm/tasking-manager/pull/6693)~***will enhance development efficiency and code maintainability. ***We aim to implement Terraform*** for infrastructure as code, ensuring stable deployments and ***dependency upgrades*** will be prioritized to maintain long-term sustainability. 
After completing initial testing last November and December, FastAPI integration is now available on ~[staging setup](https://tasks-stage.hotosm.org/)~ for user acceptance testing, and this will roll out to production as version 5 in mid-March.
**2. The new Super Mapper level has arrived**
We have now introduced **the Super Mapper,** a new mapper level above “Advanced” to recognize highly skilled mappers. This new level aims to improve data quality, reduce validator workload, and retain top contributors. This initiative seeks to create a globally recognized expert mapping pool, motivating contributors to keep mapping. We are currently discussing some key topics like eligibility criteria, assessment fairness, recognition methods, and Tasking Manager integration. Join the discussion and share your views about the Super Mapper level in this ~[discussion thread.](https://github.com/hotosm/tasking-manager/discussions/6706)~
**Other key priority areas we are considering for the 2025 roadmap include:**
<br>
* **Creating an OSM Sandbox:** this will be a dedicated testing and research environment, enabling users to experiment with mapping workflows without affecting real OpenStreetMap (OSM) data. Read more about our pilot with ***Médecins Sans Frontières (MSF)*** ~[here](https://www.linkedin.com/feed/update/urn:li:activity:7273303942606790656/)~. 
* **Expanding mapping project types:** New project types will include some thematic feature mapping, like infrastructure mapping covering public utilities and roads, or safety-focused mapping to identify disaster-prone areas. 
* **AI-Powered Mapping Enhancements:** We are planning a phased rollout of AI-driven task management, introducing support for task assignment and difficulty estimation to enhance user experience.
* **New Integrations with other mapping tools:** We also plan to explore integrations with ~[MapSwipe](https://mapswipe.org/en/)~, ~[uMap](https://umap.openstreetmap.fr/en/)~, and ~[MapRoulette](https://maproulette.org/)~ to create a seamless user experience from data generation to validation and visualization.
<br>
⠀**The Tasking Manager roadmap is driven by community feedback, and your insights are invaluable in shaping its future.** Which features excite you the most? What improvements do you think will have the biggest impact? How do you see AI enhancing your mapping experience? Whether you’re engaged in humanitarian mapping, education, research, or enterprise projects, your input is invaluable, and we’d love to hear your thoughts!
Join the discussion about the ~[2025 road map on GitHub](https://github.com/hotosm/tasking-manager/discussions/6688)~and ~[the HOT Slack](https://slack.hotosm.org/)~#tasking-manager channel to help shape the next evolution of HOT Tasking Manager!