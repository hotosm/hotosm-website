---
title: HOT's Approach to OSM data validation to EQ Mapping Projects
date: 2023-03-17 02:29:00 Z
Summary Text: Because OpenStreetMap is a crowd-sourcing project where everyone can
  freely contribute to the map, the Humanitarian OpenStreetMap Team has devised measures
  to support high-quality crowd-sourced OSM data. We have a four step validation process
  to ensure that the data created for emergencies like the current Turkey and Syria
  earthquake response is fit for use.
Feature Image: "/uploads/Validation_Process_1B.png"
Is image top aligned: true
Person: Samson Ngumenawe
Working Group:
- Quality Control and Assurance
Country:
- Turkey
- Syria
Project:
- Join the Turkey & Syria Earthquake Response
---

OpenStreetMap (OSM) data can be invaluable for disaster response efforts. It can provide spatial data updates about the affected area and help emergency responders to plan their operations more effectively.  

In the recent  7.8, 7.6, and 6.5 magnitude earthquakes in Turkey and Syria, [Yer Cizenler](https://yercizenler.org/en/home/) requested assistance in [mapping the devastated areas](https://parametric-architecture.com/yer-cizenler-calls-you-to-map-earthquake-effects-in-southern-turkey/). The geodata these mappers are creating is benefiting humanitarian workers on the ground, but to be useful, the data must be high quality.

Because OpenStreetMap is a crowd-sourcing project where everyone can freely contribute to the map, the Humanitarian OpenStreetMap Team has devised measures to support high-quality crowd-sourced OSM data. The Tasking Manager has been widely used in the Turkey and Syria Earthquake response mapping, and the steps we take to ensure the quality of the created data are:

1. Project creation
2. Mapping
3. Validation
4. Final clean-up

### Project Creation
 
The first step towards good quality data is good mapping project design on the Tasking Manager. A good mapping project has clear and comprehensive instructions about what should be mapped, who should map, how they should map, the imagery to be used, the timeline of the mapping, and who should validate the data.

![Validation_Process_2B.png](/uploads/Validation_Process_2B.png)

### Mapping

Highly experienced and trained project creators from the Open Mapping Hub - Asia Pacific created all the earthquake response projects. They created projects with different difficulty levels to reach a broader range of mappers while maintaining quality mapping.

Projects in high-density towns were set to be mapped and validated by mappers with intermediate and advanced levels of mapping. Imagery is rarely from directly overhead, and mapping high-rise buildings requires drawing their footprint, which may be obscured by the bulk of the building. 

Projects in the peri-urban areas characterized by low-density buildings and roads are open to all levels of mappers but closely reviewed by skilled validators.

Similarly, some project areas where data is urgently needed are prioritized and opened to intermediate and advanced mappers to enable the quick creation of high-quality data. 

![Validation_Process_3B.png](/uploads/Validation_Process_3B.png)
<figcaption align = "left"><h6>In the Tasking Manager, mapper level is indicated by a star. No star means a beginner mapper, a half star is an intermediate mapper, and a full star is an advanced mapper.</h6></figcaption>

### Validation

The Tasking Manager allows project creators to set who should validate specific projects. For earthquake response projects, all the validation is done by the selected teams whose members have been verified and meet the minimum required changesets to be validators. A validation team is a group of advanced volunteer mappers that an organization has coordinated to improve the quality of OSM data in that organization’s Tasking Manager projects. Some validator teams checking earthquake response mapping projects include the HOT global validators, validator trainees, UN Mappers, and OSM Africa validators.

![Validation_Process_4B.png](/uploads/Validation_Process_4B.png)

> “The primary role of the validator is to check and verify that the data created in a specific task on the tasking manager meets the required standard, and the instructed features have all been mapped in that task.” - Ralph Aytoun, Validation Lead

**The Validation Process**

Once the task has been completely mapped, the validator performs the following steps.
1.) They check for the completeness of the mapping. Each project has designated features to map, and the validator makes sure that none of them were missed in the task area. If there are any missing features, the validator can map them and validate the work or invalidate the task to open it for other mappers to add the missing features. 
2.) Next, they a the validation check. Using the validation tool and activating  JOSM map paint styles, the validator checks for common errors, including the following:
* Untagged features
* Bad geometries, including overlapping features and crossing features like buildings and highways
* Hanging nodes and ways that lack any tags describing what they are

![Validation_Process_5B.png](/uploads/Validation_Process_5B.png)

3.) Third, they validate tasks that have been well-mapped and invalidate tasks that are missing features or not mapped well. For the invalidated tasks, the indicates why the task was invalidated.
4.) Finally, they give the mappers feedback. If the task is invalid, the validator explains the reason so that the mappers know how to fix the task. Validators also send messages to mappers to guide them on improving their mapping by linking them to web content like Youtube videos or other learning resources. If the task is validated, an automated message goes to the mapper to let them know. However, the validator can also send a message to the mapper thanking them for their contribution.

Please note that this validation is at the task level. Each project task is checked individually and validated or invalidated depending on the quality of mapped data in that task.

![Validation_Process_6B.png](/uploads/Validation_Process_6B.png)

### Final Clean-up

“Final clean-up” is an advanced data check step that combines several task areas at once, or even the entire project area, and checks them to eliminate the errors resulting from features straddling task boundaries or from other human errors that remain after validation.

All earthquake response mapping projects are subject to this final clean-up step. During this clean-up, the boundaries of a completed project are used to create the final clean-up project on the Tasking Manager, where a few highly experienced mappers and validators run validation checks for the combined area. During this validation, validators use advanced operations in JOSM, like filters and map paint styles, to query specific map features and find the errors. 

![Validation_Process_7B.png](/uploads/Validation_Process_7B.png)

During the final clean-up, the errors and warnings validators check for include:
* Unconnected highways that can be a result of mappers not carrying them over task boundaries
* Overlapping features from one task to another
* The completeness of buildings, highways, and any other missing features that could have been missed by mappers and validators 
* Highway classification and continuity - checking and correcting highway tags so they are the same across the entire length of the highway, even as it crosses different tasks
* Building accuracy - combined buildings, footprints, completeness, and continuity of the map features

### New Strategies
Some of the upcoming earthquake response mapping projects on the HOT tasking manager in Syria and Turkey will be open to selected highly experienced mappers to map roads and later will be opened to other mappers to add buildings and other features as will be instructed. Tasks marked as priority areas will be opened for advanced mappers to quicken the speed of data creation, whereas the rest of the projects will be open for all mappers levels. These projects will, however, follow the validation process up to the final clean-up stage.

### Lessons Learned

We used RapID and AI data in this activation in an effort to support the large volume of data that needed to be quickly created. With many new mappers participating, many of whom did not have experience mapping with AI suggestions, the activation faced challenges with using RapID data:
Most of the roads were tagged as residential by default, even when they should have received other classifications, and this was not obvious to new mappers.
* Most buildings in high-density areas were combined, and roofs were not separated from footprints.
* New mappers tended to accept RapID data wholesale as correct, which was often not the case. In this instance, poor-quality machine learning-derived data was not helpful, and we elected not to use RapID when creating additional projects in the activation area.
* Even after validation, there were several unconnected highways that were a result of the discontinuity of mapped AI features.

The challenges triggered several data quality checks that included:
* Changing who could validate from intermediate and advanced mappers to only validation team members.
* Separate projects for high-density urban areas were created and mapped only by intermediate and advanced mappers.