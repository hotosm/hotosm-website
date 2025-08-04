---
title: Climate Resilience Fellowship - Bangladesh
date: 2025-07-22 06:24:00 Z
tags:
- Asia Pacific
- Bangladesh
Project Summary Text: The Climate Resilience Fellowship empowers young leaders across
  Bangladesh to design and implement community-led projects–known as “capstone projects”–to
  address urgent climate issues. By combining climate data and open mapping technologies
  with local knowledge and people-centered approaches, fellows work directly with
  communities to reduce climate risks and strengthen climate resilience.
Feature Image: "/uploads/CRF_Website-Cover.jpg"
Is image top aligned: false
Country:
- Bangladesh
Impact Area:
- Sustainable Cities & Communities
Person:
- Mikko Tamura
Partner:
- NetHope
- World Vision Bangladesh
Duration:
  Start Date: 2024-10-01 00:00:00 Z
---

## Climate, a Regional Challenge

Across the Asia-Pacific region, climate impacts are becoming more severe and uneven—affecting informal settlements, frontline communities, and marginalized groups first. Many of these areas lack reliable data, infrastructure, and representation in resilience planning processes.

In areas like Dhaka and Chattogram, local communities face growing climate risks such as flooding, extreme heat, and water shortages.

<hr>

## Local Youth Leadership to Drive Sustainable, Community-Led Solutions

<style>
.responsive-video {
  position: relative;
  padding-bottom: 56.25%; /* 16:9 aspect ratio */
  height: 0;
  overflow: hidden;
  max-width: 100%;
  margin: 0 auto;
}

.responsive-video iframe {
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
}
</style>

<div class="responsive-video">
  <iframe src="https://www.youtube.com/embed/cW6esPYk0us?si=2cJPcJqsMtTnj9Ub"
          title="YouTube video player"
          frameborder="0"
          allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share"
          referrerpolicy="strict-origin-when-cross-origin"
          allowfullscreen>
  </iframe>
</div>
<br>
The Climate Resilience Fellowship (CRF) is a joint initiative by [Open Mapping Hub - Asia Pacific (AP Hub)](https://www.hotosm.org/hubs/open-mapping-hub-asia-pacific/) and [World Vision Bangladesh](https://www.wvi.org/bangladesh), funded by [NetHope](https://nethope.org/). The program puts **local youth** at the center of climate resilience work.

**CRF goals:**
* Build local leadership among youth in climate-affected regions
* Enable fellows to design data-informed, community-driven interventions
* Connect open mapping technologies with local knowledge to drive sustainable climate solutions
* Provide space for experimentation, learning, and scaling of promising approaches
* Increase representation of underrepresented groups through map and data visualizations

In the long term, CRF aims to spark a larger movement for inclusive, localized, and community-led climate resilience across Asia Pacific.

<hr>

### Why Local Youth?

We believe **the best solutions come from those who truly understand the problems.**

Fellows were selected from both the climate action and open mapping communities, bridging technical expertise with lived experiences. As youth, they also bring fresh perspectives, creative problem-solving, and strong motivation to shape their communities’ futures.

Most importantly, they are **local leaders.** They live in or around the communities they serve and understand their challenges firsthand. Through their vision and deep community insight, they can create **sustainable, impactful, and inclusive solutions that truly address local needs.**

<hr>

### Capstone Projects

<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>Carousel with Arrows and Dots</title>
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
      width: 100vw;
      max-width: 100%;
      margin: 40px auto;
    }
    .carousel {
      overflow: hidden;
      width: 100%;
    }
    .carousel-images {
      display: flex;
      transition: transform 0.3s ease-in-out;
    }
    .carousel-images img {
      width: 100vw;
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
    }
    .carousel-controls button:hover {
      background: rgba(0, 0, 0, 0.8);
    }
    .carousel-pagination {
      text-align: center;
      margin-top: 15px;
    }
    .carousel-pagination button {
      background: #ddd;
      border: none;
      border-radius: 50%;
      width: 12px;
      height: 12px;
      margin: 0 5px;
      cursor: pointer;
    }
    .carousel-pagination button.active {
      background: #333;
    }
    @media (max-width: 600px) {
      .carousel-controls button {
        font-size: 24px;
        padding: 8px 12px;
      }
    }
  </style>
</head>
<body>

  <div class="carousel-wrapper">
    <div class="carousel">
      <div class="carousel-images" id="carousel">
        <img src="/uploads/CRF-Capstone-Project-1.png" alt="1" />
        <img src="/uploads/CRF-Capstone-Project-2.png" alt="2" />
        <img src="/uploads/CRF-Capstone-Project-3.png" alt="3" />
        <img src="/uploads/CRF-Capstone-Project-4.png" alt="4" />
        <img src="/uploads/CRF-Capstone-Project-5.png" alt="5" />
        <img src="/uploads/CRF-Capstone-Project-6.png" alt="6" />
        <img src="/uploads/CRF-Capstone-Project-7.png" alt="7" />
        <img src="/uploads/CRF-Capstone-Project-8.png" alt="8" />
        <img src="/uploads/CRF-Capstone-Project-7.png" alt="9" />
        <img src="/uploads/CRF-Capstone-Project-8.png" alt="10" />
      </div>
    </div>

    <div class="carousel-controls">
      <button id="prevBtn">‹</button>
      <button id="nextBtn">›</button>
    </div>
  </div>

  <div class="carousel-pagination" id="pagination"></div>

  <script>
    const carousel = document.getElementById('carousel');
    const totalSlides = carousel.children.length;
    let currentIndex = 0;

    const pagination = document.getElementById('pagination');
    const prevBtn = document.getElementById('prevBtn');
    const nextBtn = document.getElementById('nextBtn');

    function updateSlide() {
      const slideWidth = carousel.children[0].clientWidth;
      const offset = -currentIndex * slideWidth;
      carousel.style.transform = `translateX(${offset}px)`;
      updatePagination();
    }

    function prevSlide() {
      currentIndex = (currentIndex - 1 + totalSlides) % totalSlides;
      updateSlide();
    }

    function nextSlide() {
      currentIndex = (currentIndex + 1) % totalSlides;
      updateSlide();
    }

    function createPagination() {
      for (let i = 0; i < totalSlides; i++) {
        const dot = document.createElement('button');
        dot.addEventListener('click', () => {
          currentIndex = i;
          updateSlide();
        });
        pagination.appendChild(dot);
      }
    }

    function updatePagination() {
      const dots = pagination.children;
      for (let i = 0; i < dots.length; i++) {
        dots[i].classList.toggle('active', i === currentIndex);
      }
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

    createPagination();
    updateSlide();

    window.addEventListener('resize', updateSlide);
  </script>

</body>
</html>

<br>
Each fellow group leads a capstone project that addresses a specific climate risk or capacity gap. Projects cover diverse themes, including waste management, rainwater harvesting, heat adaptation, climate education, and community awareness.

Designed to be realistic, replicable, and community-owned, the capstone projects will primarily engage local communities in Dhaka, with a few projects taking place in Chattogram.
<br>
<hr>

## The Fellowship Phases

1. **Capacity Building** – Fellows participated in core learning sessions on open mapping, climate action, community engagement, and project development.
2. **Project Planning & Mentorship** – Fellows designed their capstone proposals, refined them through feedback from mentors and technical staff, and aligned their work with community needs and feasibility. This phase concluded with the Culmination Week.
3. **Capstone Implementation** (current phase) – Fellows are implementing their projects with seed funding, regular check-ins, and community engagements over three months.
4. **Pitching Session** (final phase) – Fellows will present their projects to a panel of funders, community leaders, and innovation experts. This event aims to propel promising projects forward through:

- Strategic feedback on scalability and sustainability
- Networking opportunities for future partnerships or funding
- Recognition and visibility for grassroots innovation in climate resilience
- Support to help projects sustain and grow

<hr>
<br>
By the end of the fellowship, fellows will have strengthened their skills and confidence in leveraging open mapping for climate action, while also have implemented **pilot projects that shed light on local vulnerabilities and solutions.**

Additionally, they will inspire other youths and future generations to become changemakers in climate resilience and open mapping.

<hr><br>
Stay updated on the latest news from our fellows’ capstone projects through our [social media channels](http://linktr.ee/openmapping_ap).

<span style="font-size: 12px;">*Cover and slider photos credit: Rajib Mahmud / World Vision Bangladesh*</span>