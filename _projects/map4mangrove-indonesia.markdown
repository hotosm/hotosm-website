---
title: Map4Mangrove - Collaborative Mapping for Mangrove Conservation and Climate
  Action  - Indonesia
date: 2025-07-22 19:35:00 Z
tags:
- Asia Pacific
- Indonesia
Project Summary Text: Mangroves play a crucial role in coastal protection, biodiversity
  conservation, and carbon sequestration. To enhance mangrove monitoring efforts,
  Open Mapping Hub - Asia Pacific is partnering with organizations working in biodiversity
  and conservation to integrate open geospatial data into their work.
Feature Image: "/uploads/Map4Mangrove_%20Website-Cover.jpg"
Country:
- Indonesia
Impact Area:
- Disasters & Climate Resilience
Person:
- Harry Mahardhika Machmud
Partner:
- Yayasan KEHATI
- Yayasan SALAKA
Duration:
  Start Date: 2025-01-01 00:00:00 Z
Tools:
- tool: Field Tasking Manager
- link: https://www.mapillary.com/
  tool: Mapillary
- link: https://www.kobotoolbox.org/
  tool: KoboCollect
---

## Monitoring Gaps in Mangrove Conservation

In 2018, a tsunami struck the Sumur and Panimbang Subdistricts in Pandeglang, Banten, Indonesia. This caused severe damage in several mangrove areas, underscoring the urgent need for rehabilitation.

In response, [Yayasan Lestari Alam Kita (SALAKA)](https://salaka.or.id/), through a grant from the [Indonesian Biodiversity Foundation (Yayasan KEHATI)](https://kehati.or.id/) and funding support from [PT Asahimas Chemical](https://asc.co.id/index.php/en/), is implementing the [Blue Carbon program](https://kehati.or.id/en/mangrove-blue-carbon-kehati-and-asahimas-chemical-planting-mangrove-in-pandeglang/)—a mangrove rehabilitation initiative launched in 2021, covering 14 hectares in the affected subdistricts.

![Map4Mangrove_Mangrove-Site-1.jpg](/uploads/Map4Mangrove_Mangrove-Site-1.jpg)

<div style="text-align: center;"><span style="font-size: 12px;">One of the mangrove rehabilitation sites from the Blue Carbon program | Photo: Tony Liong / Open Mapping Hub - Asia Pacific</span></div>

<br>
Despite ongoing restoration efforts, there is still **limited availability of integrated, open geospatial data to support monitoring, reporting, and decision-making.** Without a data-driven approach, achieving long-term mangrove ecosystem resilience and maximizing biodiversity and disaster mitigation benefits remain a challenge.

<hr>

## Open Mapping to Transform Mangrove Monitoring Efforts

Through the **Map4Mangrove** project, [Open Mapping Hub - Asia Pacific (AP Hub)](https://www.hotosm.org/hubs/open-mapping-hub-asia-pacific/) collaborates with KEHATI to bridge gaps in mangrove monitoring by integrating open mapping technology, tools, and data. Specifically, it will support the Blue Carbon program through:
* Mangrove rehabilitation monitoring and reporting
* Blue carbon estimation
* Disaster risk assessment in the project areas
* Socio-economic analysis

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
      overflow-x: hidden;
    }
    .carousel-wrapper {
      position: relative;
      width: 100%;
      max-width: 100%;
      margin: 40px auto 0;
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
      width: 100%;
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
        <img src="/uploads/Map4Mangrove_Stakeholder-Mapping-1_2025.jpg" alt="1" />
        <img src="/uploads/Map4Mangrove_Stakeholder-Mapping-2_2025.jpg" alt="2" />
      </div>
    </div>

    <div style="text-align: center; margin-top: 10px;">
      <span style="font-size: 12px;">
        The AP Hub team showcased the Map4Mangrove dashboard prototype to local partners and stakeholders during the Blue Carbon program stakeholder workshop. (May 2025) | Photo: Tony Liong / Open Mapping Hub - Asia Pacific
      </span>
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
A key output of the project is a centralized, interactive **digital dashboard** that visualizes critical data. This data will be used by local stakeholders, including the Pandeglang District Government, to strengthen conservation strategies.

Improved geospatial insights will also aid collaboration among stakeholders, ensuring more efficient permitting, ecosystem recovery, and disaster resilience. Ultimately, **integrating open mapping solutions empowers stakeholders with the necessary tools to sustain and scale mangrove restoration efforts across the region.**

<iframe width="100%" height="500px" frameborder="0" allowfullscreen allow="geolocation" src="//umap.hotosm.org/en/map/map4mangrove-dashboard_189?scaleControl=false&miniMap=false&scrollWheelZoom=false&zoomControl=true&editMode=disabled&moreControl=true&searchControl=null&tilelayersControl=null&embedControl=null&datalayersControl=true&onLoadPanel=caption&captionBar=false&captionMenus=true"></iframe><p><a href="//umap.hotosm.org/en/map/map4mangrove-dashboard_189?scaleControl=false&miniMap=false&scrollWheelZoom=true&zoomControl=true&editMode=disabled&moreControl=true&searchControl=null&tilelayersControl=null&embedControl=null&datalayersControl=true&onLoadPanel=caption&captionBar=false&captionMenus=true">See full screen</a></p>

<hr>

### Collaborative, Multi-Stakeholder Approach for Sustainable Monitoring

![Map4Mangrove_Field-Mapping-1_2025.jpg](/uploads/Map4Mangrove_Field-Mapping-1_2025.jpg)

<div style="text-align: center;"><span style="font-size: 12px;">Field mapping activity with KEHATI, SALAKA, university students, and local community representatives (July 2025) | Photo: Tony Liong / Open Mapping Hub - Asia Pacific</span></div>

<br>
Built on the principles of open mapping, Map4Mangrove applies a **participatory approach**, where involvement of partners, stakeholders, and local communities are key throughout all of its phases.

This inclusive process is essential to the long-term sustainability of the monitoring system. In addition to fostering hands-on experience and building technical capacity, it strengthens local ownership and ensures relevance to local contexts and community needs.

<hr>

### Project Phases

![Map4Mangrove_Project-Phases_2025.png](/uploads/Map4Mangrove_Project-Phases_2025.png)

<hr>

## Current Output (July 2025)
1) **Stakeholder mapping**

In May 2025, we shared how open mapping can transform the way we monitor mangrove conservation efforts at the Blue Carbon program stakeholder workshop. Read the article here.

2) Completed **remote mapping** for buildings and roads around the project area.

![Map4Mangrove_Remote-Mapping_2025.png](/uploads/Map4Mangrove_Remote-Mapping_2025.png)

3) **Field mapping**

At the end of July 2025, we conducted a two-day field mapping activity with partners, university students, and local community representatives. Together, we explored, mapped, and documented five mangrove rehabilitation sites.

The activities included:
* Data collection using [HOT Field Tasking Manager](https://mapper.fmtm.hotosm.org/) and [KoboCollect](https://www.kobotoolbox.org/)
* Street-level imagery using [Mapillary](https://www.mapillary.com/)
* Aerial mapping using drone

The data collection questionnaire was developed with SALAKA to ensure its **direct relevance to the identified needs and local context.** In addition to information on mangrove growth and condition, the team gathered data on site accessibility, land administration, tidal information, socio-economic data, and village profiles and local potential.

<a data-flickr-embed="true" href="https://www.flickr.com/photos/hotosm/albums/72177720328324655" title="Map4Mangrove - Field Mapping of Mangrove Sites in Panimbang and Sumur, Banten - Indonesia (2025)"><img src="https://live.staticflickr.com/65535/54718045684_25c51cfe04_h.jpg" width="1600" height="1200" alt="Map4Mangrove - Field Mapping of Mangrove Sites in Panimbang and Sumur, Banten - Indonesia (2025)"/></a><script async src="//embedr.flickr.com/assets/client-code.js" charset="utf-8"></script>

Following this milestone and everyone’s collective work so far, we are now transforming the collected data into impactful visualization and analysis. Follow our journey and stay updated with the latest news from the project through our [social media](https://linktr.ee/openmapping_ap)!

<hr>
<br>
**Take a virtual tour of the rehabilitation sites on Mapillary, captured during field mapping:**

<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <style>
    body {
      font-family: sans-serif;
      margin: 0;
      padding: 0;
      background: #f9f9f9;
    }
    .gallery {
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
      gap: 16px;
      width: 100%;
      margin: 0 auto;
    }
    .gallery-item {
      display: flex;
      flex-direction: column;
      border-radius: 8px;
      overflow: hidden;
      box-shadow: 0 2px 6px rgba(0,0,0,0.1);
      background: white;
    }
    .gallery-item iframe {
      width: 100%;
      aspect-ratio: 16 / 9;
      border: none;
      display: block;
    }
    .mapillary-link {
      padding: 8px 12px;
      background: #f1f1f1;
      text-align: center;
      font-size: 14px;
    }
    .mapillary-link a {
      text-decoration: none;
      color: #007bff;
    }
    .mapillary-link a:hover {
      text-decoration: underline;
    }
  </style>
</head>
<body>

  <div class="gallery">
    <div class="gallery-item">
      <iframe
        src="https://www.mapillary.com/embed?map_style=Mapillary%20light&image_key=769563162192154&x=0.5&y=0.5&style=photo"
        allowfullscreen allow="fullscreen">
      </iframe>
      <div class="mapillary-link">
        <a href="https://www.mapillary.com/app/?pKey=769563162192154&focus=photo" target="_blank">View on Mapillary</a>
      </div>
    </div>

    <div class="gallery-item">
      <iframe
        src="https://www.mapillary.com/embed?map_style=Mapillary%20light&image_key=30821578274123979&x=0.5&y=0.5&style=photo"
        allowfullscreen allow="fullscreen">
      </iframe>
      <div class="mapillary-link">
        <a href="https://www.mapillary.com/app/?pKey=30821578274123979&focus=photo" target="_blank">View on Mapillary</a>
      </div>
    </div>

    <div class="gallery-item">
      <iframe
        src="https://www.mapillary.com/embed?map_style=Mapillary%20light&image_key=754408757181659&x=0.5&y=0.5&style=photo"
        allowfullscreen allow="fullscreen">
      </iframe>
      <div class="mapillary-link">
        <a href="https://www.mapillary.com/app/?pKey=754408757181659&focus=photo" target="_blank">View on Mapillary</a>
      </div>
    </div>

    <div class="gallery-item">
      <iframe
        src="https://www.mapillary.com/embed?map_style=Mapillary%20light&image_key=1438418984101265&x=0.5&y=0.5&style=photo"
        allowfullscreen allow="fullscreen">
      </iframe>
      <div class="mapillary-link">
        <a href="https://www.mapillary.com/app/?pKey=1438418984101265&focus=photo" target="_blank">View on Mapillary</a>
      </div>
    </div>

    <div class="gallery-item">
      <iframe
        src="https://www.mapillary.com/embed?map_style=Mapillary%20light&image_key=719333391263051&x=0.5&y=0.5&style=photo"
        allowfullscreen allow="fullscreen">
      </iframe>
      <div class="mapillary-link">
        <a href="https://www.mapillary.com/app/?pKey=719333391263051&focus=photo" target="_blank">View on Mapillary</a>
      </div>
    </div>
  </div>

</body>
</html>
<br>
<hr>
<br>
**Explore photos from the project:**
* [Stakeholder mapping at the Blue Carbon program workshop (May 2025)](https://www.flickr.com/photos/hotosm/albums/72177720328260367/)
* [Introduction to open mapping tools with university students at UNTIRTA (July 2025)](https://www.flickr.com/photos/hotosm/albums/72177720328303789/) 
* [Field mapping of mangrove sites in Panimbang and Sumur, Banten (July 2025)](https://www.flickr.com/photos/hotosm/albums/72177720328324655/)

<span style="font-size: 12px;">*Cover photo credit: Tony Liong / Open Mapping Hub - Asia Pacific*</span>