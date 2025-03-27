---
title: Table Test
date: 2023-03-28 20:14:00 Z
---

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
            max-width: 512px; /* 50% smaller than original */
            height: 288px; /* 16:9 aspect ratio */
            margin: 0 auto;
            background: white; /* White background */
            border: 1px solid #eee; /* Optional light border */
        }
        .swiper-slide {
            display: flex;
            align-items: center;
            justify-content: center;
            background: white; /* White background for slides */
        }
        .swiper-slide img {
            max-width: 100%;
            max-height: 100%;
            object-fit: contain;
        }
        .swiper-button-next, 
        .swiper-button-prev {
            color: #333; /* Darker arrows for white background */
            background: rgba(255,255,255,0.8);
            width: 30px;
            height: 30px;
            border-radius: 50%;
            border: 1px solid #ddd; /* Light border for visibility */
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