---
title: HOT and iLab Liberia Exploring the Potential of Machine-Learning to Augment
  Human Mappers in Monrovia
date: 2020-06-11 16:40:00 Z
Feature Image: "/uploads/Machine%20Learning%20Monrovia%20Cover%20Image.jpg"
---

HOT, working in Monrovia in partnership with [iLab Liberia](https://www.ilabliberia.org/) and with the support of the World Bank, has been exploring the potential for machine-learning algorithms to augment the work of human mappers. As part of the [Open Cities AI Challenge](https://www.drivendata.org/competitions/60/building-segmentation-disaster-resilience/), HOT and iLab Liberia have been creating spatial data in Monrovia that is used to test and refine machine-learning algorithms. 

The goal of this wider project is to bring together the best machine-learning practitioners from around the world to develop open-source algorithms and workflows that can generate geospatial data for cities. Machine-learning offers HOT, humanitarian and development organizations, and city leaders a valuable toolkit to automate large-scale, repetitious data generation and mapping tasks while highlighting areas that need human attention. 

HOT and iLab Liberia worked together in Monrovia from November 2019 to January 2020 to create data to feed into three machine-learning trials.

### Capturing UAV Imagery for Digitization and Machine-Learning Algorithm Development

For the first trial, HOT worked with [Uhurulabs](http://uhurulabs.org/) to generate twenty square kilometers of drone imagery of Monrovia. Uhurulabs is based in Tanzania, but because local drone expertise is limited in Monrovia, they were brought in and collected the imagery over six days using a SenseFly eBee drone. 

This drone data was provided to the machine learning challenge for participants to develop machine-learning algorithms to create building footprints, which were then compared to footprints for the same area created by human mappers based in Monrovia. This side-by-side exercise created valuable data to refine the algorithms’ capabilities.

In addition to the machine-learning benefits, the drone imagery was used to map roads, buildings, and drains for the twenty square kilometer area where the available satellite imagery did not have the resolution needed to make out these features. The drone imagery is also now publicly accessible on [OpenAerialMap](https://openaerialmap.org/).

![Comparison Annotation 2020-06-11 123332.jpg](/uploads/Comparison%20Annotation%202020-06-11%20123332.jpg)
*Satellite imagery (left) versus UAV imagery captured with a SenseFly eBee drone (right)*

### Capturing and Using StreetView Imagery for Machine-Learning Feature Identification

For the second machine-learning exercise, iLab Liberia mounted a Blackvue Dashcam onto a car and drove all major streets in the Duala Market on Bushrod Island and in the Red Light Market areas of interest. The team captured over 150 kilometers of StreetView imagery of Monrovia. 

This imagery was used to map vehicle-accessible roads, and then to train a machine-learning algorithm developed by Mapillary to identify street features like street signs and intersections. While this has been done before in the developed world, it is much more challenging in the developing world. iLab Liberia is continuing to create and analyze imagery using dashcams, and anyone can access this data via [Mapillary](https://www.mapillary.com/).

![Mapillary Imagery Liberia.png](/uploads/Mapillary%20Imagery%20Liberia.png)

*Imagery collected at the center of Red Light Market showcasing the heavy foot-traffic on Somalia Drive, a major thoroughfare.*

![Verification Annotation 2020-06-11 123332.jpg](/uploads/Verification%20Annotation%202020-06-11%20123332.jpg)

*Verification screen for assessing the accuracy of machine-learning algorithm in identifying street features*

### Exploring AI-Assisted Mapping in OpenStreetMap with Roads and Buildings

In the third trial, HOT tested the ability of machine-learning algorithms to assist human mappers by recognizing new development and recommending mapping. Using HOT’s experimental machine-learning enabled [Tasking Manager](https://tasks-assisted.hotosm.org/), HOT validated road geometry using Facebook’s [RapiD Editor](https://mapwith.ai/rapid#background=Maxar-FB&disable_features=boundaries&map=2.00/0.0/0.0).

The objective of this task was to close any existing gaps in the road network around the entire city boundary of Monrovia. Monrovia’s road network had been largely mapped in 2014 and 2015 in response to the Ebola outbreak, but there had since been a great deal of development. Without the impetus for large numbers of mappers to update the map, the street map was getting woefully out of date. It’s one thing to get volunteers to add to a map when the map is blank, but it’s much more difficult, both logistically and motivationally, to get mappers to update an out-of-date map.

The RapiD Editor detected changes in imagery over time due to construction and suggested current images with changes for users to map. On each image, the Facebook roads AI indicated a suggested road to add with a magenta line, and the mappers decided if the suggestion was correct and added appropriate tags.

![RapiD Editor.png](/uploads/RapiD%20Editor.png)

*Example of RapiD Editor tool, roads identified through Facebook Roads AI in magenta.*

### Building Knowledge

In addition to the data generation benefits, HOT and iLab Liberia documented lessons learned for integrating machine-learning into participatory mapping. Members of the HOT community can help build on this knowledge by testing the experimental machine-learning enabled [Tasking Manager](https://tasks-assisted.hotosm.org/).

A highlight for project members was taking part in the cross-continent cooperation between teams from Liberia, Uganda, and Tanzania along with members of the government and community in Monrovia. The participants had the opportunity to learn about machine-learning and receive training on applying it in their own cities.

