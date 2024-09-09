---
title: 'The Power of Volunteers: Remote Mapping in Gaza and Other Conflict Areas'
date: 2024-08-20 21:06:00 Z
Summary Text: 'As damage reaches record levels in the Gaza Strip, expert volunteers
  coordinated by HOT have recently completed a 5-month project to create the most
  comprehensive building footprints dataset available for Gaza using OpenStreetMap.
  Looking at pre-October 2023 imagery, this effort added a net total of 59,223 buildings
  to the dataset and improved thousands of existing features. In this post, we share
  how our work in Gaza illustrates our approach to open mapping in conflict zones,
  and examines the potential role of artificial intelligence and machine learning
  (AI/ML) in the sector.

'
Feature Image: "/uploads/GazaCity.jpg"
Person: Jessica Pechmann
Country:
- Palestinian Territory
---

<html lang="en">
<head>
<style>
.image-container {
display: flex;
justify-content: center;
margin: 20px 0;
}

        .image-container img {
            width: 80%; 
            height: auto; 
        }
    
        .image-container2 {
            display: flex;
            justify-content: center; 
            margin: 20px 0;
        }
    
        .image-container2 img {
            width: 65%; 
            height: auto; 
        }
    
        @media (max-width: 768px) {
            .image-container img {
                width: 50%; 
            }
        }
    
        @media (max-width: 480px) {
            .image-container img {
                width: 75%; 
            }
        }
    </style>

</head>
<body>
<p>As an open map of the world, <a href="https://www.openstreetmap.org">OpenStreetMap (OSM)]</a> is a valuable tool for understanding the impacts of war and informing humanitarian response. For example, OSM can provide a baseline dataset of pre-conflict building footprints to be compared with damage analyses.</p>

<p>In Gaza, the escalation of conflict since October 2023 has resulted in a prolonged humanitarian crisis. Understanding the impact of the conflict on buildings has been challenging because pre-existing datasets from AI/ML models and OSM were not accurate enough to create a complete buildings baseline. The high density of buildings and the inability to safely gather on-the-ground information compounded these challenges. In such hard-to-reach areas, HOT’s remote and crowdsourced mapping methodology proved effective in collecting detailed information visible on aerial imagery.</p>

    <p>In February 2024, after consultation with humanitarian and UN actors working in Gaza, HOT initiated the creation of pre-conflict dataset of all building footprints in the area in OSM. HOT’s <a href="https://www.hotosm.org/community/">community of OpenStreetMap volunteers</a> did all the data <a href="https://wiki.openstreetmap.org/wiki/Gaza_Update_2024">work</a>, coordinating through HOT’s <a href="https://tasks.hotosm.org/">Tasking Manager</a>. The volunteers made meticulous edits to add missing data and to improve existing data. Due to protection and data quality concerns, only expert volunteer teams were assigned to map and validate the area. As in other areas that are hard to reach due to conflict, HOT balanced the data needs with <a href="https://www.hotosm.org/tools-and-data/data-principles/">responsible data practices</a> based on the context.</p>
    
    <div class="image-container">
        <img src="/uploads/Example%20of%20increased%20data%20quality%20in%20OpenStreetMap%20building%20footprints%20in%20Gaza.png" alt="Example of increased data quality in OpenStreetMap building footprints in Gaza">
    </div>
    
    <p>The updated data is live in OpenStreetMap and available via <a href="https://data.humdata.org/dataset/hotosm_pse_buildings?">HDX</a> or <a href="https://export.hotosm.org/v3/">HOT’s Export Tool</a>.</p>
    
    <h2>Comparing AI/ML with human-verified OSM building datasets in conflict zones 

</h2>

<p>AI/ML is becoming an increasingly common and quick way to obtain building footprints across large areas. Sources for automated building footprints range from worldwide datasets by Microsoft or Google to smaller-scale open community-managed tools such as HOT’s new application, <a href="https://www.hotosm.org/tech-suite/fair/">fAIr.</a></p>

    <p>Now that HOT volunteers have completely updated and validated all OSM buildings in visible imagery pre-conflict, <strong>OSM has 18% more individual buildings in the Gaza strip</strong> than  Microsoft’s ML buildings dataset (estimated 330,079 buildings vs 280,112 buildings). However, in contexts where there has not been a coordinated update effort in OSM, the numbers may differ. For example, in Sudan where there has not been a large organized editing campaign, there are just under 1,500,000 in OSM, compared to over 5,820,000 buildings in Microsoft’s ML data. It is important to note that the ML datasets have not been human-verified and their accuracy is not known. Google Open Buildings has over 26 million building features in Sudan, but on visual inspection, many of these features are noise in the data that the model incorrectly identified as buildings in the uninhabited desert.</p> 

<p>If spatial coverage is relatively similar between OSM and ML datasets, for many use cases, automated datasets created by ML image detection work well. For other use cases, the precision and verification of a human-checked dataset, such as OSM, is a better fit for the data requirements. For example, during our work in Gaza, we identified issues with ML building datasets that were avoided by working with experienced human volunteers (see image below comparing OSM to <a href="https://planetarycomputer.microsoft.com/dataset/ms-buildings">Microsoft’s ML building datasets</a>).

    <div class="image-container">
        <img src="/uploads/Examples%20of%20OSM%20vs%20AI%20in%20Gaza%20August%202024-a8e5cb.png" alt="Examples of OSM vs AI in Gaza August 2024">
    </div>
    
    <h2>What’s next?</h2>
    
    <p>When all buildings in conflict zones are reflected in one pre-conflict dataset, data analysts can track which buildings are functional and which are destroyed. Eventually, we will be able to track demolition and rebuilding when the context allows. HOT welcomes data requests from the humanitarian community and we will do our best to balance requests with anticipated usefulness, resources, and protection issues to address humanitarian data gaps in conflict zones worldwide.</p>
    
    <p>With increasingly complex emergencies displacing a <a href="https://www.unhcr.org/us/global-trends">record</a> number of people globally, aid organizations are struggling to keep up.  While automation is improving the speed and ability to remotely collect information in hard-to-reach areas, HOT’s approach to coordinating trained volunteers is more important than ever. Lessons learned from the data work in Gaza show that when higher accuracy data is needed, incorporating a human touch into automated ML datasets is still a crucial endeavor.</p>

<strong>There are many ways to get involved with our efforts. Contact us at <a href="mailto:data@hotosm.org">data@hotosm.org</a> to partner, volunteer, or donate to ongoing efforts in conflict-affected areas worldwide</strong>.</p>

    <p>For information on recent damage in Gaza  or Sudan, visit <a href="https://experience.arcgis.com/experience/ea5c453e92724c6ba0a7b8a4037129be/page/UNOSAT/?org=unosat&views=Share">UNOSAT’s Gaza Interactive Data Platform</a> and <a href="https://unosat.org/products/?date_from=2024-02-28&date_to=2024-08-28&region=&activation_type=&title=&is_charter=null">UNOSAT Analyses</a>, or the <a href="https://www.conflict-damage.org/">Decentralized Damage Mapping Group</a>.</p>
    
    <div class="image-container2">
        <img src="/uploads/Gaza-Update-Announcement-Aug-2024.png" alt="Gaza Update Announcement Aug 2024">
    </div>
    
    <p><a href="https://drive.google.com/file/d/1jVjJjji1NhLPCfk7LAf1fXXp6k4YGU0C/view?usp=sharingusp=sharing">Pdf version with the summary of Gaza Update 2024</a></p>
    
    
    <p><em>Cover image: Gaza City in 2006. Public domain.</em></p>

</body>
</html>