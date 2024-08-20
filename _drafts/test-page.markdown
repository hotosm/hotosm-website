---
title: test-page
date: 2024-08-20 16:43:00 Z
Summary Text: test
---

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Gaza Update 2024</title>
    <style>
        /* Ensure the body or parent container has a max-width */
        body {
            max-width: 1000px; /* Adjust as needed */
            margin: 0 auto;
            padding: 0 15px; /* Optional, for better spacing */
            font-family: Arial, sans-serif;
            line-height: 1.6;
        }

        /* Style images */
        img {
            display: block;
            max-width: 25%;
            height: auto; /* Maintain aspect ratio */
            margin: 0 auto; /* Center align horizontally */
            padding: 10px 0; /* Optional, for spacing between images and text */
        }

        /* Responsive styling for smaller screens */
        @media (max-width: 768px) {
            img {
                max-width: 50%; /* Increase image size for medium screens */
            }
        }

        @media (max-width: 480px) {
            img {
                max-width: 75%; /* Increase image size for small screens */
            }
        }
    </style>
</head>
<body>
    <p>Increased conflict since October 2023 has caused a prolonged humanitarian crisis in the Gaza Strip, and massive damage is only complicating the situation. For humanitarian data analysts to understand what buildings are and are not damaged, a full understanding of pre-conflict buildings is needed as a baseline. Efforts to utilize AI and existing OSM datasets for this full baseline have been challenging as the datasets were not completely accurate. The area’s buildings were too dense, and information on the ground was impossible to collect safely.</p>

    <p>HOT’s remote and crowdsourced mapping methodology can collect detailed information visible on aerial imagery in hard-to-reach areas. In areas that are hard to reach due to conflict, HOT always balances data needs with <a href="https://www.hotosm.org/tools-and-data/data-principles/">responsible data practices</a> based on the context.</p>

    <p>Based on consultation with humanitarian and UN actors working in Gaza, HOT decided in February 2024 to create a pre-conflict dataset of all building footprints in OpenStreetMap. HOT’s <a href="https://www.hotosm.org/community/">community of OpenStreetMap volunteers</a> did all the <a href="https://wiki.openstreetmap.org/wiki/Gaza_Update_2024">data work</a>, coordinated through HOT’s <a href="https://tasks.hotosm.org/">Tasking Manager</a>. Volunteers made meticulous data edits to improve existing data and add missing data. Due to protection and data quality concerns, only expert volunteer teams were assigned to map and validate the area.</p>

    <img src="/uploads/Example%20of%20increased%20data%20quality%20in%20OpenStreetMap%20building%20footprints%20in%20Gaza.png" alt="Example of increased data quality in OpenStreetMap building footprints in Gaza">

    <p>The updated data is live in OpenStreetMap and available via <a href="https://data.humdata.org/dataset/hotosm_pse_buildings?">HDX</a> or <a href="https://export.hotosm.org/v3/">HOT’s Export Tool</a>.</p>

    <h2>Other datasets: comparing ML buildings in Gaza with OSM</h2>

    <p>Increasing AI (machine-learning) detected buildings are a common, quick way to obtain building footprints across large areas. For many use cases, automated datasets created by ML image detection work well. For other use cases, the precision of a human-checked dataset, such as OSM, works better. Not all ML building datasets are the same, but for the sake of comparison and an example of differences to consider when comparing datasets, the below compares OSM to <a href="https://planetarycomputer.microsoft.com/dataset/ms-buildings">Microsoft’s ML building datasets</a> in Gaza. Overall, <strong>OSM has 18% more individual buildings in the Gaza strip</strong> (estimated 330,079 buildings vs 280,112 buildings).</p>

    <img src="/uploads/Examples%20of%20OSM%20vs%20AI%20in%20Gaza%20August%202024.png" alt="Examples of OSM vs AI in Gaza August 2024">

    <h2>What’s next?</h2>

    <p>Now that all buildings in Gaza pre-conflict are reflected in OSM, data analysts can track which buildings are functional and which are destroyed. Eventually, we will be able to track demolition and rebuilding when the context allows.</p>

    <p>With increasingly complex emergencies displacing a <a href="https://www.unhcr.org/us/global-trends">record</a> number of people globally, aid organizations are struggling to keep up. HOT’s approach to coordinating with trained volunteers to remotely gather human-verified data on hard-to-reach areas is more important than ever. <strong>There are many ways to get involved with our efforts. Contact us at data@hotosm.org to partner, volunteer, or donate to ongoing efforts in conflict-affected areas worldwide</strong>.</p>

    <img src="/uploads/Gaza%20Update%20Announcement%20Aug%202024.png" alt="Gaza Update Announcement Aug 2024">

    <p><a href="https://drive.google.com/file/d/1kwKOQgfyAsU56D7HUAxKvUsDwiWwECmG/view?usp=sharing">Pdf version with the summary of Gaza Update 2024</a></p>

    <p>For information on recent damage in Gaza, visit <a href="https://experience.arcgis.com/experience/ea5c453e92724c6ba0a7b8a4037129be/page/UNOSAT/?org=unosat&views=Share">UNOSAT’s Gaza Interactive Data Platform</a> or the <a href="https://www.conflict-damage.org/">Decentralized Damage Mapping Group</a>.</p>

    <p><em>Cover image: Gaza City in 2006. Public domain.</em></p>
</body>
</html>
