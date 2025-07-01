---
title: 'Humanitarian Mapping with WhatsApp: Introducing ChatMap'
date: 2024-12-12 19:06:00 Z
Summary Text: ChatMap, turns WhatsApp chats into instant maps, extracting location
  data and messages. Ideal for disaster-prone areas, it enhances communities with
  limited tech skills, even offline.
Feature Image: https://cdn.hotosm.org/website/chatmap+whatsapp+humanitarian+openstreetmap.jpg
Person: Emilio Mariscal
---

[Spanish version](https://www.hotosm.org/updates/mapeo-humanitario-con-whatsapp-presentando-chatmap/)

A few months ago, [Céline Jacquin](https://www.hotosm.org/people/celine-jacquin/), Senior Manager for the Latin America and the Caribbean Hub, mentioned a community in need of humanitarian mapping, where residents had zero to minimal tech knowledge.

> "Many of the people involved are people with zero tech knowledge, even very old people tell me that, well, they are using their cell phones for WhatsApp and that's it.”

A few months later, in the city of Porto Alegre, Brazil, [big floods affected a big area](https://www.hotosm.org/updates/humanitarian-mapping-for-climate-resilience-responding-to-floods-in-porto-alegre/), two million people were impacted. Again, WhatsApp was on the conversation:

> “A local university is receiving WhatsApp pictures and locations from local people in the disaster. And the university is asking us what to do with that.

As a volunteer firefighter, I have experienced this need firsthand. In the place where I live, street names are something new, so it’s common for people to share their location with us via their phones to help us find their houses during emergencies.

![Humanitarian Mapping ChatMap WhatsApp.jpg](https://cdn.hotosm.org/website/Humanitarian+Mapping+ChatMap+WhatsApp.jpg)

I aimed to create something incredibly simple and accessible—something anyone could use, even those unfamiliar with geographic coordinates. Instant messaging is widely used, everyone has an app installed for that, and, almost, everyone knows how to send messages. WhatsApp is installed in almost every phone in Latin America, but also in other areas of the world. For example, India alone has 535.8 million users.

# **WhatsApp ChatMap**

After some exploration, I came up with an idea: what if we could export chat conversations and extract the location data along with the associated messages? The solution would involve a straightforward application where users can upload their exported chats and instantly generate a map displaying all shared locations and messages. No business accounts or complex integrations would be required—just a simple, ready-to-use tool from day one.

ChatMap —[chatmap.hotosm.org](http://chatmap.hotosm.org) — is a straightforward and simple mapping solution that leverages WhatsApp, an application used by 2.78 billion people worldwide. Its simplicity and accessibility make it an effective tool for communities with limited technical knowledge. And it even works offline! as it relies on the GPS signal for location, sending all data with the phone to gather connectivity.

This solution provides complete independence, as it does not require users to adopt a technology that depends on third-party maintenance. It’s a simple data flow with an equally straightforward script that can be improved by anyone interested on [GitHub](https://github.com/hotosm/chatmap).

We’re already using it! Recently, as part of a community mapping project to assess the risks in the slopes of Comuna 8 in Medellín, an area vulnerable to repeated flooding, a group of students and local collectives collaborated with the Humanitarian OpenStreetMap (HOT) to map areas affected by landslides and other disaster impacts. This initiative facilitated the identification and characterization of settlements, supporting humanitarian aid efforts.

![Humanitarian Mapping ChatMap.jpg](https://cdn.hotosm.org/website/Humanitarian+Mapping+ChatMap.jpg)*\
**Photo by Daniela Arbeláez Suárez (source: WhatsApp)***

As shown in the picture, the community explored the area on foot, using their phones to take photos and notes, and shared them along with the location. It was incredibly simple!

The data gathered during this activity was transformed 20 minutes later (once getting access to a WIFI network) into a map, which was then uploaded to our online platform powered by uMap ([umap.hotosm.org](http://umap.hotosm.org)).

![Humanitarian Mapping ChatMap WhatsApp Colombia.jpg](https://cdn.hotosm.org/website/Humanitarian+Mapping+ChatMap+WhatsApp+Colombia.jpg)\
*See more at **[https://umap.hotosm.org/en/map/unaula-mapea-con-whatsapp_38](https://umap.hotosm.org/en/map/unaula-mapea-con-whatsapp_38#17/6.24974/-75.53854)***

# **What’s next?**

After the initial testing, many exciting ideas emerged to make the tool even more adequate, but our immediate focus is on simplifying the process of saving maps, including the shared media, so they can be easily accessed via a URL for future use. Beyond that, we’re exploring innovative ways to leverage the shared data even further.

If you’re curious about this process, why not give it a try? All you need are WhatsApp messages with shared locations—no additional setup required!

Just check this video-tutorial.

<iframe width="600" height="400" src="https://www.youtube.com/embed/ScHgVhyj1aw?si=D1kjlvvdD3xrH6Ao" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

The code is available on [GitHub](https://github.com/hotosm/chatmap), complete with documentation on how to run it and comments within the code. You’re welcome to contribute, use it, improve it, and even install it on your own servers.

Anyone interested in contributing can reach out to Emi Mariscal via email ([tech-data@hotosm.org](mailto:tech@hotosm.org)), or directly through the repository.