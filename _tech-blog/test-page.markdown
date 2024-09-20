---
title: test page
date: 2024-09-20 19:37:00 Z
published: false
Summary Text: Do not publish
---

Do not publish2

<iframe width="100%" height="500" frameborder="0"
  src="https://observablehq.com/embed/@observablehq/color-scatterplot?cell=*"></iframe>

https://observablehq.com/embed/@observablehq/color-scatterplot?cell=*

https://observablehq.com/embed/@observablehq/plot-scatterplot/2?cell=*


<iframe width="100%" height="381" frameborder="0"
  src="https://observablehq.com/embed/@observablehq/plot-us-bubble-map?cells=population%2Cus%2Cnation%2Cstatemap%2Ccountymap%2Cstatemesh%2CradiusLegend"></iframe>


<div id="observablehq-population-51b634a8"></div>
<div id="observablehq-us-51b634a8"></div>
<div id="observablehq-nation-51b634a8"></div>
<div id="observablehq-statemap-51b634a8"></div>
<div id="observablehq-countymap-51b634a8"></div>
<div id="observablehq-statemesh-51b634a8"></div>
<div id="observablehq-radiusLegend-51b634a8"></div>
<p>Credit: <a href="https://observablehq.com/@observablehq/plot-us-bubble-map">Plot: U.S. bubble map by Observable</a></p>

<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/@observablehq/inspector@5/dist/inspector.css">
<script type="module">
import {Runtime, Inspector} from "https://cdn.jsdelivr.net/npm/@observablehq/runtime@5/dist/runtime.js";
import define from "https://api.observablehq.com/@observablehq/plot-us-bubble-map.js?v=4";
new Runtime().module(define, name => {
  if (name === "population") return new Inspector(document.querySelector("#observablehq-population-51b634a8"));
  if (name === "us") return new Inspector(document.querySelector("#observablehq-us-51b634a8"));
  if (name === "nation") return new Inspector(document.querySelector("#observablehq-nation-51b634a8"));
  if (name === "statemap") return new Inspector(document.querySelector("#observablehq-statemap-51b634a8"));
  if (name === "countymap") return new Inspector(document.querySelector("#observablehq-countymap-51b634a8"));
  if (name === "statemesh") return new Inspector(document.querySelector("#observablehq-statemesh-51b634a8"));
  if (name === "radiusLegend") return new Inspector(document.querySelector("#observablehq-radiusLegend-51b634a8"));
});
</script>


