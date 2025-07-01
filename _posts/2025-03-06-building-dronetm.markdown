---
title: 'Building DroneTM: A Digital Public Good Solution To Democratize Drone Mapping'
date: 2025-03-06 19:16:00 Z
Summary Text: Guest blogger Niraj Adhikari, from our partner NAXA, takes us through
  the motivations that led him to become a geospatial software developer, as well
  as the highs and lows of developing a groundbreaking product such as DroneTM, making
  the vision of accessible and community-driven drone-based mapping a reality.
Feature Image: "https://cdn.hotosm.org/website/DroneTMGuestBanner.jpeg"
Person: Niraj Adhikari
---

For as long as I can remember, I have been fascinated by maps—not just as tools for navigation but as powerful instruments for solving real-world problems. I was always drawn to the idea that maps can tell stories, reveal hidden patterns, **and help communities prepare for and respond to challenges.** My journey as an engineer has been driven by the belief that geospatial data, when made accessible and actionable, can transform the way we understand and interact with our environment.

As a geospatial software developer at [NAXA](https://naxa.com.np/), a Geospatial Information and Communications Technology (Geo-ICT) company designing and developing digital and spatial technologies for social good, I have been fortunate to work on the application of technologies for impact-driven solutions. Over the years, we have collaborated with the Humanitarian OpenStreetMap Team (HOT) in developing multiple innovative digital public good solutions. Our partnership was a natural fit—HOT has been leveraging high-resolution imagery to contribute to the creation and expansion of an open map of the world, and our shared vision of democratizing geospatial data brought us together.

Through this collaboration, we brainstormed ideas on how to make drone-based mapping more accessible and community-driven. We envisioned a tool that would enable anyone, not just experts, to contribute high-quality aerial imagery and help build better maps for humanitarian response, disaster resilience, and sustainable development. This is how Drone Tasking Manager (DroneTM) was born.

## Why We Built DroneTM

Traditionally, aerial imagery acquisition has been controlled by big institutions with access to expensive satellites or aircraft-based surveys. While drone technology promises a shift (offering high-resolution imagery at a fraction of the cost), most available tools have major limitations:

* They are proprietary, restricting accessibility and adaptability.

* Mapping workflows are fragmented, requiring multiple disjointed tools for flight planning, execution, and data processing.

* There is no system for large-scale collaboration, making it difficult to coordinate multiple drone pilots for real-time imagery acquisition efforts.

**We wanted to build something open-source, user-friendly, and designed for large-scale collaboration**. DroneTM was created as a tasking platform that allows anyone with a drone to contribute aerial imagery to open mapping efforts—bridging the gap between local knowledge and global impact.

## How DroneTM Works

DroneTM is a platform designed to help organizations, communities, and volunteers organize, execute, and share drone mapping missions seamlessly. With DroneTM, users can:

* **Plan missions easily** - Define mapping areas, generate flight waypoints, and upload them to drone controllers.

* **Coordinate flights across multiple pilots** – A task-based system ensures efficient image collection for large-scale projects.

* **Process and share data seamlessly** – Integration with [OpenDroneMap (ODM)](https://www.opendronemap.org/) automates the transformation of raw drone imagery into usable geospatial datasets.

* **Contribute to open mapping efforts** – Collected imagery is uploaded to [OpenAerialMap](https://openaerialmap.org/), making it freely accessible for humanitarian, conservation, and development use.

## Field Testing, Deployment, and Real-World Challenges

At NAXA, we believe that the best way to build technology is to test it where it matters most on the ground, in real-world conditions. **No amount of desk research can fully prepare you for the surprises that fieldwork throws your way!** From the beginning, we knew DroneTM needed to be stress-tested in diverse environments, from dense urban areas to remote mountain villages. Our commitment to making DroneTM a practical and effective solution has led us to implement it across diverse geographical locations, each presenting unique challenges and learning opportunities. **With the support of the World Bank**, we have been able to refine and validate our approach to community-driven drone mapping in various environments, from the tropical landscapes of Bali and the Caribbean islands to the hilly ranges in Nepal.

### Field 1. Bali, Indonesia: The Case of the Disappearing Drone

![DroneTM_Bali2.jpg](https://cdn.hotosm.org/website/DroneTM_Bali2.jpg)
*Field testing of a drone in Bali alongside government officials, working with them to explore real-world challenges. Credit: Niraj Adhikari, [CC BY-NC 4.0 International](https://www.creativecommons.org/licenses/by-nc/4.0/deed.en).*

Our mission in Bali was to test DroneTM’s [waypoint](https://en.wikipedia.org/wiki/Waypoint) generation and mission execution under tropical conditions. Initially, everything was progressing smoothly—we had meticulously planned the flights, set up the equipment, and felt confident in our preparations. However, reality had other plans.
During the test flights, we observed an unexpected issue: the drones did not fly in straight lines between waypoints as anticipated. Instead, they followed a curved trajectory due to their inherent flight dynamics. This deviation led to gaps in image coverage, particularly at the edges of the survey area. To address this, we needed to refine our flight planning algorithm by incorporating buffer waypoints and adjusting overlap calculations to ensure comprehensive coverage.

Adding to the challenge, we experienced temporary signal losses when the drones flew beyond a cliff, **momentarily disappearing from our control.** Each time, the drone lost connection with the controller, creating tense moments as we waited for it to regain communication. Fortunately, the built-in return-to-home feature worked flawlessly, ensuring the drones autonomously navigated back to their starting point once the connection was restored.

This experience underscored the importance of real-world testing and iterative improvements. Despite the setbacks, these insights have been invaluable in refining our software to enhance drone navigation accuracy and survey efficiency.

### Field 2. Nepal: Flying in the Mountains and Terrain Challenges

Testing DroneTM in Nepal presented its own set of challenges, primarily regulatory hurdles and the need to adapt to extreme terrain. In Kathmandu, drone regulations are strict, making large-scale testing difficult due to the presence of international airports and several other security-sensitive locations. To work around this, we shifted our operations to rural areas where we could test terrain-following flight planning in rugged landscapes. **Terrain-following is a drone capability that allows it to maintain a consistent height above the ground, even over uneven landscapes.** Instead of maintaining a fixed altitude, the drone continuously adjusts its flight path to match the terrain below. This ensures smoother navigation and more accurate data collection. One of our primary objectives was to evaluate how well DroneTM could adapt to steep slopes, narrow valleys, and unpredictable weather conditions.

During testing, we quickly realized the critical importance of terrain-following capabilities. Without these features, drones struggled to maintain stable flight paths and risked crashing into unexpected elevation changes. In one instance, a drone nearly collided with the mountainside, only to be saved by its onboard sensors, which detected the obstacle and adjusted altitude just in time. These incidents highlighted **the need for improved terrain-awareness algorithms to ensure safer and more reliable operations in complex environments.**
One of our most significant technical achievements in Nepal was the successful implementation of terrain-following capabilities. This feature allows drones to maintain a consistent height above ground level while navigating Nepal's complex topography.

Despite these challenges, the Nepal field tests provided invaluable insights. We fine-tuned altitude adjustments for varying terrains, enhanced safety measures for unpredictable winds, and improved the user interface (UI) to give users more real-time control options. These enhancements significantly boosted DroneTM’s performance, making it more adept at handling demanding flight conditions.

![DroneTM_NepalOrtophoto.png](https://cdn.hotosm.org/website/DroneTM_NepalOrtophoto.png)
*This image showcases the camera positions recorded in WebODM during the process of generating an [orthophoto](https://en.wikipedia.org/wiki/Orthophoto) for a terrain-following project in Nepal. Each camera position represents a point where the drone captured an image, which was later stitched together to create a high-resolution, georeferenced orthophoto. The terrain-following aspect of the project ensures that the drone maintains a consistent altitude relative to the ground, improving the accuracy and quality of the imagery. Source: DroneTM.*

### Field 3. Caribbean Deployment: Dominica and St. Lucia

In the Caribbean islands of Dominica and St. Lucia, we deployed DroneTM to support local mapping initiatives. These locations provided an excellent opportunity to test our platform in coastal environments, where accurate mapping is crucial for disaster preparedness and resilience planning. The implementation in these island nations demonstrated DroneTM's capability to handle:

* Coastal mapping challenges, including varying light conditions over water.

* Coordination of multiple drone pilots across different administrative regions.

An example project in this area looks like this:
![DroneTM_DominicaOrtophoto.png](https://cdn.hotosm.org/website/DroneTM_DominicaOrtophoto.png)
*This photo from the DroneTM platform displays the project site in Dominica, Caribbean, featuring an orthophoto visualization. The image highlights the processed aerial data, providing a detailed view of the terrain for analysis and decision-making. Source: DroneTM.*

## A Call to Action: Join the Open Drone Mapping Movement

DroneTM is not just a tool. It is a movement to make aerial mapping more inclusive, community-driven, and open to all. If you share our vision of using geospatial data for social good, here’s how you can get involved:

* Test [DroneTM](https://dronetm.org/) in your mapping projects.

* Contribute to development via our [GitHub](https://github.com/hotosm/Drone-TM) repository

* Join our community and help shape the future of open drone mapping.

Let’s map the world together—one flight at a time.

## More readings

* [Can low-cost drones contribute to mangrove monitoring and conservation? Testing Drone Tasking Manager in La Paz, Mexico](https://www.hotosm.org/updates/can-low-cost-drones-contribute-to-mangrove-monitoring-and-conservation-testing-drone-tasking-manager-in-la-paz-mexico/)

* [Land care and surveillance drones: open knowledge at the service of the community](https://diff.wikimedia.org/2025/03/26/land-care-and-surveillance-drones-open-knowledge-at-the-service-of-the-community/)

* [Strengthening Communities in Mangrove Conservation: Drone Technology and Local Collaboration](https://www.hotosm.org/updates/strengthening-communities-in-mangrove-conservation-drone-technology-and-local-collaboration/)

![Drone TM Invite Guest.jpg](https://cdn.hotosm.org/website/Drone+TM+Invite+Guest.jpg)