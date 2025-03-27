---
title: Table Test
date: 2023-03-28 20:14:00 Z
---

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Photo Carousel</title>
    <!-- Swiper CSS -->
    <link rel="stylesheet" href="https://unpkg.com/swiper/swiper-bundle.min.css">
    <style>
        .swiper-container {
            width: 100%;
            max-width: 512px; /* 50% smaller than before */
            height: 288px; /* 16:9 aspect ratio */
            margin: 0 auto;
        }
        .swiper-slide {
            display: flex;
            align-items: center;
            justify-content: center;
            background: #000;
        }
        .swiper-slide img {
            max-width: 100%;
            max-height: 100%;
            object-fit: contain;
        }
        .swiper-button-next, 
        .swiper-button-prev {
            color: white;
            background: rgba(0,0,0,0.5);
            width: 30px;
            height: 30px;
            border-radius: 50%;
        }
        .swiper-button-next:after, 
        .swiper-button-prev:after {
            font-size: 16px;
        }
        .controls {
            text-align: center;
            margin-top: 10px;
        }
        .controls button {
            background: #333;
            color: white;
            border: none;
            padding: 5px 15px;
            margin: 0 5px;
            border-radius: 3px;
            cursor: pointer;
        }
        .controls button:hover {
            background: #555;
        }
    </style>
</head>
<body>
    <!-- Swiper -->
    <div class="swiper-container">
        <div class="swiper-wrapper">
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Guardianas_del_Conchalito_y_Costa_Salvaje_monitorean_el_manglar_El_Mogote_en_La_Paz_Baja_California_Sur_c4b532.jpg?w=512" 
                     alt="Guardianas monitoring mangroves">
            </div>
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Estero_El_Conchalito_en_La_Paz_Baja_California_Sur_desde_vista_aerea_3_ee8e3e.jpg?w=512" 
                     alt="Aerial view of El Conchalito">
            </div>
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Sesion_de_monitoreo_para_proteccion_de_manglares_de_Baja_California_Sur_01_429c47.jpg?w=512" 
                     alt="Mangrove monitoring session">
            </div>
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Guardianas_del_Conchalito_en_el_manglar_El_Mogote_durante_monitoreos_de_mangle_en_La_Paz_Baja_California_Sur_09b1a1.jpg?w=512" 
                     alt="Guardianas in El Mogote mangroves">
            </div>
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Editaton_Monitoreo_y_proteccion_de_manglares_de_Baja_California_Sur_06_f42b68.jpg?w=512" 
                     alt="Mangrove protection editathon">
            </div>
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Editaton_Monitoreo_y_proteccion_de_manglares_de_Baja_California_Sur_01_0e881d.jpg?w=512" 
                     alt="Mangrove protection workshop">
            </div>
        </div>
        <!-- Navigation buttons -->
        <div class="swiper-button-next"></div>
        <div class="swiper-button-prev"></div>
    </div>

    <!-- Additional manual controls -->
    <div class="controls">
        <button onclick="swiper.slidePrev()">Previous</button>
        <button onclick="swiper.slideNext()">Next</button>
    </div>

    <!-- Swiper JS -->
    <script src="https://unpkg.com/swiper/swiper-bundle.min.js"></script>
    <!-- Initialize Swiper -->
    <script>
        var swiper = new Swiper('.swiper-container', {
            loop: true,
            navigation: {
                nextEl: '.swiper-button-next',
                prevEl: '.swiper-button-prev',
            },
        });
    </script>
</body>
</html>


<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Photo Carousel</title>
    <!-- Link Swiper's CSS -->
    <link rel="stylesheet" href="https://unpkg.com/swiper/swiper-bundle.min.css">
    <style>
        .swiper-container {
            width: 100%;
            max-width: 1024px;
            height: 576px; /* 16:9 aspect ratio */
            margin: 0 auto;
        }
        .swiper-slide {
            display: flex;
            align-items: center;
            justify-content: center;
            background: #000;
        }
        .swiper-slide img {
            max-width: 100%;
            max-height: 100%;
            object-fit: contain;
        }
        .swiper-button-next, 
        .swiper-button-prev {
            color: white;
            background: rgba(0,0,0,0.5);
            width: 40px;
            height: 40px;
            border-radius: 50%;
            display: flex;
            align-items: center;
            justify-content: center;
        }
        .swiper-button-next:after, 
        .swiper-button-prev:after {
            font-size: 20px;
        }
        .swiper-pagination-bullet {
            background: white;
            opacity: 0.6;
        }
        .swiper-pagination-bullet-active {
            background: white;
            opacity: 1;
        }
    </style>
</head>
<body>
    <!-- Swiper -->
    <div class="swiper-container">
        <div class="swiper-wrapper">
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Guardianas_del_Conchalito_y_Costa_Salvaje_monitorean_el_manglar_El_Mogote_en_La_Paz_Baja_California_Sur_c4b532.jpg?w=1024" 
                     alt="Guardianas del Conchalito y Costa Salvaje monitorean el manglar El Mogote en La Paz, Baja California Sur">
            </div>
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Estero_El_Conchalito_en_La_Paz_Baja_California_Sur_desde_vista_aerea_3_ee8e3e.jpg?w=1024" 
                     alt="Estero El Conchalito en La Paz, Baja California Sur desde vista aérea">
            </div>
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Sesion_de_monitoreo_para_proteccion_de_manglares_de_Baja_California_Sur_01_429c47.jpg?w=1024" 
                     alt="Sesión de monitoreo para protección de manglares de Baja California Sur">
            </div>
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Guardianas_del_Conchalito_en_el_manglar_El_Mogote_durante_monitoreos_de_mangle_en_La_Paz_Baja_California_Sur_09b1a1.jpg?w=1024" 
                     alt="Guardianas del Conchalito en el manglar El Mogote durante monitoreos">
            </div>
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Editaton_Monitoreo_y_proteccion_de_manglares_de_Baja_California_Sur_06_f42b68.jpg?w=1024" 
                     alt="Editatón Monitoreo y protección de manglares de Baja California Sur">
            </div>
            <div class="swiper-slide">
                <img src="https://diff.wikimedia.org/wp-content/uploads/2025/03/Editaton_Monitoreo_y_proteccion_de_manglares_de_Baja_California_Sur_01_0e881d.jpg?w=1024" 
                     alt="Editatón Monitoreo y protección de manglares de Baja California Sur">
            </div>
        </div>
        <!-- Add pagination -->
        <div class="swiper-pagination"></div>
        <!-- Add navigation buttons -->
        <div class="swiper-button-next"></div>
        <div class="swiper-button-prev"></div>
    </div>

    <!-- Swiper JS -->
    <script src="https://unpkg.com/swiper/swiper-bundle.min.js"></script>
    <!-- Initialize Swiper -->
    <script>
        var swiper = new Swiper('.swiper-container', {
            loop: true,
            autoplay: {
                delay: 5000,
                disableOnInteraction: false,
            },
            pagination: {
                el: '.swiper-pagination',
                clickable: true,
            },
            navigation: {
                nextEl: '.swiper-button-next',
                prevEl: '.swiper-button-prev',
            },
        });
    </script>
</body>
</html>


<table style="border-bottom: none">
	<tr>
		<th><h2 style="color: #D73F3F">Inclusive and representative</h2></th>
		<th style="border-left: 1px solid black"><h2 style="color: #D73F3F">Ethical data and protection</h2></th>
	</tr>
	<tr>
		<td style="border-bottom: none;"><p style="font-weight: bold">What this means:</p>
		<p>
Ensure communities at all levels can access and work in the OSM ecosystem by how HOT prioritizes, creates, and structures data collection, tech, and community resources.
		</p>
		<p style="font-weight: bold">What we do:</p>
		<ol style="font-size: 1em">
<li>When creating mapping tasks, consider who and what we’re including, and who we’re omitting by how we define the area of impact and the data models.</li>
<li>Design, create, promote, and use technology and tools that are accessible and usable. Give specific attention to more vulnerable and/or minority groups to reduce barriers to access.</li>
<li>Commit to reduce inequities to contribution and participation before, during, and after mapping - such as access to devices, mobile data, digital and map literacy, opportunities and economic viability of volunteering time, etc.</li>
<li>Prioritize localization and accessibility of tools, documentation, and tech by providing multiple relevant languages.</li>
		</ol>
		</td>
		<td style="border-left: 1px solid black; border-bottom: none;"><p style="font-weight: bold">What this means:</p>
		<p>
Go for the most meaningful collaboration in data management and planning. Uphold policies and guidance to minimize risk of harms, including impact assessments and informed consent for any data collection or use, based on the people and communities we work with.
		</p>
		<ol style="font-size: 1em">
<li>Apply a workable process of engagement and informed consent across our activities, including for remote sensing and digitization (while accounting for an ever more sophisticated technological landscape).</li>
<li>Ensure respect for the beliefs, cultures, lifestyles, and choices of communities in the decision making around data collection and sharing, and in our use of collected information. Engage partners in the ethical use of information.</li>
<li>Conduct risk and data impact assessments to assess and minimize risk of harm for all projects together with the relevant communities. In situations where conflict is a factor, follow the “Conflict zones mapping policy”.</li>
<li>Ensure everyone at HOT is compliant with the application of data and protection principles.</li>
		</ol>
		</td>
	</tr>
</table> 