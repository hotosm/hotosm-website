---
title: Some Powerful Map Outputs From The Ugandan Refugee Response
date: 2018-04-14 08:14:19 Z
permalink: updates/2018-04-14_some_powerful_map_outputs_from_the_ugandan_refugee_response
Person: Rupert Allan
Projects:
- Missing Maps
Country:
- Uganda
Feature Image: https://s3.amazonaws.com/hotwww/files/old/styles/banner/public/27580116_959865527505210_4064508284428615680_n.jpg
created: 1523693659
---

*Image: Waiting for Water - Long queues of Jerrycans at the dried-out borehole near BidiBidi Refugee Settlement*

Since December 2017, HOT Uganda Community Surveyors have mapped more than eleven thousand geopoints in and around some of the biggest refugee settlements in the world. These are located in Northern Uganda south sudanese refugee response areas. This is not one refugee camp, but several.

Refugee settlements are dispersed, and well-laid out as a whole, with the idea that life in the settlement can be sustainable. Tents are dotted amongst the trees in some areas, and vegetable plots are normal, and a model of self-reliance is encouraged.

The doors of these camps are opening-up again, as the influx from Democratic Republic of Congo builds. HOT's ability to provide ground-truthed maps with information from each NGO and every community's self-gathered data is an innovation that has never been seen before here. WIth the international OSM community's help, HOT is managing to compile mapathon changesets and locally-gathered field data to significantly shape the UNHCR-coordinated Disaster Response. Large NGOs and government agencies are starting to train-in and use OpenStreetMap tools. This week sees a training of World Vision International, who are starting to consider embedding OSM in their programs. We are training Cartographers from Uganda's Ministry of Lands on a regular basis, as well as staff from the Office of the Prime Minister.

Below are some of the maps that we all as a community have managed to create:

### Settlements in Northern Uganda

<iframe src="https://overpass-turbo.eu/map.html?Q=%5Bout%3Ajson%5D%5Btimeout%3A250%5D%3B%0Aarea(3600192796)-%3E.Uganda%3B%0A%0A(%0A%0A%20%20way%5B%22boundary%22%3D%22refugee_camp%22%5D(2.7757080586045757%2C30.87570190429688%2C3.697077779669845%2C32.07595825195312)%3B%0A%20%20relation%5B%22boundary%22%3D%22refugee_camp%22%5D(2.7757080586045757%2C30.87570190429688%2C3.697077779669845%2C32.07595825195312)%3B%0A%20%20%0A%20%20%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%0A%20%20%0A%20%20%0A)%3B%0A%2F%2F%20print%20results%0Aout%20body%3B%0A%3E%3B%0Aout%20skel%20qt%3B%7B%7Bstyle%3A%20%0A%20%20%0A%20%20way%20%7Bcolor%3A%20blue%3B%7D%0A%20%20%0A%20%20%2F*Village%2FBlock%2FTank*%2F%0A%20%20relation%5Badmin_level%3D5%5D%20%7B%0A%20%20%20%20color%3A%20gray%3B%0A%20%20%20%20width%3A%201%3B%0A%20%20%7D%0A%20%20%2F*Points%2FVillages*%2F%0A%20%20relation%5Badmin_level%3D4%5D%20%7B%0A%20%20%20%20color%3A%20teal%3B%0A%20%20%7D%0A%20%20%2F*Zones*%2F%0A%20%20relation%5Badmin_level%3D3%5D%20%7B%0A%20%20%20%20color%3A%20darkred%3B%0A%20%20%7D%0A%20%20%2F*Settlements*%2F%0A%20%20relation%5Badmin_level%3D2%5D%20%7B%0A%20%20%20%20color%3A%20purple%3B%0A%20%20%20%20text%3A%20name%3B%0A%20%20%7D%0A%20%20%0A%20%20node%20%7Bsymbol-size%3A%200.1%3B%7D%0A%20%20%0A%20%20%0A%20%7D%7D" style="width:600px;height:500px;" frameborder="0"></iframe>

Cleaning this amount of data is not easy. The HOT team, Dylan. Deo, Allan, and Shamillah have been through each 'change-set' in all of this data, checked its attributes, conventionalised it for OpenStreetMap, and uploaded it. Partners who are planning interventions, and trying to efficiently direct their resources can now search Boreholes in remote villages which dry out in the hot months. Anybody in the world can use OpenStreetMap to see all of these, and can contribute a little to the map if they choose. Mapping in the past has been historically restricted to GIS speciallists. Now Refugees can use OpenSource GIS to put needs on the map. And now we can all ask the map certain questions, and it can tell us stories. Very beautiful results can come out of this, as the different visualisations can be coloured and styled in creative and individual ways. It can also be presented using standard official (United Nations) icons.

One of the fun bits of technical trainings is the wide grins - and sometimes laughs - that people express when they see, say, the tricky logic of a survey tool. Technology is not always impersonal, and, used right, can be manipulated to ask that certain question in a very sensitive or 'localised' way. Despite digital codes, there is much anthropology, even poetry in many of our OSM tools. OSM can work in different languages, and can accommodate terms and idioms that are specific to tiny rural areas in the middle of nowhere. This is special.

'Relating objects to people' is what map-production is all about. How people behave around the things they need in everyday life is fascinating. It has been called 'Techno-Anthropology'. And when understanding the behaviour can help solve a real life-or -death crisis, it is even better.

One of the goals of our project is that new OSM community members can make their own maps. Granted, a major part of the beauty of the maps is the presentation, which can be styed by individuals. But this is only half the wonder.

When we can show in blue all of the 'drinking-water wells in an area, which flood in the rains', that is one great outcome for Aid workers wanting to improve Sanitation. However, when we overlay this with 'geopoints' which represent 'latrines in an area which flood in the rains' (in green, say), we see an area affected by flooding.

But what we also see, to the trained eye, is an opportunity. We can map space. What if we ask to show every latrine which floods, and is less than 50 metres from a well? OUr maps can suddenly highlight (perhaps, say, in red) cholera risk in a given area: the waters will mix. This happens a lot in Africa, and sometimes it is not obvious that it is happening (a fence/forest hides their close proximity, so the risk can not be seen).

When we survey these points, we often ask for disease history, to help understand vulnerability. It usually coincides. That is when we know that we are asking the right kinds of questions. It is technical, but the visualisations can influence the distribution of millions of dollars of assistance to the right place, at the right time. Policy-makers need maps. And sometimes, no other tool will do.

We found that in one area, children were not attending school, so education was seriously undermined. Education can be a life-saving tool here. We heardfrom our surveyors that lessons were disrupted by pupils having to go home to find a toilet. So we decided to make a map: we asked OSM to show us all the schools without latrines in or nearby, in the Arua district.

We used 'Overpass Turbo' to visualise this: CLICKING on the map below produces a live search of OpenStreetMap for these points as they are right now.

### Schools without Sanitation (Red Map Pins) - *A surprising number*

<iframe src="https://umap.openstreetmap.fr/en/map/schools-and-sanitation-2_208023?scaleControl=false&amp;miniMap=true&amp;scrollWheelZoom=false&amp;zoomControl=true&amp;allowEdit=false&amp;moreControl=true&amp;searchControl=null&amp;tilelayersControl=null&amp;embedControl=null&amp;datalayersControl=true&amp;onLoadPanel=none&amp;captionBar=true" style="width:600px;height:400px;" frameborder="0"></iframe>

From this, we could give something to educational NGOs that were concerned. Some children spend a lot of the day collecting water, so we can also map which schools are in villages with more than four kilmetres to walk for water. We are also able to ask OSM which facilities are not lit at night; dark places where people have to go at night have been identified as risk areas for sexual violence. The statistics are quite shocking, but putting them on a map allows humanitarians to focus their campaigns in the areas where there is most risk. It is the leap between word and image which often galvanises people to action.

### Madi Okollo *- the latest new settlement in Northern Uganda*

<img title="Made Okollo Facilities" src="https://s3.amazonaws.com/hotwww/files/old/madi%20okollo_0.png" alt="Made Okollo Facilities" style="width:830px;height:588px;">

A few weeks ago, we found out that a planning team was heading to the field to look at a new area for settling the thousands of congolese who are running from the <a href="http://www.bbc.com/news/av/world-africa-43091237/i-knew-i-had-to-get-out-of-dr-congo">violence </a>over the border. Within a day, we were able to create a map of all the Water, Health and Educational facilities in that area which could be used - and built upon - for the first wave of mass-population of this rural area.

We had roads on this map which had never been on a map before. Sometimes the satellite imagery is obscured by clouds, so these roads cannot not be mapped by 'remote' volunteers. Our motorcycle (boda) riders carry our surveyors down thouseands of tracks. These are recorded with OSMAnd, using the surveyor's Smartphone. We can see from the speeds whether tracks are open roads or narrow paths. We put them on the map as ways into this difficult terrain. We need ongoing help with this from the OSM community, too. We gave some of these maps to drivers of Landcruisers preparing for the field-trip.

### OSMAnd Motorcycle Tracks

<img src="https://s3.amazonaws.com/hotwww/files/old/josm_tracks_example.PNG" alt="" style="width:2700px;height:1444px;">

BELOW: Rhino Education: This is a map of all education facilities in one of the biggest south-sudanese Settlements, Rhino Camp - It has been surprisingly well-received, so much so that we wonder if such a map has ever existed before.

<img src="https://s3.amazonaws.com/hotwww/files/old/Screen%20Shot%202018-04-16%20at%2010.06.31%20AM_0.png" alt="Education" style="width:831px;height:591px;">

Next week, we are going into the congolese refugee settlements to start mapping. It is a huge project. Wish us luck, and get online and make some edits to the Uganda Tasks in the Tasking Manager. Thanks for your support! - The HOT Uganda Team

BELOW: Water and Sanitation maps are the most important of all, in this context of Northern Uganda. Villages are digging for water in dried-out riverbeds during dry season. Times can be brutal.

<img src="https://s3.amazonaws.com/hotwww/files/old/Screen%20Shot%202018-04-16%20at%2010.05.22%20AM.png" alt="" style="width:828px;height:586px;">
