---
title: Nepal earthquake. We have maps
date: 2015-05-01 01:42:43 Z
permalink: updates/2015-05-01_nepal_earthquake_we_have_maps
Person: Harry Wood
Working Group:
- Fundraising
Project:
- 'Disaster Activation: Nepal Earthquake 2015'
Country:
- Nepal
created: 1430444563
---

Since the earthquake struck in Nepal five days ago, 3679 mappers have made 62587 edits to the map (<a href="http://osm.townsendjennings.com/nepal/">latest stats</a>)  It's an amazing groundswell of map editing effort from our global community. We're adding lots of detail to the map, which was <i>already</i> pretty impressive due to the work of the local OpenStreetMap community.

But what happens next? How can aid agencies use the maps we are creating? Well there are many ways, some very simple, some more technical. The OpenStreetMap community has 10 years of experience with access to free and open map data. We've developed all sorts of tools and processes in that time. This is a brain dump of various links you may find useful. Probably for aid agencies the most interesting ideas will be around printing the maps, or loading the maps onto devices to use offline.

<h3>Browse the maps</h3>
<ul><li>Firstly you can browse the maps on the OpenStreetMap.org front page . <a href="http://www.openstreetmap.org/#map=9/27.7674/85.1042">Zoom in on the map of Nepal</a>. Pan around and explore. This view of the map is usually updated within about 10 minutes of new features being added.</li>
<li>Take a look at <a href="http://www.openstreetmap.org/#map=9/27.7674/84.7609&layers=H">HOT's humanitarian style</a>, as well as <a href="http://www.openstreetmap.org/#map=9/27.7674/84.7609&layers=Q">Mapquest's style</a>. Even the <a href="http://www.openstreetmap.org/#map=9/27.7674/84.7609&layers=C">cycle map style</a> is actually pretty interesting in Nepal, not so much for its cycle routes, but for the nice terrain rendering style.</li>
<li>Browse maps and maps styles elsewhere on the web e.g. <a href="https://a.tiles.mapbox.com/v3/examples.map-i875mjb7.html?secure#14/27.7271/85.2875">Mapbox terrain maps</a>. The terrain cartography on the Russian <a href="http://maps.sputnik.ru/#?type=search&q=&sub_type=address&lat=27.715141756723987&lng=85.24429321289062&zoom=11">sputnik.ru</a> site is also rather nice. There are countless other examples of OpenStreetMap cartography as browsable maps created by third parties.</li>
</ul>

<h3>Web map data overlays</h3>
<ul><li><a href="http://quakemap.org">quakemap.org</a> is a tool for reporting needs or situational updates, related to the earthquake, as pins on a map (<a href="http://kathmandulivinglabs.org/blog/earthquake-relief-in-nepal-how-can-maps-help/">read more here</a>). Potentially very useful in itself, but this is also just a great example of <i>overlaying</i> additional data on top of OpenStreetMap basemaps.</li>
<li>You can use OpenStreetMap on your own website, with your own data overlaid, using web map libraries such as <a href="http://openlayers.org">OpenLayers</a> and <a href="http://leafletjs.com">LeafletJS</a>. In this way, web-based digital humanitarian initiatives are making use of OpenStreetMap as a rich detailed basemap.</li>
<li><a href="https://umap.openstreetmap.fr/">uMap</a> offers an easier (zero coding) way to create custom overlays with your own data. We've used it to create <a href="http://umap.openstreetmap.fr/en/map/2015-nepal-earthquake-contributions-via-the-task-m_37675#9/28.0211/85.4118">HOT coordination maps</a> for example. Support for viewing KML / geojson files. This can also be embedded on your own website.</li>
</ul>
<h3>Printing maps</h3>
A good old paper map is still the ultimate mapping tool, and a very popular way for aid agencies to use OpenStreetMap in disaster response. Paper works without power or internet! Poster sized printouts can also be the ideal thing to pin-up in a meeting space back at HQ.

<center><img src="http://wiki.openstreetmap.org/w/images/thumb/8/8e/Map_Poster_DSWD_Operations_Center.jpg/350px-Map_Poster_DSWD_Operations_Center.jpg"><br><i>Big poster sized printouts being used for Typhoon Haiyan response</i></center>

There are a variety of ways to get a map printout

<ul><li>Simply take a screenshot. You may like to <a href="http://www.openstreetmap.org/export/embed.html?bbox=85.06233215332031%2C27.637915318904433%2C85.3750991821289%2C27.805372649998&layer=mapnik">go fullscreen</a> first.</li>
<li><a href="http://fieldpapers.org">fieldpapers.org</a> lets you create a multi-page PDF atlas to be printed, including a nice interface for choosing the area to cover. <a href="http://maposmatic.org">maposmatic.org</a> does this too, and also lets you add a street index to the page.</li>
<li>Kathmandu Living Labs have made some <a href="http://kathmandulivinglabs.github.io/quake-maps/">pre-prepared printable PDFs to download</a>. Scroll down to see different city regions.</li>
<li>MapAction specialise in printable maps as PDF downloads tailored to disaster response. You'll see OpenStreetMap's street-level data in use in some of their maps, for example this map of <a href="http://www.mapaction.org/deployments/mapdetail/3900.html">Search And Rescue zones</a></li>
</ul>
For the more advanced, you'll be wanting to create your own maps to print...
<ul><li>This might involve loading shapefiles into GIS software, customise the cartography, and print from there (more on shapefiles below) </li>
<li>Or alternatively prepare a map as an SVG file which designers can work with in inkscape or Adobe Illustrator. <a href="http://wiki.openstreetmap.org/wiki/SVG">Several approaches to getting SVG maps</a>. For a nicely layered file, try <a href="http://maperitive.net">Maperative</a>.</li>
<li>Those last two options will tend to fail if you load too much complex map data. So for an intricate detailed hi resolution map (particularly if you're aiming for poster sizes) you may have more luck sending a very large raster image to print. You can create such an image through <a href="http://wiki.openstreetmap.org/wiki/Rendering">rendering</a> e.g. using <a href="https://www.mapbox.com/mapbox-studio/">Mapbox studio</a>. Rendering is wonderfully flexible, but pretty complicated.  Somewhat easier is to generate a big image from existing tile servers using a tool called <a href="http://wiki.openstreetmap.org/wiki/Bigmap">BigMap</a>.</li>
</ul>

<h3>Offline maps on your device</h3>
It's quite possible to download a fully detailed map of an entire country onto a smartphone (or tablet) ready for you to zoom around and navigate while you're in a disaster zone without an internet connection. This is a fantastic possibility for aid workers, which is largely made possible by OpenStreetMap's free and open approach to data downloads. In recent years app developers have made this easier and easier. So <b>if you're heading out to Nepal, and you have a smartphone, this is a no-brainer!</b>. Tell your whole team to do this before you leave your internet connection.
<ul><li>OsmAnd is our favourite recommendation these days. For android phones / tablets <a href="https://play.google.com/store/apps/details?id=net.osmand&hl=en">it's here on google play</a>, and now for iPhone/iPad it's <a href="https://itunes.apple.com/us/app/osmand-maps/id934850257?mt=8&uo=6&at=&ct=" target="itunes_store">here on the apple appstore</a>  Before you leave your wifi behind, start up the app and download the Nepal map!<br>
We particularly like OsmAnd because anyone can create newly updated map downloads for different regions in the open .obf file format. You can see some people are <a href="http://wiki.openstreetmap.org/wiki/2015_Nepal_earthquake#Exporting_OpenStreetMap_data">offering downloads listed here</a> created specially for the Nepal response. But also the OsmAnd central download server is being <a href="http://osmand.net/?special=nepal-hot-osm">specially updated for Nepal each day at the moment</a> (so the default Nepal map you get inside the app, should be pretty up-to-date). In addition to excellent map viewing, OsmAnd has many neat features, including ways of <i>collecting</i> data for OpenStreetMap. <a href="http://learnosm.org/en/mobile-mapping/osmand/">Our LearnOSM.org documentation</a> gives more information on this.</li>
<li><a href="http://maps.me/en/home">Map.me</a> is another nice offline OpenStreetMap viewing apps for android & iPhone, but the map downloads are not as up-to-date as with OsmAnd</li>
<li>Garmin GPS devices (rugged GPS units with a screen for map viewing) can also be loaded with maps from OpenStreetMap. You can download pre-generated .img files from a variety of sources, but we're <a href="http://wiki.openstreetmap.org/wiki/2015_Nepal_earthquake#Exporting_OpenStreetMap_data">listing some options</a> made specially during the Nepal earthquake response.</li>
</ul>

<center><a href="http://wiki.openstreetmap.org/wiki/File:OpenStreetMap_on_a_Garmin_in_Haiti.JPG"><img src="http://wiki.openstreetmap.org/w/images/thumb/e/e7/OpenStreetMap_on_a_Garmin_in_Haiti.JPG/350px-OpenStreetMap_on_a_Garmin_in_Haiti.JPG"></a><br><i>A Garmin unit with our maps being used by search & rescue teams in Haiti</i></center>

<h3>Data downloads</h3>
<ul><li>Shapefiles might be the data format you'll be looking for if you know a thing or two about maps and GIS software. <a href="http://wiki.openstreetmap.org/wiki/2015_Nepal_earthquake#Exporting_OpenStreetMap_data">At the same data download link</a> we list few options for shapefiles, including <a href="https://www.dropbox.com/s/dgjj1lypea93xbs/central-nepal-20150426-0049Z-shp.zip?dl=0">this download</a> created by HOT's Blake Girardot. He's split out the OpenStreetMap features into 13 thematic layers. That's significant because shapefile users will tend to expect these layers, while OpenStreetMap data has no such concept. Some shapefiles are more intelligent than others with the way their filtering of OpenStreetMap tags has happened. If you want more control over this, you can run the conversion process yourself. The <a href="http://wiki.openstreetmap.org/wiki/Shapefiles">shapefiles page on the wiki</a> gives a range options.</li>
<li>Raw OpenStreetMap data is also available <a href="http://wiki.openstreetmap.org/wiki/2015_Nepal_earthquake#Exporting_OpenStreetMap_data">at the same data download link</a>. I'm working backwards in my explanation of these things. Downloads in data formats such as shapefiles, garmin .img files, and OsmAnd .obf files, are all generated as a conversion from raw OpenStreetMap data. Big thanks to <a href="http://www.geofabrik.de">geofabrik</a> who set up their extract download server on a 30 minute update cycle for Nepal.<br>
Small areas of map follow a <a href="http://wiki.openstreetmap.org/wiki/OSM_XML">.osm xml format</a>, but for city or country-sized extracts you'll see either zipped up XML, or a special intelligently compacted <a href="http://wiki.openstreetmap.org/wiki/PBF_Format">format called PBF</a>. This data, made up of Nodes, Ways, Relations & Tags, is the source sitting at the heart of the OpenStreetMap ecosystem, with many tools, apps and scripts for working with it, and with data changes coming in from the community via <a href="http://wiki.openstreetmap.org/wiki/Planet.osm/diffs">data diffs</a> synced using tools like <a href="http://wiki.openstreetmap.org/wiki/Osmosis">osmosis</a></li></ul>

We know that some of these things sound pretty complicated, and aid agencies don't necessarily have time to be getting their heads around it all right now. Hopefully getting a map printout is not too taxing, and again that OsmAnd app is a favourite (HOT tip!).  But if you do get stuck on any of this, or you want help with some more advanced use cases, just <a href="http://hotosm.org/get-involved">get in touch</a>. We have a very active community of technical experts who will jump to attention if you tell us you're looking to use our maps in an aid context! The true power of OpenStreetMap is its community.

Don't forget <b>OpenStreetMap is editable</b> and improving all the time (very rapidly in Nepal at the moment).  This is always worth remembering for map users, because it means A) Bringing in updates can be a good idea  B) You can contribute back! Most of our mapping effort is based on puzzling over a fuzzy view from space. Contributions from people on the ground are hugely valuable, and we can feed it back into the outputs to benefit other aid workers. Mapping is a topic for another blog post, but it can be as simple as adding "<a href="http://wiki.openstreetmap.org/wiki/Notes">Notes</a>" or sharing some photos with us!

And finally give us your success stories! We love hearing back from people using our maps. It has a serious value in terms of motivating our mapping community and helping to promote our work.








