var countryList = countries.split(',')
countryList.forEach((country, countryIndex) => {
  countryList[countryIndex] = country.trim().toLowerCase()
})

$(document).ready(function (){
  document.getElementById('Countries-Covered').innerHTML = countryList.length
})

mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA';
var map = new mapboxgl.Map({
  container: 'map',
  logoPosition: 'bottom-left',
  scrollZoom: false,
  dragRotate: false,
  maxZoom: 18,
  minZoom: 1.25,
  zoom: 1.25,
  center: [0, 8],
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
});

map.on('load', function () {
  $('.mapboxgl-ctrl').addClass('hide');
  $('#loading-map').detach();
  map.addSource('countriesbetter', {
    "type": "vector",
    "url": "mapbox://hot.6w45pyli"
  });

 
  map.addLayer({
    "id": "project_countries",
    "type": "fill",
    "source": "countriesbetter",
    "source-layer": "countries-polygon-7jl2br",
    "minzoom": 0,
    "maxzoom": 8,
    "filter": ['in', 'name_low'].concat(countryList),
    "paint": {
      "fill-pattern": "lines-red-4",
      "fill-outline-color": "#EFB4B4"
    }
  }, 'place-city-sm');
 
});