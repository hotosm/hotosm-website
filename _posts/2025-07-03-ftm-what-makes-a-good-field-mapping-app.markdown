---
title: What Makes a Good Field Mapping App? Exploring the Newest Updates to the Field
  Tasking Manager
date: 2025-07-03 18:13:00 Z
Feature Image: "/uploads/8.jpg"
Person:
- Petya Kangalova
- Carter Draper
- Sam Woodcock
---

In late 2022, HOT’s tech team started a prototype of what would become the Field Tasking Manager, or Field-TM. Among a variety of [already available good field mapping apps](https://docs.fmtm.dev/about/faq/#dont-other-tools-do-similar-things), we decided to embark on this journey to add an element that was clearly missing for us: the ability to facilitate coordination between mappers. With many contributions, tests, and [updates](https://www.hotosm.org/updates/field-mapping-tasking-manager-fmtm/) over the last years, **we are excited to share that Field Tasking Manager is now production-ready. Yes, that means [it is ready for use](https://fmtm.hotosm.org/)!**

As HOT’s Tech Partnership and Engagement Lead, I decided to speak directly to [Sam Woodcock](https://www.hotosm.org/people/sam-woodcock/), our Senior Technical Lead, and the developer behind Field-TM, as well as [Carter Draper](https://www.hotosm.org/people/carter-draper/), Senior Manager of Programs at our West and Northern Africa Hub, who has tested this tool in several local projects. By bringing together the voices of both users and developers, I hope to encourage more mappers to use Field-TM! 

**Petya:** Let’s start with some Field-TM basics. Sam, what is the Field Tasking Manager?

**Sam:** The Field Tasking Manager is a web and mobile application for coordinating field mapping activities in open mapping campaigns. While there are existing field mapping applications, there is a lack of efficient tools to coordinate these activities within teams.

**Petya:** What type of users is Field-TM built for?

**Sam:** We have two primary roles to consider, with some additional support roles. Generally, but not always, we have a **campaign manager** who will help to coordinate mappers. The manager needs to be able to easily track progress amongst mappers, notifying them when there are issues to address, and exporting data at intervals to check data quality. Next, we have the **mappers** themselves, who make up the majority of users of Field-TM. These users collect the data via structured surveys to produce the final dataset. There are additional roles too: validators, who check for data quality; organization managers, who manage multiple projects across an organization or mapping theme; and field admins, who may help to coordinate mappers while actually in the field themselves.

**Petya:** Now let’s hear from a user’s perspective. Carter, what’s unique about the Field Tasking Manager? 

**Carter:** Having trained teams in Ghana, Liberia, and Sierra Leone to leverage the Field-TM for mapping informal settlements, I've witnessed firsthand how this tool has continued to evolve since last year. It's become an essential asset for conducting household surveys, especially in densely populated areas. In Ghana, we effectively utilized the Field-TM in three informal settlements (Chorkor, Agbogbloshie, and Old Fadama), yielding incredibly accurate data for our partners like never before. In Liberia, our 25 field teams successfully mapped several informal settlements with precision and coordination, ensuring no building was left behind. Meanwhile, in Sierra Leone, we empowered residents of informal settlements and local non-governmental organizations by training them to utilize their low-cost smartphones, making the mapping process not only seamless but also entertaining for their communities.

![CloseUpFTM.jpg](/uploads/CloseUpFTM.jpg)
*Close-up of a Field-TM task during a mapping campaign. Photo: Carter Draper.*

**Petya:** Those are great examples from the field! I would also recommend our readers to check out [another use in Tokha Municipality, Nepal](https://www.hotosm.org/updates/field-tm-making-urban-development-easier-in-tokha-municipality/), done by our partner, Naxa. So, Sam, what would you say makes a good field mapping application?

**Sam:** Based on our experience mapping in various contexts around the world, we can pull out three common themes for what makes for an intuitive mapping experience. 
* Firstly, a form of progress tracking—ideally, real-time updates—which allows for mappers to see where their colleagues are currently mapping and avoids duplication of work. 
* Next, users need to be able to effectively locate themselves, using high-resolution basemaps, satellite-based geolocation, and built-in navigation capabilities. 
* The final piece of the puzzle is offline support. Often, users have poor or flaky internet connections, meaning the mapping application must work while offline, then sync data when returning to a location with a better connection.

**Petya:** What unique features have you implemented to address these points?

**Sam:** Amongst all of the standard features you would expect from a field mapping application, a standout for me is the live progress tracking. It’s very useful to be able to see immediately when your colleague maps the building next to you, as the shape changes green immediately in the app interface. The offline support is a reasonably new feature and somewhat experimental, but it should work for most use cases and has fallbacks to ensure that data can always be extracted in one form or another. You can see all the changes with the FieldTM v2 release on [GitHub](https://github.com/hotosm/field-tm/releases/tag/2025.2.0) and also my own coverage of the updates [on my OpenStreetMap (OSM) diary.](https://www.openstreetmap.org/user/spwoodcock)

![7.jpg](/uploads/7.jpg)
*A shout out to all the people who have contributed to the development of Field-TM! Source: [GitHub](https://github.com/hotosm/field-tm?tab=readme-ov-file#contributors-).*

**Petya:** Coming back to Carter, do you see this reflected in your experiences? What is a key benefit you see from the Field Tasking Manager?

**Carter:** On the dashboard, I can monitor task progress in real-time and communicate instantly with field teams regarding any buildings that haven't been addressed. By synchronizing data across devices, field teams receive updates on which buildings have already been enumerated and which ones need to be visited next. This facilitates data quality checks among data collectors while they are in the field. On the server, it's possible to validate the attributes collected for each building, adding another layer of data quality assurance.

**Petya:** What would you say to someone who has never used the Field Tasking Manager?

**Carter:** This tool represents a significant advancement in field data collection methods. It effectively addresses several challenges associated with conventional approaches by prioritizing the mapping of building footprints rather than relying solely on GPS coordinates and the systemic deployment of field teams. This innovative approach is particularly advantageous in densely populated areas, as it mitigates the issue of overlapping GPS coordinates and missing buildings, which have historically compromised the accuracy of field data. Furthermore, the system enables users to monitor their progress in mapping buildings and amenities through a visual interface that distinguishes between completed and incomplete structures with color-coded patterns when the data is synced to the server. The application is user-friendly, requiring minimal training, as it is integrated with [ODK Collect](https://docs.getodk.org/collect-intro/), compatible with basic smartphones, while providing enhanced accuracy. 

I strongly encourage partners involved in projects centered on risk assessments, mapping informal settlements, central business districts, and comprehensive city analyses for service delivery, enhancing tourism, property mapping, revenue mobilization, urban planning, and fostering resilient, sustainable cities for humanitarian and inclusive development to embrace the Field Tasking Manager. This powerful tool will elevate the quality of your data, streamline fieldwork coordination, and ensure timely and remote monitoring and validation of field data collection.

![9.jpg](/uploads/9.jpg)
*Testing Field-TM in Sierra Leone, September 2024.*

**Petya:** Sam, what’s next on the development roadmap?

**Sam:** We are working on pulling back lots of OSM functionality that we neglected over time. In the near future, we will have configurations for specifically mapping OSM data and merging it back into OSM. I also had the idea of real-time user icons on the map, so you can see the location of your colleagues walking around in the field, but we have yet to gather feedback on whether users would want this! Check out [our roadmap on GitHub](https://github.com/hotosm/field-tm#roadmap) for more details.

**Petya:** Carter, what additional features would you like to see for users?

**Carter:** In relation to the program areas at HOT, we amass a diverse array of datasets. Currently, most Field Tasking Manager projects have focused on buildings. It will be great to see more projects using the available functionality of Field Tasking Manager to add all types of data, including lines for mapping drainage segments and points for identifying waste disposal locations and water access points. Additionally, many of the regions we operate in struggle with internet connectivity issues. I am excited to see that with the latest release of the Field Tasking Manager, a functionality was added to allow it to operate offline to some extent. I would love to see the tool fully function offline, which will allow for greater accessibility in remote rural areas.

**Petya:** Thank you so much, Carter and Sam, for sharing your experience with the Field Tasking Manager. I feel inspired hearing from you and seeing the huge potential FieldTM has! It has been wonderful connecting the user and developer perspective—there is no tool that works without the close communication between the two! I would encourage anyone who is working on a project and sees a use case to try and test it. Our team at HOT and our partner Naxa are here to help with any questions. 

## Wondering where to begin/what to do next?

* Check out [our latest community webinar](https://www.youtube.com/watch?v=OUeBevXfOkQ), guiding you through the latest updates to the Field-TM.
* Start using the [Field Tasking Manager](https://fmtm.hotosm.org): Create a project and start mapping by watching the mini demo tutorials for our three workflows: [Organization creation](https://www.youtube.com/watch?v=ayF6byODcD4), [Project Creation](https://www.youtube.com/watch?v=iLCuc2bXLcs), and [Mapping.](https://www.youtube.com/watch?v=fAVycJ5rowY)
* Get in touch with us: Join [HOT's Slack](https://slack.hotosm.org) and search for the #field-mapping-tasking-manager channel, and/or email us at [tech-data@hotosm.org ](tech-data@hotosm.org)

**Note:** In case you are joining [FOSS4G Europe in Mostar](https://pretix.eu/foss4ge2025/mostar/), join us [for two hands-on sessions on 18 July using the Field Tasking Manager](https://2025.europe.foss4g.org/schedule/hot-drone-mapping-workshop/). Sam and I will be there :)
