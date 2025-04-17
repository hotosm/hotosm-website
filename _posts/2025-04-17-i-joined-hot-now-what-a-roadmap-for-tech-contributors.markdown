---
title: I Joined HOT, Now What? A Roadmap for Tech Contributors
date: 2025-04-17 16:17:00 Z
published: false
Feature Image: "/uploads/3-0b24a9.jpg"
Person:
- Sam Woodcock
- Raiza Pilatowsky Gruner
---

Community -in the broadest sense of the word- is a crucial component of the work we do at HOT. Since its formalization as an organization 15 years ago, [HOT’s first members were a group of OpenStreetMap (OSM) users who brought together around 600 other mappers](https://cmci.colorado.edu/~palen/palen_papers/HaitiCOOP_Final.pdf) from around the world to digitize buildings and roads in an earthquake-stricken Port-Au-Prince in 2010. With time, our efforts mapping broader community challenges like the 2014 West Africa Ebola outbreak, access to renewable electricity in rural Tanzania, or public transportation routes in Mexico have been sustained by the many types of communities that have become the cornerstones of our open mapping approach: validators, OSM country chapters, local residents, trainers, translators, mapathon organizers, and much more. 

Among these varied ways to be part of HOT, one that we want to highlight today is the tech contributor profile. As a small NGO developing open-source tools for our community, we’ve relied on that very community to help shape our ecosystem, contributing to everything from software development and testing to feedback and documentation.

Like in a natural ecosystem, this has become a reciprocal relationship. [In a recent blog by Sam](https://spwoodcock.dev/blog/2025-03-open-source-hot/), he highlights six different stories of tech contributors who’ve recently made big and small advances on critical ideas for several of our tools, while they’ve had a chance to test and improve their software development and problem-solving skills.

## But what if you’re new to this group? How do you start? 

<ol>
  <li>Well, the first step would be to <a href="https://www.hotosm.org/tech-suite">get to know a little bit more about our tools</a> (if you already know them, skip this step :wink:)</li>
  <li>Once you get a sense of what each of them does, <a href="https://docs.hotosm.org/become-a-contributor">our documentation page</a> lists some of the different approaches you can take:
    <ul>
      <li>Code: We’ve identified <a href="https://github.com/search?q=org%3Ahotosm+label%3A%22good+first+issue%22&type=issues">a list of potential good first issues</a> that you can tackle right now on our GitHub.</li>
      <li>Test: The main goal for backend tests is to increase code coverage (meaning the amount of code that is tested) and try to ensure that changes going forward do not break any existing functionality. On the other hand, the main goal for frontend tests is to test the application’s user interface (UI) and see if the entire workflow works from end-to-end (E2E). These are some automated tests that could be better implemented:
<ul>
 <li>DroneTM needs a lot of work on its [backend tests](https://github.com/hotosm/drone-tm/tree/develop/src/backend/tests), and frontend E2E tests are yet to be implemented. The testing setup is modeled on that of FieldTM (using PyTest and Playwright as testing tools).</li>
  <li>FieldTM needs a bit of work on the [backend tests](https://github.com/hotosm/fmtm/tree/development/src/backend/tests) and [frontend E2E tests](https://github.com/hotosm/fmtm/tree/development/src/frontend/e2e)</li>
  <li>fAIr could have work done on its [backend tests,](https://github.com/hotosm/fAIr/tree/develop/backend/tests) and frontend E2E tests are yet to be implemented too.</li>
  <li>Raw-data-api backend tests are located [here](https://github.com/hotosm/raw-data-api/tree/develop/tests).</li>
</ul>
</li>
<li>Report security vulnerabilities: Often, we produce data in sensitive contexts that must be secure. We strive to produce secure software by default, but every piece of software can always benefit from thorough testing of potential vulnerabilities.</li>
    </ul>
  </li>
  <li>“But wait, I don’t have any software development/coding experience”. No worries! We still need your input:
<ul>
<li>Report bugs/suggest improvements: GitHub is the best place to do that :) If you don’t have a GitHub profile or are not feeling comfortable enough to post there yet, also feel free to reach out on the dedicated Slack channel for each tool (and somebody from the tech team will help convert your request into a GitHub issue).
</li>
<li>Discussions: You can also use GitHub or join the channels dedicated to each tool within [HOTOSM’s Slack community](https://slack.hotosm.org/). We also hold discussion sessions each month in our HOT Open Tech and Innovation Space (#geospatial-tech-and-innovation), talking about recent changes to our tools, discussing possible ideas for improvements, and possibly new ideas entirely for the open mapping ecosystem.</li>
</ul>
</li>
  <li>Meet the team: We have a very welcoming and supportive team that can help with onboarding for technical issues. Feel free to send us a message and set up a coffee chat.</li>
<li>Check out all of our resources: 
<ul>
<li>Our overarching documentation is available [here](https://docs.hotosm.org), and is a good starting point. This should link to the documentation sites for most of our tools.
<li>The documentation site for each tool is built from the code repository, most likely the content under docs.
<li>First of all, feel free to try and use our tools while following the docs. If there is anywhere you feel the documentation could be improved, feel free to modify them with a Pull Request, or open an Issue describing the problem you faced and needs clarification.
<li>If you are feeling creative, creating video tutorials based on your experience would also be very helpful! Check out [this example](https://www.google.com/url?q=https://www.youtube.com/watch?v%3Dkibi_YJ6qXo%26ab_channel%3DHumanitarianOpenStreetMapTeam&sa=D&source=docs&ust=1744910170712658&usg=AOvVaw1Igyy3VOQc7rkbV80sDTK8).
</ul>
</li>
</ol>
<br>

**So, did we convince you? Which step will you take first?** We would love to hear your story and get to know you more as you follow your journey as a HOT Tech Contributor. You can reach out to [tech-data@hotosm.org](mailto:tech-data@hotosm.org) or message us on Slack.

### 1. Well, the first step would be to [get to know a little bit more about our tools](https://www.hotosm.org/tech-suite) (if you already know them, skip this step :wink:).
 
### 2. Once you get a sense of what each of them does, [our documentation](https://docs.hotosm.org/become-a-contributor) page lists some of the different approaches you can take:

* **Code:** We’ve identified [a list of potential good first issues](https://github.com/search?q=org%3Ahotosm+label%3A%22good+first+issue%22&type=issues) that you can tackle right now on our GitHub.
* **Test:** The main goal for backend tests is to increase code coverage (meaning the amount of code that is tested) and try to ensure that changes going forward do not break any existing functionality. On the other hand, the main goal for frontend tests is to test the application’s user interface (UI) and see if the entire workflow works from end-to-end (E2E). These are some automated tests that could be better implemented:
DroneTM needs a lot of work on its backend tests and frontend E2E tests are yet to be implemented. The testing setup is modelled on that of FieldTM (using PyTest and Playwright as testing tools).
FieldTM needs a bit of work on the backend tests and frontend E2E tests
fAIr could have work done on its backend tests and frontend E2E tests are yet to be implemented too.
Raw-data-api backend test are located here.
Report security vulnerabilities: often we produce data in sensitive contexts that must be secure. We strive to produce secure software by default, but every piece of software can always benefit from thorough testing of potential vulnerabilities.

“But wait, I don’t have any software development/coding experience”. No worries! We still need your input:

Report bugs/suggest improvements: Github is the best place to do that :) If you don’t have a Github profile, or are not feeling comfortable enough to post there yet, also feel free to reach out on the dedicated Slack channel for each tool (and somebody from the tech team will help convert your request into a Github issue).
Discussions: You can also use Github or join the channels dedicated to each tool within HOTOSM’s Slack community. We also hold discussion sessions each month in our HOT Open Tech and Innovation Space (#geospatial-tech-and-innovation), talking about recent changes to our tools, discussing possible ideas for improvements, and possibly new ideas entirely for the open mapping ecosystem.

Meet the team: We have a very welcoming and supportive team that can help with onboarding for technical issues. Feel free to send us a message and set up a coffee chat.
