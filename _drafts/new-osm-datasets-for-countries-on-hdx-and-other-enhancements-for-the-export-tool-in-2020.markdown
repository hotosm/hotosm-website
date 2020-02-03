---
title: New OSM Datasets for Countries on HDX and other Enhancements for the Export
  Tool in 2020
date: 2020-02-03 18:14:00 Z
Summary Text: The most recent round of HDX development work focused on streamlining
  the backend so jobs run faster, delivering much needed OSM data into the hands of
  our users. Another key area of enhancement was admin functionality, offering additional
  control and customisation to create a more dynamic tool. This included adding the
  ability to feature specific ‘Exports’ and ‘Configs’ right on the home page, as well
  as capturing usage statistics so that future rounds of development will be better
  informed. Our humanitarian users continue to be supported through the addition of
  new baseline datasets of countries to HDX as well as key lifeline infrastructure
  data for all of Indonesia through InAWARE.
Feature Image: "/uploads/Export%20Tool%20Blog%201.png"
---

## **Greater Data Outreach**

Our aim for the Export Tool has always been to make it easier for users to select and download OpenStreetMap (OSM) data, independent of their technical skills and experience. The Export Tool allows users to identify which map features they want to extract within a chosen area of interest. These are then converted into the file format of their choice.

It sounds simple enough, but there are still difficulties that users can encounter, such as actually knowing what features might be within the area of interest. And there is the issue of knowing what tagging names are used in OpenStreetMap for specific features. This is particularly tricky for users unfamiliar with the data structure and tagging system.

This is where the collaboration with the Humanitarian Data Exchange (HDX) back in 2017 was a game changer for getting up-to-date OSM data into the hands of even more humanitarians. HDX is an open data sharing platform managed by the United Nations Office for the Coordination of Humanitarian Affairs, and a key online resource that individuals and organisations go to when looking for baseline map data.  There was a clear opportunity to provide OSM building, road, waterway, and points of interest datasets to the HDX platform through the Export Tool, making accessing OSM data easier than ever for its users.

An integration component was built into the Export Tool so that these four OSM datasets for specific countries could be set up to automatically export on a specified schedule. This way, any new data that is added to OSM for the country will be extracted and hosted on HDX, ready for download and use in a variety of common GIS file formats. This integration led to the OSM datasets being among the most downloaded on HDX in 2019, so it only made sense that we would continue to support the needs of the public with even more OSM datasets.

This successful collaboration led to the addition of seven more datasets on top of the four outlined above. Airports and helipads, education facilities, health facilities, financial services, populated places, railways and sea ports were identified as key through discussions with our partners at [MapAction](https://mapaction.org/) to see what baseline data is generally required when they are deployed for a humanitarian response. These new datasets are now included to support the Geography & Infrastructure category of the new ‘[Data Grid](https://centre.humdata.org/introducing-the-hdx-data-grid-a-way-to-find-and-fill-data-gaps/)’ feature of HDX. This feature aims to provide data for a wide range of users and needs. The Data Grid looks at country level datasets and assesses whether the data is in a common format, tidy, geo-spatially referenced, comprehensive, and up-to-date.

![Export Tool Blog 3.png](/uploads/Export%20Tool%20Blog%203.png)

## **Baseline Preparedness Data**

The YAML code used by the Export Tool to extract features and filter specific attributes for the new seven new datasets added to the country information available on HDX is outlined below. As a quick breakdown: the ‘types’ command identifies the geometry, the ‘select’ command identifies the attributes that will be filtered, the ‘where’ command identifies the feature that is extracted from OSM. To learn more about the YAML syntax and how it is used in the Export Tool, please read the [Learn](https://export.hotosm.org/en/v3/learn/yaml) section.

**Airports and Helipads**
`types:
- points
- lines
- polygons
select:
- name
- aeroway
- building
- emergency
- emergency:helipad
- operator:type
- capacity:persons
- addr:full
- addr:city
- source
where: aeroway IS NOT NULL OR building = 'aerodrome' OR emergency:helipad IS NOT NULL OR emergency = 'landing_site'`

**Education Facilities**
  types:
    - points
    - polygons
  select:
    - name
    - amenity
    - building
    - operator:type
    - capacity:persons
    - addr:full
    - addr:city
    - source
  where: amenity IN ('kindergarten', 'school', 'college', 'university') OR building IN ('kindergarten', 'school', 'college', 'university')

**Health Facilities**
  types:
    - points
    - polygons
  select:
    - name
    - amenity
    - building
    - healthcare
    - healthcare:speciality
    - operator:type
    - capacity:persons
    - addr:full
    - addr:city
    - source
  where: healthcare IS NOT NULL OR amenity IN ('doctors', 'dentist', 'clinic', 'hospital', 'pharmacy')

**Financial Services**
    types:
      - points
      - polygons
    select:
      - name
      - amenity
      - operator
      - network
      - addr:full
      - addr:city
      - source
    where: amenity IN ('mobile_money_agent','bureau_de_change','bank','microfinance','atm','sacco','money_transfer','post_office')

**Populated Places**
  types:
    - points
    - polygons
  select:
    - name
    - place
    - population
    - is_in
    - source
  where: place IN ('isolated_dwelling', 'town', 'village', 'hamlet', 'city')

**Railways**
  types:
    - lines
    - polygons
  select:
    - name
    - railway
    - ele
    - operator:type
    - layer
    - addr:full
    - addr:city
    - source
  where: railway IN ('rail','station')

**Seaports**
    types:
      - points
      - lines
      - polygons
    select:
      - name
      - amenity
      - building
      - port
      - operator:type
      - addr:full
      - addr:city
      - source
    where: amenity = 'ferry_terminal' OR building = 'ferry_terminal' OR port IS NOT NULL
