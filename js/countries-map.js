var countries;
var countryData = {
  "type": "FeatureCollection",
  "features": []
};

mapboxgl.accessToken = 'pk.eyJ1IjoiaG90IiwiYSI6IlBtUmNiR1kifQ.dCS1Eu9DIRNZGktc24IwtA';
var map = new mapboxgl.Map({
  container: 'country-map-wrap',
  logoPosition: 'bottom-left',
  scrollZoom: false,
  dragRotate: false,
  style: 'mapbox://styles/hot/cjepk5hhz5o9w2rozqj353ut4'
});

fetch('/aggregatedStats.json')
.then(function(response) {
  return response.json();
})
.then(function(jsonData) {
  var countryTitle = $(document).find("title").text().split('|')[1].trim();
  countryData.features = (jsonData[countryTitle]);
  console.log(countryData);
}
);

map.on('load', function() {
  map.addSource('countriesbetter', {
    "type": "vector",
    "url": "mapbox://hot.9fvp7us2"
  });
  map.addSource('countriesProjects', {
    "type": "geojson",
    "data": countryData
  });
  
  map.addLayer({
    "id": "active_countries",
    "type": "fill",
    "source": "countriesbetter",
    "source-layer": "countriesbetter",
    "minzoom": 0,
    "maxzoom": 8,
    "filter": ['any', ['in', 'name_low'].concat(countryName), ['in', 'ISO_A2'].concat(countryCode)],
    "paint": {
      "fill-pattern": "lines-red-4",
      "fill-outline-color": "#EFB4B4"
    }
  }, 'place-city-sm');

  map.addLayer({
    "id": "country-projects-edits-circle",
    "type": "circle",
    "source": "countriesProjects",
    "minzoom": 0,
    "maxzoom": 18,
   "paint": {
    'circle-radius': {
      property: 'edits',
      stops: [
      [0, 10],
      [10000, 15],
      [50000, 20],
      [100000, 25],
      [125000, 30],
      [150000, 35],
      [200000, 40]

      ]
     },
    "circle-opacity": 0.7,
    "circle-color": "#FFC151",
    }
  }, 'place-city-sm');

  map.addLayer({
    "id": "country-projects-black-circle",
    "type": "circle",
    "source": "countriesProjects",
    "minzoom": 0,
    "maxzoom": 18,
   "paint": {
    'circle-radius': 6.5,
    "circle-opacity": 1,
    "circle-color": "#000000",
    }
  }, 'place-city-sm');
  
map.addLayer({
    "id": "country-projects-symbol",
    "type": "symbol",
    "source": "countriesProjects",
    "minzoom": 0,
    "maxzoom": 18,
    "layout" : {
      "text-field": "+",
      "text-font" : ["Open Sans Bold"],
      "text-offset": [-0.001, -0.03]
    },
   "paint": {
     "text-color": "#FFFFFF"
    }
  }, 'place-city-sm');

  fetch('/js/bbox.json')
    .then(function(response) {
      return response.json();
    })
    .then(function(jsonData) {
      countries = jsonData;
      map.fitBounds(countries[countryCode][1], {
        padding: 40
      });
    }
  );
});