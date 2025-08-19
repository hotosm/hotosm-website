---
title: Advancing Mangrove Monitoring in Indonesia through Open Mapping and Collaboration
date: 2025-08-11 06:55:00 Z
tags:
- Asia Pacific
- Indonesia
Summary Text: Effective conservation monitoring requires reliable, open spatial data.
  Through the Map4Mangrove project, Open Mapping Hub - Asia Pacific partners with
  organizations engaged in mangrove rehabilitation in Indonesia to strengthen their
  monitoring efforts through open mapping.
Feature Image: "/uploads/Map4Mangrove_Stakeholder-Workshop-1_2025.jpg"
Is image top aligned: false
Person:
- Tony Liong
- Honey Grace Fombuena
- Harry Mahardhika Machmud
Country:
- Indonesia
---

On 8 May 2025, [Open Mapping Hub - Asia Pacific (AP Hub)](https://www.hotosm.org/hubs/open-mapping-hub-asia-pacific/) shared **how open mapping can transform the way we monitor mangrove conservation efforts.** This is part of our ongoing collaboration with the [Indonesian Biodiversity Foundation (Yayasan KEHATI)](https://kehati.or.id/), in which we are working closely with their grantee, [Yayasan Lestari Alam Kita (SALAKA)](https://salaka.or.id/), on their Blue Carbon program.

<hr>

## About the Blue Carbon Program

The [Blue Carbon program](https://kehati.or.id/en/mangrove-blue-carbon-kehati-and-asahimas-chemical-planting-mangrove-in-pandeglang/) is a joint initiative between KEHATI, SALAKA, and the [Faculty of Agriculture at UNTIRTA (Sultan Ageng Tirtayasa University)](https://faperta.untirta.ac.id/), funded by [PT Asahimas Chemical](https://asc.co.id/index.php/en/).

The program aims to plant a total of 140,000 mangroves across 14 hectares in two subdistricts, Panimbang and Sumur, along the coast of Pandeglang, Banten, Indonesia. Launched in 2021, the program brings together a range of stakeholders, including local government, the university, and community representatives.

With the program now entering its fifth year, effective monitoring becomes more crucial than ever. In response to this, AP Hub launched **[Map4Mangrove](https://www.hotosm.org/projects/map4mangrove-indonesia/)** – an initiative designed to support the Blue Carbon program’s monitoring through the integration of open mapping tools and approaches.

<hr>

### How Open Mapping Can Advance Mangrove Conservation

Despite increased awareness of mangroves’ ecological importance, mangrove management in Indonesia still faces significant challenges. These include limited monitoring and post-planting maintenance. Even when monitoring is in place, **data – including spatial data – are often fragmented or hard to access.**
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>Carousel</title>
  <style>
    * {
      box-sizing: border-box;
      margin: 0;
      padding: 0;
    }
    body {
      font-family: sans-serif;
    }
    .carousel-wrapper {
      position: relative;
      width: 100%;
      max-width: 100%;
      margin: 20px auto;
      overflow: hidden;
    }
    .carousel {
      overflow: hidden;
      width: 100%;
    }
    .carousel-images {
      display: flex;
      transition: transform 0.3s ease-in-out;
      will-change: transform;
    }
    .carousel-images img {
      width: 100vw;
      max-width: 100%;
      max-height: 600px;
      object-fit: contain;
      flex-shrink: 0;
      display: block;
    }
    .carousel-controls {
      position: absolute;
      top: 50%;
      width: 100%;
      display: flex;
      justify-content: space-between;
      transform: translateY(-50%);
      pointer-events: none;
    }
    .carousel-controls button {
      background: rgba(0, 0, 0, 0.6);
      color: white;
      border: none;
      font-size: 30px;
      padding: 10px 18px;
      cursor: pointer;
      pointer-events: all;
      user-select: none;
      transition: background 0.3s;
      border-radius: 0;
      min-width: 40px;
      min-height: 40px;
      display: flex;
      align-items: center;
      justify-content: center;
    }
    .carousel-controls button:hover {
      background: rgba(0, 0, 0, 0.8);
    }
    @media (max-width: 600px) {
      .carousel-controls button {
        display: none;
      }
    }
  </style>
</head>
<body>

  <div class="carousel-wrapper">
    <div class="carousel">
      <div class="carousel-images" id="carousel">
        <img src="/uploads/Map4Mangrove_Stakeholder-Workshop-2_2025.jpg" alt="1" />
        <img src="/uploads/Map4Mangrove_Stakeholder-Workshop-3_2025.jpg" alt="2" />
        <img src="/uploads/Map4Mangrove_Stakeholder-Workshop-4_2025.jpg" alt="3" />
      </div>
    </div>

    <div class="carousel-controls">
      <button id="prevBtn">‹</button>
      <button id="nextBtn">›</button>
    </div>
  </div>

  <script>
    const carousel = document.getElementById('carousel');
    const prevBtn = document.getElementById('prevBtn');
    const nextBtn = document.getElementById('nextBtn');
    const totalSlides = carousel.children.length;

    let currentIndex = 0;

    function updateSlide() {
      const slideWidth = carousel.children[0].offsetWidth;
      carousel.style.transform = `translateX(-${currentIndex * slideWidth}px)`;
    }

    function prevSlide() {
      currentIndex = (currentIndex - 1 + totalSlides) % totalSlides;
      updateSlide();
    }

    function nextSlide() {
      currentIndex = (currentIndex + 1) % totalSlides;
      updateSlide();
    }

    prevBtn.addEventListener('click', prevSlide);
    nextBtn.addEventListener('click', nextSlide);

    let startX = 0;
    let endX = 0;

    carousel.addEventListener('touchstart', e => {
      startX = e.touches[0].clientX;
    });

    carousel.addEventListener('touchmove', e => {
      endX = e.touches[0].clientX;
    });

    carousel.addEventListener('touchend', () => {
      const diff = startX - endX;
      if (Math.abs(diff) > 50) {
        if (diff > 0) nextSlide();
        else prevSlide();
      }
      startX = 0;
      endX = 0;
    });

    window.addEventListener('resize', updateSlide);

    updateSlide();
  </script>

</body>
</html>
Map4Mangrove’s project lead, [Harry Mahardhika](https://www.hotosm.org/people/harry-mahardhika-machmud/), opened his session with enthusiasm about the collaboration. Leveraging HOT and AP Hub’s expertise in mapping, the project is a great opportunity to showcase the power of open mapping to support issues beyond humanitarian and disaster response. This time, it’s **biodiversity** and **conservation.**

> “Given the dynamic challenges in conservation work, not all results may always meet expectations. That’s why we need a way to visualize our progress,” Harry explained.
<br>
<hr>
<br>
In this collaboration, AP Hub will work closely with KEHATI and SALAKA to support the Blue Carbon program through mapping, data collection, spatial analysis, and visualization. This includes leading the development of a **dynamic, open-access map platform (dashboard).**

The main uses of the dashboard will include:

1) **Progress monitoring**
* Visualizing the location and distribution of mangrove rehabilitation sites, including key data such as rehabilitation land area (hectares), land legality status, number of planted seedlings, and mangrove planting techniques.
* Providing field data on mangrove species, diameter at breast height (DBH), and degradation levels to assess health, individual mangrove area characteristics, and rehabilitation effectiveness. 
* Showcasing the village potential and socio-economic activities near and within the mangrove rehabilitation sites to help understand the overall relationship between mangroves and the surrounding communities.
* Enabling virtual exploration of rehabilitation sites through [Mapillary](https://www.mapillary.com/) to enhance visual information and understanding of local context.

In summary, having a **centralized, open-source dashboard with reliable and consistent data** will make it easier to track mangrove loss and gain, evaluate success, and make informed management decisions.

2) **Impact reporting**

Showcasing and providing insights into the Blue Carbon program’s collective efforts and ecological impact since its launch in 2021. Through intuitive and engaging visualization, the dashboard shares a **data-driven narrative of rehabilitation progress and the program’s broader environmental and socio-economic outcomes.**

3) **Identifying opportunities for expansion**

Visualizing potential new mangrove rehabilitation areas using data layers from [Global Mangrove Watch](https://www.globalmangrovewatch.org/) and [OpenStreetMap](https://www.openstreetmap.org/).

![Map4Mangrove_Stakeholder-Workshop-5_2025.jpg](/uploads/Map4Mangrove_Stakeholder-Workshop-5_2025.jpg)

<div style="text-align: center;"><span style="font-size: 12px;">The AP Hub team showcased the latest prototype of Map4Mangrove’s dashboard and its practical applications for mangrove monitoring. Explore the dashboard <a href="https://bit.ly/map4mangrove-dashboard" target="_blank" rel="noopener noreferrer">here</a>.</span></div>
<br>

“Aside from data collection and mapping of the mangrove sites, we are also looking to map buildings and roads in the surrounding area,” Harry added.

Considering the area was prone to disasters (including a [tsunami](https://en.wikipedia.org/wiki/2018_Sunda_Strait_tsunami) in 2018), this additional data will be crucial for **informing future disaster mitigation efforts.** Specifically, it will be used to visualize coastal flood zones, which are areas projected to experience flooding in the next 10 years.

<hr>

<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>Carousel</title>
  <style>
    * {
      box-sizing: border-box;
      margin: 0;
      padding: 0;
    }
    body {
      font-family: sans-serif;
    }
    .carousel-wrapper {
      position: relative;
      width: 100%;
      max-width: 100%;
      margin: 20px auto;
      overflow: hidden;
    }
    .carousel {
      overflow: hidden;
      width: 100%;
    }
    .carousel-images {
      display: flex;
      transition: transform 0.3s ease-in-out;
      will-change: transform;
    }
    .carousel-images img {
      width: 100vw;
      max-width: 100%;
      max-height: 600px;
      object-fit: contain;
      flex-shrink: 0;
      display: block;
    }
    .carousel-controls {
      position: absolute;
      top: 50%;
      width: 100%;
      display: flex;
      justify-content: space-between;
      transform: translateY(-50%);
      pointer-events: none;
    }
    .carousel-controls button {
      background: rgba(0, 0, 0, 0.6);
      color: white;
      border: none;
      font-size: 30px;
      padding: 10px 18px;
      cursor: pointer;
      pointer-events: all;
      user-select: none;
      transition: background 0.3s;
      border-radius: 0;
      min-width: 40px;
      min-height: 40px;
      display: flex;
      align-items: center;
      justify-content: center;
    }
    .carousel-controls button:hover {
      background: rgba(0, 0, 0, 0.8);
    }
    @media (max-width: 600px) {
      .carousel-controls button {
        display: none;
      }
    }
  </style>
</head>
<body>

  <div class="carousel-wrapper">
    <div class="carousel">
      <div class="carousel-images" id="carousel">
        <img src="/uploads/Map4Mangrove_Stakeholder-Workshop-6_2025.jpg" alt="1" />
        <img src="/uploads/Map4Mangrove_Stakeholder-Workshop-7_2025.jpg" alt="2" />
      </div>
    </div>

    <div class="carousel-controls">
      <button id="prevBtn">‹</button>
      <button id="nextBtn">›</button>
    </div>
  </div>

  <script>
    const carousel = document.getElementById('carousel');
    const prevBtn = document.getElementById('prevBtn');
    const nextBtn = document.getElementById('nextBtn');
    const totalSlides = carousel.children.length;

    let currentIndex = 0;

    function updateSlide() {
      const slideWidth = carousel.children[0].offsetWidth;
      carousel.style.transform = `translateX(-${currentIndex * slideWidth}px)`;
    }

    function prevSlide() {
      currentIndex = (currentIndex - 1 + totalSlides) % totalSlides;
      updateSlide();
    }

    function nextSlide() {
      currentIndex = (currentIndex + 1) % totalSlides;
      updateSlide();
    }

    prevBtn.addEventListener('click', prevSlide);
    nextBtn.addEventListener('click', nextSlide);

    let startX = 0;
    let endX = 0;

    carousel.addEventListener('touchstart', e => {
      startX = e.touches[0].clientX;
    });

    carousel.addEventListener('touchmove', e => {
      endX = e.touches[0].clientX;
    });

    carousel.addEventListener('touchend', () => {
      const diff = startX - endX;
      if (Math.abs(diff) > 50) {
        if (diff > 0) nextSlide();
        else prevSlide();
      }
      startX = 0;
      endX = 0;
    });

    window.addEventListener('resize', updateSlide);

    updateSlide();
  </script>

</body>
</html>

Harry also introduced some of the tools planned to be used for data collection: [HOT Field Tasking Manager](https://mapper.fmtm.hotosm.org/), [Mapillary](https://www.mapillary.com/), and [MapSwipe](https://mapswipe.org/). Responding to these tools, Fitrian Dwi Cahyo, Coastal and Marine Analyst at the [Local Office for Coastal and Marine Resource Management (LOKA PSPL) Serang](https://kkp.go.id/unit-kerja/djpkrl/upt/loka-pengelolaan-sd-pesisir-laut-serang.html), was impressed with their user-friendliness and expressed interest in learning more.

At the end of the day, **community remains at the heart of the open mapping movement.** Ensuring that tools are easy to use is key to driving community involvement and reducing barriers related to digital literacy.

> “Through open mapping, we hope that data collection will not only be done by us, but can also be supported by everyone here today, including community representatives who can give us clearer local insight on current rehabilitation sites,” Harry shared.

<hr>
<br>
![Map4Mangrove_Stakeholder-Workshop-8_2025.jpg](/uploads/Map4Mangrove_Stakeholder-Workshop-8_2025.jpg)

The session sparked lively discussion from the audience. Once the event entered the Q&A session, a couple of hands were immediately raised. Some highlight questions included:

**LOKA PSPL Serang:** We’re really interested in the dashboard. Is it possible to make it time-series to address the dynamic needs of mangrove conservation? And will it only include data from this year alone, or will it be continuous?

**Harry:** Yes, it is very possible to include a time-series feature to visualize conservation progress over the years.

As for continuity, the main reason we invited everyone here today to contribute to the project – including university students and community representatives – is because we want the dashboard to be more than just a one-time thing. Our hope is that by the end of the project in October, we can hand it over to relevant parties interested in maintaining it, whether for data monitoring or adding new field data.

That’s also why during our upcoming field mapping activities, we want everyone to get involved and learn how to contribute to the dashboard. This way, **even after this project ends, the dashboard can be continued since capacity building will already be in place.**

So, the potential for long-term use is there, but ensuring its sustainability requires commitment from KEHATI and all stakeholders.

Another note: data from the dashboard can also be downloaded in various formats, which allows further integration if LOKA PSPL or other government agencies already have their own data systems.

<hr>
<br>
**University student representative:** How can we take part in data collection and field mapping? Are there any specific requirements?

**Harry:** There’s really only one requirement: commitment. Once we’ve conducted training on how to use the tools, we hope students and others who join will contribute and help us map all 14 hectares of the mangrove area. With everyone’s collective support, we can enhance the dashboard even further.

Alternatively, in context outside of the Blue Carbon program, feel free to reach out to us and we’d be happy to share learning materials that you can use for your future mapping projects.

<hr>
<br>
Followed by more questions about the dashboard, the discussion provided indirect input on additional features with high use potential, coming from those working directly at the local level. 

Strong interest was also shown in the tools’ broader applications to address diverse biodiversity needs, including those beyond mangrove conservation. As LOKA PSPL shared, “We’re actually currently developing an underwater map. So, we’re really interested in the potential for collaboration.”

<hr>

### Collaboration as Key to Successful Conservation Efforts

At the end of the event, Toufik Alansar, KEHATI’s Marine Program Manager, reflected on the Blue Carbon program’s journey over the past four years.

![Map4Mangrove_Stakeholder-Workshop-9_2025.jpg](/uploads/Map4Mangrove_Stakeholder-Workshop-9_2025.jpg)

Looking toward the audience, especially community representatives who have been working tirelessly to improve their local area, he added, “At the end of the day, these mangroves don’t belong to KEHATI or Asahimas. **They belong to the community.** After this project ends in 2026, we will hand over the management of the planted mangrove areas to the community groups.”

“Personally, what I’m really trying to look for today are **gaps.** From the challenges shared and new insights gained, I hope we can try to come up with **solutions** to address those gaps. Let’s continue to collaborate and work together,” Toufik emphasized. 

<hr>
<br>
Thanks to the event, new connections were made and collaboration was strengthened. Reflecting on the positive response to Map4Mangrove, Harry hopes the collaboration with KEHATI, SALAKA, and all Blue Carbon Program stakeholders will result in something great and impactful by the end of this year.

![Map4Mangrove_Stakeholder-Workshop-10_2025.jpg](/uploads/Map4Mangrove_Stakeholder-Workshop-10_2025.jpg)

<div style="text-align: center;"><span style="font-size: 12px;">The AP Hub team with KEHATI, SALAKA, UNTIRTA, and PT Asahimas Chemical, working together on mangrove conservation for a greener and bluer future.</span></div>
<br>

Beyond that, hearing presentations from SALAKA, who work closely with the communities, had also sparked a new personal insight. Originally, the Blue Carbon program started with the goal of planting mangroves, but over its four years of implementation, it has grown to support broader social impact areas, including improving local livelihoods and enterprises. With guidance from SALAKA, the community has developed unique local products using natural resources like salt and [jeruju](https://kehati.or.id/jeruju-gulma-yang-bisa-menjadi-alternatif-sumber-pendapatan/) (mangrove shrubs).

> “Seeing all these ‘domino effects’ from their program got me thinking. For Map4Mangrove, our main goal is to create a dashboard to monitor the Blue Carbon program’s rehabilitation sites. But who knows what else it could evolve into – **what kind of impact and other good initiatives it might support beyond this project.**”

<hr>

### What’s Next

![Map4Mangrove_Stakeholder-Workshop-11_2025.jpg](/uploads/Map4Mangrove_Stakeholder-Workshop-11_2025.jpg)

This project marks not only AP Hub’s pilot collaboration with KEHATI, but also an important first step in applying open mapping to support mangrove conservation. We hope this initiative can serve as an entryway for **more organizations in conservation and biodiversity to explore and adopt open mapping approaches**, leading to more effective, community-driven monitoring.

Following this event, at the end of July 2025, the AP Hub team, together with KEHATI and SALAKA, have conducted [field mapping activities](https://www.linkedin.com/posts/openmapping-ap_map4mangrove-bluecarbon-climateaction-activity-7361384988996509697--Dt6) at five different mangrove rehabilitation sites, which included capturing aerial imagery with drones.

Currently, the team is preparing for capacity building in the form of training of trainers for local teams and stakeholders to ensure the project’s long-term sustainability. We’re excited to share more news and progress soon!

<hr>

<span style="font-size: 12px;">*Photos: Tony Liong / Open Mapping Hub - Asia Pacific*</span>

Explore more photos from the events [here](https://www.flickr.com/photos/hotosm/albums/72177720328260367/).