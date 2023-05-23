---
title: Siteleaf Sample Page (Widgets, Sidebar, HTML)
date: 2023-05-17 01:56:00 Z
published: false
Intro Text: |-
  This is a page for copying and pasting HTML to use on other pages. It should not be published.
  <br>
  Use breaks to add line breaks in the intro text or wherever on the page you need to add extra space.
  <br>
  This is a markdown link: [link](https://www.hotosm.org/). They don't work in intro text.
  <br>
  Use HTML instead: <a href="https://www.hotosm.org/">link</a>.

  <!-- The StoryMap container can go anywhere on the page. Be sure to
      specify a width and height.  The width can be absolute (in pixels) or
      relative (in percentage), but the height must be an absolute value.
      Of course, you can specify width and height with CSS instead -->
  <div id="mapdiv" style="width: 100%; height: 600px;"></div>

  <!-- Your script tags should be placed before the closing body tag. -->
  <link rel="stylesheet" href="https://cdn.knightlab.com/libs/storymapjs/latest/css/storymap.css">
  <script type="text/javascript" src="https://uploads.knightlab.com/storymapjs/e120c697c1124821d49174a85168e18d/equipo-alfa-del-hub-de-mapeo-abierto-de-america-latina/index.html"></script>

  <script>
  // storymap_data can be an URL or a Javascript object
  var storymap_data = '/static/demo/demo.json';

  // certain settings must be passed within a separate options object
  var storymap_options = {};

  var storymap = new KLStoryMap.StoryMap('mapdiv', storymap_data, storymap_options);
  window.onresize = function(event) {
      storymap.updateDisplay(); // this isn't automatic
  }
  </script>
Page Link:
  Label: Learn More
  Text: Learn more about our work and how OpenStreetMap data equips communities and
    policy-makers to better address climate and disaster risk.
  Link: https://www.hotosm.org/impact-areas/disaster-risk-reduction/
Page Contact:
  Label: Contact Us
  Text: |-
    <br>
    If you or your organization would like to learn more or to partner with us or any of our local implementing partners to support the use of OpenStreetMap for climate and disaster risk management, please reach out.
  Contact Email: partnerships@hotosm.org
Sidebar Text: This is sidebar text.
---

<table style="border-bottom: none">
	<tr>
		<th style="border-bottom-width: 2px"><span style="font-weight: bold">Column 1</span></th>
		<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Column 2</span></th>
		<th style="border-left: 1px solid black; border-bottom-width: 2px"><span style="font-weight: bold">Column 3</span></th>
	</tr>
	<tr>
		<td>Row 1</td>
		<td style="border-left: 1px solid black">Text A</td>
		<td style="border-left: 1px solid black">Text B</td>
	</tr>
	<tr>
		<td>Row 2</td>
		<td style="border-left: 1px solid black">Text C</td>
		<td style="border-left: 1px solid black">Text D</td>
	</tr>
</table>
<br>

* This is how a bulleted list works in Markdown
* * But there's no real way to add indents, and double bullets look weird
* So use HTML instead!

Ordered List:
<ol>
  <li>Coffee</li>
  <li>Tea</li>
  <li>Milk</li>
</ol>
<br>

Ordered List with Sub-lists:
<ol>
  <li>Coffee</li>
  <li>Tea
    <ol>
      <li>Black tea</li>
      <li>Green tea</li>
    </ol>
  </li>
  <li>Milk</li>
</ol>
<br>

Unordered List:
<ul>
  <li>Coffee</li>
  <li>Tea</li>
  <li>Milk</li>
</ul>
<br>

Unordered List with Indents:
<ul>
  <li>Coffee</li>
  <li>Tea</li>
<ul>
  <li>Black Tea</li>
  <li>Green Tea</li>
</ul>
  <li>Milk</li>
</ul>

![Canoa_de_Tolda_-_Brazil_3.jpg](/uploads/Canoa_de_Tolda_-_Brazil_3.jpg)
<figcaption align = "center"><h6>Caption aligned center</h6></figcaption>
<br>

![PhilAWARE combined.png](/uploads/PhilAWARE%20combined.png)
<figcaption align = "left"><h6>Caption aligned left</h6></figcaption>